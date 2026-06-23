# Blacklist API

BioStar 시스템에서는 분실된 카드나, 접근을 제한하고자 할 때 출입 인증 장치에 블랙리스트 카드를 추가할 수 있습니다.

- [BS2_GetBlackList](bs2_getblacklist): 주어진 블랙리스트를 가져옵니다.

- [BS2_GetAllBlackList](bs2_getallblacklist): 모든 블랙리스트를 가져옵니다.

- [BS2_SetBlackList](bs2_setblacklist): 블랙리스트를 설정합니다.

- [BS2_RemoveBlackList](bs2_removeblacklist): 주어진 블랙리스트를 제거합니다.

- [BS2_RemoveAllBlackList](bs2_removeallblacklist): 모든 블랙리스트를 제거합니다.

## 구조체

### BS2BlackList

```cpp
typedef struct {
    uint8_t cardID[BS2_CARD_DATA_SIZE];
    uint16_t issueCount;
} BS2BlackList;
```

1. `cardID`

   카드 식별자입니다.

1. `issueCount`

   카드 발급 회차로 CSN card는 항상 0이고, 스마트 카드는 카드에 쓴 발급 회차이다.