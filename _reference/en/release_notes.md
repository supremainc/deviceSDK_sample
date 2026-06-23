# Release Notes

# Version 2.9.12 (v2.9.12.0)

## Date

2026-01-30

## New Features

- Supported XPass Q2 (XPQ2-DB, XPQ2-APB)

- Supported BioStation 3 Max (BS3M-DB, BS3M-APB, BS3M-ODB, BS3M-OAPB)

- Added Master Admin configuration feature

- Added Lock Override feature

- Added Door Mode Override feature

- Added User Override feature

- Added configuration for response timeout of long-processing functions

1. Supports new devices.

* XPass Q2 (XPQ2-DB, XPQ2-APB)

- BioStation 3 Max (BS3M-DB, BS3M-APB, BS3M-ODB, BS3M-OAPB)

1. Added a feature to configure the Master Admin on the device.

   Please refer to the linked API descriptions below for supported devices and firmware versions.

- Add API [BS2_GetMasterAdmin](bs2_getmasteradmin)

- Add API [BS2_SetMasterAdmin](bs2_setmasteradmin)

- Refer to structure [BS2SystemConfig](configuration_api#bs2systemconfig)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Added Lock Override feature for emergency door opening.

   Cards enrolled via Lock Override can bypass the door lock status and open the door.

- Add API [BS2_GetLockOverride](bs2_getlockoverride)

- Add API [BS2_GetAllLockOverride](bs2_getalllockoverride)

- Add API [BS2_SetLockOverride](bs2_setlockoverride)

- Add API [BS2_RemoveLockOverride](bs2_removelockoverride)

- Add API [BS2_RemoveAllLockOverride](bs2_removealllockoverride)

- Add structure [BS2LockOverride](smartcard_api#bs2lockoverride)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Added Timed Door Lock/Unlock (Door Mode Override) feature.

- Add API [BS2_TimedLockDoor](bs2_timedlockdoor)

- Add API [BS2_TimedUnlockDoor](bs2_timedunlockdoor)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Added Extended Door Open Time (User Override) feature.

- Add API [BS2_GetUserOverride](bs2_getuseroverride)

- Add API [BS2_GetAllUserOverride](bs2_getalluseroverride)

- Add API [BS2_SetUserOverride](bs2_setuseroverride)

- Add API [BS2_RemoveUserOverride](bs2_removeuseroverride)

- Add API [BS2_RemoveAllUserOverride](bs2_removealluseroverride)

- Refer to structure [BS2Door](door_control_api#bs2door)

- Add structure [BS2UserOverride](user_management_api#bs2useroverride)

1. Added a feature to retrieve the current I/O port status of the device.

- Add API [BS2_GetDeviceIOStatus](bs2_getdeviceiostatus)

- Add API [BS2_GetAllDeviceIOStatus](bs2_getalldeviceiostatus)

- Add structure [BS2IOStatus](Log_Management_API#bs2iostatus)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Allows manual configuration of the response timeout for some APIs that require a long processing time.

* Add API [BS2_SetDefaultLongResponseTimeout](bs2_setdefaultlongresponsetimeout)

- Add API [BS2_GetDefaultLongResponseTimeout](bs2_getdefaultlongresponsetimeout)

## Fixed Features

1. Restricted controlling slave devices using the [BS2_RunAction](bs2_runaction) API.

   However, it works normally for slave panels such as DI-24.

1. Fixed an issue where a crash could occur in the SDK internal timer manager module (Specific to v2.9.6.1).

1. Improved internal logic for SDK code stability.

---

# Version 2.9.9 (v2.9.9.0)

## Date

2025-6-13

## New Features

- Supports selection of AES128 or Crypto1 encryption methods for Mifare Plus cards

- Supports new devices: CoreStation 20 (CS-20, CS-20P) and Door Interface (DI-24)

1. Added option to select either AES128 or Crypto1 encryption methods for Mifare Plus cards.

* Currently, this feature is supported only on XPass 2 v1.4.3 and XPass D2 v1.8.2.

- Refer to structure [BS2CardConfig](configuration_api#bs2cardconfig)

- Refer to structure [BS2CustomCardConfig](configuration_api#bs2customcardconfig)

- Refer to structure [BS2MifareCardConfigEx](configuration_api#bs2mifarecardconfigex)

1. Supports new devices.

- CoreStation 20(CS-20, CS-20P)

- Door Interface(DI-24)

- Refer to structure [BS2InputConfigEx](configuration_api#bs2inputconfigex)

- Refer to structure [BS2Rs485ConfigEXDynamic](configuration_api#bs2rs485configexdynamic)

  - Add API [bs2_getrs485configexdynamic](bs2_getrs485configexdynamic), [BS2_SetRS485ConfigExDynamic](bs2_setrs485configexdynamic)

- Refer to structure [BS2FacilityCodeConfig](configuration_api#bs2facilitycodeconfig)

  - Add API [BS2_GetFacilityCodeConfig](bs2_getfacilitycodeconfig), [BS2_SetFacilityCodeConfig](bs2_setfacilitycodeconfig)

- Refer to structure [BS2Rs485ConfigEXDynamic](configuration_api#bs2rs485configexdynamic)

==== Modified Features ==== \1. Fixes were made to stabilize the code internally in the SDK.

1. Improved Card ID handling for SCC smart cards in the card sample source.

---

# Version 2.9.8 (v2.9.8.0)

## Date

2024-9-30

## New Features

- Supports a feature that allows selecting how the user ID or name are displayed on the authentication result screen of the device.

- Supports a feature that selects the SIP transmission method of Intercom on the BioStation 3.

- Supports a feature of selecting the resolution of the video output when using Intercom and RTSP.

- Added an option that allows rejecting authentication for users wearing a mask during face authentication.

- Added an option to enable or disable the Scramble Keypad, which randomizes the position of numeric keys when entering a PIN on the X-Station 2.

- Added feature to set the RS-485 baud rate of slave devices.

- Added feature to set the Aux Input of the CoreStation.

1. Added a feature that allows selecting how the user ID or name are displayed on the authentication result screen of the device.

* Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig) - authMsgUserName, authMsgUserID

1. Added a setting to allow changing the data transmission method of the IP intercom on BioStation 3 to UDP, TCP, or TLS.

- Refer to the structure [BS2VoipConfigExt](configuration_api#bs2voipconfigext) - transport (Supported Device: BioStation 3)

1. Added a setting to allow selecting the video resolution for streaming when using IP intercom and RTSP on BioStation 3.

- Refer to the structure [BS2VoipConfigExt](configuration_api#bs2voipconfigext) - resolution (Supported Device: BioStation 3)

- Refer to the structure [BS2RtspConfig](configuration_api#bs2rtspconfig) - resolution (Supported Device: BioStation 3, BioEntry W3)

1. Added an option to reject authentication for users wearing masks during face authentication. This feature only applies to face authentication devices based on visual faces, such as BioStation 3, FaceStation F2, and BioEntry W3.

* Refer to the structure [BS2FaceConfigExt](configuration_api#bs2faceconfigext) - maskCheckMode

- Refer to the structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities) - authDenyMaskSupported

1. Added a feature to X-Station 2 to enable a scramble keypad that randomly changes the position of number keys when entering a PIN.

- Refer to the structure [BS2DisplayConfig](configuration_api#bs2displayconfig) - scrambleKeyboardMode

- Refer to the structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities) - scrambleKeyboardModeSupported

1. Added feature to set the RS-485 baud rate of slave devices.

- Add API [bs2_setslavebaudrate](bs2_setslavebaudrate)

1. Added a feature the Aux Input setting feature for CoreStation40.

- Refer to the structure [BS2InputConfig](configuration_api#bs2inputconfig) - aux

## Modified Features

1. Fixed a memory error that occurred when executing BS2_ReleaseContext() in C++(x64) debug mode.

1. Fixed the issue where real-time logs could not be received when reconnecting using BS2_SetAutoConnection.

1. Applied SONAME to the header of the so Linux Library files.

1. Removed the 'Not use' value in the mode of the BS2_RS485Config and BS2_RS485ConfigEx structures.

1. Improved C# Sample Source

* Improved the ConfigControl example to allow selecting slave devices when performing getDeviceCapabilities().

- Improved memory release for imagedata in the UserControl example.

- Improved the conversion method for wiegandDeviceID in the SlaveControl example.

---

# Version 2.9.6 (V2.9.6.0)

## Date

2024-02-05

## New Features

- BioEntry W3 connection support (Device name: BEW3-DB, BEW3-APB).

- XPass 2 connection support (Device name: XP2-MAPB).

- Support for storing only the template when saving facial information.

- Added feature to ignore repetitive input signals when using third-party controllers connected via Wiegand.

- Supports displaying authentication success/failure results from third-party controllers on Suprema devices.

- Added function to initialize by selecting a network.

1. Supports new devices.

* BioEntry W3 (BEW3-DB, BEW3-APB)

- XPass 2 (XP2-MAPB)

1. Added feature to allow transmitting only the template, excluding the facial image, when sending facial data.

   This is particularly useful in environments where privacy protection is emphasized.

   This feature only applies to face authentication devices based on visual face, such as BioStation 3, FaceStation F2, and BioEntry W3.

- Refer to structure [BS2FaceConfig](configuration_api#bs2faceconfig)

- Refer to structure [BS2FaceEx](face_api#bs2faceex)

1. In environments where Suprema devices are connected to third-party controllers via Wiegand, if the feedback for authentication is repetitively input to the Suprema device from a specific model of the controller, a feature has been added to ignore this.

- Refer to structure [BS2Trigger](configuration_api#bs2trigger)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Added feature to display authentication results on the device screen when Suprema devices are connected to third-party controllers as peripheral devices.

- Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. Added function to initialize by selecting a network.

   When connected to multiple networks, specifying a particular network for initialization allows for searching for devices on that sub-network after performing initialization.

- Add API [BS2_InitializeEx](bs2_initializeex)

## Modified Features

1. Fixed an issue where a BS_SDK_ERROR_NOT_SUPPORTED error would occur when importing or setting face configuration on CoreStation 40.

- Refer to API [BS2_GetFaceConfig](bs2_getfaceconfig)

- Refer to API [BS2_SetFaceConfig](bs2_setfaceconfig)

- Refer to structure [BS2FaceConfig](configuration_api#bs2faceconfig)

1. The device log filtering API [BS2_GetFilteredLog](bs2_getfilteredlog), [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid) has been `Deprecated`.

   It is recommended that filtering be performed on the server using [BS2_GetLog](bs2_getlog) and [BS2_StartMonitoringLog](bs2_startmonitoringlog).

- Refer to API [BS2_GetFilteredLog](bs2_getfilteredlog)

- Refer to API [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid)

- Refer to API [BS2_GetLog](bs2_getlog)

- Refer to API [BS2_StartMonitoringLog](bs2_startmonitoringlog)

- Refer to API [BS2_StopMonitoringLog](bs2_stopmonitoringlog)

1. Fixes were made to stabilize the code internally in the SDK.

---

# Version 2.9.4 (V2.9.4.0)

## Date

2023-08-08

## New Features

- BioStation 2a connection support (Device name: BS2A-ODPB, BS2A-OAPWB)

- Read support with Custom smart card

1. New device BioStation 2a connection is supported.

1. Support for reading Custom smart card.

- Refer to structure [BS2CustomMifareCard](configuration_api#bs2custommifarecard)

- Add structure [BS2CustomDesFireCard](configuration_api#bs2customdesfirecard)

- Add structure [BS2CustomCardConfig](configuration_api#bs2customcardconfig)

- Add API [BS2_GetCustomCardConfig](bs2_getcustomcardconfig)

- Add API [BS2_SetCustomCardConfig](bs2_setcustomcardconfig)

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

## Modified Features

1. Supported Linux environments have been upgraded to Ubuntu 22.04.

   | SDK Version | Supported Linux Version |
   | --- | --- |
   | Before V2.9.4 | Ubuntu 18.04 |
   | Later V2.9.4 | Ubuntu 22.04 |

1. Fixes were made to stabilize the code internally in the SDK.

---

# Version 2.9.1 (V2.9.1.0)

## Date

2023-02-23

## New Features

- Supports activating licenses for use of specific features on devices.

- QR code recognition and authentication support using the camera.

- Support setting the number of retries in case of socket read/write failure.

- Supports 3rd party OSDP reader connection.

1. Added device license activation feature.

- Add structure [BS2License](configuration_api#bs2license)

- Add structure [BS2LicenseConfig](configuration_api#bs2licenseconfig)

- Add structure [BS2LicenseBlob](sdk_api#bs2licenseblob)

- Add structure [BS2LicenseResult](sdk_api#bs2licenseresult)

- Add API [BS2_GetLicenseConfig](bs2_getlicenseconfig)

- Add API [BS2_EnableDeviceLicense](bs2_enabledevicelicense)

- Add API [BS2_DisableDeviceLicense](bs2_disabledevicelicense)

- Add API [BS2_QueryDeviceLicense](bs2_querydevicelicense)

1. Added features for QR code authentication by using the camera.

- Refer to structure [BS2BarcodeConfig](configuration_api#bs2barcodeconfig)

1. Added retry count for communication used when an error occurs while reading or writing packets from the socket during communication.

:::warning

**CAUTION**

Increasing the number of retries is a way to resolve temporary errors, but care must be taken as direct causes such as network disconnection occurs, can lead to wasted resources by meaningless read/write retries when reconnection is required.

:::

- Add API [BS2_GetSocketRetryCount](bs2_getsocketretrycount)

- Add API [BS2_SetSocketRetryCount](bs2_setsocketretrycount)

- Add API [BS2_GetSocketSSLRetryCount](bs2_getsocketsslretrycount)

- Add API [BS2_SetSocketSSLRetryCount](bs2_setsocketsslretrycount)

1. Added feature to connect and manage 3rd party OSDP.

- Add structure [BS2OsdpStandardDevice](slave_control_api#bs2osdpstandarddevice)

- Add structure [BS2OsdpStandardDeviceAvailable](slave_control_api#bs2osdpstandarddeviceavailable)

- Add structure [BS2OsdpStandardNotify](slave_control_api#bs2osdpstandardnotify)

- Add structure [BS2OsdpStandardConfig](configuration_api#bs2osdpstandardconfig)

- Add structure [BS2OsdpStandardActionConfig](configuration_api#bs2osdpstandardactionconfig)

- Add structure [BS2OsdpStandardDeviceAdd](slave_control_api#bs2osdpstandarddeviceadd)

- Add structure [BS2OsdpStandardDeviceUpdate](slave_control_api#bs2osdpstandarddeviceupdate)

- Add structure [BS2OsdpStandardDeviceCapability](slave_control_api#bs2osdpstandarddevicecapability)

- Add structure [BS2OsdpStandardDeviceResult](slave_control_api#bs2osdpstandarddeviceresult)

- Add structure [BS2OsdpStandardDeviceSecurityKey](slave_control_api#bs2osdpstandarddevicesecuritykey)

- Add API [BS2_GetOsdpStandardConfig](bs2_getosdpstandardconfig)

- Add API [BS2_GetOsdpStandardActionConfig](bs2_getosdpstandardactionconfig)

- Add API [BS2_SetOsdpStandardActionConfig](bs2_setosdpstandardactionconfig)

- Add API [BS2_AddOsdpStandardDevice](bs2_addosdpstandarddevice)

- Add API [BS2_GetOsdpStandardDevice](bs2_getosdpstandarddevice)

- Add API [BS2_GetAvailableOsdpStandardDevice](bs2_getavailableosdpstandarddevice)

- Add API [BS2_UpdateOsdpStandardDevice](bs2_updateosdpstandarddevice)

- Add API [BS2_RemoveOsdpStandardDevice](bs2_removeosdpstandarddevice)

- Add API [BS2_GetOsdpStandardDeviceCapability](bs2_getosdpstandarddevicecapability)

- Add API [BS2_SetOsdpStandardDeviceSecurityKey](bs2_setosdpstandarddevicesecuritykey)

- Add API [BS2_SetOsdpStandardDeviceStatusListener](bs2_setosdpstandarddevicestatuslistener)

- Add callback function [OnOsdpStandardDeviceStatusChanged](server_api#onosdpstandarddevicestatuschanged)

## Modified Features

1. Fixed memory leak caused by network switches keepalive check being misunderstood by the SDK.

1. This is a problem that occurs `only in version 2.8.3.2`, and a problem that can lead to abnormal termination during user registration while taking a log dump inside the SDK has been fixed.

1. Fixes were made to stabilize the code internally in the SDK.

---

# Version 2.8.3 (V2.8.3.2)

## Date

2022-10-05

## New Features

- BioStation 3 connection support (Device name: BS3-DB, BS3-APWB)

- Add User Information Partial Renewal Function.

- Add User statistics acquisition Function.

    *Add file log function for debugging that allows file segmentation and storage.

1. BioStation 3 Added connection support, related extended VoIP settings, and RTSP settings.

- Add structure [BS2VoipConfigExt](configuration_api#bs2voipconfigext)

- Add API [BS2_GetVoipConfigExt](bs2_getvoipconfigext)

- Add API [BS2_SetVoipConfigExt](bs2_setvoipconfigext)

- Add structure [BS2RtspConfig](configuration_api#bs2rtspconfig)

- Add API [BS2_GetRtspConfig](bs2_getrtspconfig)

- Add API [BS2_SetRtspConfig](bs2_setrtspconfig)

1. Added function to partially update user information.

- Add API [BS2_PartialUpdateUser](bs2_partialupdateuser)

- Add API [BS2_PartialUpdateUserEx](bs2_partialupdateuserex)

- Add API [BS2_PartialUpdateUserSmall](bs2_partialupdateusersmall)

- Add API [BS2_PartialUpdateUserSmallEx](bs2_partialupdateusersmallex)

- Add API [BS2_PartialUpdateUserFaceEx](bs2_partialupdateuserfaceex)

1. Added functionality to get user statistics held by the device.

- Add structure [BS2UserStatistic](user_management_api#bs2userstatistic)

- Add API [BS2_GetUserStatistic](bs2_getuserstatistic)

1. Added file log function for debugging that allows file segmentation to be saved.

- Add API [BS2_SetDebugFileLogEx](bs2_setdebugfilelogex)

## Modified Features

1. When outputting log files for debugging, the time information displayed has been modified to display up to milliseconds.

- Refer to API [BS2_SetDebugFileLog](bs2_setdebugfilelog)

1. The face setting method changes.

   In the face detection stage, face width, which represents the width of the face image, search range, which represents the search range, are entered in pixels.

   This was a rather difficult input unit for the user to set up.

   The detection distance, wide search provided afterward is changed to a more sensible setting unit by entering the distance to the detected face in cm.

   As of the time SDK V2.8.3 is distributed, only 'BioStation 3' can be distance-based, and then extended to 'FaceStation F2' is planned.

- Refer to structure [BS2FaceConfig](configuration_api#bs2faceconfig)

1. Added information such as user update support, simulated unlock support, RTSP support, Visual QR support, and extension number registered in Extended VoIP.

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

1. In the user structure, an infoMask has been added to indicate what credential information the user has.

   Also, by modifying the mask value of the infoMask and lowering it to the device, it is possible to change/delete the information that the user has partially.

- Refer to API [BS2User](user_management_api#bs2user)

1. The problem of not applying conditions such as start index and request quantity when obtaining the log of USB has been corrected.

   We also fixed an issue that occurs when the acquired log time is abnormally large.

- Refer to API [BS2_GetLogFromDir](bs2_getlogfromdir)

- Refer to API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

- Refer to API [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir)

- Refer to API [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir)

- Refer to API [BS2_GetLogFromDirWithKey](bs2_getlogfromdirwithkey)

- Refer to API [BS2_GetLogBlobFromDirWithKey](bs2_getlogblobfromdirwithkey)

- Refer to API [BS2_GetLogSmallBlobFromDirWithKey](bs2_getlogsmallblobfromdirwithkey)

- Refer to API [BS2_GetLogSmallBlobExFromDirWithKey](bs2_getlogsmallblobexfromdirwithkey)

1. When using the filtered log of USB, the problem of date search not being successful has been corrected.

- Refer to API[BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir)

- Refer to API[BS2_GetFilteredLogFromDirWithKey](bs2_getfilteredlogfromdirwithkey)

1. A simple bug in the C# example has been fixed.

1. Improved usability of SSL at low speed network environments.

1. Fixed the bug that crashed if the access group existed during a USB import.

1. Edited to stabilize code internally in SDK.

---

# Version2.8.2(V2.8.2.9)

## Date

2022-04-25

## New Features

- USB File Read Support with Ver.3

- Supports the function of adding Barcode bypass.

- Supports the function of adding Treat as CSN feature

- Supports the function of adding the Smartcard byte order functionality

- Adding support items to the system support information

1. On devices that support Ver.3 (GDPR supported), the following functions have been added to read USB files.

   The functions below are applicable if you have previously called the [BS2_SetDataEncryptKey](bs2_setdataencryptkey) function to change the device's user information encryption key.

   The newly added key parameter can be used to specify the key that was set in the past.

- Add API [BS2_GetUserDatabaseInfoFromDirWithKey](bs2_getuserdatabaseinfofromdirwithkey)

- Add API [BS2_GetUserListFromDirWithKey](bs2_getuserlistfromdirwithkey)

- Add API [BS2_GetUserInfosFromDirWithKey](bs2_getuserinfosfromdirwithkey)

- Add API [BS2_GetUserDatasFromDirWithKey](bs2_getuserdatasfromdirwithkey)

- Add API [BS2_GetUserInfosExFromDirWithKey](bs2_getuserinfosexfromdirwithkey)

- Add API [BS2_GetUserDatasExFromDirWithKey](bs2_getuserdatasexfromdirwithkey)

- Add API [BS2_GetLogFromDirWithKey](bs2_getlogfromdirwithkey)

- Add API [BS2_GetFilteredLogFromDirWithKey](bs2_getfilteredlogfromdirwithkey)

- Add API [BS2_GetUserSmallInfosFromDirWithKey](bs2_getusersmallinfosfromdirwithkey)

- Add API [BS2_GetUserSmallDatasFromDirWithKey](bs2_getusersmalldatasfromdirwithkey)

- Add API [BS2_GetUserSmallInfosExFromDirWithKey](bs2_getusersmallinfosexfromdirwithkey)

- Add API [BS2_GetUserSmallDatasExFromDirWithKey](bs2_getusersmalldatasexfromdirwithkey)

- Add API [BS2_GetUserInfosFaceExFromDirWithKey](bs2_getuserinfosfaceexfromdirwithkey)

- Add API [BS2_GetUserDatasFaceExFromDirWithKey](bs2_getuserdatasfaceexfromdirwithkey)

- Add API [BS2_GetLogBlobFromDirWithKey](bs2_getlogblobfromdirwithkey)

- Add API [BS2_GetLogSmallBlobFromDirWithKey](bs2_getlogsmallblobfromdirwithkey)

- Add API [BS2_GetLogSmallBlobExFromDirWithKey](bs2_getlogsmallblobexfromdirwithkey)

1. Barcode bypass functionality has been added to allow barcode to be subscribed from devices with barcode scan enabled.

- Refer to structure [BS2BarcodeConfig](configuration_api#bs2barcodeconfig)

- Add API [BS2_SetBarcodeScanListener](bs2_setbarcodescanlistener)

- Add callback function [OnBarcodeScanned](server_api#onbarcodescanned)

1. Barcode bypass functionality has been added to allow barcode to be subscribed from devices with barcode scan enabled.

- Refer to structure [BS2BarcodeConfig](configuration_api#bs2barcodeconfig)

1. It has been modified to specify the byte order of the Smartcard.

- Refer to structure [BS2CardConfig](configuration_api#bs2cardconfig)

- Refer to API [BS2_GetCardConfig](bs2_getcardconfig)

- Refer to API [BS2_SetCardConfig](bs2_setcardconfig)

1. The system support information for the Smartcard byte order, Treat as CSN functionality has been updated.

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

- Refer to API [BS2_GetDeviceCapabilities](bs2_getdevicecapabilities)

## Modified Features

1. libxml2 library dependency removed from SDK.

1. The USB file read function has been modified internally to support Ver.3 (GDPR supported).

   The functions below are applicable if you have never changed the device's user information encryption key by calling the [BS2_SetDataEncryptKey](bs2_setdataencryptkey) function in the past.

   The functions below are obtained by decrypting the encryption information to the default key value.

   The user can invoke the function the same as before

- Refer to API [BS2_GetUserDatabaseInfoFromDir](bs2_getuserdatabaseinfofromdir)

- Refer to API [BS2_GetUserListFromDir](bs2_getuserlistfromdir)

- Refer to API [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir)

- Refer to API [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir)

- Refer to API [BS2_GetUserInfosExFromDir](bs2_getuserinfosexfromdir)

- Refer to API [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir)

- Refer to API [BS2_GetLogFromDir](bs2_getlogfromdir)

- Refer to API [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir)

- Refer to API [BS2_GetUserSmallInfosFromDir](bs2_getusersmallinfosfromdir)

- Refer to API [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir)

- Refer to API [BS2_GetUserSmallInfosExFromDir](bs2_getusersmallinfosexfromdir)

- Refer to API [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir)

- Refer to API [BS2_GetUserInfosFaceExFromDir](bs2_getuserinfosfaceexfromdir)

- Refer to API [BS2_GetUserDatasFaceExFromDir](bs2_getuserdatasfaceexfromdir)

- Refer to API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

- Refer to API [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir)

- Refer to API [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir)

1. The following two APIs for connecting USB have been `deprecated`.

   The context can then be used by calling [bs2_allocatecontext](bs2_allocatecontext) to pass on the generated object.

* Deprecated to API [BS2_AllocateUsbContext](bs2_allocateusbcontext)

- Deprecated to API [BS2_ReleaseUsbContext](bs2_releaseusbcontext)

- Refer to API [BS2_AllocateContext](bs2_allocatecontext)

- Refer to API [BS2_ReleaseContext](bs2_releasecontext)

1. Fix the problem that the device connection is disconnected in case of a simple communication error in SSL connection mode.

---

# Version 2.8.2 (V2.8.2.3)

## Date

2021-11-29

## Modified Features

1. Supported Linux environments have been upgraded to Ubuntu 18.04.

   | SDK Version | Supported Linux Version |
   | --- | --- |
   | Before V2.8.2 | Ubuntu 16.04 |
   | Later V2.8.2 | Ubuntu 18.04 |

1. OpenSSL has been modified to support 1.1.1i from the existing 1.0.2n.

- Refer to [Building a Development Environment](getting_started#Building_a_Development_Environment)

1. Fixed an issue where a BS_SDK_ERROR_SOCKET_IS_NOT_CONNECTED error occurred when calling [BS2_GetFactoryConfig](bs2_getfactoryconfig) on an IPv6 operating device.

1. Fixed an issue that could cause a BS_SDK_ERROR_TIMEOUT error when enrolling many image-based users on FaceStation F2 devices.

1. Fixed the problem that [BS2_SetDebugExCallback](bs2_setdebugexcallback) does not work after V2.7.2.20.

1. Removed incorrect support configuration for FaceStation F2. (WLAN)

- Refer to API [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask)

1. Removed incorrect support configuration for XStation 2. (VoIP)

- Refer to API [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask)

1. Added incorrect support configuration for BioEntry R2 devices. (Wiegand)

- Refer to API [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask)

1. Fix reserved2 resizing error due to adding useScreenSaver in C# example.

- Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig)

1. There were fixes for stabilizing the code inside the SDK.

---

# Version 2.8.1 (V2.8.1.0)

## Date

2021-08-05

## New Features

- Supports X-Station 2 Finger (Product Name: XS2-OAPB, XS2-ODPB)

- Supports Input Module Feature (Product Name: IM-120)

- Supports the function of commanding certain actions to devices

1. X-Station 2 Finger Configurations are available to use.

1. Input Module(Product Name: IM-120) Configurations are available to use.

- Refer to structure [BS2InputConfigEx](configuration_api#bs2inputconfigex)

- Refer to structure [BS2RelayActionConfig](configuration_api#bs2relayactionconfig)

- Refer to structure [BS2Event](log_management_api#bs2event) **relayAction**

- Refer to API [BS2_GetInputConfigEx](bs2_getinputconfigex)

- Refer to API [BS2_SetInputConfigEx](bs2_setinputconfigex)

- Refer to API [BS2_GetRelayActionConfig](bs2_getrelayactionconfig)

- Refer to API [BS2_SetRelayActionConfig](bs2_setrelayactionconfig)

1. You can now command certain actions to devices.

   You can now turn on LED, alarm a buzzer, or control relay and perform more actions at the desired time with the COMMANDS below.

- Refer to structure [BS2Action](configuration_api#bs2action)

- Refer to API [BS2_RunAction](bs2_runaction)

## Modified Features

1. Fixed the error in which Linux returns BS_SDK_ERROR_TIMEOUT and is not able to have device connections.

1. C# examples provided to guide through server-matching function implementation will not be supported anymore.

- Refer to the Server API Document [server_api](server_api)

---

# Version 2.8.0 (V2.8.0.6)

## Date

2021-06-07

## New Features

- Supports X-Station 2

- Supports Intelligent Slave Feature (FW upgrade is required)

- Supports getting Face Image Warping (FaceStation F2 only)

- Supports the function of Device Capabilities to know the connected device capability

- Adds the relevant log events of Mobile Card Verification

- Adds new model names to check card supporting

1. X-Station 2 Configurations are available to use.

- Refer to structure [BS2BarcodeConfig](configuration_api#bs2barcodeconfig)

- Refer to API [BS2_GetBarcodeConfig](bs2_getbarcodeconfig)

- Refer to API [BS2_SetBarcodeConfig](bs2_setbarcodeconfig)

- Refer to API [BS2_WriteQRCode](bs2_writeqrcode)

1. The relevant function of Intelligent Slave is available to use. Intelligent Slave is a function that enables many users' 1:1 or 1:N matching by transmitting the authentication result to OSDP card data when authentication using biometrics is performed in an environment in which the Suprema biometric device and a third-party controller are connected.

   [Intelligent Slave Support](https://support.supremainc.com/en/support/solutions/articles/24000066085--biostar-2-intelligent-slave-support)

- Refer to structure [BS2Rs485Config](configuration_api#bs2rs485config)

- Refer to API [BS2_GetRs485Config](bs2_getrs485config)

- Refer to API [BS2_SetRs485Config](bs2_setrs485config)

1. Getting Image Warping from the raw image file of user face is available to use.

- Refer to API [BS2_GetNormalizedImageFaceEx](bs2_getnormalizedimagefaceex)

1. Getting Device Capacity Information has been added.

- Refer to structure [BS2DeviceCapabilities](device_api#bs2devicecapabilities)

- Refer to API [BS2_GetDeviceCapabilities](bs2_getdevicecapabilities)

1. New log event 'Mobile Card Verification' has been added to distinguish the user credential.

- Refer to structure [BS2Event and refer to the subcode](Log_Management_API#BS2Event)

1. API [BS2_GetCardModel](bs2_getcardmodel) has been added to support the below model names.

- Refer to API [BS2_GetCardModel](bs2_getcardmodel)

- BEW2-ODPB

- BEW2-OAPB

- BEW2-OHPB

## Modified Features

1. Fixed the error BS_SDK_ERROR_TIMEOUT where the below case.

   `RS485 Master: CoreStation 40`

   `RS485 Slave: FaceStation 2 / FaceLite`

   Assigning a face template for FaceStation 2 or FaceLite to a user and enrolling it on CoreStation 40.

- Refer to API [BS2_EnrolUser](bs2_enroluser)

- Refer to API [BS2_EnrollUser](bs2_enrolluser)

- Refer to API [BS2_EnrolUserEx](bs2_enroluserex)

- Refer to API [BS2_EnrollUserEx](bs2_enrolluserex)

- Refer to API [BS2_EnrollUserSmall](bs2_enrollusersmall)

- Refer to API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

- Refer to API [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex)

1. Fixed the issue that device transfers for more than 700 users were relatively slow compared to V2.7.2.x and earlier.

- Refer to API [BS2_EnrolUser](bs2_enroluser)

- Refer to API [BS2_EnrollUser](bs2_enrolluser)

- Refer to API [BS2_EnrolUserEx](bs2_enroluserex)

- Refer to API [BS2_EnrollUserEx](bs2_enrolluserex)

- Refer to API [BS2_EnrollUserSmall](bs2_enrollusersmall)

- Refer to API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

- Refer to API [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex)

1. Fixed the return value from BS_SDK_SUCCESS to BS_SDK_ERROR_NOT_SUPPORTED when requesting Config from FaceLite that does not support Event config.

- Refer to API [BS2_GetEventConfig](bs2_geteventconfig)

1. Fixed the issue that the SDK allocation and release were repeated, making device connection impossible if a certain number of times were exceeded.

- Refer to API [BS2_AllocateContext](bs2_allocatecontext)

- Refer to API [BS2_ReleaseContext](bs2_releasecontext)

1. Fixed the issue that calling [BS2_ReleaseContext](bs2_releasecontext) cannot release the resource intermittently and the port 51212/port 51213 occupied.

1. Fixed the issue that a deadlock could occur during event processing due to repeated connecting device/disconnecting device calls.

1. Fixed the issue that the application may crash intermittently during calling [BS2_ReleaseContext](bs2_releasecontext).

1. Fixed the issue that the device could be reset if the fields of timeout were not assigned a multiple of 10 when updating the display settings.

- Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig) menuTimeout, msgTimeout, backlightTimeout

- Refer to API [BS2_SetDisplayConfig](bs2_setdisplayconfig)

1. Fixed the issue that CPU Usages goes up to 99% when [BS2_SearchDevices](bs2_searchdevices) is called repeatedly in a 4-core environment.

1. Added 'Not used' to the White LED Settings for FaceStation F2.

1. `FaceStation F2 Only` The meaning and setting values of lightCondition in the [BS2FaceConfig](configuration_api#bs2faceconfig) have been changed as follows.

   | Supported Ver. | Meaning | 0 | 1 | 2 | 3 |
   | --- | --- | --- | --- | --- | --- |
   | 1.0.0 \~ 1.0.5 | Ambient Brightness | Indoor | Outdoor | Auto | \- |
   | 1.1.0 or higher | Light Brightness | Normal | High | \- `(Deprecated)` | Not used |

- Refer to structure [BS2FaceConfig](configuration_api#bs2faceconfig) lightCondition

---

# Version 2.7.2 (V2.7.2.12)

## Date

2020-12-11

## New Features

- Supports screensaver activation (FaceStation 2, FaceStation F2)

- FaceStation F2 server matching support (1:1 Matching when using card together)

1. You can turn the screensaver on and off. FaceStation 2, FaceStation F2 only.

- Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig)

- Refer to API [BS2_GetDisplayConfig](bs2_getdisplayconfig)

- Refer to API [BS2_SetDisplayConfig](bs2_setdisplayconfig)

1. FaceStation F2 server matching support. (Card only)

- Refer to API [BS2_SetServerMatchingHandler](bs2_setservermatchinghandler)

- Refer to API [BS2_VerifyUserFaceEx](bs2_verifyuserfaceex)

## Modified Features

1. Fixed an issue where devices could not connect normally when in Device to Server connection mode.

1. In the process of unloading SDK through [BS2_ReleaseContext](bs2_releasecontext), a problem that may not be normally unloaded due to a specific thread has been fixed.

1. Body temperature measurement range has been modified. (30º \~ 45º =\> 1º \~ 45º)

- Refer to structure [BS2FaceConfigExt](configuration_api#bs2faceconfigext) (thermalThresholdLow, thermalThresholdHigh)

1. Fixed a problem where BS_SDK_ERROR_NOT_SUPPORTED or BS_SDK_ERROR_TIMEOUT error was returned when enrolling a user with multiple images to FaceStation F2.

- Refer to API [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex)

1. Fixed a problem in which a specific function was called from some devices, but the BS_SDK_ERROR_TIMEOUT error was returned as a result value even if it succeeded.

- Refer to API [BS2_ResetConfigExceptNetInfo](bs2_resetconfigexceptnetinfo)

---

# Version 2.7.2 (V2.7.2.4)

## Date

2020-11-11

## New Features

- Supports Wiegand output User ID

1. You can select either Card ID or User ID for Wiegand output setting.

- Refer to structure [BS2WiegandConfig](configuration_api#bs2wiegandconfig)

- Refer to API [BS2_GetWiegandConfig](bs2_getwiegandconfig)

- Refer to API [BS2_SetWiegandConfig](bs2_setwiegandconfig)

## Modified Features

1. File log output structure of internal SDK has been changed.

   Before, it used to write a file from each event processing thread, but now there's a separate file writing thread.

   It leads to improve the speed of event processing.

- Refer to API [BS2_SetDebugFileLog](bs2_setdebugfilelog)

1. When enrolling multiple face users to FaceStation F2,

   Fixed an issue that could cause the BS_SDK_ERROR_NO_FACE_CREDENTIAL(-759) error.

- Refer to API [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex)

1. Fixed an issue where the callback may not work intermittently when the device is disconnected

- Refer to API [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener)

1. There were fixes for stabilizing the code inside the SDK.

---

# Version 2.7.1 (V2.7.1.1)

## Date

2020-09-15

## New Features

- Supports FaceStation F2

- Supports Thermal camera - Facial temperature & Mask detection features

- Supports the feature of changing of the user-defined PIN encryption key

1. FaceStation F2 is supported, user related structures & API are added.

- Refer to structure [BS2UserSettingEx](user_management_api#bs2usersettingex)

- Refer to structure [BS2TemplateEx](face_api#bs2templateex)

- Refer to structure [BS2FaceEx](face_api#bs2faceex)

- Refer to structure [BS2UserFaceExBlob](user_management_api#bs2userfaceexblob)

- Refer to API [BS2_ScanFaceEx](bs2_scanfaceex)

- Refer to API [BS2_ExtraceTemplateFaceEx](bs2_extracetemplatefaceex)

- Refer to API [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex)

- Refer to API [BS2_GetUserInfosFaceEx](bs2_getuserinfosfaceex)

- Refer to API [BS2_GetUserDatasFaceEx](bs2_getuserdatasfaceex)

1. Several authentication modes for FaceStation F2 have been added, and you can configure with API and structure below.

- Refer to structure [BS2AuthConfigExt](configuration_api#bs2authconfigext)

- Refer to API [BS2_GetAuthConfigExt](bs2_getauthconfigext)

- Refer to API [BS2_SetAuthConfigExt](bs2_setauthconfigext)

1. You can extract template by jpg image from FaceStation F2. The template file can be stored on AoC.

- Refer to structure [BS2SmartCardHeader](smartcard_api#bs2smartcardheader)

- Refer to API [BS2_ExtraceTemplateFaceEx](bs2_extracetemplatefaceex)

1. Thermal camera - Facial temperature & Mask detection can be configured with API & structure below.

- Refer to structure [BS2FaceConfigExt](configuration_api#bs2faceconfigext)

- Refer to API [BS2_GetFaceConfigExt](bs2_getfaceconfigext)

- Refer to API [BS2_SetFaceConfigExt](bs2_setfaceconfigext)

1. Thermal camera information structure and configurable API are available.

- Refer to structure [BS2ThermalCameraConfig](configuration_api#bs2thermalcameraconfig)

- Refer to API [BS2_GetThermalCameraConfig](bs2_getthermalcameraconfig)

- Refer to API [BS2_SetThermalCameraConfig](bs2_setthermalcameraconfig)

1. New event log structure & API to support temperature information have been added.

- Refer to callback function [OnLogReceivedEx](log_management_api#onlogreceivedex)

- Refer to structure [BS2EventSmallBlobEx](log_management_api#bs2eventsmallblobex)

- Refer to API [BS2_StartMonitoringLogEx](bs2_startmonitoringlogex)

- Refer to API [BS2_GetLogSmallBlobEx](bs2_getlogsmallblobex)

- Refer to API [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir)

1.​ User-defined PIN encryption key can be changed, and the PIN can be extracted with APIs.

- Refer to API [BS2_SetDataEncryptKey](bs2_setdataencryptkey)

- Refer to API [BS2_MakePinCodeWithKey](bs2_makepincodewithkey)

## Modified Features

1. A structure is modified to support FaceStation F2's configuration.

- Refer to structure [BS2FaceConfig](configuration_api#bs2faceconfig)

1. Masking information of some API retrieving user information with userMask has been added. (Refer to userMask parameter for each API)

- Refer to API [BS2_GetUserDatas](bs2_getuserdatas)

- Refer to API [BS2_GetUserDatasEx](bs2_getuserdatasex)

- Refer to API [BS2_GetSupportedUserMask](bs2_getsupportedusermask)

- Refer to API [BS2_GetUserSmallDatas](bs2_getusersmalldatas)

- Refer to API [BS2_GetUserSmallDatasEx](bs2_getusersmalldatasex)

- Refer to API [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir)

- Refer to API [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir)

- Refer to API [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir)

- Refer to API [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir)

- Refer to API [BS2_GetUserInfosFaceEx](bs2_getuserinfosfaceex)

- Refer to API [BS2_GetUserDatasFaceEx](bs2_getuserdatasfaceex)

1. In the past, parameters like fingerSupported, faceSupported were used meaning fingerprint authentication(matching) or facial authentication(matching).

   This was confusing because FaceStation2 or returned fingerSupported = true.

   From 2.7.1, additional information fingerScanSupported and faceScanSupported is supported to provide more accurate information.

   With this, FaceStation2 returns fingerScanSupported = false.

- Refer to API [BS2_GetDeviceInfoEx](bs2_getdeviceinfoex)

- Refer to structure [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex)

1. For security reasons, support for the function BS2_GetDataEncryptKey has been deprecated.

---

# Version 2.7.0 (V2.7.0.0)

## Date

2020-07-21

## New Features

- Supports XPass D2 Revision, XPass D2 Keypad Revision

- Supports lift lock/unlock zone features based on schedule

- Supports User phrase (Private message) feature on the server

- Supports Global APB By Door Open

1. Device XPass D2 Revision, XPass D2 Keypad Revision are supported.

1. Lift lock/unlock zone which works based on schedules regardless of access group is supported.

- Refer to structure [BS2LiftFloors](zone_control_api#bs2liftfloors)

- Refer to structure [BS2LiftLockUnlockZone](zone_control_api#bs2liftlockunlockzone)

- Refer to API [BS2_GetLiftLockUnlockZone](bs2_getliftlockunlockzone)

- Refer to API [BS2_GetAllLiftLockUnlockZone](bs2_getallliftlockunlockzone)

- Refer to API [BS2_GetLiftLockUnlockZoneStatus](bs2_getliftlockunlockzonestatus)

- Refer to API [BS2_GetAllLiftLockUnlockZoneStatus](bs2_getallliftlockunlockzonestatus)

- Refer to API [BS2_SetLiftLockUnlockZone](bs2_setliftlockunlockzone)

- Refer to API [BS2_SetLiftLockUnlockZoneAlarm](bs2_setliftlockunlockzonealarm)

- Refer to API [BS2_RemoveLiftLockUnlockZone](bs2_removeliftlockunlockzone)

- Refer to API [BS2_RemoveAllLiftLockUnlockZone](bs2_removeallliftlockunlockzone)

1. User phrase feature that you can request the user phrase(private message) to the server is supported.

- Refer to structure [BS2DisplayConfig](configuration_api#bs2displayconfig)

- Refer to API [BS2_SetUserPhraseHandler](bs2_setuserphrasehandler)

- Refer to API [BS2_ResponseUserPhrase](bs2_responseuserphrase)

1. Global APB By Door Open is supported.

   Global APB By Door Open has two steps; i) User authentication ii) Actual access based on the door sensor

   You can figure out the user who actually doesn't go in even after successful authentication and the door unlock using this feature.

- Refer to structure [BS2DoorSensor](door_control_api#bs2doorsensor)

- Refer to API [BS2_SetGlobalAPBViolationByDoorOpenHandler](bs2_setglobalapbviolationbydooropenhandler)

- Refer to API [BS2_CheckGlobalAPBViolationByDoorOpen](bs2_checkglobalapbviolationbydooropen)

## Modified Features

1. Fixed the issue that the device returns BS_SDK_ERROR_CANNOT_FIND_DEVICE after successful connection due to corrupted communication key exchange. (Only some latest FW)

1. Fixed the issue that SDK can't process received packets from the device with IPv6 connection mode.

- Refer to structure [BS2UserBlobEx](user_management_api#bs2userblobex)

- Refer to API [BS2_VerifyUserEx](bs2_verifyuserex)

- Refer to API [BS2_IdentifyUserEx](bs2_identifyuserex)

- Refer to API [BS2_EnrolUserEx](bs2_enroluserex)

- Refer to API [BS2_VerifyUserSmallEx](bs2_verifyusersmallex)

- Refer to API [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex)

- Refer to API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

1. Fixed the issue with the error BS2_SDK_ERROR_INVALID_PACKET when received log from the device due to the image log larger than 16KB.

- Refer to API [BS2_GetLogBlob](bs2_getlogblob)

- Refer to API [BS2_GetLogSmallBlob](bs2_getlogsmallblob)

- Refer to API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

- Refer to API [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir)

- Refer to API [BS2_GetImageLog](bs2_getimagelog)

---

# Version 2.6.4 (V2.6.4.1)

## Date

2020-02-25

## New Features

- Supports the API retrieving logs filtered by EventMask

- Supports DesFire Advanced format setting

- Supports the card type selection feature

- Supports duplicate fingerprints/face check

1. The API retrieving logs filtered by Event Mask so that you can use memory efficiently than before.

- Structure [BS2EventSmallBlob](Log_Management_API#bs2eventsmallblob) has been added

- API [BS2_GetLogSmallBlob](bs2_getlogsmallblob) has been added

- API [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) has been added

1. DesFire Advanced format setting is now supported.

- Structure [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex) has been added

- Structure [BS2DesFireCardConfigEx](configuration_api#bs2desfirecardconfigex) has been added

- API [BS2_GetDesFireCardConfigEx](bs2_getdesfirecardconfigex) has been added

- API [BS2_SetDesFireCardConfigEx](bs2_setdesfirecardconfigex) has been added

1. Card type selection is available so that you can select/deselect the card type you want to read fro the device.

- Structure [BS2SystemConfig](configuration_api#bs2systemconfig) has been added

- API [BS2_SetSystemConfig](bs2_setsystemconfig) has been added

1. Duplicate fingerprint and face check is available.

- Structure [BS2FaceConfig](Configuration_API#bs2faceconfig) has been added

- API [BS2_GetFingerprintConfig](bs2_getfingerprintconfig) has been added

- API [BS2_SetFingerprintConfig](bs2_setfingerprintconfig) has been added

- Structure [BS2FingerprintConfig](Configuration_API#bs2fingerprintconfig) has been added

- API [BS2_GetFaceConfig](bs2_getfaceconfig) has been added

- API [BS2_SetFaceConfig](bs2_setfaceconfig) has been added

## Modified Features

1. Fixed the issue of device malfunctioning and rebooting when BS2Job.numJobs in BS2UserBlobEx exceeds the maximum value 16.

- Refer to structure [BS2UserBlobEx](user_management_api#bs2userblobex)

- Refer to API [BS2_VerifyUserEx](bs2_verifyuserex)

- Refer to API [BS2_IdentifyUserEx](bs2_identifyuserex)

- Refer to API [BS2_EnrolUserEx](bs2_enroluserex)

- Refer to API [BS2_VerifyUserSmallEx](bs2_verifyusersmallex)

- Refer to API [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex)

- Refer to API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

1. Fixed the issue of BioStation 2 not available for user images.

1. Fixed the error BS_SDK_INVALID_CODE_SIGN when upgrading SIO2.

1. Fixed the error BS_SDK_ERROR_NOT_SUPPORTED when calling BS2_GetCardModel for BLN2-PAB.

- Refer to API [BS2_GetCardModel](bs2_getcardmodel)

1. Fixed the issue that SDK doesn't recognize device disconnection when the device is constantly disconnected.

1. Fixed the issue of Linux SDK crash.

---

# Version 2.6.4 (V2.6.4.1)

## Date

2020-02-25

## New Features

- Supports the API retrieving logs filtered by EventMask

- Supports DesFire Advanced format setting

- Supports the card type selection feature

- Supports duplicate fingerprints/face check

1. The API retrieving logs filtered by Event Mask so that you can use memory efficiently than before.

- Refer to structure [BS2EventSmallBlob](Log_Management_API#bs2eventsmallblob)

- Refer to API [BS2_GetLogSmallBlob](bs2_getlogsmallblob)

- Refer to API [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir)

1. DesFire Advanced format setting is now supported.

- Refer to structure [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex)

- Refer to structure [BS2DesFireCardConfigEx](configuration_api#bs2desfirecardconfigex)

- Refer to API [BS2_GetDesFireCardConfigEx](bs2_getdesfirecardconfigex)

- Refer to API [BS2_SetDesFireCardConfigEx](bs2_setdesfirecardconfigex)

1. Card type selection is available so that you can select/deselect the card type you want to read fro the device.

- Refer to structure [BS2SystemConfig](configuration_api#bs2systemconfig)

- Refer to API [BS2_SetSystemConfig](bs2_setsystemconfig)

1. Duplicate fingerprint and face check is available.

- Refer to structure [BS2FaceConfig](Configuration_API#bs2faceconfig)

- Refer to API [BS2_GetFingerprintConfig](bs2_getfingerprintconfig)

- Refer to API [BS2_SetFingerprintConfig](bs2_setfingerprintconfig)

- Refer to structure [BS2FingerprintConfig](Configuration_API#bs2fingerprintconfig)

- Refer to API [BS2_GetFaceConfig](bs2_getfaceconfig)

- Refer to API [BS2_SetFaceConfig](bs2_setfaceconfig)

## Modified Features

1. Fixed the issue of device malfunctioning and rebooting when BS2Job.numJobs in BS2UserBlobEx exceeds the maximum value 16.

- Refer to structure [BS2UserBlobEx](user_management_api#bs2userblobex)

- Refer to API [BS2_VerifyUserEx](bs2_verifyuserex)

- Refer to API [BS2_IdentifyUserEx](bs2_identifyuserex)

- Refer to API [BS2_EnrolUserEx](bs2_enroluserex)

- Refer to API [BS2_VerifyUserSmallEx](bs2_verifyusersmallex)

- Refer to API [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex)

- Refer to API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

1. Fixed the issue of BioStation 2 not available for user images.

1. Fixed the error BS_SDK_INVALID_CODE_SIGN when upgrading SIO2.

1. Fixed the error BS_SDK_ERROR_NOT_SUPPORTED when calling BS2_GetCardModel for BLN2-PAB.

- Refer to API [BS2_GetCardModel](bs2_getcardmodel)

1. Fixed the issue that SDK doesn't recognize device disconnection when the device is constantly disconnected.

1. Fixed the issue of Linux SDK crash.

---

# Version 2.6.3 (V2.6.3.16)

## Date

2019-11-04

## Modified features

1.Fixed the problem where the devices listed below may fail to connect when connecting.

* BioEntry Plus 2.0

* BioEntry W 2.0

* BioLiteNet 2.0

* Xpass 2.0

* Xpass Slim 2.0

1.Fixes a problem where the return value dualIDSupported and useAlphanumericID becomes 0 when BS2_GetDeviceInfo is called after directly connection a device by IP or port instead of searching for and connecting a device.

* Refer to API [BS2_SearchDevices](bs2_searchdevices)

* Refer to API [BS2_ConnectDevice](bs2_connectdevice)

* Refer to API [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip)

* Refer to API [BS2_GetDeviceInfo](bs2_getdeviceinfo)

* Refer to structure [BS2SimpleDeviceInfo](device_api#bs2simpledeviceinfo)

1.Fixes a problem where a timeout error (BS_SDK_ERROR_TIMEOUT) may occur if the devices listed below attempt a factory reset.

* BioEntry Plus 2.0

* BioEntry W 2.0

* BioLiteNet 2.0

* Xpass 2.0

* Xpass Slim 2.0

* Refer to API [BS2_FactoryReset](bs2_factoryreset)

1.Fixed a problem where the connection would be terminated normally if the device was disconnected and the packet was exchanged in the SDK without closing the connection yet.

---

# Version 2.6.3 (V2.6.3.12)

## Date

2019-09-30

## Modified features

1.Fixed an issue that could lead to infinite loops when network communication is lost and WSA_INVALID_HANDLE occurs after the device is connected through SDK.

1.Fixes a problem that can cause too many debugging logs output during packet processing during communication.

- Newly added DEBUG_LOG_OPERATION_ALL(0xFF), the level used in [BS2_SetDebugExCallback](bs2_setdebugexcallback) and [BS2_SetDebugFileLog](bs2_setdebugfilelog).

---

# Version 2.6.3 (V2.6.3.11)

## Date

2019-09-10

## New Features

- Fixes a problem where firmware upgrade might fail in SSL connection mode

---

# Version 2.6.3 (V2.6.3.10)

## Date

2019-08-30

## New Features

- Some APIs return error code BS_SDK_ERROR_TIMEOUT but work normally with debugging log is on.

- BS_SDK_ERROR_TIMEOUT is returned when calling [BS2_UpdateResource](bs2_updateresource)

- The issue with the process taking a long time such as a large number of users enroll or FW upgrade etc.

- Code modified to avoid SDK crash possibilities

---

# Version 2.6.3 (V2.6.3.5)

## Date

2019-07-24

## New Features

- Supports device XPass D2 Keypad

- Supports device Face Lite

- Supports device XPass 2 and XPass 2 Keypad

- Supports IPv6 (BS2 FW 1.8.0 only)

- Gets configured server port

- Supports setting packet response time out

- User enrollment API BS2_EnrollUser and BS2_EnrollUserEx have been added

- API BS2UserSmallBlob/BS2UserSmallBlobEx for efficient use of memory in regards to large capacity of BS2UserBlob/BS2UserBlobEx (pointer processing of User Photo area)

- Supports more than 1000 admin users (Only some devices, higher than BS2 1.8.0, A2 1.7.0, L2 1.5.0, N2 1.2.0, FS 1.3.0, FaceLite 1.0.1, CS40 1.3.0, P2 1.3.0, W2 1.4.0, Xpass 2 1.0.0)

- Supports fingerprint template quality score

- Supports file log print

1. Device XPass D2 Keypad is supported.

1. Device Face Lite is supported.

1. Device XPass 2 and XPass 2 Keypad are supported.

1. IPv6 connection is supported.

   When initialize SDK, IPv6 is disabled as default.

- Add structure [BS2IPV6Config](configuration_api#bs2ipv6config)

- Add structure [BS2IPv6DeviceInfo](device_api#bs2ipv6deviceinfo)

- Add API [BS2_SetDebugExCallback](bs2_setdebugexcallback)

- Add API [BS2_GetIPConfigViaUDPEx](bs2_getipconfigviaudpex)

- Add API [BS2_SetIPConfigViaUDPEx](bs2_setipconfigviaudpex)

- Add API [BS2_GetIPV6Config](bs2_getipv6config)

- Add API [BS2_SetIPV6Config](bs2_setipv6config)

- Add API [BS2_GetIPV6ConfigViaUDP](bs2_getipv6configviaudp)

- Add API [BS2_SetIPV6ConfigViaUDP](bs2_setipv6configviaudp)

- Add API [BS2_GetIPV6ConfigViaUDPEx](bs2_getipv6configviaudpex)

- Add API [BS2_SetIPV6ConfigViaUDPEx](bs2_setipv6configviaudpex)

- Add API [BS2_GetEnableIPV4](bs2_getenableipv4)

- Add API [BS2_SetEnableIPV4](bs2_setenableipv4)

- Add API [BS2_GetEnableIPV6](bs2_getenableipv6)

- Add API [BS2_SetEnableIPV6](bs2_setenableipv6)

- Add API [BS2_SetServerPortIPV6](bs2_setserverportipv6)

- Add API [BS2_GetServerPortIPV6](bs2_getserverportipv6)

- Add API [BS2_SetSSLServerPortIPV6](bs2_setsslserverportipv6)

- Add API [BS2_GetSSLServerPortIPV6](bs2_getsslserverportipv6)

- Add API [BS2_GetSpecifiedDeviceInfo](bs2_getspecifieddeviceinfo)

- Add API [BS2_SearchDevicesCoreStationEx](bs2_searchdevicescorestationex)

1. The APIs getting server port have been added.

- Add API [BS2_GetServerPort](bs2_getserverport)

- Add API [BS2_GetSSLServerPort](bs2_getsslserverport)

1. You can set packet response timeout with device.

- Add API [BS2_SetDefaultResponseTimeout](bs2_setdefaultresponsetimeout)

- Add API [BS2_GetDefaultResponseTimeout](bs2_getdefaultresponsetimeout)

1. BS2_EnrollUser and BS2_EnrollUserEx for user enrollment API have been added.

   It is the exactly same as the existing BS2_EnrolUser and BS2_EnrolUserEx APIs but only changed to correct spelling.

- Add API [BS2_EnrollUser](bs2_enrolluser)

- Add API [BS2_EnrollUserEx](bs2_enrolluserex)

1. Member [BS2UserPhoto](user_management_api#bs2userphoto) of user structures [BS2UserBlob](user_management_api#bs2userblob) and [BS2UserBlobEx](user_management_api#bs2userblobex) is designed to have fixed memory.

   Even if you do not use the photo, it uses fixed-size of memory.

   It wouldn't be a problem if there are few users to transfer and receive. However, if there are many users, then allocated memory is getting bigger as well.

   In 2.6.3, we added API that can use memory more efficiently through pointer processing of [BS2UserPhoto](user_management_api#bs2userphoto).

- Add structure [BS2UserSmallBlob](user_management_api#bs2usersmallblob)

- Add structure [BS2UserSmallBlobEx](user_management_api#bs2usersmallblobex)

- Add API [BS2_EnrollUserSmall](bs2_enrollusersmall)

- Add API [BS2_EnrollUserSmallEx](bs2_enrollusersmallex)

- Add API [BS2_GetUserSmallInfos](bs2_getusersmallinfos)

- Add API [BS2_GetUserSmallDatas](bs2_getusersmalldatas)

- Add API [BS2_GetUserSmallInfosEx](bs2_getusersmallinfosex)

- Add API [BS2_GetUserSmallDatasEx](bs2_getusersmalldatasex)

- Add API [BS2_VerifyUserSmall](bs2_verifyusersmall)

- Add API [BS2_IdentifyUserSmall](bs2_identifyusersmall)

- Add API [BS2_VerifyUserSmallEx](bs2_verifyusersmallex)

- Add API [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex)

- Add API [BS2_GetUserSmallInfosFromDir](bs2_getusersmallinfosfromdir)

- Add API [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir)

- Add API [BS2_GetUserSmallInfosExFromDir](bs2_getusersmallinfosexfromdir)

- Add API [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir)

1. You can add device operators up to 1000.

   Still, you can only add maximum 10 operators if you use the existing structure [BS2AuthConfig](configuration_api#bs2authconfig).

   In 2.6.3, you can add operators up to 1000 with the new structure with the new API. 

:::warning

**CAUTION**

The exsiting [BS2AuthConfig](configuration_api#bs2authconfig) and operators are valid until you call the new API. However, if at any one time you call the newly added API below, the existing [BS2AuthConfig](configuration_api#bs2authconfig) setting will be ignored so you need to use only the new API and structure.

If you want to use the new API with the new structure, please move the operator list managed by existing BS2AuthConfig securely to the new structure [BS2AuthOperatorLevel](device_api#bs2authoperatorlevel) where can manage 1000 operators.

:::

- Add structure [BS2AuthOperatorLevel](device_api#bs2authoperatorlevel)

- Add API [BS2_GetAuthOperatorLevelEx](bs2_getauthoperatorlevelex)

- Add API [BS2_GetAllAuthOperatorLevelEx](bs2_getallauthoperatorlevelex)

- Add API [BS2_SetAuthOperatorLevelEx](bs2_setauthoperatorlevelex)

- Add API [BS2_RemoveAuthOperatorLevelEx](bs2_removeauthoperatorlevelex)

- Add API [BS2_RemoveAllAuthOperatorLevelEx](bs2_removeallauthoperatorlevelex)

1. You can check fingerprint template quality score.

- Refer to structure [BS2Fingerprint](fingerprint_api#bs2fingerprint)

- Add API [BS2_GetFingerTemplateQuality](bs2_getfingertemplatequality)

1. File log print(debugging) is supported.

- Add API [BS2_SetDebugFileLog](bs2_setdebugfilelog)

## Modified features

1. In the past, when upgrading the firmware file, the code sign check was performed by the device.

   In 2.6.3 it has been modified to perform in the SDK so that SDK can return an error to improper firmware file.

- Refer to API [BS2_UpgradeFirmware](bs2_upgradefirmware)

1. Fixed an issue where all communication could not work intermittently if the socket was disconnected immediately.

1. Fixed an issue where multiple devices could not connect to each other intermittently when attempting SSL connection at the same time.

1. Fixed an intermittent crash when searching for devices.

- Refer to API [BS2_SearchDevicesEx](bs2_searchdevicesex)

1. Fixed an issue where intermittent hangs may occur in the memory return stage for terminating the SDK library or for reallocating resources in the library.

- Refer to API [BS2_ReleaseContext](bs2_releasecontext)

- Refer to API [BS2_SetMaxThreadCount](bs2_setmaxthreadcount)

1. Fixed an issue where iClass SEOS card device returns wrong error(BS_SDK_ERROR_NOT_SUPPORTED) when getting card config.

- Refer to API [BS2_GetCardConfigEx](bs2_getcardconfigex)

1. Fixed an issue where devices that use different SSL certificate files will not connect intermittently when attempting SSL connection at the same time.

1. Fixed an issue with incorrect floor level in Lift control.

- Refer to API [BS2_GetFloorLevel](bs2_getfloorlevel)

1. Fixed the restriction that the fingerprint template was fixed to 384 bytes when using server matching.

1. Fixed a problem that some fingerprint related APIs did not work in slave device.

- Refer to API [BS2_ScanFingerprint](bs2_scanfingerprint)

- Refer to API [BS2_VerifyFingerprint](bs2_verifyfingerprint)

1. The supported and unsupported settings for each device may vary.

   However, in some cases, timeout error occurs in a setting that is not supported.

   This has been modified to return BS_SDK_ERROR_NOT_SUPPORTED.

- Refer to API [BS2_GetConfig](bs2_getconfig)

1. Fixed the problem that the call result is not returned normally after calling access schedule setting.

- Refer to API [BS2_SetAccessSchedule](bs2_setaccessschedule)

1. When the device is connected in server mode, the processing is modified from synchronous to asynchronous.

1. Fixed to clean up sockets that failed to open when initialize SDK.

1. Modified to clear SSL resources at the end of SSL connection.

1. Improved performance when sending and receiving packets in socket.

   (If an error occurs, retries every 5ms. After retry 10 times or error 100ms or longer, it prcoessed as disconnected)

1. Modified the meaning of parameters in API event processing thread for better understanding.

   [BS2_SetMaxThreadCount](bs2_setmaxthreadcount) (\~2.6.2):

   It sets threads number including reserved threads, not only event processing thread. Minimum value is 8.

   6 reserved threads : timer(2), server matching(1), notification(1), TCP processing(1), UDP processing(1)

   For example, if you set this as 8, you need to minus reserved threads 6. The number of actual event processing threads is 2.

   [BS2_SetMaxThreadCount](bs2_setmaxthreadcount) (2.6.3\~):

   It sets only for event processing thread. Minimum value is 2. 

   | API | Default(\~2.6.2) | Minimum(\~2.6.2) | Default(2.6.3\~) | Minimum(2.6.3\~) |
   | --- | --- | --- | --- | --- |
   | BS2_SetMaxThreadCount | MAX(NumberOfCpuCores\*5, 15) | 8 | MAX(NumberOfCpuCores\*5, 15) | 2 |
   | BS2_SetMaxConnectThreadCount | 8 | 1 | 8 | 1 |

1. Modified to allow to connect devices with the same IP in different port for the API [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip).

1. \[C# Sample\] Changed the parameter alarmFlags(BS2Door) to unconditionalLock.

1. \[C# Sample\] Modified the size of BS2SoundAction and added parameter 'delay'.

1. \[C# Sample\] LogControl - Modified BS2EventMaskEnum.JOB_CODE to BS2EventMaskEnum.ALL for BS2_GetLogBlob.

1. \[C# Sample\] CardControl - Removed unnecessary blacklist code.

1. \[C# Sample\] ConfigControl - Modified startTime.weekDay to endTime.weekDay in BS2_SetDstConfig.

1. \[C# Sample\] SlaveControl - Added sample for slave device.

1. Added an option to turn on and off card type on a device, rather than reading all card types supported by the device.

- Refer to structure [BS2SystemConfig](configuration_api#bs2systemconfig)

1. Sensitivity setting feature for filtering fake faces has been added.

- Refer to structure [BS2FaceConfig](Configuration_API#bs2faceconfig)

1. Face fast enrollment option has been added.

- Refer to structure [BS2FaceConfig](Configuration_API#bs2faceconfig)

1. Duplicated face(or fingerprint) check feature has been added.

- Refer to structure [BS2FaceConfig](Configuration_API#bs2faceconfig)

- Refer to structure [BS2FingerprintConfig](configuration_api#bs2fingerprintconfig)

1. The option to support GDPR(General Data Protection Regulation) has been added.

- Refer to structure [BS2SystemConfig](configuration_api#bs2systemconfig)

---

# Version 2.6.2

## Date

2018-07-24

## Modified Features

1. Fixed problem that cannot get RS485 and Input configuration from CoreStation.

1. Fixed a problem where BioEntry R2 device is not supported on CoreStation.

---

# Version 2.6.1

## Date

2018-04-24

:::warning

**CAUTION**

Up to version 2.5.0, Device SDK statically included OpenSSL library,

but starting with 2.6.0, it has been changed to link in shared library form.

Therefore, you need to run the appropriate OpenSSL library after installation.

The 2.6.0 library has been tested based on the OpenSSL 1.0.2n library.

The sample files contain the OpenSSL 1.0.2n Windows library file. 

:::

## Modified Features

1. Fields that has been moved from BS2SimpleDeviceInfo to BS2SimpleDeviceInfoEx are recovered.

   This will guarantee backward compatibility for v2.5.0 related codes.

* Refer to structure [bs2simpledeviceinfo](device_api#bs2simpledeviceinfo)

- Refer to structure [bs2simpledeviceinfoex](device_api#bs2simpledeviceinfoex)

1. SSL certificates used from the C# example program has been updated.

1. Old FW files included in the C# example program has been deleted.

---

# Version 2.6.0

## Date

2018-10-31

  **NOTE**

After V2.5.0, it was reflected in V2.6.0 through bug fixes and additional supplements, but missing contents were added to the manual.  

## New Features

- Support reading USB memory (BioStation A2, FaceStation 2)

- Supports Debugging API

- Supports server port change

- Supports Global APB zone feature

- Supports device connection status check feature

- Supports automatic connection check and change feature

1. Added USB memory read feature.

- Add API [BS2_AllocateUsbContext](bs2_allocateusbcontext)

- Add API [BS2_ReleaseUsbContext](bs2_releaseusbcontext)

- Add API [BS2_GetUserDatabaseInfoFromDir](bs2_getuserdatabaseinfofromdir)

- Add API [BS2_GetUserListFromDir](bs2_getuserlistfromdir)

- Add API [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir)

- Add API [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir)

- Add API [BS2_GetUserInfosExFromDir](bs2_getuserinfosexfromdir)

- Add API [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir)

- Add API [BS2_GetLogFromDir](bs2_getlogfromdir)

- Add API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

- Add API [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir)

1. Added to refer to debug information that occurs in the SDK.

- Add API [BS2_SetDebugExCallback](bs2_setdebugexcallback)

1. Added server port designation feature.

- Add API [BS2_SetServerPort](bs2_setserverport)

- Add API [BS2_SetSSLServerPort](bs2_setsslserverport)

1. Added Global APB zone feature.

- Add API [BS2_SetCheckGlobalAPBViolationHandler](bs2_setcheckglobalapbviolationhandler)

- Add API [BS2_CheckGlobalAPBViolation](bs2_checkglobalapbviolation)

1. Added device connection status check feature.

- Add API [BS2_IsConnected](bs2_isconnected)

1. Added to automatic connection check and change feature.

- Add API [BS2_IsAutoConnection](bs2_isautoconnection)

- Add API [BS2_SetAutoConnection](bs2_setautoconnection)

## Modified Features

1. In some functions, the event mask judgment condition set when acquiring logs has been modified.

   (Logs that satisfy all set masks → Logs that satisfy even one)

* Refer to API [BS2_GetLogBlob](bs2_getlogblob)

- Refer to API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

1. Fixed an Invalid Parameter error that occurs when the set userMask is greater than 0x3FF when obtaining user information in some functions.

* Refer to API [BS2_GetUserDatas](bs2_getuserdatas)

- Refer to API [BS2_GetUserDatasEx](bs2_getuserdatasex)

- Refer to API [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir)

- Refer to API [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir)

1. Fixed a problem where a crash could occur in the context release phase when using Multi context.

   In addition, fixed a problem that could cause an access violation intermittently.

* Refer to API [BS2_AllocateContext](bs2_allocatecontext)

- Refer to API [BS2_ReleaseContext](bs2_releasecontext)

1. Fixed a problem where a crash could occur due to a buffer overflow while receiving a packet from the SDK.

1. Fixed a problem that caused a timeout occurs when deleting all users from an Entry family device.

* Refer to API [BS2_RemoveAllUser](bs2_removealluser)

1. Fixed a problem where a Not Supported error occurs when userMask is BS2_USER_MASK_ALL when obtaining user information.

* Refer to API [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask)

- Refer to API [BS2_GetSupportedUserMask](bs2_getsupportedusermask)

- Refer to API [BS2_GetUserDatas](bs2_getuserdatas)

- Refer to API [BS2_GetUserDatasEx](bs2_getuserdatasex)

1. Fixed a problem where a crash could occur when there is no data when obtaining logs.

* Refer to API [BS2_GetLog](bs2_getlog)

- Refer to API [BS2_GetFilteredLog](bs2_getfilteredlog)

- Refer to API [BS2_GetLogFromDir](bs2_getlogfromdir)

1. Fixed a problem where packet for multi packet could be discarded during RS485 communications.

1. Fixed a problem where the timer may not work on Linux SDK. (Change from signal method to thread method)

1. Fixed a problem that dead-lock could occur due to memory allocation in signal handle in Linux SDK.

1. Added socket close option SOCK_CLOEXEC when using socket on Linux.

1. Fixed a problem with lock/unlock incorrect sync objects internally when using the Server matching function.

1. Keep alive code has been improved to detect the disconnected status among the device status.

1. Fixed a problem where Intrusion Alarm Zone information was not set.

   In addition, incorrect error judgment conditions during validation have been corrected.

   Before: (0 \< door) AND (if there no card data), (0 \< card) AND (if there no door ID)

   After: (0 \< door) AND (if there no door ID), (0 \< card) AND (if there no card data)

* Refer to API [BS2_SetIntrusionAlarmZone](bs2_setintrusionalarmzone)

1. Fixed blocking until the timeout occurs when loading an image log that does not actually exist.

* Refer to API [BS2_GetImageLog](bs2_getimagelog)

- Refer to API [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir)

1. Fixed a problem so that allocation memory errors do not occur when there is no data in the **Intrusion Alarm Zone**.

   In addition, it has been modified to return only the count when zoneBlob is NULL.

* Refer to API [BS2_GetIntrusionAlarmZone](bs2_getintrusionalarmzone)

1. Fixed a problem where TCP connection was no longer possible when Socket-related internal resources were exhausted.

1. It has been modified so that it is returned as an Invalid Parameter when door ID exceeds 65535 when setting the door from an Entry family device.

* Refer to API [BS2_SetDoor](bs2_setdoor)

1. Added cryptographic activation code to handshake phase on TCP connection.

1. Fixed a problem where fingerprint information was not stored on FaceStation 2.

1. Fixed a problem where a crash occurs when using the [BS2_SearchDevicesCoreStation](bs2_searchdevicescorestation) function.

1. Fixed to validate a template and image size of the face when using the [BS2_EnrolUser](bs2_enroluser) function.

1. Fixed a problem of returning Not supported when using the below function.

* Refer to API [BS2_GetCardConfigEx](bs2_getcardconfigex)

- Refer to API [BS2_GetRs485ConfigEx](bs2_getrs485configex)

## Date

2018-04-15

:::warning

**CAUTION**

Up to version 2.5.0, Device SDK statically included OpenSSL library,

but starting with 2.6.0, it has been changed to link in shared library form.

Therefore, you need to run the appropriate OpenSSL library after installation.

The 2.6.0 library has been tested based on the OpenSSL 1.0.2n library.

The sample files contain the OpenSSL 1.0.2n Windows library file. 

:::

## New Features

- Supports for new device connections (BioLite N2, Xpass D2)

- Supports Daylight saving time (DST)

- Supports Interlock zone

- Supports data encryption key setting of device

- Factory default without network setting

1.New devices BioLite N2, Xpass D2 are supported. Xpass D2 is a slave exclusive card device.

1.Daylight Saving Time can be set up to 2 devices. In addition, relevant information has been added to the log to let you know when daylight saving time is in effect.

- Add API [BS2_GetDstConfig](bs2_getdstconfig)

- Add API [BS2_SetDstConfig](bs2_setdstconfig)

- Add structure [BS2DstConfig](configuration_api#bs2dstconfig)

- Modify structure [BS2Event](Log_Management_API#bs2event)

1. Interlock zone setting is supported. It is used when one door and the other door need to be exclusively locked to each other. Currently only CoreStation is available.

- Add API [BS2_GetInterlockZone](bs2_getinterlockzone)

- Add API [BS2_GetInterlockZoneStatus](bs2_getinterlockzonestatus)

- Add API [BS2_GetAllInterlockZoneStatus](bs2_getallinterlockzonestatus)

- Add API [BS2_SetInterlockZone](bs2_setinterlockzone)

- Add API [BS2_SetInterlockZoneAlarm](bs2_setinterlockzonealarm)

- Add API [BS2_RemoveInterlockZone](bs2_removeinterlockzone)

- Add API [BS2_RemoveAllInterlockZone](bs2_removeallinterlockzone)

- Add structure [BS2InterlockZoneBlob](zone_control_api#bs2interlockzoneblob)

1.Data Encryption key of the device can be changed and verified.

- Add API [BS2_GetDataEncryptKey](bs2_getdataencryptkey)

- Add API [BS2_SetDataEncryptKey](bs2_setdataencryptkey)

- Add API [BS2_RemoveDataEncryptKey](bs2_removedataencryptkey)

1.Supports new device initialization API BS2_ResetConfigExceptNetInfo. This API can factory default without network information unlike BS2_ResetConfig.

- Add API [BS2_ResetConfigExceptNetInfo](bs2_resetconfigexceptnetinfo)

1.Supports feature feasibility check API BS2_GetDeviceInfoEx. This API BS2_GetDeviceInfo uses structure BS2SimpleDeviceInfoEx which has recent fields moved from the BS2SimpleDeviceInfo.

- Add API [BS2_GetDeviceInfoEx](bs2_getdeviceinfoex)

- Add structure [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex)

## Modified features

1. Simultaneous use of Wiegand In / Out is supported.

   This function can be used by setting the mode value to 2 when Wiegand is set.

* Refer to structure [BS2WiegandConfig](configuration_api#bs2wiegandconfig)

1. Device security tamper setting is supported.

   The secureTamper of BS2SystemConfig can check and set whether the current security tamper is set.

     This structure must be configured after reading through BS2_GetSystemConfig, and then only necessary information should be modified through BS2_SetSystemConfig.

* Refer to structure [BS2SystemConfig](configuration_api#bs2systemconfig)

1. Fingerprinter is supported on FaceStation 2 or FaceLite

   Both FaceStation 2 and FaceLite do not have a fingerprint sensor and therefore do not support fingerprint authentication directly from those devices. However, fingerprint devices can be connected to as a slave device to either device, then it means fingerprint matching is supported.

   Thus, BS2SimpleDeviceInfo.fingersupported changed from 0 to 1.

   Whether or not the device currently supports fingerprint matching can be checked via fingerSupported in BS2SimpleDeviceInfo.

* Refer to structure [BS2SimpleDeviceInfo](device_api#bs2simpledeviceinfo)

---

# Version 2.5.0

## Date

2017-09-25

:::warning

**CAUTION**

You need to re-build SDK to SDK version upgrade as BioStar 2 Device SDK structure has been changed. 

:::

## New Features

- Supports SEOS Card(Including Elite Key, RF performance improvement)

- Supports CoreStation

- Supports Intrusion Alarm Zone

- Supports Ethernet Zone

- Supports USB log and user export

- Filtering log from device feature

1. SEOS Card(Including Elite Key, RF performance improvement) feature supports iClass SEOS card configuration via Smart card layout.

- Add API [BS2_GetCardConfigEx](bs2_getcardconfigex)

- Add API [BS2_SetCardConfigEx](bs2_setcardconfigex)

- Add structure [BS2CardConfigEx](Configuration_API#bs2cardconfigex)

1. CoreStation feature supports CoreStation which is the new Suprema device. CoreStation, which works as a controller of the master, performs overall functions along with Slave devices. The difference from other devices is CoreStation can't get credential input such as card or fingerprint since it works only as a controller. Also, CoreStation configuration and control setting is supported via BioStar because it doesn't have a separate UI.

- Add API [BS2_GetSlaveExDevice](bs2_getslaveexdevice)

- Add API [BS2_SetSlaveExDevice](bs2_setslaveexdevice)

- Add structure [BS2Rs485SlaveDeviceEX](Configuration_API#bs2rs485slavedeviceex)

1.Intrusion Alarm Zone supports following features. Normally Intrusion detection system sends signals when the installed sensor on the security facility detected intrusion or abnormal signals and it has two different ways - unmanned and local. In the Unmanned Intrusion detection system, security guards from the control center which is the remote location perform tasks when the an abnormal situation. On the other hand, in the Local Intrusion detection system, resident security guards from its own control center perform the overall task. BioStar targets users who feel pressured by the cost of an Unmanned intrusion system or whose local security guards based on their own Intrusion detection system. Currently, a normal Intrusion Alarm Zone(biostar1.X) is provided, and 3rd party alarm system intrusion detection On/Off device integration will be provided in the near future. In the long term, a professional local control system that can be applied to Video and Visual map features is a goal.

- Add API [BS2_GetIntrusionAlarmZone](bs2_getintrusionalarmzone)

- Add API [BS2_GetIntrusionAlarmZoneStatus](bs2_getintrusionalarmzonestatus)

- Add API [BS2_SetIntrusionAlarmZone](bs2_setintrusionalarmzone)

- Add API [BS2_SetIntrusionAlarmZoneAlarm](bs2_setintrusionalarmzonealarm)

- Add API [BS2_RemoveIntrusionAlarmZone](bs2_removeintrusionalarmzone)

- Add API [BS2_SetIntrusionAlarmZoneArm](bs2_setintrusionalarmzonearm)

- Add structure [BS2IntrusionAlarmZoneBlob](Configuration_API#bs2intrusionalarmzoneblob)

1.Ethernet Zone is the feature that a specific device(Not BioStar V2.x) performs as Zone Master using Ethernet TCP communication method between devices(Master \<-\> Member). Currently, it supports corresponding features to the existing 1.x Entrance Limit, Fire Alarm Zone.

- Add API [BS2_GetDeviceZone](bs2_getdevicezone)

- Add API [BS2_SetDeviceZone](bs2_setdevicezone)

- Add API [BS2_RemoveDeviceZone](bs2_removedevicezone)

- Add API [BS2_SetDeviceZoneAlarm](bs2_setdevicezonealarm)

- Add structure [BS2DeviceZoneConfig](Configuration_API#bs2devicezoneconfig)

1.USB log and User export support following features. It is used as T&A using Export/Import user & log data via USB at site where network connection is unavailable. (Usage Scenario) Users are registered at the head office where BioStar server is installed and USB memory which includes registered users is sent to the site, and T&A result is generated with log of the previous month at the beginning of every month. Practically it should be supported as a file type so that it can be handled via USB copy even when this USB data is re-forwarded.

- Add API [BS2_GetUserListFromDir](bs2_getuserlistfromdir)

- Add API [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir)

- Add API [BS2_GetLogFromDir](bs2_getlogfromdir)

1.Filtering log from device feature is improve the status of no response from the system when the log is filtered and showed from the device via SDK or when the device gets log.

- Add API [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid)

## Modified features

1. BS2_ScanFingerprint in SDK v2.4.1 is changed to BS2_ScanFingerprintEx in SDK v2.5.0 to distinguish function with existing BS2_ScanFingerprint before outQuality parameter has been added. We haven't deleted the existing BS2_ScanFingerprint function for backward compatibility.

```cpp
#include "BS_API.h"

int BS2_ScanFingerprintEx(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, uint32_t* outQuality, OnReadyToScan ptrReadyToScan);
```

1. Time reduction as giving wait time when SSL connect.

1. 'Internal Error' has been resolved when Payload size is huge.

1. The issue that some devices couldn't be found using UDP search has been resolved with the improvement of Packet Loss and Packet handling.

1. Comment out BS2Schedule for C# example since C# has a language limitation which Union is not supported. Using CSP_BS2Schedule instead of BS2Schedule, and for functions have to use BS2Schedule such as BS2_GetAllAccessSchedule, BS2_GetAccessSchedule and BS2_SetAccessSchedule can use WRAPPER function CSP_BS2_GetAllAccessSchedule, CSP_BS2_GetAccessSchedule and CSP_BS2_SetAccessSchedule. In CSP_BS2Schedule, for scheduleUnion.daily, scheduleUnion.weekly value can use valid parameter with isDaily.

1. Getting log of BS2_GetFilteredLogSinceEventId has been improved and it is applied to C# example too.

1. Template function for creating Wrapper function in Util GetAll, Get Remove, Set has been added in C# example.

1. CPU usage 100% in Linux has been resolved.

1. BS2CardModelEnum{ODPW, OAPW} has been added in C# example.

1. Transformation function UTC contents in regards to Util common UnixTimeStamp has been modified in C# example.

---

# Version 2.4.0

<text size="x-large"\>Date\</text\> 2017-3-24

:::warning

**CAUTION**

New APIs have been added that will work only with the v2.4 FW group. Please check the FW that will be compatible with the new APIs.

<text size="large"\>New API for v2.4\</text\>

* Add API [BS2_EnrolUserEx](bs2_enroluserex)

- Add API [BS2_GetUserInfosEx](bs2_getuserinfosex)

- Add structure [BS2UserBlobEx](user_management_api#bs2userblobex)

- Add [ssl api](ssl_api)

<text size="large"\>v2.4 Firmware Group\</text\>

| Device | FW version |
| --- | --- |
| BioStation 2 | 1.4.0 or higher |
| BioStation A2 | 1.3.0 or higher |
| BioStation L2 | 1.2.0 or higher |
| BioEntry W2 | 1.1.0 or higher |

:::

<text size="x-large"\>New Features\</text\> \1. A brand new lift controller OM-120 has been released. New APIs and structures were added to allow SDK users to integrate this device and features to their own system.

* Add [lift control api](lift_control_api)

The OM-120 is a new device having capability of controlling 12 relays which can be used for lifts. There is now a new concept as floors, which will work exactly like the doors. Once a user authenticates, the floors connected to the relays of the OM-120 will be activated depending on the floor level the access group has. The floor level is the same concept of the access level and they both will be allocated to an access group.

1. The new FaceStation 2 will be released in the 2nd quarter of 2017. The v2.4 has implemented all features so the FaceStation 2 can be used right away with its release.

* Add [face api](face_api) The FaceStation 2 will be supporting a feature called group matching, which is a feature where you can have maximum 5000 users to be used for 1:N matching. The user can select the group that they belong to, and continue with the face matching.

1. Certain devices will be compatible with the v1 Template on Cards. It was a downside of the v2 devices since there can be sites having v1 and v2 devices mixed. Now, it is possible to read the pre-issued cards from the v1 devices.

* Add structure [BS1CardConfig](configuration_api#bs1cardconfig) The v2 devices can now be set to read Template on Cards issued from a v1 device. The v2 device will need the starting block index to be the same as the CIS index block of the v1 Template on Card. To use both v1 Template on Card, v2 Access on Card/Secure Credential Card together, they will need to share the same starting block index and CIS index block.

1. Job code has been added to support flexibility on integrations with a T&A software. It is possible to allocate job codes to users and get the job code information from the logs. This feature is included only with the v2.4 FW group.

* Add structure [BS2UserBlobEx](user_management_api#bs2userblobex) Due to the limitation on size of the existing [BS2UserBlob](user_management_api#bs2userblob) structure, there were needs to create a new structure to implement a new feature. The new [BS2UserBlobEx](user_management_api#bs2userblobex) structure will work only with the v2.4 FW group which includes a field for the job code. Each user will have their own code and name for each job code.

1. A new method to retrieve logs has been added.

* Add API [BS2_GetLogBlob](bs2_getlogblob)

- Add structure [BS2EventBlob](log_management_api#bs2eventblob)

The existing API [BS2_GetLog](bs2_getlog) was not capable to get logs including the job code. Now there is a new API where it gets the event blob. The event blob can be categorized using a mask value, which leads to be possible to get logs based on the type of the log.

1. Personal messages will be supported from the next version of the firmware for certain devices. This was implemented to be ready to use once the releases are made.

* Add structure [BS2UserBlobEx](user_management_api#bs2userblobex) This feature will be supported starting from the FaceStation 2. The rest of the devices with a display screen will support this feature in the future release.

Due to the limitation on size of the existing [BS2UserBlob](user_management_api#bs2userblob) structure, there were needs to create a new structure to implement a new feature. The new [BS2UserBlobEx](user_management_api#bs2userblobex) structure will work only with the v2.4 FW group which includes a field for personal messages.

1. SSL Communication will be available between the server and devices. This will allow the devices to be only connected to a server where the certificate is valid.

* Add [ssl api](ssl_api)

<text size="x-large"\>Changed Objects\</text\>

1. Parameter \<text type="success"\>**outQuality**\</text\> has been added to the [BS2_ScanFingerprint](bs2_scanfingerprint) API

   The [BS2_ScanFingerprint](bs2_scanfingerprint) API now has a new parameter which returns the quality score of the scanned fingerprint. This was added to give a proper feedback to make fingerprint template management more efficient.

   **BEFORE**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, OnReadyToScan ptrReadyToScan);
```

**AFTER**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, uint32_t* outQuality, OnReadyToScan ptrReadyToScan);
```

1. Field \<text type="success"\>**useJobCode, useAlphanumericID, cameraFrequency**\</text\> has been added to the [BS2SystemConfig](Configuration_API#bs2systemconfig) structure

   The \<text type="success"\>**useJobCode**\</text\> field was added to allow enable/disable the usage of job codes.

   The alphanumeric ID was already allowed in the certain devices such as, BioStation 2, BioStation A2, BioStation L2, and BioEntry W2. However, the devices with display screens did not support keypads that allowed ID + credential authentications. Starting from the v2.4 FW group, the devices with a display screen can change the value of the \<text type="success"\>**useAlphanumericID**\</text\> field and allow users to input an alphanumeric ID for authentication.

   The camera frequency can be changed for the BioStation A2 device using the \<text type="success"\>**cameraFrequency**\</text\> field.

1. Parameter \<text type="success"\>**rs485mode, sslSupported, rootCertExist, dualIDSupported, useAlphanumericID, connectedIP, phraseCodeSupported, card1xSupported, systemExtSupported, voipSupported**\</text\> has been added to the [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) Structure

   The [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) Structure has additional fields that will indicate the capability and status of the device.

* \<text type="success"\>**rs485mode**\</text\> is a field where it determines the RS-485 mode of the device

* \<text type="success"\>**sslSupported**\</text\> is a field that indicates whether the device supports SSL connection

* \<text type="success"\>**rootCertExist**\</text\> is a field that indicates whether the device has the root certificate

* \<text type="success"\>**dualIDSupported**\</text\> is a field that indicates whether the device supports alphanumeric ID

* \<text type="success"\>**useAlphanumericID**\</text\> is a field where it determines the device is set to use alphanumeric ID

* \<text type="success"\>**connectedIP**\</text\> is a field where it determines the IP address of the server that the device is connected to

* \<text type="success"\>**phraseCodeSupported**\</text\> is a field that indicates whether the device supports personal messages

* \<text type="success"\>**card1xSupported**\</text\> is a field that indicates whether the device supports v1 ToC cards

* \<text type="success"\>**systemExtSupported**\</text\> is a field that indicates whether the device can set the RS-485 master key

* \<text type="success"\>**voipSupported**\</text\> is a field that indicates whether the device supports VoIP

<text size="x-large"\>Bug Fixes\</text\>

1. The UDP packet payload size has been changed starting from the v2.4 FW group. The SDK was modified to support both payload sizes for the old and new firmware.

1. The ALL mask of [BS2_GetConfig](bs2_getconfig) was not working properly. This was caused because the buffer size was set smaller than the added structure [BS2MultiWiegandConfig](Configuration_API#bs2multiwiegandconfig). Now the buffer size has been increased so the ALL mask will work properly.

1. The BioEntry Plus and BioEntry W did had the capability of using the multiple wiegand feature, but was ruled out in the SDK. Now these devices can operate using the multiple wiegand feature.

---

# Version 2.3.1.b

Date 2016-11-24

Bugs Fixed \1. The SDK had issues managing over 64 devices. Now the SDK is feasible to connect 1024 devices.

1. Enum \<text type="success"\>**BS2APBZoneReaderTypeEnum**\</text\> has been changed on the SFEnum.cs that is used when developing with C#. This enum was not equivalent to the actual value that is being used.

   | Enum | Before | After |
   | --- | --- | --- |
   | BS2_APB_ZONE_READER_NONE | 0 | -1 |
   | BS2_APB_ZONE_READER_ENTRY | 1 | 0 |
   | BS2_APB_ZONE_READER_EXIT | 2 | 1 |

1. API \<text type="success"\>**BS2_ReadImageLog**\</text\> was not able to process images over 16kB. Now, the SDK can receive image logs having size larger than 16kB.

---

# Version 2.3

Date 2016-08-03

New Features

- Supports Multi Wiegand Format

- Supports BioEntry W2

Added & Changed Features

1. Multi-wiegand feature has been added. You will now be able to use multiple types of formats with one device. If the device supports different card types, you will also be able to use multiple types of formats with various types of cards. Maximum 15 types of formats are supported.

- Add API [BS2_GetWiegandMultiConfig](bs2_getwiegandmulticonfig)

- Add API [BS2_SetWiegandMultiConfig](bs2_setwiegandmulticonfig)

- Add structure [BS2WiegandMultiConfig](Configuration_API#bs2wiegandmulticonfig)

1. Field \<text type="success"\>**wiegandMultiSupported**\</text\> has been added to the [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) structure

   The [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) structure is used to show information of the device following by which feature the device supports or not. Since the multi-wiegand feature has been implemented to the devices, this field has been added to show whether the device supports the multi-wiegand feature.

1. Mask \<text type="success"\>**Value 0x0D**\</text\>(BioEntry W2) has been added for the type field of [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) structure

   The [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) structure is used to give simple information about the device. Since the newly released BioEntry W2 is now supported from the BioStar 2 Device SDK, the mask for this product has been added.

1. Parameter \<text type="success"\>**IsAcceptableUserID**\</text\> has been added to the [BS2_GetUserList](bs2_getuserlist) API

   This callback function is irrelevant to BioStar 2 Device SDK developers. This is used by the BioStar v1.91 which is the latest BioStar 1 integrated with the BioStar 2 devices such as BioStation 2, BioStation A2, BioStation L2. The maximum user ID of BioStar 1 is 4294967295, but the V2 devices' maximum user ID can go up to 32 digits when creating a user directly from the device. To avoid uploading users having a user ID that is beyond the limit of BioStar 1, this callback function had to be added. BioStar 2 Device SDK developers just can put null for this parameter.

   **BEFORE**

```cpp
#include "BS_API.h"

int BS2_GetUserList(void* context, uint32_t deviceId, char** uidsObjs, uint32_t* numUid);
```

**AFTER**

```cpp
#include "BS_API.h"

int BS2_GetUserList(void* context, uint32_t deviceId, char** uidsObjs, uint32_t* numUid, IsAcceptableUserID ptrIsAcceptableUserID);
```

**EXAMPLE**

```cpp

BS2_GetUserList(context, deviceId, uidsObjs, numUid, null);
```

1. Add API [BS2_GetLastFingerprintImage](bs2_getlastfingerprintimage)

   An API that gets the actual image of the fingerprint has been added. This function has been implemented to provide a feature that has been existed in the BioStar 2 SW. This will allow you to monitor the actual status of the fingerprint by showing the image of the fingerprint instead of the fingerprint template. However, this image will not be used in any kind of matching.

1. Parameter \<text type="success"\>**templateFormat**\</text\> has been added to the [BS2_ScanFingerprint](bs2_scanfingerprint) API

   Suprema's fingerprint devices supports 3 types of fingerprint formats such as Suprema Template, ISO 19794-2, and ANSI 384. 

   | Value | Description |
   | --- | --- |
   | 0 | Suprema Template |
   | 1 | ISO19794-2 |
   | 2 | ANSI-378 |

   **BEFORE**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, OnReadyToScan ptrReadyToScan);
```

**AFTER**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, OnReadyToScan ptrReadyToScan);
```

1. Field \<text type="success"\>**wiegandMultiConfig**\</text\> has been added to [BS2Configs](Configuration_API#bs2configs) structure

   All structures related to configurations has been managed from the [BS2Configs](Configuration_API#bs2configs) structure. Since a new structure for multi wiegand has been added, this structure was added to the [BS2Configs](Configuration_API#bs2configs) structure.

1. Field \<text type="success"\>**wiegandInputMask**\</text\> has been added to the [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) structure

   Since multi-wiegand is now supported, there needs to be a bitmask field to set which format indexes will be used. This field is used to select the formats that will be understood by the master device when a card ID is sent through wiegand by a 3rd party wiegand reader or a slave device that is connected via RS-485. This can be used when the device is set to receive wiegand signals. For example, if you want to use format index 0, 2, 6, you need to set the bitmask to 0000000010001010. The 0th bit is reserved for the backward compatibility.

1. Field \<text type="success"\>**wiegandCardMask**\</text\> has been added to the [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) structure

   Since multi-wiegand is now supported, there needs to be a bitmask field to set which format indexes will be used. This field is used to select the formats that will be understood by the device when the card is directly placed to the device. This can be used when the device is set to send out wiegand signals. For example, if you want to use format index 0, 1, 2, 3, you need to set the value to 0000000000011110. The 0th bit is reserved for the backward compatibility.

1. Field \<text type="success"\>**wiegandCSNIndex**\</text\> has been added to the [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) structure

   When using a card that uses only the CSN of the card, you can still set the device to send out a wiegand signal in a specific format. This can be used when the device can only read Mifare cards or EM cards, but still needs to send out wiegand signals to another device in a certain format. For example, if you want to use format index 0, you need to set the value as 0.

1. Field \<text type="success"\>**reserved**\</text\> from the [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) structure has been changed to \<text type="success"\>**uint8_t reserved\[27\]**\</text\> from \<text type="success"\>**uint8_t reserved\[32\]**\</text\>

   There were 3 additional fields that have been added to the [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) structure, which are mentioned right above. Because of this, there were 5 bytes used from the reserved space, and the reserved space now has been reduced to 27 bytes.

1. Field \<text type="success"\>**alarmFlags**\</text\> from the [BS2Door](Door_Control_API#bs2door) sturcture has been changed to \<text type="success"\>**uint8_t unconditionalLock**\</text\> from \<text type="success"\>**uint8_t alarmFlags**\</text\>

   The \<text type="success"\>**alarmFlags**\</text\> is not used in the [BS2Door](Door_Control_API#bs2door) structure as now the \<text type="success"\>**alarmFlags**\</text\> can be displayed from the [BS2DoorStatus](Door_Control_API#bs2doorstatus) structure. Instead, the \<text type="success"\>**unconditionalLock**\</text\> field has been added for the new feature and is using the memory of the \<text type="success"\>**alarmFlags**\</text\>. The \<text type="success"\>**unconditionalLock**\</text\> field has been added to control automatic slide doors. When using a traditional dead-bolt lock, the lock shouldn't be locked after the configured time has passed unless the door is closed. However, when using an automatic slide door, there are needs for the door to be closed even when there is still an input on the door sensor. You can change this field to true to close the door regardless to the door sensor input.

---

# Version 2.2

Date 2016-01-31

New Features

- Access Control API

- Holiday group

- Blacklist

- Image log

- Firmware upgrade

- Resource update

- Door control

- Wiegand card reader's external signal feature

- Device initialization

- Notification feature

- Smart card feature(MIFARE, iClass, DesFire)

- Server matching

- Server URL

- Trigger action

- Wireless LAN configuration

- Anti Passback zone, Timed Anti Passback zone, Fire Alarm zone, Scheduled lock/unlock zone

---

# Version 2.1

Date 2015-08-26

New Features

- Supports Real-time log

- Wiegand I/O setting

---

# Version 2.0

Date 2015-07-06

New Features

- Supports x86 and x64 platform

- Uses the Suprema namespace

- Suprema.cs is subdivided into SFEnum.cs, SFStruct.cs, SFApi.cs

- Direct connection and UDP Search

- Reads the configuration information (Firmware, System, Authentication, Display, Network, Card, Fingerprint, T&A)

- Manages the user list (Import/Delete/Add)

- Fingerprint and card can be enrolled

- Manages the log (Import/Filtering/Delete)

- Can cancel the process when importing the user list or entire log

---

