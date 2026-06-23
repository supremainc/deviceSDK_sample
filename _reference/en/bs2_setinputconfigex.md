# BS2_SetInputConfigEx

<Badge only>+ v2.8.1</Badge> `IM-120` Saves Input Expandable Settings.

## Declaration

```cpp
#include "BS_API.h"

int BS2_SetInputConfigEx(void* context, uint32_t deviceId, const BS2InputConfigEx* config);
```

:::info

 [BS2InputConfigEx Structure](configuration api#BS2InputConfigEx) 

:::

## Parameters

- \[In\] `context` : Context

- \[In\] `deviceId` : Device Identifier

- \[In\] `config` : Input Expandable Setting Information Pointer

## Return Values

Return `BS_SDK_SUCCESS` when successful, and return an appropriate error code when an error occurs.
