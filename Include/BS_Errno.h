/*
 * BS_Errno.h
 *
 *  Created on: 2015. 4. 27.
 *      Author: scpark
 */

#ifndef CORE_JNI_SRC_BS_ERRNO_H_
#define CORE_JNI_SRC_BS_ERRNO_H_

#define BS_SDK_SUCCESS                                      1     ///< Success.
#define BS_SDK_DURESS_SUCCESS                               2     ///< Authenticated as duress fingerprint.
#define BS_SDK_FIRST_AUTH_SUCCESS                           3     ///< First user has been authenticated.
#define BS_SDK_SECOND_AUTH_SUCCESS                          4     ///< Second user has been authenticated.
#define BS_SDK_DUAL_AUTH_SUCCESS                            5     ///< Success on dual authentication.
#define BS_SDK_WIEGAND_BYPASS_SUCCESS                       11    ///< Success on Wiegand bypass. (Only FaceStation2)
#define BS_SDK_ANONYMOUS_SUCCESS                            12    ///< Anonymous authentication success.
#define BS_SDK_LOCKOVERRIDE_SUCCESS 						13    ///< Lock override authentication success.

// Driver errors
#define BS_SDK_ERROR_FROM_DEVICE_DRIVER                     -1    ///< Device driver error.

// Communication errors
#define BS_SDK_ERROR_CANNOT_OPEN_SOCKET                     -101  ///< Cannot create a socket.
#define BS_SDK_ERROR_CANNOT_CONNECT_SOCKET                  -102  ///< Cannot connect to socket.
#define BS_SDK_ERROR_CANNOT_LISTEN_SOCKET                   -103  ///< Cannot set socket to listen for connections.
#define BS_SDK_ERROR_CANNOT_ACCEPT_SOCKET                   -104  ///< Cannot accept socket.
#define BS_SDK_ERROR_CANNOT_READ_SOCKET                     -105  ///< Cannot read from socket.
#define BS_SDK_ERROR_CANNOT_WRITE_SOCKET                    -106  ///< Cannot write on socket.
#define BS_SDK_ERROR_SOCKET_IS_NOT_CONNECTED                -107  ///< Not connected to socket.
#define BS_SDK_ERROR_SOCKET_IS_NOT_OPEN                     -108  ///< Cannot use socket.
#define BS_SDK_ERROR_SOCKET_IS_NOT_LISTENED                 -109  ///< Socket not set to listen.
#define BS_SDK_ERROR_SOCKET_IN_PROGRESS                     -110  ///< Already in progress.
//Custom => [IPv6]
#define BS_SDK_ERROR_IPV4_IS_NOT_ENABLE					    -111  ///< IPv4 connection mode is not enabled.
#define BS_SDK_ERROR_IPV6_IS_NOT_ENABLE					    -112  ///< IPv6 connection mode is not enabled.
#define BS_SDK_ERROR_NOT_SUPPORTED_SPECIFIED_DEVICE_INFO    -113  ///< Specified device info is not supported.
#define BS_SDK_ERROR_NOT_ENOUGTH_BUFFER					    -114  ///< Buffer is not large enough.
#define BS_SDK_ERROR_NOT_SUPPORTED_IPV6					    -115  ///< IPv6 not supported.
#define BS_SDK_ERROR_INVALID_ADDRESS                        -116  ///< Invalid address.
//Custom <=

// Packet errors
#define BS_SDK_ERROR_INVALID_PARAM                          -200  ///< Invalid parameter.
#define BS_SDK_ERROR_INVALID_PACKET                         -201  ///< Invalid packet.
#define BS_SDK_ERROR_INVALID_DEVICE_ID                      -202  ///< Invalid device ID.
#define BS_SDK_ERROR_INVALID_DEVICE_TYPE                    -203  ///< Invalid device type.
#define BS_SDK_ERROR_PACKET_CHECKSUM                        -204  ///< Packet data's checksum is not correct.
#define BS_SDK_ERROR_PACKET_INDEX                           -205  ///< Invalid packet index.
#define BS_SDK_ERROR_PACKET_COMMAND                         -206  ///< Invalid command.
#define BS_SDK_ERROR_PACKET_SEQUENCE                        -207  ///< Packet sequence error due to unstable network connection.
#define BS_SDK_ERROR_NO_PACKET                              -209  ///< Invalid packet.
#define BS_SDK_ERROR_INVALID_CODE_SIGN                      -210  ///< Invalid firmware code sign. //=> [Check Firmware CodeSign][ET] <=

//Fingerprint errors
#define BS_SDK_ERROR_EXTRACTION_FAIL                        -300  ///< Cannot extract template data.
#define BS_SDK_ERROR_VERIFY_FAIL                            -301  ///< Failed on 1:1 verification.
#define BS_SDK_ERROR_IDENTIFY_FAIL                          -302  ///< Failed on 1:N identification.
#define BS_SDK_ERROR_IDENTIFY_TIMEOUT                       -303  ///< Identification timeout.
#define BS_SDK_ERROR_FINGERPRINT_CAPTURE_FAIL               -304  ///< Cannot capture the fingerprint image.
#define BS_SDK_ERROR_FINGERPRINT_SCAN_TIMEOUT               -305  ///< Fingerprint scan timeout.
#define BS_SDK_ERROR_FINGERPRINT_SCAN_CANCELLED             -306  ///< Fingerprint scan canceled.
#define BS_SDK_ERROR_NOT_SAME_FINGERPRINT                   -307  ///< Not identical fingerprints.
#define BS_SDK_ERROR_EXTRACTION_LOW_QUALITY                 -308  ///< Need more information of fingerprint minutiae.
#define BS_SDK_ERROR_CAPTURE_LOW_QUALITY                    -309  ///< Low quality of captured fingerprint image.
#define BS_SDK_ERROR_CANNOT_FIND_FINGERPRINT                -310  ///< Fingerprint not registered.
#define BS_SDK_ERROR_NO_FINGER_DETECTED                     BS_SDK_ERROR_FINGERPRINT_CAPTURE_FAIL ///< @deprecated Alias for BS_SDK_ERROR_FINGERPRINT_CAPTURE_FAIL.
#define BS_SDK_ERROR_FAKE_FINGER_DETECTED                   -311  ///< Fake finger detected.
#define BS_SDK_ERROR_FAKE_FINGER_TRY_AGAIN                  -312  ///< Fake finger try again.
#define BS_SDK_ERROR_FAKE_FINGER_SENSOR_ERROR               -313  ///< Fake finger sensor error.
#define BS_SDK_ERROR_CANNOT_FIND_FACE                       -314  ///< Cannot find face.
#define BS_SDK_ERROR_FACE_CAPTURE_FAIL                      -315  ///< Face capture failed.
#define BS_SDK_ERROR_FACE_SCAN_TIMEOUT                      -316  ///< Face scan timeout error.
#define BS_SDK_ERROR_FACE_SCAN_CANCELLED                    -317  ///< Face scan cancelled.
#define BS_SDK_ERROR_FACE_SCAN_FAILED                       -318  ///< Failed to face scan. (FaceStation2, FaceLite only)
#define BS_SDK_ERROR_NO_FACE_DETECTED                       BS_SDK_ERROR_FACE_CAPTURE_FAIL ///< @deprecated Alias for BS_SDK_ERROR_FACE_CAPTURE_FAIL.
#define BS_SDK_ERROR_UNMASKED_FACE_DETECTED                 -319  ///< Unmasked face detected.
#define BS_SDK_ERROR_FAKE_FACE_DETECTED                     -320  ///< Fake face detected.
#define BS_SDK_ERROR_CANNOT_ESTIMATE                        -321  ///< Cannot estimate face position.
#define BS_SDK_ERROR_NORMALIZE_FACE                         -322  ///< Cannot normalize face image.
#define BS_SDK_ERROR_SMALL_DETECTION                        -323  ///< Detected face is too small.
#define BS_SDK_ERROR_LARGE_DETECTION                        -324  ///< Detected face is too large.
#define BS_SDK_ERROR_BIASED_DETECTION                       -325  ///< Detected face is biased out of frame.
#define BS_SDK_ERROR_ROTATED_FACE                           -326  ///< Face is too rotated.
#define BS_SDK_ERROR_OVERLAPPED_FACE                        -327  ///< Multiple faces are overlapping.
#define BS_SDK_ERROR_UNOPENED_EYES                          -328  ///< Eyes are not open.
#define BS_SDK_ERROR_NOT_LOOKING_FRONT                      -329  ///< Face is not looking front.
#define BS_SDK_ERROR_OCCLUDED_MOUTH                         -330  ///< Mouth is occluded.
#define BS_SDK_ERROR_MATCH_FAIL                             -331  ///< Face matching failed.
#define BS_SDK_ERROR_INCOMPATIBLE_FACE                      -332  ///< Incompatible face template format.

//File I/O errors
#define BS_SDK_ERROR_CANNOT_OPEN_DIR                        -400  ///< Cannot open directory.
#define BS_SDK_ERROR_CANNOT_OPEN_FILE                       -401  ///< Cannot open file.
#define BS_SDK_ERROR_CANNOT_WRITE_FILE                      -402  ///< Cannot write on file.
#define BS_SDK_ERROR_CANNOT_SEEK_FILE                       -403  ///< Cannot seek file.
#define BS_SDK_ERROR_CANNOT_READ_FILE                       -404  ///< Cannot read file.
#define BS_SDK_ERROR_CANNOT_GET_STAT                        -405  ///< Cannot get file status.
#define BS_SDK_ERROR_CANNOT_GET_SYSINFO                     -406  ///< Cannot get system information.
#define BS_SDK_ERROR_DATA_MISMATCH                          -407  ///< Failed on data redundancy check.
#define BS_SDK_ERROR_ALREADY_OPEN_DIR                       -408  ///< Directory is already open.

// I/O errors
#define BS_SDK_ERROR_INVALID_RELAY                          -500  ///< Invalid Relay.
#define BS_SDK_ERROR_CANNOT_WRITE_IO_PACKET                 -501  ///< Failed to write I/O packet.
#define BS_SDK_ERROR_CANNOT_READ_IO_PACKET                  -502  ///< Failed to read I/O packet.
#define BS_SDK_ERROR_CANNOT_READ_INPUT                      -503  ///< Cannot read input device.
#define BS_SDK_ERROR_READ_INPUT_TIMEOUT                     -504  ///< Timeout during reading the input device.
#define BS_SDK_ERROR_CANNOT_ENABLE_INPUT                    -505  ///< Cannot enable the input device.
#define BS_SDK_ERROR_CANNOT_SET_INPUT_DURATION              -506  ///< Cannot set the duration of the input device.
#define BS_SDK_ERROR_INVALID_PORT                           -507  ///< Invalid port.
#define BS_SDK_ERROR_INVALID_INTERPHONE_TYPE                -508  ///< Invalid intercom type.
#define BS_SDK_ERROR_INVALID_LCD_PARAM                      -510  ///< Invalid LCD parameter.
#define BS_SDK_ERROR_CANNOT_WRITE_LCD_PACKET                -511  ///< Failed to write LCD packet.
#define BS_SDK_ERROR_CANNOT_READ_LCD_PACKET                 -512  ///< Failed to read LCD packet.
#define BS_SDK_ERROR_INVALID_LCD_PACKET                     -513  ///< Invalid LCD packet.
#define BS_SDK_ERROR_INPUT_QUEUE_FULL                       -520  ///< Not enough buffer space on input device.
#define BS_SDK_ERROR_WIEGAND_QUEUE_FULL                     -521  ///< Not enough input buffer space on wiegand device.
#define BS_SDK_ERROR_MISC_INPUT_QUEUE_FULL                  -522  ///< Not enough buffer space on miscellaneous device.
#define BS_SDK_ERROR_WIEGAND_DATA_QUEUE_FULL                -523  ///< Not enough output buffer space on wiegand device.
#define BS_SDK_ERROR_WIEGAND_DATA_QUEUE_EMPTY               -524  ///< Empty output data of wiegand device.

//Util errors
#define BS_SDK_ERROR_NOT_SUPPORTED                          -600  ///< Not supported.
#define BS_SDK_ERROR_TIMEOUT                                -601  ///< Timeout.
#define BS_SDK_ERROR_CANNOT_SET_TIME                        -602  ///< Cannot set time.

//Database errors
#define BS_SDK_ERROR_INVALID_DATA_FILE                      -700  ///< Invalid data file.
#define BS_SDK_ERROR_TOO_LARGE_DATA_FOR_SLOT                -701  ///< The data is larger than the slot.
#define BS_SDK_ERROR_INVALID_SLOT_NO                        -702  ///< Invalid slot number.
#define BS_SDK_ERROR_INVALID_SLOT_DATA						-703  ///< Invalid slot data.
#define BS_SDK_ERROR_CANNOT_INIT_DB                         -704  ///< Cannot initialize Database.
#define BS_SDK_ERROR_DUPLICATE_ID                           -705  ///< Duplicated ID.
#define BS_SDK_ERROR_USER_FULL                              -706  ///< No more users can be added.
#define BS_SDK_ERROR_DUPLICATE_TEMPLATE                     -707  ///< Fingerprint already enrolled.
#define BS_SDK_ERROR_FINGERPRINT_FULL                       -708  ///< No more fingerprints can be added.
#define BS_SDK_ERROR_DUPLICATE_CARD                         -709  ///< Duplicated Card.
#define BS_SDK_ERROR_CARD_FULL                              -710  ///< No more cards can be added.
#define BS_SDK_ERROR_NO_VALID_HDR_FILE                      -711  ///< Invalid file header.
#define BS_SDK_ERROR_INVALID_LOG_FILE						-712  ///< Invalid log file.
#define BS_SDK_ERROR_CANNOT_FIND_USER                       -714  ///< Cannot find user.
#define BS_SDK_ERROR_ACCESS_LEVEL_FULL                      -715  ///< No more access levels can be added.
#define BS_SDK_ERROR_INVALID_USER_ID                        -716  ///< Invalid user ID.
#define BS_SDK_ERROR_BLACKLIST_FULL                         -717  ///< No more cards can be added to blacklist.
#define BS_SDK_ERROR_USER_NAME_FULL                         -718  ///< No more user names can be added.
#define BS_SDK_ERROR_USER_IMAGE_FULL                        -719  ///< No more profile pictures can be added.
#define BS_SDK_ERROR_USER_IMAGE_SIZE_TOO_BIG                -720  ///< User profile picture's size is too big.
#define BS_SDK_ERROR_SLOT_DATA_CHECKSUM                     -721  ///< Slot data checksum error.
#define BS_SDK_ERROR_CANNOT_UPDATE_FINGERPRINT              -722  ///< Cannot update fingerprint template.
#define BS_SDK_ERROR_TEMPLATE_FORMAT_MISMATCH               -723  ///< Template format does not match the type of the server.
#define BS_SDK_ERROR_NO_ADMIN_USER                          -724  ///< There is no administrator.
#define BS_SDK_ERROR_CANNOT_FIND_LOG                        -725  ///< Cannot find log.
#define BS_SDK_ERROR_DOOR_SCHEDULE_FULL                     -726  ///< No more door schedules can be added.
#define BS_SDK_ERROR_DB_SLOT_FULL                           -727  ///< Not enough space in database.
#define BS_SDK_ERROR_ACCESS_GROUP_FULL                      -728  ///< No more access groups can be added.
#define BS_SDK_ERROR_FLOOR_LEVEL_FULL                       -729  ///< No more floor levels can be added.
#define BS_SDK_ERROR_ACCESS_SCHEDULE_FULL                   -730  ///< No more access schedule can be added.
#define BS_SDK_ERROR_HOLIDAY_GROUP_FULL                     -731  ///< No more holiday groups can be added.
#define BS_SDK_ERROR_HOLIDAY_FULL                           -732  ///< No more holidays can be added.
#define BS_SDK_ERROR_TIME_PERIOD_FULL                       -733  ///< No more time periods can be added for one day.
#define BS_SDK_ERROR_NO_CREDENTIAL                          -734  ///< No credentials.
#define BS_SDK_ERROR_NO_BIOMETRIC_CREDENTIAL                -735  ///< No registered fingerprint.
#define BS_SDK_ERROR_NO_CARD_CREDENTIAL                     -736  ///< Card not registered.
#define BS_SDK_ERROR_NO_PIN_CREDENTIAL                      -737  ///< No registered PIN.
#define BS_SDK_ERROR_NO_BIOMETRIC_PIN_CREDENTIAL            -738  ///< No registered PIN or fingerprint.
#define BS_SDK_ERROR_NO_USER_NAME                           -739  ///< User name not registered.
#define BS_SDK_ERROR_NO_USER_IMAGE                          -740  ///< No user profile picture.
#define BS_SDK_ERROR_READER_FULL                            -741  ///< Unable to add more devices.
#define BS_SDK_ERROR_CACHE_MISSED                           -742  ///< Cannot find cache data.
#define BS_SDK_ERROR_OPERATOR_FULL                          -743  ///< No more operators can be added.
#define BS_SDK_ERROR_INVALID_LINK_ID                        -744  ///< Invalid link ID.
#define BS_SDK_ERROR_TIMER_CANCELED                         -745  ///< Timer has been canceled.
#define BS_SDK_ERROR_USER_JOB_FULL                          -746  ///< Cannot add more job codes.
#define BS_SDK_ERROR_CANNOT_UPDATE_FACE                     -747  ///< Cannot update face.
#define BS_SDK_ERROR_FACE_FULL                              -748  ///< No more face template can be added.
#define BS_SDK_ERROR_FLOOR_SCHEDULE_FULL                    -749  ///< No more floor schedule can be added.
#define BS_SDK_ERROR_CANNOT_FIND_AUTH_GROUP                 -750  ///< Cannot find auth group.
#define BS_SDK_ERROR_AUTH_GROUP_FULL                        -751  ///< No more auth group can be added.
#define BS_SDK_ERROR_USER_PHRASE_FULL                       -752  ///< No more User phrase can be added.
#define BS_SDK_ERROR_DST_SCHEDULE_FULL                      -753  ///< No more DST schedule can be added.
#define BS_SDK_ERROR_CANNOT_FIND_DST_SCHEDULE               -754  ///< Cannot find DST schedule.
#define BS_SDK_ERROR_INVALID_SCHEDULE                       -755  ///< Invalid schedule.
#define BS_SDK_ERROR_CANNOT_FIND_OPERATOR                   -756  ///< Cannot find operator.
#define BS_SDK_ERROR_DUPLICATE_FINGERPRINT                  -757  ///< Duplicated fingerprint.
#define BS_SDK_ERROR_DUPLICATE_FACE                         -758  ///< Duplicated face.
#define BS_SDK_ERROR_NO_FACE_CREDENTIAL                     -759  ///< No face credential registered.
#define BS_SDK_ERROR_NO_FINGERPRINT_CREDENTIAL              -760  ///< No fingerprint credential registered.
#define BS_SDK_ERROR_NO_FACE_PIN_CREDENTIAL                 -761  ///< No face or PIN credential registered.
#define BS_SDK_ERROR_NO_FINGERPRINT_PIN_CREDENTIAL          -762  ///< No fingerprint or PIN credential registered.
#define BS_SDK_ERROR_USER_IMAGE_EX_FULL                     (DEPRECATED_MAC)-763 ///< @deprecated No more extended profile pictures can be added.
#define BS_SDK_ERROR_SQL_ERROR                              -763  ///< SQL database error.
#define BS_SDK_ERROR_LOCKOVERRIDE_LIST_FULL 				-764  ///< Lock override list is full.
#define BS_SDK_ERROR_CANNOT_FIND_LOCKOVERRIDE_LIST 			-765  ///< Cannot find lock override entry.
#define BS_SDK_ERROR_USER_OVERRIDE_FULL 					-766  ///< User override list is full.
#define BS_SDK_ERROR_ADMIN_INVALID_CREDENTIAL               -767  ///< Admin has invalid credential.
#define BS_SDK_ERROR_ADMIN_USER_NO_CREDENTIAL               -768  ///< Admin user has no credential.
#define BS_SDK_ERROR_ADMIN_USER_NOT_ENOUGH_CREDENTIAL 		-769  ///< Admin user does not have enough credentials.
#define BS_SDK_ERROR_ADMIN_UNSUPPORTED_CREDENTIAL 			-770  ///< Admin credential type is not supported.
#define BS_SDK_ERROR_ADMIN_CANNOT_SCAN 						-771  ///< Cannot scan admin credential.

//Config errors
#define BS_SDK_ERROR_INVALID_CONFIG                         -800  ///< Invalid system configuration.
#define BS_SDK_ERROR_CANNOT_OPEN_CONFIG_FILE                -801  ///< Cannot open system configuration file.
#define BS_SDK_ERROR_CANNOT_READ_CONFIG_FILE                -802  ///< Cannot read system configuration file.
#define BS_SDK_ERROR_INVALID_CONFIG_FILE                    -803  ///< Invalid system configuration header information.
#define BS_SDK_ERROR_INVALID_CONFIG_DATA                    -804  ///< Invalid system configuration data.
#define BS_SDK_ERROR_CANNOT_WRITE_CONFIG_FILE               -805  ///< Cannot write system configuration file.
#define BS_SDK_ERROR_INVALID_CONFIG_INDEX                   -806  ///< Invalid configuration sector index.

//Device errors
#define BS_SDK_ERROR_CANNOT_SCAN_FINGER                     -900  ///< Cannot scan finger.
#define BS_SDK_ERROR_CANNOT_SCAN_CARD                       -901  ///< Cannot scan card.
#define BS_SDK_ERROR_CANNOT_OPEN_RTC                        -902  ///< No RTC device.
#define BS_SDK_ERROR_CANNOT_SET_RTC                         -903  ///< Unable to set time on RTC device.
#define BS_SDK_ERROR_CANNOT_GET_RTC                         -904  ///< Unable to get time of RTC device.
#define BS_SDK_ERROR_CANNOT_SET_LED                         -905  ///< Cannot set LCD pattern.
#define BS_SDK_ERROR_CANNOT_OPEN_DEVICE_DRIVER              -906  ///< Device driver missing.
#define BS_SDK_ERROR_CANNOT_FIND_DEVICE                     -907  ///< Cannot find device.
#define BS_SDK_ERROR_CANNOT_SCAN_FACE                       -908  ///< Cannot scan face.
#define BS_SDK_ERROR_SLAVE_FULL                             -910  ///< No more Slave device can be added.
#define BS_SDK_ERROR_CANNOT_ADD_DEVICE                      -911  ///< Cannot add device.
#define BS_SDK_ERROR_SLAVE_NOT_READY                        -912  ///< Slave device is not ready.
#define BS_SDK_ERROR_CANNOT_DEL_DEVICE 						-913  ///< Cannot delete device.

//Door errors
#define BS_SDK_ERROR_CANNOT_FIND_DOOR                       -1000 ///< Cannot find door.
#define BS_SDK_ERROR_DOOR_FULL                              -1001 ///< No more doors can be added.
#define BS_SDK_ERROR_CANNOT_LOCK_DOOR                       -1002 ///< Cannot lock door.
#define BS_SDK_ERROR_CANNOT_UNLOCK_DOOR                     -1003 ///< Cannot unlock door.
#define BS_SDK_ERROR_CANNOT_RELEASE_DOOR                    -1004 ///< Failed to release door.
#define BS_SDK_ERROR_CANNOT_FIND_LIFT                       -1005 ///< Cannot find lift.
#define BS_SDK_ERROR_LIFT_FULL                              -1006 ///< No more Lift device can be added.

//Access control errors
#define BS_SDK_ERROR_ACCESS_RULE_VIOLATION                  -1100 ///< Access rules violated.
#define BS_SDK_ERROR_DISABLED                               -1101 ///< Disabled user.
#define BS_SDK_ERROR_NOT_YET_VALID                          -1102 ///< Not valid yet.
#define BS_SDK_ERROR_EXPIRED                                -1103 ///< Time expired.
#define BS_SDK_ERROR_BLACKLIST                              -1104 ///< Card registered to blacklist.
#define BS_SDK_ERROR_CANNOT_FIND_ACCESS_GROUP               -1105 ///< Cannot find access group.
#define BS_SDK_ERROR_CANNOT_FIND_ACCESS_LEVEL               -1106 ///< Cannot find access level.
#define BS_SDK_ERROR_CANNOT_FIND_ACCESS_SCHEDULE            -1107 ///< Cannot find access schedule.
#define BS_SDK_ERROR_CANNOT_FIND_HOLIDAY_GROUP              -1108 ///< Cannot find holiday group.
#define BS_SDK_ERROR_CANNOT_FIND_BLACKLIST                  -1109 ///< Blacklist doesn't exist.
#define BS_SDK_ERROR_AUTH_TIMEOUT                           -1110 ///< Authentication timeout.
#define BS_SDK_ERROR_DUAL_AUTH_TIMEOUT                      -1111 ///< Dual authentication timeout.
#define BS_SDK_ERROR_INVALID_AUTH_MODE                      -1112 ///< Invalid authentication mode.
#define BS_SDK_ERROR_AUTH_UNEXPECTED_USER                   -1113 ///< User information is not matched with the credentials.
#define BS_SDK_ERROR_AUTH_UNEXPECTED_CREDENTIAL             -1114 ///< Invalid credentials in current schedule.
#define BS_SDK_ERROR_DUAL_AUTH_FAIL                         -1115 ///< Failed on dual authentication.
#define BS_SDK_ERROR_BIOMETRIC_AUTH_REQUIRED                -1116 ///< Fingerprint is required.
#define BS_SDK_ERROR_CARD_AUTH_REQUIRED                     -1117 ///< Card authentication is required.
#define BS_SDK_ERROR_PIN_AUTH_REQUIRED                      -1118 ///< PIN is required.
#define BS_SDK_ERROR_BIOMETRIC_OR_PIN_AUTH_REQUIRED         -1119 ///< Fingerprint or PIN required.
#define BS_SDK_ERROR_TNA_CODE_REQUIRED                      -1120 ///< T&A code required.
#define BS_SDK_ERROR_AUTH_SERVER_MATCH_REFUSAL              -1121 ///< Server matching refused.
#define BS_SDK_ERROR_CANNOT_FIND_FLOOR_LEVEL                -1122 ///< Cannot find floor level.
#define BS_SDK_ERROR_AUTH_FAIL                              -1123 ///< Auth failed.
#define BS_SDK_ERROR_AUTH_GROUP_REQUIRED                    -1124 ///< Auth group is required.
#define BS_SDK_ERROR_IDENTIFICATION_REQUIRED                -1125 ///< Identification is required.
#define BS_SDK_ERROR_ANTI_TAILGATE_VIOLATION                -1126 ///< Anti tailgating rules violated.
#define BS_SDK_ERROR_HIGH_TEMPERATURE_VIOLATION             -1127 ///< Temperature is too high to authenticate.
#define BS_SDK_ERROR_CANNOT_MEASURE_TEMPERATURE             -1128 ///< Cannot measure temperature.
#define BS_SDK_ERROR_UNMASKED_FACE_VIOLATION                -1129 ///< Unmasked face access violation.

// Required (Fingerprint/Face/PIN/Mask/Thermal ...)
#define BS_SDK_MASK_CHECK_REQUIRED                          -1130 ///< Mask check is required.
#define BS_SDK_THERMAL_CHECK_REQUIRED                       -1131 ///< Thermal check is required.
#define BS_SDK_FACE_AUTH_REQUIRED                           -1132 ///< Face authentication is required.
#define BS_SDK_FINGERPRINT_AUTH_REQUIRED                    -1133 ///< Fingerprint authentication is required.
#define BS_SDK_FACE_OR_PIN_AUTH_REQUIRED                    -1134 ///< Face or PIN authentication is required.
#define BS_SDK_FINGERPRINT_OR_PIN_AUTH_REQUIRED             -1135 ///< Fingerprint or PIN authentication is required.

//Zone errors
#define BS_SDK_ERROR_CANNOT_FIND_ZONE                       -1200 ///< Unregistered zone.
#define BS_SDK_ERROR_ZONE_FULL                              (DEPRECATED_MAC)-1201 ///< @deprecated Use BS_SDK_ERROR_SET_ZONE. No more zone can be added. Deprecated since 2.6.0.
#define BS_SDK_ERROR_SET_ZONE                               -1201 ///< No more zone can be added.
#define BS_SDK_ERROR_HARD_APB_VIOLATION                     -1202 ///< Hard APB rules violated.
#define BS_SDK_ERROR_SOFT_APB_VIOLATION                     -1203 ///< Soft APB rules violated.
#define BS_SDK_ERROR_HARD_TIMED_APB_VIOLATION               -1204 ///< Timed Hard APB rules violated.
#define BS_SDK_ERROR_SOFT_TIMED_APB_VIOLATION               -1205 ///< Timed Soft APB rules violated.
#define BS_SDK_ERROR_SCHEDULED_LOCK_VIOLATION               -1206 ///< Invalid user attempted access in the lock schedule.
#define BS_SDK_ERROR_SCHEDULED_UNLOCK_VIOLATION             (DEPRECATED_MAC)-1207 ///< @deprecated Deprecated since 2.7.2. Invalid user attempted access in the unlock schedule.
#define BS_SDK_ERROR_INTRUSION_ALARM_VIOLATION              -1207 ///< Intrusion alarm zone violation.
#define BS_SDK_ERROR_SET_FIRE_ALARM                         (DEPRECATED_MAC)-1208 ///< @deprecated Deprecated since 2.7.2. Cannot set fire alarm.
#define BS_SDK_ERROR_APB_ZONE_FULL                          -1208 ///< No more APB zone can be added.
#define BS_SDK_ERROR_TIMED_APB_ZONE_FULL                    -1209 ///< Cannot add more Timed APB zone.
#define BS_SDK_ERROR_FIRE_ALARM_ZONE_FULL                   -1210 ///< Cannot add more fire alarm zone.
#define BS_SDK_ERROR_SCHEDULED_LOCK_UNLOCK_ZONE_FULL        -1211 ///< Cannot add more scheduled lock/unlock zone.
#define BS_SDK_ERROR_INACTIVE_ZONE                          -1212 ///< Inactive zone.
#define BS_SDK_ERROR_INTRUSION_ALARM_ZONE_FULL              -1213 ///< No more intrusion alarm zone can be added.
#define BS_SDK_ERROR_CANNOT_ARM                             -1214 ///< Cannot switch to alarm mode.
#define BS_SDK_ERROR_CANNOT_DISARM                          -1215 ///< Cannot switch to disalarm mode.
#define BS_SDK_ERROR_CANNOT_FIND_ARM_CARD                   -1216 ///< Cannot find alarm mode switch card.
#define BS_SDK_ERROR_HARD_ENTRANCE_LIMIT_COUNT_VIOLATION    -1217 ///< The number of Entrance limit area(Hard) exceeds the allowable number.
#define BS_SDK_ERROR_SOFT_ENTRANCE_LIMIT_COUNT_VIOLATION    -1218 ///< The number of Entrance limit area(Soft) exceeds the allowable number.
#define BS_SDK_ERROR_HARD_ENTRANCE_LIMIT_TIME_VIOLATION     -1219 ///< Entrance time limit (hard) time violation.
#define BS_SDK_ERROR_SOFT_ENTRANCE_LIMIT_TIME_VIOLATION     -1220 ///< Entrance time limit (soft) time violation.
#define BS_SDK_ERROR_INTERLOCK_ZONE_DOOR_VIOLATION          -1221 ///< Interlock zone door rule violation.
#define BS_SDK_ERROR_INTERLOCK_ZONE_INPUT_VIOLATION         -1222 ///< Interlock zone input rule violation.
#define BS_SDK_ERROR_INTERLOCK_ZONE_FULL                    -1223 ///< No more interlock zone can be added.
#define BS_SDK_ERROR_AUTH_LIMIT_SCHEDULE_VIOLATION          -1224 ///< Auth limit rule(schedule) violation.
#define BS_SDK_ERROR_AUTH_LIMIT_COUNT_VIOLATION             -1225 ///< Auth limit rule(count) violation.
#define BS_SDK_ERROR_AUTH_LIMIT_USER_VIOLATION              -1226 ///< Auth limit rule(user) violation.
#define BS_SDK_ERROR_SOFT_AUTH_LIMIT_VIOLATION              -1227 ///< Auth limit rule(network disconnected or soft auth limit) violation.
#define BS_SDK_ERROR_HARD_AUTH_LIMIT_VIOLATION              -1228 ///< Auth limit rule(network disconnected or hard auth limit) violation.

#define BS_SDK_ERROR_LIFT_LOCK_UNLOCK_ZONE_FULL             -1229 ///< No more Lift Lock/Unlock zone can be added.
#define BS_SDK_ERROR_LIFT_LOCK_VIOLATION                    -1230 ///< Lift lock/unlock schedule violation.

//Card errors
#define BS_SDK_ERROR_CARD_IO                                -1300 ///< Unsupported Card I/O.
#define BS_SDK_ERROR_CARD_INIT_FAIL                         -1301 ///< Failed to initialize card.
#define BS_SDK_ERROR_CARD_NOT_ACTIVATED                     -1302 ///< Card has not been activated.
#define BS_SDK_ERROR_CARD_CANNOT_READ_DATA                  -1303 ///< Cannot read data from card.
#define BS_SDK_ERROR_CARD_CIS_CRC                           -1304 ///< CIS checksum error.
#define BS_SDK_ERROR_CARD_CANNOT_WRITE_DATA                 -1305 ///< Cannot write data on card.
#define BS_SDK_ERROR_CARD_READ_TIMEOUT                      -1306 ///< Card read timeout.
#define BS_SDK_ERROR_CARD_READ_CANCELLED                    -1307 ///< Card read canceled.
#define BS_SDK_ERROR_CARD_CANNOT_SEND_DATA                  -1308 ///< Failed to send card data.
#define BS_SDK_ERROR_CANNOT_FIND_CARD                       -1310 ///< Cannot find card.

// Operation
#define BS_SDK_ERROR_INVALID_PASSWORD                       -1400 ///< Invalid password.

// System
#define BS_SDK_ERROR_CAMERA_INIT_FAIL                       -1500 ///< Failed to initialize the camera.
#define BS_SDK_ERROR_JPEG_ENCODER_INIT_FAIL                 -1501 ///< Failed to initialize the JPEG encoder.
#define BS_SDK_ERROR_CANNOT_ENCODE_JPEG                     -1502 ///< Cannot encode to JPEG.
#define BS_SDK_ERROR_JPEG_ENCODER_NOT_INITIALIZED           -1503 ///< Failed to initialize Jpeg encoder.
#define BS_SDK_ERROR_JPEG_ENCODER_DEINIT_FAIL               -1504 ///< Unable to remove the Jpeg encoder.
#define BS_SDK_ERROR_CAMERA_CAPTURE_FAIL                    -1505 ///< Failed to capture image with the camera.
#define BS_SDK_ERROR_CANNOT_DETECT_FACE                     -1506 ///< Cannot detect face.
#define BS_SDK_ERROR_CANNOT_EXECUTE_THREAD                  -1507 ///< Cannot execute thread.

//ETC.
#define BS_SDK_ERROR_FILE_IO                                -2000 ///< Failed on file I/O operation.
#define BS_SDK_ERROR_ALLOC_MEM                              -2002 ///< Failed to allocate memory.
#define BS_SDK_ERROR_CANNOT_UPGRADE                         -2003 ///< Failed on upgrade.
#define BS_SDK_ERROR_DEVICE_LOCKED                          -2004 ///< Device is locked.
#define BS_SDK_ERROR_CANNOT_SEND_TO_SERVER                  -2005 ///< Cannot send data to server.
#define BS_SDK_ERROR_CANNOT_UPGRADE_MEMOEY                  -2006 ///< Cannot upgrade memory.
#define BS_SDK_ERROR_UPGRADE_NOT_SUPPORTED                  -2007 ///< Upgrade is not supported.

//SSL
#define BS_SDK_ERROR_SSL_INIT                               -3000 ///< SSL initialization error.
#define BS_SDK_ERROR_SSL_EXIST                              (DEPRECATED_MAC)-3001 ///< @deprecated Deprecated since 2.7.2. Use BS_SDK_ERROR_SSL_NOT_SUPPORTED.
#define BS_SDK_ERROR_SSL_NOT_SUPPORTED                      -3001 ///< SSL is not supported.
#define BS_SDK_ERROR_SSL_IS_NOT_CONNECTED                   (DEPRECATED_MAC)-3002 ///< @deprecated Deprecated since 2.7.2. Use BS_SDK_ERROR_SSL_CANNOT_CONNECT.
#define BS_SDK_ERROR_SSL_CANNOT_CONNECT                     -3002 ///< Cannot connect via SSL.
#define BS_SDK_ERROR_SSL_ALREADY_CONNECTED                  -3003 ///< SSL is already connected.
#define BS_SDK_ERROR_SSL_INVALID_CA                         (DEPRECATED_MAC)-3004 ///< @deprecated Deprecated since 2.7.2. Use BS_SDK_ERROR_SSL_INVALID_CERT.
#define BS_SDK_ERROR_SSL_INVALID_CERT                       -3004 ///< Invalid SSL certificate.
#define BS_SDK_ERROR_SSL_VERIFY_CA                          (DEPRECATED_MAC)-3005 ///< @deprecated Deprecated since 2.7.2. Use BS_SDK_ERROR_SSL_VERIFY_CERT.
#define BS_SDK_ERROR_SSL_VERIFY_CERT                        -3005 ///< SSL certificate verification failed.
#define BS_SDK_ERROR_SSL_INVALID_KEY                        -3006 ///< Invalid SSL key.
#define BS_SDK_ERROR_SSL_VERIFY_KEY                         -3007 ///< SSL key verification failed.

// Mobile access
#define BS_SDK_ERROR_MOBILE_PORTAL                          -3100 ///< Mobile portal error.

// OSDP
#define BS_SDK_ERROR_NOT_OSDP_STANDARD_CHANNEL              -4001 ///< Not an OSDP standard channel.
#define BS_SDK_ERROR_ALREADY_FULL_SLAVES                    -4002 ///< No more slave devices can be added.
#define BS_SDK_ERROR_DUPLICATE_OSDP_ID                      -4003 ///< Duplicated OSDP ID.
#define BS_SDK_ERROR_FAIL_ADD_OSDP_DEVICE                   -4004 ///< Failed to add OSDP device.
#define BS_SDK_ERROR_FAIL_UPDATE_OSDP_DEVICE                -4005 ///< Failed to update OSDP device.
#define BS_SDK_ERROR_INVALID_OSDP_DEVICE_ID                 -4006 ///< Invalid OSDP device ID.
#define BS_SDK_ERROR_FAIL_MASTER_SET_KEY                    -4007 ///< Failed to set master OSDP security key.
#define BS_SDK_ERROR_FAIL_SLAVE_SET_KEY                     -4008 ///< Failed to set slave OSDP security key.
#define BS_SDK_ERROR_DISCONNECT_SLAVE_DEVICE                -4009 ///< Slave device disconnected.

// license
#define BS_SDK_ERROR_NO_LICENSE                             -4010 ///< No license.
#define BS_SDK_ERROR_LICENSE_CRC                            -4011 ///< License CRC error.
#define BS_SDK_ERROR_LICENSE_FILE_NOT_VALID                 -4012 ///< License file is not valid.
#define BS_SDK_ERROR_LICENSE_PAYLOAD_LENGTH                 -4013 ///< License payload length error.
#define BS_SDK_ERROR_LICENSE_PARRING_JSON                   -4014 ///< License JSON parsing error.
#define BS_SDK_ERROR_LICENSE_JSON_FORMAT                    -4015 ///< License JSON format error.
#define BS_SDK_ERROR_LICENSE_ENABLE_PARTIAL                 -4016 ///< License partial activation error.
#define BS_SDK_ERROR_LICENSE_NO_MATCH_DEVICE                -4017 ///< License does not match device.

#define BS_SDK_ERROR_UZ_ENABLE_COUNT_ZERO                   -4020 ///< User zone enable count is zero.
#define BS_SDK_ERROR_UZ_ENABLE_FULL                         -4021 ///< User zone enable count is full.
#define BS_SDK_ERROR_UZ_CHANNEL_FULL                        -4022 ///< User zone channel is full.
#define BS_SDK_ERROR_UZ_SPEC_FULL                           -4023 ///< User zone spec is full.
#define BS_SDK_ERROR_UZ_ADD_FAIL                            -4024 ///< Failed to add user zone.

#define BS_SDK_ERROR_NULL_POINTER                           -10000 ///< Wrong pointer.
#define BS_SDK_ERROR_UNINITIALIZED                          -10001 ///< SDK not initialized.
#define BS_SDK_ERROR_CANNOT_RUN_SERVICE                     -10002 ///< Cannot run SDK service.
#define BS_SDK_ERROR_CANCELED                               -10003 ///< Canceled.
#define BS_SDK_ERROR_EXIST                                  -10004 ///< Already exists.
#define BS_SDK_ERROR_ENCRYPT                                -10005 ///< Failed on encryption.
#define BS_SDK_ERROR_DECRYPT                                -10006 ///< Failed on decryption.
#define BS_SDK_ERROR_DEVICE_BUSY							-10007 ///< Device cannot response.
#define BS_SDK_ERROR_INTERNAL								-10008 ///< Internal SDK error.
#define BS_SDK_ERROR_INVALID_FILE_FORMAT					-10009 ///< Invalid file format.
#define BS_SDK_ERROR_INVALID_SCHEDULE_ID					-10010 ///< Invalid schedule ID.
#define BS_SDK_ERROR_UNKNOWN_FINGER_TEMPLATE                -10011 ///< Not supported fingerprint template. (Template type is not Suprema, ANSI or ISO)

// Mobile access (defined from SDK)
#define BS_SDK_ERROR_MOBILE_STATUS_FAULT                    -10100 ///< Mobile access status fault.
#define BS_SDK_ERROR_MOBILE_NO_RESPONSE                     -10101 ///< Mobile access no response.
#define BS_SDK_ERROR_MOBILE_NOT_LOGIN						-10103 ///< Mobile access not logged in.
#define BS_SDK_ERROR_MOBILE_ADD_DEVICE_FAULT                -10104 ///< Mobile access failed to add device.
#define BS_SDK_ERROR_MOBILE_DEVICE_NOT_FOUND				-10105 ///< Mobile access device not found.

#define BS_SDK_ERROR_INITIALIZE_FILELOG                     -10201 ///< Failed to initialize file log.
#define BS_SDK_ERROR_INITIALIZE_NOTIFYMGR                   -10202 ///< Failed to initialize notification manager.

#endif /* CORE_JNI_SRC_BS_ERRNO_H_ */
