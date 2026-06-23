# SDK API

The followings are a set of APIs that initialize device management information and that are used for dynamic memory control and PIN code generation.

* [BS2_Version](bs2_version): Returns the SDK version.

- [BS2_AllocateContext](bs2_allocatecontext): Allocates the device management Context.

- [BS2_ReleaseContext](bs2_releasecontext): Releases the device management Context.

- [BS2_Initialize](bs2_initialize): Initializes the device management Context.

- [BS2_ReleaseObject](bs2_releaseobject): Releases dynamic memory.

- [BS2_MakePinCode](bs2_makepincode): Encrypts the PIN.

- [BS2_MakePinCodeWithKey](bs2_makepincodewithkey):​ Encryptes PIN code with the user-defined PIN encryption key. <Badge only>+ v2.7.1</Badge>

- [BS2_SetMaxThreadCount](bs2_setmaxthreadcount): Specifies the maximum thread count.

- [BS2_ComputeCRC16CCITT](bs2_computecrc16ccitt): Calculates the CRC-16 CCITT checksum.

- [BS2_GetCardModel](bs2_getcardmodel): Retrieves the supported card models.

- [BS2_SetDataEncryptKey](bs2_setdataencryptkey): Changes the user defined PIN encryption key. <Badge only>+ v2.7.1</Badge>

- [BS2_RemoveDataEncryptKey](bs2_removedataencryptkey): Removes the encryption key for the device.

- [BS2_SetDeviceSearchingTimeout](bs2_setdevicesearchingtimeout) : Specifies the device searching time.

- [BS2_SetDebugFileLog](bs2_setdebugfilelog) : Retrieves debugging file log.

- [BS2_EnableDeviceLicense](bs2_enabledevicelicense): <Badge only>+ v2.9.1</Badge> Activate the device license.

- [BS2_DisableDeviceLicense](bs2_disabledevicelicense): <Badge only>+ v2.9.1</Badge> Deactivate the device license.

- [BS2_QueryDeviceLicense](bs2_querydevicelicense): <Badge only>+ v2.9.1</Badge> Check device license information.

- [BS2_InitializeEx](bs2_initializeex): <Badge only>+ v2.9.6</Badge> Initializes the device management context.

## Structure

### BS2EncryptKey

```cpp
enum
{
    BS2_ENC_KEY_SIZE = 32,
};

typedef struct
{
    uint8_t key[BS2_ENC_KEY_SIZE];
    uint8_t reserved[32];
} BS2EncryptKey;
```

1. `key`

   The key value used by the device.

1. `reserved`

   Reserved space.

### BS2LicenseBlob

```cpp
typedef struct {
    BS2_LICENSE_TYPE    licenseType;
    uint16_t            numOfDevices;
    BS2_DEVICE_ID*      deviceIDObjs;
    uint32_t            licenseLen;
    uint8_t*            licenseObj;
} BS2LicenseBlob;
```

1. `licenseType`

   The type of license.

   | Value | Description |
   | --- | --- |
   | 0x0000 | None |
   | 0x0001 | Visual QR |

1. `numOfDevices`

   Number of licenses activated devices.

1. `deviceIDObjs`

   Slave devices for which license information will be issued.

1. `licenseLen`

   license activation file size.

1. `licenseObj`

   License activation data block.

### BS2LicenseResult

```cpp
typedef struct {
    BS2_DEVICE_ID       deviceID;
    BS2_LICENSE_STATUS  status;
} BS2LicenseResult;
```

1. `deviceID`

   Device identifier.

1. `status`

   License status information.

   | Value | Description |
   | --- | --- |
   | 0 | Not supported |
   | 1 | Disable |
   | 2 | Enable |
   | 3 | Expired |
