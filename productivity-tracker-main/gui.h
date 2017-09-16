#pragma once

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#define INITIALIZE_WINDOW_HANDLER(hwnd) hwnd = CreateWindow(szAppName,              \
                                                      TEXT("The HelloWin Program"),	\
                                                      WS_OVERLAPPEDWINDOW,			\
                                                      CW_USEDEFAULT,				\
                                                      CW_USEDEFAULT,				\
                                                      CW_USEDEFAULT,				\
                                                      CW_USEDEFAULT,				\
                                                      nullptr,						\
                                                      nullptr,						\
                                                      hInstance,					\
                                                      nullptr);							