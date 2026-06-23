# Doxygen을 이용한 HTML 문서 제작

이 프로젝트는 BioStar Device SDK에 대한 문서를 만들기 위한 프로젝트입니다.

## 목표

Doxygen을 이용해 HTML 문서를 제작하려고 합니다.

기존에는 DokuWiki(<https://kb.supremainc.com/bs2sdk/doku.php)를> 이용해 제작했으나 코드와 문서의 일관성있는 문서 제작을 위해 Doxygen을 활용하려고 합니다.

* Include 경로의 C++ 파일들에는 적절한 설명이 부족, 이 부분을 _reference 경로의 마크다운 파일을 참조해서 문서 작업을 진행할 것
* 한국어, 영어 문서 제작해야 함

## DokuWiki 문서 마크다운으로 저장

_reference 경로에 DokuWiki의 문서들을 마크다운으로 변환하여 저장함. 한국어, 영어 폴더로 구분됨

## 코드 파일

Include 경로의 SDK 코드 파일을 확인하세요. 각 코드 파일에 _refernece 경로의 마크다운 파일을 참조하여 내용을 추가하세요.

### 주요 파일 구조

* `Include/BS_API.h` — 메인 API 함수 선언 파일 (90KB, 문서화 작업의 주요 대상)
* `Include/BS_Errno.h` — 에러 코드 정의 (_reference/{lang}/return_code.md와 연동)
* `Include/BS_Deprecated.h` — deprecated 함수 목록
* `Include/BSCommon/BS2Types.h` — 공통 타입 정의
* `Include/BSCommon/config/` — 설정 구조체 헤더 파일 (30개)
* `Include/BSCommon/data/` — 데이터 구조체 헤더 파일 (28개)
* `Include/BSCommon/protocol/` — 프로토콜 정의 헤더 파일 (4개)

## Doxygen 설정 파일

* 영어 문서: `biostar_device_sdk` (현재 존재, `OUTPUT_LANGUAGE = English`, `OUTPUT_DIRECTORY = output`)
  * 새로 생성할 것
* 한국어 문서: `biostar_device_sdk_ko` 별도 생성 필요 (`OUTPUT_LANGUAGE = Korean`, `OUTPUT_DIRECTORY = output_ko`)

### 다국어 문서 생성 전략

참조: <https://www.doxygen.nl/manual/langhowto.html>

영어를 우선으로 진행하고, 한글은 추후 진행하는 것으로.

#### 핵심 원칙: `\~` 언어 전환 명령 + `EXAMPLE_PATH` 스위칭

**`BS_API.h` 함수 주석 작성 형식**

```cpp
/**
 * \~english
 * @brief Returns the SDK version string.
 * @param[in] context SDK context handle.
 * @return Null-terminated string representing the SDK version.
 * \~korean
 * @brief SDK 버전을 반환합니다.
 * @param[in] context SDK 컨텍스트 핸들.
 * @return 버전 문자열을 반환합니다.
 * \~
 * @ingroup group_sdk_api
 * @include{doc} bs2_version.md
 */
```

* `\~english` / `\~korean` — 이후 내용을 해당 언어 빌드에서만 표시
* `\~` — 언어 제한 해제 (이후 내용은 모든 언어에 공통 적용)
* `@ingroup`, `@include{doc}` 는 반드시 `\~` 이후(공통 영역)에 작성

**`EXAMPLE_PATH` 스위칭**

`@include{doc} bs2_version.md` 처럼 파일명만 명시하면, Doxygen이 `EXAMPLE_PATH`에서 파일을 탐색함.

* 영어 Doxyfile: `EXAMPLE_PATH = _reference/en` → `_reference/en/bs2_version.md`
* 한국어 Doxyfile: `EXAMPLE_PATH = _reference/ko` → `_reference/ko/bs2_version.md`

`_reference/en/`과 `_reference/ko/` 의 파일명이 동일(517개 vs 516개)하므로, `@include{doc}` 코드 수정 없이 Doxyfile의 `EXAMPLE_PATH` 한 줄만 바꾸면 전체 함수 상세 설명이 자동 전환됨.

#### 파일별 역할

| 파일 | 역할 |
| ------ | ------ |
| `BS_API.h` | `\~english`/`\~korean`으로 @brief, @param, @return 이중 언어 작성 |
| `docs/en/groups.dox` | 영어 `@defgroup` brief 정의 |
| `docs/ko/groups.dox` | 한국어 `@defgroup` brief 정의 |
| `biostar_device_sdk_en` | 영어 Doxyfile: `EXAMPLE_PATH = _reference/en` |
| `biostar_device_sdk_ko` | 한국어 Doxyfile: `EXAMPLE_PATH = _reference/ko`, `OUTPUT_LANGUAGE = Korean` |

### Doxygen 주석 작성 지침

함수 문서화 형식:

```cpp
/**
 * @brief 함수의 간략한 설명
 * @param[in] context SDK context handle
 * @param[out] deviceId 디바이스 ID
 * @return BS_SDK_SUCCESS on success, error code otherwise
 * @see BS2_ReleaseContext
 */
```

그룹 태그:

* `@defgroup` — 그룹 정의 (별도 .dox 파일 또는 헤더 파일 상단에 작성)
* `@ingroup` — 함수/구조체를 특정 그룹에 소속
* `@addtogroup` + `@{` ... `@}` — 여러 항목을 한 블록으로 그룹에 추가

구조체/enum 문서화:

```cpp
typedef struct {
    uint32_t deviceId;  ///< 디바이스 식별자
    uint8_t type;       ///< 디바이스 타입
} BS2Device;
```

## 페이지 순서

* **Main Page**: _reference/{lang}/start.md 콘텐츠 사용
* **Quick Guide**: _reference/{lang}/quick_guide.md 콘텐츠 사용
* **Release Notes**: reference/{lang}/release_note_*.md 파일들을 병합하여 최신 순으로 나열할 것
* **Return Code**: `BS_Errno.h` - _reference/{lang}/return_code.md 파일과 연동하여 주석 추가할 것
* **Topics**: 카테고리화된 문서 모음
* **Classes**
  * Class list
  * Class Index
  * Class Hierarchy
* **Files**
  * File list

## Doxygen 문서 카테고리화

아래의 기준으로 Group/Module 기능을 적용할 것.

* SDK API: _reference/{lang}/sdk_api.md 파일 참조
  * BS2_Version: Returns the SDK version.
  * BS2_AllocateContext: Allocates the device management Context.
  * BS2_ReleaseContext: Releases the device management Context.
  * BS2_Initialize: Initializes the device management Context.
  * BS2_InitializeEx: [+ 2.9.6] Initializes the device management context.
  * BS2_ReleaseObject: Releases dynamic memory.
  * BS2_MakePinCode: Encrypts the PIN.
  * BS2_MakePinCodeWithKey: [+ 2.7.1] Encrypts PIN code with the user-defined PIN encryption key.
  * BS2_SetMaxThreadCount: Specifies the maximum thread count.
  * BS2_ComputeCRC16CCITT: Calculates the CRC-16 CCITT checksum.
  * BS2_GetCardModel: Retrieves the supported card models.
  * BS2_SetDataEncryptKey: [+ 2.7.1] Changes the user defined PIN encryption key.
  * BS2_RemoveDataEncryptKey: Removes the encryption key for the device.
  * BS2_SetDeviceSearchingTimeout: Specifies the device searching time.
  * BS2_SetDebugFileLog: Retrieves debugging file log.
  * BS2_EnableDeviceLicense: [+ 2.9.1] Activate the device license.
  * BS2_DisableDeviceLicense: [+ 2.9.1] Deactivate the device license.
  * BS2_QueryDeviceLicense: [+ 2.9.1] Check device license information.
* Debugging API
  * BS2_SetDebugExCallback: Registers the callback function that gets called for debugging message.
* Communication API
  * BS2_SetDeviceEventListener: Sets device search and network connection event listener.
  * BS2_SearchDevices: Search for devices in subnet.
  * BS2_SearchDevicesEx: Search for devices in a specific IP address band.
  * BS2_GetDevices: Gets the managed device information.
  * BS2_ConnectDevice: Connects the device using the device identifier.
  * BS2_ConnectDeviceIPV6: Connects the device in IPv6 mode using the device identifier.
  * BS2_ConnectDeviceViaIP: Connect devices using IP address and Port.
  * BS2_DisconnectDevice: Disconnects from the device.
  * BS2_SetKeepAliveTimeout: Sets the keep-alive timeout.
  * BS2_SetNotificationListener: Sets the Notification listener.
  * BS2_SetServerPort: Sets the server Port.
  * BS2_SetSSLServerPort: Sets the SSL server Port.
  * BS2_GetServerPort: [+ 2.6.3] Gets the server Port.
  * BS2_GetSSLServerPort: [+ 2.6.3] Gets the SSL server port.
  * BS2_IsConnected: Checks device connection status.
  * BS2_IsAutoConnection: Checks auto connection status.
  * BS2_SetAutoConnection: Sets auto connection.
  * BS2_GetEnableIPV4: [+ 2.6.3] Gets IPv4 connection mode.
  * BS2_SetEnableIPV4: [+ 2.6.3] Sets IPv4 connection mode.
  * BS2_GetEnableIPV6: [+ 2.6.3] Gets IPv6 connection mode.
  * BS2_SetEnableIPV6: [+ 2.6.3] Sets IPv6 connection mode.
  * BS2_SetServerPortIPV6: [+ 2.6.3] Sets server port when connecting IPv6 server mode.
  * BS2_GetServerPortIPV6: [+ 2.6.3] Gets server port when connecting IPv6 server mode.
  * BS2_SetSSLServerPortIPV6: [+ 2.6.3] Sets server port when connecting IPv6 server mode using SSL.
  * BS2_GetSSLServerPortIPV6: [+ 2.6.3] Gets server port when connecting IPv6 server mode using SSL.
  * BS2_SetDefaultResponseTimeout: [+ 2.6.3] Sets default response timeout between device and server.
  * BS2_GetDefaultResponseTimeout: [+ 2.6.3] Gets default response timeout between device and server.
  * BS2_GetSocketRetryCount: [+ 2.9.1] Gets the setting value of the number of retries for read/write failures during Non SSL communication.
  * BS2_SetSocketRetryCount: [+ 2.9.1] Set the number of retries for read/write failures during Non SSL communication.
  * BS2_GetSocketSSLRetryCount: [+ 2.9.1] Gets the setting value of the number of retries for read/write failures during SSL communication.
  * BS2_SetSocketSSLRetryCount: [+ 2.9.1] Set the number of retries for read/write failures during SSL communication.
  * BS2_SetDefaultLongResponseTimeout: [+ 2.9.12] Sets the packet response timeout with the device. (For time-intensive APIs)
  * BS2_GetDefaultLongResponseTimeout: [+ 2.9.12] Checks the packet response timeout information with the device. (For time-intensive APIs)
* SSL API
  * BS2_SetSSLHandler: Configures the SSL communication.
  * BS2_DisableSSL: Disables the SSL communication.
* Device API
  * BS2_GetDeviceInfo: Gets the device information.
  * BS2_GetDeviceInfoEx: [+ 2.6.0] Gets additional device information.
  * BS2_GetDeviceTime: Gets the device time.
  * BS2_SetDeviceTime: Sets the device time.
  * BS2_ClearDatabase: Initializes the user information and blacklist.
  * BS2_FactoryReset: Initializes all configurations and the database.
  * BS2_RebootDevice: Restarts the device.
  * BS2_LockDevice: Doesn't allow user authentication by locking the device.
  * BS2_UnlockDevice: Allows user authentication by unlocking the device.
  * BS2_SetKeepAliveTimeout: Configures the keep-alive time of the device.
  * BS2_UpgradeFirmware: Upgrades the firmware.
  * BS2_UpdateResource: Updates the resource.
  * BS2_GetSpecifiedDeviceInfo: [+ 2.6.3] Gets specified device information.
  * BS2_GetAuthOperatorLevelEx: [+ 2.6.3] Gets specified device operator. (Support operator up to 1000)
  * BS2_GetAllAuthOperatorLevelEx: [+ 2.6.3] Gets all device operators. (Support operator up to 1000)
  * BS2_SetAuthOperatorLevelEx: [+ 2.6.3] Sets device operator. (Support operator up to 1000)
  * BS2_RemoveAuthOperatorLevelEx: [+ 2.6.3] Removes specified device operator. (Support operator up to 1000)
  * BS2_RemoveAllAuthOperatorLevelEx: [+ 2.6.3] Removes all device operators. (Support operator up to 1000)
  * BS2_GetDeviceCapabilities: [+ 2.8] Gets available function information of the device.
  * BS2_RunAction: [+ 2.8.1] Commands the device to take certain actions.
  * BS2_GetMasterAdmin: [+ 2.9.12] Gets the master admin from the device.
  * BS2_SetMasterAdmin: [+ 2.9.12] Sets the master admin on the device.
* Log Management API
  * BS2_GetLog: Gets certain amount of logs.
  * BS2_GetFilteredLog: [Deprecated] Gets filtered logs.
  * BS2_ClearLog: Deletes all logs.
  * BS2_StartMonitoringLog: Starts Real-time log streaming.
  * BS2_StartMonitoringLogEx: [+ V2.7.1] Starts Real-time log streaming including the temperature information.
  * BS2_StopMonitoringLog: Stops Real-time log streaming.
  * BS2_GetLogBlob: Gets certain amount of logs based on the event mask.
  * BS2_GetFilteredLogSinceEventId: [Deprecated] Gets filtered logs.
  * BS2_GetImageLog : Gets image logs using event ID.
  * BS2_GetLogSmallBlob: [+ 2.6.4] Gets certain amount of logs based on the event mask in an efficient way.
  * BS2_GetLogSmallBlobEx: [+ 2.7.1] Gets certain amount of logs based on the event mask in an efficient way, including the temperature information.
  * BS2_GetDeviceIOStatus: [+ 2.9.12] Gets the current device I/O port status.
  * BS2_GetAllDeviceIOStatus: [+ 2.9.12] Gets the current I/O port status of the device and slave devices.
* User Management API
  * BS2_GetUserList: Gets the enrolled user ID list.
  * BS2_RemoveUser: Deletes user.
  * BS2_RemoveAllUser: Deletes all users.
  * BS2_GetUserInfos: Gets the user information of the given user ID.
  * BS2_GetUserInfosEx: [+ 2.4.0] Gets the user information of the given user ID. (including Job code and User phrase)
  * BS2_EnrolUser: Enrolls new user.
  * BS2_EnrolUserEx: [+ 2.4.0] Enrolls new user. (including Job code and User phrase)
  * BS2_EnrollUser: [+ 2.6.3] Enrolls new user.
  * BS2_EnrollUserEx: [+ 2.6.3] Enrolls new user. (including Job code and User phrase)
  * BS2_GetUserDatas:​ Gets selected data of user.
  * BS2_GetUserDatasEx:​ [+ 2.5.0] Gets selected data of user. (including Job code, User phrase)
  * BS2_GetSupportedUserMask: Gets user settings supported by the device.
  * BS2_EnrollUserSmall: [+ 2.6.3] Enrolls new user with efficient use of memory.
  * BS2_EnrollUserSmallEx: [+ 2.6.3] Enrolls new user with efficient use of memory.
  * BS2_GetUserSmallInfos: [+ 2.6.3] Gets the user information of the given user ID with efficient use of memory.
  * BS2_GetUserSmallInfosEx: [+ 2.6.3] Gets the user information of the given user ID with efficient use of memory.
  * BS2_GetUserSmallDatas: [+ 2.6.3] Gets selected data of user with efficient use of memory.
  * BS2_GetUserSmallDatasEx: [+ 2.6.3] Gets selected data of user with efficient use of memory.
  * BS2_EnrollUserFaceEx: [+ 2.7.1] Visual Face Support Enrolls new user.
  * BS2_GetUserInfosFaceEx: [+ 2.7.1] Visual Face Support Gets the user information of the given user ID.
  * BS2_GetUserDatasFaceEx: [+ 2.7.1] Visual Face Support Gets selected data of user.
  * BS2_PartialUpdateUser: [+ 2.8.3] Updates partial information of an already registered user.
  * BS2_PartialUpdateUserEx: [+ 2.8.3] Updates partial information of an already registered user. (including Job code and User phrase)
  * BS2_PartialUpdateUserSmall: [+ 2.8.3] Updates partial information of an already registered user with efficient use of memory.
  * BS2_PartialUpdateUserSmallEx: [+ 2.8.3] Updates partial information of an already registered user with efficient use of memory.
  * BS2_PartialUpdateUserFaceEx: [+ 2.8.3] Visual Face Support Updates partial information of an already registered user.
  * BS2_GetUserStatistic: [+ 2.8.3] Gets the user-related statistics that the device has.
  * BS2_GetUserOverride: [+ 2.9.12] Gets user information for extended door open time that meets specified conditions.
  * BS2_GetAllUserOverride: [+ 2.9.12] Gets all user information using extended door open time.
  * BS2_SetUserOverride: [+ 2.9.12] Sets users to use extended door open time.
  * BS2_RemoveUserOverride: [+ 2.9.12] Removes users using extended door open time.
  * BS2_RemoveAllUserOverride: [+ 2.9.12] Removes all users using extended door open time.
* Configuration API
  * BS2_ResetConfig: Initializes the device's configurations.
  * BS2_ResetConfigExceptNetInfo:​ Initializes the setting information of the device. (Excluding network settings)
  * BS2_GetConfig: Retrieves configuration blob from the device.
  * BS2_SetConfig: Stores configuration blob on the device.
  * BS2_GetFactoryConfig: Retrieves software version and hardware settings from the device.
  * BS2_GetSystemConfig: Retrieves system settings from the device.
  * BS2_SetSystemConfig: Stores system settings on the device.
  * BS2_GetAuthConfig: Retrieves authentication settings from the device.
  * BS2_SetAuthConfig: Stores authentication settings on the device.
  * BS2_GetStatusConfig: Retrieves LED and buzzer settings from the device.
  * BS2_SetStatusConfig: Stores LED and buzzer settings on the device.
  * BS2_GetDisplayConfig: Retrieves sound and UI settings from the device.
  * BS2_SetDisplayConfig: Stores sound and UI settings on the device.
  * BS2_GetIPConfig: Retrieves IP settings from the device.
  * BS2_GetIPConfigViaUDP: Retrieves IP settings from the device via the UDP broadcasting.
  * BS2_SetIPConfig: Stores IP settings on the device.
  * BS2_SetIPConfigViaUDP: Stores IP settings on the device via the UDP broadcasting.
  * BS2_GetIPConfigExt: Retrieves DNS and server URL settings from the device.
  * BS2_SetIPConfigExt: Stores DNS and server URL settings on the device.
  * BS2_GetTNAConfig: Retrieves time and attendance settings from the device.
  * BS2_SetTNAConfig: Stores time and attendance settings on the device.
  * BS2_GetCardConfig: Retrieves smart card settings from the device.
  * BS2_SetCardConfig: Stores smart card settings on the device.
  * BS2_GetFingerprintConfig: Retrieves fingerprint matching settings from the device.
  * BS2_SetFingerprintConfig: Stores fingerprint matching settings on the device.
  * BS2_GetRS485Config: Retrieves RS-485 network settings from the device.
  * BS2_SetRS485Config: Stores RS-485 network settings on the device.
  * BS2_GetWiegandConfig: Retrieves Wiegand I/O settings from the device.
  * BS2_SetWiegandConfig: Stores Wiegand I/O settings on the device.
  * BS2_GetWiegandDeviceConfig: Retrieves Wiegand device settings from the device.
  * BS2_SetWiegandDeviceConfig: Stores Wiegand device settings on the device.
  * BS2_GetInputConfig: Retrieves supervised input port settings from the device.
  * BS2_SetInputConfig: Stores supervised input port settings on the device.
  * BS2_GetWlanConfig: Retrieves wireless LAN settings from the device.
  * BS2_SetWlanConfig: Stores wireless LAN settings on the device.
  * BS2_GetTriggerActionConfig: Retrieves trigger and action settings from the device.
  * BS2_SetTriggerActionConfig: Stores trigger and action settings on the device.
  * BS2_GetEventConfig: Retrieves image log filter settings from the device.
  * BS2_SetEventConfig: Stores image log filter settings on the device.
  * BS2_GetWiegandMultiConfig: Retrieves Multi-Wiegand settings from the device.
  * BS2_SetWiegandMultiConfig: Stores Multi-Wiegand settings on the device.
  * BS2_GetCard1xConfig: Retrieves v1 Template on Card settings from the device.
  * BS2_SetCard1xConfig: Stores v1 Template on Card settings on the device.
  * BS2_GetSystemExtConfig: Retrieves Master and slave device encryption settings from the device.
  * BS2_SetSystemExtConfig: Stores Master and slave device encryption settings on the device
  * BS2_GetVoipConfig: Retrieves VoIP settings from the device.
  * BS2_SetVoipConfig: Stores VoIP settings on the device.
  * BS2_GetFaceConfig: Retrieves face settings from the device.
  * BS2_SetFaceConfig: Stores face settings on the device.
  * BS2_GetRS485ConfigEx: In case of Corestation, retrieves RS-485 network settings from the device.
  * BS2_SetRS485ConfigEx: In case of CoreStation, stores RS-485 network settings on the device.
  * BS2_GetCardConfigEx: Retrieves iClass SEOS card settings from the device.
  * BS2_SetCardConfigEx: Stores iClass SEOS card settings on the device.
  * BS2_GetDstConfig:​ Retrieves the device DST information.
  * BS2_SetDstConfig:​ Stores the device DST information.
  * BS2_GetSupportedConfigMask: Retrieves supported configuration of the device.
  * BS2_GetIPConfigViaUDPEx: [+ 2.6.3] Retrieves IP configuration through UDP broadcast with host IP.
  * BS2_SetIPConfigViaUDPEx: [+ 2.6.3] Stores IP configuration through UDP broadcast with host IP.
  * BS2_GetIPV6Config: [+ 2.6.3] Retrieves IPv6 configuration information.
  * BS2_SetIPV6Config: [+ 2.6.3] Stores IPv6 configuration information.
  * BS2_GetIPV6ConfigViaUDP: [+ 2.6.3] Retrieves IPv6 configuration through UDP broadcast.
  * BS2_SetIPV6ConfigViaUDP: [+ 2.6.3] Stores IPv6 configuration through UDP broadcast.
  * BS2_GetIPV6ConfigViaUDPEx: [+ 2.6.3] Retrieves IPv6 configuration through UDP broadcast with host IP.
  * BS2_SetIPV6ConfigViaUDPEx: [+ 2.6.3] Stores IPv6 configuration through UDP broadcast with host IP.
  * BS2_GetDesFireCardConfigEx: [+ 2.6.4] Retrieves DesFire advanced configuration from the device.
  * BS2_SetDesFireCardConfigEx: [+ 2.6.4] Sets DesFire advanced configuration in the device.
  * BS2_GetAuthConfigExt: [+ 2.7.1] Visual Face-based devices Retrieves authentication settings from the device.
  * BS2_SetAuthConfigExt: [+ 2.7.1] Visual Face-based devices Stores authentication settings from the device.
  * BS2_GetFaceConfigExt: [+ 2.7.1] Retrieves configuration of thermal camera and mask detection.
  * BS2_SetFaceConfigExt: [+ 2.7.1] Stores configuration of thermal camera and mask detection.
  * BS2_GetThermalCameraConfig: [+ 2.7.1] Retrieves configuration of thermal camera.
  * BS2_SetThermalCameraConfig: [+ 2.7.1] Stores configuration of thermal camera.
  * BS2_GetBarcodeConfig: [+ 2.8] X-Station 2 Retrieves configuration of Barcode.
  * BS2_SetBarcodeConfig: [+ 2.8] X-Station 2 Stores configuration of Barcode.
  * BS2_GetInputConfigEx:​ [+ 2.8.1] ​IM-120​ Retrieves Expanded Configuration related to the Input.
  * BS2_SetInputConfigEx:​ [+ 2.8.1] ​IM-120​ Retrieves Expanded Configuration related to the Input.
  * BS2_GetRelayActionConfig:​ [+ 2.8.1] ​IM-120​ Retrieves Configuration related to the RelayAction.
  * BS2_SetRelayActionConfig:​ [+ 2.8.1] ​IM-120​ Retrieves Configuration related to the RelayAction.
  * BS2_GetVoipConfigExt: [+ 2.8.3] Gets the extended VoIP settings.
  * BS2_SetVoipConfigExt: [+ 2.8.3] Save the extended VoIP settings.
  * BS2_GetRtspConfig: [+ 2.8.3] Gets the RTSP settings.
  * BS2_SetRtspConfig: [+ 2.8.3] Save the RTSP settings.
  * BS2_GetLicenseConfig: [+ 2.9.1] Gets the device license activation information.
  * BS2_GetOsdpStandardConfig: [+ 2.9.1] Get the device's OSDP setting information.
  * BS2_GetOsdpStandardActionConfig: [+ 2.9.1] Get the LED/buzzer settings for each action of the OSDP device.
  * BS2_SetOsdpStandardActionConfig: [+ 2.9.1] Specifies the LED/buzzer setting for each action of the OSDP device.
  * BS2_GetCustomCardConfig: [+ 2.9.4] Retrieves Custom smart card settings.
  * BS2_SetCustomCardConfig: [+ 2.9.4] Stores Custom smart card settings.
  * BS2_GetMifareCardConfigEx: [+ 2.9.9] Gets the setting information used for AES128-encrypted Mifare cards on the device.
  * BS2_SetMifareCardConfigEx: [+ 2.9.9] Saves the setting information used for AES128-encrypted Mifare cards on the device.
  * BS2_GetFacilityCodeConfig: [+ 2.9.9] Gets the BS2FacilityCode used as an authentication code when the OSDP connection between the Door Interface (DI-24) and the master device is lost.
  * BS2_SetFacilityCodeConfig: [+ 2.9.9] Saves the BS2FacilityCode setting used as an authentication code when the OSDP connection between the Door Interface (DI-24) and the master device is lost.
  * BS2_GetRS485ConfigExDynamic: [+ 2.9.9] Gets the RS485 network setting information for CoreStation.
  * BS2_SetRS485ConfigExDynamic: [+ 2.9.9] Saves the RS485 network setting information for CoreStation.
* Smartcard API
  * BS2_ScanCard: Scans the card from the device and analyzes it.
  * BS2_WriteCard: Writes data to the smart card.
  * BS2_EraseCard: Formats the smart card.
  * BS2_GetLockOverride: [+ 2.9.12] Gets Lock Override information from the device that meets specific conditions.
  * BS2_GetAllLockOverride: [+ 2.9.12] Gets all Lock Override information from the device.
  * BS2_SetLockOverride: [+ 2.9.12] Sets Lock Override information on the device.
  * BS2_RemoveLockOverride: [+ 2.9.12] Removes Lock Override information from the device that meets specific conditions.
  * BS2_RemoveAllLockOverride: [+ 2.9.12] Removes all Lock Override information from the device.
* QR code API
  * BS2_WriteQRCode: [+ 2.8] X-Station 2 Write a string to be used as a QR code in the card structure.
* Fingerprint API
  * BS2_ScanFingerprint: Scans a fingerprint from a device and extracts template data.
  * BS2_ScanFingerprintEx:​ Scans a fingerprint from a device and extracts template data and scan image scores.
  * BS2_VerifyFingerprint: Compares the template data to check if it is the same finger.
  * BS2_GetLastFingerprintImage: Extracts the image of the last scanned fingerprint using the BS2_ScanFingerprint API.
  * BS2_GetFingerTemplateQuality: Checks the quality score of the fingerprint from the fingerprint template data.
* Face API: This API allows to scan/verify the face template.
  * BS2_ScanFace: IR Face based Scans the face from a device and extracts template and image data.
  * BS2_GetAuthGroup: Retrieves selected authentication groups.
  * BS2_GetAllAuthGroup: Retrieves all authentication groups.
  * BS2_SetAuthGroup: Configures an authentication group.
  * BS2_RemoveAuthGroup: Removes selected authentication groups.
  * BS2_RemoveAllAuthGroup: Remove all authentication groups.
* FaceEx API
  * BS2_ScanFaceEx: Visual Face based Scans the face from a device and extracts template and image data. [+ 2.7.1]
  * BS2_ExtractTemplateFaceEx: Visual Face based Extracts template data by the face image. [+ 2.7.1]
  * BS2_GetNormalizedImageFaceEx: Visual Face based Create a WARP image with an un-warped (unprocessed) face image. [+ 2.8]
* Access Control API: API for access control, which can manage access authority by individual, group, time schedules.
  * BS2_GetAccessGroup: Retrieves selected access groups.
  * BS2_GetAllAccessGroup: Retrieves all access groups.
  * BS2_SetAccessGroup: Configures an access group.
  * BS2_RemoveAccessGroup: Removes selected access groups.
  * BS2_RemoveAllAccessGroup: Removes all access groups.
  * BS2_GetAccessLevel: Retrieves selected access levels.
  * BS2_GetAllAccessLevel: Retrieves all access levels.
  * BS2_SetAccessLevel: Configures an access level.
  * BS2_RemoveAccessLevel: Removes selected access levels.
  * BS2_RemoveAllAccessLevel: Removes all access levels.
  * BS2_GetAccessSchedule: Retrieves selected time schedules.
  * BS2_GetAllAccessSchedule: Retrieves all time schedules.
  * BS2_SetAccessSchedule: Configures a time schedule.
  * BS2_RemoveAccessSchedule: Removes selected time schedules.
  * BS2_RemoveAllAccessSchedule: Removes all time schedules.
  * BS2_GetHolidayGroup: Retrieves selected holiday groups.
  * BS2_GetAllHolidayGroup: Retrieves all holiday groups.
  * BS2_SetHolidayGroup: Configures a holiday group.
  * BS2_RemoveHolidayGroup: Removes selected holiday groups.
  * BS2_RemoveAllHolidayGroup: Removes all holiday groups.
* Blacklist API: API that adds a card to the blacklist when a card is lost or to limit access.
  * BS2_GetBlackList: Retrieves selected blacklists.
  * BS2_GetAllBlackList: Retrieves all blacklists.
  * BS2_SetBlackList: Configures a blacklist.
  * BS2_RemoveBlackList: Removes selected blacklists.
  * BS2_RemoveAllBlackList: Removes all blacklists.
* Door Control API: API that configures whether the device is set as entrance/exit of the door, how the device will control the door, and the APB settings.
  * BS2_GetDoor: Retrieves selected doors.
  * BS2_GetAllDoor: Retrieves all doors.
  * BS2_GetDoorStatus: Retrieves the status of selected doors.
  * BS2_GetAllDoorStatus: Retrieves the status of all doors.
  * BS2_SetDoor: Configures a door.
  * BS2_SetDoorAlarm: Configures the alarm status of the door.
  * BS2_RemoveDoor: Removes selected doors.
  * BS2_RemoveAllDoor: Removes all doors.
  * BS2_ReleaseDoor: Releases the lock/unlock flag of the door status. This initializes the priorities set to the door.
  * BS2_LockDoor: Configures the priority of when the door gets locked. The lock priority must be higher than the unlock to lock the door.
  * BS2_UnlockDoor: Configures the priority of when the door gets unlocked. The unlock priority must be higher than the lock to unlock the door.
  * BS2_TimedLockDoor: [+ 2.9.12] Performs timed door lock.
  * BS2_TimedUnlockDoor: [+ 2.9.12] Performs timed door unlock.
* Lift Control API: API that configures the OM-120, which can control lifts.
  * BS2_GetLift: Retrieves selected lifts.
  * BS2_GetAllLift: Retrieves all lifts.
  * BS2_GetLiftStatus: Retrieves the status of selected lifts.
  * BS2_GetAllLiftStatus: Retrieves the status of all lifts.
  * BS2_SetLift: Configures a lift.
  * BS2_SetLiftAlarm: Configures the alarm status of the lift.
  * BS2_RemoveLift: Removes selected lifts.
  * BS2_RemoveAllLift: Removes all doors.
  * BS2_ReleaseFloor: Releases the activate/deactivate flag of the lift status. This initializes the priorities set to the lift.
  * BS2_ActivateFloor: Configures the priority of when the floor is activated. The activate priority must be higher than the deactivate to allow access to the floor.
  * BS2_DeActivateFloor: Configures the priority of when the floor is deactivated. The deactivate priority must be higher than the activate to deny access to the floor.
  * BS2_GetFloorLevel: Retrieves selected floor levels.
  * BS2_GetAllFloorLevel: Retrieves all floor levels.
  * BS2_SetFloorLevel: Configures a floor level.
  * BS2_RemoveFloorLevel: Removes selected floor levels.
  * BS2_RemoveAllFloorLevel: Removes all floor levels.
* Slave Control API: API that connects the master and slave device by using the RS-485 network. The v2 devices will now work as a dummy reader when set as a slave device. It will not store any kind of information for user and all will be stored inside the master device. The slave device will send the information scanned, and the matching and access rule check will be done from the master device. The slave device will only receive the result.
  * BS2_GetSlaveDevice: Searches a slave device from the RS-485 network.
  * BS2_SetSlaveDevice: Add/Modify/Delete a slave device from the master device.
  * BS2_GetSlaveExDevice: In case of CoreStation, searches a slave device from the RS-485 network.
  * BS2_SetSlaveExDevice: In case of CoreStation, Add/Modify/Delete a slave device from the master device.
  * BS2_SearchDevicesCoreStation:​ Searches CoreStation devices from the current network.
  * BS2_SearchDevicesCoreStationEx:​ [+ 2.6.3] Searches CoreStation devices from the current network with host IP.
  * BS2_GetDevicesCoreStation:​ Gets searched CoreStation devices.
  * BS2_AddOsdpStandardDevice: [+ 2.9.1] Add the OSDP device.
  * BS2_GetOsdpStandardDevice: [+ 2.9.1] Gets OSDP device information.
  * BS2_GetAvailableOsdpStandardDevice: [+ 2.9.1] Gets all OSDP device information of the specified master device.
  * BS2_UpdateOsdpStandardDevice: [+ 2.9.1] Updates OSDP device information.
  * BS2_RemoveOsdpStandardDevice: [+ 2.9.1] Remove the OSDP device.
  * BS2_GetOsdpStandardDeviceCapability: [+ 2.9.1] Gets OSDP device support information.
  * BS2_SetOsdpStandardDeviceSecurityKey: [+ 2.9.1] Set the security key for the OSDP device.
  * BS2_SetSlaveBaudrate: [+ 2.9.8] Set the RS-485 baud rate of a slave device connected to a master device.
* Wiegand API: API that composes the Wiegand card readers and configures the Wiegand input/output.
  * BS2_SearchWiegandDevices: Searches Wiegand card readers.
  * BS2_GetWiegandDevices: Retrieves the Wiegand card readers being used.
  * BS2_AddWiegandDevices: Adds Wiegand card readers.
  * BS2_RemoveWiegandDevices: Removes Wiegand card readers.
* Server API: API that can enable server matching or controls the device from the BioStar application.
  * BS2_SetServerMatchingHandler: Registers the server matching handler.
  * BS2_VerifyUser: Transfers user information mapped to the card or user ID authentication results to the device.
  * BS2_IdentifyUser: Transfers user information mapped to the fingerprint authentication results to the device.
  * BS2_VerifyUserEx: [+ 2.4.0] Transfers user information mapped to the card or user ID authentication results to the device.
  * BS2_IdentifyUserEx: [+ 2.4.0] Transfers user information mapped to the fingerprint authentication results to the device.
  * BS2_VerifyUserSmall: [+ 2.6.3] Transfers user information mapped to the card or user ID authentication results to the device.
  * BS2_IdentifyUserSmall: [+ 2.6.3] Transfers user information mapped to the fingerprint authentication results to the device.
  * BS2_VerifyUserSmallEx: [+ 2.6.3] Transfers user information mapped to the card or user ID authentication results to the device.
  * BS2_IdentifyUserSmallEx: [+ 2.6.3] Transfers user information mapped to the fingerprint authentication results to the device.
  * BS2_VerifyUserFaceEx: [+ 2.7.2] Transfers user information mapped to the card or user ID authentication results to the device.
  * BS2_SetUserPhraseHandler:​ [+ 2.7.0] Registers the server user phrase handler.
  * BS2_ResponseUserPhrase:​ [+ 2.7.0] Transfers the user phrase to the device.
  * BS2_SetBarcodeScanListener: [+2.8.2] Register the listener function that detects barcode input.
  * BS2_SetOsdpStandardDeviceStatusListener: [+ 2.9.1] Register a listener function that detects state changes of the OSDP device.
* Zone Control API: API that configures the zone, which can control the entry device and door's operations. This feature will allow to divide one managing area into several zones for access control
  * Anti Passback Zone: To prevent the situation where a user lends it's card to someone else or to use it's fingerprint to enter someone else, an Anti Passback zone can be used. This zone has two options(soft, hard). When selecting soft, it will allow a user to enter even though the Anti Passback rule has been violated, but will leave a log of violation. When selecting hard, it does not allow any kind of Anti Passback violation and will leave a log of violation.
    * BS2_GetAntiPassbackZone: Retrieves selected Anti Passback zones.
    * BS2_GetAllAntiPassbackZone: Retrieves all Anti Passback zones.
    * BS2_GetAntiPassbackZoneStatus: Retrieves the status of selected Anti Passback zones.
    * BS2_GetAllAntiPassbackZoneStatus: Retrieves the status of all Anti Passback zones.
    * BS2_SetAntiPassbackZone: Configures an Anti Passback zone.
    * BS2_SetAntiPassbackZoneAlarm: Configures the alarm status of the Anti Passback zone.
    * BS2_RemoveAntiPassbackZone: Removes selected Anti Passback zones.
    * BS2_RemoveAllAntiPassbackZone: Removes all Anti Passback zones.
    * BS2_ClearAntiPassbackZoneStatus: Updates selected users to be not violating against the Anti Passback zone rule.
    * BS2_ClearAllAntiPassbackZoneStatus: Updates all users to be not violating against the Anti Passback zone rule.
    * BS2_SetCheckGlobalAPBViolationHandler:​ Registers callback function for global determination when an APB violation alarm occurs.
    * BS2_CheckGlobalAPBViolation:​ Transfers Global APB results to the device.
    * BS2_SetGlobalAPBViolationByDoorOpenHandler: [+ 2.7.0] Registers callback function for global determination when an APB violation by door alarm occurs.
    * BS2_CheckGlobalAPBViolationByDoorOpen: [+ 2.7.0] Transfers Global APB by door open results to the device.
  * Timed Anti Passback Zone: To prevent a user from re-entering in a certain time, a Timed Anti Passback zone can be used. This zone offers two options(soft, hard) as same as the Anti Passback zone.
    * BS2_GetTimedAntiPassbackZone: Retrieves selected timed Anti Passback zones.
    * BS2_GetAllTimedAntiPassbackZone: Retrieves all timed Anti Passback zones.
    * BS2_GetTimedAntiPassbackZoneStatus: Retrieves the status of the selected timed Anti Passback zones.
    * BS2_GetAllTimedAntiPassbackZoneStatus: Retrieves the status of all timed Anti Passback zones.
    * BS2_SetTimedAntiPassbackZone: Configures a timed Anti Passback zone.
    * BS2_SetTimedAntiPassbackZoneAlarm: Configures the alarm status of the timed Anti Passback zone.
    * BS2_RemoveTimedAntiPassbackZone: Removes selected timed Anti Passback zones.
    * BS2_RemoveAllTimedAntiPassbackZone: Removes all timed Anti Passback zones.
    * BS2_ClearTimedAntiPassbackZoneStatus: Updates selected users to be not violating against the timed Anti Passback zone rule.
    * BS2_ClearAllTimedAntiPassbackZoneStatus: Updates all users to be not violating against the timed Anti Passback zone rule.
  * Fire Alarm Zone: To detect fire and contorl the alarm for the access control area, a Fire alarm zone can be used. When an output signal gets sent to the BioStar system, the BioStar will automatically unlock all doors and activates the predefined alarms.
    * BS2_GetFireAlarmZone: Retrieves selected Fire Alarm zones.
    * BS2_GetAllFireAlarmZone: Retrieves all Fire Alarm zones.
    * BS2_GetFireAlarmZoneStatus: Retrieves the status of selected Fire Alarm zones.
    * BS2_GetAllFireAlarmZoneStatus: Retrieves the status of all Fire Alarm zones.
    * BS2_SetFireAlarmZone: Configures a Fire Alarm zone.
    * BS2_SetFireAlarmZoneAlarm: Configures the alarm status of the Fire Alarm zone.
    * BS2_RemoveFireAlarmZone: Removes selected Fire Alarm zones.
    * BS2_RemoveAllFireAlarmZone: Removes all Fire Alarm zones.
  * Scheduled Lock/Unlock Zone: To lock or unlock an area based on time, a Scheduled Lock/Unlock zone can be used. This zone will operate exclusively as a status of unlocking every doors in the area at a certain time, or locking every doors in the area at a certain time.
    * BS2_GetScheduledLockUnlockZone: Retrieves selected Scheduled Lock/Unlock zones.
    * BS2_GetAllScheduledLockUnlockZone: Retrieves all Scheduled Lock/Unlock zones.
    * BS2_GetScheduledLockUnlockZoneStatus: Retrieves the status of selected Scheduled Lock/Unlock zones.
    * BS2_GetAllScheduledLockUnlockZoneStatus: Retrieves the status of all Scheduled Lock/Unlock zones.
    * BS2_SetScheduledLockUnlockZone: Configures a Scheduled Lock/Unlock zone.
    * BS2_SetScheduledLockUnlockZoneAlarm: Configures the alarm status of the Scheduled Lock/Unlock zone.
    * BS2_RemoveScheduledLockUnlockZone: Removes selected Scheduled Lock/Unlock zones.
    * BS2_RemoveAllScheduledLockUnlockZone: Removes all Scheduled Lock/Unlock zones.
  * Intrusion Alarm Zone: It can be used to deal with crisis as receiving signal when intrusion is detected in intrusion zone. BioStar automatically raise pre-defined alarms when output signal is transmitted to BioStar system.
    * BS2_GetIntrusionAlarmZone: Retrieves selected Intrusion Alarm zones.
    * BS2_GetIntrusionAlarmZoneStatus: Retrieves the status of selected Intrusion Alarm zones.
    * BS2_GetAllIntrusionAlarmZoneStatus: Retrieves the status of all Intrusion Alarm zones.
    * BS2_SetIntrusionAlarmZone: Configures an Intrusion Alarm zone.
    * BS2_SetIntrusionAlarmZoneAlarm: Updates Intrusion alarm zone alarm status.
    * BS2_RemoveIntrusionAlarmZone: Removes selected Intrusion Alarm zones.
    * BS2_RemoveAllIntrusionAlarmZone: Removes all Intrusion Alarm zones.
  * Interlock Zone: [CoreStation] In case of dual door configuration, it is used when the opposite side must be closed before passing through the other door. Currently this feature is only supported in CoreStation.
    * BS2_GetInterlockZone: Gets selected Interlock zones.
    * BS2_GetInterlockZoneStatus: Gets selected Interlock zone status.
    * BS2_GetAllInterlockZoneStatus: Gets all Interlock zone's status information.
    * BS2_SetInterlockZone: Sets Interlock Zones.
    * BS2_SetInterlockZoneAlarm: Updates the alarm status in the Interlock zone.
    * BS2_RemoveInterlockZone: Removes the selected Interlock zone.
    * BS2_RemoveAllInterlockZone: Removes all Interlock zones.
  * Ethernet Zone: Not BioStar V2.x server, but specific device acts as Zone Master. Ethernet zone uses Ethernet TCP protocol between devices(Master ↔ Members). Currently, it only supports corresponding features to existing 1.x Entrance Limit, Fire Alarm Zone. It is supported on A2(FW 1.4.0 or higher), BS2(FW 1.5.0 or higher), FS2(FW 1.1.0 or higher), FL(FW 1.0.0 or higher) and P2(FW 1.0.0 or higher).
    * BS2_GetDeviceZone: Retrieves selected Ethernet zones..
    * BS2_GetAllDeviceZone: Retrieves all Ethernet zones.
    * BS2_SetDeviceZone: Configures a Ethernet zone.
    * BS2_RemoveDeviceZone: Removes selected Ethernet zones.
    * BS2_RemoveAllDeviceZone: Removes all Ethernet zones.
    * BS2_SetDeviceZoneAlarm: Configures the alarm status of the Ethernet zone.
    * BS2_ClearDeviceZoneAccessRecord: Updates selected users to be not violating against the Ethernet zone rule.
    * BS2_ClearAllDeviceZoneAccessRecord: Updates all users to be not violating against the Ethernet rule.
    * BS2_GetDeviceZoneAGEntranceLimit: Retrieves selected Ethernet Access Group Entrance limit.
    * BS2_GetAllDeviceZoneAGEntranceLimit: Retrieves all Ethernet Access Group Entrance limit.
    * BS2_SetDeviceZoneAGEntranceLimit: Configures Ethernet access group entrance limit.
    * BS2_RemoveDeviceZoneAGEntranceLimit: Removes selected Ethernet access group entrance limit.
    * BS2_RemoveAllDeviceZoneAGEntranceLimit: Removes all Ethernet access group entrance limit.
    * BS2_GetDeviceZoneMasterConfig: Retrieves the zone master config of the Ethernet zone.
    * BS2_SetDeviceZoneMasterConfig: Configures the zone master config of the Ethernet zone.
    * BS2_RemoveDeviceZoneMasterConfig: Removes the zone master config of the Ethernet zone.
  * Lift Lock/Unlock Zone: [+ 2.7.0] To control the elevator floor regardless of access groups but only based on schedules, Lift lock/unlock zone can be used.
    * BS2_GetLiftLockUnlockZone: Retrieves selected Lift Lock/Unlock zones.
    * BS2_GetAllLiftLockUnlockZone: Retrieves all Lift Lock/Unlock zones.
    * BS2_GetLiftLockUnlockZoneStatus: Retrieves the status of selected Lift Lock/Unlock zones.
    * BS2_GetAllLiftLockUnlockZoneStatus: Retrieves the status of all Lift Lock/Unlock zones.
    * BS2_SetLiftLockUnlockZone: Configures a Lift Lock/Unlock zone.
    * BS2_SetLiftLockUnlockZoneAlarm: Configures the alarm status of the Lift Lock/Unlock zone.
    * BS2_RemoveLiftLockUnlockZone: Removes selected Lift Lock/Unlock zones.
    * BS2_RemoveAllLiftLockUnlockZone: Removes all Lift Lock/Unlock zones.
* USB Exported Control API: This API allows to control/manage USB Exported.
  * BS2_AllocateUsbContext: [Depredated]Allocates context which manages & controls USB device.
  * BS2_ReleaseUsbContext: [Depredated]Releases context which manages & controls USB device.
  * BS2_GetUserDatabaseInfoFromDir: Gets total user information(Number of user/card/fingerprint/face) from USB exported data.
  * BS2_GetUserListFromDir: Gets the enrolled user ID list from USB exported data.
  * BS2_GetUserInfosFromDir: Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserDatasFromDir: Gets the user information of the given user ID & usermask from USB exported data.
  * BS2_GetUserInfosExFromDir: Gets the user information of the given user ID from USB exported data. (Including Job, phrase)
  * BS2_GetUserDatasExFromDir: Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)
  * BS2_GetUserSmallInfosFromDir: [+ 2.6.3] Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserSmallDatasFromDir: [+ 2.6.3] Gets the user information of the given user ID & usermask from USB exported data.
  * BS2_GetUserSmallInfosExFromDir: [+ 2.6.3] Gets the user information of the given user ID from USB exported data. (Including Job, phrase)
  * BS2_GetUserSmallDatasExFromDir: [+ 2.6.3] Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)
  * BS2_GetLogFromDir: Gets certain amount of logs from USB exported data.
  * BS2_GetLogBlobFromDir: Gets certain amount of logs based on the event mask from USB exported data.
  * BS2_GetFilteredLogFromDir: Gets filtered logs from USB exported data.
  * BS2_GetLogSmallBlobFromDir: [+ 2.6.4] Gets certain amount of logs based on the event mask from USB exported data in an efficient way.
  * BS2_GetLogSmallBlobExFromDir: [+ 2.7.1] Gets certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way.
  * BS2_GetUserInfosFaceExFromDir: [+2.7.1] Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserDatasFaceExFromDir: [+2.7.1] Gets the user information of the given user ID & usermask from USB exported data.

  [+2.8.2] API for managing USB Exported. Key user-related sensitive information is stored encrypted with predefined key values within the device. If you have changed the user information encryption key of the device using the BS2_SetDataEncryptKey function, you must pass the value of the key to use the USB-related API.

  * BS2_GetUserDatabaseInfoFromDirWithKey: [+2.8.2] Gets total user information(Number of user/card/fingerprint/face) from USB exported data.
  * BS2_GetUserListFromDirWithKey: [+2.8.2] Gets the enrolled user ID list from USB exported data.
  * BS2_GetUserInfosFromDirWithKey: [+2.8.2] Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserDatasFromDirWithKey: [+2.8.2] Gets the user information of the given user ID & usermask from USB exported data.
  * BS2_GetUserInfosExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID from USB exported data. (Including Job, phrase)
  * BS2_GetUserDatasExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)
  * BS2_GetUserSmallInfosFromDirWithKey: [+2.8.2] Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserSmallDatasFromDirWithKey: [+2.8.2] Gets the user information of the given user ID & usermask from USB exported data.
  * BS2_GetUserSmallInfosExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID from USB exported data. (Including Job, phrase)
  * BS2_GetUserSmallDatasExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)
  * BS2_GetLogFromDirWithKey: [+2.8.2] Gets certain amount of logs from USB exported data.
  * BS2_GetLogBlobFromDirWithKey: [+2.8.2] Gets certain amount of logs based on the event mask from USB exported data.
  * BS2_GetFilteredLogFromDirWithKey: [+2.8.2] Gets filtered logs from USB exported data.
  * BS2_GetLogSmallBlobFromDirWithKey: [+2.8.2] Gets certain amount of logs based on the event mask from USB exported data in an efficient way.
  * BS2_GetLogSmallBlobExFromDirWithKey: [+2.8.2] Gets certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way.
  * BS2_GetUserInfosFaceExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID from USB exported data.
  * BS2_GetUserDatasFaceExFromDirWithKey: [+2.8.2] Gets the user information of the given user ID & usermask from USB exported data.


## HTML 출력 폴더 구조

```text
output/
├── index.html       ← 영어 (루트)
├── group__...html
└── ko/              ← 한국어 서브디렉토리
    └── index.html
```

### Doxyfile 출력 경로 설정

```ini
# 영어 Doxyfile (biostar_device_sdk_en)
OUTPUT_DIRECTORY = .
HTML_OUTPUT      = output

# 한국어 Doxyfile (biostar_device_sdk_ko)
OUTPUT_DIRECTORY = output
HTML_OUTPUT      = ko
```

### 언어 전환 버튼 (JavaScript)

`assets/lang_switch.js` 파일을 만들고 두 Doxyfile에 모두 등록:

```javascript
(function () {
    var path = window.location.pathname;
    var isKorean = path.indexOf('/ko/') !== -1;

    var targetPath, label;
    if (isKorean) {
        // 한국어 → 영어: /ko/ 제거
        targetPath = path.replace('/ko/', '/');
        label = 'English';
    } else {
        // 영어 → 한국어: 파일명 앞에 /ko 삽입
        var lastSlash = path.lastIndexOf('/');
        targetPath = path.substring(0, lastSlash) + '/ko' + path.substring(lastSlash);
        label = '한국어';
    }

    var btn = document.createElement('a');
    btn.href = targetPath;
    btn.textContent = label;
    btn.style.cssText = 'position:fixed;top:10px;right:10px;padding:4px 10px;'
                      + 'background:#0a73bf;color:#fff;border-radius:4px;'
                      + 'font-size:13px;text-decoration:none;z-index:9999;';
    document.body.appendChild(btn);
})();
```

두 Doxyfile에 추가:

```ini
HTML_EXTRA_FILES       = docs/lang_switch.js
HTML_EXTRA_JAVASCRIPT  = lang_switch.js
```
