The meaning of the return codes is shown below. To search your return code, press <kbd>Ctrl+F</kbd>.

| Code | Description |
| --- | --- |
| `BS_SDK_SUCCESS` | Success. |
| `BS_SDK_DURESS_SUCCESS` | Authenticated as duress fingerprint. |
| `BS_SDK_FIRST_AUTH_SUCCESS` | First user has been authenticated. |
| `BS_SDK_SECOND_AUTH_SUCCESS` | Second user has been authenticated. |
| `BS_SDK_DUAL_AUTH_SUCCESS` | Success on dual authentication. |
| `BS_SDK_WIEGAND_BYPASS_SUCCESS` | Success on Wiegand bypass. (Only FaceStation2) |
| `BS_SDK_ERROR_FROM_DEVICE_DRIVER` | Device driver error. |
| `BS_SDK_ERROR_CANNOT_OPEN_SOCKET` | Cannot create a socket. |
| `BS_SDK_ERROR_CANNOT_CONNECT_SOCKET` | Cannot connect to socket. |
| `BS_SDK_ERROR_CANNOT_LISTEN_SOCKET` | Cannot set socket to listen for connections. |
| `BS_SDK_ERROR_CANNOT_ACCEPT_SOCKET` | Cannot accept socket. |
| `BS_SDK_ERROR_CANNOT_READ_SOCKET` | Cannot read from socket. |
| `BS_SDK_ERROR_CANNOT_WRITE_SOCKET` | Cannot write on socket. |
| `BS_SDK_ERROR_SOCKET_IS_NOT_CONNECTED` | Not connected to socket. |
| `BS_SDK_ERROR_SOCKET_IS_NOT_OPEN` | Cannot use socket. |
| `BS_SDK_ERROR_SOCKET_IS_NOT_LISTENED` | Socket not set to listen. |
| `BS_SDK_ERROR_SOCKET_IN_PROGRESS` | Already in progress. |
| `BS_SDK_ERROR_INVALID_PARAM` | Invalid parameter. |
| `BS_SDK_ERROR_INVALID_PACKET` | Invalid packet. |
| `BS_SDK_ERROR_INVALID_DEVICE_ID` | Invalid device ID. |
| `BS_SDK_ERROR_INVALID_DEVICE_TYPE` | Invalid device type. |
| `BS_SDK_ERROR_PACKET_CHECKSUM` | Packet data's checksum is not correct. \\| \\|''BS_SDK_ERROR_PACKET_INDEX'' |
| `BS_SDK_ERROR_PACKET_COMMAND` | Invalid command. |
| `BS_SDK_ERROR_PACKET_SEQUENCE` | Packet sequence error due to unstable network connection. |
| `BS_SDK_ERROR_NO_PACKET` | Invalid packet. |
| `BS_SDK_ERROR_EXTRACTION_FAIL` | Cannot extract template data. |
| `BS_SDK_ERROR_VERIFY_FAIL` | Failed on 1:1 verification. |
| `BS_SDK_ERROR_IDENTIFY_FAIL` | Failed on 1:N identification. |
| `BS_SDK_ERROR_IDENTIFY_TIMEOUT` | Identification timeout. |
| `BS_SDK_ERROR_FINGERPRINT_CAPTURE_FAIL` | Cannot capture the fingerprint image. |
| `BS_SDK_ERROR_FINGERPRINT_SCAN_TIMEOUT` | Fingerprint scan timeout. |
| `BS_SDK_ERROR_FINGERPRINT_SCAN_CANCELLED` | Fingerprint can canceled. |
| `BS_SDK_ERROR_NOT_SAME_FINGERPRINT` | Not identical fingerprints. |
| `BS_SDK_ERROR_EXTRACTION_LOW_QUALITY` | Need more information of fingerprint minutiae. |
| `BS_SDK_ERROR_CAPTURE_LOW_QUALITY` | Low quality of captured fingerprint image. |
| `BS_SDK_ERROR_CANNOT_FIND_FINGERPRINT` | Fingerprint not registered. |
| `​BS_SDK_ERROR_FAKE_FINGER_DETECTED`​ | Fake finger detected. |
| `BS_SDK_ERROR_FAKE_FINGER_TRY_AGAIN` | Fake finger try again. |
| `BS_SDK_ERROR_FAKE_FINGER_SENSOR_ERROR` | Fake finger sensor error. |
| `BS_SDK_ERROR_CANNOT_FIND_FACE` | Cannot find face. |
| `BS_SDK_ERROR_FACE_CAPTURE_FAIL` | Face capture failed. |
| `BS_SDK_ERROR_FACE_SCAN_TIMEOUT` | Face scan timeout error. |
| `BS_SDK_ERROR_FACE_SCAN_CANCELLED` | Face scan cancelled. |
| `BS_SDK_ERROR_FACE_SCAN_FAILED` | Failed to face scan. (FaceStation2, FaceLite only) |
| `BS_SDK_ERROR_CANNOT_OPEN_DIR` | Cannot open directory. |
| `BS_SDK_ERROR_CANNOT_OPEN_FILE` | Cannot open file. |
| `BS_SDK_ERROR_CANNOT_WRITE_FILE` | Cannot write on file. |
| `BS_SDK_ERROR_CANNOT_SEEK_FILE` | Cannot seek file. |
| `BS_SDK_ERROR_CANNOT_READ_FILE` | Cannot read file. |
| `BS_SDK_ERROR_CANNOT_GET_STAT` | Cannot get file status. |
| `BS_SDK_ERROR_CANNOT_GET_SYSINFO` | Cannot get system information. |
| `BS_SDK_ERROR_DATA_MISMATCH` | Failed on data redundancy check. |
| `​BS_SDK_ERROR_INVALID_RELAY`​ | Invalid Relay. |
| `​BS_SDK_ERROR_CANNOT_WRITE_IO_PACKET`​ | Failed to write I/O packet. |
| `​BS_SDK_ERROR_CANNOT_READ_IO_PACKET`​ | Failed to read I/O packet. |
| `​BS_SDK_ERROR_CANNOT_READ_INPUT`​ | Cannot read input device. |
| `​BS_SDK_ERROR_READ_INPUT_TIMEOUT`​ | Timeout during reading the input device. |
| `​BS_SDK_ERROR_CANNOT_ENABLE_INPUT`​ | Cannot enable the input device. |
| `​BS_SDK_ERROR_CANNOT_SET_INPUT_DURATION`​ | Cannot set the duration of the input device. |
| `​BS_SDK_ERROR_INVALID_PORT`​ | Invalid port. |
| `​BS_SDK_ERROR_INVALID_INTERPHONE_TYPE`​ | Invalid intercom type. |
| `​BS_SDK_ERROR_INVALID_LCD_PARAM`​ | Invalid LCD parameter. |
| `​BS_SDK_ERROR_CANNOT_WRITE_LCD_PACKET`​ | Failed to write LCD packet. |
| `​BS_SDK_ERROR_CANNOT_READ_LCD_PACKET`​ | Failed to read LCD packet. |
| `​BS_SDK_ERROR_INVALID_LCD_PACKET`​ | Invalid LCD packet. |
| `​BS_SDK_ERROR_INPUT_QUEUE_FULL`​ | Not enough buffer space on input device. |
| `​BS_SDK_ERROR_WIEGAND_QUEUE_FULL`​ | Not enough input buffer space on wiegand device. |
| `​BS_SDK_ERROR_MISC_INPUT_QUEUE_FULL`​ | Not enough buffer space on miscellaneous device. |
| `​BS_SDK_ERROR_WIEGAND_DATA_QUEUE_FULL`​ | Not enough output buffer space on wiegand device. |
| `​BS_SDK_ERROR_WIEGAND_DATA_QUEUE_EMPTY`​ | Empty output data of wiegand device. |
| `BS_SDK_ERROR_NOT_SUPPORTED` | Not supported. |
| `BS_SDK_ERROR_TIMEOUT` | Timeout. |
| `BS_SDK_ERROR_INVALID_DATA_FILE` | Invalid data file. |
| `​BS_SDK_ERROR_TOO_LARGE_DATA_FOR_SLOT`​ | The data is larger than the slot. |
| `BS_SDK_ERROR_INVALID_SLOT_NO` | Invalid slot number. |
| `BS_SDK_ERROR_INVALID_SLOT_DATA` | Invalid slot data. |
| `BS_SDK_ERROR_CANNOT_INIT_DB` | Cannot initialize Database. |
| `BS_SDK_ERROR_DUPLICATE_ID` | Duplicated ID. |
| `BS_SDK_ERROR_USER_FULL` | No more users can be added. |
| `​BS_SDK_ERROR_DUPLICATE_TEMPLATE`​ | Fingerprint already enrolled. |
| `BS_SDK_ERROR_FINGERPRINT_FULL` | No more fingerprints can be added. |
| `BS_SDK_ERROR_DUPLICATE_CARD` | Duplicated Card. |
| `BS_SDK_ERROR_CARD_FULL` | No more cards can be added. |
| `BS_SDK_ERROR_NO_VALID_HDR_FILE` | Invalid file header. |
| `​BS_SDK_ERROR_INVALID_LOG_FILE`​ | Invalid log file. |
| `BS_SDK_ERROR_CANNOT_FIND_USER` | Cannot find user. |
| `BS_SDK_ERROR_ACCESS_LEVEL_FULL` | No more access levels can be added. |
| `BS_SDK_ERROR_INVALID_USER_ID` | Invalid user ID. |
| `BS_SDK_ERROR_BLACKLIST_FULL` | No more cards can be added to blacklist. |
| `BS_SDK_ERROR_USER_NAME_FULL` | No more user names can be added. |
| `BS_SDK_ERROR_USER_IMAGE_FULL` | No more profile pictures can be added. |
| `BS_SDK_ERROR_USER_IMAGE_SIZE_TOO_BIG` | User profile picture's size is to big. \\| \\|''BS_SDK_ERROR_SLOT_DATA_CHECKSUM'' |
| `BS_SDK_ERROR_CANNOT_UPDATE_FINGERPRINT` | Cannot update fingerprint template. |
| `​BS_SDK_ERROR_TEMPLATE_FORMAT_MISMATCH`​ | Template format does not match the type of the server. |
| `​BS_SDK_ERROR_NO_ADMIN_USER`​ | There is no administrator. |
| `​BS_SDK_ERROR_CANNOT_FIND_LOG`​ | Cannot find log. |
| `BS_SDK_ERROR_DOOR_SCHEDULE_FULL` | No more door schedules can be added. |
| `BS_SDK_ERROR_DB_SLOT_FULL` | Not enough space in database. |
| `BS_SDK_ERROR_ACCESS_GROUP_FULL` | No more access groups can be added. |
| `​BS_SDK_ERROR_ACCESS_SCHEDULE_FULL`​ | No more access schedule can be added. |
| `BS_SDK_ERROR_HOLIDAY_GROUP_FULL` | No more holiday groups can be added. |
| `BS_SDK_ERROR_HOLIDAY_FULL` | No more holidays can be added. |
| `BS_SDK_ERROR_TIME_PERIOD_FULL` | No more time periods can be added for one day. |
| `​BS_SDK_ERROR_NO_CREDENTIAL`​ | No credentials. |
| `BS_SDK_ERROR_NO_BIOMETRIC_CREDENTIAL` | No registered fingerprint. |
| `​BS_SDK_ERROR_NO_CARD_CREDENTIAL`​ | Card not registered. |
| `BS_SDK_ERROR_NO_PIN_CREDENTIAL` | No registered PIN. |
| `BS_SDK_ERROR_NO_BIOMETRIC_PIN_CREDENTIAL` | No registered PIN or fingerprint. |
| `​BS_SDK_ERROR_NO_USER_NAME`​ | User name not registered. |
| `BS_SDK_ERROR_NO_USER_IMAGE` | No user profile picture. |
| `​BS_SDK_ERROR_READER_FULL`​ | Unable to add more devices. |
| `​BS_SDK_ERROR_CACHE_MISSED`​ | Cannot find cache data. |
| `BS_SDK_ERROR_OPERATOR_FULL` | No more operators can be added. |
| `​BS_SDK_ERROR_INVALID_LINK_ID`​ | Invalid link ID. |
| `​BS_SDK_ERROR_TIMER_CANCELED`​ | Timer has been canceled. |
| `​BS_SDK_ERROR_USER_JOB_FULL`​ | Cannot add more job codes. |
| `BS_SDK_ERROR_CANNOT_UPDATE_FACE` | Cannot update face. |
| `BS_SDK_ERROR_FACE_FULL` | No more face template can be added. |
| `BS_SDK_ERROR_FLOOR_SCHEDULE_FULL` | No more floor schedule can be added. |
| `BS_SDK_ERROR_CANNOT_FIND_AUTH_GROUP` | Cannot find auth group. |
| `BS_SDK_ERROR_AUTH_GROUP_FULL` | No more auth group can be added. |
| `BS_SDK_ERROR_USER_PHRASE_FULL` | No more User phrase can be added. |
| `BS_SDK_ERROR_DST_SCHEDULE_FULL` | No more DST schedule can be added.. |
| `BS_SDK_ERROR_CANNOT_FIND_DST_SCHEDULE` | Cannot find DST schedule. |
| `BS_SDK_ERROR_INVALID_SCHEDULE` | Invalid schedule. |
| `BS_SDK_ERROR_CANNOT_FIND_OPERATOR` | Cannot find operator. |
| `BS_SDK_ERROR_DUPLICATE_FINGERPRINT` | Duplicated fingerprint. |
| `BS_SDK_ERROR_DUPLICATE_FACE` | Duplicated face. |
| `​BS_SDK_ERROR_INVALID_CONFIG`​ | Invalid system configuration. |
| `​BS_SDK_ERROR_CANNOT_OPEN_CONFIG_FILE`​ | Cannot open system configuration file. |
| `​BS_SDK_ERROR_CANNOT_READ_CONFIG_FILE`​ | Cannot read system configuration file. |
| `BS_SDK_ERROR_INVALID_CONFIG_FILE` | Invalid system configuration header information. |
| `BS_SDK_ERROR_INVALID_CONFIG_DATA` | Invalid system configuration. |
| `​BS_SDK_ERROR_CANNOT_WRITE_CONFIG_FILE`​ | Cannot write system configuration file. |
| `BS_SDK_ERROR_INVALID_CONFIG_INDEX` | Invalid configuration sector index. |
| `BS_SDK_ERROR_CANNOT_SCAN_FINGER` | Cannot scan finger. |
| `BS_SDK_ERROR_CANNOT_SCAN_CARD` | Cannot scan card. |
| `​BS_SDK_ERROR_CANNOT_OPEN_RTC`​ | No RTC device. |
| `​BS_SDK_ERROR_CANNOT_SET_RTC`​ | Unable to set time on RTC device. |
| `​BS_SDK_ERROR_CANNOT_GET_RTC`​ | Unable to get time of RTC device. |
| `​BS_SDK_ERROR_CANNOT_SET_LED`​ | Cannot set LCD pattern. |
| `​BS_SDK_ERROR_CANNOT_OPEN_DEVICE_DRIVER`​ | Device driver missing. |
| `BS_SDK_ERROR_CANNOT_FIND_DEVICE` | Cannot find device. |
| `BS_SDK_ERROR_CANNOT_SCAN_FACE` | Cannot scan face. |
| `BS_SDK_ERROR_SLAVE_FULL` | No more Slave device can be added. |
| `BS_SDK_ERROR_CANNOT_ADD_DEVICE` | Cannot add device. |
| `BS_SDK_ERROR_CANNOT_FIND_DOOR` | Cannot find door. |
| `BS_SDK_ERROR_DOOR_FULL` | No more doors can be added. |
| `BS_SDK_ERROR_CANNOT_LOCK_DOOR` | Cannot lock door. |
| `BS_SDK_ERROR_CANNOT_UNLOCK_DOOR` | Cannot unlock door. |
| `​BS_SDK_ERROR_CANNOT_RELEASE_DOOR`​ | Failed to release door. |
| `BS_SDK_ERROR_CANNOT_FIND_LIFT` | Cannot find lift. |
| `BS_SDK_ERROR_LIFT_FULL` | No more Lift device can be added. |
| `BS_SDK_ERROR_ACCESS_RULE_VIOLATION` | Access rules violated. |
| `BS_SDK_ERROR_DISABLED` | Disabled user. |
| `BS_SDK_ERROR_NOT_YET_VALID` | Not valid yet. |
| `BS_SDK_ERROR_EXPIRED` | Time expired. |
| `BS_SDK_ERROR_BLACKLIST` | Card registered to blacklist. |
| `BS_SDK_ERROR_CANNOT_FIND_ACCESS_GROUP` | Cannot find access group. |
| `BS_SDK_ERROR_CANNOT_FIND_ACCESS_LEVEL` | Cannot find access level. |
| `BS_SDK_ERROR_CANNOT_FIND_ACCESS_SCHEDULE` | Cannot find access schedule. |
| `BS_SDK_ERROR_CANNOT_FIND_HOLIDAY_GROUP` | Cannot find holiday group. |
| `​BS_SDK_ERROR_CANNOT_FIND_BLACKLIST`​ | Blacklist doesn't exist.\\| \\|''BS_SDK_ERROR_AUTH_TIMEOUT'' |
| `BS_SDK_ERROR_DUAL_AUTH_TIMEOUT` | Dual authentication timeout. |
| `BS_SDK_ERROR_INVALID_AUTH_MODE` | Invalid authentication mode. |
| `BS_SDK_ERROR_AUTH_UNEXPECTED_USER` | User information is not matched with the credentials. |
| `BS_SDK_ERROR_AUTH_UNEXPECTED_CREDENTIAL` | Invalid credentials in current schedule. |
| `BS_SDK_ERROR_DUAL_AUTH_FAIL` | Failed on dual authentication. |
| `BS_SDK_ERROR_BIOMETRIC_AUTH_REQUIRED` | Fingerprint is required. |
| `BS_SDK_ERROR_PIN_AUTH_REQUIRED` | PIN is required. |
| `BS_SDK_ERROR_BIOMETRIC_OR_PIN_AUTH_REQUIRED` | Fingerprint or PIN required. |
| `BS_SDK_ERROR_TNA_CODE_REQUIRED` | T&A code required. |
| `​BS_SDK_ERROR_AUTH_SERVER_MATCH_REFUSAL`​ | Server matching refused. |
| `BS_SDK_ERROR_CANNOT_FIND_FLOOR_LEVEL` | Cannot find floor level. |
| `BS_SDK_ERROR_AUTH_FAIL` | Auth failed. |
| `BS_SDK_ERROR_AUTH_GROUP_REQUIRED` | Auth group is required. |
| `BS_SDK_ERROR_IDENTIFICATION_REQUIRED` | Identification is required. |
| `BS_SDK_ERROR_ANTI_TAILGATE_VIOLATION` | Anti tailgating rules violated. |
| `BS_SDK_ERROR_CANNOT_FIND_ZONE` | Unregistered zone. |
| `BS_SDK_ERROR_SET_ZONE` | No more zone can be added. |
| `BS_SDK_ERROR_HARD_APB_VIOLATION` | Hard APB rules violated. |
| `BS_SDK_ERROR_SOFT_APB_VIOLATION` | Soft APB rules violated. |
| `BS_SDK_ERROR_HARD_TIMED_APB_VIOLATION` | Timed Hard APB rules violated. |
| `BS_SDK_ERROR_SOFT_TIMED_APB_VIOLATION` | Timed Soft APB rules violated. |
| `BS_SDK_ERROR_SCHEDULED_LOCK_VIOLATION` | Invalid user attempted access in the lock schedule. |
| `​BS_SDK_ERROR_SCHEDULED_UNLOCK_VIOLATION`​ | Invalid user attempted access in the unlock schedule. |
| `BS_SDK_ERROR_SET_FIRE_ALARM` | Cannot set fire alarm. |
| `​BS_SDK_ERROR_TIMED_APB_ZONE_FULL`​ | Cannot add more Timed APB zone. |
| `​BS_SDK_ERROR_FIRE_ALARM_ZONE_FULL`​ | Cannot add more fire alarm zone. |
| `​BS_SDK_ERROR_SCHEDULED_LOCK_UNLOCK_ZONE_FULL`​ | Cannot add more scheduled lock/unlock zone. |
| `​BS_SDK_ERROR_INACTIVE_ZONE`​ | Inactive zone. |
| `BS_SDK_ERROR_INTRUSION_ALARM_ZONE_FULL` | No more intrusion alarm zone can be added. |
| `BS_SDK_ERROR_CANNOT_ARM` | Cannot switch to alarm mode. |
| `BS_SDK_ERROR_CANNOT_DISARM` | Cannot switch to disalarm mode. |
| `BS_SDK_ERROR_CANNOT_FIND_ARM_CARD` | Cannot find alarm mode switch card. |
| `BS_SDK_ERROR_HARD_ENTRANCE_LIMIT_COUNT_VIOLATION` | The number of Entrance limit area(Hard) exceeds the allowable number. |
| `BS_SDK_ERROR_SOFT_ENTRANCE_LIMIT_COUNT_VIOLATION` | The number of Entrance limit area(Soft) exceeds the allowable number. |
| `BS_SDK_ERROR_HARD_ENTRANCE_LIMIT_TIME_VIOLATION` | Entrance time limit (hard) time violation. |
| `BS_SDK_ERROR_SOFT_ENTRANCE_LIMIT_TIME_VIOLATION` | Entrance time limit (hard) time violation. |
| `BS_SDK_ERROR_INTERLOCK_ZONE_DOOR_VIOLATION` | Interlock zone door rule violation. |
| `BS_SDK_ERROR_INTERLOCK_ZONE_INPUT_VIOLATION` | Interlock zone input rule violation. |
| `BS_SDK_ERROR_INTERLOCK_ZONE_FULL` | No more interlock zone can be added. |
| `BS_SDK_ERROR_AUTH_LIMIT_SCHEDULE_VIOLATION` | Auth limit rule(schedule) violation. |
| `BS_SDK_ERROR_AUTH_LIMIT_COUNT_VIOLATION` | Auth limit rule(count) violation |
| `BS_SDK_ERROR_AUTH_LIMIT_USER_VIOLATION` | Auth limit rule(user) violation. |
| `BS_SDK_ERROR_SOFT_AUTH_LIMIT_VIOLATION` | Auth limit rule(network disconnected or soft auth limit) violation. |
| `BS_SDK_ERROR_HARD_AUTH_LIMIT_VIOLATION` | Auth limit rule(network disconnected or hard auth limit) violation. |
| `BS_SDK_ERROR_CARD_IO` | Unsupported Card I/O. |
| `​BS_SDK_ERROR_CARD_INIT_FAIL`​ | Failed to initialize card. |
| `​BS_SDK_ERROR_CARD_NOT_ACTIVATED`​ | Card has not been activated. |
| `BS_SDK_ERROR_CARD_CANNOT_READ_DATA` | Cannot read data from card. |
| `​BS_SDK_ERROR_CARD_CIS_CRC`​ | CIS checksum error. |
| `BS_SDK_ERROR_CARD_CANNOT_WRITE_DATA` | Cannot write data on card. |
| `BS_SDK_ERROR_CARD_READ_TIMEOUT` | Card read timeout. |
| `BS_SDK_ERROR_CARD_READ_CANCELLED` | Card read canceled. |
| `​BS_SDK_ERROR_CARD_CANNOT_SEND_DATA`​ | Failed to send card data. |
| `BS_SDK_ERROR_CANNOT_FIND_CARD` | Cannot find card. |
| `​BS_SDK_ERROR_INVALID_PASSWORD`​ | Invalid password. |
| `​BS_SDK_ERROR_CAMERA_INIT_FAIL`​ | Failed to initialize the camera. |
| `​BS_SDK_ERROR_JPEG_ENCODER_INIT_FAIL`​ | Failed to initialize the JPEG encoder. |
| `​BS_SDK_ERROR_CANNOT_ENCODE_JPEG`​ | Cannot encode to JPEG. |
| `​BS_SDK_ERROR_JPEG_ENCODER_NOT_INITIALIZED`​ | Failed to initialize Jpeg encoder. |
| `​BS_SDK_ERROR_JPEG_ENCODER_DEINIT_FAIL`​ | Unable to remove the Jpeg encoder. |
| `​BS_SDK_ERROR_CAMERA_CAPTURE_FAIL`​ | Failed to capture image with the camera. |
| `​BS_SDK_ERROR_CANNOT_DETECT_FACE`​ | Cannot detect face. |
| `​BS_SDK_ERROR_FILE_IO`​ | Failed on file I/O operation. |
| `​BS_SDK_ERROR_ALLOC_MEM`​ | Failed to allocate memory. |
| `BS_SDK_ERROR_CANNOT_UPGRADE` | Failed on upgrade. |
| `​BS_SDK_ERROR_DEVICE_LOCKED`​ | Device is locked. |
| `​BS_SDK_ERROR_CANNOT_SEND_TO_SERVER`​ | Cannot send data to server. |
| `BS_SDK_ERROR_CANNOT_UPGRADE_MEMOEY` | Cannot upgrade memory. |
| `BS_SDK_ERROR_NULL_POINTER` | Wrong pointer. |
| `BS_SDK_ERROR_UNINITIALIZED` | SDK not initialized. |
| `BS_SDK_ERROR_CANNOT_RUN_SERVICE` | Cannot run SDK service. |
| `BS_SDK_ERROR_CANCELED` | Canceled. |
| `BS_SDK_ERROR_EXIST` | Already exists. |
| `BS_SDK_ERROR_ENCRYPT` | Failed on encryption. |
| `BS_SDK_ERROR_DECRYPT` | Failed on decryption. |
| `BS_SDK_ERROR_DEVICE_BUSY` | Device cannot response. |
| `​BS_SDK_ERROR_INTERNAL`​ | Internal SDK error. |
| `​BS_SDK_ERROR_INVALID_FILE_FORMAT`​ | Invalid file format. |
| `BS_SDK_ERROR_INVALID_SCHEDULE_ID` | Invalid schedule ID. |
| `BS_SDK_ERROR_UNKNOWN_FINGER_TEMPLATE` | Not supported fingerprint template. (Template type is not Suprema, ANSI or ISO) |
