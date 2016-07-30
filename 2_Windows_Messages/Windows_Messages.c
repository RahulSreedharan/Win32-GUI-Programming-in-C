
	// Program to study Windows Messages
	// Date 21 April 2013

	#include<windows.h>
    

	#define APPTITLE "Messages in Windows"

	ATOM Init_Window_Class(HINSTANCE);                  //Intialize and register Window class
	BOOL InitInstance(HINSTANCE,int);                   //Create window using the registered Class
	LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);  

	//Main loop 
	int WINAPI WinMain(HINSTANCE hInstance,                     //Current Instance of the Program
		               HINSTANCE hPrevInstance,					//Previous Instance of the Program	
					   LPSTR     nCmdLine,					    //Pointer to Command Line Parameters							
					   int       nCmdShow)                      //How to display the window
		                                {
											MSG msg;
											
											if(!Init_Window_Class(hInstance)) //if Window registeration fails
												{
												  MessageBox(NULL,"Window Registeration Failed","ERROR",0);
												  return FALSE;    //end WinMain()
												}

											if(!InitInstance(hInstance,nCmdShow)) //if Window Creation fails
												{
												  MessageBox(NULL,"Window Creation Failed","ERROR",0);
												  return FALSE;    //end WinMain()
												}

											while(GetMessage(&msg,NULL,0,0) > 0 )   //Get Message from Windows OS,get out of loop if WN_QUIT is recieved
												{
													TranslateMessage(&msg); //additional processing,translates virtual key messages to characters,optional
													DispatchMessage(&msg);  //Send the Message to WinProc() for processing
												}
											return msg.wParam;
		                                }
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*                Function to create the Window Class and Register it with the OS                                                       */
	/*--------------------------------------------------------------------------------------------------------------------------------------*/

	ATOM Init_Window_Class(HINSTANCE hInstance)                 //Function to intialize and Register the Window
		                  {
								WNDCLASSEX wc;                  //Create a variable 'wc' of type WNDCLASSEX which is a structure
								
								//fill up the Structure "wc" with parameters
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

								return RegisterClassEx(&wc);                              //Register the Window class with OS
		                  }
    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*                Function to create the Window   and  Display it                                                                       */
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)          
		             {
							HWND hWnd;          //Handle for the window
							//Create Window
							hWnd = CreateWindow( APPTITLE,                 // Class Name
								                 APPTITLE,                 // Title of the Window
												 WS_OVERLAPPEDWINDOW,      // Window Style
												 CW_USEDEFAULT,            // Default X position
												 CW_USEDEFAULT,            // Default Y Position 
												 300,                      // Width
												 150,					   // Height
												 NULL,                     // No Parent Window
												 NULL,                     // No Menu
												 hInstance,                // Instance Handle
												 NULL);                    // Window Parameters

							if(!hWnd)           //if window creation fails Return False 
								return FALSE;   //Failure :-(
							
							ShowWindow(hWnd,nCmdShow);  // Display the Window
							UpdateWindow(hWnd);         // Update the window in response to commands
							return TRUE;                // success!
		             }
    /*--------------------------------------------------------------------------------------------------------------------------------------*/
    /*                Windows Call back Function that processes the Messages from the OS                                                    */
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	LRESULT CALLBACK WinProc(HWND   hWnd,                       // Handle to the window
		                     UINT   Message,                    // Messages from the Window OS
							 WPARAM wParam,                     // Parameters
							 LPARAM lParam)                     // Parameters
		                     {
								                               
								switch (Message)                                            //Switch to handle system messages
									   {						                    
										   case WM_CLOSE:                                   //Control for Pressing the Close Button On the Window
																	DestroyWindow(hWnd);    //Destroy the Window  
																	break;

										   case WM_DESTROY:			PostQuitMessage(0);     //Send the WM_QUIT message to the while loop in WinMAIN()
																	break;

										   case WM_COMMAND:			//Menu Control Code
																	break;

										   case WM_LBUTTONDOWN:		SendMessage(hWnd,WM_RBUTTONDOWN,0,0); //Posting the WM_RBUTTONDOWN message to the Message Queue
																	//MessageBox(hWnd,"Left button is down","Messages",0);
										    						break;

										   case WM_RBUTTONDOWN:		MessageBox(hWnd,"Right button is down","Messages",0);
																	break;

										  

										   default:                 return DefWindowProc(hWnd,Message,wParam,lParam);  //Default Windows Procedure
									   }                                                                               //WM_PAINT may some times create problem with MessageBox()
								
		                     } 