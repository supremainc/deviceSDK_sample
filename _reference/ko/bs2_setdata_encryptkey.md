<Badge only>+ v2.7.1</Badge> 사용자의 PIN 코드 암호화 키 값을 변경합니다.

기기의 PIN 암호화 키가 설정하려는 키와 동일한 경우, 변경 사항은 무시됩니다.

또한, 기기의 PIN 암호화 키가 설정하려는 키와 다른 경우, 변경된 키로 설정되고 기기에 저장된 모든 사용자 정보가 삭제됩니다.

**주의사항**

PIN 암호화 키를 변경하면 변경된 사용자 정의 키를 사용하는 기기의 모든 사용자 정보가 삭제됩니다.

사용자는 [BS2_EnrolUser](bs2_enroluser)와 같은 함수를 통해 기기에 다시 추가해야 합니다.

[BS2_MakePinCode](bs2_makepincode) 함수는 기본 키 값을 사용하여 사용자 PIN 코드를 암호화합니다.

PIN 암호화 키가 사용자 정의 값으로 변경된 경우 [BS2_MakePinCodeWithKey](bs2_makepincodewithkey)를 호출하여 사용자에게 다시 할당해야 합니다.

### 선언

```cpp
#include "BS_API.h"

int BS2_SetDataEncryptKey(void* context, uint32_t deviceId, const BS2EncryptKey* keyInfo);
```

:::info

 [View the structure of the BS2EncryptKey](sdk_api#BS2EncryptKey)

:::

### 파라미터

- \[In\] `context` : Context

- \[In\] `deviceId` : Device Identifier

- \[In\] `keyInfo` : The address of the key information structure to be set

### 반환값

Returns `BS_SDK_SUCCESS` if performed successfully, or a corresponding error code if an error occurs.

### 함께 보기

[BS2_MakePinCodeWithKey](bs2_makepincodewithkey)

[BS2_RemoveDataEncryptKey](bs2_removedataencryptkey)
