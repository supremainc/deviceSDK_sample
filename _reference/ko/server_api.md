# Server API

서버 매칭를 사용하거나, BioStar 애플리케이션에서 단말기를 직접 제어할 수 있습니다.

:::warning

**주의 사항**

독립된 별도의 법인에서 제공하는 UFMatcher.dll의 관리문제로, 더 이상 실행가능한 예제를 제공하지 않습니다.

기존의 예제는 코드 레벨에서의 참조만 부탁드립니다.

서버 매칭용 지문 library를 포함한, 기타 기술지원은 Xperix를 통해 제공받으실 수 있습니다.

<wrap hi\>Xperix : <https://www.xperix.com/>**

:::

- [BS2_SetServerMatchingHandler](bs2_setservermatchinghandler): 서버 매칭 핸들러를 등록합니다.

- [BS2_VerifyUser](bs2_verifyuser): 카드나 User ID의 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_IdentifyUser](bs2_identifyuser): 지문 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_VerifyUserEx](bs2_verifyuserex): <Badge only>+ v2.4.0</Badge> 카드나 User ID의 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_IdentifyUserEx](bs2_identifyuserex): <Badge only>+ v2.4.0</Badge> 지문 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_VerifyUserSmall](bs2_verifyusersmall): <Badge only>+ v2.6.3</Badge> 카드나 User ID의 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_IdentifyUserSmall](bs2_identifyusersmall): <Badge only>+ v2.6.3</Badge> 지문 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_VerifyUserSmallEx](bs2_verifyusersmallex): <Badge only>+ v2.6.3</Badge> 카드나 User ID의 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_IdentifyUserSmallEx](bs2_identifyusersmallex): <Badge only>+ v2.6.3</Badge> 지문 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_VerifyUserFaceEx](bs2_verifyuserfaceex): <Badge only>+ v2.7.2</Badge> 카드나 User ID의 인증 결과와 맵핑된 유저 정보를 단말기로 전송합니다.

- [BS2_SetUserPhraseHandler](bs2_setuserphrasehandler): <Badge only>+ v2.7.0</Badge> 서버요청 개인 메시지 핸들러를 등록합니다.

- [BS2_ResponseUserPhrase](bs2_responseuserphrase): <Badge only>+ v2.7.0</Badge> 개인 메시지를 단말기로 전송합니다.

- [BS2_SetBarcodeScanListener](bs2_setbarcodescanlistener): <Badge only>+ v2.8.2</Badge> Barcode 입력을 감지하는 listener 함수를 등록합니다.

- [BS2_SetOsdpStandardDeviceStatusListener](bs2_setosdpstandarddevicestatuslistener): <Badge only>+ v2.9.1</Badge> OSDP 장치의 상태변화를 감지하는 listener 함수를 등록합니다.

## 콜백함수

```cpp
typedef void (*OnVerifyUser)(uint32_t deviceId, uint16_t seq, uint8_t isCard, uint8_t cardType, const uint8_t* data, uint32_t dataLen);
typedef void (*OnIdentifyUser)(uint32_t deviceId, uint16_t seq, uint8_t format, const uint8_t* templateData, uint32_t templateSize);
```

1. `OnVerifyUser`

   장치에서 Card나, User ID가 일치하는지를 BioStar 애플리케이션에서 판별해야 할 때 호출되는 콜백 함수입니다.

1. `OnIdentifyUser`

   장치에서 지문이 일치하는지를 BioStar 애플리케이션에서 판별해야 할 때 호출되는 콜백 함수입니다.

### OnUserPhrase

개인 메시지를 서버에 요청하는 콜백 함수입니다.

```cpp
typedef void (*OnUserPhrase)(uint32_t deviceId, uint16_t seq, const char* userID);
```

1. `deviceId`

   장치 식별자입니다.

1. `seq`

   패킷 일련번호입니다.

1. `userID`

   사용자 ID 입니다.

### OnBarcodeScanned

장치에서 barcode가 scan 되었을 때 호출되는 콜백 함수입니다.

```cpp
typedef void (*OnBarcodeScanned)(uint32_t deviceId, const char* barcode);
```

1. `deviceId`

   읽혀진 barcode를 보내준 장치 ID입니다.

1. `barcode`

   장치로부터 읽혀진 barcode 문자열입니다.

### OnOsdpStandardDeviceStatusChanged

OSDP 장치의 상태가 변화되었을 때 호출되는 콜백 함수입니다.

```cpp
typedef void (*OnOsdpStandardDeviceStatusChanged)(uint32_t deviceId, const BS2OsdpStandardDeviceNotify* notifyData);
```

1. `deviceId`

   OSDP 장치 식별자입니다.

1. `notifyData`

   OSDP 장치 정보입니다.
