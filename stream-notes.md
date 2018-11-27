# Stream 01 Notes

* Performed basic system setup
* Created a hello world app
* Created a higher-lower game
* Created this git repo

## Set-up Windows

**Installed software:**

* Visual Studio Code: https://code.visualstudio.com/
* Cmder: http://cmder.net/
* MSYS2: https://www.msys2.org/
	* To install g++ after updating (as instructed on the website) in the MSYS terminal (as opposed to Cmder) type `pacman -S mingw-w64-x86_64-gcc`
* Git: https://git-scm.com/

**Code for wdo batch script:**

`wdo.bat`

```batch
@echo off
setlocal enabledelayedexpansion

set argCount=0
for %%x in (%*) do (
    set /A argCount+=1
    set "argVec[!argCount!]=%%~x"
)

set exec=echo wdo-ing stuff...

for /L %%i in (1,1,%argCount%) do (
    set "exec=!exec! & wdo-!argVec[%%i]!.bat"
)

(
    endlocal
    @%exec%
)
```

## Set-up for Linux
Install gcc, g++ and git. Ubuntu example:

```
$ sudo apt install gcc g++
$ sudo apt-install git
```

## Set-up for macOS

Intall homebrew: http://brew.sh

Install command line tools and git:

```
$ xcode-select --install
$ brew install git
```