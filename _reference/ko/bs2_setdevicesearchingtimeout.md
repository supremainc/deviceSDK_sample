# BS2_SetDeviceSearchingTimeout

장치 검색 시간을 설정합니다.

## Declaration

```cpp
#include "BS_API.h"

int BS2_SetDeviceSearchingTimeout(void* context, uint32_t second);
```

## Parameter

- \[In\] `context` : Context

- \[In\] `second` : Device searching timeout

  **NOTE**

Timeout 기본 값은 5초 입니다.  

## 반환값

성공적으로 수행될 경우 BS_SDK_SUCCESS를 반환하고, 에러가 발생할 경우 상응하는 에러 코드를 반환합니다.
