# Communication API

장치 통신을 제어하는 API로써 통신 인터페이스는 LAN, USB, RS485 등이 있습니다. 실시간으로 장치의 연결유무와 탐색 결과를 받으려면 [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener) 함수를 통해 콜백 함수를 등록하십시오.

- [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener): 장치 검색, 네트워크 연결 Event listener를 설정합니다.

- [BS2_SearchDevices](bs2_searchdevices): Subnet에서 장치를 검색합니다.

- [BS2_SearchDevicesEx](bs2_searchdevicesex): 특정 IP주소 대역의 장치를 검색합니다.

- [BS2_GetDevices](bs2_getdevices): 관리되고 있는 장치 정보를 가져옵니다.

- [BS2_ConnectDevice](bs2_connectdevice): 장치 식별자를 이용해 장치를 연결합니다.

- [BS2_ConnectDeviceIPV6](bs2_connectdeviceipv6): 장치 식별자를 이용해 장치를 IPv6 모드로 연결합니다.

- [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip): IP주소와 Port를 이용해 장치를 연결합니다.

- [BS2_DisconnectDevice](bs2_disconnectdevice): 장치와의 연결을 해제합니다.

- [BS2_SetKeepAliveTimeout](bs2_setkeepalivetimeout): Keep-alive timeout을 설정합니다.

- [BS2_SetNotificationListener](bs2_setnotificationlistener): Notification listener를 설정합니다.

- [BS2_SetServerPort](bs2_setserverport): Server Port를 설정합니다.

- [BS2_SetSSLServerPort](bs2_setsslserverport): Server의 SSL Port를 설정합니다.

- [BS2_GetServerPort](bs2_getserverport): <Badge only>+ v2.6.3</Badge> Server Port 설정을 확인합니다.

- [BS2_GetSSLServerPort](bs2_getsslserverport): <Badge only>+ v2.6.3</Badge> Server의 SSL Port 설정을 확인합니다.

- [BS2_IsConnected](bs2_isconnected): 장치의 연결 상태를 확인합니다.

- [BS2_IsAutoConnection](bs2_isautoconnection): 자동연결 설정 여부를 확인합니다.

- [BS2_SetAutoConnection](bs2_setautoconnection): 자동연결을 설정합니다.

- [BS2_GetEnableIPV4](bs2_getenableipv4): <Badge only>+ v2.6.3</Badge> IP V4 연결모드 여부를 확인합니다.

- [BS2_SetEnableIPV4](bs2_setenableipv4): <Badge only>+ v2.6.3</Badge> IP V4 연결모드로 설정합니다.

- [BS2_GetEnableIPV6](bs2_getenableipv6): <Badge only>+ v2.6.3</Badge> IP V6 연결모드 여부를 확인합니다.

- [BS2_SetEnableIPV6](bs2_setenableipv6): <Badge only>+ v2.6.3</Badge> IP V6 연결모드로 설정합니다.

- [BS2_SetServerPortIPV6](bs2_setserverportipv6): <Badge only>+ v2.6.3</Badge> IP V6를 이용하여 서버모드 연결 시 연결 port를 정의합니다.

- [BS2_GetServerPortIPV6](bs2_getserverportipv6): <Badge only>+ v2.6.3</Badge> IP V6를 이용하여 서버모드 연결 시 연결 port 정보를 확인합니다.

- [BS2_SetSSLServerPortIPV6](bs2_setsslserverportipv6): <Badge only>+ v2.6.3</Badge> IP V6와 ssl을 이용하여 서버모드 연결 시 연결 port를 정의합니다.

- [BS2_GetSSLServerPortIPV6](bs2_getsslserverportipv6): <Badge only>+ v2.6.3</Badge> IP V6와 ssl을 이용하여 서버모드 연결 시 연결 port 정보를 확인합니다.

- [BS2_SetDefaultResponseTimeout](bs2_setdefaultresponsetimeout): <Badge only>+ v2.6.3</Badge> 장치와의 패킷 응답 대기시간을 설정합니다.

- [BS2_GetDefaultResponseTimeout](bs2_getdefaultresponsetimeout): <Badge only>+ v2.6.3</Badge> 장치와의 패킷 응답 대기시간 정보를 확인합니다.

- [BS2_GetSocketRetryCount](bs2_getsocketretrycount): <Badge only>+ v2.9.1</Badge> Non SSL 통신시, 읽기/쓰기 실패에대한 재시도 횟수 설정 값을 가져옵니다.

- [BS2_SetSocketRetryCount](bs2_setsocketretrycount): <Badge only>+ v2.9.1</Badge> Non SSL 통신시, 읽기/쓰기 실패에대한 재시도 횟수를 설정합니다.

- [BS2_GetSocketSSLRetryCount](bs2_getsocketsslretrycount): <Badge only>+ v2.9.1</Badge> SSL 통신시, 읽기/쓰기 실패에대한, 재시도 횟수 설정 값을 가져옵니다.

- [BS2_SetSocketSSLRetryCount](bs2_setsocketsslretrycount): <Badge only>+ v2.9.1</Badge> SSL 통신시, 읽기/쓰기 실패에대한, 재시도 횟수를 설정합니다.

- [BS2_SetDefaultLongResponseTimeout](bs2_setdefaultlongresponsetimeout): <Badge only>+ v2.9.12</Badge> 장치와의 패킷 응답 대기시간을 설정합니다. (시간이 많이 소요되는 API)

- [BS2_GetDefaultLongResponseTimeout](bs2_getdefaultlongresponsetimeout): <Badge only>+ v2.9.12</Badge> 장치와의 패킷 응답 대기시간 정보를 확인합니다. (시간이 많이 소요되는 API)

## 콜백 함수

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

   Subnet에서 새로운 BioStar 장치를 찾았을 때 호출되는 콜백 함수입니다.

1. `OnDeviceAccepted`

   BioStar 장치가 BioStar 애플리케이션으로 연결을 요청할 때 호출되는 콜백 함수입니다.

1. `OnDeviceConnected`

   장치와 BioStar 애플리케이션이 연결되었을 때 호출되는 콜백 함수입니다.

1. `OnDeviceDisconnected`

   장치와 BioStar 애플리케이션의 연결이 끊어졌을 때 호출되는 콜백 함수입니다.

1. `OnAlarmFired`

   Zone에 설정한 알람이 발생되면 호출되는 콜백 함수입니다.

1. `OnInputDetected`

   입력 신호가 발생되면 호출되는 콜백 함수입니다.

1. `OnConfigChanged`

   단말기를 조작하여 Configuration이 변경될 때 호출되는 콜백 함수입니다.