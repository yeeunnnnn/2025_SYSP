# 🌟 UNIX 명령어 및 C 언어 입출력 실습 🌟

## 🖥️ UNIX 명령어 정리

### 📂 파일 및 디렉토리 조작 명령어

- **cp**: 파일 또는 디렉토리를 복사하는 명령어입니다.  
  - 예: `cp source.txt destination.txt`
- **mv**: 파일 또는 디렉토리를 이동하거나 이름을 변경하는 명령어입니다.  
  - 예: `mv oldname.txt newname.txt`

### 🔗 링크 관련 명령어

- **링크(Link)**: 파일을 참조하는 방식으로, 하드 링크와 심볼릭 링크가 있습니다.
- **하드링크(Hard Link)**: 원본 파일과 동일한 inode를 가지며, 파일이 삭제되어도 유지됩니다.  
  - 예: `ln original.txt hardlink.txt`
- **심볼릭링크(Symbolic Link, Soft Link)**: 원본 파일의 경로를 참조하는 링크로, 원본이 삭제되면 링크가 깨집니다.  
  - 예: `ln -s original.txt symlink.txt`

### 🏷️ 파일 속성과 종류

- **파일속성(File Attributes)**: 파일의 크기, 소유자, 권한, 수정 날짜 등의 정보를 포함합니다.
- **파일종류(File Type)**: 
  - 일반 파일 (`-`)
  - 디렉토리 (`d`)
  - 심볼릭 링크 (`l`)
  - 문자 장치 (`c`)
  - 블록 장치 (`b`)
  - 소켓 (`s`)
  - FIFO (`p`)
- **file 명령어**: 파일의 타입을 확인하는 명령어입니다.  
  - 예: `file example.txt`

### 🔐 파일 접근 권한

- **접근권한(Permissions)**: 파일 및 디렉토리에 대한 읽기(r), 쓰기(w), 실행(x) 권한을 설정하는 기능입니다.
- **chmod**: 파일의 권한을 변경하는 명령어입니다.  
  - 기호 방식: `chmod u+rwx file.txt` (소유자에게 읽기, 쓰기, 실행 권한 부여)
  - 8진수 방식: `chmod 755 file.txt` (소유자=7, 그룹=5, 기타=5)
- **8진수(Octal) 방식**: 
  - `r (4)`, `w (2)`, `x (1)`을 조합하여 8진수로 표현합니다.
  - 예: `chmod 644 file.txt` (소유자 읽기/쓰기, 그룹 및 기타 읽기)
- **기호(Symbolic) 방식**:
  - `u` (사용자), `g` (그룹), `o` (기타), `a` (전체)
  - 예: `chmod u+x script.sh` (소유자에게 실행 권한 추가)

---

## 🎯 C 언어 입출력 실습

### ✨ 1️⃣ 학번과 이름 입력 프로그램

```c
#include <stdio.h>

int main() {
    char name[50];
    int student_id;

    printf("학번을 입력하세요: ");
    scanf("%d", &student_id);

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("\n[입력 정보]\n");
    printf("학번: %d\n", student_id);
    printf("이름: %s\n", name);

    return 0;
}
```

### 🚀 실행 방법

1. 코드 작성 후 파일 저장 (예: `input_test.c`)
2. 터미널에서 컴파일 수행:
   ```sh
   gcc input_test.c -o input_test
   ```
3. 실행:
   ```sh
   ./input_test
   ```
4. 학번과 이름을 입력하면 입력값이 출력됩니다.

---

### 🔄 2️⃣ 영문자 대소문자 변환 프로그램

```c
#include <stdio.h>

int main() {
    char ch;

    while (1) {
        printf("문자 입력 : ");
        scanf(" %c", &ch);

        if (ch == '0') {
            break;
        }

        if (ch >= 'A' && ch <= 'Z') {
            printf("%c의 소문자는 %c입니다.\n", ch, ch + 32);
        }
        else if (ch >= 'a' && ch <= 'z') {
            printf("%c의 대문자는 %c입니다.\n", ch, ch - 32);
        }
        else {
            printf("영문자만 입력해주세요.\n");
        }
    }

    return 0;
}
```

### 🚀 실행 방법

1. 코드 작성 후 파일 저장 (예: `char_case_converter.c`)
2. 터미널에서 컴파일 수행:
   ```sh
   gcc char_case_converter.c -o char_case_converter
   ```
3. 실행:
   ```sh
   ./char_case_converter
   ```
4. 문자 입력 후 대소문자로 변환된 결과를 확인합니다. (종료하려면 `0` 입력)
