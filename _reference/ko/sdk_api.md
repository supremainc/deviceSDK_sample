# SDK API

장치를 관리하는 정보를 초기화 하고, 동적 메모리 제어와 PIN 생성을 위해 사용되는 API입니다.

* [BS2_Version](bs2_version): SDK 버전을 반환합니다.

- [BS2_AllocateContext](bs2_allocatecontext): 장치 관리 Context를 생성합니다.

- [BS2_ReleaseContext](bs2_releasecontext): 장치 관리 Context를 파괴합니다.

- [BS2_Initialize](bs2_initialize): 장치 관리 Context를 초기화 합니다.

- [BS2_ReleaseObject](bs2_releaseobject): 동적 메모리를 해제합니다.

- [BS2_MakePinCode](bs2_makepincode): PIN으로 암호화 합니다.

- [BS2_MakePinCodeWithKey](bs2_makepincodewithkey): 사용자 정의 PIN 암호화 키를 이용하여 암호화 합니다. <Badge only>+ v2.7.1</Badge>

- [BS2_SetMaxThreadCount](bs2_setmaxthreadcount): 최대 스레드 개수를 지정합니다.

- [BS2_ComputeCRC16CCITT](bs2_computecrc16ccitt): CRC-16 CCITT 체크섬을 계산합니다.

- [BS2_GetCardModel](bs2_getcardmodel): 지원하는 카드 모델을 가져옵니다.

- [BS2_SetDataEncryptKey](bs2_setdataencryptkey): 사용자의 PIN 코드 암호화 키 값을 변경 합니다. <Badge only>+ v2.7.1</Badge>

- [BS2_RemoveDataEncryptKey](bs2_removedataencryptkey): 장치의 데이터 암호화 키를 삭제합니다.

- [BS2_SetDeviceSearchingTimeout](bs2_setdevicesearchingtimeout): 장치 검색 시간을 설정합니다.

- [BS2_SetDebugFileLog](bs2_setdebugfilelog): 디버깅용 파일로그를 지정합니다.

- [BS2_SetDebugFileLogEx](bs2_setdebugfilelogex): 디버깅용 파일로그를 지정합니다. (파일 분할 가능) <Badge only>+ v2.8.3</Badge>

- [BS2_EnableDeviceLicense](bs2_enabledevicelicense): <Badge only>+ v2.9.1</Badge> 장치 라이선스를 활성화 시킵니다.

- [BS2_DisableDeviceLicense](bs2_disabledevicelicense): <Badge only>+ v2.9.1</Badge> 장치 라이선스를 비활성화 시킵니다.

- [BS2_QueryDeviceLicense](bs2_querydevicelicense): <Badge only>+ v2.9.1</Badge> 장치 라이선스 정보를 확인합니다.

- [BS2_InitializeEx](bs2_initializeex): <Badge only>+ v2.9.6</Badge> 장치 관리 Context를 초기화 합니다.

## 구조체

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

   장치에서 사용되는 키 값입니다.

1. `reserved`

   예약된 영역입니다.

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

   라이선스의 종류를 나타냅니다.

   | 값 | 설명 |
   | --- | --- |
   | 0x0000 | None |
   | 0x0001 | Visual QR |

1. `numOfDevices`

   라이선스 활성화 장치의 갯수입니다.

1. `deviceIDObjs`

   라이선스 정보가 내려질 slave 장치들입니다.

1. `licenseLen`

   라이선스 활성화 파일의 크기입니다.

1. `licenseObj`

   라이선스 활성화 데이터 블록입니다.

### BS2LicenseResult

```cpp
typedef struct {
    BS2_DEVICE_ID       deviceID;
    BS2_LICENSE_STATUS  status;
} BS2LicenseResult;
```

1. `deviceID`

   장치 식별자입니다.

1. `status`

   라이선스 상태 정보입니다.

   | 값 | 설명 |
   | --- | --- |
   | 0 | Not supported (지원 안함) |
   | 1 | Disable (꺼짐) |
   | 2 | Enable (켜짐) |
   | 3 | Expired (만료됨) |
