# BS2_GetBarcodeConfig

`[+ V2.8]` Retrieves configuration of Barcode of `X-Station 2`.

## Declaration

```cpp
#include "BS_API.h"

int BS2_GetBarcodeConfig(void* context, uint32_t deviceId, BS2BarcodeConfig* config);
```

:::info

 [See BS2BarcodeConfig](configuration api#BS2BarcodeConfig) 

:::

## Parameter

- \[In\] `context` : Context

- \[In\] `deviceId` : Device ID

- \[Out\] `config` : Barcode configurations pointer

## Return Value

If successfully done, `BS_SDK_SUCCESS` will be returned. If there is an error, the corresponding error code will be returned.
