# BS2_SetBarcodeConfig

`[+ V2.8]` Stores configuration of Barcode of `X-Station 2`.

## Declatation

```cpp
#include "BS_API.h"

int BS2_SetBarcodeConfig(void* context, uint32_t deviceId, BS2BarcodeConfig* config);
```

:::info

 [See BS2BarcodeConfig](configuration api#BS2BarcodeConfig) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[In\] `config` : Barcode configurations pointer

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned. If there is an error, the corresponding error code will be returned.
