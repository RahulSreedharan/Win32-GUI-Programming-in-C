//+=======================================================================================+ //
//|           Program to generate a simple Window using  Win32 API                        | //
//+=======================================================================================+ //
//| Program to generate a simple Window using  Win32 API using C                          | //
//+=======================================================================================+ //
//| Compiler/IDE  :	Microsoft Visual Studio Express 2013 for Windows Desktop(Version 12.0)| //
//|               : gcc 4.8.1 (MinGW)                                                     | //
//|                                                                                       | //
//| Library       : Win32 API,windows.h,                                                  | //
//| OS            :	Windows(Windows 7)                                                    | //
//| Programmer    :	Rahul.S                                                               | //
//| Date	      :	29-July-2016                                                          | //
//+=======================================================================================+ //

//+=========================================================================================+ //
//| Compilation  : gcc -o Simple_Window  Simple_Window.c -lcomctl32 -Wl,--subsystem,windows | //
//+-----------------------------------------------------------------------------------------+ //
//| The -Wl,--subsystem,windows linker switch ensures that the application is built as a    | //
//| Windows GUI application, and not a console application. Failing to do so would result   | //
//| in a console window being displayed whilst your application runs,                       | //
//+=========================================================================================+ //


//+=======================================================================================+ //
//| Reference -> http://www.transmissionzero.co.uk/computing/win32-apps-with-mingw/       | //
//+=======================================================================================+ //

//WINAPI is same as _stdcall 

#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance,                   // contains the instance of the program        
				   HINSTANCE hPrevInstance,               // contains the previous instance 
				   LPSTR lpCmdLine,                       // pointer to command line arguments
				   int nCmdShow)                          // display properties
	{
		HWND h;                                           
		h = CreateWindow("BUTTON","Hit me",WS_OVERLAPPEDWINDOW,350,300,250,100,0,0,hInstance,0); //Create a window with BUTTON class
		ShowWindow(h,nCmdShow);                                                                  //show the window                                                
		
		MessageBox(0,"Press Me","Waiting",MB_OK);                                                //used to display window like getch() in DOS env                                                

	}