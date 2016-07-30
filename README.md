#Building Graphical User Interface using Win32 API and C language 
-----------------------------------------------------------------------------------------------------------------------------------------
##Introduction

A collection of programs for learning to build a Graphical user interface in C using Win32 API.
The code is tested on a Windows 7 Machine.

The code can be compiled using 
- **Visual Studio** Express Edition from Microsoft
- **GCC** (through MinGW Tool Chain)

--------------------------------------------------------------------------------------------------------------------------------------
##Compilation

Compilation of the code can be done in GCC (MinGW) using the Following command.

```
C:\ gcc -o SourceFile.exe  SourceFile.c -Wl,--subsystem,windows  -lgdi32
```

- The **-Wl,--subsystem,windows** linker switch ensures that the application is built as a Windows GUI application, and not a console application. Failing to do so would result in a console window being displayed whilst your application runs

- You should link with the gdi32 library using "**-lgdi32** " otherwise the code will complain about "*undefined reference to GetStockObject*".

--------------------------------------------------------------------------------------------------------------------------------------
## Contents

###1_Hello_Windows

  - **MessageBox.c** - Code for creating a pop up messagebox 
  - **Simple_Window.c** - Code for creating a Basic Window 
  - **WindowComplete.c** - Code for creating a Complete Window with Call Back Function

###2_Windows_Messages

- **Windows_Messages.c** - Shows how Windows handles Messages and pass it to the callback function

###3_Button_Win32

  


