
#include "windows-headers.h"

#include <cstdlib>


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (message)
	{
	case (WM_CREATE):
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return (EXIT_SUCCESS);

	case (WM_PAINT):
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		
		DrawText(hdc, TEXT("Hello, Windows 98!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		
		EndPaint(hwnd, &ps);

		return (EXIT_SUCCESS);

	case (WM_DESTROY):
		PostQuitMessage(EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}

	return (DefWindowProc(hwnd, message, wParam, lParam));
}
