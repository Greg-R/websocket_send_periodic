/*
 * Generated file - do not edit.
 * Command: /mongoose-os/fw/tools/gen_sys_config.py --c_name=sys_config --dest_dir=/fwbuild-volumes/1.17/apps/mjs-latest/esp32/build_contexts/build_ctx_165162746/build/gen/ /mongoose-os/fw/src/mgos_debug_udp_config.yaml /mongoose-os/fw/src/mgos_sntp_config.yaml /mongoose-os/fw/platforms/esp32/src/esp32_config.yaml /mongoose-os/fw/src/mgos_sys_config.yaml /mongoose-os/fw/platforms/esp32/src/esp32_sys_config.yaml /fwbuild-volumes/1.17/apps/mjs-latest/esp32/build_contexts/build_ctx_165162746/build/gen/mos_conf_schema.yml
 */

#ifndef SYS_CONFIG_H_
#define SYS_CONFIG_H_

#include "mgos_config.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct sys_config_sntp {
  int enable;
  char *server;
  int retry_min;
  int retry_max;
  int update_interval;
};

struct sys_config_device {
  char *id;
  char *password;
};

struct sys_config_debug {
  char *udp_log_addr;
  int mbedtls_level;
  int level;
  char *filter;
  int stdout_uart;
  int stderr_uart;
  int factory_reset_gpio;
  char *mg_mgr_hexdump_file;
};

struct sys_config_sys_mount {
  char *path;
  char *dev_type;
  char *dev_opts;
  char *fs_type;
  char *fs_opts;
};

struct sys_config_sys {
  struct sys_config_sys_mount mount;
  int wdt_timeout;
  char *tz_spec;
};

struct sys_config_wifi_sta {
  int enable;
  char *ssid;
  char *pass;
  char *user;
  char *anon_identity;
  char *cert;
  char *key;
  char *ca_cert;
  char *ip;
  char *netmask;
  char *gw;
  char *nameserver;
  char *dhcp_hostname;
};

struct sys_config_wifi_ap {
  int enable;
  char *ssid;
  char *pass;
  int hidden;
  int channel;
  int max_connections;
  char *ip;
  char *netmask;
  char *gw;
  char *dhcp_start;
  char *dhcp_end;
  int trigger_on_gpio;
  int keep_enabled;
};

struct sys_config_wifi {
  struct sys_config_wifi_sta sta;
  struct sys_config_wifi_ap ap;
};

struct sys_config_http {
  int enable;
  char *listen_addr;
  char *document_root;
  char *ssl_cert;
  char *ssl_key;
  char *ssl_ca_cert;
  char *upload_acl;
  char *hidden_files;
  char *auth_domain;
  char *auth_file;
};

struct sys_config_rpc_ws {
  int enable;
  char *server_address;
  int reconnect_interval_min;
  int reconnect_interval_max;
  char *ssl_server_name;
  char *ssl_ca_file;
  char *ssl_client_cert_file;
};

struct sys_config_rpc_uart {
  int uart_no;
  int baud_rate;
  int fc_type;
  int wait_for_start_frame;
};

struct sys_config_rpc {
  int enable;
  int max_frame_size;
  int max_queue_length;
  int default_out_channel_idle_close_timeout;
  char *acl_file;
  char *auth_domain;
  char *auth_file;
  struct sys_config_rpc_ws ws;
  struct sys_config_rpc_uart uart;
};

struct sys_config {
  struct sys_config_sntp sntp;
  struct sys_config_device device;
  struct sys_config_debug debug;
  struct sys_config_sys sys;
  char *conf_acl;
  struct sys_config_wifi wifi;
  struct sys_config_http http;
  struct sys_config_rpc rpc;
};


const struct mgos_conf_entry *sys_config_schema();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SYS_CONFIG_H_ */
