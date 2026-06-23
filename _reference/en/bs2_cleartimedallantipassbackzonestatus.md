# BS2_ClearAllTimedAntiPassbackZoneStatus

Renews all users as not violating the authentication restriction zone rules.

## Function

```cpp

#include "BS_API.h"

int BS2_ClearAllTimedAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID);

```

## Parameters

- \[In\] `context` : Context

- \[In\] `deviceId` : Device identifier

- \[In\] `zoneID` : Zone identifier

## Return Value

Returns `BS_SDK_SUCCESS` on success, and the corresponding error code if an error occurs.

## Together look

[BS2_GetTimedAntiPassbackZone](bs2_gettimedantipassbackzone)

[BS2_GetAllTimedAntiPassbackZone](bs2_getalltimedantipassbackzone)

[BS2_GetTimedAntiPassbackZoneStatus](bs2_gettimedantipassbackzonestatus)

[BS2_GetAllTimedAntiPassbackZoneStatus](bs2_getalltimedantipassbackzonestatus)

[BS2_SetTimedAntiPassbackZone](bs2_settimedantipassbackzone)

[BS2_SetTimedAntiPassbackZoneAlarm](bs2_settimedantipassbackzonealarm)

[BS2_RemoveTimedAntiPassbackZone](bs2_removetimedantipassbackzone)

[BS2_RemoveAllTimedAntiPassbackZone](bs2_removealltimedantipassbackzone)

[BS2_ClearTimedAntiPassbackZoneStatus](bs2_cleartimedantipassbackzonestatus)
