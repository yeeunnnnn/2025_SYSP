## 📄 1. Vim 편집기 기초

### 🔹 Vi와 Vim 차이
- `vi`: 유닉스 전통 텍스트 편집기
- `vim`: **Vi IMproved** — vi의 개선판

### 🔹 파일 열기
```bash
vi test
🔹 중단된 프로세스 재시작
bash
Copy
Edit
fg
🧑‍💻 2. Vim 사용법 요약
명령어	설명
i	입력 모드 진입
ESC	명령 모드로 돌아가기
:w	저장만
:q	종료만
:wq	저장 후 종료
:q!	저장 안 하고 강제 종료

⚙️ 3. C 프로그램 작성, 컴파일, 실행
🔹 소스 작성
bash
Copy
Edit
vi hello.c
입력 모드(i) 진입 후 작성:

c
Copy
Edit
#include <stdio.h>

int main() {
  printf("Hello World!!");
  return 0;
}
명령 모드(ESC) 진입 후 저장:

bash
Copy
Edit
:wq
🔹 컴파일 및 실행
bash
Copy
Edit
gcc hello.c -o hello
./hello
🔐 4. 실행 권한 및 파일 속성 확인
🔹 권한 확인
bash
Copy
Edit
ls -l
예시 출력:

diff
Copy
Edit
-rwxr-xr-x 1 yeeunnnnn yeeunnnnn  8544 Apr 11 10:30 hello
-rw-r--r-- 1 yeeunnnnn yeeunnnnn   123 Apr 11 10:20 hello.c
🔹 권한 구조
scss
Copy
Edit
- rwx r-x r-x
│ │   │   └─ 기타 사용자 권한 (others)
│ │   └───── 그룹 권한 (group)
│ └───────── 소유자 권한 (owner)
└─────────── 파일 타입 (‘-’은 일반 파일)
🔹 실행 권한 추가
bash
Copy
Edit
chmod +x 파일명
🧾 5. Shell 스크립트 실습
🔹 파일 작성 및 실행
bash
Copy
Edit
vi test1
입력 내용:

bash
Copy
Edit
date
권한 추가 후 실행:

bash
Copy
Edit
chmod +x test1
./test1
📤 6. echo와 변수
🔹 echo 명령
bash
Copy
Edit
echo "hello"
🔹 특수 변수들
변수	설명
$0	스크립트 파일명
$1, $2	첫 번째, 두 번째 인자
$#	인자의 개수
$@	모든 인자 (리스트 형태)
$?	직전 명령의 종료 코드
$USER, $UID, $HOME	현재 사용자 정보

🛠 7. 실습 예제: test2
🔹 내용
bash
Copy
Edit
echo "User info for userid: $USER"
echo UID: $UID
echo HOME: $HOME
🔹 실행
bash
Copy
Edit
chmod u+x test2
./test2
🤖 8. 자동 실행 프로그램: st
bash
Copy
Edit
vi $1
chmod u+x $1
./$1
인자로 받은 파일을 편집하고 자동으로 실행하는 유틸리티 스크립트입니다.

🧪 9. 실습 예제: test3
🔹 스크립트 내용
bash
Copy
Edit
days=10
guest="Katie"
echo "$guest checked in $days days ago"

days=5
guest="Jessica"
echo "$guest checked in $days days ago"
🔹 실행
bash
Copy
Edit
./st test3