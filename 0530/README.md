## 🔍 grep 명령어 정리

`grep`은 파일이나 표준 입력에서 **패턴을 검색**하는 명령어입니다. 텍스트 필터링과 로그 분석 등에 자주 사용됩니다.

---

### 📌 기본 문법

```bash
grep [옵션] '패턴' 파일명

🧩 주요 옵션
옵션	설명
-i	대소문자 무시 (ignore case)
-v	패턴과 일치하지 않는 라인 출력
-n	일치하는 라인의 번호 함께 출력
-c	일치하는 라인의 개수만 출력
-l	일치하는 파일 이름만 출력 (파일 내 내용은 출력 안 함)
-w	단어 단위로 정확히 일치하는 것만 검색
-r 또는 -R	하위 디렉토리까지 재귀적으로 검색
-E	확장 정규표현식 사용 (egrep과 동일)
-F	고정 문자열 검색 (fgrep과 동일)
--color	일치하는 문자열을 색상 강조

✅ 사용 예시
명령어	설명
grep "apple" file.txt	file.txt에서 "apple" 포함된 줄 출력
grep -i "apple" file.txt	대소문자 구분 없이 "apple", "Apple" 등 검색
grep -v "error" logfile.txt	"error" 없는 줄만 출력
grep -n "main" *.c	.c 파일에서 "main"이 있는 줄과 줄 번호 출력
grep -c "bash" ~/.bashrc	.bashrc 파일에서 "bash" 등장 횟수 출력
grep -r "TODO" .	현재 디렉토리 이하에서 "TODO" 포함된 줄 모두 출력

🎯 정규표현식 예시
패턴	의미	예시
^abc	abc로 시작	grep '^abc' file
xyz$	xyz로 끝남	grep 'xyz$' file
a.b	a와 b 사이에 아무 문자 하나	grep 'a.b' file
[0-9]	숫자 하나	grep '[0-9]' file
[a-zA-Z]	알파벳 하나	grep '[a-zA-Z]' file
`foo	bar`	foo 또는 bar

🚀 실전 팁
여러 로그 파일에서 에러만 찾을 때:

bash
Copy
Edit
grep -i "error" /var/log/*.log
실행 파일에서 특정 함수 호출 찾기:

bash
Copy
Edit
grep -nr "functionName" src/
특정 문자열을 포함하지 않는 줄만 출력:

bash
Copy
Edit
grep -v "DEBUG" app.log
📘 참고: grep, egrep, fgrep은 현재는 모두 grep 명령어로 통합되어 있으며 -E, -F 옵션으로 사용 가능합니다.