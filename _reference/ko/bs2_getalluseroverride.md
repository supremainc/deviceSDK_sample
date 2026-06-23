# BS2_GetAllUserOverride

:::info

 Àå¾ÖÀÎÀÌ³ª ¹è´Þ¿ø µî ÃâÀÔ¿¡ ´õ ¸¹Àº ½Ã°£ÀÌ ÇÊ¿äÇÑ »ç¿ëÀÚ¸¦ À§ÇØ, Ç¥ÁØ °³¹æ ½Ã°£º¸´Ù ±æ°Ô ÃâÀÔ¹®À» ¿­¾îµÑ ¼ö ÀÖ´Â ±â´ÉÀÔ´Ï´Ù.

[BS2Door](door_control_api#bs2door)ÀÇ extendedAutoLockTimeout¸¦ ÅëÇØ ÇØ´ç ÃâÀÔ¹®¿¡ ¿¬Àå °³¹æ ½Ã°£À» ¼³Á¤ÇÏ°í, [BS2UserOverride](user_management_api#bs2useroverride)¸¦ ÅëÇØ ¿¬Àå °³¹æ ½Ã°£À» Àû¿ëÇÒ »ç¿ëÀÚ¸¦ ÁöÁ¤ÇÕ´Ï´Ù.

¿¬ÀåµÈ °³¹æ ½Ã°£ »ç¿ë ½Ã, ´ÙÀ½ ±ÔÄ¢À» µû¸¨´Ï´Ù.

* ¿¬Àå °³¹æ ½Ã°£ ´ë»ó »ç¿ëÀÚ¿Í ºñ´ë»ó »ç¿ëÀÚ°¡ ¿¬¼ÓÀ¸·Î ÀÎÁõÇÏ´Â °æ¿ì, ¸¶Áö¸·¿¡ ÀÎÁõÇÑ »ç¿ëÀÚ¸¦ ±âÁØÀ¸·Î °³¹æ ½Ã°£ÀÌ Àû¿ëµË´Ï´Ù.

- 2´Ü°è ÀÎÁõ »ç¿ë ½Ã, ÀÎÁõ »ç¿ëÀÚ Áß ÇÑ ¸íÀÌ¶óµµ ¿¬Àå °³¹æ ½Ã°£ ´ë»óÀÚ¶ó¸é ¿¬ÀåµÈ °³¹æ ½Ã°£À¸·Î ÃâÀÔ¹®ÀÌ ¿­¸³´Ï´Ù.

</callout\> <Badge only>+ v2.9.12</Badge> ¿¬ÀåµÈ ÃâÀÔ¹® °³¹æ ½Ã°£À» »ç¿ëÇÏ´Â ¸ðµç »ç¿ëÀÚ Á¤º¸¸¦ °¡Á®¿É´Ï´Ù.

## ÇÔ¼ö

```cpp
#include "BS_API.h"

int BS2_GetAllUserOverride(void* context, BS2_DEVICE_ID deviceId, BS2UserOverride** overrideObjs, uint32_t* numOfOverrides);
```

:::info

 [BS2UserOverride ±¸Á¶Ã¼ º¸±â](user management api#BS2UserOverride) 

:::

## ÆÄ¶ó¹ÌÅÍ

- \[In\] `context` : Context

- \[In\] `deviceId` : ÀåÄ¡ ½Äº°ÀÚ

- \[Out\] `overrideObjs` : ¿¬ÀåµÈ ÃâÀÔ¹® °³¹æ ½Ã°£À» »ç¿ëÇÏ´Â »ç¿ëÀÚ Á¤º¸°¡ ÀúÀåµÉ Æ÷ÀÎÅÍ

- \[Out\] `numOfOverrides` : ÃëµæÇÑ »ç¿ëÀÚÀÇ ¼ö¸¦ ÀúÀåÇÒ Æ÷ÀÎÅÍ

==== ¹ÝÈ¯°ª ==== ¼º°øÀûÀ¸·Î ¼öÇàµÉ °æ¿ì `BS_SDK_SUCCESS`¸¦ ¹ÝÈ¯ÇÏ°í, ½ÇÆÐÇßÀ» °æ¿ì »óÀÀÇÏ´Â ¿¡·¯ ÄÚµå¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.

## ÇÔ²² º¸±â

[BS2_GetUserOverride](bs2_getuseroverride)

[BS2_SetUserOverride](bs2_setuseroverride)

[BS2_RemoveUserOverride](bs2_removeuseroverride)

[BS2_RemoveAllUserOverride](bs2_removealluseroverride)
