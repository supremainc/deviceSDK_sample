# BS2_GetDeviceInfoEx

Retrives not only information that can be retrieved via BS2SimpleDeviceInfo, such as device ID, type, network information, and property information, but also additional information such as iClass SEOS card, daylight saving time information.

## Declaration

```cpp
#include "BS_API.h"

int BS2_GetDeviceInfoEx(void* context, uint32_t deviceId, BS2SimpleDeviceInfo* deviceInfo, BS2SimpleDeviceInfoEx* deviceInfoEx);
```

:::info

 [BS2SimpleDeviceInfoEx Structure](device_api#BS2SimpleDeviceInfoEx) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[Out\] `deviceInfo` : Device information settings pointer

- \[Out\] `deviceInfoEx` : Device additional information settings pointer

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned.

If there is an error, the corresponding error code will be returned.
