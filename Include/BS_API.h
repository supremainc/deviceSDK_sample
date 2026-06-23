/*
 * BS_API.h
 *
 *  Created on: 2015. 4. 10.
 *      Author: scpark
 */

#ifndef CORE_SRC_BS_API_H_
#define CORE_SRC_BS_API_H_

#include "BSCommon/BS2Types.h"
#include "BSCommon/config/BS2FactoryConfig.h"
#include "BSCommon/config/BS2SystemConfig.h"
#include "BSCommon/config/BS2AuthConfig.h"
#include "BSCommon/config/BS2StatusConfig.h"
#include "BSCommon/config/BS2DisplayConfig.h"
#include "BSCommon/config/BS2IpConfig.h"
#include "BSCommon/config/BS2IPV6Config.h" //[IPv6 Cfg] 
#include "BSCommon/config/BS2IpConfigExt.h"
#include "BSCommon/config/BS2TnaExtConfig.h"
#include "BSCommon/config/BS2CardConfig.h"
#include "BSCommon/config/BS2FingerprintConfig.h"
#include "BSCommon/config/BS2Rs485Config.h"
#include "BSCommon/config/BS2WiegandConfig.h"
#include "BSCommon/config/BS2WiegandDeviceConfig.h"
#include "BSCommon/config/BS2InputConfig.h"
#include "BSCommon/config/BS2WlanConfig.h"
#include "BSCommon/config/BS2TriggerActionConfig.h"
#include "BSCommon/config/BS2EventConfig.h"
#include "BSCommon/config/BS2WiegandMultiConfig.h"
#include "BSCommon/config/BS1CardConfig.h"
#include "BSCommon/config/BS2SystemConfigExt.h"
#include "BSCommon/config/BS2VoipConfig.h"
#include "BSCommon/config/BS2FaceConfig.h"
#include "BSCommon/config/BS2DstConfig.h"
#include "BSCommon/config/BS2ConfigHeader.h"
#include "BSCommon/config/BS2ConfigHeaderEx.h"
#include "BSCommon/config/BS2DeviceZoneMasterConfig.h"
#include "BSCommon/config/BS2DeviceZoneConfig.h"
#include "BSCommon/data/BS2AccessGroup.h"
#include "BSCommon/data/BS2AccessLevel.h"
#include "BSCommon/data/BS2FloorLevel.h"
#include "BSCommon/data/BS2Action.h"
#include "BSCommon/data/BS2AntiPassbackZone.h"
#include "BSCommon/data/BS2BlackList.h"
#include "BSCommon/data/BS2CSNCard.h"
#include "BSCommon/data/BS2DaySchedule.h"
#include "BSCommon/data/BS2Device.h"
#include "BSCommon/data/BS2Door.h"
#include "BSCommon/data/BS2Lift.h"
#include "BSCommon/data/BS2Event.h"
#include "BSCommon/data/BS2EventExt.h"
#include "BSCommon/data/BS2Face.h"
#include "BSCommon/data/BS2FaceEx.h"
#include "BSCommon/data/BS2Fingerprint.h"
#include "BSCommon/data/BS2FireAlarmZone.h"
#include "BSCommon/data/BS2ScheduledLockUnlockZone.h"
#include "BSCommon/data/BS2Holiday.h"
#include "BSCommon/data/BS2Resource.h"
#include "BSCommon/data/BS2Rs485Channel.h"
#include "BSCommon/data/BS2Rs485SlaveDeviceSetting.h"
#include "BSCommon/data/BS2Schedule.h"
#include "BSCommon/data/BS2SmartCard.h"
#include "BSCommon/data/BS2TimedAntiPassbackZone.h"
#include "BSCommon/data/BS2Trigger.h"
#include "BSCommon/data/BS2User.h"
#include "BSCommon/data/BS2Zone.h"
#include "BSCommon/data/BS2AuthGroup.h"
#include "BSCommon/data/BS2IntrusionAlarmZone.h"
#include "BSCommon/data/BS2InterlockZone.h"
#include "BSCommon/data/BS2LiftLockUnlockZone.h"
#include "BSCommon/data/BS2Operator.h" //[Admin 1000] 
#include "BSCommon/data/BS2UserOverride.h"
#include "BSCommon/data/BS2LockOverride.h"
#include "BSCommon/data/BS2IO.h"
 //[Admin 1000] 
#include "BSCommon/protocol/BS2UdpDiscover.h"
#include "BSCommon/protocol/BS2SystemInfo.h"
#include "BSCommon/config/BS2AuthConfigExt.h"
#include "BSCommon/config/BS2FaceConfigExt.h"
#include "BSCommon/config/BS2ThermalCameraConfig.h"
#include "BSCommon/config/BS2BarcodeConfig.h"
#include "BSCommon/protocol/BS2DeviceInfo.h"
#include "BSCommon/config/BS2RelayActionConfig.h"
#include "BSCommon/config/BS2VoipConfigExt.h"
#include "BSCommon/config/BS2RtspConfig.h"
#include "BSCommon/config/BS2OsdpStandardActionConfig.h"
#include "BSCommon/config/BS2OsdpStandardConfig.h"
#include "BSCommon/config/BS2LicenseConfig.h"
#include "BSCommon/config/BS2FaceConfigExt.h"
#include "BSCommon/config/BS2FacilityCodeConfig.h"
#include "BS_Deprecated.h"

#ifdef BS_SDK_V2_DLL
#define BS_API_EXPORT __declspec(dllimport)
#define BS_CALLING_CONVENTION __cdecl
#else
#define BS_API_EXPORT
#define BS_CALLING_CONVENTION
#endif


#ifndef BS2_MAX_NUM_OF_CARD_PER_USER
#define BS2_MAX_NUM_OF_CARD_PER_USER                8
#endif

#ifndef BS2_MAX_NUM_OF_CARD_PER_MASTERADMIN
#define BS2_MAX_NUM_OF_CARD_PER_MASTERADMIN			4
#endif

#ifndef BS2_MAX_NUM_OF_FINGER_PER_USER
#define BS2_MAX_NUM_OF_FINGER_PER_USER              10
#endif

#ifndef BS2_MAX_NUM_OF_FACE_PER_USER
#define BS2_MAX_NUM_OF_FACE_PER_USER                5
#endif

#ifndef BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER
#define BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER        16
#endif

#define BS2_SSL_CONNECT_TIMEOUT						(20*1000)

#define DEFAULT_RESPONSE_TIMEOUT_MS					(10*1000) //[Set/Get default response wait timeout] 
#define DEFAULT_LONG_RESPONSE_TIMEOUT_MS			(30*1000) // DSDKIIT-55 Long operation timeout

#define All_nodes_in_the_interface_local	"FF01::1" //All node multicast (in the interface local)
#define All_nodes_in_the_link_local			"FF02::1" //All node multicast (in the link local)
#define All_routers_in_the_interface_local	"FF01::2" //All router multicast (in the interface local)
#define All_routers_in_the_link_local		"FF02::2" //All router multicast (in the link local)
#define All_routers_in_the_site_local		"FF05::2" //All router multicast (in the site local)
#define OSPFIGP_routers						"FF02::5" //OSPF router (link-local)
#define OSPFIGP_designated_routers			"FF02::6" //OSPF DR/BDR (link-local)
#define RIP_routers							"FF02::9" //RIPng router (link-local)
#define EIGRP_routers						"FF02::A" //EIGRP router (link-local)
#define Mobile_agents						"FF02::B" //Mobile agents (link-local)
#define All_PIM_routers						"FF02::D" //PIM router (link-local)
#define All_MLDv2_capable_routers			"FF02::16" //MLDv2 capable router (link-local)
#define All_dhcp_agents						"FF02::1:2" //DHCPv6 agents (link-local)
#define All_dhcp_servers					"FF05::1:3" //DHCPv6 servers (site-local)
//#define 									"FF02:1:FF::" //Solicited node multicast (link-local)

#define DEFAULT_MULTICAST_IPV6_ADDRESS 		All_routers_in_the_site_local
#define DEFAULT_BROADCAST_IPV4_ADDRESS 		"255.255.255.255"

#pragma pack(1)

typedef struct
{
	BS2User user;
	BS2UserSetting setting;
	BS2_USER_NAME user_name;
	BS2UserPhoto user_photo;
	BS2_USER_PIN pin;
	BS2CSNCard* cardObjs;
	BS2Fingerprint* fingerObjs;
	BS2Face* faceObjs;
	BS2_ACCESS_GROUP_ID accessGroupId[BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER];
}BS2UserBlob;

typedef struct
{
	BS2User user;
	BS2UserSetting setting;
	BS2_USER_NAME user_name;
	BS2UserPhoto user_photo;
	BS2_USER_PIN pin;
	BS2CSNCard* cardObjs;
	BS2Fingerprint* fingerObjs;
	BS2Face* faceObjs;
	BS2Job job;
	BS2_USER_PHRASE phrase;
	BS2_ACCESS_GROUP_ID accessGroupId[BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER];
}BS2UserBlobEx;

typedef struct
{
	uint16_t eventMask;
	BS2_EVENT_ID id;
	BS2EventExtInfo info;                         // valid if eventMask has BS2_EVENT_MASK_INFO
	union
	{
		BS2_USER_ID userID;                       // valid if eventMask has BS2_EVENT_MASK_USER_ID
		uint8_t cardID[BS2_CARD_DATA_SIZE];       // valid if eventMask has BS2_EVENT_MASK_CARD_ID
		BS2_DOOR_ID doorID;                       // valid if eventMask has BS2_EVENT_MASK_DOOR_ID
		BS2_ZONE_ID zoneID;                       // valid if eventMask has BS2_EVENT_MASK_ZONE_ID
		BS2EventExtIoDevice ioDevice;             // valid if eventMask has BS2_EVENT_MASK_IODEVICE
	};
	BS2_TNA_KEY tnaKey;                           // valid if eventMask has BS2_EVENT_MASK_TNA_KEY
	BS2_JOB_CODE jobCode;                         // valid if eventMask has BS2_EVENT_MASK_JOB_CODE
	uint16_t imageSize;                           // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t image[BS2_EVENT_MAX_IMAGE_SIZE];      // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t reserved;
}BS2EventBlob;

typedef struct
{
	BS2_DEVICE_ID id;
	BS2_DEVICE_TYPE type;
	BS2_CONNECTION_MODE connectionMode;
    uint32_t ipv4Address;
    BS2_PORT port;
    uint32_t maxNumOfUser;
	uint8_t userNameSupported;
	uint8_t userPhotoSupported;
	uint8_t pinSupported;
	uint8_t cardSupported;
	uint8_t fingerSupported;
	uint8_t faceSupported;
	uint8_t wlanSupported;
	uint8_t tnaSupported;
	uint8_t triggerActionSupported;
	uint8_t wiegandSupported;
	uint8_t imageLogSupported;
	uint8_t dnsSupported;
	uint8_t jobCodeSupported;
	uint8_t wiegandMultiSupported;
	BS2_RS485_MODE rs485Mode;
	uint8_t sslSupported;
	uint8_t rootCertExist;
	uint8_t dualIDSupported;
	uint8_t useAlphanumericID;
	uint32_t connectedIP;
	uint8_t phraseSupported;
	uint8_t card1xSupported;
	uint8_t systemExtSupported;
	uint8_t voipSupported;	
	uint8_t rs485ExSupported;
	uint8_t	cardExSupported;		
}BS2SimpleDeviceInfo;

typedef struct
{
	enum
	{
		BS2_SUPPORT_RS485EX 		= 0x00000001,
		BS2_SUPPORT_CARDEX  		= 0x00000002,
		BS2_SUPPORT_DST     		= 0x00000004,
		BS2_SUPPORT_DESFIREEX		= 0x00000008,
		
		BS2_SUPPORT_FACE_EX			= 0x00000010,
		BS2_SUPPORT_QR				= 0x00000020,

		BS2_SUPPORT_FINGER_SCAN		= 0x00010000,
		BS2_SUPPORT_FACE_SCAN		= 0x00020000,
		BS2_SUPPORT_FACE_EX_SCAN	= 0x00040000,
		BS2_SUPPORT_QR_SCAN			= 0x00080000,

		BS2_SUPPORT_VOIPEX			= 0x01000000,

		BS2_SUPPORT_ALL     		= BS2_SUPPORT_RS485EX |
									  BS2_SUPPORT_CARDEX |
									  BS2_SUPPORT_DST |
									  BS2_SUPPORT_DESFIREEX |
									  BS2_SUPPORT_FACE_EX |
									  BS2_SUPPORT_QR |
									  BS2_SUPPORT_FINGER_SCAN |
									  BS2_SUPPORT_FACE_SCAN |
									  BS2_SUPPORT_FACE_EX_SCAN |
									  BS2_SUPPORT_QR_SCAN |
									  BS2_SUPPORT_VOIPEX,
	};

	uint32_t supported;
	uint8_t  reserved[4];
}BS2SimpleDeviceInfoEx;

typedef struct
{
	uint32_t configMask;
	BS2FactoryConfig factoryConfig;
	BS2SystemConfig systemConfig;
	BS2AuthConfig authConfig;
	BS2StatusConfig statusConfig;
	BS2DisplayConfig displayConfig;
	BS2IpConfig ipConfig;
	BS2IpConfigExt ipConfigExt;
	BS2TNAConfig tnaConfig;
	BS2CardConfig cardConfig;
	BS2FingerprintConfig fingerprintConfig;
	BS2Rs485Config rs485Config;
	BS2WiegandConfig wiegandConfig;
	BS2WiegandDeviceConfig wiegandDeviceConfig;
	BS2InputConfig inputConfig;
	BS2WlanConfig wlanConfig;
	BS2TriggerActionConfig triggerActionConfig;
	BS2EventConfig eventConfig;
	BS2WiegandMultiConfig wiegandMultiConfig;
	BS1CardConfig card1xConfig;
	BS2SystemConfigExt systemExtConfig;
	BS2VoipConfig voipConfig;
	BS2FaceConfig faceConfig;
}BS2Configs;

typedef struct
{
	BS2_RESOURCE_TYPE type;
	uint32_t numResData;
	struct {
		uint8_t index;
		uint32_t dataLen;
		uint8_t* data;
	}resData[128];
}BS2ResourceElement;

typedef struct
{
	uint8_t isSmartCard;
	union
	{
		BS2CSNCard card;
		BS2SmartCardData smartCard;
	};
}BS2Card;

typedef struct
{
	BS2_DEVICE_ID parentDeviceID;
	BS2_DEVICE_ID deviceID;
	BS2_DEVICE_TYPE deviceType;
}BS2DeviceNode;

typedef struct
{
	int numSensors;  
	BS2FireSensor sensor[BS2_MAX_FIRE_SENSORS_PER_FIRE_ALARM_ZONE];
	BS2Action action[BS2_MAX_FIRE_ALARM_ACTION];
}BS2FireAlarmZoneProperty;

typedef struct
{
	BS2Action action[BS2_MAX_APB_ALARM_ACTION];
}BS2APBZoneProperty;

typedef struct
{
	int zoneId;
	int zoneType;
	union
	{
		BS2APBZoneProperty apbProperty;
		BS2FireAlarmZoneProperty fireAlarmProperty;
	};
}BS2ZoneEx;

/**
 *  BS2AntiPassbackZone
 */
typedef struct {
	BS2_ZONE_ID zoneID;					///< 4 bytes
	char name[BS2_MAX_ZONE_NAME_LEN];		///< 48 * 3 bytes

	BS2_APB_ZONE_TYPE type;				///< 1 byte
	uint8_t numReaders;					///< 1 byte
	uint8_t numBypassGroups;				///< 1 byte
	BS2_BOOL disabled;				///< 1 byte

	BS2_BOOL alarmed;				///< 1 byte
	uint8_t reserved[3];				///< 3 bytes (packing)

	uint32_t resetDuration;				///< 4 bytes: in seconds, 0: no reset

	BS2Action alarm[BS2_MAX_APB_ALARM_ACTION];		///< 32 * 5 bytes

	BS2ApbMember readers[BS2_MAX_READERS_PER_APB_ZONE];		///< 8 * 64 bytes
	uint8_t reserved2[8 * 64];		///< 8 * 64 bytes (packing)

	BS2_ACCESS_GROUP_ID bypassGroupIDs[BS2_MAX_BYPASS_GROUPS_PER_APB_ZONE];		///< 4 * 16 bytes
} BS2APBZoneConfig;

typedef struct
{
	uint32_t authGroupID;
	uint32_t numUsers;
	BS2_USER_ID* userObjs;
}BS2AuthUserBlob;

typedef struct
{
	BS2IntrusionAlarmZone IntrusionAlarmZone;
	BS2AlarmZoneMember* memberObjs;
	BS2AlarmZoneInput* inputObjs;
	BS2AlarmZoneOutput* outputObjs;
	BS2CSNCard* cardObjs;
	BS2_DOOR_ID* doorIDs;
	BS2_ACCESS_GROUP_ID* groupIDs;
}BS2IntrusionAlarmZoneBlob;

typedef struct
{
	BS2InterlockZone InterlockZone;
	BS2InterlockZoneInput* inputObjs;
	BS2InterlockZoneOutput* outputObjs;
	BS2_DOOR_ID* doorIDs;
}BS2InterlockZoneBlob;


enum
{
	BS2_ENC_KEY_SIZE      = 32,
};

/**
 * BS2EncryptKey
 */
typedef struct
{
	uint8_t key[BS2_ENC_KEY_SIZE];
	uint8_t reserved[32];
} BS2EncryptKey;

//[IPv6]
typedef struct
{
	BS2_DEVICE_ID id;
	uint8_t reserved[1];
	uint8_t bIPv6Mode;
	BS2_IPV6_ADDR ipv6Address;
    BS2_PORT portV6;	
	BS2_IPV6_ADDR connectedIPV6;	
	uint8_t numOfAllocatedAddressV6;
	BS2_IPV6_ADDR allocatedIpAddressV6[BS2_MAX_IPV6_ALLOCATED_ADDR]; 
}BS2IPv6DeviceInfo;

typedef enum 
{
	BS2_SPECIFIED_DEVICE_INFO_SIMPLE 		= 1,
	BS2_SPECIFIED_DEVICE_INFO_SIMPLE_EX 	= 2,
	BS2_SPECIFIED_DEVICE_INFO_IPV6			= 3,
}BS2EnumSpecifiedDeviceInfo;


//User Small Blob
typedef struct
{
	BS2User user;
	BS2UserSetting setting;
	BS2_USER_NAME user_name;
	BS2UserPhoto* user_photo_obj;
	BS2_USER_PIN pin;
	BS2CSNCard* cardObjs;
	BS2Fingerprint* fingerObjs;
	BS2Face* faceObjs;
	BS2_ACCESS_GROUP_ID accessGroupId[BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER];
}BS2UserSmallBlob;

typedef struct
{
	BS2User user;
	BS2UserSetting setting;
	BS2_USER_NAME user_name;
	BS2UserPhoto* user_photo_obj;
	BS2_USER_PIN pin;
	BS2CSNCard* cardObjs;
	BS2Fingerprint* fingerObjs;
	BS2Face* faceObjs;
	BS2Job job;
	BS2_USER_PHRASE phrase;
	BS2_ACCESS_GROUP_ID accessGroupId[BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER];
}BS2UserSmallBlobEx;

typedef struct
{
	BS2User user;
	BS2UserSetting setting;
	BS2_USER_NAME user_name;
	BS2UserPhoto* user_photo_obj;
	BS2_USER_PIN pin;
	BS2CSNCard* cardObjs;
	BS2Fingerprint* fingerObjs;
	BS2Face* faceObjs;						// FS2, FL
	BS2Job job;
	BS2_USER_PHRASE phrase;
	BS2_ACCESS_GROUP_ID accessGroupId[BS2_MAX_NUM_OF_ACCESS_GROUP_PER_USER];

	BS2UserSettingEx settingEx;				// F2
	BS2FaceEx* faceExObjs;					// F2
} BS2UserFaceExBlob;


typedef struct
{
	uint16_t eventMask;
	BS2_EVENT_ID id;
	BS2EventExtInfo info;                         // valid if eventMask has BS2_EVENT_MASK_INFO
	union
	{
		BS2_USER_ID userID;                       // valid if eventMask has BS2_EVENT_MASK_USER_ID
		uint8_t cardID[BS2_CARD_DATA_SIZE];       // valid if eventMask has BS2_EVENT_MASK_CARD_ID
		BS2_DOOR_ID doorID;                       // valid if eventMask has BS2_EVENT_MASK_DOOR_ID
		BS2_ZONE_ID zoneID;                       // valid if eventMask has BS2_EVENT_MASK_ZONE_ID
		BS2EventExtIoDevice ioDevice;             // valid if eventMask has BS2_EVENT_MASK_IODEVICE
	};
	BS2_TNA_KEY tnaKey;                           // valid if eventMask has BS2_EVENT_MASK_TNA_KEY
	BS2_JOB_CODE jobCode;                         // valid if eventMask has BS2_EVENT_MASK_JOB_CODE
	uint16_t imageSize;                           // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t* imageObj;                            // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t reserved;
}BS2EventSmallBlob;

typedef struct
{
	uint16_t eventMask;
	BS2_EVENT_ID id;
	BS2EventExtInfo info;                         // valid if eventMask has BS2_EVENT_MASK_INFO
	union
	{
		BS2_USER_ID userID;                       // valid if eventMask has BS2_EVENT_MASK_USER_ID
		uint8_t cardID[BS2_CARD_DATA_SIZE];       // valid if eventMask has BS2_EVENT_MASK_CARD_ID
		BS2_DOOR_ID doorID;                       // valid if eventMask has BS2_EVENT_MASK_DOOR_ID
		BS2_ZONE_ID zoneID;                       // valid if eventMask has BS2_EVENT_MASK_ZONE_ID
		BS2EventExtIoDevice ioDevice;             // valid if eventMask has BS2_EVENT_MASK_IODEVICE
	};
	BS2_TNA_KEY tnaKey;                           // valid if eventMask has BS2_EVENT_MASK_TNA_KEY
	BS2_JOB_CODE jobCode;                         // valid if eventMask has BS2_EVENT_MASK_JOB_CODE
	uint16_t imageSize;                           // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t* imageObj;                            // valid if eventMask has BS2_EVENT_MASK_IMAGE
	uint8_t reserved;
	uint32_t temperature;                         // valid if eventMask has BS2_EVENT_MASK_TEMPERATURE
} BS2EventSmallBlobEx;

typedef uint32_t BS2_CONFIG_MASK;

#pragma pack()

typedef void (*OnDeviceFound)(BS2_DEVICE_ID deviceId);
typedef void (*OnDeviceAccepted)(BS2_DEVICE_ID deviceId);
typedef void (*OnDeviceConnected)(BS2_DEVICE_ID deviceId);
typedef void (*OnDeviceDisconnected)(BS2_DEVICE_ID deviceId);
typedef void (*OnReadyToScan)(BS2_DEVICE_ID deviceId, uint32_t sequence);
typedef void (*OnProgressChanged)(BS2_DEVICE_ID deviceId, uint32_t progressPercentage);
typedef void (*OnLogReceived)(BS2_DEVICE_ID deviceId, const BS2Event* event);
typedef void (*OnLogReceivedEx)(BS2_DEVICE_ID deviceId, const BS2Event* event, BS2_TEMPERATURE temperature);
typedef void (*OnAlarmFired)(BS2_DEVICE_ID deviceId, const BS2Event* event);
typedef void (*OnInputDetected)(BS2_DEVICE_ID deviceId, const BS2Event* event);
typedef void (*OnBarcodeScanned)(BS2_DEVICE_ID deviceId, const char* barcode);
typedef void (*OnConfigChanged)(BS2_DEVICE_ID deviceId, uint32_t configMask);
typedef void (*OnVerifyUser)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, uint8_t isCard, uint8_t cardType, const uint8_t* data, uint32_t dataLen);
typedef void (*OnIdentifyUser)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, BS2_FINGER_TEMPLATE_FORMAT format, const uint8_t* templateData, uint32_t templateSize);
typedef int (*IsAcceptableUserID)(const char* uid);
typedef void(*OnSendRootCA)(BS2_DEVICE_ID deviceId, int result);
typedef void (*OnCheckGlobalAPBViolation)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, const char* userID_1, const char* userID_2, bool isDualAuth);
typedef void (*OnCheckGlobalAPBViolationByDoorOpen)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, const char* userID_1, const char* userID_2, bool isDualAuth);
typedef void (*OnUpdateGlobalAPBViolationByDoorOpen)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, const char* userID_1, const char* userID_2, bool isDualAuth);
typedef void (*OnUserPhrase)(BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, const char* userID);
typedef void (*OnOsdpStandardDeviceStatusChanged)(BS2_DEVICE_ID deviceId, const BS2OsdpStandardDeviceNotify* notifyData);

typedef uint32_t (*PreferMethod)(BS2_DEVICE_ID deviceID);
typedef const char* (*GetRootCaFilePath)(BS2_DEVICE_ID deviceID);
typedef const char* (*GetServerCaFilePath)(BS2_DEVICE_ID deviceID);
typedef const char* (*GetServerPrivateKeyFilePath)(BS2_DEVICE_ID deviceID);
typedef const char* (*GetPassword)(BS2_DEVICE_ID deviceID);
typedef void (*OnErrorOccured)(BS2_DEVICE_ID deviceID, int errCode);


//Debug
//Debug Print
#define DEBUG_KEEP_ALIVE                (0x1 << 0)
#define DEBUG_SOCKET_MANAGER            (0x1 << 1)
#define DEBUG_SOCKETBASE_HANDLER        (0x1 << 2)
#define DEBUG_DEVICE                    (0x1 << 3)
#define DEBUG_DEVICE_MANAGER            (0x1 << 4)
#define DEBUG_EVENT_DISPATCHER          (0x1 << 5)
#define DEBUG_API                       (0x1 << 6)
#define DEBUG_ALL                       0xFFFFFFFF
typedef void (*CBDebugPrint)(char* msg);

//DebugEx Print
#define DEBUG_MODULE_KEEP_ALIVE			(DEBUG_KEEP_ALIVE)
#define DEBUG_MODULE_SOCKET_MANAGER		(DEBUG_SOCKET_MANAGER)
#define DEBUG_MODULE_SOCKET_HANDLER		(DEBUG_SOCKETBASE_HANDLER)
#define DEBUG_MODULE_DEVICE				(DEBUG_DEVICE)
#define DEBUG_MODULE_DEVICE_MANAGER		(DEBUG_DEVICE_MANAGER)
#define DEBUG_MODULE_EVENT_DISPATCHER	(DEBUG_EVENT_DISPATCHER)
#define DEBUG_MODULE_API				(DEBUG_API)
#define DEBUG_MODULE_MISC				(0x1 << 7)
#define DEBUG_MODULE_PACKET				(0x1 << 8)
#define DEBUG_MODULE_MOBILEACCESS		(0x1 << 9)
#define DEBUG_MODULE_NOTIFY_MANAGER		(0x1 << 10)
#define DEBUG_MODULE_EVENT				(0x1 << 11)
#define DEBUG_MODULE_USB				(0x1 << 12)
#define DEBUG_MODULE_ALL				(DEBUG_ALL)
#define DEBUG_LOG_FATAL					(0x1 << 0)
#define DEBUG_LOG_ERROR					(0x1 << 1)
#define DEBUG_LOG_WARN					(0x1 << 2)
#define DEBUG_LOG_API					(0x1 << 3)		// Print IN and OUT of API
#define DEBUG_LOG_INFO					(0x1 << 4)
#define DEBUG_LOG_TRACE					(0x1 << 8)		// Modified bit mask value (V2.6.3.12)
#define DEBUG_LOG_SYSTEM				(0x0000000F)	// DEBUG_LOG_FATAL | DEBUG_LOG_ERROR | DEBUG_LOG_WARN | DEBUG_LOG_API
#define DEBUG_LOG_OPERATION_ALL			(0x000000FF)	// Output support except trace logs (V2.6.3.12)
#define DEBUG_LOG_ALL_WITHOUT_RELEASE	(0x0FFFFFFF)
#define DEBUG_LOG_ALL					(0xFFFFFFFF)
typedef void (*CBDebugExPrint)(uint32_t level, uint32_t module, const char* msg);

#ifdef __cplusplus
extern "C"
{
#endif

//Debug
// - Replaced
/**
 * @brief Outputs SDK log messages to a file for debugging purposes. [+ 2.6.3]
 * @ingroup group_debugging_api
 * @param[in] level Debug level bitmask (e.g., DEBUG_LOG_ALL, DEBUG_LOG_ERROR).
 * @param[in] module Module bitmask to filter log output (e.g., DEBUG_MODULE_ALL).
 * @param[in] logPath Path to the directory where log files will be stored. Log files are named in the form YYYYMMDD.log.
 * \sdkreturn
 * @include{doc} bs2_setdebugfilelog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDebugFileLog(uint32_t level, uint32_t module, const char* logPath);

/**
 * @brief Outputs SDK log messages to split files for debugging purposes. [+ 2.8.3]
 * @ingroup group_debugging_api
 * @param[in] level Debug level bitmask (e.g., DEBUG_LOG_ALL, DEBUG_LOG_ERROR).
 * @param[in] module Module bitmask to filter log output (e.g., DEBUG_MODULE_ALL).
 * @param[in] logPath Path to the directory where log files will be stored. Log files are named in the form YYYYMMDD_x.log.
 * @param[in] fileMaxSizeMB Maximum size of each log file in megabytes. Set to 0 to disable file splitting.
 * sdkreturn
 * @include{doc} bs2_setdebugfilelogex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDebugFileLogEx(uint32_t level, uint32_t module, const char* logPath, int fileMaxSizeMB);

// - Deprecated
/**
 * @brief Registers a callback function for debug messages.
 * @ingroup group_debugging_api
 * @deprecated Use BS2_SetDebugExCallback() instead.
 * @param[in] ptrCBDebugPrint Callback function that receives debug print messages.
 * @param[in] debugLevel Debug level value.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
DEPRECATED_FUNC BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDebugLevel(CBDebugPrint ptrCBDebugPrint, uint32_t debugLevel);

/**
 * @brief Registers the callback function that gets called for debugging messages. [+ 2.5.0]
 * @ingroup group_debugging_api
 * @deprecated Use BS2_SetDebugFileLog() or BS2_SetDebugFileLogEx() instead.
 * @param[in] ptrCBDebugExPrint Callback function that is called for debugging messages.
 * @param[in] level @parblock
 *   Debugging information level bitmask (e.g., 0xFFFFFFFF for all).
 *
 *   | Value      | Description |
 *   |------------|-------------|
 *   | 0x00000000 | None        |
 *   | 0x00000001 | Fatal       |
 *   | 0x00000002 | Error       |
 *   | 0x00000004 | Warning     |
 *   | 0x00000008 | Information |
 *   | 0x00000010 | Trace       |
 *   | 0xFFFFFFFF | All         |
 *   @endparblock
 * @param[in] module Debugging module bitmask (e.g., 0xFFFFFFFF for all).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdebugexcallback.md
 */
DEPRECATED_FUNC BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDebugExCallback(CBDebugExPrint ptrCBDebugExPrint, uint32_t level, uint32_t module);

//SDK API
/**
 * @brief Returns the SDK version string.
 * @ingroup group_sdk_api
 * @return Null-terminated string representing the SDK version (e.g. "2.9.12.0").
 * @include{doc} bs2_version.md
 */
BS_API_EXPORT const char* BS_CALLING_CONVENTION BS2_Version();

/**
 * @brief Allocates and returns a new SDK context handle.
 * @ingroup group_sdk_api
 * @return Pointer to the allocated context, or NULL on failure. Must be released with BS2_ReleaseContext().
 * @include{doc} bs2_allocatecontext.md
 */
BS_API_EXPORT void* BS_CALLING_CONVENTION BS2_AllocateContext();

/**
 * @brief Releases the SDK context and all associated resources.
 * @ingroup group_sdk_api
 * @param[in] context SDK context handle allocated by BS2_AllocateContext().
 * @include{doc} bs2_releasecontext.md
 */
BS_API_EXPORT void BS_CALLING_CONVENTION BS2_ReleaseContext(void* context);

/**
 * @brief Initializes the SDK context. Must be called before any device control API.
 * @ingroup group_sdk_api
 * @param[in] context SDK context handle.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_initialize.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_Initialize(void* context);

/**
 * @brief Initializes the SDK context and binds the socket to the specified host IP address. [+ 2.9.6]
 * @ingroup group_sdk_api
 * @param[in] context SDK context handle.
 * @param[in] hostIPAddr Host IP address to bind the socket to.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_initializeex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_InitializeEx(void* context, const char* hostIPAddr);

/**
 * @brief Releases dynamically allocated memory returned by SDK APIs.
 * @ingroup group_sdk_api
 * @param[in] object Pointer to the dynamically allocated memory to release.
 * @include{doc} bs2_releaseobject.md
 */
BS_API_EXPORT void BS_CALLING_CONVENTION BS2_ReleaseObject(void* object);

//Timeout
/**
 * @brief Sets the timeout for device searching operations (BS2_SearchDevices / BS2_SearchDevicesEx).
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] second Timeout in seconds. Default is 5 seconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicesearchingtimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceSearchingTimeout(void* context, uint32_t second);

/**
 * @brief Gets the SSL handshake timeout value.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[out] second Pointer to store the current SSL handshake timeout in seconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSSLHandshakeTimeout(void* context, uint32_t* second);

/**
 * @brief Sets the SSL handshake timeout value.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] second SSL handshake timeout in seconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSSLHandshakeTimeout(void* context, uint32_t second);

/**
 * @brief Sets the maximum number of threads used by the SDK.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] maxThreadCount Maximum thread count. Default is 4 * CPU core count. Cannot be set lower than 8.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setmaxthreadcount.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetMaxThreadCount(void* context, uint32_t maxThreadCount);

/**
 * @brief Sets the maximum number of connection threads used by the SDK.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] maxThreadCount Maximum connection thread count.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetMaxConnectThreadCount(void* context, uint32_t maxThreadCount);

/**
 * @brief Gets the retry count for read/write failures during Non-SSL socket communication. [+ 2.9.1]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[out] count Pointer to store the current retry count setting value.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsocketretrycount.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSocketRetryCount(void* context, uint32_t* count);

/**
 * @brief Sets the retry count for read/write failures during Non-SSL socket communication. [+ 2.9.1]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] count Retry count to set.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsocketretrycount.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSocketRetryCount(void* context, uint32_t count);

/**
 * @brief Gets the retry count for read/write failures during SSL socket communication. [+ 2.9.1]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[out] count Pointer to store the current SSL retry count setting value.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsocketsslretrycount.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSocketSSLRetryCount(void* context, uint32_t* count);

/**
 * @brief Sets the retry count for read/write failures during SSL socket communication. [+ 2.9.1]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] count Retry count to set.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsocketsslretrycount.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSocketSSLRetryCount(void* context, uint32_t count);

//Communication API
/**
 * @brief Checks whether auto connection is enabled.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[out] enable Pointer to store whether auto connection is enabled (non-zero) or disabled (0).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_isautoconnection.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IsAutoConnection(void* context, int* enable);

/**
 * @brief Sets the auto connection mode.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] enable Set to non-zero to enable auto connection, 0 to disable.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setautoconnection.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAutoConnection(void* context, int enable);

/**
 * @brief Registers callback functions for device search and network connection events.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] ptrDeviceFound Callback function called when a new device is found in the subnet.
 * @param[in] ptrDeviceAccepted Callback function called when a device requests connection to the application.
 * @param[in] ptrDeviceConnected Callback function called when a device is connected.
 * @param[in] ptrDeviceDisconnected Callback function called when a device is disconnected.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdeviceeventlistener.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceEventListener(void* context,
                                            OnDeviceFound ptrDeviceFound,
											OnDeviceAccepted ptrDeviceAccepted,
                                            OnDeviceConnected ptrDeviceConnected,
                                            OnDeviceDisconnected ptrDeviceDisconnected);

/**
 * @brief Sets the notification listener for alarm, input, and configuration change events.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] ptrAlarmFired Callback function called when an alarm configured to a zone triggers.
 * @param[in] ptrInputDetected Callback function called when an input signal is detected.
 * @param[in] ptrConfigChanged Callback function called when the device configuration is modified.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setnotificationlistener.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetNotificationListener(void* context,
											OnAlarmFired ptrAlarmFired,
											OnInputDetected ptrInputDetected,
											OnConfigChanged ptrConfigChanged);

/**
 * @brief Registers the listener function that detects barcode input. [+ 2.8.2]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] ptrBarcodeScanned Callback function called when a barcode is scanned on the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setbarcodescanlistener.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetBarcodeScanListener(void* context,
											OnBarcodeScanned ptrBarcodeScanned);

/**
 * @brief Sets the server port for device connections.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] serverPort Port number the server listens on.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setserverport.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetServerPort(void* context, BS2_PORT serverPort);

/**
 * @brief Searches for BioStar devices in the subnet and refreshes the device list.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_searchdevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SearchDevices(void* context);

/**
 * @brief Searches for devices in a specific IP address band and updates the device list.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] hostipAddr Host IP address defining the UDP broadcast range to search.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_searchdevicesex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SearchDevicesEx(void* context, const char* hostipAddr);

/**
 * @brief Gets the list of managed device IDs.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[out] deviceListObj Pointer to an array of device IDs. Must be released with BS2_ReleaseObject().
 * @param[out] numDevice Pointer to store the number of devices in the list.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDevices(void* context, BS2_DEVICE_ID** deviceListObj, uint32_t* numDevice);

/**
 * @brief Gets device information including device ID, type, and network settings.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID.
 * @param[out] deviceInfo Pointer to a BS2SimpleDeviceInfo structure to store device information.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdeviceinfo.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceInfo(void* context, BS2_DEVICE_ID deviceId, BS2SimpleDeviceInfo* deviceInfo);

/**
 * @brief Gets extended device information including iClass SEOS card and DST settings. [+ 2.6.0]
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID.
 * @param[out] deviceInfo Pointer to a BS2SimpleDeviceInfo structure to store device information.
 * @param[out] deviceInfoEx Pointer to a BS2SimpleDeviceInfoEx structure to store additional device information.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdeviceinfoex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceInfoEx(void* context, BS2_DEVICE_ID deviceId, BS2SimpleDeviceInfo* deviceInfo, BS2SimpleDeviceInfoEx* deviceInfoEx);

/**
 * @brief Connects to a device using its device identifier.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID to connect to.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_connectdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ConnectDevice(void* context, BS2_DEVICE_ID deviceId);

/**
 * @brief Connects to a device using its IP address and port number.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceAddress IPv4 address of the device.
 * @param[in] defaultDevicePort Port number of the device.
 * @param[out] deviceId Pointer to store the connected device ID.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_connectdeviceviaip.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ConnectDeviceViaIP(void* context, const char* deviceAddress, BS2_PORT defaultDevicePort, BS2_DEVICE_ID* deviceId);

/**
 * @brief Disconnects from the specified device.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID to disconnect from.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_disconnectdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_DisconnectDevice(void* context, BS2_DEVICE_ID deviceId);

/**
 * @brief Retrieves the network topology (device node hierarchy) of the specified device.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID.
 * @param[out] networkNodeObj Pointer to an array of BS2DeviceNode structures. Must be released with BS2_ReleaseObject().
 * @param[out] numNetworkNode Pointer to store the number of network nodes returned.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceTopology(void* context, BS2_DEVICE_ID deviceId, BS2DeviceNode** networkNodeObj, uint32_t* numNetworkNode);

/**
 * @brief Configures the network topology (device node hierarchy) of the specified device.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID.
 * @param[in] networkNode Array of BS2DeviceNode structures defining the topology.
 * @param[in] numNetworkNode Number of elements in the networkNode array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceTopology(void* context, BS2_DEVICE_ID deviceId, BS2DeviceNode* networkNode, uint32_t numNetworkNode);

/**
 * @brief Checks whether the specified device is currently connected.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID to check.
 * @param[out] connected Pointer to store the connection status (non-zero if connected, 0 if not).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_isconnected.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IsConnected(void* context, BS2_DEVICE_ID deviceId, int* connected);

//SSL API
/**
 * @brief Sets the SSL server port. Set to 0 to close the SSL port.
 * @ingroup group_ssl_api
 * @param[in] context SDK context handle.
 * @param[in] sslServerPort SSL server port number. Set to 0 to disable.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsslserverport.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSSLServerPort(void* context, BS2_PORT sslServerPort);

/**
 * @brief Configures SSL communication by registering the required SSL callback functions.
 * @ingroup group_ssl_api
 * @param[in] context SDK context handle.
 * @param[in] ptrPreferMethod Callback function called to retrieve the preferred SSL method mask.
 * @param[in] ptrGetRootCaFilePath Callback function called to retrieve the root CA file path.
 * @param[in] ptrGetServerCaFilePath Callback function called to retrieve the server CA file path.
 * @param[in] ptrGetServerPrivateKeyFilePath Callback function called to retrieve the server private key file path.
 * @param[in] ptrGetPassword Callback function called to retrieve the password.
 * @param[in] ptrOnErrorOccured Callback function called when an SSL error occurs.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsslhandler.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSSLHandler(void* context, PreferMethod ptrPreferMethod, GetRootCaFilePath ptrGetRootCaFilePath, GetServerCaFilePath ptrGetServerCaFilePath, GetServerPrivateKeyFilePath ptrGetServerPrivateKeyFilePath, GetPassword ptrGetPassword, OnErrorOccured ptrOnErrorOccured);

/**
 * @brief Registers the SSL event listener for sending root CA to the device.
 * @ingroup group_ssl_api
 * @param[in] context SDK context handle.
 * @param[in] ptrSendRootCA Callback function called when the root CA is sent to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceSSLEventListener(void* context, OnSendRootCA ptrSendRootCA);

/**
 * @brief Disables SSL communication for the specified device.
 * @ingroup group_ssl_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device ID to disable SSL for.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_disablessl.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_DisableSSL(void* context, BS2_DEVICE_ID deviceId);

// AccessControl api
/**
 * @brief Retrieves selected access groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessGroupIds Array of access group IDs to retrieve.
 * @param[in] accessGroupIdCount Number of IDs in accessGroupIds.
 * @param[out] accessGroupObj Pointer to the retrieved access group array. Release with BS2_ReleaseObject().
 * @param[out] numAccessGroup Number of retrieved access groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getaccessgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAccessGroup(void* context, BS2_DEVICE_ID deviceId, BS2_ACCESS_GROUP_ID* accessGroupIds, uint32_t accessGroupIdCount, BS2AccessGroup** accessGroupObj, uint32_t* numAccessGroup);
/**
 * @brief Retrieves all access groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] accessGroupObj Pointer to the retrieved access group array. Release with BS2_ReleaseObject().
 * @param[out] numAccessGroup Number of retrieved access groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallaccessgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAccessGroup(void* context, BS2_DEVICE_ID deviceId, BS2AccessGroup** accessGroupObj, uint32_t* numAccessGroup);
/**
 * @brief Configures an access group on the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessGroups Array of access groups to set.
 * @param[in] accessGroupCount Number of access groups in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setaccessgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAccessGroup(void* context, BS2_DEVICE_ID deviceId, BS2AccessGroup* accessGroups, uint32_t accessGroupCount);
/**
 * @brief Removes selected access groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessGroupIds Array of access group IDs to remove.
 * @param[in] accessGroupIdCount Number of IDs in accessGroupIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeaccessgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAccessGroup(void* context, BS2_DEVICE_ID deviceId, BS2_ACCESS_GROUP_ID* accessGroupIds, uint32_t accessGroupIdCount);
/**
 * @brief Removes all access groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallaccessgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAccessGroup(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves selected access levels from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessLevelIds Array of access level IDs to retrieve.
 * @param[in] accessLevelIdCount Number of IDs in accessLevelIds.
 * @param[out] accessLevelObj Pointer to the retrieved access level array. Release with BS2_ReleaseObject().
 * @param[out] numAccessLevel Number of retrieved access levels.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getaccesslevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAccessLevel(void* context, BS2_DEVICE_ID deviceId, BS2_ACCESS_LEVEL_ID* accessLevelIds, uint32_t accessLevelIdCount, BS2AccessLevel** accessLevelObj, uint32_t* numAccessLevel);
/**
 * @brief Retrieves all access levels from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] accessLevelObj Pointer to the retrieved access level array. Release with BS2_ReleaseObject().
 * @param[out] numAccessLevel Number of retrieved access levels.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallaccesslevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAccessLevel(void* context, BS2_DEVICE_ID deviceId, BS2AccessLevel** accessLevelObj, uint32_t* numAccessLevel);
/**
 * @brief Configures an access level on the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessLevels Array of access levels to set.
 * @param[in] accessLevelCount Number of access levels in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setaccesslevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAccessLevel(void* context, BS2_DEVICE_ID deviceId, BS2AccessLevel* accessLevels, uint32_t accessLevelCount);
/**
 * @brief Removes selected access levels from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessLevelIds Array of access level IDs to remove.
 * @param[in] accessLevelIdCount Number of IDs in accessLevelIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeaccesslevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAccessLevel(void* context, BS2_DEVICE_ID deviceId, BS2_ACCESS_LEVEL_ID* accessLevelIds, uint32_t accessLevelIdCount);
/**
 * @brief Removes all access levels from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallaccesslevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAccessLevel(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves selected time schedules from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessSheduleIds Array of schedule IDs to retrieve.
 * @param[in] accessScheduleIdCount Number of IDs in accessSheduleIds.
 * @param[out] accessScheduleObj Pointer to the retrieved schedule array. Release with BS2_ReleaseObject().
 * @param[out] numAccessSchedule Number of retrieved schedules.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getaccessschedule.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAccessSchedule(void* context, BS2_DEVICE_ID deviceId, BS2_SCHEDULE_ID* accessSheduleIds, uint32_t accessScheduleIdCount, BS2Schedule** accessScheduleObj, uint32_t* numAccessSchedule);
/**
 * @brief Retrieves all time schedules from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] accessScheduleObj Pointer to the retrieved schedule array. Release with BS2_ReleaseObject().
 * @param[out] numAccessSchedule Number of retrieved schedules.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallaccessschedule.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAccessSchedule(void* context, BS2_DEVICE_ID deviceId, BS2Schedule** accessScheduleObj, uint32_t* numAccessSchedule);
/**
 * @brief Configures a time schedule on the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessShedules Array of schedules to set.
 * @param[in] accessSheduleCount Number of schedules in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setaccessschedule.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAccessSchedule(void* context, BS2_DEVICE_ID deviceId, BS2Schedule* accessShedules, uint32_t accessSheduleCount);
/**
 * @brief Removes selected time schedules from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] accessSheduleIds Array of schedule IDs to remove.
 * @param[in] accessScheduleIdCount Number of IDs in accessSheduleIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeaccessschedule.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAccessSchedule(void* context, BS2_DEVICE_ID deviceId, BS2_SCHEDULE_ID* accessSheduleIds, uint32_t accessScheduleIdCount);
/**
 * @brief Removes all time schedules from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallaccessschedule.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAccessSchedule(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves selected holiday groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] holidayGroupIds Array of holiday group IDs to retrieve.
 * @param[in] holidayGroupIdCount Number of IDs in holidayGroupIds.
 * @param[out] holidayGroupObj Pointer to the retrieved holiday group array. Release with BS2_ReleaseObject().
 * @param[out] numHolidayGroup Number of retrieved holiday groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getholidaygroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetHolidayGroup(void* context, BS2_DEVICE_ID deviceId, BS2_HOLIDAY_GROUP_ID* holidayGroupIds, uint32_t holidayGroupIdCount, BS2HolidayGroup** holidayGroupObj, uint32_t* numHolidayGroup);
/**
 * @brief Retrieves all holiday groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] holidayGroupObj Pointer to the retrieved holiday group array. Release with BS2_ReleaseObject().
 * @param[out] numHolidayGroup Number of retrieved holiday groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallholidaygroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllHolidayGroup(void* context, BS2_DEVICE_ID deviceId, BS2HolidayGroup** holidayGroupObj, uint32_t* numHolidayGroup);
/**
 * @brief Configures a holiday group on the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] holidayGroups Array of holiday groups to set.
 * @param[in] holidayGroupCount Number of holiday groups in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setholidaygroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetHolidayGroup(void* context, BS2_DEVICE_ID deviceId, BS2HolidayGroup* holidayGroups, uint32_t holidayGroupCount);
/**
 * @brief Removes selected holiday groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] holidayGroupIds Array of holiday group IDs to remove.
 * @param[in] holidayGroupIdCount Number of IDs in holidayGroupIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeholidaygroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveHolidayGroup(void* context, BS2_DEVICE_ID deviceId, BS2_HOLIDAY_GROUP_ID* holidayGroupIds, uint32_t holidayGroupIdCount);
/**
 * @brief Removes all holiday groups from the device.
 * @ingroup group_access_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallholidaygroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllHolidayGroup(void* context, BS2_DEVICE_ID deviceId);

// Blacklist api
/**
 * @brief Retrieves selected blacklist entries from the device.
 * @ingroup group_blacklist
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] blacklists Array of blacklist entries to search for.
 * @param[in] blacklistCount Number of entries in blacklists.
 * @param[out] blacklistObj Pointer to the retrieved blacklist array. Release with BS2_ReleaseObject().
 * @param[out] numBlacklist Number of retrieved blacklist entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getblacklist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetBlackList(void* context, BS2_DEVICE_ID deviceId, BS2BlackList* blacklists, uint32_t blacklistCount, BS2BlackList** blacklistObj, uint32_t* numBlacklist);
/**
 * @brief Retrieves all blacklist entries from the device.
 * @ingroup group_blacklist
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] blacklistObj Pointer to the retrieved blacklist array. Release with BS2_ReleaseObject().
 * @param[out] numBlacklist Number of retrieved blacklist entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallblacklist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllBlackList(void* context, BS2_DEVICE_ID deviceId, BS2BlackList** blacklistObj, uint32_t* numBlacklist);
/**
 * @brief Configures blacklist entries on the device.
 * @ingroup group_blacklist
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] blacklists Array of blacklist entries to set.
 * @param[in] blacklistCount Number of entries in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setblacklist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetBlackList(void* context, BS2_DEVICE_ID deviceId, BS2BlackList* blacklists, uint32_t blacklistCount);
/**
 * @brief Removes selected blacklist entries from the device.
 * @ingroup group_blacklist
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] blacklists Array of blacklist entries to remove.
 * @param[in] blacklistCount Number of entries to remove.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeblacklist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveBlackList(void* context, BS2_DEVICE_ID deviceId, BS2BlackList* blacklists, uint32_t blacklistCount);
/**
 * @brief Removes all blacklist entries from the device.
 * @ingroup group_blacklist
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallblacklist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllBlackList(void* context, BS2_DEVICE_ID deviceId);

// Card api
/**
 * @brief Scans the card from the device and analyzes it.
 * @ingroup group_smartcard
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] card Pointer to the BS2Card structure to receive the scanned card data.
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_scancard.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanCard(void* context, BS2_DEVICE_ID deviceId, BS2Card* card, OnReadyToScan ptrReadyToScan);
/**
 * @brief Writes data to the smart card.
 * @ingroup group_smartcard
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] smartCard Pointer to the smart card data to write.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_writecard.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_WriteCard(void* context, BS2_DEVICE_ID deviceId, BS2SmartCardData* smartCard);
/**
 * @brief Formats (erases) the smart card.
 * @ingroup group_smartcard
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_erasecard.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EraseCard(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Writes a string to be used as a QR code in the card structure.
 * @ingroup group_qrcode
 * @note Supported on X-Station 2. [+ 2.8]
 * @param[in] qrText Null-terminated string to encode as a QR code.
 * @param[out] card Pointer to the BS2CSNCard structure to receive the QR code data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_writeqrcode.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_WriteQRCode(const char* qrText, BS2CSNCard* card);
/**
 * @brief Gets Lock Override information from the device that meets specific conditions.
 * @ingroup group_smartcard
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] requests Array of BS2LockOverride conditions to query.
 * @param[in] numOfRequests Number of entries in requests.
 * @param[out] responseObjs Pointer to the retrieved Lock Override array. Release with BS2_ReleaseObject().
 * @param[out] numOfResponses Number of retrieved entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlockoverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLockOverride(void* context, BS2_DEVICE_ID deviceId, const BS2LockOverride* requests, uint32_t numOfRequests, BS2LockOverride** responseObjs, uint32_t* numOfResponses);
/**
 * @brief Gets all Lock Override information from the device.
 * @ingroup group_smartcard
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] responseObjs Pointer to the retrieved Lock Override array. Release with BS2_ReleaseObject().
 * @param[out] numOfResponses Number of retrieved entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalllockoverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllLockOverride(void* context, BS2_DEVICE_ID deviceId, BS2LockOverride** responseObjs, uint32_t* numOfResponses);
/**
 * @brief Sets Lock Override information on the device.
 * @ingroup group_smartcard
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] requests Array of BS2LockOverride entries to set.
 * @param[in] numOfRequests Number of entries in requests.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setlockoverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetLockOverride(void* context, BS2_DEVICE_ID deviceId, const BS2LockOverride* requests, uint32_t numOfRequests);
/**
 * @brief Removes Lock Override information from the device that meets specific conditions.
 * @ingroup group_smartcard
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] requests Array of BS2LockOverride conditions to remove.
 * @param[in] numOfRequests Number of entries in requests.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removelockoverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveLockOverride(void* context, BS2_DEVICE_ID deviceId, const BS2LockOverride* requests, uint32_t numOfRequests);
/**
 * @brief Removes all Lock Override information from the device.
 * @ingroup group_smartcard
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealllockoverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllLockOverride(void* context, BS2_DEVICE_ID deviceId);

// Config api
/**
 * @brief Initializes the user information and blacklist on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_cleardatabase.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearDatabase(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Initializes all configurations and the database on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] includingDB If non-zero, also initializes the user database.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_resetconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ResetConfig(void* context, BS2_DEVICE_ID deviceId, uint8_t includingDB);
/**
 * @brief Initializes the device configuration, excluding network settings.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] includingDB If non-zero, also initializes the user database.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_resetconfigexceptnetinfo.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ResetConfigExceptNetInfo(void* context, BS2_DEVICE_ID deviceId, uint8_t includingDB);
/**
 * @brief Retrieves configuration blob from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] configs Pointer to the BS2Configs structure to receive configuration data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetConfig(void* context, BS2_DEVICE_ID deviceId, BS2Configs* configs);
/**
 * @brief Stores configuration blob on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] configs Pointer to the BS2Configs structure containing configuration data to store.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetConfig(void* context, BS2_DEVICE_ID deviceId, BS2Configs* configs);
/**
 * @brief Retrieves software version and hardware settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2FactoryConfig structure to receive factory configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfactoryconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFactoryConfig(void* context, BS2_DEVICE_ID deviceId, BS2FactoryConfig* config);
/**
 * @brief Retrieves system settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2SystemConfig structure to receive system configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsystemconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSystemConfig(void* context, BS2_DEVICE_ID deviceId, BS2SystemConfig* config);
/**
 * @brief Stores system settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2SystemConfig structure containing system configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsystemconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSystemConfig(void* context, BS2_DEVICE_ID deviceId, BS2SystemConfig* config);
/**
 * @brief Retrieves authentication settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2AuthConfig structure to receive authentication configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getauthconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAuthConfig(void* context, BS2_DEVICE_ID deviceId, BS2AuthConfig* config);
/**
 * @brief Stores authentication settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2AuthConfig structure containing authentication configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setauthconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAuthConfig(void* context, BS2_DEVICE_ID deviceId, BS2AuthConfig* config);
/**
 * @brief Retrieves LED and buzzer settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2StatusConfig structure to receive status configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getstatusconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetStatusConfig(void* context, BS2_DEVICE_ID deviceId, BS2StatusConfig* config);
/**
 * @brief Stores LED and buzzer settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2StatusConfig structure containing status configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setstatusconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetStatusConfig(void* context, BS2_DEVICE_ID deviceId, BS2StatusConfig* config);
/**
 * @brief Retrieves sound and UI settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2DisplayConfig structure to receive display configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdisplayconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDisplayConfig(void* context, BS2_DEVICE_ID deviceId, BS2DisplayConfig* config);
/**
 * @brief Stores sound and UI settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2DisplayConfig structure containing display configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdisplayconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDisplayConfig(void* context, BS2_DEVICE_ID deviceId, BS2DisplayConfig* config);
/**
 * @brief Retrieves IP settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IpConfig structure to receive IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPConfig(void* context, BS2_DEVICE_ID deviceId, BS2IpConfig* config);
/**
 * @brief Retrieves DNS and server URL settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IpConfigExt structure to receive extended IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPConfigExt(void* context, BS2_DEVICE_ID deviceId, BS2IpConfigExt* config);
/**
 * @brief Retrieves IP settings from the device via UDP broadcasting.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IpConfig structure to receive IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipconfigviaudp.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPConfigViaUDP(void* context, BS2_DEVICE_ID deviceId, BS2IpConfig* config);
/**
 * @brief Stores IP settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IpConfig structure containing IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPConfig(void* context, BS2_DEVICE_ID deviceId, BS2IpConfig* config);
/**
 * @brief Stores DNS and server URL settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IpConfigExt structure containing extended IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPConfigExt(void* context, BS2_DEVICE_ID deviceId, BS2IpConfigExt* config);
/**
 * @brief Stores IP settings on the device via UDP broadcasting.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IpConfig structure containing IP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipconfigviaudp.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPConfigViaUDP(void* context, BS2_DEVICE_ID deviceId, BS2IpConfig* config);
/**
 * @brief Retrieves time and attendance settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2TNAConfig structure to receive TNA configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_gettnaconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetTNAConfig(void* context, BS2_DEVICE_ID deviceId, BS2TNAConfig* config);
/**
 * @brief Stores time and attendance settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2TNAConfig structure containing TNA configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_settnaconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetTNAConfig(void* context, BS2_DEVICE_ID deviceId, BS2TNAConfig* config);
/**
 * @brief Retrieves smart card settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2CardConfig structure to receive card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getcardconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetCardConfig(void* context, BS2_DEVICE_ID deviceId, BS2CardConfig* config);
/**
 * @brief Stores smart card settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2CardConfig structure containing card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setcardconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetCardConfig(void* context, BS2_DEVICE_ID deviceId, BS2CardConfig* config);
/**
 * @brief Retrieves fingerprint matching settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2FingerprintConfig structure to receive fingerprint configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfingerprintconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFingerprintConfig(void* context, BS2_DEVICE_ID deviceId, BS2FingerprintConfig* config);
/**
 * @brief Stores fingerprint matching settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2FingerprintConfig structure containing fingerprint configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfingerprintconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFingerprintConfig(void* context, BS2_DEVICE_ID deviceId, BS2FingerprintConfig* config);
/**
 * @brief Retrieves RS-485 network settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2Rs485Config structure to receive RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getrs485config.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetRS485Config(void* context, BS2_DEVICE_ID deviceId, BS2Rs485Config* config);
/**
 * @brief Stores RS-485 network settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2Rs485Config structure containing RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setrs485config.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetRS485Config(void* context, BS2_DEVICE_ID deviceId, BS2Rs485Config* config);
/**
 * @brief Retrieves Wiegand I/O settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2WiegandConfig structure to receive Wiegand configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getwiegandconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetWiegandConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandConfig* config);
/**
 * @brief Stores Wiegand I/O settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2WiegandConfig structure containing Wiegand configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setwiegandconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetWiegandConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandConfig* config);
/**
 * @brief Retrieves Wiegand device settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2WiegandDeviceConfig structure to receive Wiegand device configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getwieganddeviceconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetWiegandDeviceConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandDeviceConfig* config);
/**
 * @brief Stores Wiegand device settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2WiegandDeviceConfig structure containing Wiegand device configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setwieganddeviceconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetWiegandDeviceConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandDeviceConfig* config);
/**
 * @brief Retrieves supervised input port settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2InputConfig structure to receive input configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getinputconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetInputConfig(void* context, BS2_DEVICE_ID deviceId, BS2InputConfig* config);
/**
 * @brief Stores supervised input port settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2InputConfig structure containing input configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setinputconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetInputConfig(void* context, BS2_DEVICE_ID deviceId, BS2InputConfig* config);
/**
 * @brief Retrieves wireless LAN settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2WlanConfig structure to receive WLAN configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getwlanconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetWlanConfig(void* context, BS2_DEVICE_ID deviceId, BS2WlanConfig* config);
/**
 * @brief Stores wireless LAN settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2WlanConfig structure containing WLAN configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setwlanconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetWlanConfig(void* context, BS2_DEVICE_ID deviceId, BS2WlanConfig* config);
/**
 * @brief Retrieves trigger and action settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2TriggerActionConfig structure to receive trigger/action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_gettriggeractionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetTriggerActionConfig(void* context, BS2_DEVICE_ID deviceId, BS2TriggerActionConfig* config);
/**
 * @brief Stores trigger and action settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2TriggerActionConfig structure containing trigger/action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_settriggeractionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetTriggerActionConfig(void* context, BS2_DEVICE_ID deviceId, BS2TriggerActionConfig* config);
/**
 * @brief Retrieves image log filter settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2EventConfig structure to receive event configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_geteventconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetEventConfig(void* context, BS2_DEVICE_ID deviceId, BS2EventConfig* config);
/**
 * @brief Stores image log filter settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2EventConfig structure containing event configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_seteventconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetEventConfig(void* context, BS2_DEVICE_ID deviceId, BS2EventConfig* config);
/**
 * @brief Retrieves Multi-Wiegand settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2WiegandMultiConfig structure to receive Multi-Wiegand configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getwiegandmulticonfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetWiegandMultiConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandMultiConfig* config);
/**
 * @brief Stores Multi-Wiegand settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2WiegandMultiConfig structure containing Multi-Wiegand configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setwiegandmulticonfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetWiegandMultiConfig(void* context, BS2_DEVICE_ID deviceId, BS2WiegandMultiConfig* config);
/**
 * @brief Retrieves v1 Template on Card settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS1CardConfig structure to receive v1 card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getcard1xconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetCard1xConfig(void* context, BS2_DEVICE_ID deviceId, BS1CardConfig* config);
/**
 * @brief Stores v1 Template on Card settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS1CardConfig structure containing v1 card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setcard1xconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetCard1xConfig(void* context, BS2_DEVICE_ID deviceId, BS1CardConfig* config);
/**
 * @brief Retrieves Master and slave device encryption settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2SystemConfigExt structure to receive extended system configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsystemextconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSystemExtConfig(void* context, BS2_DEVICE_ID deviceId, BS2SystemConfigExt* config);
/**
 * @brief Stores Master and slave device encryption settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2SystemConfigExt structure containing extended system configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsystemextconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSystemExtConfig(void* context, BS2_DEVICE_ID deviceId, BS2SystemConfigExt* config);
/**
 * @brief Retrieves VoIP settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2VoipConfig structure to receive VoIP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getvoipconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetVoipConfig(void* context, BS2_DEVICE_ID deviceId, BS2VoipConfig* config);
/**
 * @brief Stores VoIP settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2VoipConfig structure containing VoIP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setvoipconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetVoipConfig(void* context, BS2_DEVICE_ID deviceId, BS2VoipConfig* config);
/**
 * @brief Retrieves face settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2FaceConfig structure to receive face configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfaceconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFaceConfig(void* context, BS2_DEVICE_ID deviceId, BS2FaceConfig* config);
/**
 * @brief Stores face settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2FaceConfig structure containing face configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfaceconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFaceConfig(void* context, BS2_DEVICE_ID deviceId, BS2FaceConfig* config);
/**
 * @brief Retrieves iClass SEOS card settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2CardConfigEx structure to receive extended card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getcardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetCardConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2CardConfigEx* config);
/**
 * @brief Stores iClass SEOS card settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2CardConfigEx structure containing extended card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setcardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetCardConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2CardConfigEx* config);
/**
 * @brief In case of CoreStation, retrieves RS-485 network settings from the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2Rs485ConfigEX structure to receive extended RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getrs485configex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetRS485ConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2Rs485ConfigEX* config);
/**
 * @brief In case of CoreStation, stores RS-485 network settings on the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2Rs485ConfigEX structure containing extended RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setrs485configex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetRS485ConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2Rs485ConfigEX* config);
/**
 * @brief Gets the RS485 network setting information for CoreStation.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2Rs485ConfigEXDynamic structure to receive dynamic RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getrs485configexdynamic.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetRS485ConfigExDynamic(void* context, BS2_DEVICE_ID deviceId, BS2Rs485ConfigEXDynamic* config);
/**
 * @brief Saves the RS485 network setting information for CoreStation.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2Rs485ConfigEXDynamic structure containing dynamic RS-485 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setrs485configexdynamic.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetRS485ConfigExDynamic(void* context, BS2_DEVICE_ID deviceId, BS2Rs485ConfigEXDynamic* config);
/**
 * @brief Retrieves supported configuration of the device.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] configMask Pointer to receive the supported configuration mask.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsupportedconfigmask.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSupportedConfigMask(void* context, BS2_DEVICE_ID deviceId, BS2_CONFIG_MASK* configMask);
/**
 * @brief Retrieves the device DST (Daylight Saving Time) information.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2DstConfig structure to receive DST configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdstconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDstConfig(void* context, BS2_DEVICE_ID deviceId, BS2DstConfig* config);
/**
 * @brief Stores the device DST (Daylight Saving Time) information.
 * @ingroup group_configuration
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2DstConfig structure containing DST configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdstconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDstConfig(void* context, BS2_DEVICE_ID deviceId, BS2DstConfig* config);
/**
 * @brief Retrieves DesFire advanced configuration from the device.
 * @ingroup group_configuration
 * @note [+ 2.6.4]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2DesFireCardConfigEx structure to receive DesFire configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdesfirecardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDesFireCardConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2DesFireCardConfigEx* config);
/**
 * @brief Sets DesFire advanced configuration in the device.
 * @ingroup group_configuration
 * @note [+ 2.6.4]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2DesFireCardConfigEx structure containing DesFire configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdesfirecardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDesFireCardConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2DesFireCardConfigEx* config);
/**
 * @brief Retrieves authentication settings from Visual Face-based devices.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2AuthConfigExt structure to receive extended authentication configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getauthconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAuthConfigExt(void* context, BS2_DEVICE_ID deviceId, BS2AuthConfigExt* config);
/**
 * @brief Stores authentication settings on Visual Face-based devices.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2AuthConfigExt structure containing extended authentication configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setauthconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAuthConfigExt(void* context, BS2_DEVICE_ID deviceId, const BS2AuthConfigExt* config);
/**
 * @brief Retrieves configuration of thermal camera and mask detection.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2FaceConfigExt structure to receive extended face configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfaceconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFaceConfigExt(void* context, BS2_DEVICE_ID deviceId, BS2FaceConfigExt* config);
/**
 * @brief Stores configuration of thermal camera and mask detection.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2FaceConfigExt structure containing extended face configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfaceconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFaceConfigExt(void* context, BS2_DEVICE_ID deviceId, const BS2FaceConfigExt* config);
/**
 * @brief Retrieves configuration of thermal camera.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2ThermalCameraConfig structure to receive thermal camera configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getthermalcameraconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetThermalCameraConfig(void* context, BS2_DEVICE_ID deviceId, BS2ThermalCameraConfig* config);
/**
 * @brief Stores configuration of thermal camera.
 * @ingroup group_configuration
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2ThermalCameraConfig structure containing thermal camera configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setthermalcameraconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetThermalCameraConfig(void* context, BS2_DEVICE_ID deviceId, const BS2ThermalCameraConfig* config);
/**
 * @brief Retrieves Barcode configuration from X-Station 2.
 * @ingroup group_configuration
 * @note [+ 2.8] Supported on X-Station 2.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2BarcodeConfig structure to receive barcode configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getbarcodeconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetBarcodeConfig(void* context, BS2_DEVICE_ID deviceId, BS2BarcodeConfig* config);
/**
 * @brief Stores Barcode configuration on X-Station 2.
 * @ingroup group_configuration
 * @note [+ 2.8] Supported on X-Station 2.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2BarcodeConfig structure containing barcode configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setbarcodeconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetBarcodeConfig(void* context, BS2_DEVICE_ID deviceId, const BS2BarcodeConfig* config);
/**
 * @brief Retrieves expanded input configuration from IM-120.
 * @ingroup group_configuration
 * @note [+ 2.8.1] Supported on IM-120.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2InputConfigEx structure to receive extended input configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getinputconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetInputConfigEx(void* context, BS2_DEVICE_ID deviceId, BS2InputConfigEx* config);
/**
 * @brief Stores expanded input configuration on IM-120.
 * @ingroup group_configuration
 * @note [+ 2.8.1] Supported on IM-120.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2InputConfigEx structure containing extended input configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setinputconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetInputConfigEx(void* context, BS2_DEVICE_ID deviceId, const BS2InputConfigEx* config);
/**
 * @brief Retrieves relay action configuration from IM-120.
 * @ingroup group_configuration
 * @note [+ 2.8.1] Supported on IM-120.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2RelayActionConfig structure to receive relay action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getrelayactionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetRelayActionConfig(void* context, BS2_DEVICE_ID deviceId, BS2RelayActionConfig* config);
/**
 * @brief Stores relay action configuration on IM-120.
 * @ingroup group_configuration
 * @note [+ 2.8.1] Supported on IM-120.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2RelayActionConfig structure containing relay action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setrelayactionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetRelayActionConfig(void* context, BS2_DEVICE_ID deviceId, const BS2RelayActionConfig* config);
/**
 * @brief Gets the extended VoIP settings.
 * @ingroup group_configuration
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2VoipConfigExt structure to receive extended VoIP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getvoipconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetVoipConfigExt(void* context, BS2_DEVICE_ID deviceId, BS2VoipConfigExt* config);
/**
 * @brief Saves the extended VoIP settings.
 * @ingroup group_configuration
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2VoipConfigExt structure containing extended VoIP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setvoipconfigext.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetVoipConfigExt(void* context, BS2_DEVICE_ID deviceId, const BS2VoipConfigExt* config);
/**
 * @brief Gets the RTSP settings.
 * @ingroup group_configuration
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2RtspConfig structure to receive RTSP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getrtspconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetRtspConfig(void* context, BS2_DEVICE_ID deviceId, BS2RtspConfig* config);
/**
 * @brief Saves the RTSP settings.
 * @ingroup group_configuration
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2RtspConfig structure containing RTSP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setrtspconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetRtspConfig(void* context, BS2_DEVICE_ID deviceId, const BS2RtspConfig* config);
/**
 * @brief Gets the device's OSDP setting information.
 * @ingroup group_configuration
 * @note [+ 2.9.1]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2OsdpStandardConfig structure to receive OSDP configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getosdpstandardconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetOsdpStandardConfig(void* const, BS2_DEVICE_ID deviceId, BS2OsdpStandardConfig* config);
/**
 * @brief Gets the LED/buzzer settings for each action of the OSDP device.
 * @ingroup group_configuration
 * @note [+ 2.9.1]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2OsdpStandardActionConfig structure to receive OSDP action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getosdpstandardactionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetOsdpStandardActionConfig(void* const, BS2_DEVICE_ID deviceId, BS2OsdpStandardActionConfig* config);
/**
 * @brief Specifies the LED/buzzer setting for each action of the OSDP device.
 * @ingroup group_configuration
 * @note [+ 2.9.1]
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2OsdpStandardActionConfig structure containing OSDP action configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setosdpstandardactionconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetOsdpStandardActionConfig(void* const, BS2_DEVICE_ID deviceId, const BS2OsdpStandardActionConfig* config);
/**
 * @brief Gets the device license activation information.
 * @ingroup group_configuration
 * @note [+ 2.9.1]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2LicenseConfig structure to receive license configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlicenseconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLicenseConfig(void* const, BS2_DEVICE_ID deviceId, BS2LicenseConfig* config);
/**
 * @brief Retrieves Custom smart card settings from the device.
 * @ingroup group_configuration
 * @note [+ 2.9.4]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2CustomCardConfig structure to receive custom card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getcustomcardconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetCustomCardConfig(void* const, BS2_DEVICE_ID deviceId, BS2CustomCardConfig* config);
/**
 * @brief Stores Custom smart card settings on the device.
 * @ingroup group_configuration
 * @note [+ 2.9.4]
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2CustomCardConfig structure containing custom card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setcustomcardconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetCustomCardConfig(void* const, BS2_DEVICE_ID deviceId, const BS2CustomCardConfig* config);
/**
 * @brief Gets the BS2FacilityCode used as authentication code when OSDP connection between DI-24 and master device is lost.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2FacilityCodeConfig structure to receive facility code configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfacilitycodeconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFacilityCodeConfig(void* const, BS2_DEVICE_ID deviceId, BS2FacilityCodeConfig* config);
/**
 * @brief Saves the BS2FacilityCode setting used as authentication code when OSDP connection between DI-24 and master device is lost.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2FacilityCodeConfig structure containing facility code configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfacilitycodeconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFacilityCodeConfig(void* const, BS2_DEVICE_ID deviceId, const BS2FacilityCodeConfig* config);
/**
 * @brief Gets the setting information used for AES128-encrypted Mifare cards on the device.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2MifareCardConfigEx structure to receive extended Mifare card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getmifarecardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetMifareCardConfigEx(void* const, BS2_DEVICE_ID deviceId, BS2MifareCardConfigEx* config);
/**
 * @brief Saves the setting information used for AES128-encrypted Mifare cards on the device.
 * @ingroup group_configuration
 * @note [+ 2.9.9]
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2MifareCardConfigEx structure containing extended Mifare card configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setmifarecardconfigex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetMifareCardConfigEx(void* const, BS2_DEVICE_ID deviceId, const BS2MifareCardConfigEx* config);

// Door api
/**
 * @brief Retrieves selected doors from the device.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] doorIds Array of door IDs to retrieve.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @param[out] doorObj Pointer to the retrieved door array. Release with BS2_ReleaseObject().
 * @param[out] numDoor Number of retrieved doors.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_ID* doorIds, uint32_t doorIdCount, BS2Door** doorObj, uint32_t* numDoor);
/**
 * @brief Retrieves all doors from the device.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] doorObj Pointer to the retrieved door array. Release with BS2_ReleaseObject().
 * @param[out] numDoor Number of retrieved doors.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalldoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllDoor(void* context, BS2_DEVICE_ID deviceId, BS2Door** doorObj, uint32_t* numDoor);
/**
 * @brief Retrieves the status of selected doors.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] doorIds Array of door IDs to query status.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @param[out] doorStatusObj Pointer to the retrieved door status array. Release with BS2_ReleaseObject().
 * @param[out] numDoorStatus Number of retrieved door statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdoorstatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDoorStatus(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_ID* doorIds, uint32_t doorIdCount, BS2DoorStatus** doorStatusObj, uint32_t* numDoorStatus);
/**
 * @brief Retrieves the status of all doors.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] doorStatusObj Pointer to the retrieved door status array. Release with BS2_ReleaseObject().
 * @param[out] numDoorStatus Number of retrieved door statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalldoorstatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllDoorStatus(void* context, BS2_DEVICE_ID deviceId, BS2DoorStatus** doorStatusObj, uint32_t* numDoorStatus);
/**
 * @brief Configures a door on the device.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] doors Array of door configurations to set.
 * @param[in] doorCount Number of doors in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDoor(void* context, BS2_DEVICE_ID deviceId, BS2Door* doors, uint32_t doorCount);
/**
 * @brief Configures the alarm status of the door.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door alarm flag to set.
 * @param[in] doorIds Array of door IDs to configure alarm.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdooralarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDoorAlarm(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_ALARM_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount);
/**
 * @brief Removes selected doors from the device.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] doorIds Array of door IDs to remove.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removedoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_ID* doorIds, uint32_t doorIdCount);
/**
 * @brief Removes all doors from the device.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealldoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllDoor(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Releases the lock/unlock flag of the door status, initializing priorities set to the door.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door flag indicating the priority to release.
 * @param[in] doorIds Array of door IDs to release.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_releasedoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ReleaseDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount);
/**
 * @brief Configures the priority of when the door gets locked.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door lock priority flag.
 * @param[in] doorIds Array of door IDs to lock.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_lockdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_LockDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount);
/**
 * @brief Configures the priority of when the door gets unlocked.
 * @ingroup group_door_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door unlock priority flag.
 * @param[in] doorIds Array of door IDs to unlock.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_unlockdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_UnlockDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount);
/**
 * @brief Performs timed door lock.
 * @ingroup group_door_control
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door lock priority flag.
 * @param[in] doorIds Array of door IDs to lock.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @param[in] timeout Lock duration in seconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_timedlockdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_TimedLockDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount, uint32_t timeout);
/**
 * @brief Performs timed door unlock.
 * @ingroup group_door_control
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Door unlock priority flag.
 * @param[in] doorIds Array of door IDs to unlock.
 * @param[in] doorIdCount Number of IDs in doorIds.
 * @param[in] timeout Unlock duration in seconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_timedunlockdoor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_TimedUnlockDoor(void* context, BS2_DEVICE_ID deviceId, BS2_DOOR_FLAG flag, BS2_DOOR_ID* doorIds, uint32_t doorIdCount, uint32_t timeout);

// Lift api
/**
 * @brief Retrieves selected lifts from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] liftIds Array of lift IDs to retrieve.
 * @param[in] liftIdCount Number of IDs in liftIds.
 * @param[out] liftObj Pointer to the retrieved lift array. Release with BS2_ReleaseObject().
 * @param[out] numLift Number of retrieved lifts.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlift.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLift(void* context, BS2_DEVICE_ID deviceId, BS2_LIFT_ID* liftIds, uint32_t liftIdCount, BS2Lift** liftObj, uint32_t* numLift);
/**
 * @brief Retrieves all lifts from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] liftObj Pointer to the retrieved lift array. Release with BS2_ReleaseObject().
 * @param[out] numLift Number of retrieved lifts.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalllift.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllLift(void* context, BS2_DEVICE_ID deviceId, BS2Lift** liftObj, uint32_t* numLift);
/**
 * @brief Retrieves the status of selected lifts.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] liftIds Array of lift IDs to query status.
 * @param[in] liftIdCount Number of IDs in liftIds.
 * @param[out] liftStatusObj Pointer to the retrieved lift status array. Release with BS2_ReleaseObject().
 * @param[out] numLiftStatus Number of retrieved lift statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getliftstatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLiftStatus(void* context, BS2_DEVICE_ID deviceId, BS2_LIFT_ID* liftIds, uint32_t liftIdCount, BS2LiftStatus** liftStatusObj, uint32_t* numLiftStatus);
/**
 * @brief Retrieves the status of all lifts.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] liftStatusObj Pointer to the retrieved lift status array. Release with BS2_ReleaseObject().
 * @param[out] numLiftStatus Number of retrieved lift statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallliftstatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllLiftStatus(void* context, BS2_DEVICE_ID deviceId, BS2LiftStatus** liftStatusObj, uint32_t* numLiftStatus);
/**
 * @brief Configures a lift on the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] lifts Array of lift configurations to set.
 * @param[in] liftCount Number of lifts in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setlift.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetLift(void* context, BS2_DEVICE_ID deviceId, BS2Lift* lifts, uint32_t liftCount);
/**
 * @brief Configures the alarm status of the lift.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Lift alarm flag to set.
 * @param[in] liftIds Array of lift IDs to configure alarm.
 * @param[in] liftIdCount Number of IDs in liftIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setliftalarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetLiftAlarm(void* context, BS2_DEVICE_ID deviceId, BS2_LIFT_ALARM_FLAG flag, BS2_LIFT_ID* liftIds, uint32_t liftIdCount);
/**
 * @brief Removes selected lifts from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] liftIds Array of lift IDs to remove.
 * @param[in] liftIdCount Number of IDs in liftIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removelift.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveLift(void* context, BS2_DEVICE_ID deviceId, BS2_LIFT_ID* liftIds, uint32_t liftIdCount);
/**
 * @brief Removes all lifts from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealllift.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllLift(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Releases the activate/deactivate flag of the lift status, initializing priorities set to the lift.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Floor flag indicating the priority to release.
 * @param[in] liftID Target lift identifier.
 * @param[in] floorIndexs Array of floor indices to release.
 * @param[in] floorIndexCount Number of floor indices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_releasefloor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ReleaseFloor(void* context, BS2_DEVICE_ID deviceId, BS2_FLOOR_FLAG flag, BS2_LIFT_ID liftID, uint16_t* floorIndexs, uint8_t floorIndexCount);
/**
 * @brief Configures the priority of when the floor is activated to allow access.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Floor activate priority flag.
 * @param[in] liftID Target lift identifier.
 * @param[in] floorIndexs Array of floor indices to activate.
 * @param[in] floorIndexCount Number of floor indices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_activatefloor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ActivateFloor(void* context, BS2_DEVICE_ID deviceId, BS2_FLOOR_FLAG flag, BS2_LIFT_ID liftID, uint16_t* floorIndexs, uint8_t floorIndexCount);
/**
 * @brief Configures the priority of when the floor is deactivated to deny access.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] flag Floor deactivate priority flag.
 * @param[in] liftID Target lift identifier.
 * @param[in] floorIndexs Array of floor indices to deactivate.
 * @param[in] floorIndexCount Number of floor indices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_deactivatefloor.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_DeActivateFloor(void* context, BS2_DEVICE_ID deviceId, BS2_FLOOR_FLAG flag, BS2_LIFT_ID liftID, uint16_t* floorIndexs, uint8_t floorIndexCount);

// Fingerprint api
/**
 * @brief Extracts the image of the last scanned fingerprint.
 * @ingroup group_fingerprint
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] imageObj Pointer to receive the fingerprint image data. Release with BS2_ReleaseObject().
 * @param[out] imageWidth Width of the fingerprint image in pixels.
 * @param[out] imageHeight Height of the fingerprint image in pixels.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlastfingerprintimage.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLastFingerprintImage(void* context, BS2_DEVICE_ID deviceId, uint8_t** imageObj, uint32_t* imageWidth, uint32_t* imageHeight);
/**
 * @brief Scans a fingerprint from a device and extracts template data.
 * @ingroup group_fingerprint
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] finger Pointer to the BS2Fingerprint structure to receive fingerprint template data.
 * @param[in] templateIndex Index of the template slot (0 or 1).
 * @param[in] quality Minimum quality threshold for the scan.
 * @param[in] templateFormat Template format (BS2_FINGER_TEMPLATE_FORMAT).
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_scanfingerprint.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanFingerprint(void* context, BS2_DEVICE_ID deviceId,
															BS2Fingerprint* finger,
															uint32_t templateIndex,
															uint32_t quality,
															uint8_t templateFormat, //BS2_FINGER_TEMPLATE_FORMAT
															OnReadyToScan ptrReadyToScan);
/**
 * @brief Scans a fingerprint from a device and extracts template data and scan image quality score.
 * @ingroup group_fingerprint
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] finger Pointer to the BS2Fingerprint structure to receive fingerprint template data.
 * @param[in] templateIndex Index of the template slot (0 or 1).
 * @param[in] quality Minimum quality threshold for the scan.
 * @param[in] templateFormat Template format (BS2_FINGER_TEMPLATE_FORMAT).
 * @param[out] outquality Pointer to receive the actual quality score of the scanned fingerprint.
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_scanfingerprintex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanFingerprintEx(void* context, BS2_DEVICE_ID deviceId,
															BS2Fingerprint* finger,
															uint32_t templateIndex,
															uint32_t quality,
															uint8_t templateFormat, //BS2_FINGER_TEMPLATE_FORMAT
															uint32_t* outquality,
															OnReadyToScan ptrReadyToScan);
/**
 * @brief Scans a fingerprint from a device and extracts raw image data.
 * @ingroup group_fingerprint
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] templateIndex Index of the template slot (0 or 1).
 * @param[in] quality Minimum quality threshold for the scan.
 * @param[in] templateFormat Template format (BS2_FINGER_TEMPLATE_FORMAT).
 * @param[out] imageData Buffer to receive the scanned fingerprint image data.
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanFingerprintImage(void* context, BS2_DEVICE_ID deviceId,
															uint32_t templateIndex,
															uint32_t quality,
															uint8_t templateFormat, //BS2_FINGER_TEMPLATE_FORMAT
															unsigned char* imageData,
															OnReadyToScan ptrReadyToScan);
/**
 * @brief Compares the template data to check if it is the same finger.
 * @ingroup group_fingerprint
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] finger Pointer to the BS2Fingerprint structure containing template data to verify.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyfingerprint.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyFingerprint(void* context, BS2_DEVICE_ID deviceId, BS2Fingerprint* finger);
/**
 * @brief Checks the quality score of the fingerprint from the fingerprint template data.
 * @ingroup group_fingerprint
 * @param[in] templateBuffer Pointer to the fingerprint template buffer.
 * @param[in] templateSize Size of the template buffer in bytes.
 * @param[out] score Pointer to receive the quality score of the fingerprint template.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfingertemplatequality.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFingerTemplateQuality(const uint8_t* templateBuffer, const int32_t templateSize, int32_t* score);

// Log api
/**
 * @brief Gets a specified number of logs starting from the given event ID.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLog(void* context, BS2_DEVICE_ID deviceId, BS2_EVENT_ID eventId, uint32_t amount, BS2Event** logsObj, uint32_t* numLog);
/**
 * @brief Gets a specified number of logs based on the event mask.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogblob.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogBlob(void* context, BS2_DEVICE_ID deviceId, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventBlob** logsObj, uint32_t* numLog);
/**
 * @brief Gets filtered logs matching the specified criteria.
 * @ingroup group_log_management
 * @deprecated Use BS2_GetLogBlob() or BS2_GetLogSmallBlob() instead.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uid User ID to filter by (NULL for all users).
 * @param[in] eventCode Event code to filter by.
 * @param[in] start Start timestamp for filtering.
 * @param[in] end End timestamp for filtering.
 * @param[in] tnakey TNA key to filter by.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfilteredlog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFilteredLog(void* context, BS2_DEVICE_ID deviceId, char* uid, BS2_EVENT_CODE eventCode, BS2_TIMESTAMP start, BS2_TIMESTAMP end, uint8_t tnakey,
															BS2Event** logsObj,uint32_t* numLog);
/**
 * @brief Gets filtered logs matching the specified criteria, starting from a specific event ID.
 * @ingroup group_log_management
 * @deprecated Use BS2_GetLogBlob() or BS2_GetLogSmallBlob() instead.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uid User ID to filter by (NULL for all users).
 * @param[in] eventCode Event code to filter by.
 * @param[in] start Start timestamp for filtering.
 * @param[in] end End timestamp for filtering.
 * @param[in] tnakey TNA key to filter by.
 * @param[in] lastEventId Starting event ID for retrieval.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfilteredlogsinceeventid.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFilteredLogSinceEventId(void* context, BS2_DEVICE_ID deviceId, char* uid, BS2_EVENT_CODE eventCode, BS2_TIMESTAMP start, BS2_TIMESTAMP end, uint8_t tnakey, BS2_EVENT_ID lastEventId, uint32_t amount,
															BS2Event** logsObj, uint32_t* numLog);

/**
 * @brief Gets image logs using event ID.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] eventId Event ID of the image log to retrieve.
 * @param[out] imageObj Pointer to receive the image data. Release with BS2_ReleaseObject().
 * @param[out] imageSize Pointer to receive the image data size in bytes.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getimagelog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetImageLog(void* context, BS2_DEVICE_ID deviceId, BS2_EVENT_ID eventId, uint8_t** imageObj, uint32_t* imageSize);
/**
 * @brief Deletes all logs from the device.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_clearlog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearLog(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Starts real-time log streaming from the device.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] ptrLogReceived Callback function invoked when a log event is received.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_startmonitoringlog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_StartMonitoringLog(void* context, BS2_DEVICE_ID deviceId, OnLogReceived ptrLogReceived);
/**
 * @brief Starts real-time log streaming including temperature information.
 * @ingroup group_log_management
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] ptrLogReceivedEx Callback function invoked when a log event (including temperature) is received.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_startmonitoringlogex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_StartMonitoringLogEx(void* context, BS2_DEVICE_ID deviceId, OnLogReceivedEx ptrLogReceivedEx);
/**
 * @brief Stops real-time log streaming from the device.
 * @ingroup group_log_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_stopmonitoringlog.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_StopMonitoringLog(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Gets the current device I/O port status.
 * @ingroup group_log_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] slaveIDs Array of slave device IDs to query (NULL for master only).
 * @param[in] numOfSlave Number of slave device IDs.
 * @param[out] statusObj Pointer to the retrieved I/O status array. Release with BS2_ReleaseObject().
 * @param[out] numOfStatus Number of retrieved status entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdeviceiostatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceIOStatus(void* context, BS2_DEVICE_ID deviceId, const BS2_DEVICE_ID* slaveIDs, uint32_t numOfSlave, BS2IOStatus** statusObj, uint32_t* numOfStatus);
/**
 * @brief Gets the current I/O port status of the device and all slave devices.
 * @ingroup group_log_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] statusObj Pointer to the retrieved I/O status array. Release with BS2_ReleaseObject().
 * @param[out] numOfStatus Number of retrieved status entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalldeviceiostatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllDeviceIOStatus(void* context, BS2_DEVICE_ID deviceId, BS2IOStatus** statusObj, uint32_t* numOfStatus);

// Misc api
/**
 * @brief Initializes all configurations and the database on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_factoryreset.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_FactoryReset(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Restarts the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_rebootdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RebootDevice(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Locks the device to prevent user authentication.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_lockdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_LockDevice(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Unlocks the device to allow user authentication.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_unlockdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_UnlockDevice(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Gets the device time.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] gmtTime Pointer to receive the current device time as a GMT timestamp.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicetime.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceTime(void* context, BS2_DEVICE_ID deviceId, BS2_TIMESTAMP* gmtTime);
/**
 * @brief Sets the device time.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] gmtTime GMT timestamp to set on the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicetime.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceTime(void* context, BS2_DEVICE_ID deviceId, BS2_TIMESTAMP gmtTime);
/**
 * @brief Upgrades the firmware on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] firmwareData Pointer to the firmware binary data.
 * @param[in] firmwareDataLen Size of the firmware data in bytes.
 * @param[in] keepVerifyingSlaveDevice If non-zero, continue verifying slave devices during upgrade.
 * @param[in] ptrProgressChanged Callback function invoked to report upgrade progress.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_upgradefirmware.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_UpgradeFirmware(void* context, BS2_DEVICE_ID deviceId, uint8_t* firmwareData, uint32_t firmwareDataLen, uint8_t keepVerifyingSlaveDevice, OnProgressChanged ptrProgressChanged);
/**
 * @brief Updates the resource on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] resourceElement Pointer to the resource element to upload.
 * @param[in] keepVerifyingSlaveDevice If non-zero, continue verifying slave devices during update.
 * @param[in] ptrProgressChanged Callback function invoked to report update progress.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_updateresource.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_UpdateResource(void* context, BS2_DEVICE_ID deviceId, BS2ResourceElement* resourceElement, uint8_t keepVerifyingSlaveDevice, OnProgressChanged ptrProgressChanged);
/**
 * @brief Sets the keep-alive timeout for the device connection.
 * @ingroup group_communication_api
 * @param[in] context SDK context handle.
 * @param[in] ms Keep-alive timeout in milliseconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setkeepalivetimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetKeepAliveTimeout(void* context, long ms);
/**
 * @brief Generates an encrypted PIN code from a plaintext PIN.
 * @ingroup group_sdk_api
 * @param[in] context SDK context handle.
 * @param[in] plaintext Null-terminated plaintext PIN string.
 * @param[out] ciphertext Buffer to receive the encrypted PIN code.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_makepincode.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_MakePinCode(void* context, char* plaintext, unsigned char* ciphertext);
/**
 * @brief Generates an encrypted PIN code from a plaintext PIN using a specified encryption key.
 * @ingroup group_sdk_api
 * @param[in] context SDK context handle.
 * @param[in] plaintext Null-terminated plaintext PIN string.
 * @param[out] ciphertext Buffer to receive the encrypted PIN code.
 * @param[in] key Pointer to the BS2EncryptKey structure specifying the encryption key.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_makepincodewithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_MakePinCodeWithKey(void* context, char* plaintext, unsigned char* ciphertext, const BS2EncryptKey* key);
/**
 * @brief Computes the CRC16-CCITT checksum of the given data.
 * @ingroup group_sdk_api
 * @param[in] data Pointer to the data to compute checksum for.
 * @param[in] dataLen Length of the data in bytes.
 * @param[out] crc Pointer to receive the computed CRC16-CCITT value.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_computecrc16ccitt.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ComputeCRC16CCITT(unsigned char* data, uint32_t dataLen, uint16_t* crc);
/**
 * @brief Gets the card model type from the model name string.
 * @ingroup group_sdk_api
 * @param[in] modelName Null-terminated device model name string.
 * @param[out] cardModel Pointer to receive the corresponding BS2_CARD_MODEL value.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getcardmodel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetCardModel(char* modelName, BS2_CARD_MODEL* cardModel);
/**
 * @brief Gets available function information of the device.
 * @ingroup group_device_api
 * @note [+ 2.8]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] capabilities Pointer to the BS2DeviceCapabilities structure to receive capability information.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicecapabilities.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceCapabilities(void* context, BS2_DEVICE_ID deviceId, BS2DeviceCapabilities* capabilities);
/**
 * @brief Commands the device to take certain actions.
 * @ingroup group_device_api
 * @note [+ 2.8.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] action Pointer to the BS2Action structure specifying the action to perform.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_runaction.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RunAction(void* context, BS2_DEVICE_ID deviceId, const BS2Action* action);

// Slave Control api
/**
 * @brief Searches a slave device from the RS-485 network.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[out] slaveDeviceObj Pointer to the retrieved slave device array. Release with BS2_ReleaseObject().
 * @param[out] slaveDeviceCount Number of discovered slave devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getslavedevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSlaveDevice(void* context, BS2_DEVICE_ID deviceId, BS2Rs485SlaveDevice** slaveDeviceObj, uint32_t* slaveDeviceCount);
/**
 * @brief Adds, modifies, or deletes a slave device on the master device.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[in] slaveDevices Array of slave device configurations to set.
 * @param[in] slaveDeviceCount Number of slave devices in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setslavedevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSlaveDevice(void* context, BS2_DEVICE_ID deviceId, BS2Rs485SlaveDevice* slaveDevices, uint32_t slaveDeviceCount);
/**
 * @brief Removes all slave devices from the master device RS-485 network.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveSlaveDevice(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Sets the RS-485 baud rate of a slave device connected to a master device.
 * @ingroup group_slave_control
 * @note [+ 2.9.8]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[in] slaveId Slave device identifier to configure.
 * @param[in] baudrate RS-485 baud rate value to set.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setslavebaudrate.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSlaveBaudrate(void* context, BS2_DEVICE_ID deviceId, BS2_DEVICE_ID slaveId, uint32_t baudrate);

// Server Matching api
/**
 * @brief Registers the server matching handler for card/fingerprint authentication.
 * @ingroup group_server
 * @param[in] context SDK context handle.
 * @param[in] ptrVerifyUser Callback invoked when card or user ID authentication occurs.
 * @param[in] ptrIdentifyUser Callback invoked when fingerprint authentication occurs.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setservermatchinghandler.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetServerMatchingHandler(void* context, OnVerifyUser ptrVerifyUser, OnIdentifyUser ptrIdentifyUser);
/**
 * @brief Transfers user information mapped to the card or user ID authentication results to the device.
 * @ingroup group_server
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the user data blob to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyuser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyUser(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserBlob* userBlob);
/**
 * @brief Transfers user information mapped to the fingerprint authentication results to the device.
 * @ingroup group_server
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the user data blob to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_identifyuser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IdentifyUser(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserBlob* userBlob);

// User api
/**
 * @brief Gets the total number of users, cards, fingerprints, and faces stored on the device.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] numUsers Pointer to receive the total number of enrolled users.
 * @param[out] numCards Pointer to receive the total number of enrolled cards.
 * @param[out] numFingers Pointer to receive the total number of enrolled fingerprints.
 * @param[out] numFaces Pointer to receive the total number of enrolled faces.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatabaseInfo(void* context, BS2_DEVICE_ID deviceId, uint32_t* numUsers, uint32_t* numCards, uint32_t* numFingers, uint32_t* numFaces, IsAcceptableUserID ptrIsAcceptableUserID);
/**
 * @brief Gets the enrolled user ID list from the device.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] uidsObj Pointer to the retrieved user ID list. Release with BS2_ReleaseObject().
 * @param[out] numUid Number of retrieved user IDs.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserlist.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserList(void* context, BS2_DEVICE_ID deviceId,
														char** uidsObj, uint32_t* numUid,
														IsAcceptableUserID ptrIsAcceptableUserID);
/**
 * @brief Gets the user information of the given user IDs.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfos.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfos(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserBlob* userBlob);
/**
 * @brief Gets selected data of the given users based on user mask.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatas.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatas(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Enrolls new users on the device.
 * @ingroup group_user_management
 * @deprecated Use BS2_EnrollUser() instead.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Array of BS2UserBlob structures containing user data to enroll.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite If non-zero, overwrite existing user with the same ID.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enroluser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrolUser(void* context, BS2_DEVICE_ID deviceId, BS2UserBlob* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Enrolls new users on the device.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Array of BS2UserBlob structures containing user data to enroll.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite If non-zero, overwrite existing user with the same ID.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enrolluser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrollUser(void* context, BS2_DEVICE_ID deviceId, BS2UserBlob* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Deletes specified users from the device.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to remove.
 * @param[in] uidCount Number of user IDs to remove.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeuser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveUser(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount);
/**
 * @brief Deletes all users from the device.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealluser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllUser(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Gets user settings supported by the device.
 * @ingroup group_user_management
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] userMask Pointer to receive the supported user mask bitmask.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsupportedusermask.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSupportedUserMask(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK* userMask);
/**
 * @brief Registers the server user phrase handler.
 * @ingroup group_server
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] ptrQuery Callback function invoked to request a user phrase from the server.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setuserphrasehandler.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetUserPhraseHandler(void* context, OnUserPhrase ptrQuery);
/**
 * @brief Transfers the user phrase to the device.
 * @ingroup group_server
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the user phrase request.
 * @param[in] handleResult Result code for the user phrase query (0 for success).
 * @param[in] userPhrase The user phrase string to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_responseuserphrase.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ResponseUserPhrase(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, const BS2_USER_PHRASE userPhrase);
/**
 * @brief Gets user information for extended door open time that meets specified conditions.
 * @ingroup group_user_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userIDs Array of user ID strings to query.
 * @param[in] numOfUsers Number of user IDs in the array.
 * @param[out] overrideObjs Pointer to the retrieved user override array. Release with BS2_ReleaseObject().
 * @param[out] numOfOverrides Number of retrieved user override entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuseroverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserOverride(void* context, BS2_DEVICE_ID deviceId, const char* userIDs, uint32_t numOfUsers, BS2UserOverride** overrideObjs, uint32_t* numOfOverrides);
/**
 * @brief Gets all user information using extended door open time.
 * @ingroup group_user_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] overrideObjs Pointer to the retrieved user override array. Release with BS2_ReleaseObject().
 * @param[out] numOfOverrides Number of retrieved user override entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalluseroverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllUserOverride(void* context, BS2_DEVICE_ID deviceId, BS2UserOverride** overrideObjs, uint32_t* numOfOverrides);
/**
 * @brief Sets users to use extended door open time.
 * @ingroup group_user_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] overrides Array of BS2UserOverride structures to set.
 * @param[in] numOfOverrides Number of entries in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setuseroverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetUserOverride(void* context, BS2_DEVICE_ID deviceId, const BS2UserOverride* overrides, uint32_t numOfOverrides);
/**
 * @brief Removes specified users from using extended door open time.
 * @ingroup group_user_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userIDs Array of user ID strings to remove override for.
 * @param[in] numOfUsers Number of user IDs in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeuseroverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveUserOverride(void* context, BS2_DEVICE_ID deviceId, const char* userIDs, uint32_t numOfUsers);
/**
 * @brief Removes all users from using extended door open time.
 * @ingroup group_user_management
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealluseroverride.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllUserOverride(void* context, BS2_DEVICE_ID deviceId);

// Wiegand api
/**
 * @brief Searches for Wiegand card readers connected to the device.
 * @ingroup group_wiegand
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] wiegandDeviceObj Pointer to the discovered Wiegand device ID array. Release with BS2_ReleaseObject().
 * @param[out] numWiegandDevice Number of discovered Wiegand devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_searchwieganddevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SearchWiegandDevices(void* context, BS2_DEVICE_ID deviceId, BS2_DEVICE_ID** wiegandDeviceObj, uint32_t* numWiegandDevice);
/**
 * @brief Retrieves the Wiegand card readers currently configured on the device.
 * @ingroup group_wiegand
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] wiegandDeviceObj Pointer to the Wiegand device ID array. Release with BS2_ReleaseObject().
 * @param[out] numWiegandDevice Number of configured Wiegand devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getwieganddevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetWiegandDevices(void* context, BS2_DEVICE_ID deviceId, BS2_DEVICE_ID** wiegandDeviceObj, uint32_t* numWiegandDevice);
/**
 * @brief Adds Wiegand card readers to the device.
 * @ingroup group_wiegand
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] wiegandDevice Array of Wiegand device IDs to add.
 * @param[in] numWiegandDevice Number of Wiegand devices to add.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_addwieganddevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_AddWiegandDevices(void* context, BS2_DEVICE_ID deviceId, BS2_DEVICE_ID* wiegandDevice, uint32_t numWiegandDevice);
/**
 * @brief Removes Wiegand card readers from the device.
 * @ingroup group_wiegand
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] wiegandDevice Array of Wiegand device IDs to remove.
 * @param[in] numWiegandDevice Number of Wiegand devices to remove.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removewieganddevices.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveWiegandDevices(void* context, BS2_DEVICE_ID deviceId, BS2_DEVICE_ID* wiegandDevice, uint32_t numWiegandDevice);

// Zone api
/**
 * @brief Retrieves selected Anti Passback zones from the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to retrieve.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2AntiPassbackZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves all Anti Passback zones from the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2AntiPassbackZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Anti Passback zones.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Anti Passback zones.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures an Anti Passback zone on the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zones Array of Anti Passback zone configurations to set.
 * @param[in] zoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2AntiPassbackZone* zones, uint32_t zoneCount);
/**
 * @brief Configures the alarm status of the Anti Passback zone.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setantipassbackzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAntiPassbackZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Anti Passback zones from the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Anti Passback zones from the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Updates selected users to be not violating against the Anti Passback zone rule.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Anti Passback zone identifier.
 * @param[in] uids Array of user ID strings to clear violation status.
 * @param[in] uidCount Number of user IDs in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_clearantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID, char* uids, uint32_t uidCount);
/**
 * @brief Updates all users to be not violating against the Anti Passback zone rule.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Anti Passback zone identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_clearallantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearAllAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID);
/**
 * @brief Retrieves selected Timed Anti Passback zones from the device.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to retrieve.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_gettimedantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetTimedAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2TimedAntiPassbackZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves all Timed Anti Passback zones from the device.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalltimedantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllTimedAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2TimedAntiPassbackZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Timed Anti Passback zones.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_gettimedantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetTimedAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Timed Anti Passback zones.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalltimedantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllTimedAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures a Timed Anti Passback zone on the device.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zones Array of Timed Anti Passback zone configurations to set.
 * @param[in] zoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_settimedantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetTimedAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2TimedAntiPassbackZone* zones, uint32_t zoneCount);
/**
 * @brief Configures the alarm status of the Timed Anti Passback zone.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_settimedantipassbackzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetTimedAntiPassbackZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Timed Anti Passback zones from the device.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removetimedantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveTimedAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Timed Anti Passback zones from the device.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealltimedantipassbackzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllTimedAntiPassbackZone(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Updates selected users to be not violating against the Timed Anti Passback zone rule.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Timed Anti Passback zone identifier.
 * @param[in] uids Array of user ID strings to clear violation status.
 * @param[in] uidCount Number of user IDs in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_cleartimedantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearTimedAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID, char* uids, uint32_t uidCount);
/**
 * @brief Updates all users to be not violating against the Timed Anti Passback zone rule.
 * @ingroup group_timed_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Timed Anti Passback zone identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_clearalltimedantipassbackzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearAllTimedAntiPassbackZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID);
/**
 * @brief Retrieves selected Fire Alarm zones from the device.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to retrieve.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfirealarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFireAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2FireAlarmZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves all Fire Alarm zones from the device.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallfirealarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllFireAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2FireAlarmZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Fire Alarm zones.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfirealarmzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFireAlarmZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Fire Alarm zones.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallfirealarmzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllFireAlarmZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures a Fire Alarm zone on the device.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zones Array of Fire Alarm zone configurations to set.
 * @param[in] zoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfirealarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFireAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2FireAlarmZone* zones, uint32_t zoneCount);
/**
 * @brief Configures the alarm status of the Fire Alarm zone.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfirealarmzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFireAlarmZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Fire Alarm zones from the device.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removefirealarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveFireAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Fire Alarm zones from the device.
 * @ingroup group_fire_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallfirealarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllFireAlarmZone(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves selected Scheduled Lock/Unlock zones from the device.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to retrieve.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getscheduledlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetScheduledLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ScheduledLockUnlockZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves all Scheduled Lock/Unlock zones from the device.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallscheduledlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllScheduledLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2ScheduledLockUnlockZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Scheduled Lock/Unlock zones.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getscheduledlockunlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetScheduledLockUnlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Scheduled Lock/Unlock zones.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallscheduledlockunlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllScheduledLockUnlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures a Scheduled Lock/Unlock zone on the device.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zones Array of Scheduled Lock/Unlock zone configurations to set.
 * @param[in] zoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setscheduledlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetScheduledLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2ScheduledLockUnlockZone* zones, uint32_t zoneCount);
/**
 * @brief Configures the alarm status of the Scheduled Lock/Unlock zone.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setscheduledlockunlockzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetScheduledLockUnlockZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Scheduled Lock/Unlock zones from the device.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removescheduledlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveScheduledLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Scheduled Lock/Unlock zones from the device.
 * @ingroup group_scheduled_lock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallscheduledlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllScheduledLockUnlockZone(void* context, BS2_DEVICE_ID deviceId);

//FloorLevel
/**
 * @brief Retrieves selected floor levels from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] floorLevelIds Array of floor level IDs to retrieve.
 * @param[in] floorLevelIdCount Number of IDs in floorLevelIds.
 * @param[out] floorLevelObj Pointer to the retrieved floor level array. Release with BS2_ReleaseObject().
 * @param[out] numFloorLevel Number of retrieved floor levels.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfloorlevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFloorLevel(void* context, BS2_DEVICE_ID deviceId, BS2_FLOOR_LEVEL_ID* floorLevelIds, uint32_t floorLevelIdCount, BS2FloorLevel** floorLevelObj, uint32_t* numFloorLevel);
/**
 * @brief Retrieves all floor levels from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] floorLevelObj Pointer to the retrieved floor level array. Release with BS2_ReleaseObject().
 * @param[out] numFloorLevel Number of retrieved floor levels.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallfloorlevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllFloorLevel(void* context, BS2_DEVICE_ID deviceId, BS2FloorLevel** floorLevelObj, uint32_t* numFloorLevel);
/**
 * @brief Configures a floor level on the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] floorLevels Array of floor level configurations to set.
 * @param[in] floorLevelCount Number of floor levels in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setfloorlevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetFloorLevel(void* context, BS2_DEVICE_ID deviceId, BS2FloorLevel* floorLevels, uint32_t floorLevelCount);
/**
 * @brief Removes selected floor levels from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] floorLevelIds Array of floor level IDs to remove.
 * @param[in] floorLevelIdCount Number of IDs in floorLevelIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removefloorlevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveFloorLevel(void* context, BS2_DEVICE_ID deviceId, BS2_FLOOR_LEVEL_ID* floorLevelIds, uint32_t floorLevelIdCount);
/**
 * @brief Removes all floor levels from the device.
 * @ingroup group_lift_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallfloorlevel.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllFloorLevel(void* context, BS2_DEVICE_ID deviceId);

//Face
/**
 * @brief Scans the face from a device and extracts template and image data (IR Face based).
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] face Pointer to the BS2Face structure to receive face template and image data.
 * @param[in] enrollmentThreshold Minimum quality threshold for enrollment.
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_scanface.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanFace(void* context, BS2_DEVICE_ID deviceId, BS2Face* face, uint8_t enrollmentThreshold, OnReadyToScan ptrReadyToScan);

//FaceEx
/**
 * @brief Scans the face from a device and extracts template and image data (Visual Face based).
 * @ingroup group_faceex
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] faceEx Pointer to the BS2FaceEx structure to receive Visual Face template and image data.
 * @param[in] enrollmentThreshold Minimum quality threshold for enrollment.
 * @param[in] ptrReadyToScan Callback function invoked when the device is ready to scan.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_scanfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ScanFaceEx(void* context, BS2_DEVICE_ID deviceId, BS2FaceEx* faceEx, uint8_t enrollmentThreshold, OnReadyToScan ptrReadyToScan);
/**
 * @brief Extracts template data from a face image (Visual Face based).
 * @ingroup group_faceex
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] imageData Pointer to the face image data buffer.
 * @param[in] imageDataLen Size of the image data in bytes.
 * @param[in] isWarped Non-zero if the image is already warped (normalized), zero if unwarped.
 * @param[out] templateEx Pointer to the BS2TemplateEx structure to receive the extracted template data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ExtractTemplateFaceEx(void* context, BS2_DEVICE_ID deviceId, const uint8_t* imageData, uint32_t imageDataLen, int isWarped, BS2TemplateEx* templateEx);
/**
 * @brief Creates a warped (normalized) image from an unwarped face image (Visual Face based).
 * @ingroup group_faceex
 * @note [+ 2.8]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] unwarpedImage Pointer to the unwarped face image data.
 * @param[in] unwarpedImageLen Size of the unwarped image data in bytes.
 * @param[out] warpedImage Buffer to receive the warped image data.
 * @param[in,out] warpedImageLen On input, the buffer size; on output, the actual warped image size.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getnormalizedimagefaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetNormalizedImageFaceEx(void* context, BS2_DEVICE_ID deviceId, const uint8_t* unwarpedImage, uint32_t unwarpedImageLen, uint8_t* warpedImage, uint32_t* warpedImageLen);

//AuthGroup
/**
 * @brief Retrieves selected authentication groups from the device.
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] authGroupIds Array of authentication group IDs to retrieve.
 * @param[in] authGroupIdCount Number of IDs in authGroupIds.
 * @param[out] authGroupObj Pointer to the retrieved auth group array. Release with BS2_ReleaseObject().
 * @param[out] numAuthGroup Number of retrieved authentication groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getauthgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAuthGroup(void* context, BS2_DEVICE_ID deviceId, BS2_AUTH_GROUP_ID* authGroupIds, uint32_t authGroupIdCount, BS2AuthGroup** authGroupObj, uint32_t* numAuthGroup);
/**
 * @brief Retrieves all authentication groups from the device.
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] authGroupObj Pointer to the retrieved auth group array. Release with BS2_ReleaseObject().
 * @param[out] numAuthGroup Number of retrieved authentication groups.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallauthgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAuthGroup(void* context, BS2_DEVICE_ID deviceId, BS2AuthGroup** authGroupObj, uint32_t* numAuthGroup);
/**
 * @brief Configures an authentication group on the device.
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] authGroups Array of authentication group configurations to set.
 * @param[in] authGroupCount Number of authentication groups in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setauthgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAuthGroup(void* context, BS2_DEVICE_ID deviceId, BS2AuthGroup* authGroups, uint32_t authGroupCount);
/**
 * @brief Removes selected authentication groups from the device.
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] authGroupIds Array of authentication group IDs to remove.
 * @param[in] authGroupIdCount Number of IDs in authGroupIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeauthgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAuthGroup(void* context, BS2_DEVICE_ID deviceId, BS2_AUTH_GROUP_ID* authGroupIds, uint32_t authGroupIdCount);
/**
 * @brief Removes all authentication groups from the device.
 * @ingroup group_face
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallauthgroup.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAuthGroup(void* context, BS2_DEVICE_ID deviceId);

//UserEx
/**
 * @brief Transfers user information (including Job code and User phrase) mapped to the card or user ID authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.4.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the extended user data blob to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyuserex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyUserEx(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserBlobEx* userBlob);
/**
 * @brief Transfers user information (including Job code and User phrase) mapped to the fingerprint authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.4.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the extended user data blob to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_identifyuserex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IdentifyUserEx(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserBlobEx* userBlob);
/**
 * @brief Gets the user information (including Job code and User phrase) of the given user IDs.
 * @ingroup group_user_management
 * @note [+ 2.4.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive extended user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob);
/**
 * @brief Gets selected data (including Job code and User phrase) of the given users based on user mask.
 * @ingroup group_user_management
 * @note [+ 2.5.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive extended user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Enrolls new users with Job code and User phrase on the device.
 * @ingroup group_user_management
 * @deprecated Use BS2_EnrollUserEx() instead.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Array of BS2UserBlobEx structures containing extended user data to enroll.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite If non-zero, overwrite existing user with the same ID.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enroluserex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrolUserEx(void* context, BS2_DEVICE_ID deviceId, BS2UserBlobEx* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Enrolls new users with Job code and User phrase on the device.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Array of BS2UserBlobEx structures containing extended user data to enroll.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite If non-zero, overwrite existing user with the same ID.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enrolluserex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrollUserEx(void* context, BS2_DEVICE_ID deviceId, BS2UserBlobEx* userBlob, uint32_t userCount, uint8_t overwrite);

//USB Exported
/**
 * @brief Allocates context which manages and controls USB device.
 * @ingroup group_usb_export
 * @deprecated Use the standard context from BS2_Initialize() instead.
 * @param[in] szDir Path to the USB exported data directory.
 * @return Pointer to the allocated USB context, or NULL on failure.
 * @include{doc} bs2_allocateusbcontext.md
 */
DEPRECATED_FUNC BS_API_EXPORT void* BS_CALLING_CONVENTION BS2_AllocateUsbContext(const char* szDir);
/**
 * @brief Releases context which manages and controls USB device.
 * @ingroup group_usb_export
 * @deprecated Use the standard context release instead.
 * @param[in] context USB context handle to release.
 * @include{doc} bs2_releaseusbcontext.md
 */
DEPRECATED_FUNC BS_API_EXPORT void BS_CALLING_CONVENTION BS2_ReleaseUsbContext(void* context);
/**
 * @brief Gets total user information from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[out] numUsers Pointer to receive the total number of enrolled users.
 * @param[out] numCards Pointer to receive the total number of enrolled cards.
 * @param[out] numFingers Pointer to receive the total number of enrolled fingerprints.
 * @param[out] numFaces Pointer to receive the total number of enrolled faces.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatabaseinfofromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatabaseInfoFromDir(void* context, const char* szDir, uint32_t* numUsers, uint32_t* numCards, uint32_t* numFingers, uint32_t* numFaces, IsAcceptableUserID ptrIsAcceptableUserID);
/**
 * @brief Gets the enrolled user ID list from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[out] uidsObj Pointer to the retrieved user ID list. Release with BS2_ReleaseObject().
 * @param[out] numUid Number of retrieved user IDs.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserlistfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserListFromDir(void* context, const char* szDir, char** uidsObj, uint32_t* numUid, IsAcceptableUserID ptrIsAcceptableUserID);
/**
 * @brief Gets the user information of given user IDs from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlob* userBlob);
/**
 * @brief Gets selected data of users from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Gets the user information (including Job code and User phrase) of given user IDs from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive extended user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob);
/**
 * @brief Gets selected data (including Job code and User phrase) of users from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive extended user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Gets a specified number of logs from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogFromDir(void* context, const char* szDir, BS2_EVENT_ID eventId, uint32_t amount, BS2Event** logsObj, uint32_t* numLog);
/**
 * @brief Gets a specified number of logs based on the event mask from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogblobfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogBlobFromDir(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventBlob** logsObj, uint32_t* numLog);
/**
 * @brief Gets filtered logs from USB exported data.
 * @ingroup group_usb_export
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uid User ID to filter by (NULL for all users).
 * @param[in] eventCode Event code to filter by.
 * @param[in] start Start timestamp for filtering.
 * @param[in] end End timestamp for filtering.
 * @param[in] tnakey TNA key to filter by.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfilteredlogfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFilteredLogFromDir(void* context, const char* szDir, char* uid, BS2_EVENT_CODE eventCode, BS2_TIMESTAMP start, BS2_TIMESTAMP end, uint8_t tnakey, BS2Event** logsObj, uint32_t* numLog);
//BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFilteredLogSinceEventIdFromDir(void* context, const char* szDir, char* uid, BS2_EVENT_CODE eventCode, BS2_TIMESTAMP start, BS2_TIMESTAMP end, uint8_t tnakey, BS2_EVENT_ID lastEventId, uint32_t amount, BS2Event** logsObj, uint32_t* numLog);

//SlaveEx
/**
 * @brief In case of CoreStation, searches a slave device from the RS-485 network.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId CoreStation master device identifier.
 * @param[in] channelPort RS-485 channel port number to search.
 * @param[out] slaveDevices Pointer to the retrieved slave device array. Release with BS2_ReleaseObject().
 * @param[out] outchannelPort Pointer to receive the actual channel port used.
 * @param[out] slaveDeviceCount Number of discovered slave devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getslaveexdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSlaveExDevice(void* context, BS2_DEVICE_ID deviceId, uint32_t channelPort, BS2Rs485SlaveDeviceEX** slaveDevices, uint32_t* outchannelPort, uint32_t* slaveDeviceCount);
/**
 * @brief In case of CoreStation, adds, modifies, or deletes a slave device from the master device.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[in] deviceId CoreStation master device identifier.
 * @param[in] channelPort RS-485 channel port number.
 * @param[in] slaveDevices Array of extended slave device configurations to set.
 * @param[in] slaveDeviceCount Number of slave devices in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setslaveexdevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSlaveExDevice(void* context, BS2_DEVICE_ID deviceId, uint32_t channelPort, BS2Rs485SlaveDeviceEX* slaveDevices, uint32_t slaveDeviceCount);
/**
 * @brief Searches CoreStation devices from the current network.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_searchdevicescorestation.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SearchDevicesCoreStation(void* context);
/**
 * @brief Gets searched CoreStation devices.
 * @ingroup group_slave_control
 * @param[in] context SDK context handle.
 * @param[out] deviceListObj Pointer to the discovered CoreStation device ID array. Release with BS2_ReleaseObject().
 * @param[out] numDevice Number of discovered CoreStation devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicescorestation.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDevicesCoreStation(void* context, BS2_DEVICE_ID** deviceListObj, uint32_t* numDevice);

// OSDP
/**
 * @brief Adds an OSDP device.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[in] channelIndex RS-485 channel index to add the OSDP device on.
 * @param[in] osdpDevice Pointer to the BS2OsdpStandardDeviceAdd structure with OSDP device information.
 * @param[out] outChannelIndex Pointer to receive the assigned channel index.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_addosdpstandarddevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_AddOsdpStandardDevice(void* context, BS2_DEVICE_ID deviceId, uint32_t channelIndex, const BS2OsdpStandardDeviceAdd* osdpDevice, uint32_t* outChannelIndex);
/**
 * @brief Gets OSDP device information.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] osdpDeviceId OSDP device identifier.
 * @param[out] osdpDevice Pointer to the BS2OsdpStandardDevice structure to receive OSDP device information.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getosdpstandarddevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetOsdpStandardDevice(void* context, BS2_DEVICE_ID osdpDeviceId, BS2OsdpStandardDevice* osdpDevice);
/**
 * @brief Gets all OSDP device information of the specified master device.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[out] osdpDevices Pointer to the BS2OsdpStandardDeviceAvailable structure to receive available OSDP devices.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getavailableosdpstandarddevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAvailableOsdpStandardDevice(void* context, BS2_DEVICE_ID deviceId, BS2OsdpStandardDeviceAvailable* osdpDevices);
/**
 * @brief Updates OSDP device information.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[in] osdpDevices Array of OSDP device update structures.
 * @param[in] numOfDevice Number of OSDP devices to update.
 * @param[out] outResultObj Pointer to the result array. Release with BS2_ReleaseObject().
 * @param[out] outNumOfResult Number of result entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_updateosdpstandarddevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_UpdateOsdpStandardDevice(void* context, BS2_DEVICE_ID deviceId, const BS2OsdpStandardDeviceUpdate* osdpDevices, uint32_t numOfDevice, BS2OsdpStandardDeviceResult** outResultObj, uint32_t* outNumOfResult);
/**
 * @brief Removes the OSDP device.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Master device identifier.
 * @param[in] osdpDeviceIds Array of OSDP device IDs to remove.
 * @param[in] numOfDevice Number of OSDP device IDs to remove.
 * @param[out] outResultObj Pointer to the result array. Release with BS2_ReleaseObject().
 * @param[out] outNumOfResult Number of result entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeosdpstandarddevice.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveOsdpStandardDevice(void* context, BS2_DEVICE_ID deviceId, const BS2_DEVICE_ID* osdpDeviceIds, uint32_t numOfDevice, BS2OsdpStandardDeviceResult** outResultObj, uint32_t* outNumOfResult);
/**
 * @brief Gets OSDP device support information.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] osdpDeviceId OSDP device identifier.
 * @param[out] capability Pointer to the BS2OsdpStandardDeviceCapability structure to receive capability information.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getosdpstandarddevicecapability.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetOsdpStandardDeviceCapability(void* context, BS2_DEVICE_ID osdpDeviceId, BS2OsdpStandardDeviceCapability* capability);
/**
 * @brief Sets the security key for the OSDP device.
 * @ingroup group_slave_control
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] masterOrSlaveId Master or slave device identifier.
 * @param[in] key Pointer to the BS2OsdpStandardDeviceSecurityKey structure containing the security key.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setosdpstandarddevicesecuritykey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetOsdpStandardDeviceSecurityKey(void* context, BS2_DEVICE_ID masterOrSlaveId, const BS2OsdpStandardDeviceSecurityKey* key);
/**
 * @brief Registers a listener function that detects state changes of the OSDP device.
 * @ingroup group_server
 * @note [+ 2.9.1]
 * @param[in] context SDK context handle.
 * @param[in] ptrOsdpStandardDeviceStatus Callback function invoked when OSDP device status changes.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setosdpstandarddevicestatuslistener.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetOsdpStandardDeviceStatusListener(void* context, OnOsdpStandardDeviceStatusChanged ptrOsdpStandardDeviceStatus);

// Device license
/**
 * @brief Enables a device license.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] licenseBlob Pointer to the license blob data to activate.
 * @param[out] outResultObj Pointer to the license result array. Release with BS2_ReleaseObject().
 * @param[out] outNumOfResult Number of result entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enabledevicelicense.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnableDeviceLicense(void* context, BS2_DEVICE_ID deviceId, const BS2LicenseBlob* licenseBlob, BS2LicenseResult** outResultObj, uint32_t* outNumOfResult);
/**
 * @brief Disables a device license.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] licenseBlob Pointer to the license blob data to deactivate.
 * @param[out] outResultObj Pointer to the license result array. Release with BS2_ReleaseObject().
 * @param[out] outNumOfResult Number of result entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_disabledevicelicense.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_DisableDeviceLicense(void* context, BS2_DEVICE_ID deviceId, const BS2LicenseBlob* licenseBlob, BS2LicenseResult** outResultObj, uint32_t* outNumOfResult);
/**
 * @brief Queries the device license status.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] licenseType License type to query.
 * @param[out] outResultObj Pointer to the license result array. Release with BS2_ReleaseObject().
 * @param[out] outNumOfResult Number of result entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_querydevicelicense.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_QueryDeviceLicense(void* context, BS2_DEVICE_ID deviceId, BS2_LICENSE_TYPE licenseType, BS2LicenseResult** outResultObj, uint32_t* outNumOfResult);

//IntrusionAlarmZone
/**
 * @brief Retrieves selected Intrusion Alarm zones from the device.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneBlob Pointer to the BS2IntrusionAlarmZoneBlob structure to receive zone data.
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getintrusionalarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIntrusionAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2IntrusionAlarmZoneBlob* zoneBlob, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Intrusion Alarm zones.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getintrusionalarmzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIntrusionAlarmZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Intrusion Alarm zones.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallintrusionalarmzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllIntrusionAlarmZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures an Intrusion Alarm zone on the device.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneBlob Pointer to the BS2IntrusionAlarmZoneBlob structure containing zone configuration.
 * @param[in] zoneCount Number of zones to configure.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setintrusionalarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIntrusionAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2IntrusionAlarmZoneBlob* zoneBlob, uint32_t zoneCount);
/**
 * @brief Updates Intrusion Alarm zone alarm status.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setintrusionalarmzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIntrusionAlarmZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Intrusion Alarm zones from the device.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeintrusionalarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveIntrusionAlarmZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Intrusion Alarm zones from the device.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallintrusionalarmzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllIntrusionAlarmZone(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Sets the arm/disarm status of the Intrusion Alarm zone.
 * @ingroup group_intrusion_alarm_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] armed Non-zero to arm the zone, zero to disarm.
 * @param[in] zoneIds Array of zone IDs to arm/disarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setintrusionalarmzonearm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIntrusionAlarmZoneArm(void* context, BS2_DEVICE_ID deviceId, uint8_t armed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);

//InterlockZone
/**
 * @brief Gets selected Interlock zones from the device.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier (CoreStation).
 * @param[out] zoneBlob Pointer to the BS2InterlockZoneBlob structure to receive zone data.
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getinterlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetInterlockZone(void* context, BS2_DEVICE_ID deviceId, BS2InterlockZoneBlob* zoneBlob, uint32_t* numZone);
/**
 * @brief Gets selected Interlock zone status.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getinterlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetInterlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Gets all Interlock zone status information.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallinterlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllInterlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Sets Interlock Zones on the device.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier (CoreStation).
 * @param[in] zoneBlob Pointer to the BS2InterlockZoneBlob structure containing zone configuration.
 * @param[in] zoneCount Number of zones to configure.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setinterlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetInterlockZone(void* context, BS2_DEVICE_ID deviceId, BS2InterlockZoneBlob* zoneBlob, uint32_t zoneCount);
/**
 * @brief Updates the alarm status in the Interlock zone.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setinterlockzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetInterlockZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes the selected Interlock zone from the device.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeinterlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveInterlockZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Interlock zones from the device.
 * @ingroup group_interlock_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallinterlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllInterlockZone(void* context, BS2_DEVICE_ID deviceId);

//LiftLockUnlockZone
/**
 * @brief Retrieves selected Lift Lock/Unlock zones from the device.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to retrieve.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getliftlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLiftLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2LiftLockUnlockZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves all Lift Lock/Unlock zones from the device.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneObj Pointer to the retrieved zone array. Release with BS2_ReleaseObject().
 * @param[out] numZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallliftlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllLiftLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2LiftLockUnlockZone** zoneObj, uint32_t* numZone);
/**
 * @brief Retrieves the status of selected Lift Lock/Unlock zones.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to query status.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getliftlockunlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLiftLockUnlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Retrieves the status of all Lift Lock/Unlock zones.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] zoneStatusObj Pointer to the retrieved zone status array. Release with BS2_ReleaseObject().
 * @param[out] numZoneStatus Number of retrieved zone statuses.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallliftlockunlockzonestatus.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllLiftLockUnlockZoneStatus(void* context, BS2_DEVICE_ID deviceId, BS2ZoneStatus** zoneStatusObj, uint32_t* numZoneStatus);
/**
 * @brief Configures a Lift Lock/Unlock zone on the device.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zones Array of Lift Lock/Unlock zone configurations to set.
 * @param[in] zoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setliftlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetLiftLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2LiftLockUnlockZone* zones, uint32_t zoneCount);
/**
 * @brief Configures the alarm status of the Lift Lock/Unlock zone.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setliftlockunlockzonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetLiftLockUnlockZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes selected Lift Lock/Unlock zones from the device.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneIds Array of zone IDs to remove.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeliftlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveLiftLockUnlockZone(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Removes all Lift Lock/Unlock zones from the device.
 * @ingroup group_lift_lock_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallliftlockunlockzone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllLiftLockUnlockZone(void* context, BS2_DEVICE_ID deviceId);

//Ethernet Zone
/**
 * @brief Retrieves the zone master config of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2DeviceZoneMasterConfig structure to receive zone master configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicezonemasterconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceZoneMasterConfig(void* context, BS2_DEVICE_ID deviceId, BS2DeviceZoneMasterConfig* config);
/**
 * @brief Configures the zone master config of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2DeviceZoneMasterConfig structure containing zone master configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicezonemasterconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceZoneMasterConfig(void* context, BS2_DEVICE_ID deviceId, const BS2DeviceZoneMasterConfig* config);
/**
 * @brief Removes the zone master config of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removedevicezonemasterconfig.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveDeviceZoneMasterConfig(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves selected Ethernet zones from the device.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] Ids Array of zone table IDs to retrieve.
 * @param[in] IdCount Number of IDs in Ids.
 * @param[out] deviceZoneObj Pointer to the retrieved device zone array. Release with BS2_ReleaseObject().
 * @param[out] numDeviceZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicezone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceZone(void* context, BS2_DEVICE_ID deviceId, const BS2_DEVICE_ZONE_TABLE_ID* Ids, uint32_t IdCount, BS2DeviceZone** deviceZoneObj, uint32_t* numDeviceZone);
/**
 * @brief Retrieves all Ethernet zones from the device.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] deviceZoneObj Pointer to the retrieved device zone array. Release with BS2_ReleaseObject().
 * @param[out] numDeviceZone Number of retrieved zones.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalldevicezone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllDeviceZone(void* context, BS2_DEVICE_ID deviceId, BS2DeviceZone** deviceZoneObj, uint32_t* numDeviceZone);
/**
 * @brief Configures an Ethernet zone on the device.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] deviceZones Array of device zone configurations to set.
 * @param[in] deviceZoneCount Number of zones in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicezone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceZone(void* context, BS2_DEVICE_ID deviceId, const BS2DeviceZone* deviceZones, uint32_t deviceZoneCount);
/**
 * @brief Removes selected Ethernet zones from the device.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] Ids Array of zone table IDs to remove.
 * @param[in] IdCount Number of IDs in Ids.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removedevicezone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveDeviceZone(void* context, BS2_DEVICE_ID deviceId, const BS2_DEVICE_ZONE_TABLE_ID* Ids, uint32_t IdCount);
/**
 * @brief Removes all Ethernet zones from the device.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealldevicezone.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllDeviceZone(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Retrieves the device zone configuration of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2DeviceZoneConfig structure to receive zone configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceZoneConfig(void* context, BS2_DEVICE_ID deviceId, BS2DeviceZoneConfig* config);
/**
 * @brief Stores the device zone configuration of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2DeviceZoneConfig structure containing zone configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceZoneConfig(void* context, BS2_DEVICE_ID deviceId, const BS2DeviceZoneConfig* config);
/**
 * @brief Configures the alarm status of the Ethernet zone.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] alarmed Non-zero to activate alarm, zero to deactivate.
 * @param[in] zoneIds Array of zone IDs to configure alarm.
 * @param[in] zoneIdCount Number of IDs in zoneIds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicezonealarm.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceZoneAlarm(void* context, BS2_DEVICE_ID deviceId, uint8_t alarmed, BS2_ZONE_ID* zoneIds, uint32_t zoneIdCount);
/**
 * @brief Updates selected users to be not violating against the Ethernet zone rule.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Ethernet zone identifier.
 * @param[in] uids Array of user ID strings to clear access record for.
 * @param[in] uidCount Number of user IDs in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_cleardevicezoneaccessrecord.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearDeviceZoneAccessRecord(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID, char* uids, uint32_t uidCount);
/**
 * @brief Updates all users to be not violating against the Ethernet zone rule.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] zoneID Target Ethernet zone identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_clearalldevicezoneaccessrecord.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ClearAllDeviceZoneAccessRecord(void* context, BS2_DEVICE_ID deviceId, BS2_ZONE_ID zoneID);
/**
 * @brief Retrieves selected Ethernet Access Group Entrance limit.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] Ids Array of zone IDs to retrieve.
 * @param[in] IdCount Number of IDs in Ids.
 * @param[out] deviceZoneAGEntranceLimitObj Pointer to the retrieved entrance limit array. Release with BS2_ReleaseObject().
 * @param[out] numDeviceZoneAGEntranceLimit Number of retrieved entrance limit entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdevicezoneagentrancelimit.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDeviceZoneAGEntranceLimit(void* context, BS2_DEVICE_ID deviceId, const BS2_ZONE_ID* Ids, uint32_t IdCount, BS2DeviceZoneAGEntranceLimit** deviceZoneAGEntranceLimitObj, uint32_t* numDeviceZoneAGEntranceLimit);
/**
 * @brief Retrieves all Ethernet Access Group Entrance limit.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] deviceZoneAGEntranceLimitObj Pointer to the retrieved entrance limit array. Release with BS2_ReleaseObject().
 * @param[out] numDeviceZoneAGEntranceLimit Number of retrieved entrance limit entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getalldevicezoneagentrancelimit.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllDeviceZoneAGEntranceLimit(void* context, BS2_DEVICE_ID deviceId, BS2DeviceZoneAGEntranceLimit** deviceZoneAGEntranceLimitObj, uint32_t* numDeviceZoneAGEntranceLimit);
/**
 * @brief Configures Ethernet access group entrance limit.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] deviceZoneAGEntranceLimits Array of entrance limit configurations to set.
 * @param[in] deviceZoneAGEntranceLimitCount Number of entries in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdevicezoneagentrancelimit.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDeviceZoneAGEntranceLimit(void* context, BS2_DEVICE_ID deviceId, const BS2DeviceZoneAGEntranceLimit* deviceZoneAGEntranceLimits, uint32_t deviceZoneAGEntranceLimitCount);
/**
 * @brief Removes selected Ethernet access group entrance limit.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] Ids Array of zone IDs to remove entrance limit for.
 * @param[in] IdCount Number of IDs in Ids.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removedevicezoneagentrancelimit.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveDeviceZoneAGEntranceLimit(void* context, BS2_DEVICE_ID deviceId, const BS2_ZONE_ID* Ids, uint32_t IdCount);
/**
 * @brief Removes all Ethernet access group entrance limit.
 * @ingroup group_ethernet_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removealldevicezoneagentrancelimit.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllDeviceZoneAGEntranceLimit(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Registers callback function for global determination when an APB violation alarm occurs.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] ptrCheckGlobalAPBViolation Callback function invoked when global APB violation occurs.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setcheckglobalapbviolationhandler.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetCheckGlobalAPBViolationHandler(void* context, OnCheckGlobalAPBViolation ptrCheckGlobalAPBViolation);
/**
 * @brief Transfers Global APB results to the device.
 * @ingroup group_apb_zone
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the APB violation check.
 * @param[in] handleResult APB check result code (0 to allow, non-zero to deny).
 * @param[in] zoneID Anti Passback zone identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_checkglobalapbviolation.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_CheckGlobalAPBViolation(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2_ZONE_ID zoneID);
/**
 * @brief Registers callback function for global determination when an APB violation by door open alarm occurs.
 * @ingroup group_apb_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] ptrCheck Callback function invoked when APB violation by door open occurs.
 * @param[in] ptrUpdate Callback function invoked to update APB violation by door open status.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setglobalapbviolationbydooropenhandler.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetGlobalAPBViolationByDoorOpenHandler(void* context, OnCheckGlobalAPBViolationByDoorOpen ptrCheck, OnUpdateGlobalAPBViolationByDoorOpen ptrUpdate);
/**
 * @brief Transfers Global APB by door open results to the device.
 * @ingroup group_apb_zone
 * @note [+ 2.7.0]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the APB door open check.
 * @param[in] handleResult APB check result code (0 to allow, non-zero to deny).
 * @param[in] zoneID Anti Passback zone identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_checkglobalapbviolationbydooropen.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_CheckGlobalAPBViolationByDoorOpen(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2_ZONE_ID zoneID);

// Encryption Key
/**
 * @brief Gets the user data encryption key from the device.
 * @ingroup group_device_api
 * @deprecated Use BS2_SetDataEncryptKey() to set and track your own key.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] keyInfo Pointer to the BS2EncryptKey structure to receive the encryption key.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdataencryptkey.md
 */
DEPRECATED_FUNC BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDataEncryptKey(void* context, BS2_DEVICE_ID deviceId, BS2EncryptKey* keyInfo);
/**
 * @brief Sets the user data encryption key on the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] keyInfo Pointer to the BS2EncryptKey structure containing the encryption key to set.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdataencryptkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDataEncryptKey(void* context, BS2_DEVICE_ID deviceId, const BS2EncryptKey* keyInfo);
/**
 * @brief Removes the user data encryption key from the device.
 * @ingroup group_device_api
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removedataencryptkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveDataEncryptKey(void* context, BS2_DEVICE_ID deviceId);

//[IPv6]
/**
 * @brief Retrieves IP configuration through UDP broadcast with host IP.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IpConfig structure to receive IP configuration.
 * @param[in] hostipAddr Host IP address string for targeted UDP broadcast.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipconfigviaudpex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPConfigViaUDPEx(void* context, BS2_DEVICE_ID deviceId, BS2IpConfig* config, const char* hostipAddr);
/**
 * @brief Stores IP configuration through UDP broadcast with host IP.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IpConfig structure containing IP configuration.
 * @param[in] hostipAddr Host IP address string for targeted UDP broadcast.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipconfigviaudpex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPConfigViaUDPEx(void* context, BS2_DEVICE_ID deviceId, const BS2IpConfig* config, const char* hostipAddr);
/**
 * @brief Retrieves IPv6 configuration information from the device.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IPV6Config structure to receive IPv6 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipv6config.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPV6Config(void* context, BS2_DEVICE_ID deviceId, BS2IPV6Config* config);
/**
 * @brief Stores IPv6 configuration information on the device.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IPV6Config structure containing IPv6 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipv6config.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPV6Config(void* context, BS2_DEVICE_ID deviceId, const BS2IPV6Config* config);
/**
 * @brief Retrieves IPv6 configuration through UDP broadcast.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IPV6Config structure to receive IPv6 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipv6configviaudp.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPV6ConfigViaUDP(void* context, BS2_DEVICE_ID deviceId, BS2IPV6Config* config);
/**
 * @brief Stores IPv6 configuration through UDP broadcast.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IPV6Config structure containing IPv6 configuration.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipv6configviaudp.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPV6ConfigViaUDP(void* context, BS2_DEVICE_ID deviceId, const BS2IPV6Config* config);
/**
 * @brief Retrieves IPv6 configuration through UDP broadcast with host IP.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] config Pointer to the BS2IPV6Config structure to receive IPv6 configuration.
 * @param[in] hostipAddr Host IP address string for targeted UDP broadcast.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getipv6configviaudpex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetIPV6ConfigViaUDPEx(void* context, BS2_DEVICE_ID deviceId, BS2IPV6Config* config, const char* hostipAddr);
/**
 * @brief Stores IPv6 configuration through UDP broadcast with host IP.
 * @ingroup group_configuration
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] config Pointer to the BS2IPV6Config structure containing IPv6 configuration.
 * @param[in] hostipAddr Host IP address string for targeted UDP broadcast.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setipv6configviaudpex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetIPV6ConfigViaUDPEx(void* context, BS2_DEVICE_ID deviceId, const BS2IPV6Config* config, const char* hostipAddr);
/**
 * @brief Gets IPv4 connection mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] enable Pointer to receive the IPv4 enable state (non-zero if enabled).
 * @return `BS_SDK_SUCCESS` on success, error code on failure.
 * @include{doc} bs2_getenableipv4.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetEnableIPV4(void* context, int* enable);
/**
 * @brief Sets IPv4 connection mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] enable Non-zero to enable IPv4, zero to disable.
 * @return `BS_SDK_SUCCESS` on success, error code on failure.
 * @include{doc} bs2_setenableipv4.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetEnableIPV4(void* context, int enable);
/**
 * @brief Gets IPv6 connection mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] enable Pointer to receive the IPv6 enable state (non-zero if enabled).
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getenableipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetEnableIPV6(void* context, int* enable);
/**
 * @brief Sets IPv6 connection mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] enable Non-zero to enable IPv6, zero to disable.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setenableipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetEnableIPV6(void* context, int enable);
/**
 * @brief Sets server port when connecting IPv6 server mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] serverPort Port number to set for IPv6 server connections.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setserverportipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetServerPortIPV6(void* context, BS2_PORT serverPort);
/**
 * @brief Gets server port when connecting IPv6 server mode.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] serverPort Pointer to receive the IPv6 server port number.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getserverportipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetServerPortIPV6(void* context, BS2_PORT* serverPort);
/**
 * @brief Sets server port when connecting IPv6 server mode using SSL.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] sslServerPort SSL port number to set for IPv6 server connections.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setsslserverportipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetSSLServerPortIPV6(void* context, BS2_PORT sslServerPort);
/**
 * @brief Gets server port when connecting IPv6 server mode using SSL.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] sslServerPort Pointer to receive the IPv6 SSL server port number.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsslserverportipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSSLServerPortIPV6(void* context, BS2_PORT* sslServerPort);
/**
 * @brief Gets specified device information.
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] specifiedDeviceInfo Enum specifying which device information to retrieve.
 * @param[out] pOutDeviceInfo Pointer to buffer to receive the specified device information.
 * @param[in] nDeviceInfoSize Size of the pOutDeviceInfo buffer in bytes.
 * @param[out] pOutDeviceInfoSize Pointer to receive the actual size of the returned data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getspecifieddeviceinfo.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSpecifiedDeviceInfo(void* context, BS2_DEVICE_ID deviceId, BS2EnumSpecifiedDeviceInfo specifiedDeviceInfo, void* pOutDeviceInfo, uint32_t nDeviceInfoSize, uint32_t* pOutDeviceInfoSize);
/**
 * @brief Connects the device in IPv6 mode using the device identifier.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_connectdeviceipv6.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_ConnectDeviceIPV6(void* context, BS2_DEVICE_ID deviceId);
/**
 * @brief Searches CoreStation devices from the current network with host IP.
 * @ingroup group_slave_control
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] hostipAddr Host IP address string for targeted search.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_searchdevicescorestationex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SearchDevicesCoreStationEx(void* context, const char* hostipAddr);


//[Get ServerPort]
/**
 * @brief Gets the server port.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] serverPort Pointer to receive the server port number.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getserverport.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetServerPort(void* context, BS2_PORT* serverPort);
/**
 * @brief Gets the SSL server port.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] sslServerPort Pointer to receive the SSL server port number.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getsslserverport.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetSSLServerPort(void* context, BS2_PORT* sslServerPort);


//[Set/Get default response wait timeout]
/**
 * @brief Sets the default response timeout between device and server.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] ms Response timeout in milliseconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdefaultresponsetimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDefaultResponseTimeout(void* context, long ms);
/**
 * @brief Gets the default response timeout between device and server.
 * @ingroup group_communication_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[out] poMs Pointer to receive the default response timeout in milliseconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdefaultresponsetimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDefaultResponseTimeout(void* context, long* poMs);
/**
 * @brief Sets the packet response timeout with the device (for time-intensive APIs).
 * @ingroup group_communication_api
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] ms Long response timeout in milliseconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setdefaultlongresponsetimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetDefaultLongResponseTimeout(void* context, long ms);
/**
 * @brief Checks the packet response timeout information with the device (for time-intensive APIs).
 * @ingroup group_communication_api
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[out] poMs Pointer to receive the long response timeout in milliseconds.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getdefaultlongresponsetimeout.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetDefaultLongResponseTimeout(void* context, long* poMs);


//[User Small Blob]
/**
 * @brief Transfers user information (small blob) mapped to the card or user ID authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the BS2UserSmallBlob structure to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyusersmall.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyUserSmall(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserSmallBlob* userBlob);
/**
 * @brief Transfers user information (small blob) mapped to the fingerprint authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the BS2UserSmallBlob structure to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_identifyusersmall.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IdentifyUserSmall(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserSmallBlob* userBlob);
/**
 * @brief Gets the user information (small blob) of the given user IDs with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfos.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfos(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob);
/**
 * @brief Gets selected data (small blob) of the given users with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatas.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatas(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Enrolls new user with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Pointer to the array of BS2UserSmallBlob structures containing user data.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite Non-zero to overwrite existing users, zero to skip on conflict.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enrollusersmall.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrollUserSmall(void* context, BS2_DEVICE_ID deviceId, BS2UserSmallBlob* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Transfers user information (small blob ex) mapped to the card or user ID authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the BS2UserSmallBlobEx structure to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyusersmallex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyUserSmallEx(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserSmallBlobEx* userBlob);
/**
 * @brief Transfers user information (small blob ex) mapped to the fingerprint authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the BS2UserSmallBlobEx structure to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_identifyusersmallex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_IdentifyUserSmallEx(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserSmallBlobEx* userBlob);
/**
 * @brief Gets the user information (small blob ex, including Job code and User phrase) of the given user IDs with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfosex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfosEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob);
/**
 * @brief Gets selected data (small blob ex, including Job code and User phrase) of the given users with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatasex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatasEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Enrolls new user (including Job code and User phrase) with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Pointer to the array of BS2UserSmallBlobEx structures containing user data.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite Non-zero to overwrite existing users, zero to skip on conflict.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enrollusersmallex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrollUserSmallEx(void* context, BS2_DEVICE_ID deviceId, BS2UserSmallBlobEx* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Gets the user information (small blob) of the given user IDs from USB exported data.
 * @ingroup group_usb_export
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfosfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfosFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob);
/**
 * @brief Gets selected data (small blob) of the given users from USB exported data with efficient use of memory.
 * @ingroup group_usb_export
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatasfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatasFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Gets the user information (small blob ex, including Job code and User phrase) of the given user IDs from USB exported data.
 * @ingroup group_usb_export
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfosexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfosExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob);
/**
 * @brief Gets selected data (small blob ex, including Job code and User phrase) of the given users from USB exported data.
 * @ingroup group_usb_export
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatasexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatasExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob, BS2_USER_MASK userMask);


//[Admin 1000]
/**
 * @brief Gets specified device operators (supports up to 1000 operators).
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userIDs Array of user ID strings for the operators to retrieve.
 * @param[in] userIDCount Number of user IDs in the array.
 * @param[out] operatorlevelObj Pointer to the retrieved operator level array. Release with BS2_ReleaseObject().
 * @param[out] numOperatorlevel Number of retrieved operator level entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getauthoperatorlevelex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAuthOperatorLevelEx(void* context, BS2_DEVICE_ID deviceId, BS2_USER_ID* userIDs, uint32_t userIDCount, BS2AuthOperatorLevel** operatorlevelObj, uint32_t* numOperatorlevel);
/**
 * @brief Gets all device operators (supports up to 1000 operators).
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] operatorlevelObj Pointer to the retrieved operator level array. Release with BS2_ReleaseObject().
 * @param[out] numOperatorlevel Number of retrieved operator level entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getallauthoperatorlevelex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetAllAuthOperatorLevelEx(void* context, BS2_DEVICE_ID deviceId, BS2AuthOperatorLevel** operatorlevelObj, uint32_t* numOperatorlevel);
/**
 * @brief Sets device operators (supports up to 1000 operators).
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] operatorlevels Array of BS2AuthOperatorLevel structures to set.
 * @param[in] operatorlevelCount Number of operator levels in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setauthoperatorlevelex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetAuthOperatorLevelEx(void* context, BS2_DEVICE_ID deviceId, BS2AuthOperatorLevel* operatorlevels, uint32_t operatorlevelCount);
/**
 * @brief Removes specified device operators (supports up to 1000 operators).
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userIDs Array of user ID strings for the operators to remove.
 * @param[in] userIDCount Number of user IDs in the array.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeauthoperatorlevelex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAuthOperatorLevelEx(void* context, BS2_DEVICE_ID deviceId, BS2_USER_ID* userIDs, uint32_t userIDCount);
/**
 * @brief Removes all device operators (supports up to 1000 operators).
 * @ingroup group_device_api
 * @note [+ 2.6.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_removeallauthoperatorlevelex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_RemoveAllAuthOperatorLevelEx(void* context, BS2_DEVICE_ID deviceId);


/**
 * @brief Gets the master admin from the device.
 * @ingroup group_device_api
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] masterAdmin Pointer to the BS2UserFaceExBlob structure to receive master admin data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getmasteradmin.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetMasterAdmin(void* context, BS2_DEVICE_ID deviceId, BS2UserFaceExBlob* masterAdmin);
/**
 * @brief Sets the master admin on the device.
 * @ingroup group_device_api
 * @note [+ 2.9.12]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] masterAdmin Pointer to the BS2UserFaceExBlob structure containing master admin data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_setmasteradmin.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_SetMasterAdmin(void* context, BS2_DEVICE_ID deviceId, const BS2UserFaceExBlob* masterAdmin);
/**
 * @brief Gets a certain amount of logs based on the event mask in an efficient way.
 * @ingroup group_log_management
 * @note [+ 2.6.4]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblob.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlob(void* context, BS2_DEVICE_ID deviceId, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlob** logsObj, uint32_t* numLog);
/**
 * @brief Gets a certain amount of logs based on the event mask from USB exported data in an efficient way.
 * @ingroup group_usb_export
 * @note [+ 2.6.4]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblobfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlobFromDir(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlob** logsObj, uint32_t* numLog);
/**
 * @brief Gets a certain amount of logs based on the event mask in an efficient way, including temperature information.
 * @ingroup group_log_management
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob ex array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblobex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlobEx(void* context, BS2_DEVICE_ID deviceId, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlobEx** logsObj, uint32_t* numLog);
/**
 * @brief Gets a certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way.
 * @ingroup group_usb_export
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob ex array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblobexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlobExFromDir(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlobEx** logsObj, uint32_t* numLog);

// FaceEx
/**
 * @brief Visual Face Support: Enrolls new user.
 * @ingroup group_user_management
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] userBlob Pointer to the array of BS2UserFaceExBlob structures containing user data.
 * @param[in] userCount Number of users to enroll.
 * @param[in] overwrite Non-zero to overwrite existing users, zero to skip on conflict.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_enrolluserfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_EnrollUserFaceEx(void* context, BS2_DEVICE_ID deviceId, BS2UserFaceExBlob* userBlob, uint32_t userCount, uint8_t overwrite);
/**
 * @brief Visual Face Support: Gets the user information of the given user IDs.
 * @ingroup group_user_management
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosFaceEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob);
/**
 * @brief Visual Face Support: Gets selected data of the given users.
 * @ingroup group_user_management
 * @note [+ 2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasFaceEx(void* context, BS2_DEVICE_ID deviceId, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Visual Face Support: Gets the user information of the given user IDs from USB exported data.
 * @ingroup group_usb_export
 * @note [+2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosfaceexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosFaceExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob);
/**
 * @brief Visual Face Support: Gets selected data of the given users from USB exported data.
 * @ingroup group_usb_export
 * @note [+2.7.1]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasfaceexfromdir.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasFaceExFromDir(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob, BS2_USER_MASK userMask);
/**
 * @brief Updates partial information of an already registered user.
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] mask Bitmask specifying which user data fields to update.
 * @param[in] userBlob Pointer to the array of BS2UserBlob structures containing updated user data.
 * @param[in] userCount Number of users to update.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_partialupdateuser.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_PartialUpdateUser(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK mask, BS2UserBlob* userBlob, uint32_t userCount);
/**
 * @brief Updates partial information of an already registered user (including Job code and User phrase).
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] mask Bitmask specifying which user data fields to update.
 * @param[in] userBlob Pointer to the array of BS2UserBlobEx structures containing updated user data.
 * @param[in] userCount Number of users to update.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_partialupdateuserex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_PartialUpdateUserEx(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK mask, BS2UserBlobEx* userBlob, uint32_t userCount);
/**
 * @brief Updates partial information of an already registered user with efficient use of memory.
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] mask Bitmask specifying which user data fields to update.
 * @param[in] userBlob Pointer to the array of BS2UserSmallBlob structures containing updated user data.
 * @param[in] userCount Number of users to update.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_partialupdateusersmall.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_PartialUpdateUserSmall(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK mask, BS2UserSmallBlob* userBlob, uint32_t userCount);
/**
 * @brief Updates partial information of an already registered user with efficient use of memory (including Job code and User phrase).
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] mask Bitmask specifying which user data fields to update.
 * @param[in] userBlob Pointer to the array of BS2UserSmallBlobEx structures containing updated user data.
 * @param[in] userCount Number of users to update.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_partialupdateusersmallex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_PartialUpdateUserSmallEx(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK mask, BS2UserSmallBlobEx* userBlob, uint32_t userCount);
/**
 * @brief Visual Face Support: Updates partial information of an already registered user.
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] mask Bitmask specifying which user data fields to update.
 * @param[in] userBlob Pointer to the array of BS2UserFaceExBlob structures containing updated user data.
 * @param[in] userCount Number of users to update.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_partialupdateuserfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_PartialUpdateUserFaceEx(void* context, BS2_DEVICE_ID deviceId, BS2_USER_MASK mask, BS2UserFaceExBlob* userBlob, uint32_t userCount);
/**
 * @brief Gets the user-related statistics that the device has.
 * @ingroup group_user_management
 * @note [+ 2.8.3]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[out] userStatistic Pointer to the BS2UserStatistic structure to receive user statistics.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserstatistic.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserStatistic(void* context, BS2_DEVICE_ID deviceId, BS2UserStatistic* userStatistic);

//USB Exported (+V2.8.2.4)
/**
 * @brief Gets total user information (number of users/cards/fingerprints/faces) from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[out] numUsers Pointer to receive the total number of enrolled users.
 * @param[out] numCards Pointer to receive the total number of enrolled cards.
 * @param[out] numFingers Pointer to receive the total number of enrolled fingerprints.
 * @param[out] numFaces Pointer to receive the total number of enrolled faces.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatabaseinfofromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatabaseInfoFromDirWithKey(void* context, const char* szDir, uint32_t* numUsers, uint32_t* numCards, uint32_t* numFingers, uint32_t* numFaces, IsAcceptableUserID ptrIsAcceptableUserID, const BS2EncryptKey* key);
/**
 * @brief Gets the enrolled user ID list from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[out] uidsObj Pointer to the retrieved user ID list. Release with BS2_ReleaseObject().
 * @param[out] numUid Number of retrieved user IDs.
 * @param[in] ptrIsAcceptableUserID Callback to filter acceptable user IDs (NULL to accept all).
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserlistfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserListFromDirWithKey(void* context, const char* szDir, char** uidsObj, uint32_t* numUid, IsAcceptableUserID ptrIsAcceptableUserID, const BS2EncryptKey* key);
/**
 * @brief Gets the user information of the given user IDs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlob* userBlob, const BS2EncryptKey* key);
/**
 * @brief Gets selected data of the given users from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlob* userBlob, BS2_USER_MASK userMask, const BS2EncryptKey* key);
/**
 * @brief Gets the user information (including Job code and User phrase) of the given user IDs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive user data.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob, const BS2EncryptKey* key);
/**
 * @brief Gets selected data (including Job code and User phrase) of the given users from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserBlobEx structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserBlobEx* userBlob, BS2_USER_MASK userMask, const BS2EncryptKey* key);
/**
 * @brief Gets a certain amount of logs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting log data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogFromDirWithKey(void* context, const char* szDir, BS2_EVENT_ID eventId, uint32_t amount, BS2Event** logsObj, uint32_t* numLog, const BS2EncryptKey* key);
/**
 * @brief Gets filtered logs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uid User ID to filter by (NULL for all users).
 * @param[in] eventCode Event code to filter by.
 * @param[in] start Start timestamp for filtering.
 * @param[in] end End timestamp for filtering.
 * @param[in] tnakey TNA key to filter by.
 * @param[out] logsObj Pointer to the retrieved log array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting log data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getfilteredlogfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetFilteredLogFromDirWithKey(void* context, const char* szDir, char* uid, BS2_EVENT_CODE eventCode, BS2_TIMESTAMP start, BS2_TIMESTAMP end, uint8_t tnakey, BS2Event** logsObj, uint32_t* numLog, const BS2EncryptKey* key);
/**
 * @brief Gets the user information (small blob) of the given user IDs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfosfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfosFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob, const BS2EncryptKey* key);
/**
 * @brief Gets selected data (small blob) of the given users from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatasfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatasFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlob* userBlob, BS2_USER_MASK userMask, const BS2EncryptKey* key);
/**
 * @brief Gets the user information (small blob ex, including Job code and User phrase) of the given user IDs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmallinfosexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallInfosExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob, const BS2EncryptKey* key);
/**
 * @brief Gets selected data (small blob ex, including Job code and User phrase) of the given users from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserSmallBlobEx structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getusersmalldatasexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserSmallDatasExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserSmallBlobEx* userBlob, BS2_USER_MASK userMask, const BS2EncryptKey* key);
/**
 * @brief Visual Face Support: Gets the user information of the given user IDs from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserinfosfaceexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserInfosFaceExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob, const BS2EncryptKey* key);
/**
 * @brief Visual Face Support: Gets selected data of the given users from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] uids Array of user ID strings to retrieve.
 * @param[in] uidCount Number of user IDs in the array.
 * @param[out] userBlob Pointer to the array of BS2UserFaceExBlob structures to receive user data.
 * @param[in] userMask Bitmask specifying which user data fields to retrieve.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting user data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getuserdatasfaceexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetUserDatasFaceExFromDirWithKey(void* context, const char* szDir, char* uids, uint32_t uidCount, BS2UserFaceExBlob* userBlob, BS2_USER_MASK userMask, const BS2EncryptKey* key);
/**
 * @brief Gets a certain amount of logs based on the event mask from USB exported data using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting log data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogblobfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogBlobFromDirWithKey(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventBlob** logsObj, uint32_t* numLog, const BS2EncryptKey* key);
/**
 * @brief Gets a certain amount of logs based on the event mask from USB exported data in an efficient way using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting log data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblobfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlobFromDirWithKey(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlob** logsObj, uint32_t* numLog, const BS2EncryptKey* key);
/**
 * @brief Gets a certain amount of logs including temperature information based on the event mask from USB exported data in an efficient way using an encryption key.
 * @ingroup group_usb_export
 * @note [+2.8.2]
 * @param[in] context SDK context handle.
 * @param[in] szDir Path to the USB exported data directory.
 * @param[in] eventMask Bitmask specifying which event types to include.
 * @param[in] eventId Starting event ID to retrieve logs from.
 * @param[in] amount Maximum number of log entries to retrieve.
 * @param[out] logsObj Pointer to the retrieved small log blob ex array. Release with BS2_ReleaseObject().
 * @param[out] numLog Number of retrieved log entries.
 * @param[in] key Pointer to the BS2EncryptKey structure for decrypting log data.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_getlogsmallblobexfromdirwithkey.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_GetLogSmallBlobExFromDirWithKey(void* context, const char* szDir, uint16_t eventMask, BS2_EVENT_ID eventId, uint32_t amount, BS2EventSmallBlobEx** logsObj, uint32_t* numLog, const BS2EncryptKey* key);
/**
 * @brief Visual Face Support: Transfers user information mapped to the card or user ID authentication results to the device.
 * @ingroup group_server
 * @note [+ 2.7.2]
 * @param[in] context SDK context handle.
 * @param[in] deviceId Target device identifier.
 * @param[in] seq Packet sequence number from the matching request.
 * @param[in] handleResult Authentication result code (0 for success).
 * @param[in] userBlob Pointer to the BS2UserFaceExBlob structure to send to the device.
 * @return BS_SDK_SUCCESS on success, error code on failure.
 * @include{doc} bs2_verifyuserfaceex.md
 */
BS_API_EXPORT int BS_CALLING_CONVENTION BS2_VerifyUserFaceEx(void* context, BS2_DEVICE_ID deviceId, BS2_PACKET_SEQ seq, int handleResult, BS2UserFaceExBlob* userBlob);


#ifdef __cplusplus
}
#endif


#endif /* CORE_SRC_BS_API_H_ */
