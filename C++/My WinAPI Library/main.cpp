#include <windows.h>
#include "Application.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow) {
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  MyWindow *wnd = new MyWindow;
  wnd->Create(0, "MyWindow", 0, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 300, 300,
              500, 400, 0);
  Application *app = new Application;
  app->Run();
  return 0;
}

