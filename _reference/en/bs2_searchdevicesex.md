# BS2_SearchDevicesEx

Search for devices in a specific IP address band and update the list of devices available in the current context. The list of devices can be obtained via the [BS2_GetDevices](bs2_getdevices) function.

**NOTE**

Overwrite the old device list. 

## Declaration

```cpp
#include "BS_API.h"

int BS2_SearchDevicesEx(void* context, const char* hostipAddr);
```

## Parameter

- \[In\] `context` : Context

- \[In\] `hostipAddr` : Address of the UDP range

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned.

If there is an error, the corresponding error code will be returned.

## See Also

[BS2_GetDevices](bs2_getdevices)
