# 다중 Wiegand 포맷 지원

## 1. 다중 Wiegand 포맷 지원이 필요한 이유

기기에 단일 Wiegand 포맷만 저장되어 있는 경우, 다른 Wiegand 포맷의 카드를 읽을 때마다 기기의 Wiegand 설정을 변경해야 합니다. 하지만 기기에 다중 Wiegand 포맷을 저장해 놓으면, 서로 다른 Wiegand 포맷의 카드를 읽기 위해 기기의 Wiegand 설정을 변경할 필요가 없습니다. 다중 Wiegand 포맷 지원은 회사가 보안 강화를 위해 출입 카드의 Wiegand 포맷을 변경하기로 결정했을 때(예: 26비트 근접 카드에서 35비트 Corporate 1000으로) 매우 중요합니다. 모든 직원의 카드를 동시에 교체하는 것은 현실적으로 불가능하기 때문에 항상 전환 기간이 필요합니다. 이 기간 동안 카드 리더기는 서로 다른 Wiegand 포맷의 카드를 읽을 수 있어야 합니다. 다중 Wiegand 포맷을 지원하지 않는 리더기는 이러한 상황에 대응할 수 없습니다.

## 2. 다중 Wiegand 형식 지원 작동 방식

BioStar를 접근 제어 관리 시스템으로 사용하는 경우, BioStar 서버의 Wiegand 형식 구성이 장치로 자동으로 전송됩니다. 그런 다음 장치 상세 페이지에서 사용할 Wiegand 형식을 지정해야 합니다. BioStar Device SDK를 사용하여 자체 애플리케이션을 개발하는 경우, Wiegand 형식 구성을 생성하고 전송해야 합니다. 또한 사용할 Wiegand 형식을 지정하는 데 필요한 Wiegand 형식 인덱스가 포함된 구성도 전송해야 합니다. BS2WiegandMultiConfig 데이터 구조의 formats 필드에는 최대 15개의 서로 다른 Wiegand 형식을 저장할 수 있습니다.

    public struct BS2WiegandMultiConfig

    {

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 15)]

        public BS2WiegandInConfig[] formats;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]

        public byte[] reserved;

    }

BS2WiegandConfig 데이터 구조에는 사용할 위건드 형식의 인덱스를 지정할 수 있는 세 개의 마스크 필드가 있습니다.

    public struct BS2WiegandConfig

    {

        public byte mode;

        public byte useWiegandBypass;

        public byte useFailCode;

        public byte failCode;

        public UInt16 outPulseWidth; //(20 ~ 100 us)

        public UInt16 outPulseInterval; //(200 ~ 20000 us)

        public UInt32 formatID;

        public BS2WiegandFormat format;

        public UInt16 wiegandInputMask;

        public UInt16 wiegandCardMask;

        public byte wiegandCSNIndex;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 27)]

        public byte[] reserved;

    }

- wiegandInputMask: 슬레이브 장치와 Wiegand 장치에 사용할 Wiegand 형식의 인덱스를 나타내는 비트마스크입니다. 슬레이브 장치는 더미 장치로 작동하며 Wiegand 구성을 저장하지 않습니다(슬레이브 장치는 RS485를 통해 다른 Suprema 장치에 더미 리더로 연결된 Suprema 장치입니다). BS2WiegandMultiConfig 데이터 구조의 formats 배열 필드에서 첫 번째 및 세 번째 요소(배열 인덱스: 0 및 2)를 지정하려면 비트마스크를 0000000000001010으로 설정해야 합니다. 0번째 비트는 하위 호환성을 위해 예약되어 있기 때문입니다. 이 wiegandInputMask 필드는 슬레이브 장치(또는 Wiegand 장치)에서 Wiegand 카드(iClass 또는 Prox)를 읽을 때 적용됩니다.

- wiegandCardMask: 마스터 장치에 사용할 Wiegand 형식의 인덱스를 나타내는 비트마스크입니다. 장치가 마스터 장치로 작동할 때, 이 필드에 지정된 위건드 형식과 일치하는 위건드 카드를 읽습니다. BS2WiegandMultiConfig 데이터 구조의 formats 배열 필드에서 첫 번째 및 세 번째 요소(배열 인덱스: 0 및 2)를 지정하려면 비트마스크를 0000000000001010으로 설정해야 합니다. 0번째 비트는 하위 호환성을 위해 예약되어 있기 때문입니다. 이 wiegandCardMask 필드는 마스터 장치에서 위건드 카드(iClass 또는 Prox)를 읽을 때 적용됩니다.

- wiegandCSNIndex: 마스터 장치와 슬레이브 장치 모두에서 카드 일련 번호를 변환하는 데 사용되는 위건드 형식의 인덱스를 포함합니다. 위건드 형식이 아닌 카드(Mifare 또는 EM)를 장치에 플래싱하면 카드에서 카드 일련 번호를 읽어 이 필드에 지정된 위건드 형식으로 변환합니다. 이 필드에는 하나의 인덱스만 설정할 수 있습니다. BS2WiegandMultiConfig 데이터 구조의 formats 배열 필드의 세 번째 요소(배열 인덱스: 2)에 저장된 Wiegand 형식으로 카드 일련 번호를 변환하려면 wiegandCSNIndex 필드를 3으로 설정해야 합니다. 이 wiegandCSNIndex 필드는 마스터 및 슬레이브 장치 모두에서 Wiegand 형식이 아닌 카드(Mifare 또는 EM)를 읽을 때 적용됩니다.

위의 세 가지 마스크 필드가 모두 0으로 설정된 경우, 장치는 BS2WiegandConfig 데이터 구조의 BS2WiegandFormat 필드에 저장된 Wiegand 형식과 일치하는 Wiegand 카드를 읽으려고 시도합니다.

    public struct BS2WiegandConfig

    {

        public byte mode;

        public byte useWiegandBypass;

        public byte useFailCode;

        public byte failCode;

        public UInt16 outPulseWidth;    //(20 ~ 100 us)

        public UInt16 outPulseInterval; //(200 ~ 20000 us)

        public UInt32 formatID;

        public BS2WiegandFormat format;

        public UInt16 wiegandInputMask;

        public UInt16 wiegandCardMask;

        public byte wiegandCSNIndex;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 27)]

        public byte[] reserved;

    }

## 3. 예제 (C#)

```csharp
// 26 bit H10301
IntPtr the26bitformatPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(BS2WiegandFormat)));
BS2WiegandFormat the26bitFormat = new BS2WiegandFormat();
the26bitFormat.idFields = new byte[128];
the26bitFormat.parityFields = new byte[128];
the26bitFormat.parityType = new byte[4];
the26bitFormat.parityPos = new byte[4];
                                
the26bitFormat.length = 26;

the26bitFormat.parityPos[0] = 0;
the26bitFormat.parityPos[1] = 25;

the26bitFormat.parityType[0] = 2;
the26bitFormat.parityType[1] = 1;
the26bitFormat.parityType[2] = 0;
the26bitFormat.parityType[3] = 0;

the26bitFormat.parityFields[28] = 1;
the26bitFormat.parityFields[29] = 255;
the26bitFormat.parityFields[30] = 224;
the26bitFormat.parityFields[62] = 31;
the26bitFormat.parityFields[63] = 254;

the26bitFormat.idFields[28] = 1;
the26bitFormat.idFields[29] = 254;
the26bitFormat.idFields[61] = 1;
the26bitFormat.idFields[62] = 255;
the26bitFormat.idFields[63] = 254;

Marshal.StructureToPtr(the26bitFormat, the26bitformatPtr, false);

// Corporate 1000
IntPtr theCorp1000FormatPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(BS2WiegandFormat)));
BS2WiegandFormat theCorp1000Format = new BS2WiegandFormat();
theCorp1000Format.idFields = new byte[128];
theCorp1000Format.parityFields = new byte[128];
theCorp1000Format.parityType = new byte[4];
theCorp1000Format.parityPos = new byte[4];

theCorp1000Format.length = 35;

theCorp1000Format.parityPos[0] = 1;
theCorp1000Format.parityPos[0] = 1;
theCorp1000Format.parityPos[1] = 34;

theCorp1000Format.parityType[0] = 2;
theCorp1000Format.parityType[1] = 1;
theCorp1000Format.parityType[2] = 1;

theCorp1000Format.parityFields[27] = 1;
theCorp1000Format.parityFields[28] = 182;
theCorp1000Format.parityFields[29] = 219;
theCorp1000Format.parityFields[30] = 109;
theCorp1000Format.parityFields[31] = 182;
theCorp1000Format.parityFields[59] = 3;
theCorp1000Format.parityFields[60] = 109;
theCorp1000Format.parityFields[61] = 182;
theCorp1000Format.parityFields[62] = 219;
theCorp1000Format.parityFields[63] = 108;
theCorp1000Format.parityFields[91] = 3;
theCorp1000Format.parityFields[92] = 255;
theCorp1000Format.parityFields[93] = 255;
theCorp1000Format.parityFields[94] = 255;
theCorp1000Format.parityFields[95] = 255;

theCorp1000Format.idFields[27] = 1;
theCorp1000Format.idFields[28] = 255;
theCorp1000Format.idFields[29] = 224;
theCorp1000Format.idFields[61] = 31;
theCorp1000Format.idFields[62] = 255;
theCorp1000Format.idFields[63] = 254;

Marshal.StructureToPtr(theCorp1000Format, theCorp1000FormatPtr, false);
Marshal.Copy(the26bitformatPtr, wiegandMultiConfig.formats[0].format, 0,
             Marshal.SizeOf(typeof(BS2WiegandFormat)));
Marshal.Copy(theCorp1000FormatPtr, wiegandMultiConfig.formats[3].format, 0, 
             Marshal.SizeOf(typeof(BS2WiegandFormat)));
Marshal.FreeHGlobal(the26bitformatPtr);
Marshal.FreeHGlobal(theCorp1000FormatPtr);

result = API.BS2_SetWiegandMultiConfig(sdkContext, deviceId, ref wiegandMultiConfig);
if (result != (int)BS2ErrorCode.BS_SDK_SUCCESS)
{
    Console.WriteLine("BS2_SetWiegandMultiConfig failed: " + result);
    API.BS2_DisconnectDevice(sdkContext, deviceId);
    API.BS2_ReleaseContext(sdkContext);
    return;
}

BS2WiegandConfig wiegandConfig;
result = API.BS2_GetWiegandConfig(sdkContext, deviceId, out wiegandConfig);
if (result != (int)BS2ErrorCode.BS_SDK_SUCCESS)
{
    Console.WriteLine("BS2_GetWiegandConfig failed: " + result);
    API.BS2_DisconnectDevice(sdkContext, deviceId);
    API.BS2_ReleaseContext(sdkContext);
    return;
}
wiegandConfig.wiegandCardMask = 18; // Use the first and fourth Wiegand formats only 
                                    // (0x0000000000010010)

result = API.BS2_SetWiegandConfig(sdkContext, deviceId, ref wiegandConfig);
if (result != (int)BS2ErrorCode.BS_SDK_SUCCESS)
{
    Console.WriteLine("BS2_SetWiegandConfig failed: " + result);
    API.BS2_DisconnectDevice(sdkContext, deviceId);
    API.BS2_ReleaseContext(sdkContext);
    return;
}
```
