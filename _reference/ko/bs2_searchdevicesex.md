# BS2_SearchDevicesEx

특정 IP 주소 대역의 장치를 검색하고 현재 Context에 가용한 장치 목록을 갱신합니다. 장치 목록은 [BS2_GetDevices](bs2_getdevices) 함수를 통해 가져올 수 있습니다.

**참고**

이전의 장치 목록을 덮어씁니다. 

## 함수

```cpp
#include "BS_API.h"

int BS2_SearchDevices(void* context, const char* hostipAddr);
```

## 파라미터

- \[In\] `context` : Context

- \[In\] `hostipAddr` : Address of the UDP range

## 반환값

성공적으로 수행될 경우 `BS_SDK_SUCCESS`를 반환하고, 에러가 발생할 경우 상응하는 에러 코드를 반환합니다.

## 함께 보기

[BS2_GetDevices](bs2_getdevices)
