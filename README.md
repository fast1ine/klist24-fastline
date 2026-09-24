# klist24-fastline

2024 경기고등학교 화동제(축제) LIST 동아리 프로젝트에 사용된 아두이노 코드 모음 중 fastline 기여분입니다.

## 파일

- `dpad_example_kglist/` — ADKeyboard D-패드 예제 코드
- `led_random_kglist/` — 10초 카운터용 LED 코드
- `step_motor-uln2003_kglist/` — 미니카 레이싱 스텝 모터(ULN2003) 코드
- `oldversion_fps_source_dpad_included_kglist/` — [구버전] 자이로 슈팅 총기 하드웨어 코드에 D-패드 코드를 병합한 버전 (동작 불완전, 사용 주의)

## 출처 및 라이선스 (Credits and license)

- **저작 / Authorship**: `oldversion_fps_source_dpad_included_kglist.ino`는 동아리 선배와 **공동 개발**한 파일입니다(각 파일 헤더의 `Developer` 표기 참조). 그 외 모든 파일은 **본인이 단독으로 작성**했습니다.
- **참조 자료 / References**: ADKeyboard D-패드의 아날로그 버튼 임계값(`adc_key_val = {30, 150, 360, 535, 760}`)은 판매처 제공 데이터시트를 참조했습니다.
  - Devicemart ADKeyboard 데이터시트: <https://www.devicemart.co.kr/goods/download?id=1064936&rank=1>
- **라이선스 / License**: 학습·동아리 목적으로 공개합니다. 본인이 단독 작성한 파일은 출처를 표기하면 자유롭게 사용할 수 있습니다. 공동 저작물(`oldversion_fps_source_dpad_included_kglist.ino`)의 이용은 공동 저작자의 권리를 함께 따릅니다.
