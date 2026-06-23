# BS2_SetRS485Config

Stores RS-485 network settings on the device.

## Declaration

```cpp
#include "BS_API.h"

int BS2_SetRS485Config(void* context, uint32_t deviceId, BS2Rs485Config* config);
```

:::info

 [See BS2Rs485Config Structure](configuration api#BS2Rs485Config) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[In\] `config` : RS-485 network configurations pointer

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned.

If there is an error, the corresponding error code will be returned.
