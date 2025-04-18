## 📌 프로세스

| 항목      | 내용                               |           |
| ------- | -------------------------------- | --------- |
| 정의      | 실행 중인 프로그램                       |           |
| 종류      | 시스템 프로세스 / 사용자 프로세스              |           |
| 조회 명령어  | `ps`, `pgrep`, \`ps -ef          | grep 패턴\` |
| 후면 실행   | `명령어 &`                          |           |
| 중지 / 재개 | `Ctrl + Z`, `fg`, `bg`           |           |
| 입출력 제어  | `명령어 > 파일`, `명령어 < 파일`           |           |
| 종료      | `kill [PID]`, `exit`             |           |
| 대기      | `wait [PID]`                     |           |
| 우선순위 제어 | `nice`, `renice`                 |           |
| ID 확인   | `id`, `$UID`, `$EUID`            |           |
| 특수 권한   | `chmod 4755`, `chmod 2755`       |           |
| 시그널 종류  | `SIGKILL`, `SIGINT`, `SIGTSTP` 등 |           |
| 시그널 전송  | `kill -시그널 PID`, `kill -9 PID`   |           |

---

## 🌐 인터넷과 서버

### 네트워크 구성

* LAN, 이더넷, 라우터, 게이트웨이
* IP 확인: `ip addr`, `hostname`
* DNS 조회: `nslookup 도메인`

### 인터넷

* 프로토콜: TCP/IP
* 도메인 → IP: DNS
* 사용자 정보 확인: `finger 사용자명`

### 서버 설치

* 웹서버: Apache, PHP, MariaDB → `apt install apache2 php mariadb-server`
* FTP 서버: `vsftpd`
* SSH 서버: `apt install ssh`
* 서비스 구동: `systemctl start|enable|status 서비스명`

### 파일 전송

| 방법          | 명령어           |
| ----------- | ------------- |
| FTP/SFTP 접속 | `ftp`, `sftp` |
| 업로드         | `put`, `mput` |
| 다운로드        | `get`, `mget` |

### 원격 접속

* SSH: `ssh 사용자@호스트`
* 원격 명령 실행: `ssh 호스트 명령어`
* 상태 확인: `ping 호스트명`
* xrdp 설치: `apt install xrdp`, `ufw allow 3389`, `systemctl start xrdp`

---

## 📂 파일 유틸리티

### 파일 찾기: `find`

* 기본형: `find 디렉토리 -옵션`
* 옵션: `-name`, `-user`, `-size`, `-type`, `-perm`, `-mtime`, `-exec`

### 필터링: `grep`

* 기본형: `grep 패턴 파일`
* 옵션: `-i`, `-l`, `-n`, `-v`, `-w`, `-c`

### 정렬: `sort`

* 기본형: `sort [-옵션] 파일`
* 옵션: `-r`, `-k`, `-n`, `-t`, `-o`

### 비교: `cmp`, `diff`

* `cmp`: 바이트 단위 비교
* `diff`: 줄 단위 차이 확인

### 기타 조작

* 분할: `split -l n 파일`
* 합병: `cat`, `paste`

---

## 🛠️ 명령어 스케줄링

### cron (주기적 실행)

* 등록: `crontab 파일`, `crontab -e`
* 예: `30 18 * * * rm /home/chang/tmp/*`

### at (1회 실행)

* 등록: `at 시간`
* 조회: `atq`
* 삭제: `at -r 작업번호`

---

## 💾 디스크 및 압축

### 디스크 사용량

* `df`, `du`

### tar 아카이브

* 생성: `tar -cvf 파일.tar 파일들`
* 해제: `tar -xvf 파일.tar`
* 목록: `tar -tvf 파일.tar`

### 압축

* gzip / gunzip: `.gz`
* compress / uncompress: `.Z`

---

## 🔧 AWK

### 기본 구조

* `조건 { 액션 }`
* 내장 변수: `NR`, `NF`, `$0`, `$1`...

### 조건문 및 흐름 제어

* `BEGIN`, `END`
* `if`, `for`, `while`, `next`, `exit`

### 예제

1. 파일 시작/끝:

```bash
awk 'BEGIN{print "파일 시작"} {print $1, $NF} END{print "파일 끝"}' 파일명
```

2. 줄/단어 수:

```bash
awk '{printf "line %d: %d\n", NR, NF; word+=NF} END {print NR, word}' 파일명
```

3. 홀수 필드:

```bash
awk '{for(i=1;i<=NF;i+=2) printf "%s ", $i; print ""}' 파일명
```

4. 패턴 검색:

```bash
awk '/st.*e/ {print NR, $0}' 파일명
```

5. 구간 추출:

```bash
awk '/strong/,/heart/ {print NR, $0}' 파일명
```

6. 단어 수 세기:

```bash
awk '/raise/ {++line} END {print line}' 파일명
```

7. 단어별 빈도수:

```bash
awk 'BEGIN{FS="[^a-zA-Z]+"} {for(i=1;i<=NF;i++) words[tolower($i)]++} END {for(i in words) print i, words[i]}' 파일명
```

---

## 🐚 Bash 쉘 스크립트

### 시작 파일

* `/etc/profile`, `/etc/bash.bashrc`, `~/.bash_profile`, `~/.bashrc`

### 별명 / 히스토리

* alias: `alias ll='ls -al'`
* history: `!!`, `!n`, `!gcc`, `!?text`

### 변수

* 단일: `x=1`, `echo $x`
* 배열: `arr=(a b c)`, `${arr[1]}`
* 입력: `read a b`

### 지역/환경 변수

* 환경 변수로 설정: `export country=KR`
* 사전 정의: `$USER`, `$HOME`, `$PATH`
* 인수 관련: `$0`, `$1`, `$*`, `$$`, `$#`

### 조건문

```bash
if [ $# -eq 1 ]; then
  wc $1
else
  echo "사용법: $0 파일"
fi
```

### 수식 연산

* 정수 비교: `-eq`, `-ne`, `-gt`, `-lt`, `-ge`, `-le`
* 문자열: `==`, `!=`, `-z`, `-n`
* 파일: `-e`, `-f`, `-d`, `-r`, `-w`, `-x`

### 논리연산

* `&&`, `||`, `!`

### 반복문

```bash
for name in a b c; do
  echo $name
done
```

```bash
let i=0
while ((i<5)); do
  echo $i
  let i++
done
```

### 함수

```bash
hello() {
  echo "Hello, $1"
}
hello world
```

### 디버깅

* `bash -v`, `bash -x`

---

## 🧑‍💻 개발 환경: gcc, make, gdb

### gedit 사용

```bash
gedit file.c &
```

### gcc 컴파일

```bash
gcc file.c -o file
./file
```

### 다중 모듈

```bash
gcc -c a.c
gcc -c b.c
gcc -o main a.o b.o
```

### Makefile 예시

```make
main: main.o copy.o
	gcc -o main main.o copy.o
main.o: main.c copy.h
	gcc -c main.c
copy.o: copy.c
	gcc -c copy.c
```

### gdb

```bash
gcc -g file.c -o file
gdb ./file
```

| 명령어       | 설명       |
| --------- | -------- |
| break n   | n줄 중단점   |
| run       | 실행       |
| next      | 다음 줄 실행  |
| step      | 함수 내부 진입 |
| print var | 변수 출력    |
| list      | 소스 보기    |
| quit      | 종료       |

```
}

```
