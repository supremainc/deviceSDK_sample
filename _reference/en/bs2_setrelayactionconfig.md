# BS2_SetRelayActionConfig

<Badge only>+ v2.8.1</Badge> `IM-120` Save RelayAction Settings.

## Declaration

```cpp
#include "BS_API.h"

int BS2_SetRelayActionConfig(void* context, uint32_t deviceId, const BS2RelayActionConfig* config);
```

:::info

 [BS2RelayActionConfig Structure](configuration api#BS2RelayActionConfig) 

:::

## Parameters

- \[In\] `context` : Context

- \[In\] `deviceId` : Device Identifier

- \[In\] `config` : RelayAction Setting Information Pointer

## Return Values

Return `BS_SDK_SUCCESS` when successful, and return an appropriate error code when an error occurs.
