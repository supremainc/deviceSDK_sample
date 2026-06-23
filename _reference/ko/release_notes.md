# 릴리즈 노트

# 2.9.12 버전 (v2.9.12.0)

## 날짜

2026-1-30

## 새로운 기능

- XPass Q2 (XPQ2-DB, XPQ2-APB) 연결 지원

- BioStation 3 Max (BS3M-DB, BS3M-APB, BS3M-ODB, BS3M-OAPB) 연결 지원

- 마스터 관리자(Master Admin) 설정 기능 추가

- 출입문 긴급 개방(Lock Override) 기능 추가

- 시간 제한 출입문 잠금/개방(Door Mode Override) 기능 추가

- 연장된 출입문 개방시간(User Override) 기능 추가

- 처리 시간이 긴 API의 응답 대기 시간(Response Timeout) 설정 기능 추가

1. 신규 장치의 연결을 지원합니다.

* XPass Q2 (XPQ2-DB, XPQ2-APB)

- BioStation 3 Max (BS3M-DB, BS3M-APB, BS3M-ODB, BS3M-OAPB)

1. 장치에 마스터 관리자(Master Admin)를 설정하는 기능이 추가되었습니다.

   지원 장치 및 펌웨어 버전 정보는 아래 링크된 함수 설명을 참조하세요.

- 함수 [BS2_GetMasterAdmin](bs2_getmasteradmin) 추가

- 함수 [BS2_SetMasterAdmin](bs2_setmasteradmin) 추가

- 구조체 [BS2SystemConfig](configuration_api#bs2systemconfig) 참조

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 출입문 긴급 개방(Lock Override) 기능이 추가되었습니다.

   Lock Override를 통해 등록된 카드는 출입문의 잠금 상태를 무시하고 출입문을 개방할 수 있습니다.

- 함수 [BS2_GetLockOverride](bs2_getlockoverride) 추가

- 함수 [BS2_GetAllLockOverride](bs2_getalllockoverride) 추가

- 함수 [BS2_SetLockOverride](bs2_setlockoverride) 추가

- 함수 [BS2_RemoveLockOverride](bs2_removelockoverride) 추가

- 함수 [BS2_RemoveAllLockOverride](bs2_removealllockoverride) 추가

- 구조체 [BS2LockOverride](smartcard_api#bs2lockoverride) 추가

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 시간 제한 출입문 잠금/개방(Door Mode Override) 기능이 추가되었습니다.

- 함수 [BS2_TimedLockDoor](bs2_timedlockdoor) 추가

- 함수 [BS2_TimedUnlockDoor](bs2_timedunlockdoor) 추가

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 연장된 출입문 개방시간(User Override) 기능이 추가되었습니다.

- 함수 [BS2_GetUserOverride](bs2_getuseroverride) 추가

- 함수 [BS2_GetAllUserOverride](bs2_getalluseroverride) 추가

- 함수 [BS2_SetUserOverride](bs2_setuseroverride) 추가

- 함수 [BS2_RemoveUserOverride](bs2_removeuseroverride) 추가

- 함수 [BS2_RemoveAllUserOverride](bs2_removealluseroverride) 추가

- 구조체 [BS2Door](door_control_api#bs2door) 참조

- 구조체 [BS2UserOverride](user_management_api#bs2useroverride) 추가

1. 장치의 현재 입출력(I/O) 포트 상태 정보를 가져오는 기능이 추가되었습니다.

- 함수 [BS2_GetDeviceIOStatus](bs2_getdeviceiostatus) 추가

- 함수 [BS2_GetAllDeviceIOStatus](bs2_getalldeviceiostatus) 추가

- 구조체 [BS2IOStatus](Log_Management_API#bs2iostatus) 추가

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 처리 시간이 긴 일부 API의 응답 대기 시간을 사용자가 직접 설정할 수 있도록 개선되었습니다.

* 함수 [BS2_SetDefaultLongResponseTimeout](bs2_setdefaultlongresponsetimeout) 추가

- 함수 [BS2_GetDefaultLongResponseTimeout](bs2_getdefaultlongresponsetimeout) 추가

## 수정 기능

1. [BS2_RunAction](bs2_runaction) 함수를 이용한 슬레이브 장치 제어가 제한됩니다.

   단, DI-24와 같은 슬레이브 패널(Slave Panel)에 대해서는 정상적으로 동작합니다.

1. SDK 내부 타이머 매니저(Timer Manager) 모듈에서 충돌이 발생할 수 있는 문제가 수정되었습니다. (2.9.6.1 버전 해당)

1. SDK 코드 안정성 향상을 위한 내부 로직이 개선되었습니다.


---

# 2.9.9 버전 (v2.9.9.0)

## 날짜

2025-6-13

## 새로운 기능

- Mifare Plus 카드 AES128/Crypto1 암호화 방식 선택 기능 지원

- 신규 장치 CoreStation 20(CS-20, CS-20P), Door Interface(DI-24) 지원

1. Mifare Plus 카드의 AES128/Crypto1 암호화 방식을 선택할 수 있도록 변경되었습니다.

* 현재 XPass 2 v1.4.3, XPass D2 v1.8.2만 지원합니다.

- 구조체 [BS2CardConfig](configuration_api#bs2cardconfig) 참조

- 구조체 [BS2CustomCardConfig](configuration_api#bs2customcardconfig) 참조

- 구조체 [BS2MifareCardConfigEx](configuration_api#bs2mifarecardconfigex) 참조

1. 신규 장치의 연결을 지원합니다.

- CoreStation 20(CS-20, CS-20P)

- Door Interface(DI-24)

- 구조체 [BS2InputConfigEx](configuration_api#bs2inputconfigex) 참조

- 구조체 [BS2Rs485ConfigEXDynamic](configuration_api#bs2rs485configexdynamic) 참조

  - 함수 [bs2_getrs485configexdynamic](bs2_getrs485configexdynamic), [BS2_SetRS485ConfigExDynamic](bs2_setrs485configexdynamic) 추가

- 구조체 [BS2FacilityCodeConfig](configuration_api#bs2facilitycodeconfig) 참조

  - 함수 [BS2_GetFacilityCodeConfig](bs2_getfacilitycodeconfig), [BS2_SetFacilityCodeConfig](bs2_setfacilitycodeconfig) 추가

- 구조체 [BS2Rs485ConfigEXDynamic](configuration_api#bs2rs485configexdynamic) 참조

==== 수정 기능 ==== \1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.

1. 카드 샘플소스 중 SCC 스마트 카드의 Card ID 처리 방식이 개선되었습니다.


---

# 2.9.8 버전 (v2.9.8.0)

## 날짜

2024-9-30

## 새로운 기능

- 장치 인증 결과에 사용자 ID, 이름이 표시되는 방법을 선택할 수 있는 기능 지원

- BioStation 3에서 IP 인터폰의 SIP 전송 방법을 선택할 수 있는 기능 지원

- BioStation 3에서 IP 인터폰, RTSP 사용 시 영상 해상도를 선택할 수 있는 기능 지원

- 마스크를 착용한 사용자는 인증을 거부하도록 설정할 수 있는 옵션 추가

- X-Station 2에서 PIN을 입력할 때 숫자 키의 위치가 무작위로 변경되는 스크램블 키패드를 활성화하거나 비활성화할 수 있는 옵션 추가

- 슬레이브 장치의 RS-485 전송 속도를 설정할 수 있는 기능 추가

- CoreStation의 Aux Input 설정 기능 추가

1. 장치의 화면에 표시되는 인증 결과 메시지에서 ID 또는 이름의 표시 방법을 변경할 수 있도록 설정이 추가되었습니다.

* 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) - authMsgUserName, authMsgUserID 참조

1. BioStation 3의 IP 인터폰에서 데이터 전송 방법을 UDP, TCP, TLS로 변경할 수 있도록 설정이 추가되었습니다.

- 구조체 [BS2VoipConfigExt](configuration_api#bs2voipconfigext) - transport 참조 (지원장치: BioStation 3)

1. BioStation 3의 IP 인터폰과 RTSP 사용 시 송출되는 영상 해상도를 선택할 수 있도록 설정이 추가되었습니다.

- 구조체 [BS2VoipConfigExt](configuration_api#bs2voipconfigext) - resolution 참조 (지원장치: BioStation 3)

- 구조체 [BS2RtspConfig](configuration_api#bs2rtspconfig) - resolution 참조 (지원장치: BioStation 3, BioEntry W3)

1. 얼굴 인증 시 마스크를 착용한 사용자는 인증을 거부하도록 설정할 수 있는 옵션이 추가되었습니다. 이 기능은 BioStation 3, FaceStation F2, BioEntry W3 등의 비주얼 페이스를 기반으로 하는 얼굴 인증 장치에만 해당됩니다.

* 구조체 [BS2FaceConfigExt](configuration_api#bs2faceconfigext) - maskCheckMode 참조

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) - authDenyMaskSupported 참조

1. X-Station 2에서 PIN을 입력할 때 숫자 키의 위치가 무작위로 변경되는 스크램블 키패드를 설정할 수 있도록 추가되었습니다.

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) - scrambleKeyboardMode 참조

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) - scrambleKeyboardModeSupported 참조

1. 슬레이브 장치의 RS-485 전송 속도를 설정할 수 있는 기능이 추가되었습니다.

- 함수 [bs2_setslavebaudrate](bs2_setslavebaudrate) 추가

1. CoreStation40의 Aux Input 설정 기능이 추가되었습니다.

- 구조체 [BS2InputConfig](configuration_api#bs2inputconfig) - aux 참조

==== 수정 기능 ==== \1. C++(x64) 디버그 모드에서 BS2_ReleaseContext() 수행 시 발생하는 메모리 오류가 수정되었습니다.

1. BS2_SetAutoConnection을 사용하여 재연결을 하는 경우, 실시간 로그를 받을 수 없는 문제가 수정되었습니다.

1. so Linux Library 파일 헤더에 SONAME이 적용되었습니다.

1. BS2_RS485Config, BS2_RS485ConfigEx 구조체의 사용되지 않는 mode의 값 중에서 'Not use'가 제거되었습니다.

1. C# 샘플소스 개선

* ConfigControl 예제에서 getDeviceCapabilities() 수행 시 슬레이브 장치를 선택할 수 있도록 개선되었습니다.

- UserControl 예제에서 imagedata 메모리해제 누락이 개선되었습니다.

- SlaveControl 예제에서 wiegandDeviceID 변환 방법이 개선되었습니다.


---

# 2.9.6 버전 (V2.9.6.0)

## 날짜

2024-02-05

## 새로운 기능

- BioEntry W3 연결 지원 (BEW3-DB, BEW3-APB)

- XPass 2 지원 모델 추가 (XP2-MAPB)

- 얼굴 정보 저장 시 템플릿만 저장하도록 지원

- 타사 컨트롤러와 wiegand 연동 사용 시, 동일한 입력 신호가 반복적으로 입력되는 것을 무시하는 기능 추가

- 슈프리마 장치에서 타사 컨트롤러의 인증 성공/실패 결과를 받아서 표시하도록 지원

- 네트워크를 선택해서 초기화할 수 있는 함수 추가

1. 신규 장치의 연결을 지원합니다.

* BioEntry W3 (BEW3-DB, BEW3-APB)

- XPass 2 (XP2-MAPB)

1. 장치가 얼굴 정보를 저장할 때 템플릿만 저장할 수 있도록 하는 설정이 추가되었습니다.

   개인정보 보호가 좀 더 중요시되는 현장에서 유용합니다.

   이 기능은 BioStation 3, FaceStation F2, BioEntry W3 등의 visual face를 기반으로하는 얼굴 인증 장치에만 해당됩니다.

- 구조체 [BS2FaceConfig](configuration_api#bs2faceconfig) 참조

- 구조체 [BS2FaceEx](face_api#bs2faceex) 참조

1. 슈프리마 장치와 타사 컨트롤러를 wiegand로 연결하여 사용하는 환경에서,

   특정 모델의 컨트롤러로부터 슈프리마 장치로 인증에 대한 피드백이 반복적으로 입력되는 경우

   이를 무시하도록 지정할 수 있는 기능이 추가되었습니다.

- 구조체 [BS2Trigger](configuration_api#bs2trigger) 참조

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 슈프리마 장치가 타사 컨트롤러에 연결되어 사용되는 경우,

   컨트롤러에서 LED command와 같은 인증 결과를 화면에 표시할 수 있도록하는 기능이 추가되었습니다.

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) 참조

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 네트워크를 선택해서 초기화할 수 있는 함수가 추가되었습니다.

   복수의 네트워크에 연결되어 있는 경우, 특정 네트워크를 지정하여 초기화를 수행한 후 장치를 검색하면 해당 서브네트워크의 장치들을 검색 할 수 있습니다.

- 함수 [BS2_InitializeEx](bs2_initializeex) 추가

## 수정 기능

1. CoreStation 40에 face configuration을 가져오거나 설정할 때, BS_SDK_ERROR_NOT_SUPPORTED 오류를 반환하는 문제가 수정되었습니다.

- 함수 [BS2_GetFaceConfig](bs2_getfaceconfig) 참조

- 함수 [BS2_SetFaceConfig](bs2_setfaceconfig) 참조

- 구조체 [BS2FaceConfig](configuration_api#bs2faceconfig) 참조

1. 장치 로그 필터링 함수 [BS2_GetFilteredLog](bs2_getfilteredlog), [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid)가 `지원중단` 되었습니다.

   [BS2_GetLog](bs2_getlog)와 [BS2_StartMonitoringLog](bs2_startmonitoringlog)를 적절히 활용하여 서버에서 필터링하는 것을 권장합니다.

- 함수 [BS2_GetFilteredLog](bs2_getfilteredlog) 참조

- 함수 [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid) 참조

- 함수 [BS2_GetLog](bs2_getlog) 참조

- 함수 [BS2_StartMonitoringLog](bs2_startmonitoringlog) 참조

- 함수 [BS2_StopMonitoringLog](bs2_stopmonitoringlog) 참조

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.9.4 버전 (V2.9.4.0)

## 날짜

2023-08-08

## 새로운 기능

- BioStation 2a 연결 지원 (BS2A-ODPB, BS2A-OAPWB)

- Custom smart card 읽기 지원

1. 신규 장치 BioStation 2a의 연결을 지원합니다.

1. Custom smart card 읽기를 지원합니다.

- 구조체 [BS2CustomMifareCard](configuration_api#bs2custommifarecard) 참조

- 구조체 [BS2CustomDesFireCard](configuration_api#bs2customdesfirecard) 추가

- 구조체 [BS2CustomCardConfig](configuration_api#bs2customcardconfig) 추가

- 함수 [BS2_GetCustomCardConfig](bs2_getcustomcardconfig) 추가

- 함수 [BS2_SetCustomCardConfig](bs2_setcustomcardconfig) 추가

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

## 수정 기능

1. 지원 Linux 환경이 Ubuntu 22.04로 상향되었습니다.

   | SDK 버전 | 지원 Linux 버전 |
   | --- | --- |
   | V2.9.4 이전 | Ubuntu 18.04 |
   | V2.9.4 이후 | Ubuntu 22.04 |

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.9.1 버전 (V2.9.1.0)

## 날짜

2023-02-23

## 새로운 기능

- 장치에서 특정 기능 사용에 대한 라이선스 활성화 지원

- 카메라를 이용한 QR 코드 인식 및 인증 지원

- 소켓 읽기/쓰기 실패 시, 재시도 횟수 설정 기능 지원

- 타사 OSDP 리더 연결 지원

1. 장치 라이선스 활성화 기능이 추가되었습니다.

- 구조체 [BS2License](configuration_api#bs2license) 추가

- 구조체 [BS2LicenseConfig](configuration_api#bs2licenseconfig) 추가

- 구조체 [BS2LicenseBlob](sdk_api#bs2licenseblob) 추가

- 구조체 [BS2LicenseResult](sdk_api#bs2licenseresult) 추가

- 함수 [BS2_GetLicenseConfig](bs2_getlicenseconfig) 추가

- 함수 [BS2_EnableDeviceLicense](bs2_enabledevicelicense) 추가

- 함수 [BS2_DisableDeviceLicense](bs2_disabledevicelicense) 추가

- 함수 [BS2_QueryDeviceLicense](bs2_querydevicelicense) 추가

1. 카메라를 통해 QR코드의 인식 및 인증을 지원하는 기능이 추가되었습니다.

- 구조체 [BS2BarcodeConfig](configuration_api#bs2barcodeconfig) 참조

1. 통신 도중 소켓에서 패킷을 읽고 쓰는 중에 오류가 발생했을 때 사용되는 통신 재시도 횟수를 추가했습니다.

:::warning

**주의 사항**

재시도 횟수를 늘리는 것은 일시적인 오류를 해결할 수 있는 좋은 방법이지만, 네트워크 연결 끊김 등의 직접적인 원인이 발생하여 재연결이 필요할 때 무의미한 읽기/쓰기를 재시도하게 되면서 리소스 낭비가 발생할 수 있으므로 주의가 필요합니다.

:::

- 함수 [BS2_GetSocketRetryCount](bs2_getsocketretrycount) 추가

- 함수 [BS2_SetSocketRetryCount](bs2_setsocketretrycount) 추가

- 함수 [BS2_GetSocketSSLRetryCount](bs2_getsocketsslretrycount) 추가

- 함수 [BS2_SetSocketSSLRetryCount](bs2_setsocketsslretrycount) 추가

1. OSDP 표준의 3rd party 장치들을 연결 및 관리를 할 수 있도록 기능이 추가되었습니다.

- 구조체 [BS2OsdpStandardDevice](slave_control_api#bs2osdpstandarddevice) 추가

- 구조체 [BS2OsdpStandardDeviceAvailable](slave_control_api#bs2osdpstandarddeviceavailable) 추가

- 구조체 [BS2OsdpStandardNotify](slave_control_api#bs2osdpstandardnotify) 추가

- 구조체 [BS2OsdpStandardConfig](configuration_api#bs2osdpstandardconfig) 추가

- 구조체 [BS2OsdpStandardActionConfig](configuration_api#bs2osdpstandardactionconfig) 추가

- 구조체 [BS2OsdpStandardDeviceAdd](slave_control_api#bs2osdpstandarddeviceadd) 추가

- 구조체 [BS2OsdpStandardDeviceUpdate](slave_control_api#bs2osdpstandarddeviceupdate) 추가

- 구조체 [BS2OsdpStandardDeviceCapability](slave_control_api#bs2osdpstandarddevicecapability) 추가

- 구조체 [BS2OsdpStandardDeviceResult](slave_control_api#bs2osdpstandarddeviceresult) 추가

- 구조체 [BS2OsdpStandardDeviceSecurityKey](slave_control_api#bs2osdpstandarddevicesecuritykey) 추가

- 함수 [BS2_GetOsdpStandardConfig](bs2_getosdpstandardconfig) 추가

- 함수 [BS2_GetOsdpStandardActionConfig](bs2_getosdpstandardactionconfig) 추가

- 함수 [BS2_SetOsdpStandardActionConfig](bs2_setosdpstandardactionconfig) 추가

- 함수 [BS2_AddOsdpStandardDevice](bs2_addosdpstandarddevice) 추가

- 함수 [BS2_GetOsdpStandardDevice](bs2_getosdpstandarddevice) 추가

- 함수 [BS2_GetAvailableOsdpStandardDevice](bs2_getavailableosdpstandarddevice) 추가

- 함수 [BS2_UpdateOsdpStandardDevice](bs2_updateosdpstandarddevice) 추가

- 함수 [BS2_RemoveOsdpStandardDevice](bs2_removeosdpstandarddevice) 추가

- 함수 [BS2_GetOsdpStandardDeviceCapability](bs2_getosdpstandarddevicecapability) 추가

- 함수 [BS2_SetOsdpStandardDeviceSecurityKey](bs2_setosdpstandarddevicesecuritykey) 추가

- 함수 [BS2_SetOsdpStandardDeviceStatusListener](bs2_setosdpstandarddevicestatuslistener) 추가

- 콜백함수 [OnOsdpStandardDeviceStatusChanged](server_api#onosdpstandarddevicestatuschanged) 추가

## 수정 기능

1. 네트워크 switch에서 제공하는 keepalive check 기능처럼, 실제 장치 연결은 아니면서 연결 후 끊기가 반복되는 경우가 있습니다.

   이 경우 SDK에서 실제 장치 연결로 오인하고 이것이 메모리 누수로 이어질 수 있는 문제가 수정되었습니다.

1. `2.8.3.2 버전에서만` 발생하는 문제로, 사용자 등록 시 SDK 내부적으로 log dump를 수행하면서, 이 과정에서 비정상 종료로 이어질 수 있는 문제가 수정되었습니다.

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.8.3 버전 (V2.8.3.2)

## 날짜

2022-10-05

## 새로운 기능

- BioStation 3 연결 지원 (제품명: BS3-DB, BS3-APWB)

- 사용자 정보 부분 갱신 함수 추가

- 사용자 통계 정보 취득 기능 추가

- 파일 분할 저장이 가능한 디버깅용 파일로그 함수 추가

1. BioStation 3 연결 지원 및 관련 확장형 Voip 설정, RTSP 설정 기능이 추가되었습니다.

- 구조체 [BS2VoipConfigExt](configuration_api#bs2voipconfigext) 추가

- 함수 [BS2_GetVoipConfigExt](bs2_getvoipconfigext) 추가

- 함수 [BS2_SetVoipConfigExt](bs2_setvoipconfigext) 추가

- 구조체 [BS2RtspConfig](configuration_api#bs2rtspconfig) 추가

- 함수 [BS2_GetRtspConfig](bs2_getrtspconfig) 추가

- 함수 [BS2_SetRtspConfig](bs2_setrtspconfig) 추가

1. 사용자 정보를 부분적으로 갱신하는 함수가 추가되었습니다.

- 함수 [BS2_PartialUpdateUser](bs2_partialupdateuser) 추가

- 함수 [BS2_PartialUpdateUserEx](bs2_partialupdateuserex) 추가

- 함수 [BS2_PartialUpdateUserSmall](bs2_partialupdateusersmall) 추가

- 함수 [BS2_PartialUpdateUserSmallEx](bs2_partialupdateusersmallex) 추가

- 함수 [BS2_PartialUpdateUserFaceEx](bs2_partialupdateuserfaceex) 추가

1. 장치가 보유한 사용자 통계정보를 가져올 수 있도록 기능이 추가되었습니다.

- 구조체 [BS2UserStatistic](user_management_api#bs2userstatistic) 추가

- 함수 [BS2_GetUserStatistic](bs2_getuserstatistic) 추가

1. 디버깅용 파일로그 함수가 추가되었습니다. (파일분할 저장 지원)

- 함수 [BS2_SetDebugFileLogEx](bs2_setdebugfilelogex) 추가

## 수정 기능

1. 디버깅용 로그 파일 출력 시, 표시되는 시간 정보가 밀리 초까지 표시되도록 수정되었습니다.

- 함수 [BS2_SetDebugFileLog](bs2_setdebugfilelog) 참조

1. 얼굴 설정 방법이 변경됩니다.

   얼굴 검출 단계에서 얼굴 이미지 폭을 나타내는 faceWidth, 검색 범위를 나타내는 searchRange 등은 pixel 단위로 입력하며,

   이는 사용자가 설정하기 다소 난해한 입력 단위였습니다.

   이후 제공되는 detectDistance, wideSearch는 감지되는 얼굴까지의 거리를 cm로 입력하여, 보다 체감 가능한 설정 단위로 변경됩니다.

   SDK V2.8.3이 배포되는 시점 기준으로 `BioStation 3`만 거리 기반의 설정이 가능하며, 이후 `FaceStation F2`로 확대 적용 계획에 있습니다.

- 구조체 [BS2FaceConfig](configuration_api#bs2faceconfig) 참조

1. [BS2DeviceCapabilities](device_api#bs2devicecapabilities)에 다음의 지원 정보가 추가되었습니다. (사용자 업데이트 지원, Simulated unlock, RTSP, Visual QR 등)

* 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

1. 사용자 구조체에, 해당 사용자가 어떤 credential 정보를 가지고 있는지 나타내는 infoMask가 추가되었습니다.

   또한 infoMask의 mask 값을 수정 후 장치로 내려줌으로써, 해당 사용자가 가지고 있는 정보의 부분 변경/삭제가 가능하게 됩니다.

- 함수 [BS2User](user_management_api#bs2user) 참조

1. USB의 로그 취득 시, 시작 index, 요청 수량 등의 조건이 적용되지 않는 문제가 수정되었습니다.

   또한 취득된 로그 시간이 비정상적으로 큰 경우가 발생하는 문제를 수정하였습니다.

- 함수 [BS2_GetLogFromDir](bs2_getlogfromdir) 참조

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 참조

- 함수 [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) 참조

- 함수 [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir) 참조

- 함수 [BS2_GetLogFromDirWithKey](bs2_getlogfromdirwithkey) 참조

- 함수 [BS2_GetLogBlobFromDirWithKey](bs2_getlogblobfromdirwithkey) 참조

- 함수 [BS2_GetLogSmallBlobFromDirWithKey](bs2_getlogsmallblobfromdirwithkey) 참조

- 함수 [BS2_GetLogSmallBlobExFromDirWithKey](bs2_getlogsmallblobexfromdirwithkey) 참조

1. USB의 filtered log 이용 시, 날짜 검색이 정상적으로 되지 않는 문제 수정되었습니다.

- 함수 [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir) 참조

- 함수 [BS2_GetFilteredLogFromDirWithKey](bs2_getfilteredlogfromdirwithkey) 참조

1. C# 예제 내의 간단한 버그 등이 수정되었습니다.

1. 저속 네트워크 환경에서 SSL 사용에 대한 사용성이 개선되었습니다.

1. USB import 시 사용자에 access group이 존재하면 crash 되는 문제가 수정되었습니다.

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.8.2 버전 (V2.8.2.9)

## 날짜

2022-04-25

## 새로운 기능

- Ver.3를 지원하는 USB 파일 읽기 지원

- Barcode bypass 기능 추가

- Treat as CSN 기능 추가

- Smart card byte order 기능 추가

- 시스템 지원정보에 지원항목 추가

1. Ver.3를 지원하는(GDPR supported) 장치에서, USB 파일 읽기를 위해 아래의 함수들이 추가되었습니다.

   아래의 함수들은 과거에 [BS2_SetDataEncryptKey](bs2_setdataencryptkey) 함수를 호출하여 장치의 사용자 정보 암호화 키를 변경한 적이 있는 경우에 해당됩니다.

   새로 추가된 key 파라메터는 과거에 설정한 키를 지정하면 됩니다.

- 함수 [BS2_GetUserDatabaseInfoFromDirWithKey](bs2_getuserdatabaseinfofromdirwithkey) 추가

- 함수 [BS2_GetUserListFromDirWithKey](bs2_getuserlistfromdirwithkey) 추가

- 함수 [BS2_GetUserInfosFromDirWithKey](bs2_getuserinfosfromdirwithkey) 추가

- 함수 [BS2_GetUserDatasFromDirWithKey](bs2_getuserdatasfromdirwithkey) 추가

- 함수 [BS2_GetUserInfosExFromDirWithKey](bs2_getuserinfosexfromdirwithkey) 추가

- 함수 [BS2_GetUserDatasExFromDirWithKey](bs2_getuserdatasexfromdirwithkey) 추가

- 함수 [BS2_GetLogFromDirWithKey](bs2_getlogfromdirwithkey) 추가

- 함수 [BS2_GetFilteredLogFromDirWithKey](bs2_getfilteredlogfromdirwithkey) 추가

- 함수 [BS2_GetUserSmallInfosFromDirWithKey](bs2_getusersmallinfosfromdirwithkey) 추가

- 함수 [BS2_GetUserSmallDatasFromDirWithKey](bs2_getusersmalldatasfromdirwithkey) 추가

- 함수 [BS2_GetUserSmallInfosExFromDirWithKey](bs2_getusersmallinfosexfromdirwithkey) 추가

- 함수 [BS2_GetUserSmallDatasExFromDirWithKey](bs2_getusersmalldatasexfromdirwithkey) 추가

- 함수 [BS2_GetUserInfosFaceExFromDirWithKey](bs2_getuserinfosfaceexfromdirwithkey) 추가

- 함수 [BS2_GetUserDatasFaceExFromDirWithKey](bs2_getuserdatasfaceexfromdirwithkey) 추가

- 함수 [BS2_GetLogBlobFromDirWithKey](bs2_getlogblobfromdirwithkey) 추가

- 함수 [BS2_GetLogSmallBlobFromDirWithKey](bs2_getlogsmallblobfromdirwithkey) 추가

- 함수 [BS2_GetLogSmallBlobExFromDirWithKey](bs2_getlogsmallblobexfromdirwithkey) 추가

1. Barcode scan이 가능한 장치로부터 barcode를 구독할 수 있도록, barcode bypass 기능이 추가되었습니다.

- 구조체 [BS2BarcodeConfig](configuration_api#bs2barcodeconfig) 참조

- 함수 [BS2_SetBarcodeScanListener](bs2_setbarcodescanlistener) 추가

- 콜백함수 [OnBarcodeScanned](server_api#onbarcodescanned) 추가

1. Barcode를 일반 CSN 카드와 동일하게 취급할 수 있는 기능(Treat as CSN)이 추가되었습니다.

- 구조체 [BS2BarcodeConfig](configuration_api#bs2barcodeconfig) 참조

1. Smart card의 byte order를 지정할 수 있도록 수정되었습니다.

- 구조체 [BS2CardConfig](configuration_api#bs2cardconfig) 참조

- 함수 [BS2_GetCardConfig](bs2_getcardconfig) 참조

- 함수 [BS2_SetCardConfig](bs2_setcardconfig) 참조

1. Smart card byte order, Treat as CSN 기능에 대한, 시스템 지원 정보가 업데이트 되었습니다.

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

- 함수 [BS2_GetDeviceCapabilities](bs2_getdevicecapabilities) 참조

## 수정 기능

1. SDK에서 libxml2 library 종속성이 제거되었습니다.

1. USB 파일 읽기 함수가 Ver.3(GDPR supported)를 지원하도록 내부적으로 수정되었습니다.

   아래의 함수들은 과거에 [BS2_SetDataEncryptKey](bs2_setdataencryptkey) 함수를 호출하여 장치의 사용자 정보 암호화 키를 변경한 적이 없는 경우에 해당됩니다.

   아래의 함수들은 암호화 정보를 기본키값으로 복호화하여 가져옵니다.

   사용자는 이전과 동일하게 함수를 호출하면 됩니다.

- 함수 [BS2_GetUserDatabaseInfoFromDir](bs2_getuserdatabaseinfofromdir) 참조

- 함수 [BS2_GetUserListFromDir](bs2_getuserlistfromdir) 참조

- 함수 [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir) 참조

- 함수 [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir) 참조

- 함수 [BS2_GetUserInfosExFromDir](bs2_getuserinfosexfromdir) 참조

- 함수 [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir) 참조

- 함수 [BS2_GetLogFromDir](bs2_getlogfromdir) 참조

- 함수 [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir) 참조

- 함수 [BS2_GetUserSmallInfosFromDir](bs2_getusersmallinfosfromdir) 참조

- 함수 [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir) 참조

- 함수 [BS2_GetUserSmallInfosExFromDir](bs2_getusersmallinfosexfromdir) 참조

- 함수 [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir) 참조

- 함수 [BS2_GetUserInfosFaceExFromDir](bs2_getuserinfosfaceexfromdir) 참조

- 함수 [BS2_GetUserDatasFaceExFromDir](bs2_getuserdatasfaceexfromdir) 참조

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 참조

- 함수 [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) 참조

- 함수 [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir) 참조

1. USB를 연결하기 위한 아래의 두 API가 `지원중단` 되었습니다.

   이후로 context는 [BS2_AllocateContext](bs2_allocatecontext)를 호출하여 생성된 객체를 전달하여 사용하면 됩니다.

* 함수 [BS2_AllocateUsbContext](bs2_allocateusbcontext) 지원중단

- 함수 [BS2_ReleaseUsbContext](bs2_releaseusbcontext) 지원중단

- 함수 [BS2_AllocateContext](bs2_allocatecontext) 참조

- 함수 [BS2_ReleaseContext](bs2_releasecontext) 참조

1. SSL 연결 모드에서 단순 통신 오류 발생 시, 장치 연결이 끊기는 문제가 수정되었습니다.


---

# 2.8.2 버전 (V2.8.2.3)

## 날짜

2021-11-29

## 수정 기능

1. 지원 Linux 환경이 Ubuntu 18.04로 상향되었습니다.

   | SDK 버전 | 지원 Linux 버전 |
   | --- | --- |
   | V2.8.2 이전 | Ubuntu 16.04 |
   | V2.8.2 이후 | Ubuntu 18.04 |

1. OpenSSL이 기존 1.0.2n에서 1.1.1i를 지원하도록 수정되었습니다.

- 문서 [개발환경 구축하기](getting_started#개발_환경_구축하기) 참조

1. IPv6 운용 장치에서 [BS2_GetFactoryConfig](bs2_getfactoryconfig) 호출 시, BS_SDK_ERROR_SOCKET_IS_NOT_CONNECTED 오류가 발생될 수 있는 문제가 수정되었습니다.

1. FaceStation F2 장치로 Unwarped image 사용자를 대량으로 전송하면, BS_SDK_ERROR_TIMEOUT 오류가 발생될 수 있는 문제가 수정되었습니다.

1. V2.7.2.20 이후 버전에서 [BS2_SetDebugExCallback](bs2_setdebugexcallback) 함수가 동작되지 않는 문제가 수정되었습니다.

1. 지원 구성 정보 내역 중 FaceStation F2 장치와 관련하여 지원 항목으로 잘못 설정된 정보가 삭제되었습니다. (WLAN)

- 함수 [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask) 참조

1. 지원 구성 정보 내역 중 XStation 2 장치와 관련하여 지원 항목으로 잘못 설정된 정보가 삭제되었습니다. (VoIP)

- 함수 [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask) 참조

1. 지원 구성 정보 내역 중 BioEntry R2 장치와 관련하여 미지원 항목으로 잘못 설정된 정보가 추가되었습니다. (Wiegand)

- 함수 [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask) 참조

1. C# 예제에서 [BS2DisplayConfig](configuration_api#bs2displayconfig)의 reserved2 array의 첨자가 잘못 표기되어 있는 문제가 수정되었습니다. (useScreenSaver의 영향으로 1 감소)

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) 참조

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.8.1 버전 (V2.8.1.0)

## 날짜

2021-08-05

## 새로운 기능

- X-Station 2 Finger 연결 지원 (제품명: XS2-OAPB, XS2-ODPB)

- Input Module 연결 지원 (제품명: IM-120)

- 장치에 특정동작을 요구하는 기능 추가

1. X-Station 2 Finger 연결 지원 기능이 추가되었습니다.

1. Input Module 연결 지원 기능이 추가되었습니다.

- 구조체 [BS2InputConfigEx](configuration_api#bs2inputconfigex) 참조

- 구조체 [BS2RelayActionConfig](configuration_api#bs2relayactionconfig) 참조

- 구조체 [BS2Event](log_management_api#bs2event)의 **relayAction** 참조

- 함수 [BS2_GetInputConfigEx](bs2_getinputconfigex) 참조

- 함수 [BS2_SetInputConfigEx](bs2_setinputconfigex) 참조

- 함수 [BS2_GetRelayActionConfig](bs2_getrelayactionconfig) 참조

- 함수 [BS2_SetRelayActionConfig](bs2_setrelayactionconfig) 참조

1. 장치에 특정 동작을 직접 지시할 수 있습니다.

   이제 아래의 명령을 통해 LED를 켜거나, buzzer를 울릴 수 있고, relay 동작 등을 원하는 시점에 직접 제어할 수 있습니다.

- 구조체 [BS2Action](configuration_api#bs2action) 참조

- 함수 [BS2_RunAction](bs2_runaction) 참조

## 수정 기능

1. Linux에서 BS_SDK_ERROR_TIMEOUT 오류를 반환하며, 장치 연결이 되지 않을 수 있는 문제가 수정되었습니다.

1. 현재 서버매칭 기능 구현에 대한 도움을 제공하기 위하여 C# 예제가 제공되었으나, 이에대한 지원이 중단됩니다.

- 서버 API 문서 [server_api](server_api) 참조


---

# 2.8.0 버전 (V2.8.0.6)

## 날짜

2021-06-07

## 새로운 기능

- X-Station 2 연결 지원

- Intelligent Slave 기능 지원

- WARP 이미지 취득 기능 추가 (FaceStation F2)

- 장치 지원 정보 취득 기능 추가

- Mobile 카드 이벤트 추가

- 특정 장치의 새로운 카드모델 지원 정보 추가

1. X-Station 2 연결 지원 기능이 추가되었습니다.

- 구조체 [BS2BarcodeConfig](configuration_api#bs2barcodeconfig) 참조

- 함수 [BS2_GetBarcodeConfig](bs2_getbarcodeconfig) 참조

- 함수 [BS2_SetBarcodeConfig](bs2_setbarcodeconfig) 참조

- 함수 [BS2_WriteQRCode](bs2_writeqrcode) 참조

1. Intelligent Slave 기능이 지원됩니다.

   Intelligent Slave는 슈프리마 생체 인식 기기와 타사 컨트롤러가 연결된 환경에서 인증결과(카드 또는 사용자ID)를 ODSP로 전송하여줍니다.

   [Intelligent Slave Support](https://support.supremainc.com/en/support/solutions/articles/24000066085--biostar-2-intelligent-slave-support)

- 구조체 [BS2Rs485Config](configuration_api#bs2rs485config) 참조

- 함수 [BS2_GetRs485Config](bs2_getrs485config) 참조

- 함수 [BS2_SetRs485Config](bs2_setrs485config) 참조

1. WARP 되어지지 않은(가공되어지지 않은) 얼굴 이미지로, WARP 이미지를 취득하는 기능이 추가되었습니다.

- 함수 [BS2_GetNormalizedImageFaceEx](bs2_getnormalizedimagefaceex) 참조

1. 장치 지원 정보를 취득하는 기능이 추가되었습니다.

- 구조체 [BS2DeviceCapabilities](device_api#bs2devicecapabilities) 참조

- 함수 [BS2_GetDeviceCapabilities](bs2_getdevicecapabilities) 참조

1. Mobile 카드 이벤트가 추가되었습니다.

- 구조체 [BS2Event의 subCode](Log_Management_API#BS2Event) 참조

1. [BS2_GetCardModel](bs2_getcardmodel) 함수가 다음의 새로운 모델들을 지원할 수 있도록 추가되었습니다.

- 함수 [BS2_GetCardModel](bs2_getcardmodel) 참조

- BEW2-ODPB

- BEW2-OAPB

- BEW2-OHPB

## 수정 기능

1. `Master: CoreStation 40`, `Slave: FaceStation 2 / FaceLite`에서 FaceStation 2, FaceLite에 대한 얼굴 template을 사용자에 할당하고, CoreStation 40에 등록 시 BS_SDK_ERROR_TIMEOUT 오류가 반환되는 문제가 수정되었습니다.

- 함수 [BS2_EnrolUser](bs2_enroluser) 참조

- 함수 [BS2_EnrollUser](bs2_enrolluser) 참조

- 함수 [BS2_EnrolUserEx](bs2_enroluserex) 참조

- 함수 [BS2_EnrollUserEx](bs2_enrolluserex) 참조

- 함수 [BS2_EnrollUserSmall](bs2_enrollusersmall) 참조

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 참조

- 함수 [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex) 참조

1. 많은 사용자(700명 이상)의 장치 전송 시, V2.7.2.x 이전 버전에 비해 상대적으로 느려졌던 문제가 수정되었습니다.

- 함수 [BS2_EnrolUser](bs2_enroluser) 참조

- 함수 [BS2_EnrollUser](bs2_enrolluser) 참조

- 함수 [BS2_EnrolUserEx](bs2_enroluserex) 참조

- 함수 [BS2_EnrollUserEx](bs2_enrolluserex) 참조

- 함수 [BS2_EnrollUserSmall](bs2_enrollusersmall) 참조

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 참조

- 함수 [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex) 참조

1. Event config를 지원하지 않는 장치 FaceLite에 config를 요청하게되는 경우, 반환 값이 BS_SDK_SUCCESS에서 BS_SDK_ERROR_NOT_SUPPORTED로 수정되었습니다.

- 함수 [BS2_GetEventConfig](bs2_geteventconfig) 참조

1. SDK의 allocation과 release를 반복하면, 일정 횟수 초과 시 장치 연결이 불가능해지는 현상 수정되었습니다.

- 함수 [BS2_AllocateContext](bs2_allocatecontext) 참조

- 함수 [BS2_ReleaseContext](bs2_releasecontext) 참조

1. [BS2_ReleaseContext](bs2_releasecontext) 호출 시, 간헐적으로 정상적인 리소스 반납이 이루어지지 않으며, 51212, 51213 포트를 점유하고 있는 문제가 수정되었습니다.

1. 장치에대한 connect/cisconnect 호출을 반복하게 되면 event 처리과정에서 deadlock이 발생할 수 있는 문제가 수정되었습니다.

1. [BS2_ReleaseContext](bs2_releasecontext) 호출 시, 간헐적으로 응용프로그램이 crash 될 수 있는 문제가 수정되었습니다.

1. Display 설정 변경 시, timeout을 나타내는 필드들이 10의 배수로 할당되지 않으면, 장치가 reset될 수 있는 문제가 수정되었습니다.

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) menuTimeout, msgTimeout, backlightTimeout 참조

- 함수 [BS2_SetDisplayConfig](bs2_setdisplayconfig) 참조

1. 4 core 환경에서 [BS2_SearchDevices](bs2_searchdevices) 호출을 반복하면, CPU 점유율이 99%로 올라가는 문제가 수정되었습니다.

1. FaceStation F2의 white LED 설정 옵션에 사용안함(Not used)이 추가되었습니다.

1. `FaceStation F2 Only` [BS2FaceConfig](configuration_api#bs2faceconfig)의 lightCondition 멤버의 의미와 설정 값이 변경되었습니다.

   | 지원 버전 | 의미 | 0 | 1 | 2 | 3 |
   | --- | --- | --- | --- | --- | --- |
   | 1.0.0 \~ 1.0.5 | Ambient Brightness | Indoor | Outdoor | Auto | \- |
   | 1.1.0 이상 | Light Brightness | Normal | High | \- `(Deprecated)` | Not used |

- 구조체 [BS2FaceConfig](configuration_api#bs2faceconfig) lightCondition 참조


---

# 2.7.2 버전 (V2.7.2.12)

## 날짜

2020-12-11

## 새로운 기능

- Screensaver 활성화 기능 추가 (FaceStation 2, FaceStation F2)

- FaceStation F2의 서버 매칭 지원 (카드 만)

1. Screensaver 활성화 기능이 추가되었습니다. FaceStation 2, FaceStation F2 장치만 적용됩니다.

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) 참조

- 함수 [BS2_GetDisplayConfig](bs2_getdisplayconfig) 참조

- 함수 [BS2_SetDisplayConfig](bs2_setdisplayconfig) 참조

1. FaceStation F2의 서버 매칭을 지원합니다. (카드 만)

- 함수 [BS2_SetServerMatchingHandler](bs2_setservermatchinghandler) 참조

- 함수 [BS2_VerifyUserFaceEx](bs2_verifyuserfaceex) 참조

## 수정 기능

1. Device to server 연결 모드일 때 장치가 정상적으로 연결되지 않을 수 있는 문제가 수정되었습니다.

1. [BS2_ReleaseContext](bs2_releasecontext)를 통해 SDK가 unload 되는 과정에서, 특정 thread로 인해 정상적으로 unload 되지 않을 수 있는 문제가 수정되었습니다.

1. 체온 측정 범위가 수정되었습니다. (30º \~ 45º =\> 1º \~ 45º)

- 구조체 [BS2FaceConfigExt](configuration_api#bs2faceconfigext) 참조 (thermalThresholdLow, thermalThresholdHigh)

1. FaceStation F2에서 복수의 이미지를 가진 사용자를 등록시, BS_SDK_ERROR_NOT_SUPPORTED 또는 BS_SDK_ERROR_TIMEOUT 오류가 반환되는 문제가 수정되었습니다.

- 함수 [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex) 참조

1. BioStation 2를 제외한 일부 장치들에서 특정함수를 호출하면 정상 동작되나, 결과값으로 BS_SDK_ERROR_TIMEOUT 오류를 반환하는 문제가 수정되었습니다.

- 함수 [BS2_ResetConfigExceptNetInfo](bs2_resetconfigexceptnetinfo) 참조


---

# 2.7.2 버전 (V2.7.2.4)

## 날짜

2020-11-11

## 새로운 기능

- Wiegand 출력 시 사용자 ID 출력 지원.

1. Wiegand 출력 시, Card ID 또는 사용자 ID를 선택적으로 출력할 수 있도록 추가되었습니다.

- 구조체 [BS2WiegandConfig](configuration_api#bs2wiegandconfig) 참조

- 함수 [BS2_GetWiegandConfig](bs2_getwiegandconfig) 참조

- 함수 [BS2_SetWiegandConfig](bs2_setwiegandconfig) 참조

## 수정 기능

1. SDK 내부적으로 파일로그 출력 구조가 수정되었습니다.

   기존에는 이벤트 처리 쓰레드들이 각자 파일쓰기를 처리했으나, 파일처리 쓰레드를 별도로 두어 처리하도록 수정되었습니다.

   이로인해 이벤트 처리속도가 향상되었습니다.

- 함수 [BS2_SetDebugFileLog](bs2_setdebugfilelog) 참조

1. FaceStation F2에서 얼굴 복수 개 등록 시,

   BS_SDK_ERROR_NO_FACE_CREDENTIAL(-759) 오류가 발생할 수 있는 문제가 수정되었습니다.

- 함수 [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex) 참조

1. 장치 연결이 끊길 경우, 간헐적으로 callback 동작하지 않을 수 있는 문제가 수정되었습니다.

- 함수 [BS2_SetDeviceEventListener](bs2_setdeviceeventlistener) 참조

1. SDK 내부적으로 코드 안정화를 위한 수정이 있었습니다.


---

# 2.7.1 버전 (V2.7.1.1)

## 날짜

2020-09-15

## 새로운 기능

- 신규장치 FaceStation F2 지원 추가.

- 열화상 감지 및 마스크 착용 여부를 검출 기능 지원

- 사용자 정의 PIN 암호화 키 변경 기능 추가.

1. 신규장치 FaceStation F2을 지원하며, 사용자 관련 함수 및 구조체가 추가되었습니다.

- 구조체 [BS2UserSettingEx](user_management_api#bs2usersettingex) 참조

- 구조체 [BS2TemplateEx](face_api#bs2templateex) 참조

- 구조체 [BS2FaceEx](face_api#bs2faceex) 참조

- 구조체 [BS2UserFaceExBlob](user_management_api#bs2userfaceexblob) 참조

- 함수 [BS2_ScanFaceEx](bs2_scanfaceex) 참조

- 함수 [BS2_ExtraceTemplateFaceEx](bs2_extracetemplatefaceex) 참조

- 함수 [BS2_EnrollUserFaceEx](bs2_enrolluserfaceex) 참조

- 함수 [BS2_GetUserInfosFaceEx](bs2_getuserinfosfaceex) 참조

- 함수 [BS2_GetUserDatasFaceEx](bs2_getuserdatasfaceex) 참조

1. FaceStation F2의 인증모드가 대폭 추가되었으며, 아래의 함수를 통해 설정할 수 있습니다.

- 구조체 [BS2AuthConfigExt](configuration_api#bs2authconfigext) 참조

- 함수 [BS2_GetAuthConfigExt](bs2_getauthconfigext) 참조

- 함수 [BS2_SetAuthConfigExt](bs2_setauthconfigext) 참조

1. FaceStation F2 장치에서 jpg image로 template을 추출할 수 있습니다. 이렇게 추출한 template은 AOC에 담을 수 있습니다.

- 구조체 [BS2SmartCardHeader](smartcard_api#bs2smartcardheader) 참조

- 함수 [BS2_ExtraceTemplateFaceEx](bs2_extracetemplatefaceex) 참조

1. 얼굴의 열화상 감지와 마스크 착용 체크 정보 구조체 및 설정 함수가 추가되었습니다.

- 구조체 [BS2FaceConfigExt](configuration_api#bs2faceconfigext) 참조

- 함수 [BS2_GetFaceConfigExt](bs2_getfaceconfigext) 참조

- 함수 [BS2_SetFaceConfigExt](bs2_setfaceconfigext) 참조

1. 열화상 카메라 정보 구조체 및 설정 함수가 추가되었습니다.

- 구조체 [BS2ThermalCameraConfig](configuration_api#bs2thermalcameraconfig) 참조

- 함수 [BS2_GetThermalCameraConfig](bs2_getthermalcameraconfig) 참조

- 함수 [BS2_SetThermalCameraConfig](bs2_setthermalcameraconfig) 참조

1. 측정된 체온정보가 포함된 이벤트로그를 수신할 수 있는 함수가 추가되었습니다.

- 콜백함수 [OnLogReceivedEx](log_management_api#onlogreceivedex) 참조

- 구조체 [BS2EventSmallBlobEx](log_management_api#bs2eventsmallblobex) 참조

- 함수 [BS2_StartMonitoringLogEx](bs2_startmonitoringlogex) 참조

- 함수 [BS2_GetLogSmallBlobEx](bs2_getlogsmallblobex) 참조

- 함수 [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir) 참조

1. 사용자 정의 PIN 암호화 키를 변경하고, PIN을 추출할 수 있는 함수가 추가되었습니다.

- 함수 [BS2_SetDataEncryptKey](bs2_setdataencryptkey) 참조

- 함수 [BS2_MakePinCodeWithKey](bs2_makepincodewithkey) 참조

## 수정 기능

1. FaceStation F2 장치의 configuration 설정을 지원하기 위해 구조체가 수정되었습니다.

- 구조체 [BS2FaceConfig](configuration_api#bs2faceconfig) 참조

1. Mask를 지정하여 사용자 정보를 취득하는 함수들의 mask 정보가 추가되었습니다. (각 함수의 userMask 파라메터 참조)

- 함수 [BS2_GetUserDatas](bs2_getuserdatas) 참조

- 함수 [BS2_GetUserDatasEx](bs2_getuserdatasex) 참조

- 함수 [BS2_GetSupportedUserMask](bs2_getsupportedusermask) 참조

- 함수 [BS2_GetUserSmallDatas](bs2_getusersmalldatas) 참조

- 함수 [BS2_GetUserSmallDatasEx](bs2_getusersmalldatasex) 참조

- 함수 [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir) 참조

- 함수 [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir) 참조

- 함수 [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir) 참조

- 함수 [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir) 참조

- 함수 [BS2_GetUserInfosFaceEx](bs2_getuserinfosfaceex) 참조

- 함수 [BS2_GetUserDatasFaceEx](bs2_getuserdatasfaceex) 참조

1. 장치 지원정보에서 fingerSupported, faceSupported와 같은 정보들이,

   내부적으로 지문인증(매칭), 얼굴인증(매칭)을 지원하는 의미로 사용되었었습니다.

   따라서 FaceStation2가 fingerSupported true를 반환하고, CoreStation이 fingerSupported true를 반환하는 등, 혼란이 있었습니다.

   V2.7.1에서는 fingerScanSupported, faceScanSupported와 같은 정보를 추가로 제공할 수 있도록 추가되었습니다.

   이제부터 FaceStation2에서 fingerScanSupported는 false를 반환합니다.

- 함수 [BS2_GetDeviceInfoEx](bs2_getdeviceinfoex) 참조

- 구조체 [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex) 참조

1. 보안상의 문제로 함수 BS2_GetDataEncryptKey의 지원이 중단되었습니다.


---

# 2.7.0 버전 (V2.7.0.0)

## 날짜

2020-07-21

## 새로운 기능

- XPass D2 Revision, XPass D2 Keypad Revision 장치 지원.

- 스케줄 기반의 lift lock/unlock zone 추가.

- 개인인증 메시지 서버 확인 기능 추가.

- 출입문 센서 기반의 글로벌 안티패스백 지원 추가.

1. XPass D2 Revision, XPass D2 Keypad Revision 장치연결 지원이 추가되었습니다.

1. Lift 사용과 관련하여, 인증권한과 무관하게 스케줄 기반으로 특정 층에 접근할 수 있도록 기능이 추가되었습니다.

- 구조체 [BS2LiftFloors](zone_control_api#bs2liftfloors) 참조

- 구조체 [BS2LiftLockUnlockZone](zone_control_api#bs2liftlockunlockzone) 참조

- 함수 [BS2_GetLiftLockUnlockZone](bs2_getliftlockunlockzone) 참조

- 함수 [BS2_GetAllLiftLockUnlockZone](bs2_getallliftlockunlockzone) 참조

- 함수 [BS2_GetLiftLockUnlockZoneStatus](bs2_getliftlockunlockzonestatus) 참조

- 함수 [BS2_GetAllLiftLockUnlockZoneStatus](bs2_getallliftlockunlockzonestatus) 참조

- 함수 [BS2_SetLiftLockUnlockZone](bs2_setliftlockunlockzone) 참조

- 함수 [BS2_SetLiftLockUnlockZoneAlarm](bs2_setliftlockunlockzonealarm) 참조

- 함수 [BS2_RemoveLiftLockUnlockZone](bs2_removeliftlockunlockzone) 참조

- 함수 [BS2_RemoveAllLiftLockUnlockZone](bs2_removeallliftlockunlockzone) 참조

1. 개인 인증 메시지를 서버에 요청할 수 있는 기능이 추가되었습니다.

- 구조체 [BS2DisplayConfig](configuration_api#bs2displayconfig) 참조

- 함수 [BS2_SetUserPhraseHandler](bs2_setuserphrasehandler) 참조

- 함수 [BS2_ResponseUserPhrase](bs2_responseuserphrase) 참조

1. 출입문 센서 기반의 글로벌 안티패스백 지원이 추가되었습니다.

   이 기능은 사용자 인증 후 한 번, 출입문 센서 기반으로 또 한 번, 총 두 차례 서버에 안티패스백 판정을 묻습니다.

   출입문 센서 기반의 안티패스백을 이용하여, 실제 인증이 이루어졌지만, 문을 개방하여 들어가지 않았거나, 나가지 않은 경우를 여과해낼 수 있습니다.

- 구조체 [BS2DoorSensor](door_control_api#bs2doorsensor) 참조

- 함수 [BS2_SetGlobalAPBViolationByDoorOpenHandler](bs2_setglobalapbviolationbydooropenhandler) 참조

- 함수 [BS2_CheckGlobalAPBViolationByDoorOpen](bs2_checkglobalapbviolationbydooropen) 참조

## 수정 기능

1. 통신키가 오염되어, 장치연결 성공 이후, 어떠한 장치명령도 수행되지 않는 문제가 수정되었습니다. (최신의 FW 장치에서 드물게 발생)

1. IPv6 연결 모드에서 장치로부터 정상적인 패킷의 수신 처리가 되지 않을 수 있는 문제가 수정되었습니다.

- 구조체 [BS2UserBlobEx](user_management_api#bs2userblobex) 참조

- 함수 [BS2_VerifyUserEx](bs2_verifyuserex) 참조

- 함수 [BS2_IdentifyUserEx](bs2_identifyuserex) 참조

- 함수 [BS2_EnrolUserEx](bs2_enroluserex) 참조

- 함수 [BS2_VerifyUserSmallEx](bs2_verifyusersmallex) 참조

- 함수 [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex) 참조

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 참조

1. 장치로부터 로그 수신 시, 16KB 이상의 이미지가 수신될 때 BS2_SDK_ERROR_INVALID_PACKET 오류를 발생시키며 수신이 중단되는 문제가 수정되었습니다.

- 함수 [BS2_GetLogBlob](bs2_getlogblob) 참조

- 함수 [BS2_GetLogSmallBlob](bs2_getlogsmallblob) 참조

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 참조

- 함수 [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) 참조

- 함수 [BS2_GetImageLog](bs2_getimagelog) 참조


---

# 2.6.4 버전 (V2.6.4.1)

## 날짜

2020-02-25

## 새로운 기능

- EventMask에 맞게 로그를 취득하는 함수 추가.

- DesFire 카드 고급 설정 지원.

- 장치에서 지원하는 카드를 선택할 수 있는 기능 지원.

- 중복 지문/얼굴 검사기능 지원

1. 보다 효율적으로 메모리를 사용면서, EventMask에 맞는 로그를 취득하는 함수가 추가되었습니다.

- 구조체 [BS2EventSmallBlob](Log_Management_API#bs2eventsmallblob) 참조

- 함수 [BS2_GetLogSmallBlob](bs2_getlogsmallblob) 참조

- 함수 [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) 참조

1. DesFire 카드 고급 설정을 지원합니다.

- 구조체 [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex) 참조

- 구조체 [BS2DesFireCardConfigEx](configuration_api#bs2desfirecardconfigex) 참조

- 함수 [BS2_GetDesFireCardConfigEx](bs2_getdesfirecardconfigex) 참조

- 함수 [BS2_SetDesFireCardConfigEx](bs2_setdesfirecardconfigex) 참조

1. 장치에서 지원하는 카드를 선택적으로 읽을 수 있게, 켜고 끄는 옵션이 추가되었습니다.

- 구조체 [BS2SystemConfig](configuration_api#bs2systemconfig) 참조

- 함수 [BS2_SetSystemConfig](bs2_setsystemconfig) 참조

1. 중복 얼굴(또는 지문) 여부 확인 모드가 추가되었습니다.

- 구조체 [BS2FaceConfig](Configuration_API#bs2faceconfig) 참조

- 함수 [BS2_GetFingerprintConfig](bs2_getfingerprintconfig) 참조

- 함수 [BS2_SetFingerprintConfig](bs2_setfingerprintconfig) 참조

- 구조체 [BS2FingerprintConfig](Configuration_API#bs2fingerprintconfig) 참조

- 함수 [BS2_GetFaceConfig](bs2_getfaceconfig) 참조

- 함수 [BS2_SetFaceConfig](bs2_setfaceconfig) 참조

## 수정 기능

1. BS2UserBlobEx의 멤버 BS2Job에서 numJobs가 array의 허용치인 16을 초과하여 설정하면 장치가 오동작되며 재부팅되는 문제가 수정되었습니다.

- 구조체 [BS2UserBlobEx](user_management_api#bs2userblobex) 참조

- 함수 [BS2_VerifyUserEx](bs2_verifyuserex) 참조

- 함수 [BS2_IdentifyUserEx](bs2_identifyuserex) 참조

- 함수 [BS2_EnrolUserEx](bs2_enroluserex) 참조

- 함수 [BS2_VerifyUserSmallEx](bs2_verifyusersmallex) 참조

- 함수 [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex) 참조

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 참조

1. BioStation 2에서 사용자 이미지를 사용할 수 없었던 문제가 수정되었습니다.

1. SecureIO 2 펌웨어 업그레이드 시, BS_SDK_INVALID_CODE_SIGN 오류가 발생하는 문제가 수정되었습니다.

1. BLN2-PAB 모델에 BS2_GetCardModel을 호출 시, BS_SDK_ERROR_NOT_SUPPORTED 오류가 발생하는 문제가 수정되었습니다.

- 함수 [BS2_GetCardModel](bs2_getcardmodel) 참조

1. 장치가 간헐적으로 끊기는 상황이 반복되면, SDK에서 장치가 끊어지는 상황을 감지하지 못하는 문제가 수정되었습니다.

1. Linux상에서 SDK가 crash 될 수 있는 문제가 수정되었습니다.


---

# 2.6.4 버전 (V2.6.4.1)

## 날짜

2020-02-25

## 새로운 기능

- EventMask에 맞게 로그를 취득하는 함수 추가.

- DesFire 카드 고급 설정 지원.

- 장치에서 지원하는 카드를 선택할 수 있는 기능 지원.

- 중복 지문/얼굴 검사기능 지원

1. 보다 효율적으로 메모리를 사용면서, EventMask에 맞는 로그를 취득하는 함수가 추가되었습니다.

- 구조체 [BS2EventSmallBlob](Log_Management_API#bs2eventsmallblob) 참조

- 함수 [BS2_GetLogSmallBlob](bs2_getlogsmallblob) 참조

- 함수 [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir) 참조

1. DesFire 카드 고급 설정을 지원합니다.

- 구조체 [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex) 참조

- 구조체 [BS2DesFireCardConfigEx](configuration_api#bs2desfirecardconfigex) 참조

- 함수 [BS2_GetDesFireCardConfigEx](bs2_getdesfirecardconfigex) 참조

- 함수 [BS2_SetDesFireCardConfigEx](bs2_setdesfirecardconfigex) 참조

1. 장치에서 지원하는 카드를 선택적으로 읽을 수 있게, 켜고 끄는 옵션이 추가되었습니다.

- 구조체 [BS2SystemConfig](configuration_api#bs2systemconfig) 참조

- 함수 [BS2_SetSystemConfig](bs2_setsystemconfig) 참조

1. 중복 얼굴(또는 지문) 여부 확인 모드가 추가되었습니다.

- 구조체 [BS2FaceConfig](Configuration_API#bs2faceconfig) 참조

- 함수 [BS2_GetFingerprintConfig](bs2_getfingerprintconfig) 참조

- 함수 [BS2_SetFingerprintConfig](bs2_setfingerprintconfig) 참조

- 구조체 [BS2FingerprintConfig](Configuration_API#bs2fingerprintconfig) 참조

- 함수 [BS2_GetFaceConfig](bs2_getfaceconfig) 참조

- 함수 [BS2_SetFaceConfig](bs2_setfaceconfig) 참조

## 수정 기능

1. BS2UserBlobEx의 멤버 BS2Job에서 numJobs가 array의 허용치인 16을 초과하여 설정하면 장치가 오동작되며 재부팅되는 문제가 수정되었습니다.

- 구조체 [BS2UserBlobEx](user_management_api#bs2userblobex) 참조

- 함수 [BS2_VerifyUserEx](bs2_verifyuserex) 참조

- 함수 [BS2_IdentifyUserEx](bs2_identifyuserex) 참조

- 함수 [BS2_EnrolUserEx](bs2_enroluserex) 참조

- 함수 [BS2_VerifyUserSmallEx](bs2_verifyusersmallex) 참조

- 함수 [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex) 참조

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 참조

1. BioStation 2에서 사용자 이미지를 사용할 수 없었던 문제가 수정되었습니다.

1. SecureIO 2 펌웨어 업그레이드 시, BS_SDK_INVALID_CODE_SIGN 오류가 발생하는 문제가 수정되었습니다.

1. BLN2-PAB 모델에 BS2_GetCardModel을 호출 시, BS_SDK_ERROR_NOT_SUPPORTED 오류가 발생하는 문제가 수정되었습니다.

- 함수 [BS2_GetCardModel](bs2_getcardmodel) 참조

1. 장치가 간헐적으로 끊기는 상황이 반복되면, SDK에서 장치가 끊어지는 상황을 감지하지 못하는 문제가 수정되었습니다.

1. Linux상에서 SDK가 crash 될 수 있는 문제가 수정되었습니다.


---

# 2.6.3 버전 (V2.6.3.16)

## 날짜

2019-11-04

## 수정 기능

1. 장치 연결 시, 다음의 장치들이 연결에 실패할 수 있는 문제 수정.

* BioEntry Plus 2.0

* BioEntry W 2.0

* BioLiteNet 2.0

* Xpass 2.0

* Xpass Slim 2.0

1. 장치 검색을 하고 연결하는 형태가 아닌,

   IP, port로 장치를 직접 연결한 후 BS2_GetDeviceInfo를 호출하면 반환값 dualIDSupported, useAlphanumericID의 값이 0이 되는 문제 수정.

* 함수 [BS2_SearchDevices](bs2_searchdevices) 참조

* 함수 [BS2_ConnectDevice](bs2_connectdevice) 참조

* 함수 [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip) 참조

* 함수 [BS2_GetDeviceInfo](bs2_getdeviceinfo) 참조

* 구조체 [BS2SimpleDeviceInfo](device_api#bs2simpledeviceinfo) 참조

1. 다음의 장치들이 Factory reset을 시도하게되는 경우, timeout 오류(BS_SDK_ERROR_TIMEOUT)가 발생할 수 있는 문제 수정.

* BioEntry Plus 2.0

* BioEntry W 2.0

* BioLiteNet 2.0

* Xpass 2.0

* Xpass Slim 2.0

* 함수 [BS2_FactoryReset](bs2_factoryreset) 참조

1. 장치와의 연결이 끊어지고 SDK 내에서는 아직 연결이 닫히지 않은 상태에서 패킷을 교환하게되는 경우 무한루프에 빠지게되는 문제를 정상적으로 연결이 종료되도록 수정.


---

# 2.6.3 버전 (V2.6.3.12)

## 날짜

2019-09-30

## 수정 기능

1. SDK를 통해 장치가 연결된 이후, 네트워크 통신이 끊어지고 WSA_INVALID_HANDLE이 발생되는 경우, 무한루프에 빠질 수 있는 문제수정.

1. 통신 패킷 처리과정에서 출력되는 디버깅 로그가 너무 많아 질수 있는 문제 보완.

* 함수 [BS2_SetDebugExCallback](bs2_setdebugexcallback), [BS2_SetDebugFileLog](bs2_setdebugfilelog)에서 사용되는 level(DEBUG_LOG_OPERATION_ALL - 0xFF\] 신규추가


---

# 2.6.3 버전 (V2.6.3.11)

## 날짜

2019-09-10

## 수정 기능

- SSL 연결 상태에서, firmware upgrade가 간헐적으로 실패할 수 있는 문제 수정


---

# 2.6.3 버전 (V2.6.3.10)

## 날짜

2019-08-30

## 수정 기능

- 일부 API에서 디버깅로그 출력을 선언하고 호출하면 정상 호출되나, 디버깅로그 출력을하지 않고 호출하면 BS_SDK_ERROR_TIMEOUT 오류가 발생하는 문제 수정.

- [BS2_UpdateResource](bs2_updateresource) 호출 후 BS_SDK_ERROR_TIMEOUT 오류가 발생할 수 있는 문제 수정.

- 벌크 사용자 등록, FW 업그레이드 등 시간이 소요되는 작업이 오류로 반환될 수 있는 문제 수정

- SDK 크래시 가능성이 있는 코드 보완


---

# 2.6.3 버전 (V2.6.3.5)

## 날짜

2019-07-24

## 새로운 기능

- XPass D2 Keypad 장치 지원

- Face Lite 장치 지원

- XPass 2, XPass 2 Keypad 장치 지원

- IPv6 지원(BS2 FW 1.8.0 only)

- 설정된 서버 포트 얻기

- 패킷 응답 대기시간 설정 지원

- 사용자 등록 함수 BS2_EnrollUser 및 BS2_EnrollUserEx 지원

- 큰 용량의 BS2UserBlob / BS2UserBlobEx 에 대해서 효율적인 메모리 사용을 위해 BS2UserSmallBlob / BS2UserSmallBlobEx 을 지원 (User Photo 영역을 포인터 처리)

- Admin User 1000 명 이상 지원 (BS2 1.8.0, A2 1.7.0, L2 1.5.0, N2 1.2.0, FS 1.3.0, FaceLite 1.0.1, CS40 1.3.0, P2 1.3.0, W2 1.4.0, Xpass 2 1.0.0 이상 버전, 표기되지 않은 장치는 지원되지 않음)

- 지문템플릿 품질점수 지원

- 파일로그 출력 지원

1. XPass D2 Keypad 장치연결 지원이 추가되었습니다.

1. Face Lite 장치연결 지원이 추가되었습니다.

1. XPass 2, XPass 2 Keypad 장치연결 지원이 추가되었습니다.

1. IPv6 연결을 지원합니다.

   SDK가 초기화 되어진 이후 IP V6의 기본값은 비활성화 상태입니다.

- 구조체 [BS2IPV6Config](configuration_api#bs2ipv6config) 추가

- 구조체 [BS2IPv6DeviceInfo](device_api#bs2ipv6deviceinfo) 추가

- 함수 [BS2_SetDebugExCallback](bs2_setdebugexcallback) 추가

- 함수 [BS2_GetIPConfigViaUDPEx](bs2_getipconfigviaudpex) 추가

- 함수 [BS2_SetIPConfigViaUDPEx](bs2_setipconfigviaudpex) 추가

- 함수 [BS2_GetIPV6Config](bs2_getipv6config) 추가

- 함수 [BS2_SetIPV6Config](bs2_setipv6config) 추가

- 함수 [BS2_GetIPV6ConfigViaUDP](bs2_getipv6configviaudp) 추가

- 함수 [BS2_SetIPV6ConfigViaUDP](bs2_setipv6configviaudp) 추가

- 함수 [BS2_GetIPV6ConfigViaUDPEx](bs2_getipv6configviaudpex) 추가

- 함수 [BS2_SetIPV6ConfigViaUDPEx](bs2_setipv6configviaudpex) 추가

- 함수 [BS2_GetEnableIPV4](bs2_getenableipv4) 추가

- 함수 [BS2_SetEnableIPV4](bs2_setenableipv4) 추가

- 함수 [BS2_GetEnableIPV6](bs2_getenableipv6) 추가

- 함수 [BS2_SetEnableIPV6](bs2_setenableipv6) 추가

- 함수 [BS2_SetServerPortIPV6](bs2_setserverportipv6) 추가

- 함수 [BS2_GetServerPortIPV6](bs2_getserverportipv6) 추가

- 함수 [BS2_SetSSLServerPortIPV6](bs2_setsslserverportipv6) 추가

- 함수 [BS2_GetSSLServerPortIPV6](bs2_getsslserverportipv6) 추가

- 함수 [BS2_GetSpecifiedDeviceInfo](bs2_getspecifieddeviceinfo) 추가

- 함수 [BS2_SearchDevicesCoreStationEx](bs2_searchdevicescorestationex) 추가

1. 서버 포트를 얻을 수 있는 함수가 추가되었습니다.

- 함수 [BS2_GetServerPort](bs2_getserverport) 추가

- 함수 [BS2_GetSSLServerPort](bs2_getsslserverport) 추가

1. 장치와의 패킷 응답 대기시간 변경이 가능하도록 추가되었습니다.

- 함수 [BS2_SetDefaultResponseTimeout](bs2_setdefaultresponsetimeout) 추가

- 함수 [BS2_GetDefaultResponseTimeout](bs2_getdefaultresponsetimeout) 추가

1. 사용자 등록 함수의 미국식 표현인 BS2_EnrollUser 및 BS2_EnrollUserEx가 추가되었습니다.

   기존 BS2_EnrolUser, BS2_EnrolUserEx 함수와 내용 동일합니다.

- 함수 [BS2_EnrollUser](bs2_enrolluser) 추가

- 함수 [BS2_EnrollUserEx](bs2_enrolluserex) 추가

1. 사용자 구조체 [BS2UserBlob](user_management_api#bs2userblob)과 [BS2UserBlobEx](user_management_api#bs2userblobex)의 멤버 [BS2UserPhoto](user_management_api#bs2userphoto)는 고정메모리를 갖도록 설계되어 있습니다.

   photo 기능을 사용하지 않는 경우에도 적지않은 크기의 메모리를 고정적으로 사용하게 됩니다.

   송수신하는 사용자 수가 많지 않은 경우 크게 문제되지 않으나,

   사용자 수가 많아지면 차지하는 메모리의 크기도 비례적으로 커지게 되는 문제가 발생할 수 있습니다.

   2.6.3에서는 [BS2UserPhoto](user_management_api#bs2userphoto)의 포인터 처리를 통해, 보다 효율적으로 메모리를 사용할 수 있는 함수를 새롭게 추가하였습니다.

- 구조체 [BS2UserSmallBlob](user_management_api#bs2usersmallblob) 추가

- 구조체 [BS2UserSmallBlobEx](user_management_api#bs2usersmallblobex) 추가

- 함수 [BS2_EnrollUserSmall](bs2_enrollusersmall) 추가

- 함수 [BS2_EnrollUserSmallEx](bs2_enrollusersmallex) 추가

- 함수 [BS2_GetUserSmallInfos](bs2_getusersmallinfos) 추가

- 함수 [BS2_GetUserSmallDatas](bs2_getusersmalldatas) 추가

- 함수 [BS2_GetUserSmallInfosEx](bs2_getusersmallinfosex) 추가

- 함수 [BS2_GetUserSmallDatasEx](bs2_getusersmalldatasex) 추가

- 함수 [BS2_VerifyUserSmall](bs2_verifyusersmall) 추가

- 함수 [BS2_IdentifyUserSmall](bs2_identifyusersmall) 추가

- 함수 [BS2_VerifyUserSmallEx](bs2_verifyusersmallex) 추가

- 함수 [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex) 추가

- 함수 [BS2_GetUserSmallInfosFromDir](bs2_getusersmallinfosfromdir) 추가

- 함수 [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir) 추가

- 함수 [BS2_GetUserSmallInfosExFromDir](bs2_getusersmallinfosexfromdir) 추가

- 함수 [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir) 추가

1. 장치 관리자를 1000명까지 등록할 수 있도록 추가되었습니다.

   기존 [BS2AuthConfig](configuration_api#bs2authconfig)를 이용하여 장치 관리자 등록 시, 10명의 관리자까지 허용된다는 한계가 있었습니다.

   2.6.3부터는 아래 새롭게 제공되는 함수를 통해 최대 1000명까지 관리자 등록이 가능합니다.

:::warning

**주의 사항**

아래 새롭게 제공되는 함수를 호출하게되면,

기존 BS2AuthConfig를 통해 관리되던 관리자 목록을 1000명의 관리자 지원이 가능한 장소로 안전하게 이동시키고,

해당 장소를 통해 장치관리자들을 관리하게 됩니다.

이후부터는 아래의 새롭게 제공되는 함수들만을 이용하여 장치관리자를 관리해야 합니다.

그리고 기존의 BS2AuthConfig를 통한 관리자 설정은 무시되어집니다.

아래의 장치관리자 확장용 신규함수가 호출되어지지 않는다면

기존의 BS2AuthConfig 관련 함수를 통한 관리자 설정은 유효합니다. 

:::

- 구조체 [BS2AuthOperatorLevel](device_api#bs2authoperatorlevel) 추가

- 함수 [BS2_GetAuthOperatorLevelEx](bs2_getauthoperatorlevelex) 추가

- 함수 [BS2_GetAllAuthOperatorLevelEx](bs2_getallauthoperatorlevelex) 추가

- 함수 [BS2_SetAuthOperatorLevelEx](bs2_setauthoperatorlevelex) 추가

- 함수 [BS2_RemoveAuthOperatorLevelEx](bs2_removeauthoperatorlevelex) 추가

- 함수 [BS2_RemoveAllAuthOperatorLevelEx](bs2_removeallauthoperatorlevelex) 추가

1. 지문템플릿의 품질점수 확인 기능이 추가되었습니다.

- 구조체 [BS2Fingerprint](fingerprint_api#bs2fingerprint) 참조

- 함수 [BS2_GetFingerTemplateQuality](bs2_getfingertemplatequality) 추가

1. 디버깅용 파일로그 출력 지원이 추가되었습니다.

- 함수 [BS2_SetDebugFileLog](bs2_setdebugfilelog) 추가

## 수정 기능

1. Firmware file 업그레이드 시, Code sign 체크를 장치에서 수행하였으나, 이후 SDK에서 수행하도록 수정되었습니다.

   따라서 부적절한 firmware file의 경우 보다 빠르게 오류를 반환할 수 있게되었습니다.

- 함수 [BS2_UpgradeFirmware](bs2_upgradefirmware) 참조

1. 소켓이 연결된 후 바로 끊어지게되면, 간헐적으로 모든 통신이 동작되지 않을 수 있는 문제를 수정하였습니다.

1. 다수의 장치가 동시에 SSL 연결 시도 시, 간헐적으로 통신이 연결되지 않을 수 있는 문제를 수정하였습니다.

1. 장치 검색 시 간헐적으로 crash되는 문제를 수정하였습니다.

- 함수 [BS2_SearchDevicesEx](bs2_searchdevicesex) 참조

1. SDK 라이브러리의 사용종료 또는 라이브러리 내의 리소스 재할당을 위한 메모리 반납 단계에서

   간헐적으로 무응답(hang) 현상이 나타날 수 있는 문제를 수정하였습니다.

- 함수 [BS2_ReleaseContext](bs2_releasecontext) 참조

- 함수 [BS2_SetMaxThreadCount](bs2_setmaxthreadcount) 참조

1. iClass SEOS 카드 장치에서 card config 취득 시 잘못된 오류(BS_SDK_ERROR_NOT_SUPPORTED)를 반환하는 문제를 수정하였습니다.

- 함수 [BS2_GetCardConfigEx](bs2_getcardconfigex) 참조

1. 서로 다른 SSL 인증서 파일을 사용하는 장치들에서 동시에 SSL 연결 시도 시, 간헐적으로 연결이 되지 않는 문제를 수정하였습니다.

1. Lift control에서 잘못된 floor level을 가져오는 문제를 수정하였습니다.

- 함수 [BS2_GetFloorLevel](bs2_getfloorlevel) 참조

1. 서버 매칭 사용 시 지문 template이 384byte로 고정되어 있던 제약을 수정하였습니다.

1. Slave 장치에서 지문관련 일부 함수가 동작되지 않는 문제를 수정하였습니다.

- 함수 [BS2_ScanFingerprint](bs2_scanfingerprint) 참조

- 함수 [BS2_VerifyFingerprint](bs2_verifyfingerprint) 참조

1. 장치 별로 지원하는 장치설정과 지원하지 않는 장치설정이 다를 수 있는데,

   특정 설정을 지원하지 않는 장치로부터 설정을 가져오는 경우 timeout까지 기다리는 부분을

   BS_SDK_ERROR_NOT_SUPPORTED를 반환하도록 수정하였습니다.

- 함수 [BS2_GetConfig](bs2_getconfig) 참조

1. Access schedule 설정 호출 시, 호출 이후 정상적으로 호출 결과를 반환받지 못하는 문제를 수정하였습니다.

- 함수 [BS2_SetAccessSchedule](bs2_setaccessschedule) 참조

1. 장치가 서버모드로 연결 시, 처리방식을 동기식에서 비동기식으로 처리되도록 수정하였습니다.

1. SDK 초기화 단계에서 열기에 실패한 소켓을 정리하도록 수정하였습니다.

1. SSL 연결 종료 시 SSL 리소스를 정리하도록 수정하였습니다.

1. Socket에서 패킷 송수신 시 성능을 개선하였습니다.

   (오류 발생 시 5ms 간격으로 재시도. 10회의 재시도 또는 100ms 이상 오류 지속 시 끊김 처리)

1. 이벤트 처리 thread 생성 함수의 인자의 의미를 조정하였습니다.

   [BS2_SetMaxThreadCount](bs2_setmaxthreadcount) (2.6.3 이전):

   인자 값이 이벤트 처리 thread의 수만을 의미하지 않았습니다.

   실제로는 timer(2), server matching(1), notification(1), TCP/UDP 처리 각(1)

   총 6개의 예약 thread를 포함한 이벤트 처리 thread수를 지정해야했습니다.

   인자로 지정되는 thread의 최소값은 8이었습니다.

   실제 인자 값 8을 설정하면 내부적으로 예약 thread 총 6개를 뺀 실제 이벤트 처리 thread 수 2개를 설정하였습니다.

   [BS2_SetMaxThreadCount](bs2_setmaxthreadcount) (2.6.3 이후):

   인자로 지정하는 thread수가 이벤트 처리용 thread 수를 의미합니다. 따라서 최소값은 2입니다. 

   | 함수 | 초기값(이전) | 최소값(이전) | 초기값(이후) | 최소값(이후) |
   | --- | --- | --- | --- | --- |
   | BS2_SetMaxThreadCount | MAX(NumberOfCpuCores\*5, 15) | 8 | MAX(NumberOfCpuCores\*5, 15) | 2 |
   | BS2_SetMaxConnectThreadCount | 8 | 1 | 8 | 1 |

1. [BS2_ConnectDeviceViaIP](bs2_connectdeviceviaip) 사용시, 동일한 IP의 장치인 경우 복수 연결을 허용하지 않았으나, 동일 IP라도 다른 port인 경우 연결을 허용하도록 수정되었습니다.

1. \[C#예제\] BS2Door의 멤버 alarmFlags를 unconditionalLock으로 수정되었습니다.

1. \[C#예제\] BS2SoundAction 크기 변경 및 delay 멤버가 추가되었습니다.

1. \[C#예제\] LogControl에서 BS2_GetLogBlob의 BS2EventMaskEnum.JOB_CODE가 BS2EventMaskEnum.ALL로 수정되었습니다.

1. \[C#예제\] CardControl에서 불필요한 blacklist 코드를 제거하였습니다.

1. \[C#예제\] ConfigControl에서 BS2_SetDstConfig의 잘못된 코드 startTime.weekDay를 endTime.weekDay로 수정하였습니다.

1. \[C#예제\] SlaveControl에서 slave device에 대한 예제코드가 추가되었습니다.

   1.장치에서 지원하는 카드를 선택적으로 읽을 수 있도록 켜고 끄는 옵션이 추가되었습니다.

- 구조체 [BS2SystemConfig](Configuration_API#bs2systemconfig) 참조

1. 위조된 얼굴을 여과할 수 있는 민감도 설정항목이 추가되었습니다.

- 구조체 [BS2FaceConfig](Configuration_API#bs2faceconfig) 참조

1. 빠른 얼굴 등록 모드가 추가되었습니다.

- 구조체 [BS2FaceConfig](Configuration_API#bs2faceconfig) 참조

1. 중복 얼굴(또는 지문) 검사 기능이 추가되었습니다.

- 구조체 [BS2FaceConfig](Configuration_API#bs2faceconfig) 참조

- 구조체 [BS2FingerprintConfig](Configuration_API#bs2fingerprintconfig) 참조

1. GDPR(개인정보보호 규정) 지원 옵션이 추가되었습니다.

- 구조체 [BS2SystemConfig](Configuration_API#bs2systemconfig) 참조


---

# 2.6.2 버전

## 날짜

2018-07-24

## 수정 기능

1. CoreStation에서 RS485 설정, Input 설정 가져올수 없는 문제 수정.

1. CoreStation에서 BioEntry R2 장치를 지원하지 않는 문제 수정.


---

# 2.6.1 버전

## 날짜

2018-04-24

:::warning

**주의 사항**

2.5.0 버전까지는 Device SDK가 OpenSSL library를 정적으로 포함하고 있었으나,

2.6.0 버전부터는 공유 library 형태로 링크하도록 변경되었습니다.

따라서 적절한 OpenSSL library를 설치 후 실행시켜주셔야 합니다.

2.6.0 라이브러리는 OpenSSL 1.0.2n library를 기반으로 테스트 되었습니다.

예제파일에는 OpenSSL 1.0.2n Windows library 파일을 포함하고 있습니다. 

:::

## 수정 기능

1. BS2SimpleDeviceInfo에서 BS2SimpleDeviceInfoEx로 옮겨진 필드들이 원복 되었습니다.

   이로 인하여 v2.5.0의 코드에 대한 하위 호환성을 확보합니다.

* 구조체 [bs2simpledeviceinfo](device_api#bs2simpledeviceinfo) 참조

- 구조체 [bs2simpledeviceinfoex](device_api#bs2simpledeviceinfoex) 참조

1. C# 예제에 사용되는 SSL 인증서가 업데이트 되었습니다.

1. C# 예제에 포함되었던 오래된 FW 파일들을 삭제했습니다.


---

# 2.6.0 버전

## 날짜

2018-10-31

  **참고**

V2.5.0 이후 버그 수정 및 추가 보완 작업을 통해 V2.6.0으로 연계 반영되었으나, 매뉴얼 반영 시, 누락된 내용들을 추가 작성합니다.  

## 새로운 기능

- USB 읽기 기능(BioStation A2, FaceStation 2) 지원

- Debugging API 지원

- 서버 포트 변경 지원

- Global APB zone 기능 지원

- 장치 연결상태를 확인 기능 지원

- 자동연결 여부를 확인하고, 변경 기능 지원

1.USB 읽기 기능이 추가되었습니다.

- 함수 [BS2_AllocateUsbContext](bs2_allocateusbcontext) 추가

- 함수 [BS2_ReleaseUsbContext](bs2_releaseusbcontext) 추가

- 함수 [BS2_GetUserDatabaseInfoFromDir](bs2_getuserdatabaseinfofromdir) 추가

- 함수 [BS2_GetUserListFromDir](bs2_getuserlistfromdir) 추가

- 함수 [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir) 추가

- 함수 [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir) 추가

- 함수 [BS2_GetUserInfosExFromDir](bs2_getuserinfosexfromdir) 추가

- 함수 [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir) 추가

- 함수 [BS2_GetLogFromDir](bs2_getlogfromdir) 추가

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 추가

- 함수 [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir) 추가

1.SDK 내에서 발생하는 디버그 정보를 참조할 수 있도록 추가되었습니다.

- 함수 [BS2_SetDebugExCallback](bs2_setdebugexcallback) 추가

1.서버 포트를 지정할 수 있도록 추가하였습니다.

- 함수 [BS2_SetServerPort](bs2_setserverport) 추가

- 함수 [BS2_SetSSLServerPort](bs2_setsslserverport) 추가

1.Global APB zone 기능이 추가되었습니다.

- 함수 [BS2_SetCheckGlobalAPBViolationHandler](bs2_setcheckglobalapbviolationhandler) 추가

- 함수 [BS2_CheckGlobalAPBViolation](bs2_checkglobalapbviolation) 추가

1.장치 연결상태를 확인하는 기능이 추가되었습니다.

- 함수 [BS2_IsConnected](bs2_isconnected) 추가

1.자동연결 여부를 확인하고, 변경할 수 있도록 추가하였습니다.

- 함수 [BS2_IsAutoConnection](bs2_isautoconnection) 추가

- 함수 [BS2_SetAutoConnection](bs2_setautoconnection) 추가

## 수정 기능

1. 일부 함수에서 log 취득 시, 설정된 event mask 판단 조건이 수정되었습니다.

   (설정된 mask들 모두 만족하는 로그 =\> 하나라도 만족하는 로그)

* 함수 [BS2_GetLogBlob](bs2_getlogblob) 참조

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 참조

1. 일부 함수에서 사용자 정보 취득 시,

   설정된 userMask가 0x3FF보다 크면 Invalid Parameter 오류가 발생하는 문제를 수정하였습니다.

* 함수 [BS2_GetUserDatas](bs2_getuserdatas) 참조

- 함수 [BS2_GetUserDatasEx](bs2_getuserdatasex) 참조

- 함수 [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir) 참조

- 함수 [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir) 참조

1. Multi context를 사용 시, context release 단계에서 crash가 발생할 수 있는 문제를 수정하였습니다.

   또한 간헐적으로 access violation이 발생될 수 있는 문제를 수정하였습니다.

* 함수 [BS2_AllocateContext](bs2_allocatecontext) 참조

- 함수 [BS2_ReleaseContext](bs2_releasecontext) 참조

1. SDK 내부적으로 packet을 수신하는 중, buffer overflow로 crash가 될 수 있는 문제를 수정하였습니다.

1. Entry 계열의 장치에서 전체 사용자 삭제 시, timeout이 발생하는 문제를 수정하였습니다.

* 함수 [BS2_RemoveAllUser](bs2_removealluser) 참조

1. 사용자 정보 취득 시, userMask가 BS2_USER_MASK_ALL인 경우 Not Supported 오류가 발생하는 문제를 수정하였습니다.

* 함수 [BS2_GetSupportedConfigMask](bs2_getsupportedconfigmask) 참조

- 함수 [BS2_GetSupportedUserMask](bs2_getsupportedusermask) 참조

- 함수 [BS2_GetUserDatas](bs2_getuserdatas) 참조

- 함수 [BS2_GetUserDatasEx](bs2_getuserdatasex) 참조

1. Log 취득 시 data가 없는 경우, crash가 발생될 수 있는 문제를 수정하였습니다.

* 함수 [BS2_GetLog](bs2_getlog) 참조

- 함수 [BS2_GetFilteredLog](bs2_getfilteredlog) 참조

- 함수 [BS2_GetLogFromDir](bs2_getlogfromdir) 참조

1. RS485 통신 시 multi packet에 대한 packet이 버려질 수 있는 문제를 수정하였습니다.

1. Linux SDK에서 timer가 동작하지 않을 수 있는 문제를 수정하였습니다. (signal 방식에서 thread 방식으로 변경)

1. Linux SDK에서 signal handle 내의 memory 할당으로 dead-lock이 발생할 수 있는 문제를 수정하였습니다.

1. Linux에서 socket 사용 시, socket close 옵션 SOCK_CLOEXEC를 추가하였습니다.

1. Server matching 함수 사용시 내부적으로 잘못된 동기화 객체에 lock/unlock을 걸어주는 문제를 수정하였습니다.

1. 장치의 연결상태 중, 끊김 상태 (disconnected status)를 감지하기 위해 keep alive code를 보완하였습니다.

1. 침입탐지 구역 정보가 설정되지 않는 문제를 수정하였습니다.

   또한, 유효성 검사 시 잘못된 오류 판단 조건을 수정하였습니다.

   이전 : (0 \< door) AND (card data가 없는 경우), (0 \< card) AND (door ID가 없는 경우)

   이후 : (0 \< door) AND (door ID가 없는 경우), (0 \< card) AND (card data가 없는 경우)

* 함수 [BS2_SetIntrusionAlarmZone](bs2_setintrusionalarmzone) 참조

1. 실제 존재하지 않는 image log를 가져오는 경우 timeout이 발생될 때까지 block되는 문제를 수정하였습니다.

* 함수 [BS2_GetImageLog](bs2_getimagelog) 참조

- 함수 [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir) 참조

1. 침입탐지 구역에서 data가 없는 경우, allocation memory 오류가 발생하지 않도록 수정하였습니다.

   또한 zoneBlob이 NULL인 경우 개수만 반환하도록 수정하였습니다.

* 함수 [BS2_GetIntrusionAlarmZone](bs2_getintrusionalarmzone) 참조

1. Socket관련 내부 리소스가 소진되면 더 이상 TCP 연결이 되지 않던 문제가 수정되었습니다.

1. Entry 계열의 경우 출입문 설정 시, door ID가 65535를 초과하면 Invalid Parameter로 반환되도록 수정되었습니다.

* 함수 [BS2_SetDoor](bs2_setdoor) 참조

1. TCP 연결 시 handshake 단계에서 암호화 기능 활성화 코드가 추가되었습니다.

1. FaceStation2에서 지문 정보가 저장이 되지 않는 문제를 수정하였습니다.

1. 함수 [BS2_SearchDevicesCoreStation](bs2_searchdevicescorestation) 호출 시 crash 되는 문제 수정되었습니다.

1. 함수 [BS2_EnrolUser](bs2_enroluser) 호출 시 face의 template, image 크기의 유효성을 검사하도록 수정하였습니다.

1. 다음의 함수 호출 시 Not supported로 반환되는 문제를 수정하였습니다.

* 함수 [BS2_GetCardConfigEx](bs2_getcardconfigex) 참조

- 함수 [BS2_GetRs485ConfigEx](bs2_getrs485configex) 참조

## 날짜

2018-04-15

:::warning

**주의 사항**

2.5.0 버전까지는 Device SDK가 OpenSSL library를 정적으로 포함하고 있었으나,

2.6.0 버전부터는 공유 library 형태로 링크하도록 변경되었습니다.

따라서 적절한 OpenSSL library를 설치 후 실행시켜주셔야 합니다.

2.6.0 라이브러리는 OpenSSL 1.0.2n library를 기반으로 테스트 되었습니다.

예제파일에는 OpenSSL 1.0.2n Windows library 파일을 포함하고 있습니다. 

:::

## 새로운 기능

- 새로운 장치 연결 (BioLite N2, Xpass D2) 지원

- 일광절약 시간(DST) 지원

- 인터락 구역 지원

- 장치의 데이터 암호화키 설정 지원

- 네트워크 설정을 제외한 장치 초기화 지원

1.새로운 장치 BioLite N2, Xpass D2에 대한 연결을 지원합니다. Xpass D2는 slave 전용 카드 모델입니다.

1.일광절약 시간 설정은 장치당 2개까지 가능합니다. 또한 일광절약 시간 적용 여부를 알수 있도록 로그에 관련 정보가 추가되었습니다.

- 함수 [BS2_GetDstConfig](bs2_getdstconfig) 추가

- 함수 [BS2_SetDstConfig](bs2_setdstconfig) 추가

- 구조체 [BS2DstConfig](configuration_api#bs2dstconfig) 추가

- 구조체 [BS2Event](Log_Management_API#bs2event) 수정

1.인터락 구역 설정을 지원합니다. 이중 문으로 구성되어 한 쪽 문과, 다른 한 쪽 문이 서로 배타적으로 잠겨있어야 하는 경우 사용됩니다. 현재 CoreStation만 사용가능합니다.

- 함수 [BS2_GetInterlockZone](bs2_getinterlockzone) 추가

- 함수 [BS2_GetInterlockZoneStatus](bs2_getinterlockzonestatus) 추가

- 함수 [BS2_GetAllInterlockZoneStatus](bs2_getallinterlockzonestatus) 추가

- 함수 [BS2_SetInterlockZone](bs2_setinterlockzone) 추가

- 함수 [BS2_SetInterlockZoneAlarm](bs2_setinterlockzonealarm) 추가

- 함수 [BS2_RemoveInterlockZone](bs2_removeinterlockzone) 추가

- 함수 [BS2_RemoveAllInterlockZone](bs2_removeallinterlockzone) 추가

- 구조체 [BS2InterlockZoneBlob](zone_control_api#bs2interlockzoneblob) 추가

1.장치의 데이터 암호화키의 변경 및 확인을 지원합니다.

- 함수 [BS2_GetDataEncryptKey](bs2_getdataencryptkey) 추가

- 함수 [BS2_SetDataEncryptKey](bs2_setdataencryptkey) 추가

- 함수 [BS2_RemoveDataEncryptKey](bs2_removedataencryptkey) 추가

1.신규 장치초기화 함수 BS2_ResetConfigExceptNetInfo를 지원합니다. 이 함수는 BS2_ResetConfig와 비교하여 네트워크 정보를 제외한 초기화가 가능합니다.

- 함수 [BS2_ResetConfigExceptNetInfo](bs2_resetconfigexceptnetinfo) 추가

1.장치의 기능 지원 유무에 관한 정보를 가져오는 함수 BS2_GetDeviceInfoEx를 지원합니다. 이 함수는 BS2_GetDeviceInfo 함수를 호출할 때 사용되는 BS2SimpleDeviceInfo 구조체에서 최근 추가된 항목들을 옮긴 구조체 BS2SimpleDeviceInfoEx를 사용합니다.

- 함수 [BS2_GetDeviceInfoEx](bs2_getdeviceinfoex) 추가

- 구조체 [BS2SimpleDeviceInfoEx](device_api#bs2simpledeviceinfoex) 추가

## 수정 기능

1. Wiegand In/Out 동시 사용 지원 기능이 추가되었습니다.

   Wiegand 설정 시 mode 값으로 2를 설정하여 이 기능을 이용할 수 있습니다.

* 구조체 [BS2WiegandConfig](configuration_api#bs2wiegandconfig) 참조

1. 장치 보안템퍼 설정을 지원합니다.

   BS2SystemConfig의 secureTamper를 통해 현재 보안템퍼가 설정되어 있는지 확인 및 설정이 가능합니다.

   이 구조체 정보는 반드시 BS2_GetSystemConfig를 통해 읽어낸 후, 필요한 정보만 수정하고 BS2_SetSystemConfig로 설정하여야 합니다.

* 구조체 [BS2SystemConfig](configuration_api#bs2systemconfig) 참조

1. FaceStation2와 FaceLite의 지문 매칭 기능 지원

   얼굴인증 장치 FS2 혹은 FL는 지문센서가 없으며, 따라서 지문인증을 지원하지 않습니다.

   그러나 slave 장치로 지문장치가 연결이 되어질 수 있으므로 지문매칭을 지원합니다.

   따라서 FS2와 FL의 BS2SimpleDeviceInfo.fingersupported 값이 0에서 1로 변경되었습니다.

   현재 장치가 지문매칭을 지원하는지 여부는 BS2SimpleDeviceInfo의 fingerSupported를 통해 확인할 수 있습니다.

* 구조체 [BS2SimpleDeviceInfo](device_api#bs2simpledeviceinfo) 참조


---

# 2.5.0 버전

## 날짜

2017-09-25

:::warning

**주의 사항**

BioStar 2 Device SDK를 구성하고 있는 구조체가 바뀜에 따라서, SDK 버전을 업데이트하기 위해서는 SDK을 다시 빌드해야 합니다. 

:::

## 새로운 기능

- SEOS 카드(Elite Key, RF 성능 개선 포함) 지원

- CoreStation 지원, 장치 P2 지원

- Intrusion Alarm Zone 지원

- Ethernet Zone 지원

- USB 로그 및 유저 Export 지원

- 장치에서 로그 검색 기능 추가

1. SEOS 카드(Elite Key, RF 성능 개선 포함) 지원은 스마트 카드 레이아웃을 통해 iClass SEOS 카드 설정 지원하는 기능입니다.

* 함수 [BS2_GetCardConfigEx](bs2_getcardconfigex) 추가

- 함수 [BS2_SetCardConfigEx](bs2_setcardconfigex) 추가

- 구조체 [BS2CardConfigEx](Configuration_API#bs2cardconfigex) 추가

1. CoreStation 지원은 신규 장치인 CoreStation을 지원하는 기능이다. CoreStation은 Master의 Controller 역할을 하는 장치로서 하위 Slave 장치들과 연동하여 전반적인 기능을 수행합니다. 일반 장치와 다른 점은 Controller 역할만을 하기에 자체적으로 카드와 지문과 같은 크리덴셜의 입력을 받을 수 없습니다. 또한, 장치에서 별도의 UI를 제공하지 않기에 CoreStation에 대한 제어 및 설정은 BioStar 를 통해 지원합니다.

- 함수 [BS2_GetSlaveExDevice](bs2_getslaveexdevice) 추가

- 함수 [BS2_SetSlaveExDevice](bs2_setslaveexdevice) 추가

- 구조체 [BS2Rs485SlaveDeviceEX](Configuration_API#bs2rs485slavedeviceex) 추가

1.Intrusion Alarm Zone 지원은 다음과 같습니다. 경비 시스템이란 경비 대상 시설물에 감지기를 설치하여 침입 혹은 이상 신호가 발생할 경우 신호를 수신하여 대처하는 시스템으로, 무인 경비와 로컬 경비로 나뉩니다. 무인 경비는 원격지의 관제 센터에서 출동 요원이 대처하지만, 로컬 경비는 자체 관제 센터에서 상주 경비원이 대처하는 시스템이라고 합니다. 바이오스타의 타겟은 무인 경비의 비용에 부담을 느끼거나 자체 경비 시스템을 갖추고 있는 고객의 로컬 경비를 대상으로 합니다. 현재는 일반적인 경비 구역 기능(biostar1.X)을 제공하며, 향후 3rd party alarm 시스템의 경비/해제 장치 통합, 장기적으로는 Video와 Visual map기능에서의 적용 등 전문 로컬 관제 시스템 구축을 목표로 합니다.

- 함수 [BS2_GetIntrusionAlarmZone](bs2_getintrusionalarmzone) 추가

- 함수 [BS2_GetIntrusionAlarmZoneStatus](bs2_getintrusionalarmzonestatus) 추가

- 함수 [BS2_SetIntrusionAlarmZone](bs2_setintrusionalarmzone) 추가

- 함수 [BS2_SetIntrusionAlarmZoneAlarm](bs2_setintrusionalarmzonealarm) 추가

- 함수 [BS2_RemoveIntrusionAlarmZone](bs2_removeintrusionalarmzone) 추가

- 함수 [BS2_SetIntrusionAlarmZoneArm](bs2_setintrusionalarmzonearm) 추가

- 구조체 [BS2IntrusionAlarmZoneBlob](Configuration_API#bs2intrusionalarmzoneblob) 추가

1.Ethernet Zone 지원은 Zone Master 역할을 BioStar V2.x 서버가 아닌 특정 장치가 하며 장치 사이(Master \<-\> Member)의 통신 방식으로 Ethernet TCP 통신 방식을 사용하는 Zone입니다.기존 1.x Entrance Limit, Fire Alarm Zone에 사응하는 기능만을 현재는 지원합니다.

- 함수 [BS2_GetDeviceZone](bs2_getdevicezone) 추가

- 함수 [BS2_SetDeviceZone](bs2_setdevicezone) 추가

- 함수 [BS2_RemoveDeviceZone](bs2_removedevicezone) 추가

- 함수 [BS2_SetDeviceZoneAlarm](bs2_setdevicezonealarm) 추가

- 구조체 [BS2DeviceZoneConfig](Configuration_API#bs2devicezoneconfig) 추가

1.USB 로그 및 유저 Export 지원은 다음과 같습니다. 네트워크 연결이 어려운 현장에서 USB를 통해 유저와 로그를 Export / Import 하여 T&A 용도로 사용하고 있습니다. (대표적 사용 시나리오) BioStar 서버가 설치된 본사에서 유저를 등록하고 해당 유저를 USB에 담아 현장에 보내서 사용하고, 매월 초에 전월의 로그를 담아서 T&A 근태 결과를 반영하고 있습니다. 실제적으로는 USB에 옮겨담아 처리하거나, USB로 받은 데이터를 재 전달하여서도 처리할 수 있도록 하기 위해 파일 형태로 지원되어야 합니다.

- 함수 [BS2_GetUserListFromDir](bs2_getuserlistfromdir) 추가

- 함수 [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir) 추가

- 함수 [BS2_GetLogFromDir](bs2_getlogfromdir) 추가

1.장치에서 로그 검색 기능 추가는 장치에서 SDK를 이용해서 로그를 검색하여 표시하거나 가져 갈 경우 장시간 응답 없는 상태 을 개선을 하였습니다.

- 함수 [BS2_GetFilteredLogSinceEventId](bs2_getfilteredlogsinceeventid) 추가

## 수정 기능

1. BS2_ScanFingerprint의 확장형으로 BS2_ScanFingerprintEx 추가가 되었습니다. 확장된 함수에는 outQuality 파라미터 추가가 되었습니다. 기존 함수를 유지하는 이유는 하위 호환성을 고려하기 위함입니다.

```cpp
#include "BS_API.h"

int BS2_ScanFingerprintEx(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, uint32_t* outQuality, OnReadyToScan ptrReadyToScan);
```

1. SSL connect시 wait time시간을 주어서 시간 단축을 하였습니다.

1. Payload size가 큰 경우 Internal Error 발생 오류 수정이 되었습니다.

1. Packet Loss 및 Packet 처리 방법 개선으로 UDP 장치 검색시 일부 장치를 찾지 못한 이슈가 수정이 되었습니다.

1. C# 예제에 관련된 사항으로 BS2Schedule 주석 처리를 하였습니다. C#언어적인 한계(Union 형식 미지원)로 문제점을 가지고 있기 때문입니다. BS2Schedule 대신 CSP_BS2Schedule를 사용하고, BS2Schedule을 사용해야 하는 함수 BS2_GetAllAccessSchedule, BS2_GetAccessSchedule, BS2_SetAccessSchedule는 WRAPPER함수인 CSP_BS2_GetAllAccessSchedule, CSP_BS2_GetAccessSchedule, CSP_BS2_SetAccessSchedule 사용하면 됩니다. CSP_BS2Schedule 에서 scheduleUnion.daily, scheduleUnion.weekly 값은 isDaily에 값에 의해 유효한 변수를 사용하면 됩니다.

1. BS2_GetFilteredLogSinceEventId 로그 가져오기 성능 개선이 되었습니다. C# 예제에도 적용이 되었습니다.

1. C# 예제에서 Util GetAll, Get Remove, Set의 Wrapper 함수 제작을 위한 Template 함수 추가가 되었습니다.

1. Linux에서 CPU 사용률 100%되는 이슈를 수정하였습니다.

1. C# 예제에서 BS2CardModelEnum{ODPW, OAPW} 추가가 되었습니다.

1. C# 예제에서 Util 공용 UnixTimeStamp 관련 변환 함수 UTC내용 수정 되었습니다.


---

# 2.4.0 버전

날짜 2017-3-24

:::warning

**주의 사항**

BioStar 2 Device SDK v2.4 에서 추가된 새로운 함수들은 2.4 펌웨어 그룹에서만 지원됩니다. 아래 목록에서 새로운 함수들을 사용할 수 있는 펌웨어 버전을 확인하십시오.

<text size="large"\>v2.4용 신규 함수\</text\>

* [BS2_EnrolUserEx](bs2_enroluserex) 함수가 추가되었습니다.

- [BS2_GetUserInfosEx](bs2_getuserinfosex) 함수가 추가되었습니다.

- [BS2UserBlobEx](user_management_api#bs2userblobex) 구조체가 추가되었습니다.

- [ssl api](ssl_api)가 추가되었습니다.

<text size="large"\>v2.4 펌웨어 그룹\</text\>

| 장치명 | 펌웨어 버전 |
| --- | --- |
| BioStation 2 | 1.4.0 |
| BioStation A2 | 1.3.0 |
| BioStation L2 | 1.2.0 |
| BioEntry W2 | 1.1.0 |

:::

<text size="x-large"\>신규 기능\</text\> \1. 신규 장치인 엘레베이터 컨트롤러 OM-120이 출시되었습니다. 해당 장치를 SDK 고객의 시스템에 통합할 수 있도록 신규 API 와 구조체가 추가되었습니다.

* [lift control api](lift_control_api) 가 추가되었습니다.

OM-120은 Lift에 사용할 수있는 12 개의 Relay를 제어 할 수있는 새로운 장치입니다. 이제는 door와 똑같이 작동하는 새로운 개념의 floor가 있습니다. 사용자가 인증되면 OM-120의 릴레이에 연결된 층은 Access group의 floor level에 따라 활성화됩니다. floor level은 Access level과 동일한 개념이며 둘 다 액세스 그룹에 할당됩니다.

1. 새로운 FaceStation 2는 2017 년 2 분기에 출시 될 예정입니다. v2.4는 FaceStation 2를 출시 이후 바로 사용될 수 있도록 모든 기능을 구현했습니7다.

* [face api](face_api) 가 추가되었습니다.

FaceStation 2는 1:N Matching에 최대 5,000 명의 사용자를 사용할 수 있는 그룹 매칭 기능을 지원합니다. 사용자는 자신이 속한 그룹을 선택한 뒤 얼굴 매칭할 수 있습니다.

1. 특정 장치는 카드의 v1 Template과 호환됩니다. v1 및 v2 장치가 함께 사용되는 곳에서 호환되지 않는 단점이 있었지만, 이제 v1 장치에서 미리 발급 된 카드를 읽을 수 있습니다.

* 구조체 [BS1CardConfig](configuration_api#bs1cardconfig) 가 추가되었습니다. v1 장치에서 발행된 ToC(Template on Card)가 v2 장치에서 읽을 수 있도록 설정되었습니다. v2 장치는 시작 block index가 카드의 v1 장치의 CIS index block과 동일하게 설정되어야 합니다. v1 ToC와 v2 Access on Card/Secure Credential Card를 함께 사용하기 위해서는,동일한 시작 block index와 CIS index block를 사용해야 합니다.

1. T&A SW와의 연동성을 위해 Job Code가 추가되었습니다. Job Code를 사용자에게 할당하고 로그에서 Job Code 정보를 얻을 수 있습니다. 이 기능은 v2.4 FW 그룹에만 포함됩니다.

* 구조체 [BS2UserBlobEx](user_management_api#bs2userblobex) 가 추가되었습니다. 기존 [BS2UserBlob](user_management_api#bs2userblob) 구조체 크기 제한으로 인해 새로운 기능 구현을 위한 새로운 구조체를 만들어야했습니다. 새로운 [BS2UserBlobEx](user_management_api#bs2userblobex) 구조체는 Job Code 필드를 포함하는 v2.4 FW 그룹에서만 동작합니다. 각 사용자는 각 Job Code에 대해 고유 코드 및 이름을 갖습니다.

1. 로그를 검색하는 새로운 방법이 추가되었습니다.

* 함수 [BS2_GetLogBlob](bs2_getlogblob) 가 추가되었습니다.

- 구조체 [BS2EventBlob](log_management_api#bs2eventblob) 가 추가되었습니다.

기존 API [BS2_GetLog](bs2_getlog)는 Job Code를 포함한 로그를 가져올 수 없었습니다. 이제 이벤트 blob을 가져 오는 새로운 API가 있습니다. 이벤트 blob는 마스크 값을 사용하여 분류할 수 있으며 로그의 유형에 따라 로그를 가져올 수 있습니다.

1. 개인 메시지는 특정 장치에 한해 다음 버전 FW에서 지원됩니다. 출시되면 사용할 수 있도록 구현되었습니다.

* 구조체 [BS2UserBlobEx](user_management_api#bs2userblobex) 가 추가되었습니다. 이 기능은 FaceStation 2부터 지원됩니다. 디스플레이 화면이 있는 나머지 장치는 향후 릴리스에서이 기능을 지원합니다.

기존 [BS2UserBlobEx](user_management_api#bs2userblobex) 구조체의 크기 제한으로 인해 새로운 기능을 구현하기 위한 새로운 구조체를 만들어야했습니다. 새로운 [BS2UserBlobEx](user_management_api#bs2userblobex) 구조체는 개인 메시지 필드를 포함하는 v2.4 FW 그룹에서만 작동합니다.

1. SSL 통신은 서버와 장치간에 사용 가능합니다. SSL 통신 사용 시, 장치가 인증서가 유효한 서버에만 연결될 수 있습니다.

* [ssl api](ssl_api) 가 추가되었습니다.

<text size="x-large"\>변경 사항\</text\>

1. 파라미터 \<text type="success"\>**outQuality**\</text\> 가 [BS2_ScanFingerprint](bs2_scanfingerprint) API 에 추가되었습니다.

   [BS2_ScanFingerprint](bs2_scanfingerprint) API에 스캔된 지문의 품질 점수를 반환하는 새로운 매개 변수가 추가되었습니다. 이것은 지문 템플릿 관리를보다 효율적으로 수행 할 수 있도록 적절한 피드백을 제공하기 위해 추가되었습니다.

   **변경 전**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, OnReadyToScan ptrReadyToScan);
```

**변경 후**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, uint32_t* outQuality, OnReadyToScan ptrReadyToScan);
```

1. 필드 \<text type="success"\>**useJobCode, useAlphanumericID, cameraFrequency**\</text\> 가 구조체 [BS2SystemConfig](Configuration_API#bs2systemconfig) 에 추가되었습니다.

   <text type="success"\>**useJobCode**\</text\> 필드는 Job Code 사용 Enable/Disable 설정을 위해 추가되었습니다.

   영문 ID는 이미 BioStation 2, BioStation A2, BioStation L2 및 BioEntry W2와 같은 특정 장치에서 가능했었습니다. 그러나 디스플레이 화면이 있는 장치는 ID + Credential 인증을 위한 키패드가 지원되지 않았습니다. v2.4 FW 그룹부터 디스플레이 화면이 있는 장치는 \<text type="success"\>**useAlphanumericID**\</text\> 필드의 값을 변경하고 사용자가 인증을 위해 영문 ID를 입력 할 수있게합니다.

   카메라 주파수는 \<text type="success"\>**cameraFrequency**\</text\> 필드를 사용하여 BioStation A2 장치에서 변경할 수 있습니다.

1. 파라미터 \<text type="success"\>**rs485mode, sslSupported, rootCertExist, dualIDSupported, useAlphanumericID, connectedIP, phraseCodeSupported, card1xSupported, systemExtSupported, voipSupported**\</text\> 가 구조체 [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) 에 추가되었습니다.

   구조체 [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) 에는 장치 지원여부 및 상황을 나타내는 추가적인 필드가 있습니다.

* \<text type="success"\>**rs485mode**\</text\>는 장치의 RS-485 모드를 결정하는 필드입니다.

* \<text type="success"\>**sslSupported**\</text\>는 장치가 SSL 연결을 지원하는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**rootCertExist**\</text\>는 장치에 루트 인증서가 있는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**dualIDSupported**\</text\>는 장치가 Dual ID를 지원하는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**useAlphanumericID**\</text\>는 장치가 영문 ID를 지원하는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**connectedIP**\</text\> 는 장치가 연결된 서버의 IP 주소를 결정하는 필드입니다.

* \<text type="success"\>**phraseCodeSupported**\</text\> 는 장치가 개인 메시지를 지원하는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**card1xSupported**\</text\> 는 장치가 v1 ToC 카드를 지원하는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**systemExtSupported**\</text\> 는 장치가 RS-485 마스터 키를 설정할 수 있는지 여부를 나타내는 필드입니다.

* \<text type="success"\>**voipSupported**\</text\> 장치가 VoIP를 지원하는지 여부를 나타내는 필드입니다.

<text size="x-large"\>수정된 버그\</text\>

1. UDP 패킷 페이로드 크기가 v2.4 FW 부터 변경되었습니다. SDK는 이전 펌웨어와 새 펌웨어의 페이로드 크기를 모두 지원하도록 수정되었습니다.

1. [BS2_GetConfig](bs2_getconfig)의 모든 마스크가 제대로 작동하지 않았습니다. 이것은 버퍼 크기가 추가된 구조체 [BS2MultiWiegandConfig](Configuration_API#bs2multiwiegandconfig) 보다 작게 설정 되었기 때문에 발생했습니다. 이제 버퍼 크기가 증가하여 모든 마스크가 제대로 작동합니다.

1. BioEntry Plus와 BioEntry W는 다중 wiegand 기능을 사용할 수 있었지만 SDK에서는 제외되었습니다. 이제 이 장치들도 여러 wiegand 기능을 사용하여 작동 할 수 있습니다.


---

# 2.3.1.b 버전

날짜 2016-11-24

수정된 버그 \1. 최대 64대의 장치만 연결할 수 있는 버그가 수정되었습니다. 최대 1024대까지 연결 가능합니다.

1.BioStar 2 Device SKD C# 예제 프로그램의 SFEnum.cs 파일에 존재하던 \<text type="success"\>**BS2APBZoneReaderTypeEnum**\</text\> 이 실제 사용되는 값과 일치되지 않아 실제 값에 맞게 변경되었습니다.

| Enum | 변경 전 | 변경 후 |
| --- | --- | --- |
| BS2_APB_ZONE_READER_NONE | 0 | -1 |
| BS2_APB_ZONE_READER_ENTRY | 1 | 0 |
| BS2_APB_ZONE_READER_EXIT | 2 | 1 |

1.\<text type="success"\>**BS2_ReadImageLog**\</text\> 함수가 16kB가 넘는 이미지를 처리하지 못하는 버그가 수정되었습니다. 이제는 SDK 에서 16kB가 넘는 이미지 로그를 문제 없이 처리할 수 있습니다.


---

# 2.3 버전

날짜 2016-08-03

새로운 기능

- Multi Wiegand Format 지원

- BioEntry W2 지원

추가 및 변경된 기능

1. 새로운 멀티 위겐드 기능이 추가되었습니다. 이제 한 장치로 여러 포맷을 사용할 수 있게 되었습니다. 만약 장치에서 여러 종류의 카드를 지원한다면, 여러 포맷을 다양한 카드 종류에 적용할 수 있습니다. 최대 15개의 포맷까지 설정할 수 있습니다.

- 함수 [BS2_GetWiegandMultiConfig](bs2_getwiegandmulticonfig) 추가

- 함수 [BS2_SetWiegandMultiConfig](bs2_setwiegandmulticonfig) 추가

- 구조체 [BS2WiegandMultiConfig](Configuration_API#bs2wiegandmulticonfig) 추가

1. 필드 \<text type="success"\>**wiegandMultiSupported**\</text\>가 [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo)구조체에 추가되었습니다.

   [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) 구조체는 해당 장치에서 특정 기능의 지원 여부를 나타내기 위해 사용됩니다. 멀티 위겐드 기능이 추가됨으로써, 해당 기능의 지원 여부를 나타내기 위한 필드가 추가되었습니다.

1. 마스크 \<text type="success"\>**0x0D**\</text\>(BioEntry W2) 값이 [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) 구조체에 추가 되었습니다.

   [BS2SimpleDeviceInfo](Device_API#bs2simpledeviceinfo) 구조체는 장치의 간략한 정보를 나타내기 위해 사용됩니다. 이번 SDK 버전에서부터 신규 출시된 BioEntry W2 가 지원되며, 이를 나타내기 위해 마스크값이 추가되었습니다.

1. \<text type="success"\>**IsAcceptableUserID**\</text\> 파라미터가 [BS2_GetUserList](bs2_getuserlist) 함수에 추가되었습니다.

   이 콜백함수는 BioStar 2 Device SDK를 이용하여 개발하는 개발자들에게는 아무런 관련이 없습니다. 이 필드는 BioStar v1.91 에서만 사용되며 BioStar v1.91 은 최신 장치들인 BioStation 2, BioStation A2, BioStation L2, BioEntry W2 를 지원할 수 있도록 BioStar 2 Device SDK 를 인테그레이션한 버전입니다. BioStar 1에서 사용자 ID의 최대값은 4294967295이지만 2세대 장치들은 최대 32 자리의 ID를 가질 수 있도록 설계되었습니다. 장치에서 BioStar 1 서버로 기존 BioStar 1의 최대 사용자 ID를 넘어가는 값을 전송하지 못하도록 막기 위해 해당 파라미터가 추가되었습니다.

   **변경 전**

```cpp
#include "BS_API.h"

int BS2_GetUserList(void* context, uint32_t deviceId, char** uidsObjs, uint32_t* numUid);
```

**변경 후**

```cpp
#include "BS_API.h"

int BS2_GetUserList(void* context, uint32_t deviceId, char** uidsObjs, uint32_t* numUid, IsAcceptableUserID ptrIsAcceptableUserID);
```

**예제**

```cpp

BS2_GetUserList(context, deviceId, uidsObjs, numUid, null);
```

1. 함수 [BS2_GetLastFingerprintImage](bs2_getlastfingerprintimage) 가 추가되었습니다.

   지문의 실제 이미지를 취득할 수 있는 함수가 추가되었습니다. 해당 함수는 기존의 BioStar 2 에서 존재하는 기능을 제공하기 위해 추가되었습니다. 이 함수를 이용하여 지문 템플릿의 상태가 아닌 실제 지문의 상태를 확인할 수 있습니다. 그러나, 이 함수로 취득하는 이미지는 실제 매칭에 사용되지 않습니다.

   1.\<text type="success"\>**templateFormat**\</text\> 파라미터가 [BS2_ScanFingerprint](bs2_scanfingerprint) 함수에 추가되었습니다.

   슈프리마의 지문 단말기들은 슈프리마 템플릿, ISO 19794-2, 그리고 ANSI 384 총 3종류의 템플릿을 지원합니다. 

   | 값 | 설명 |
   | --- | --- |
   | 0 | Suprema Template |
   | 1 | ISO19794-2 |
   | 2 | ANSI-378 |

   **변경 전**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, OnReadyToScan ptrReadyToScan);
```

**변경 후**

```cpp
#include "BS_API.h"

int BS2_ScanFingerprint(void* context, uint32_t deviceId, BS2Fingerprint* finger, uint32_t templateIndex, uint32_t quality, uint8_t templateFormat, OnReadyToScan ptrReadyToScan);
```

1.\<text type="success"\>**wiegandMultiConfig**\</text\>필드가 [BS2Configs](Configuration_API#bs2configs) 구조체에 추가되었습니다.

설정과 관련된 모든 구조체들은 [BS2Configs](Configuration_API#bs2configs) 구조체로 관리할 수 있습니다. 멀티 위겐드를 위한 새로운 구조체가 추가되었기 때문에, [BS2Configs](Configuration_API#bs2configs) 구조체에 해당 구조체가 추가되었습니다.

1. \<text type="success"\>**wiegandInputMask**\</text\>필드가 [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) 구조체에 추가되었습니다.

   멀티 위겐드 기능이 추가되면서, 어떠한 포맷이 사용될 것인지에 대해 나타낼 수 있는 마스크 값이 필요해졌습니다. 이 필드는 마스터 장치가 위겐드 카드 리더기나 RS-485를 통해 연결된 슬레이브 장치에서 보내지는 카드 데이터 중 처리를 해야 하는 포맷들을 나타냅니다. 이 필드는 장치가 위겐드 신호를 받아들이도록 설정되었을 때 사용 가능합니다. 예를 들어, 포맷 인덱스 0번, 2번, 6번을 사용하고 싶다면, 마스크 값을 0000000010001010로 설정하면 됩니다. 0번째 비트는 하위호환을 위해 따로 잡아둔 비트입니다.

   1.\<text type="success"\>**wiegandCardMask**\</text\> 필드가 [BS2WiegandConfig](Configuration_API#bs2wiegandconfig)구조체에 추가되었습니다.

   멀티 위겐드 기능이 추가되면서, 어떠한 포맷이 사용될 것인지에 대해 나타낼 수 있는 마스크 값이 필요해졌습니다. 이 필드는 장치에 직접 카드를 읽혔을 때 장치가 처리를 해야 하는 포맷들을 나타냅니다. 이 필드는 장치가 위겐드 신호를 내보내도록 설정되었을 때 사용 가능합니다. 예를 들어, 포맷 인덱스 0번, 1번, 2번, 3번을 사용하고 싶다면, 마스크 값을 0000000000011110로 설정하면 됩니다. 0번째 비트는 하위호환을 위해 따로 잡아둔 비트입니다.

   1.\<text type="success"\>**wiegandCSNIndex**\</text\>필드가 [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) 구조체에 추가되었습니다.

   카드의 CSN 만 사용한다고 해도, 여전히 특정 포맷으로 위겐드 값을 내보낼 수 있습니다. 이 필드는 Mifare 나 EM 카드 같은 카드의 CSN을 사용하지만, 여전히 위겐드 신호를 내보내야하는 경우에 사용할 수 있습니다. 예를 들어, 인증했을 때 CSN 카드의 값을 포맷 인덱스 0번의 포맷으로 내보내고 싶을 경우, 값을 0으로 설정하면 됩니다. 해당 기능은 하나의 포맷만 설정할 수 있습니다.

   1.[BS2WiegandConfig](Configuration_API#bs2wiegandconfig) 구조체의 \<text type="success"\>**reserved**\</text\> 필드가 \<text type="success"\>**uint8_t reserved\[27\]**\</text\> 에서 \<text type="success"\>**uint8_t reserved\[32\]**\</text\> 으로 변경되었습니다.

   [BS2WiegandConfig](Configuration_API#bs2wiegandconfig) 구조체에 위에서 언급된 필드 3개가 더 추가 되었습니다. 이로 인해 reserved 에서 5바이트를 사용하게 되었습니다.

   1.[BS2Door](Door_Control_API#bs2door) 구조체의 \<text type="success"\>**alarmFlags**\</text\>필드가 \<text type="success"\>**uint8_t alarmFlags**\</text\>에서 \<text type="success"\>**uint8_t unconditionalLock**\</text\>로 변경되었습니다.

   <text type="success"\>**alarmFlags**\</text\> 필드는 [BS2Door](Door_Control_API#bs2door) 구조체에서 사용되지 않습니다. 그 대신, \<text type="success"\>**unconditionalLock**\</text\> 필드가 새로운 기능을 지원하기 위해 추가되었으며, 기존 \<text type="success"\>**alarmFlags**\</text\>의 메모리를 그대로 사용합니다. \<text type="success"\>**unconditionalLock**\</text\> 자동문을 효율적으로 제어하기 위해 추가되었습니다. 일반적인 데드볼트형의 락을 사용할때는 설정해놓은 문열림 시간이 지나도 문이 닫히기 전에 락이 잠금이 되면 안 됩니다. 하지만 자동계폐식 문을 사용할때는, 문이 열려있다고 해도 설정해놓은 시간이 지나면 락이 잠겨야 합니다. 이 필드의 값을 변경하면 문열림 시간이 지나면 바로 문이 닫히게끔 설정할 수 있습니다.


---

# 2.2 버전

날짜 2016-01-31

새로운 기능

- 출입 통제 API

- 휴일 그룹 설정

- 블랙리스트

- 이미지 로그

- 펌웨어 업그레이드

- 리소스 업데이트

- 출입문 제어

- Wiegand card reader의 외부 신호 지원

- 장치 초기화 기능

- Notification 지원

- Smart card 지원(MIFARE, iClass, DesFire)

- 서버 매칭 지원

- Server URL 지원

- Trigger action 설정

- 무선랜 설정

- 안티패스백 구역, 시간 지정 안티패스백 구역, 화재 경보 구역, 스케줄 잠금/개방 구역 설정


---

# 2.1 버전

날짜 2015-08-26

새로운 기능

- 실시간 로그 지원

- Wiegand 입출력 설정


---

# 2.0 버전

날짜 2015-07-06

새로운 기능

- x86, x64 플랫폼 지원

- Suprema 네임스페이스 사용

- 기존 suprema.cs를 SFEnum.cs, SFStruct.cs, SFApi.cs으로 세분화

- 직접 연결 및 UDP 검색

- 설정 정보 읽기(펌웨어, 시스템, 인증, 화면, 네트워크, 카드, 지문, 근태)

- 사용자 목록 불러오기 / 삭제 / 추가

- 지문 및 카드 등록 가능

- 로그 가져오기 / 필터링 / 삭제

- 사용자 목록이나 전체 로그를 가져올 때 취소 가능


---
