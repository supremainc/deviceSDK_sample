# Server API

API that can enable server matching or controls the device from the BioStar application.

:::warning

Warning

Due to the issues with the management of UFMatcher.dll which was provided by a separate independent Corporation,​ Runnable examples will not be available anymore.

Please reference the prior examples at the code level only. ​

Other technical supports including fingerprint libraries for server matching can be provided by Xperix.

<wrap hi\>Xperix : <https://www.xperix.com/>**

:::

- [BS2_SetServerMatchingHandler](bs2_setservermatchinghandler): Registers the server matching handler.

- [BS2_VerifyUser](bs2_verifyuser): Transfers user information mapped to the card or user ID authentication results to the device.

- [BS2_IdentifyUser](bs2_identifyuser): Transfers user information mapped to the fingerprint authentication results to the device.

- [BS2_VerifyUserEx](bs2_verifyuserex): <Badge only>+ v2.4.0</Badge> Transfers user information mapped to the card or user ID authentication results to the device.

- [BS2_IdentifyUserEx](bs2_identifyuserex): <Badge only>+ v2.4.0</Badge> Transfers user information mapped to the fingerprint authentication results to the device.

- [BS2_VerifyUserSmall](bs2_verifyusersmall): <Badge only>+ v2.6.3</Badge> Transfers user information mapped to the card or user ID authentication results to the device.

- [BS2_IdentifyUserSmall](bs2_identifyusersmall): <Badge only>+ v2.6.3</Badge> Transfers user information mapped to the fingerprint authentication results to the device.

- [BS2_VerifyUserSmallEx](bs2_verifyusersmallex): <Badge only>+ v2.6.3</Badge> Transfers user information mapped to the card or user ID authentication results to the device.

- [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex): <Badge only>+ v2.6.3</Badge> Transfers user information mapped to the fingerprint authentication results to the device.

- [BS2_VerifyUserFaceEx](bs2_verifyuserfaceex): <Badge only>+ v2.7.2</Badge> Transfers user information mapped to the card or user ID authentication results to the device.

- [BS2_SetUserPhraseHandler](bs2_setuserphrasehandler):​ <Badge only>+ v2.7.0</Badge> Registers the server user phrase handler.

- [BS2_ResponseUserPhrase](bs2_responseuserphrase):​ <Badge only>+ v2.7.0</Badge> Transfers the user phrase to the device.

- [BS2_SetBarcodeScanListener](bs2_setbarcodescanlistener): <Badge only>+ v2.8.2</Badge> Register the listener function that detects barcode input.

- [BS2_SetOsdpStandardDeviceStatusListener](bs2_setosdpstandarddevicestatuslistener): <Badge only>+ v2.9.1</Badge> Register a listener function that detects state changes of the OSDP device.

## Callback Function

```cpp
typedef void (*OnVerifyUser)(uint32_t deviceId, uint16_t seq, uint8_t isCard, uint8_t cardType, const uint8_t* data, uint32_t dataLen);
typedef void (*OnIdentifyUser)(uint32_t deviceId, uint16_t seq, uint8_t format, const uint8_t* templateData, uint32_t templateSize);
```

1. `OnVerifyUser`

   Callback function that is called when the BioStar application needs to distinguish whether the card or user ID matches.

1. `OnIdentifyUser`

   Callback function that is called when the BioStar application needs to distinguish whether the fingerprint matches.

### OnUserPhrase

Callback function asking for user phrase to the server.

```cpp
typedef void (*OnUserPhrase)(uint32_t deviceId, uint16_t seq, const char* userID);
```

1. `deviceId`

   Device ID

1. `seq`

   Packet sequence

1. `userID`

   User ID

### OnBarcodeScanned

Callback function called when barcode is scanned on the device.

```cpp
typedef void (*OnBarcodeScanned)(uint32_t deviceId, const char* barcode);
```

1. `deviceId`

   Device ID that sent the scanned barcode.

1. `barcode`

   Barcode string read from device.

### OnOsdpStandardDeviceStatusChanged

This is a callback function that is called when the state of the OSDP device changes.

```cpp
typedef void (*OnOsdpStandardDeviceStatusChanged)(uint32_t deviceId, const BS2OsdpStandardDeviceNotify* notifyData);
```

1. `deviceId`

   OSDP device identifier.

1. `notifyData`

   OSDP device information.
