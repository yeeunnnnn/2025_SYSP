# 📁 파일 입출력 고급 기법 (Advanced File I/O in C)

---

## 📝 파일 복사 프로그램 (`copy.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
   int fd1, fd2, n;
   char buf[BUFSIZ];

   if (argc != 3) {
       fprintf(stderr,"사용법: %s file1 file2\n", argv[0]);
       exit(1);
   }

   if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
       perror(argv[1]);
       exit(2);
   }

   if ((fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)) == -1) {
       perror(argv[2]);
       exit(3);
   }

   while ((n = read(fd1, buf, BUFSIZ)) > 0)
       write(fd2, buf, n);

   exit(0);
}
```

---

## 🔁 파일 디스크립터 복제 (`dup`, `dup2`)

```c
#include <unistd.h>

int dup(int oldfd);             // 새 파일 디스크립터 자동 할당
int dup2(int oldfd, int newfd); // 지정된 파일 디스크립터로 복제
```

- **`oldfd`와 `newfd`는 동일한 파일 테이블 엔트리를 공유**
- 동일한 오프셋과 파일 상태 플래그를 가짐

### 📌 예시: `dup.c`

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;

    if((fd1 = creat("myfile", 0600)) == -1)
        perror("myfile");

    write(fd1, "Hello! Linux", 12);
    fd2 = dup(fd1);
    write(fd2, "Bye! Linux", 10);

    exit(0);
}
```

📄 결과:
```
Hello! LinuxBye! Linux
```

---

## 🎯 파일 위치 포인터 (File Position Pointer)

- 읽기/쓰기 위치를 관리하는 커널 내부 오프셋
- 파일 디스크립터별로 존재

### 🧭 `lseek()` 시스템 호출

```c
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
```

| `whence` 값 | 설명 |
|-------------|------|
| `SEEK_SET` | 파일 시작 기준 |
| `SEEK_CUR` | 현재 위치 기준 |
| `SEEK_END` | 파일 끝 기준 |

### 🔧 예시

```c
lseek(fd, 0L, SEEK_SET);          // 파일 시작으로 이동
lseek(fd, 100L, SEEK_SET);        // 100바이트 위치로
lseek(fd, sizeof(record), SEEK_CUR);  // 다음 레코드로 이동
lseek(fd, -sizeof(record), SEEK_CUR); // 이전 레코드로 이동
```

---

## 💾 실습: 학생 정보 데이터베이스 시스템

### 📌 헤더 정의 (`student.h`)

```c
#define MAX 24
#define START_ID 1401001

struct student {
    char name[MAX];
    int id;
    int score;
};
```

---

### 📦 데이터베이스 생성 (`dbcreate.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
    int fd;
    struct student record;

    if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("%-9s %-8s %-4s\n", "학번", "이름", "점수");
    while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3) {
        lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
        write(fd, (char *) &record, sizeof(record));
    }

    close(fd);
    exit(0);
}
```

---

### 🔍 데이터베이스 조회 (`dbquery.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
    int fd, id;
    char c;
    struct student record;

    if (argc < 2) {
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("\n검색할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
                printf("이름:%s\t 학번:%d\t 점수:%d\n", record.name, record.id, record.score);
            else 
                printf("레코드 %d 없음\n", id);
        }
        printf("계속하겠습니까?(Y/N): ");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}
```

---

### ✏️ 데이터베이스 수정 (`dbupdate.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;

    if (argc < 2) {
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
                printf("학번:%8d\t 이름:%4s\t 점수:%4d\n",
                record.id, record.name, record.score);
                printf("새로운 점수: ");
                scanf("%d", &record.score);
                lseek(fd, (long) -sizeof(record), SEEK_CUR);
                write(fd, (char *) &record, sizeof(record));
            } else printf("레코드 %d 없음\n", id);
        } else printf("입력오류\n");
        printf("계속하겠습니까?(Y/N): ");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}
```

---

> 📚 **요약**
> - 파일 디스크립터는 고급 입출력의 핵심 도구입니다.
> - `dup`, `lseek`을 이용하면 입출력 제어 및 위치 이동이 가능합니다.
> - 구조체 기반 데이터베이스 처리에서는 레코드 단위 접근이 효율적입니다.

