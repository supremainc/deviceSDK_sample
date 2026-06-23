# BS_OpenSocket

Opens a TCP socket with the specified IP address and port number. With FaceStation, BioStation T2, D-Station, BioStation, BioLite Net and X-Station, you can find out this information in the LCD menu of the device. With BioEntry Plus, BioEntry W, Xpass and Xpass Slim, Xpass S2, you have to search the device first by `BS_SearchDevicesInLAN.Initializes` the SDK. This function should be called once before any other functions are executed.

#### 지원 모델

FaceStation, BioStation T2, D-Station, BioStation, BioEntry Plus, BioEntry W, BioLite Net, X-Station, Xpass, Xpass Slim, Xpass S2

### 코드

![Java,bs_opensocket_cp\|C++,bs_opensocket_cs\|C#](tabinclude>*bs_opensocket_java)

### 매개 변수

  ----------------------------------------------------------------------------------------

| 이름 | 설명 |
| --- | --- |
| *ipAddr* | 장치의 IP 주소. |

  *port*     TCP 포트 번호. 기본값은 1470, 1471 입니다.

             - 1470: FaceStation, BioStation T2, D-Station, BioStation, X-Station

             - 1471: BioEntry Plus, BioEntry W, BioLite Net, Xpass, Xpass Slim, Xpass S2

  *handle*   Pointer to the handle to be assigned.

  ----------------------------------------------------------------------------------------

### 응답 코드

If the function succeeds, return `BS_SUCCESS`. Otherwise, return the corresponding error code.
