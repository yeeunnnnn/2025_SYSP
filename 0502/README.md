# System Programming 07

## 목차
1. 컴퓨터 시스템 구조  
2. 시스템 호출

---

## ① 컴퓨터 시스템 구조

### 유닉스 커널 (Kernel)

커널은 **하드웨어를 운영 관리**하여 다음과 같은 **서비스**를 제공합니다:

- 파일 관리 (File management)
- 프로세스 관리 (Process management)
- 메모리 관리 (Memory management)
- 통신 관리 (Communication management)
- 주변장치 관리 (Device management)

> ![kernel 구조 이미지](image)

---

## ② 시스템 호출 (System Call)

### 시스템 호출이란?

- 커널에 서비스 요청을 하기 위한 **프로그래밍 인터페이스**
- 응용 프로그램은 시스템 호출을 통해 **커널에 요청**

> ![시스템 호출 흐름 이미지](image)

---

### 시스템 호출 요약

| 주요 자원         | 시스템 호출 예시                                      |
|------------------|------------------------------------------------------|
| 파일             | `open()`, `close()`, `read()`, `write()`, `dup()`, `lseek()` |
| 프로세스         | `fork()`, `exec()`, `exit()`, `wait()`, `getpid()`, `getppid()` |
| 메모리           | `malloc()`, `calloc()`, `free()` (*라이브러리 함수지만 시스템 자원 활용*) |
| 시그널           | `signal()`, `alarm()`, `kill()`, `sleep()`            |
| 프로세스 간 통신 | `pipe()`, `socket()`                                  |

---

## 유닉스에서 파일

- **연속된 바이트의 나열**
- 특별한 포맷 없음 (바이너리/텍스트 구분 없음)
- **디스크 파일뿐 아니라 외부 장치 인터페이스** 역할도 가능

---

## 주요 시스템 호출

### 🔹 `open()` - 파일 열기

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *path, int oflag, [mode_t mode]);
