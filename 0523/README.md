# ⚙️ 프로세스 관리 및 동기화 (Process Management in C)

---

## 🔄 프로세스 생성 - `fork()`

### 📌 `fork()` 시스템 호출
- 기능: 부모 프로세스가 **자기 자신을 복제**하여 **자식 프로세스**를 생성
- 반환값:
  - **부모 프로세스**: 생성된 자식의 **PID**
  - **자식 프로세스**: **0**
- 특징:  
  🧠 “**한 번 호출, 두 번 리턴**”되는 함수

---

## ⏳ 프로세스 동기화

| 함수 | 설명 |
|------|------|
| `wait()` | 자식 프로세스가 종료될 때까지 부모가 대기 |
| `waitpid(pid, ...)` | 특정 자식 프로세스만 기다림 |

---

## 🧪 실습 예제

### 🔧 예제 1: `fork1.c` – 자식 생성 후 PID 출력

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    printf("[%d] 프로세스 시작 \n", getpid());
    pid = fork();
    printf("[%d] 프로세스 : 리턴값 %d\n", getpid(), pid);
    printf("[%d] 프로세스 : 리턴값 %d\n", getpid(), pid);
    printf("[%d] 프로세스 : 리턴값 %d\n", getpid(), pid);
}
```

---

### 🔧 예제 2: `fork2.c` – 부모/자식의 메시지 구분 출력

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("[Child] : Hello, world pid=%d\n", getpid());
    } else {
        printf("[Parent] : Hello, world pid=%d\n", getpid());
    }
}
```

---

### 🔧 예제 3: `fork3.c` – 두 자식 프로세스 생성

```c
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        printf("[Child 1] : Hello, world ! pid=%d\n", getpid());
        exit(0);
    }
    pid2 = fork();
    if (pid2 == 0) {
        printf("[Child 2] : Hello, world ! pid=%d\n", getpid());
        exit(0);
    }
    printf("[PARENT] : Hello, world ! pid=%d\n", getpid());
}
```

---

### 🔧 예제 4: `forkwait.c` – 자식 프로세스 종료까지 대기

```c
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, child, status;
    printf("[%d] 부모 프로세스 시작 \n", getpid());

    pid = fork();

    if (pid == 0) {
        printf("[%d] 자식 프로세스 시작 \n", getpid());
        exit(1);  // 종료 코드 1
    }

    child = wait(&status);

    printf("[%d] 자식 프로세스 %d 종료 \n", getpid(), child);
    printf("\t종료 코드 %d\n", WEXITSTATUS(status));
    return 0;
}
```

---

### 🔧 예제 5: `waitpid.c` – 특정 자식 프로세스를 순차적으로 기다림

```c
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid1, pid2, child, status;

    printf("[%d] 부모 프로세스 시작 \n", getpid());

    pid1 = fork();
    if (pid1 == 0) {
        printf("[%d] 자식 프로세스[1] 시작 \n", getpid());
        sleep(1);
        printf("[%d] 자식 프로세스[1] 종료 \n", getpid());
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("[%d] 자식 프로세스[2] 시작 \n", getpid());
        sleep(2);
        printf("[%d] 자식 프로세스[2] 종료 \n", getpid());
        exit(2);
    }

    child = waitpid(pid1, &status, 0);
    printf("[%d] 자식 프로세스 #1 %d 종료 \n", getpid(), child);
    printf("\t종료 코드 %d\n", WEXITSTATUS(status));

    child = waitpid(pid2, &status, 0);
    printf("[%d] 자식 프로세스 #2 %d 종료 \n", getpid(), child);
    printf("\t종료 코드 %d\n", WEXITSTATUS(status));

    return 0;
}
```

---

> 🧠 **요약**
> - `fork()`를 통해 간단하게 **병렬 구조**를 만들 수 있습니다.
> - `wait()`와 `waitpid()`를 이용하면 **동기적 제어**가 가능합니다.
> - 실습을 통해 **프로세스의 생성, 실행, 종료** 흐름을 정확히 파악할 수 있습니다.
