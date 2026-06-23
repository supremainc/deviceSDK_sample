# Wiegand API

Wiegand card reader를 구성하고 Wiegand 입출력을 설정할 수 있습니다.

- [BS2_SearchWiegandDevices](bs2_searchwieganddevices): 물리적으로 연결된 Wiegand card reader를 검색합니다.

- [BS2_GetWiegandDevices](bs2_getwieganddevices): 사용중인 Wiegand card reader를 가져옵니다.

- [BS2_AddWiegandDevices](bs2_addwieganddevices): Wiegand card reader를 추가합니다.

- [BS2_RemoveWiegandDevices](bs2_removewieganddevices): Wiegand card reader를 제거합니다.

**주의**

SDK가 초기화된 상태에서는 Wiegand card reader의 구성을 알 수가 없기 때문에 Wiegand card reader를 제어하기 전에 반드시 Wiegand card reader를 검색하거나 추가해야 합니다. 
