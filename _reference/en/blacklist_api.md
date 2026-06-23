# Blacklist API

API that adds a card to the blacklist when a card is lost or to limit access.

- [BS2_GetBlackList](bs2_getblacklist): Retrieves selected blacklists.

- [BS2_GetAllBlackList](bs2_getallblacklist): Retrieves all blacklists.

- [BS2_SetBlackList](bs2_setblacklist): Configures a blacklist.

- [BS2_RemoveBlackList](bs2_removeblacklist): Removes selected blacklists.

- [BS2_RemoveAllBlackList](bs2_removeallblacklist): Removes all blacklists.

## Structure

### BS2BlackList

```cpp
typedef struct {
    uint8_t cardID[BS2_CARD_DATA_SIZE];
    uint16_t issueCount;
} BS2BlackList;
```

1. `cardID`

   Card ID.

1. `issueCount`

   Number of the issue count of a card. CSN cards are always set as 0, and smart cards will have the issue count that is written on the card.