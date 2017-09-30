This Mongoose-OS project uses the ESP32 by Espressif.

The device is configured as a web server.
Websocket is used to connect the device to a browser.

The device periodically sends a JSON string via the Websocket.
The incoming JSON is parsed by Javascript and is used to update
a time display in the web page.

The project is intended to be used with a wireless router.
The file

fs/conf9.json

determines the configuration of the device as a station.
The SSID and password should be edited for the user's system.
It is also possible to configure the device as an access
point.

To use browse to the URL:

http://192.168.1.3/websocketclock.html

The above is an example.  You will need to use your router
to determine the assigned IP address.  This can also be
seen using

mos console

at the command line.  The device will connect and this
will appear in the console output.
