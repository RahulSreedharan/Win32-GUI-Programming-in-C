//+=======================================================================================+ //
//|           Program to generate a Complete Window using  Win32 API                      | //
//+=======================================================================================+ //
//| Program to generate a Complete Window using  Win32 API using C                        | //
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
//| Compilation  : gcc -o WindowComplete  WindowComplete.c -Wl,--subsystem,windows  -lgdi32 | //
//+-----------------------------------------------------------------------------------------+ //
//| The -Wl,--subsystem,windows linker switch ensures that the application is built as a    | //
//| Windows GUI application, and not a console application. Failing to do so would result   | //
//| in a console window being displayed whilst your application runs,                       | //
//|                                                                                         | //
//| You should link with the gdi32 library using " -lgdi32 " otherwise the code will        | //
//| complain about "undefined reference to GetStockObject".                                 | //
//+=========================================================================================+ //

#include<windows.h>

#define APPTITLE "Hello World"

ATOM Init_App_Window_class(HINSTANCE);                 //Function to create and fill the Window class structure WNDCLASSEX
BOOL InitInstance(HINSTANCE,int);                      //Create window according to specifics in window class structure
LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);     //Used to process the Messages from Windows to Application

//-------------------------- Main Program------------------------------------------------------------------------------------------------------//
int WINAPI WinMain(HINSTANCE hInstance,               //instance of the running program
	               HINSTANCE hPrevInstance,           //Previous Instance of the running Program
				   LPSTR     lpCmdLine,               //Long Pointer to Command line Arguments
				   int       nCmdShow)                //Showing the Window
	                                    {
											MSG m;                                //MSG is a typdef for a structure to get messages from windows OS
											         
											Init_App_Window_class(hInstance);     //Create and fill the Window class structure WNDCLASSEX
											
											if(!InitInstance(hInstance,nCmdShow)) //Create window according to specifics in window class structure
												return FALSE;
											            
											
											while(GetMessage(&m,NULL,0,0))        //Get message from Application Message Queue,Quit loop on Recieving WM_QUIT
												 {
												    TranslateMessage(&m);         //Transalate Message 
													DispatchMessage(&m);          //Dispatch Message to WinProc() function 
												 }
											return m.wParam;
	                                    }

ATOM Init_App_Window_class(HINSTANCE hInstance)  //Function to create and fill the Window class structure WNDCLASSEX
	                      {
								WNDCLASSEX wc;   //define wc as a structure of type WNDCLASSEX
								                 // Fill up the structure


								wc.cbSize        =  sizeof(WNDCLASSEX);                   //Size of the structure
								wc.style         =  CS_HREDRAW | CS_VREDRAW;              //Redraw if Size Changes
								wc.lpfnWndProc   =  (WNDPROC)WinProc;                     //Points to the Window Procedure" LRESULT CALLBACK WinProc (,,,,);"
								wc.cbClsExtra    =  0;                                    //No Extra Class Memory
								wc.cbWndExtra    =  0;                                    //No Extra Window Memory
								wc.hInstance     =  hInstance;                            //Handle to the instance
								wc.hIcon         =  NULL;                                 //No Icon
								wc.hCursor       =  LoadCursor(NULL,IDC_ARROW);           //Predefined Arrow
								wc.hbrBackground =  (HBRUSH) GetStockObject(WHITE_BRUSH); //Back ground Color
								wc.lpszMenuName  =  NULL;                                 //No Menu
								wc.lpszClassName =  APPTITLE;                             //Name of Window Class
								wc.hIconSm       =  NULL; 

								return RegisterClassEx(&wc); //Register the Window class with OS
	                      }

BOOL InitInstance(HINSTANCE hInstance,int nCmdShow) //Create window according to specifics in window class structure
	             {
						HWND hWnd;					// Handle for the window

						hWnd = CreateWindow( APPTITLE,            // Window Class Name
							                 APPTITLE,            // Title Bar
											 WS_OVERLAPPEDWINDOW, // Window style
											 CW_USEDEFAULT,       // x position of Window
											 CW_USEDEFAULT,       // y position of Window
											 500,                 // Width of the Window
											 400,                 // Height of the Window
											 NULL,                // Parent Window
											 NULL,                // Menu
											 hInstance,           // Application Instance
											 NULL );              // Window parameters
						
						if(!hWnd)          //Was there an error in creating a window ? ie hWnd = 0;           
							return FALSE;

						ShowWindow(hWnd,nCmdShow);  //show the Window 
						UpdateWindow(hWnd);         //update the window inresponse to events
						return TRUE;
	             }

//---------Windows Call Back function to Process Messages from Windows-------------------------------------------------------------------------//

LRESULT CALLBACK WinProc (HWND hWnd,           //Window handle 
	                      UINT message,        //messages from Windows like WM_DESTROY,WM_PAINT
						  WPARAM wParam,       //
						  LPARAM lParam)
                    	                   {   
												switch(message)
							                          {  
												         
											             case WM_DESTROY: PostQuitMessage(0);
									                          break;
														 
							                         }
												 return DefWindowProc(hWnd,message,wParam,lParam);
						                   }
