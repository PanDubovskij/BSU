
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "Kr2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
static COLORREF Gold=RGB(255,215,0);
static COLORREF SaddleBrown=RGB(139,69,19);
static COLORREF OrangeRed=RGB(255,69,0);
static COLORREF ForestGreen = RGB(34, 139, 34);
static COLORREF Fire = OrangeRed;
static int shift_x, shift_y,x,y;
static int M = 5, N =7, step;
static int size_x, size_y;
static bool start=1,error=0;
static int speed = 1000,k=1;
std::vector<std::pair<int, int>> Centres;
std::vector<Spot> Spots(M* N);

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void SelectColor(HWND hwnd, COLORREF& color);
void InitCentres(std::vector<std::pair<int, int>>& Centres, int MatrixX,
                 int MatrixY);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  static BOOL bTracking = FALSE;
  static int p = 0,a,b;
  static HDC hDC;
  static HPEN pen1;
  static int cursor;
    switch (message)
    {
    case WM_MOUSEMOVE: {
        bTracking = true;
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      if (x < size_x - (size_x - M * step) / 2 &&
          y < size_y - (size_y - N * step) / 2 &&
          x > (size_x - M * step) / 2 &&
          y > (size_y - N * step) / 2) {
        int cntr_x = (x - (size_x - M * step) / 2) / step;
        int cntr_y = (y - (size_y - N * step) / 2) / step;
        cursor = (cntr_y)*M + cntr_x;
      } else {
        bTracking = false;
      }
      InvalidateRect(hWnd, 0, 1);
      break;
    }
    case WM_LBUTTONDOWN: {
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      if (x < size_x - (size_x - M * step) / 2 &&
          y < size_y - (size_y - N * step) / 2 && x > (size_x - M * step) / 2 &&
          y > (size_y - N * step) / 2) {
        int cntr_x = (x - (size_x - M * step) / 2) / step;
        int cntr_y = (y - (size_y - N * step) / 2) / step;
        auto it = std::find_if(Spots.begin(), Spots.end(),
                               [cntr_x, cntr_y](Spot spot) {
                                 return spot.x_ == cntr_x && spot.y_ == cntr_y;
                             }); 
        it->type == 1;  
      }
        InvalidateRect(hWnd, NULL, TRUE);
    } break;
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_F5: {
            SelectColor(hWnd, Fire);
            InvalidateRect(hWnd, NULL, TRUE);
          } break;
        }
    }break;
    case WM_CHAR: {
      switch (wParam) {
        case 'P': {
          if (!p) {KillTimer(hWnd, 1);
            p++;
          } else {
            SetTimer(hWnd, 1, k*speed, NULL);
            p--;
          }
        } break;
      }
    } break;
    case WM_TIMER: {
      SetTimer(hWnd, 1, k*speed, NULL);
    } break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_START:
              KillTimer(hWnd, 1);
              DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc);
              SetTimer(hWnd, 1, speed * k, NULL);
              InvalidateRect(hWnd, NULL, TRUE);
              break;
            case ID_CHOOSECOLOR:
              SelectColor(hWnd, Fire);
              InvalidateRect(hWnd, NULL, TRUE);
              break;
            case ID_OPEN: {
              OPENFILENAME ofn;
              ZeroMemory(&ofn, sizeof(ofn));
              CHAR FileName[300] = {'\0'};
              ofn.lStructSize = sizeof(ofn);
              ofn.hwndOwner = NULL;
              ofn.lpstrFile = FileName;
              ofn.nMaxFile = sizeof(FileName);
              ofn.lpstrFilter = "All Files\0*.*\0.TXT\0";
              ofn.nFilterIndex = 1;
              ofn.lpstrFileTitle = NULL;
              ofn.nMaxFileTitle = 0;
              ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
              if (GetOpenFileName(&ofn) == TRUE) {
                std::ifstream in(FileName);
                in >> N >> M;
                if (!Spots.empty()) {
                  Spots.clear();
                } 
                  for (int i = 0; i < M; i++) {
                    for (int j = 0; j < N; j++) {
                      Spot spot(i, j);
                      Spots.push_back(spot);
                    }
                  }
                  for (int i = 0; !in.eof(); i++) {
                    in >> Spots[i].type;
                  }
                InitCentres(Centres, N, M);
                  for (int i = 0; i < Spots.size(); i++) {
                    if (Spots[i].type == 1) {
                      Spots[i].type = 1;
                      Spots[i].x_ = Centres[i].first;
                      Spots[i].y_ = Centres[i].second;
                      Spots[i].color_ = Gold;
                    } else if (Spots[i].type == 2) {
                      Spots[i].x_ = Centres[i].first;
                      Spots[i].y_ = Centres[i].second;
                      Spots[i].color_ = SaddleBrown;
                    } else if (Spots[i].type == 3) {
                      Spots[i].x_ = Centres[i].first;
                      Spots[i].y_ = Centres[i].second;
                      Spots[i].color_ = Fire;
                    } else {
                      Spots[i].x_ = Centres[i].first;
                      Spots[i].y_ = Centres[i].second;
                      Spots[i].color_ = OrangeRed;
                    }
                    start = 0;
                  }
              }
              InvalidateRect(hWnd, NULL, TRUE);
            } break;
            case ID_SAVE: {
              static OPENFILENAME file;
              CHAR FileName[300] = {'\0'};
              DWORD result;
              HANDLE hFile;
              static char text[200];
              static DWORD nCharRead;
              file.lStructSize = sizeof(OPENFILENAME);
              file.hInstance = hInst;
              file.lpstrFilter = _T("Text\0*.txt\0Все файлы\0*.*");
              file.lpstrFile = FileName;
              file.nMaxFile = 256;
              file.lpstrInitialDir = _T(".\\");
              file.lpstrDefExt = _T("txt");
              file.lpstrTitle = _T("Открыть файл для записи");
              file.Flags = OFN_NOTESTFILECREATE;
              if (!GetSaveFileName(&file)) return 1;
              std::ofstream out(FileName);
              hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL,
                                 CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
              out << N << " " << M << " ";
              for (int i = 0; i < Spots.size(); i++) {
               out<<Spots[i].type<<" ";
              }
              CloseHandle(hFile);
            } break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_SIZE: {
      size_x = LOWORD(lParam);
      size_y = HIWORD(lParam);
      InvalidateRect(hWnd, NULL, TRUE);
    } break;
    case WM_CREATE: {
      if (Spots.empty()) {
        for (int i = 0; i < M; i++) {
          for (int j = 0; j < N; j++) {
            Spot spot(i, j);
            Spots.push_back(spot);
          }
        }
      }
      hDC = GetDC(hWnd);
     InvalidateRect(hWnd, NULL, TRUE);
    } break;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      hDC= BeginPaint(hWnd, &ps);
      
      HBRUSH brush;
      TCHAR text[20];
      int radix = 10;
      pen1 = CreatePen(PS_DASH, 1, Gold);
      SelectObject(hDC, pen1);
      if (M > N) {
        step = min(size_x, size_y) / max(M, N);
      } else {
        step = min(size_x, size_y) / min(M, N);
      }
        
        shift_x = (size_x - N * step) / 2;
        shift_y = (size_y - M * step) / 2;
       FillRect(hDC, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        for (int i = 0; i <= N*step; i += step) {
          MoveToEx(hDC, i+shift_x, 0+shift_y, NULL);
          LineTo(hDC, i+shift_x, M * step+shift_y);
        }
        for (int i = 0; i <=M * step; i += step) {
          MoveToEx(hDC, 0+shift_x, i+shift_y, NULL);
          LineTo(hDC,N * step+shift_x, i+shift_y);
        }
        if (bTracking) {
          HPEN pen2 = CreatePen(PS_SOLID, 2, ForestGreen);
          SelectObject(hDC, pen2);
          Rectangle(hDC, Centres[cursor].first - step / 2,
                    Centres[cursor].second - step / 2,
                    Centres[cursor].first + step / 2,
                    Centres[cursor].second + step / 2);
        }
        InitCentres(Centres, N, M);
        pen1 = CreatePen(PS_SOLID, 1, RGB(0,0,0));
        SelectObject(hDC, pen1);
        int object;
        if (start) {
          for (int i = 0; i < Spots.size(); i++) {
            object = rand() % 4;
            Spots[i].type = object;
            if (object == 1) {
              Spots[i].type = 1;
              Spots[i].x_ = Centres[i].first;
              Spots[i].y_ = Centres[i].second;
              Spots[i].color_ = Gold;
              brush = CreateSolidBrush(Gold);
              SelectObject(hDC, brush);
              Ellipse(hDC, Centres[i].first - step / 2,
                      Centres[i].second - step / 2, Centres[i].first + step / 2,
                      Centres[i].second + step / 2);
            } else if (object == 2) {
              Spots[i].type = 2;
              Spots[i].x_ = Centres[i].first;
              Spots[i].y_ = Centres[i].second;
              Spots[i].color_ = SaddleBrown;
              brush = CreateSolidBrush(SaddleBrown);
              SelectObject(hDC, brush);
              Rectangle(hDC, Centres[i].first - step / 2,
                        Centres[i].second - step / 2,
                        Centres[i].first + step / 2,
                        Centres[i].second + step / 2);
            } else if (object == 3) {
              Spots[i].type = 3;
              Spots[i].x_ = Centres[i].first;
              Spots[i].y_ = Centres[i].second;
              Spots[i].color_ = Fire;
              brush = CreateSolidBrush(Fire);
              SelectObject(hDC, brush);
              POINT points[3];
              points[0].x = Centres[i].first - step / 2;
              points[0].y = Centres[i].second + step / 2;
              points[1].x = Centres[i].first + step / 2;
              points[1].y = Centres[i].second + step / 2;
              points[2].x = Centres[i].first + step / 4;
              points[2].y = Centres[i].second - step / 2;
              Polygon(hDC, points, 3);
            } else {
              Spots[i].type = 4;
              Spots[i].x_ = Centres[i].first;
              Spots[i].y_ = Centres[i].second;
              Spots[i].color_ = OrangeRed;
              brush = CreateSolidBrush(OrangeRed);
              SelectObject(hDC, brush);
              Ellipse(hDC, Centres[i].first - step / 2,
                      Centres[i].second - step / 2, Centres[i].first + step / 2,
                      Centres[i].second + step / 2);
            }
          }
          start = 0;
        }
        if (!start) {
          for (int i = 0; i < Spots.size(); i++) {
            if (Spots[i].type == 1) {
              brush = CreateSolidBrush(Spots[i].color_);
              SelectObject(hDC, brush);
              Ellipse(hDC, Spots[i].x_ - step / 2, Spots[i].y_ - step / 2,
                      Spots[i].x_ + step / 2, Spots[i].y_ + step / 2);
            } else if (Spots[i].type == 2) {
              brush = CreateSolidBrush(Spots[i].color_);
              SelectObject(hDC, brush);
              Rectangle(hDC, Spots[i].x_ - step / 2, Spots[i].y_ - step / 2,
                      Spots[i].x_ + step / 2, Spots[i].y_ + step / 2);
            } else if (Spots[i].type == 3) {
              brush = CreateSolidBrush(Fire);
              SelectObject(hDC, brush);
              POINT points[3];
              points[0].x = Spots[i].x_ - step / 2;
              points[0].y = Spots[i].y_ + step / 2;
              points[1].x = Spots[i].x_ + step / 2;
              points[1].y = Spots[i].y_ + step / 2;
              points[2].x = Spots[i].x_ + step / 4;
              points[2].y = Spots[i].y_ - step / 2;
              Polygon(hDC, points, 3);
            } else {
              brush = CreateSolidBrush(Spots[i].color_);
              SelectObject(hDC, brush);
              Ellipse(hDC, Spots[i].x_ - step / 2, Spots[i].y_ - step / 2,
                      Spots[i].x_ + step / 2, Spots[i].y_ + step / 2);
            }
          }
        }
      EndPaint(hWnd, &ps);  
        }
        break;
      UpdateWindow(hWnd);
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
  UNREFERENCED_PARAMETER(lParam);

  switch (message) {
    case WM_INITDIALOG: {
      CHAR text[20];
      CHAR text1[20];
      int radix = 10;
      if (!Spots.empty()) {
        Spots.clear();
      }
      SetDlgItemText(hDlg, IDC_HEIGHT, _itoa(M, text, radix));
      SetDlgItemText(hDlg, IDC_WIDTH, _itoa(N, text1, radix));
    }
      break;
    case WM_COMMAND:
      switch (LOWORD(wParam)) {
         case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
          break;
        case IDOK: {
          CHAR text[20];
          GetDlgItemText(hDlg, IDC_WIDTH, text, sizeof(text));
          CHAR text1[20];
          GetDlgItemText(hDlg, IDC_HEIGHT, text1, sizeof(text1));
          if (atoi(text1) > 19 || atoi(text) > 19 || atoi(text1) <= 2 ||
              atoi(text) <= 2) {
           MessageBox(hDlg, _T("Not correct info"), _T("ERROR"),
                       MB_ICONEXCLAMATION);
          } else {
            start = 1;
            N = atoi(text);
            M = atoi(text1);
            if (Spots.empty()) {
              for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                  Spot spot(i, j);
                  Spots.push_back(spot);
                }
              }
            }
            EndDialog(hDlg, TRUE);
          }
        } break;
      }
  }
  return (INT_PTR)FALSE;
} 
void SelectColor(HWND hwnd, COLORREF& color) {
  static CHOOSECOLOR ccs;
  static COLORREF acrCustClr[16];
  ccs.lStructSize = sizeof(CHOOSECOLOR);
  ccs.hwndOwner = hwnd;
  ccs.rgbResult = color;
  ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
  ccs.lpCustColors = (LPDWORD)acrCustClr;
  if (ChooseColor(&ccs) == TRUE) {
    color = ccs.rgbResult;
  }
}
void InitCentres(std::vector<std::pair<int, int>>& Centres, int MatrixX,
                 int MatrixY) {
  if (!Centres.empty()) {
    Centres.clear();
  }
  for (int i = 0; i < MatrixY; i++) {
    for (int j = 0; j < MatrixX; j++) {
      Centres.push_back(
          std::make_pair(j * step + step / 2+shift_x, i * step + step / 2+shift_y));
    }
  }
}