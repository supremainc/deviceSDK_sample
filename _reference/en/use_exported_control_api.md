# USB Exported Control API

This API allows to control/manage USB Exported.

- [BS2_AllocateUsbContext](bs2_allocateusbcontext): `[Depredated]`Allocates context which manages & controls USB device.

- [BS2_ReleaseUsbContext](bs2_releaseusbcontext): `[Depredated]`Releases context which manages & controls USB device.

- [BS2_GetUserDatabaseInfoFromDir](bs2_getuserdatabaseinfofromdir): Gets total user information(Number of user/card/fingerprint/face) from USB exported data.

- [BS2_GetUserListFromDir](bs2_getuserlistfromdir): Gets the enrolled user ID list from USB exported data.

- [BS2_GetUserInfosFromDir](bs2_getuserinfosfromdir): Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserDatasFromDir](bs2_getuserdatasfromdir): Gets the user information of the given user ID & usermask from USB exported data.

- [BS2_GetUserInfosExFromDir](bs2_getuserinfosexfromdir): Gets the user information of the given user ID from USB exported data. (Including Job, phrase)

- [BS2_GetUserDatasExFromDir](bs2_getuserdatasexfromdir): Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)

- [BS2_GetUserSmallInfosFromDir](bs2_getusersmallinfosfromdir): <Badge only>+ v2.6.3</Badge> Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserSmallDatasFromDir](bs2_getusersmalldatasfromdir): <Badge only>+ v2.6.3</Badge> Gets the user information of the given user ID & usermask from USB exported data.

- [BS2_GetUserSmallInfosExFromDir](bs2_getusersmallinfosexfromdir): <Badge only>+ v2.6.3</Badge> Gets the user information of the given user ID from USB exported data. (Including Job, phrase)

- [BS2_GetUserSmallDatasExFromDir](bs2_getusersmalldatasexfromdir): <Badge only>+ v2.6.3</Badge> Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)

- [BS2_GetLogFromDir](bs2_getlogfromdir): Gets certain amount of logs from USB exported data.

- [BS2_GetLogBlobFromDir](bs2_getlogblobfromdir): Gets certain amount of logs based on the event mask from USB exported data.

- [BS2_GetFilteredLogFromDir](bs2_getfilteredlogfromdir): Gets filtered logs from USB exported data.

- [BS2_GetLogSmallBlobFromDir](bs2_getlogsmallblobfromdir): <Badge only>+ v2.6.4</Badge> Gets certain amount of logs based on the event mask from USB exported data in an efficient way.

- [BS2_GetLogSmallBlobExFromDir](bs2_getlogsmallblobexfromdir): <Badge only>+ v2.7.1</Badge> Gets certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way.

- [BS2_GetUserInfosFaceExFromDir](bs2_getuserinfosfaceexfromdir): <Badge only>+ v2.7.1</Badge> Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserDatasFaceExFromDir](bs2_getuserdatasfaceexfromdir): <Badge only>+ v2.7.1</Badge> Gets the user information of the given user ID & usermask from USB exported data.

<Badge only>+ v2.8.2</Badge> API for managing USB Exported.

Key user-related sensitive information is stored encrypted with predefined key values within the device. If you have changed the user information encryption key of the device using the [BS2_SetDataEncryptKey](bs2_setdataencryptkey) function, you must pass the value of the key to use the USB-related API.

- [BS2_GetUserDatabaseInfoFromDirWithKey](bs2_getuserdatabaseinfofromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets total user information(Number of user/card/fingerprint/face) from USB exported data.

- [BS2_GetUserListFromDirWithKey](bs2_getuserlistfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the enrolled user ID list from USB exported data.

- [BS2_GetUserInfosFromDirWithKey](bs2_getuserinfosfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserDatasFromDirWithKey](bs2_getuserdatasfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID & usermask from USB exported data.

- [BS2_GetUserInfosExFromDirWithKey](bs2_getuserinfosexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID from USB exported data. (Including Job, phrase)

- [BS2_GetUserDatasExFromDirWithKey](bs2_getuserdatasexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)

- [BS2_GetUserSmallInfosFromDirWithKey](bs2_getusersmallinfosfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserSmallDatasFromDirWithKey](bs2_getusersmalldatasfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID & usermask from USB exported data.

- [BS2_GetUserSmallInfosExFromDirWithKey](bs2_getusersmallinfosexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID from USB exported data. (Including Job, phrase)

- [BS2_GetUserSmallDatasExFromDirWithKey](bs2_getusersmalldatasexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID & usermask from USB exported data. (Including Job, phrase)

- [BS2_GetLogFromDirWithKey](bs2_getlogfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets certain amount of logs from USB exported data.

- [BS2_GetLogBlobFromDirWithKey](bs2_getlogblobfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets certain amount of logs based on the event mask from USB exported data.

- [BS2_GetFilteredLogFromDirWithKey](bs2_getfilteredlogfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets filtered logs from USB exported data.

- [BS2_GetLogSmallBlobFromDirWithKey](bs2_getlogsmallblobfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets certain amount of logs based on the event mask from USB exported data in an efficient way.

- [BS2_GetLogSmallBlobExFromDirWithKey](bs2_getlogsmallblobexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way.

- [BS2_GetUserInfosFaceExFromDirWithKey](bs2_getuserinfosfaceexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID from USB exported data.

- [BS2_GetUserDatasFaceExFromDirWithKey](bs2_getuserdatasfaceexfromdirwithkey): <Badge only>+ v2.8.2</Badge> Gets the user information of the given user ID & usermask from USB exported data.
