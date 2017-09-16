
#include "windows-headers.h"
#include "stdlib.h"


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = szAppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(nullptr, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);

		return (0);
	}

	hwnd = CreateWindow(szAppName,			// Window Class Name
		TEXT("The HelloWin Program"),		// Window Caption
		WS_OVERLAPPEDWINDOW,				// Window Style
		CW_USEDEFAULT,						// Initial X Position
		CW_USEDEFAULT,						// Initial Y Position
		CW_USEDEFAULT,						// Initial X size
		CW_USEDEFAULT,						// Initial Y size
		nullptr,							// Parent Window Handle
		nullptr,							// Window Menu Handle
		hInstance,							// Program Instance Handle
		nullptr);							// Creation Parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}