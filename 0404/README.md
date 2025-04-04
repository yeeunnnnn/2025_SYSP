# 🌐 AI 실무 이해와 생성형 AI 활용 예제

인공지능 기술의 진화와 실무 적용 사례를 소개하고,  
ChatGPT 기반 생성형 AI를 활용한 간단한 프로그래밍 실습을 포함합니다.

---

## 🔎 Overview

| 항목 | 주요 내용 |
|------|----------|
| **AI 진화** | 규칙 기반 → 머신러닝 → 딥러닝 → 생성형 AI |
| **핵심 기술** | LLM (GPT 계열), 자연어 처리, 이미지·음성·영상 생성 |
| **활용 분야** | 문서 작성 자동화, 검색, 상담, 콘텐츠 제작 등 |
| **도구 예시** | ChatGPT, DALL·E, Midjourney, Perplexity, Runway, ElevenLabs 등 |

---

## 🧠 AI 키워드 정리

### 1. LLM과 생성형 AI
- GPT 계열 LLM 구조 및 작동 원리
- 문서 생성, 상담, 요약, 코드 작성 등 폭넓은 활용
- 대표 기업: OpenAI, Google, Anthropic 등

### 2. 챗봇 비교 및 활용
- ChatGPT Plus vs Claude, Perplexity 등
- 실무 예시: 고객 대응, 문서 자동화, 일정 관리

### 3. 생성형 AI 도구 활용
- **문서 작성**: 이메일, 제안서, PPT 자동 생성
- **검색**: GPT 기반 지식 탐색 (Open/Closed Book)
- **시각화**: 엑셀 데이터 → 차트, 문서 → 슬라이드 자동화
- **이미지/영상/오디오**: 텍스트로 창작물 생성

---

## 🛠 실습 예제: C 언어로 AI 논리 구현

### 🎯 목표
입력된 숫자(0~255)에 대해:
1. 8비트 이진수로 출력  
2. 1의 개수 출력  
3. 상위 4비트 출력

### 💻 코드

```c
#include <stdio.h>

int countOnes(unsigned char n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void printBinary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    int input;

    printf("0~255 사이의 정수를 입력하세요: ");
    scanf("%d", &input);

    if (input < 0 || input > 255) {
        printf("입력값이 범위를 벗어났습니다.\n");
        return 1;
    }

    unsigned char number = (unsigned char)input;

    printf("2진수: ");
    printBinary(number);
    printf("\n");

    printf("1의 개수: %d개\n", countOnes(number));

    printf("상위 4비트: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (number >> 4 >> i) & 1);
    }
    printf("\n");

    return 0;
}
