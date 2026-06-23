# BS2_InitializeEx

Initializes the context and initializes the socket with the IP address specified as the second argument.

**NOTE**

It must be called before calling the device control API. 

## Declaration

```cpp
#include "BS_API.h"

int BS2_InitializeEx(void* context, const char* hostIPAddr);
```

## Parameter

- \[In\] `context` : Context

- \[In\] `hostIPAddr` : host IP Address

## Return Value

If successfully done, `BS_SDK_SUCCESS`will be returned. If there is an error, the corresponding error code will be returned.

## Sample Code(C++)

```cpp
void initializeSDK()
{
    void* context_ = BS2_AllocateContext();

    string hostAddr = Utility::getInput<string>("Please enter the host network address.");
    sdkResult = BS2_InitializeEx(context_, hostAddr.c_str());
    if (BS_SDK_SUCCESS != sdkResult)
    {
        TRACE("BS2_InitializeEx call failed: %d", sdkResult);
        BS2_ReleaseContext(context_);
        context_ = NULL;
    }
}
```

## Sample Code(C#)

```csharp
public void initializeSDK()
{
    sdkContext = API.BS2_AllocateContext();
    if (sdkContext == IntPtr.Zero)
    {
        Console.WriteLine("Can't allocate sdk context.");
        return;
    }

    string deviceIpAddress = Console.ReadLine();
    IntPtr ptrIPAddr = Marshal.StringToHGlobalAnsi(deviceIpAddress);

    BS2ErrorCode result = (BS2ErrorCode)API.BS2_InitializeEx(sdkContext, ptrIPAddr);
    if (result != BS2ErrorCode.BS_SDK_SUCCESS)
    {
        Console.WriteLine("SDK initialization failed with : {0}, {1}", result, deviceIpAddress);
        API.BS2_ReleaseContext(sdkContext);
        sdkContext = IntPtr.Zero;
        return;
    }
}
```

