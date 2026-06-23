# BS2_GetAllAntiPassbackZone

Retrieves all Anti Passback zones.

## Declaration

```cpp
#include "BS_API.h"

int BS2_GetAllAntiPassbackZone(void* context, uint32_t deviceId, BS2AntiPassbackZone** zoneObj, uint32_t* numZone);
```

:::info

 [See BS2AntiPassbackZone Structure](zone control api#BS2AntiPassbackZone) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[Out\] `zoneObj` : Anti Passback zone list pointer

- \[Out\] `numZone` : Number of Anti Passback zones

  **NOTE**

The zoneObj variable needs to return the memory to the system by the [BS2_ReleaseObject](bs2_releaseobject) function after being used.  

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned.

If there is an error, the corresponding error code will be returned.

## See Also

[BS2_GetAntiPassbackZone](bs2_getantipassbackzone)

[BS2_SetAntiPassbackZone](bs2_setantipassbackzone)

[BS2_RemoveAntiPassbackZone](bs2_removeantipassbackzone)

[BS2_RemoveAllAntiPassbackZone](bs2_removeallantipassbackzone)
