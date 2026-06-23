# BS2_GetDeviceInfo

Gets the device ID, type, network information, and configuration.

## Declaration

```cpp
#include "BS_API.h"

int BS2_GetDeviceInfo(void* context, uint32_t deviceId, BS2SimpleDeviceInfo* deviceInfo);
```

:::info

 [See BS2SimpleDeviceInfo Structure](device_api#BS2SimpleDeviceInfo) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[Out\] `deviceInfo` : Pointer to store device information

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned.

If there is an error, the corresponding error code will be returned.
