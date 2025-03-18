# 🎯 Windows Subsystem for Linux (WSL)

## 🏆 WSL이란?
**Windows Subsystem for Linux (WSL)**은 Windows 환경에서 **리눅스 커널을 실행할 수 있도록 지원하는 기능**입니다.  
즉, **가상 머신 없이** Windows에서 Linux 명령어를 직접 실행할 수 있도록 해줍니다.



## 🚀 WSL 설치 및 설정 방법

### 🔹 1. Windows PowerShell을 관리자 권한으로 실행
1. `Win + X` 키를 눌러 **PowerShell (관리자 권한)** 실행  
   또는 `cmd`를 검색 후 `Ctrl + Shift + Enter`로 실행

---

### 🔹 2. Windows Subsystem for Linux(WSL) 활성화
```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```
✅ 위 명령어를 입력하면 **WSL 기능이 활성화**됩니다.

---

### 🔹 3. 가상 머신 플랫폼(Virtual Machine Platform) 활성화
```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```
✅ **WSL 2를 사용하려면 필수!**  
✅ 시스템 재부팅을 추천합니다.

---

### 🔹 4. WSL을 이용해 Ubuntu 설치
```powershell
wsl --install -d Ubuntu
```
✅ 실행하면 자동으로 **Ubuntu가 설치**됩니다.  
✅ 기본적으로 WSL 2로 설치됨.

---

### 🔹 5. WSL 기본 버전을 2로 설정
```powershell
wsl --set-default-version 2
```
✅ WSL에서 **모든 리눅스 배포판이 기본적으로 WSL 2를 사용**하도록 설정

---

### 🔹 6. Ubuntu 실행 및 초기 설정
1. **Windows 검색창에 `Ubuntu` 입력 후 실행**
2. **최초 실행 시 사용자 이름 및 비밀번호 설정**
3. WSL에서 리눅스 기본 명령어 입력 가능 ✅
   ```bash
   ls        # 현재 디렉토리 목록 확인
   cd ..     # 한 단계 상위 디렉토리로 이동
   ```