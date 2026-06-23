# Doxygen 문서화 가이드

BioStar Device SDK 문서화 담당자를 위한 Doxygen 작업 안내서입니다.

---

## 1. 도입 배경

### 기존 DokuWiki 방식의 한계

BioStar Device SDK 문서는 기존에 [DokuWiki](https://kb.supremainc.com/bs2sdk/doku.php)로 관리되었습니다.
DokuWiki는 별도 위키 사이트로 운영되기 때문에 다음 문제가 반복적으로 발생했습니다.

- **코드-문서 불일치**: SDK 함수 시그니처가 변경되어도 위키 문서가 자동으로 반영되지 않음
- **이중 관리 부담**: 코드 수정 시 개발자가 위키도 별도로 수동 업데이트해야 함
- **버전 추적 어려움**: 코드 이력(git)과 문서 이력이 분리되어 특정 버전의 문서 상태 확인이 어려움

### Doxygen 도입 이유

Doxygen은 소스 코드의 주석을 파싱하여 HTML 문서를 자동 생성합니다.
코드와 문서가 같은 저장소에서 함께 관리되므로 위의 문제를 구조적으로 해소할 수 있습니다.

- 코드 수정과 문서 수정이 단일 커밋으로 묶임
- CI/CD 파이프라인에 빌드 단계를 추가해 자동 배포 가능
- 영어/한국어 다국어 문서를 단일 소스로 관리

---

## 2. Doxygen 개요

### Doxygen이란?

Doxygen은 C, C++, Java, Python 등 다양한 언어의 소스 코드에서 주석을 추출해 HTML, PDF, XML 형식의 문서를 생성하는 도구입니다.

주요 동작 방식:

1. `/** ... */` 형식의 javadoc 스타일 주석을 파싱
2. `@brief`, `@param`, `@return` 등의 태그로 구조화
3. Doxyfile(설정 파일)에 따라 지정된 출력 경로에 HTML 생성

이 가이드를 통해 만들어지는 결과물의 샘플은 아래에서 확인할 수 있습니다.

- [BioStar Device SDK 샘플 문서](https://supremainc.github.io/deviceSDK_sample/index.html)

### 프로젝트 문서 구조 개요

```
BioStarDeviceSDK/
├── Include/                  ← SDK 헤더 파일 (문서화 대상)
│   ├── BS_API.h              ← 메인 API 함수 선언 (~400개 함수)
│   ├── BS_Errno.h            ← 에러 코드 정의
│   └── BSCommon/             ← 공통 타입 및 구조체
├── _reference/
│   ├── en/                   ← 영어 마크다운 레퍼런스 (517개)
│   └── ko/                   ← 한국어 마크다운 레퍼런스 (516개)
├── docs/
│   ├── groups.dox            ← 영어 그룹(@defgroup) 정의
│   ├── groups_ko.dox         ← 한국어 그룹 정의
│   ├── return_code.dox       ← 에러 코드 문서
│   ├── release_notes.dox     ← 릴리스 노트
│   └── lang_switch.js        ← 언어 전환 버튼 스크립트
├── biostar_device_sdk_en     ← 영어 Doxyfile
└── biostar_device_sdk_ko     ← 한국어 Doxyfile
```

`_reference` 경로의 마크다운 파일은 별도의 스크립트를 통해 DokuWiki의 문서를 자동으로 내려받아 마크다운으로 변환합니다.

---

## 3. 환경 설정

### Doxygen 설치

**Windows**

[Doxygen 공식 다운로드 페이지](https://www.doxygen.nl/download.html)에서 Windows 설치 파일을 받아 설치합니다.

설치 후 환경 변수 PATH에 Doxygen 실행 파일 경로를 추가합니다 (기본값: `C:\Program Files\doxygen\bin`).

```powershell
# 설치 확인
doxygen --version
```

**macOS**

```bash
brew install doxygen
```

**Ubuntu/Debian**

```bash
sudo apt-get install doxygen
```

### Doxyfile 구성

프로젝트 루트에 영어(`biostar_device_sdk_en`)와 한국어(`biostar_device_sdk_ko`) Doxyfile이 각각 존재합니다.
두 파일의 주요 차이점은 아래와 같습니다.

| 설정 항목 | 영어 (`biostar_device_sdk_en`) | 한국어 (`biostar_device_sdk_ko`) |
|---|---|---|
| `OUTPUT_LANGUAGE` | `English` | `Korean` |
| `OUTPUT_DIRECTORY` | `.` | `output` |
| `HTML_OUTPUT` | `output` | `ko` |
| `EXAMPLE_PATH` | `_reference/en` | `_reference/ko` |

> **주의**: `EXAMPLE_PATH`는 `@include{doc}` 명령이 마크다운 파일을 탐색하는 기준 경로입니다.
> 이 값 하나만 바꾸면 함수별 상세 설명 전체가 해당 언어로 전환됩니다.

---

## 4. 주석 작성 규칙

### 함수 주석 형식

`BS_API.h`에 함수를 문서화할 때는 아래 형식을 사용합니다.

```cpp
/**
 * \~english
 * @brief Returns the SDK version string.
 * @param[in] context SDK context handle.
 * @return Null-terminated string representing the SDK version.
 * \~korean
 * @brief SDK 버전 문자열을 반환합니다.
 * @param[in] context SDK 컨텍스트 핸들.
 * @return 버전 문자열을 반환합니다.
 * \~
 * @ingroup group_sdk_api
 * @include{doc} bs2_version.md
 */
BS2_API const char* BS2_Version(void* context);
```

### 다국어 처리 (`\~` 언어 전환 명령)

Doxygen의 `\~` 명령은 언어별 빌드에서 특정 내용만 출력하도록 제어합니다.

| 명령 | 역할 |
|---|---|
| `\~english` | 이후 내용을 영어 빌드에서만 표시 |
| `\~korean` | 이후 내용을 한국어 빌드에서만 표시 |
| `\~` | 언어 제한 해제. 이후 내용은 모든 언어에 공통 적용 |

> **핵심 규칙**: `@ingroup`과 `@include{doc}`는 반드시 `\~`(공통 영역) 이후에 작성합니다.
> 언어 블록 안에 넣으면 해당 언어 빌드에서만 동작하여 그룹 분류가 깨집니다.

### 구조체 / enum 문서화

멤버 변수는 `///<` 인라인 주석을 사용합니다.

```cpp
typedef struct {
    uint32_t deviceId;   ///< 디바이스 고유 식별자
    uint8_t  type;       ///< 디바이스 타입 (BS2_DEVICE_TYPE 참조)
    uint8_t  connectionMode; ///< 연결 모드 (0: TCP/IP, 1: RS-485)
} BS2SimpleDeviceInfo;
```

enum의 경우:

```cpp
typedef enum {
    BS2_DEVICE_TYPE_BIOENTRY_W2   = 0x1001, ///< BioEntry W2
    BS2_DEVICE_TYPE_BIOSTATION_L2 = 0x1002, ///< BioStation L2
} BS2_DEVICE_TYPE;
```

### 공통 반환값 처리 (`ALIASES`)

대부분의 함수가 동일한 `@return` 문구를 사용하는 경우, Doxyfile의 `ALIASES`에 단축 명령을 정의하면 반복 작성을 없앨 수 있습니다.

**Doxyfile 설정** (영어/한국어 양쪽 모두 추가):

```ini
ALIASES += sdkreturn="\~english @return If successfully done, `BS_SDK_SUCCESS` will be returned. If there is an error, the corresponding error code will be returned. \~korean @return 성공적으로 수행될 경우 `BS_SDK_SUCCESS`를 반환하고, 에러가 발생할 경우 상응하는 에러 코드를 반환합니다. \~"
```

**함수 주석에서 사용**:

```cpp
/**
 * \~english
 * @brief Connects the device.
 * @param[in] context SDK context handle.
 * @param[in] deviceId Device identifier.
 * \~korean
 * @brief 디바이스에 연결합니다.
 * @param[in] context SDK 컨텍스트 핸들.
 * @param[in] deviceId 디바이스 식별자.
 * \sdkreturn
 * @ingroup group_communication_api
 */
```

> `ALIASES` 값을 수정하면 해당 alias를 사용하는 모든 함수의 반환값 설명이 일괄 변경됩니다.
> 포인터 반환이나 특정 값을 반환하는 함수처럼 공통 문구가 맞지 않는 경우에는 `@return`을 직접 작성합니다.

### 그룹 태그

그룹 정의는 `docs/groups.dox`(영어), `docs/groups_ko.dox`(한국어) 파일에서 관리합니다.
헤더 파일에서는 `@ingroup`으로 소속만 선언합니다.

**그룹 정의** (`docs/groups.dox`):

```cpp
/**
 * @defgroup group_sdk_api SDK API
 * @brief APIs that initialize device management and control memory and PIN.
 *
 * @include{doc} sdk_api.md
 */
```

**함수를 그룹에 소속** (`BS_API.h`):

```cpp
/**
 * ...
 * \~
 * @ingroup group_sdk_api
 */
BS2_API const char* BS2_Version(void* context);
```

**여러 함수를 블록으로 묶기**:

```cpp
/// @addtogroup group_sdk_api
/// @{

BS2_API void* BS2_AllocateContext();
BS2_API void  BS2_ReleaseContext(void* context);

/// @}
```

---

## 5. 레퍼런스 파일 연동

### `_reference` 디렉토리 구조

`_reference` 디렉토리에는 DokuWiki에서 마크다운으로 변환된 함수별 상세 설명 파일이 저장되어 있습니다.

```
_reference/
├── en/                     ← 영어 마크다운 (517개)
│   ├── bs2_version.md
│   ├── bs2_allocatecontext.md
│   └── ...
└── ko/                     ← 한국어 마크다운 (516개)
    ├── bs2_version.md
    ├── bs2_allocatecontext.md
    └── ...
```

영어와 한국어 디렉토리의 **파일명이 동일**하게 유지되어야 `EXAMPLE_PATH` 스위칭이 정상 동작합니다.

### `@include{doc}`으로 마크다운 삽입

함수 주석의 공통 영역(`\~` 이후)에서 `@include{doc}` 명령으로 외부 마크다운 파일을 본문에 삽입합니다.

```cpp
/**
 * \~english
 * @brief Allocates the device management context.
 * \~korean
 * @brief 디바이스 관리 컨텍스트를 할당합니다.
 * \~
 * @ingroup group_sdk_api
 * @include{doc} bs2_allocatecontext.md
 */
BS2_API void* BS2_AllocateContext();
```

Doxygen은 `EXAMPLE_PATH`에 지정된 경로에서 `bs2_allocatecontext.md`를 탐색합니다.

### `EXAMPLE_PATH` 스위칭 전략

Doxyfile의 `EXAMPLE_PATH` 한 줄만 변경하면 전체 함수 상세 설명이 해당 언어로 전환됩니다.

```ini
# 영어 Doxyfile (biostar_device_sdk_en)
EXAMPLE_PATH = _reference/en

# 한국어 Doxyfile (biostar_device_sdk_ko)
EXAMPLE_PATH = _reference/ko
```

코드(`@include{doc}` 명령)는 수정할 필요 없이, Doxyfile 설정만으로 언어가 전환됩니다.

---

## 6. 문서 빌드

### 영어 문서 빌드

```powershell
doxygen biostar_device_sdk_en
```

출력 경로: `output/` (프로젝트 루트 기준)

### 한국어 문서 빌드

```powershell
doxygen biostar_device_sdk_ko
```

출력 경로: `output/ko/`

### 출력 폴더 구조

빌드 후 생성되는 폴더 구조입니다.

```
output/
├── index.html              ← 영어 메인 페이지
├── group__sdk__api.html
├── group__communication__api.html
├── ...
└── ko/                     ← 한국어 서브디렉토리
    ├── index.html
    ├── group__sdk__api.html
    └── ...
```

영어와 한국어 페이지는 같은 파일명을 사용하며, 경로(`/ko/` 유무)로 구분됩니다.

---

## 7. 언어 전환 버튼

### `lang_switch.js` 동작 원리

`docs/lang_switch.js`는 현재 URL의 `/ko/` 포함 여부로 언어를 감지하고, 반대 언어 페이지로 이동하는 버튼을 삽입합니다.

- 영어 페이지(`/output/group__sdk__api.html`) → 버튼 클릭 시 `/output/ko/group__sdk__api.html`로 이동
- 한국어 페이지(`/output/ko/group__sdk__api.html`) → 버튼 클릭 시 `/output/group__sdk__api.html`로 이동

### Doxyfile 등록

두 Doxyfile 모두에 아래 설정을 추가합니다.

```ini
HTML_EXTRA_FILES       = docs/lang_switch.js
HTML_EXTRA_JAVASCRIPT  = lang_switch.js
```

---

## 8. 페이지 구성 및 카테고리

### 주요 페이지

| 페이지 | 소스 | 비고 |
|---|---|---|
| Main Page | `_reference/{lang}/start.md` | SDK 개요 및 시작하기 |
| Quick Guide | `_reference/{lang}/quick_guide.md` | 빠른 시작 가이드 |
| Release Notes | `_reference/{lang}/release_note_*.md` | 최신 순으로 병합 |
| Return Code | `BS_Errno.h` + `_reference/{lang}/return_code.md` | 에러 코드 목록 |

### Topics 그룹 분류

`docs/groups.dox`에 정의된 그룹 목록입니다. 각 그룹은 관련 함수를 `@ingroup`으로 묶어 Topics 메뉴에 카테고리별로 표시합니다.

| 그룹 ID | 표시 이름 |
|---|---|
| `group_sdk_api` | SDK API |
| `group_debugging_api` | Debugging API |
| `group_communication_api` | Communication API |
| `group_ssl_api` | SSL API |
| `group_device_api` | Device API |
| `group_log_api` | Log Management API |
| `group_user_api` | User Management API |
| `group_config_api` | Configuration API |
| `group_smartcard_api` | Smartcard API |
| `group_qr_api` | QR Code API |
| `group_fingerprint_api` | Fingerprint API |
| `group_face_api` | Face API |
| `group_faceex_api` | FaceEx API |
| `group_access_api` | Access Control API |
| `group_blacklist_api` | Blacklist API |
| `group_door_api` | Door Control API |
| `group_lift_api` | Lift Control API |
| `group_slave_api` | Slave Control API |
| `group_wiegand_api` | Wiegand API |
| `group_server_api` | Server API |
| `group_zone_api` | Zone Control API |
| `group_usb_api` | USB Exported Control API |

## 9. 향후 계획

SDK 저장소에서 개발과 문서화를 동시에 진행할 수 있도록 아래 순서로 작업을 진행합니다.

1. **접근 권한 확보**: SDK 개발팀 저장소에 대한 쓰기 권한 요청
2. **문서화 브랜치 생성**: `docs/doxygen` 등 별도 브랜치에서 주석 작성 및 Doxyfile 정비 진행
3. **main 브랜치 병합**: 문서화 작업 리뷰 후 main 브랜치에 반영
4. **CI/CD 자동 배포**: SDK 저장소 파이프라인에 Doxygen 빌드 단계 추가, 변경 사항 push 시 문서 자동 갱신
