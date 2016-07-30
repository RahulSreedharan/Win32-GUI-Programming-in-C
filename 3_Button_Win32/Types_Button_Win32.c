
	// Program to create a different types of Button using Win32 API
	// Date 22 April 2013

	#include<windows.h>
    
	#define APPTITLE "Windows Buttons"
	
	ATOM Init_Window_Class(HINSTANCE);
	BOOL InitInstance(HINSTANCE,int);
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
													TranslateMessage(&msg);         //additional processing,translates virtual key messages to characters,optional
													DispatchMessage(&msg);          //Send the Message to WinProc() for processing
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
								wc.hIcon         =  LoadIcon(NULL,IDI_ASTERISK);          //Icon Asterisk
								wc.hCursor       =  LoadCursor(NULL,IDC_ARROW);           //Predefined Arrow
								wc.hbrBackground =  (HBRUSH) GetStockObject(WHITE_BRUSH); //Back ground Color
								wc.lpszMenuName  =  NULL;                                 //Menu is not registered here
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
												 250,                      // Width
												 200,					   // Height
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
								HWND PushButton_Handle,CheckBox_Handle,Radiobutton_Handle; //Handle for the button 

								switch (Message)                                    //Switch to handle system messages
									   {						                    
										   case WM_CLOSE:                           //Control for Pressing the Close Button On the Window
											                DestroyWindow(hWnd);    //Destroy the Window  
															break;

										   case WM_DESTROY: PostQuitMessage(0);     //Send the WM_QUIT message to the while loop in WinMAIN()
											                break;

										   case WM_COMMAND: //Menu Control Code
											                switch(HIWORD(wParam))  //LOWORD(wParam) is used to extract the Menu handle from the Message
																  {
																	case BN_CLICKED: MessageBox(hWnd,"You clicked Me","Messages ",MB_OK);

																  }								  
															break;

										   case WM_CREATE:      //System generates this message when creating a Window
											                {   //PushButton
																PushButton_Handle = CreateWindow( "BUTTON",                                               // Window Type = Button
																							      "Click Me",                                             // Text on Button
																							      WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Button Style
																							      10,                                                     // x position 
																							      10,                                                     // y position 
																							      80,                                                     // Button width
																							      30,                                                     // Button height
																							      hWnd,                                                   // Parent window
																							      NULL,                                                   // No menu.
																							      (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), 
																							      NULL );                                                 // Pointer not needed.

																//Check Box
																CheckBox_Handle   = CreateWindow( "BUTTON",                                               // Window Type = Button
																							      "Check Me",                                             // Text on Button
																							      WS_TABSTOP | WS_VISIBLE | WS_CHILD |BS_CHECKBOX,        // Button Style->Check box
																							      100,                                                    // x position 
																							      10,                                                     // y position 
																							      80,                                                     // Button width
																							      30,                                                     // Button height
																							      hWnd,                                                   // Parent window
																							      NULL,                                                   // No menu.
																							      (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), 
																							      NULL );                                                 // Pointer not needed.
																//Radio button
																Radiobutton_Handle = CreateWindow( "BUTTON",                                              // Window Type = Button
																							      "Check Me",                                             // Text on Button
																							      WS_TABSTOP | WS_VISIBLE | WS_CHILD |BS_RADIOBUTTON,     // Button Style
																							      200,                                                    // x position 
																							      10,                                                     // y position 
																							      80,                                                     // Button width
																							      30,                                                     // Button height
																							      hWnd,                                                   // Parent window
																							      NULL,                                                   // No menu.
																							      (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), 
																							      NULL );                                                 // Pointer not needed.


															}
											                break;

										   default:         return DefWindowProc(hWnd,Message,wParam,lParam);  //Default Windows Procedure
									   }                                                                       //WM_PAINT may some times create problem with MessageBox()
								
		                     } 