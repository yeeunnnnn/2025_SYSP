# 📂 0314 Directory Structure

## 🔍 Tree 명령어란?
리눅스의 `tree` 명령어는 **현재 디렉터리 및 하위 디렉터리의 구조를 트리 형태로 시각적으로 출력**하는 명령어입니다.  
이를 활용하면 디렉터리 내의 **파일과 폴더 구조를 한눈에 파악**할 수 있습니다.

### ✅ 기본적인 사용법
터미널에서 다음과 같이 입력하면 현재 디렉터리의 트리 구조를 확인할 수 있습니다.

```sh
tree
```

또한 특정 디렉터리를 지정하여 실행할 수도 있습니다.

```sh
tree /path/to/directory
```

---

## 🔧 Tree 명령어 설치 방법

리눅스 환경에서 `tree` 명령어가 설치되어 있지 않다면, 아래 명령어를 사용하여 설치할 수 있습니다.

#### 📌 Ubuntu / Debian 계열
```sh
sudo apt-get update
sudo apt-get install tree
```

#### 📌 Red Hat 계열
```sh
sudo yum install tree
```

#### 📌 Fedora / CentOS 계열
```sh
sudo dnf install tree
```

#### 📌 계열 무관 (Snap 패키지 관리자 이용)
```sh
sudo snap install tree
```

---

## 🏗 실습: 0314 디렉터리 구조 만들기

다음 명령어를 실행하면 아래와 같은 **디렉터리 및 파일 구조**가 생성됩니다.

```
.
├── app
│   └── d.txt
├── system
│   ├── LP
│   │   ├── compiler
│   │   │   └── a.txt
│   │   ├── interpreter
│   │   │   └── b.txt
│   ├── OS
│   ├── Util
│   │   └── c.txt
```

---

## 📜 명령어 실행 방법 (순차적 생성)

### 🔹 1. **`app` 디렉터리 및 파일 생성**
```sh
mkdir app
touch app/d.txt
```

### 🔹 2. **`system` 디렉터리 생성**
```sh
mkdir system
```

### 🔹 3. **`system/LP` 디렉터리 생성**
```sh
mkdir system/LP
```

### 🔹 4. **`system/LP/compiler` 디렉터리 및 파일 생성**
```sh
mkdir system/LP/compiler
touch system/LP/compiler/a.txt
```

### 🔹 5. **`system/LP/interpreter` 디렉터리 및 파일 생성**
```sh
mkdir system/LP/interpreter
touch system/LP/interpreter/b.txt
```

### 🔹 6. **`system/OS` 디렉터리 생성**
```sh
mkdir system/OS
```

### 🔹 7. **`system/Util` 디렉터리 및 파일 생성**
```sh
mkdir system/Util
touch system/Util/c.txt
```

### 🔹 8. **구조 확인**
```sh
tree
```

---

## 🎯 결과 확인
위 명령어 실행 후, `tree` 명령어를 입력하면 아래와 같은 결과가 출력됩니다.

```sh
$ tree
.
├── app
│   └── d.txt
├── system
│   ├── LP
│   │   ├── compiler
│   │   │   └── a.txt
│   │   ├── interpreter
│   │   │   └── b.txt
│   ├── OS
│   ├── Util
│   │   └── c.txt