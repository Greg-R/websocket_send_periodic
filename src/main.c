#include "mgos.h"
#include "mgos_http_server.h"

//  Clock update interval.
#define INTERVAL_SECONDS 1
//  POSIX time related data structures.
time_t maintime;
struct tm * localstruct;
char utctime[50];
//  JSON message which is sent to web page using mg_printf_websocket_frame().
char* timeString = "{\"messageType\":\"serverTime\",\"serverTime\":\"%s\"}";
//  Using defaults for http options in http response.
struct mg_serve_http_opts http_opts = {.document_root = "."};

//  This is the HTTP server handler.  It is also handling Websocket.
//  Not all of the possible events are being handled.
static void ev_handler(struct mg_connection *nc, int ev, void *ev_data, void *user_data) {
	struct http_message *hm = (struct http_message *) ev_data;
	switch (ev) {
	case MG_EV_HTTP_REQUEST: {
		mg_serve_http(nc, hm, http_opts);
		break;
	}
	case MG_EV_SEND: {
		// puts("MG_EV_SEND event fired!");
		break;
	}
	case MG_EV_WEBSOCKET_HANDSHAKE_DONE: {
		//  This sets the periodic time updating in motion.
		mg_set_timer(nc, mg_time() + INTERVAL_SECONDS);
		break;
	}
	case MG_EV_WEBSOCKET_FRAME: {
		// printf("Websocket message received:\n");
		break;
	}
	case MG_EV_CLOSE: {
		break;
	}
	//  The timer event causes a JSON string to be sent to the
	//  webpage via Websocket.
	case MG_EV_TIMER: {
		maintime = time(NULL);
		localstruct = localtime(&maintime);
		strftime(utctime, sizeof(utctime), "%A %B %d %T", localstruct);
		// printf("Time is %s.\n", utctime);
		mg_printf_websocket_frame(nc, WEBSOCKET_OP_TEXT, timeString, utctime);
		//  A new timer is set.
		mg_set_timer(nc, mg_time() + INTERVAL_SECONDS);
		break;
	}
	}
}

enum mgos_app_init_result mgos_app_init(void) {
	struct mg_connection * nc;
	void * user_data = "";

	//  Get the server handle.
	if((nc = mgos_get_sys_http_server()) == NULL) {
		puts("The value of nc is NULL");
	}

	//  Bind the event handler to the HTTP server.
	mgos_register_http_endpoint("/", ev_handler, user_data);

	return MGOS_APP_INIT_SUCCESS;
}
