#pragma once

#include <windows.h>

static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                                  LPARAM lParam);
class Application {  //класс, который будет запускать цикл обработки сообщений.
 public:
  int Run();
};

int Application::Run() {
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    if (msg.hwnd == NULL) continue;
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (LRESULT)msg.wParam;
}

class Window { //класс окна
 public:
  HWND _hwnd;
  bool Create(HWND parent, LPCSTR text, DWORD exstyle, DWORD style, int x,
              int y, int w, int h, UINT id);
  static LRESULT CALLBACK _WndProc(HWND hwnd, UINT message, WPARAM wparam,
   LPARAM lparam) {
   //нет обработчика сообщений
    return DefWindowProc(hwnd, message, wparam, lparam);
  }
};
bool Window::Create(HWND parent, LPCSTR text, DWORD exstyle, DWORD style, int x,
                    int y, int w, int h, UINT id) {
  WNDCLASSEX wndc;
  wndc.lpszClassName = "MyWnd";
  wndc.cbSize = sizeof(WNDCLASSEX);
  wndc.lpfnWndProc = WNDPROC(_WndProc); 
  wndc.cbClsExtra = 0;
  wndc.cbWndExtra = 0;
  wndc.hbrBackground = HBRUSH(COLOR_WINDOW);  
  wndc.hInstance = GetModuleHandle(0);        
  wndc.hCursor = LoadCursor(0, IDC_ARROW);  
  wndc.style = CS_HREDRAW | CS_VREDRAW;
  wndc.hIcon = 0;
  wndc.hIconSm = 0;
  wndc.lpszMenuName = 0;
  RegisterClassEx(&wndc);

  //Создаем само окно
  _hwnd = CreateWindowEx(
      exstyle, "MyWnd", text,
      style | WS_CLIPCHILDREN, x, y, w, h, parent, HMENU(id), GetModuleHandle(0),this);

  if (!_hwnd) return false;
  return true;
}

class MyWindow : public Window {
  LRESULT OnPaint(LPARAM lparam, WPARAM wparam) {
    PAINTSTRUCT ps;
    RECT rect;
    GetClientRect(_hwnd, &rect);
    HDC hdc = BeginPaint(_hwnd, &ps);
    HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
    Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
    EndPaint(_hwnd, &ps);
  }
  LRESULT OnCreate(LPARAM lparam, WPARAM wparam) {
    MessageBox(0, "Window", "", 0);
    return 0;
  }
  LRESULT OnDestroy(LPARAM lparam, WPARAM wparam) {
    PostQuitMessage(0);
    return 0;
  }
};