# Communication API

As API that configures the SSL communication, there are communication interfaces include LAN, USB, and RS485. To get real-time device connectivity and search results, please register the callback function via the [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener) function.

- [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener): Sets device search and network connection event listener.

- [BS2_SearchDevices](bs2_searchdevices): Search for devices in subnet.

- [BS2_SearchDevicesEx](bs2_searchdevicesex): Search for devices in a specific IP address band.

- [BS2_GetDevices](bs2_getdevices): Gets the managed device information.

- [BS2_ConnectDevice](bs2_connectdevice): Connects the device using the device identifier.

- [BS2_ConnectDeviceIPV6](bs2_connectdeviceipv6): Connects the device in IPv6 mode using the device identifier.

- [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip): Connect devices using IP address and Port.

- [BS2_DisconnectDevice](bs2_disconnectdevice): Disconnects from the device.

- [BS2_SetKeepAliveTimeout](bs2_setkeepalivetimeout): Sets the keep-alive timeout.

- [BS2_SetNotificationListener](bs2_setnotificationlistener): Sets the Notification listener.

- [BS2_SetServerPort](bs2_setserverport): Sets the server Port.

- [BS2_SetSSLServerPort](bs2_setsslserverport): Sets the SSL server Port.

- [BS2_GetServerPort](bs2_getserverport): <Badge only>+ v2.6.3</Badge> Gets the server Port.

- [BS2_GetSSLServerPort](bs2_getsslserverport): <Badge only>+ v2.6.3</Badge> Gets the SSL server port.

- [BS2_IsConnected](bs2_isconnected): Checks device connection status.

- [BS2_IsAutoConnection](bs2_isautoconnection): Checks auto connection status.

- [BS2_SetAutoConnection](bs2_setautoconnection): Sets auto connection.

- [BS2_GetEnableIPV4](bs2_getenableipv4): <Badge only>+ v2.6.3</Badge> Gets IPv4 connection mode.

- [BS2_SetEnableIPV4](bs2_setenableipv4): <Badge only>+ v2.6.3</Badge> Sets IPv4 connection mode.

- [BS2_GetEnableIPV6](bs2_getenableipv6): <Badge only>+ v2.6.3</Badge> Gets IPv6 connection mode.

- [BS2_SetEnableIPV6](bs2_setenableipv6): <Badge only>+ v2.6.3</Badge> Sets IPv6 connection mode.

- [BS2_SetServerPortIPV6](bs2_setserverportipv6): <Badge only>+ v2.6.3</Badge> Sets server port when connecting IPv6 server mode.

- [BS2_GetServerPortIPV6](bs2_getserverportipv6): <Badge only>+ v2.6.3</Badge> Gets server port when connecting IPv6 server mode.

- [BS2_SetSSLServerPortIPV6](bs2_setsslserverportipv6): <Badge only>+ v2.6.3</Badge> Sets server port when connecting IPv6 server mode using SSL.

- [BS2_GetSSLServerPortIPV6](bs2_getsslserverportipv6): <Badge only>+ v2.6.3</Badge> Gets server port when connecting IPv6 server mode using SSL.

- [BS2_SetDefaultResponseTimeout](bs2_setdefaultresponsetimeout): <Badge only>+ v2.6.3</Badge> Sets default response timeout between device and server.

- [BS2_GetDefaultResponseTimeout](bs2_getdefaultresponsetimeout): <Badge only>+ v2.6.3</Badge> Gets default response timeout between device and server.

- [BS2_GetSocketRetryCount](bs2_getsocketretrycount): <Badge only>+ v2.9.1</Badge> Gets the setting value of the number of retries for read/write failures during Non SSL communication.

- [BS2_SetSocketRetryCount](bs2_setsocketretrycount): <Badge only>+ v2.9.1</Badge> Set the number of retries for read/write failures during Non SSL communication.

- [BS2_GetSocketSSLRetryCount](bs2_getsocketsslretrycount): <Badge only>+ v2.9.1</Badge> Gets the setting value of the number of retries for read/write failures during SSL communication.

- [BS2_SetSocketSSLRetryCount](bs2_setsocketsslretrycount): <Badge only>+ v2.9.1</Badge> Set the number of retries for read/write failures during SSL communication.

- [BS2_SetDefaultLongResponseTimeout](bs2_setdefaultlongresponsetimeout): <Badge only>+ v2.9.12</Badge> Sets the packet response timeout with the device. (For time-intensive APIs)

- [BS2_GetDefaultLongResponseTimeout](bs2_getdefaultlongresponsetimeout): <Badge only>+ v2.9.12</Badge> Checks the packet response timeout information with the device. (For time-intensive APIs)

## Callback Function

```cpp
typedef void (*OnDeviceFound)(uint32_t deviceId);
typedef void (*OnDeviceAccepted)(BS2_DEVICE_ID deviceId);
typedef void (*OnDeviceConnected)(uint32_t deviceId);
typedef void (*OnDeviceDisconnected)(uint32_t deviceId);
typedef void (*OnAlarmFired)(BS2_DEVICE_ID deviceId, const BS2Event* event);
typedef void (*OnInputDetected)(BS2_DEVICE_ID deviceId, const BS2Event* event);
typedef void (*OnConfigChanged)(BS2_DEVICE_ID deviceId, uint32_t configMask);
```

1. `OnDeviceFound`

   Callback function that is called when a new BioStar device is found in Subnet.

1. `OnDeviceAccepted`

   Callback function that is called when the BioStar device requests a connection to the BioStar application.

1. `OnDeviceConnected`

   Callback function that is called when the device and the BioStar application are connected.

1. `OnDeviceDisconnected`

   Callback function that is called when the connection between the device and the BioStar application is lost.

1. `OnAlarmFired`

   Callback function that is called when an alarm set in the Zone occurs.

1. `OnInputDetected`

   Callback function that is called when an input signal is generated.

1. `OnConfigChanged`

   Callback function that is called when the configuration is changed by manipulating the terminal.