
//+=======================================================================================+ //
//|           Program to generate MessageBox using Win32 API                              | //
//+=======================================================================================+ //
//| A simple Program to generate two types of Message Boxes using C                       | //
//+=======================================================================================+ //
//| Compiler/IDE  :	Microsoft Visual Studio Express 2013 for Windows Desktop(Version 12.0)| //
//|               : gcc 4.8.1 (MinGW)                                                     | //
//|                                                                                       | //
//| Library       : Win32 API,windows.h,                                                  | //
//| OS            :	Windows(Windows 7)                                                    | //
//| Programmer    :	Rahul.S                                                               | //
//| Date	      :	29-July-2016                                                          | //
//+=======================================================================================+ //

//+=======================================================================================+ //
//| Compilation  : gcc -o MessageBox  MessageBox.c -Wl,--subsystem,windows                | //
//+---------------------------------------------------------------------------------------+ //
//| The -Wl,--subsystem,windows linker switch ensures that the application is built as a  | //
//| Windows GUI application, and not a console application. Failing to do so would result | //
//| in a console window being displayed whilst your application runs,                     | //
//+=======================================================================================+ //


//+=======================================================================================+ //
//| Reference -> http://www.transmissionzero.co.uk/computing/win32-apps-with-mingw/       | //
//+=======================================================================================+ //


#include <Windows.h>
// main function for win32 
int WINAPI WinMain(HINSTANCE hinstance,             //
	               HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nShowCmd)
  	{
	     MessageBox(NULL,"What ever you want to say here","text on the title bar",MB_OK |MB_ICONEXCLAMATION);           //create a msgbox with ok button & exclamation mark
		 MessageBox(NULL,"What ever you want to say here","text on the title bar", MB_ABORTRETRYIGNORE|MB_ICONASTERISK);//create a msgbox with abort retry button & exclamation mark
	}
