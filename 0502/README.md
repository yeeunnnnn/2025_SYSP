# 📘 컴퓨터 시스템 구조 – 유닉스 커널 & 시스템 호출 요약

## 🔧 유닉스 커널(Kernel)이란?

커널은 하드웨어를 운영하고 자원을 관리하는 **운영체제의 핵심**입니다.  
다음과 같은 서비스를 제공합니다:

- 📁 **파일 관리 (File Management)**
- 🔄 **프로세스 관리 (Process Management)**
- 🧠 **메모리 관리 (Memory Management)**
- 🧵 **통신 관리 (Communication Management)**
- 🖨️ **주변장치 관리 (Device Management)**

---

## 🧩 시스템 호출(System Call)이란?

- 사용자 프로그램이 **커널에 서비스 요청**을 보내는 인터페이스
- 응용 프로그램은 시스템 호출을 통해 **커널 기능**(입출력, 프로세스 생성 등)을 사용

---

## 📜 시스템 호출 요약

| 주요 자원         | 시스템 호출 예시 |
|------------------|-------------------|
| 📁 파일           | `open()`, `close()`, `read()`, `write()`, `dup()`, `lseek()` |
| 🔄 프로세스       | `fork()`, `exec()`, `exit()`, `wait()`, `getpid()`, `getppid()` |
| 🧠 메모리 관리     | `malloc()`, `calloc()`, `free()` *(libc 함수)* |
| 🔔 시그널 처리     | `signal()`, `alarm()`, `kill()`, `sleep()` |
| 🧵 프로세스 간 통신 | `pipe()`, `socket()` 등 |

---

## 📁 유닉스에서의 파일

- 유닉스에서 파일은 **연속된 바이트의 나열**이며,
- 별도의 포맷 없이 데이터를 저장
- **디스크 파일**뿐 아니라 **장치**도 파일처럼 다룸

---

## 📂 파일 관련 주요 시스템 호출

### 1. `open()` – 파일 열기

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *path, int oflag [, mode_t mode]);
