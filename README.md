# BioStar Device SDK Docs

BioStar Device SDK의 API 레퍼런스 문서를 Doxygen으로 빌드하는 프로젝트입니다.  
영어(`output/{root}`)와 한국어(`output/ko/`) 두 가지 언어를 지원합니다.

---

## 사전 요구사항

| 도구 | 버전 | 설치 |
| ---- | ---- | ---- |
| [Node.js](https://nodejs.org/) | 20 이상 | nodejs.org |
| [xpm](https://xpack.github.io/xpm/) | 0.17.0 이상 | `npm install -g xpm` |
| [Doxygen](https://www.doxygen.nl/) | 1.17.0 | doxygen.nl |

---

## 설치

```bash
# 1. 저장소 클론
git clone https://github.com/supremainc/deviceSDK_sample.git
cd deviceSDK_sample

# 2. xpm 전역 설치 (최초 1회)
npm install -g xpm

# 3. xpack 의존성 설치 (doxygen-awesome-css, build-helper)
xpm install
```

> `xpm install`은 `xpacks/` 디렉터리에 다음 패키지를 설치합니다.

- `@jothepro/doxygen-awesome-css` — Doxygen 테마
- `@micro-os-plus/build-helper` — 빌드 헬퍼

---

## 빌드

```bash
node build_docs.js
```

또는

```bash
npm run build
```

빌드 순서:

1. `_reference/en/` 릴리즈 노트 파일들을 병합 → `_reference/en/release_notes.md`
2. `_reference/ko/` 릴리즈 노트 파일들을 병합 → `_reference/ko/release_notes.md`
3. `doxygen biostar_device_sdk_en` — 영어 문서 생성
4. `doxygen biostar_device_sdk_ko` — 한국어 문서 생성

---

## 출력 결과

```text
output/
├── index.html          ← 루트 진입점 (영어로 자동 리다이렉트)
├── en/
│   └── index.html      ← 영어 문서
└── ko/
    └── index.html      ← 한국어 문서
```

---

## Doxyfile 구성

| 파일 | 언어 | 출력 경로 |
| --- | --- | --- |
| `biostar_device_sdk_en` | 영어 | `output/` (root) |
| `biostar_device_sdk_ko` | 한국어 | `output/ko/` |

---

## GitHub Actions 자동 빌드

GitHub Actions 워크플로우(`.github/workflows/build_docs.yml`)를 통해 GitHub Pages에 자동 배포할 수 있습니다.

**수동 트리거 방법:**

1. GitHub 저장소 → **Actions** 탭 이동
2. **Build Documentation** 워크플로우 선택
3. **Run workflow** 버튼 클릭

배포 완료 후 GitHub Pages URL에서 문서를 확인할 수 있습니다.
