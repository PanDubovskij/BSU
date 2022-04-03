// лаб 2 винапи.cpp : Определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#define _USE_MATH_DEFINES

#include<cmath>
#include "framework.h"
#include "лаб 2 винапи.h"
#include <map>
#include <string>
#include <vector>
#include "commdlg.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void SelectColor(HWND hwndDlg, COLORREF& color);
BOOL CALLBACK Edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
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
    LoadStringW(hInstance, IDC_MY2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2);
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
static std::map<std::string, int> diag = {
    {"Gapanovich", 8}, {"Dubovik", 9}, {"Larin", 6}, {"Zelenkovskij", 8}, {"Dubovskij",4}};
static int size_x, size_y;
static int full_mark;
struct Student {
  std::string surname;
  int mark;
};

static std::vector<Student> students;
static int number_students=0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
                         LPARAM lParam) {
 static COLORREF Color;
    switch (message)
    {
    case WM_COMMAND:
        {
            HMENU hMenu = GetMenu(hWnd);
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_CHANGE:
              EnableMenuItem(hMenu, ID_CHANGE, MF_ENABLED);
              SelectColor(hWnd, Color);
              InvalidateRect(hWnd, 0, 1);
              break;
            case ID_FILL: {
              if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd,
                            Edit_R)) {
                InvalidateRect(hWnd, 0, 1);
              }
            }
              break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_SIZE:
      size_x = LOWORD(lParam);
      size_y = HIWORD(lParam);
      break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN pen = CreatePen(PS_DASH, 3, RGB(0, 0, 0));
            SelectObject(hdc, pen);
            MoveToEx(hdc, 20, size_y/2, NULL);
            LineTo(hdc, size_x/3, size_y / 2);
            MoveToEx(hdc, 20, 20, NULL);
            LineTo(hdc, 20, size_y / 2);
            HBRUSH brush =
                CreateSolidBrush(Color);
            SelectObject(hdc, brush);
            int h = 20;
            char text[20];
            int radix = 10;
            int sum=0;
            for (int i = 0; i < number_students; i++) {
              int y = students[i].mark;
              Rectangle(hdc, 20 + h, (size_y / 2) - 20 * y, 40 + h, size_y / 2);
              TextOut(hdc, 20 + h, (size_y / 2) - 23 * y, (students[i].surname).c_str(),
                      (students[i].surname).length());
              TextOut(hdc, 10 + h, (size_y / 2) - 23 * y, _itoa(y, text, radix),
                      strlen(_itoa(y, text, radix)));
              h += 30;
              sum += students[i].mark; 
            }

            double step2 = (2.0 * M_PI) / sum;
            step2 = round(step2 * 10000000) / 10000000;
            double first_angle = 0.0, second_angle = 0.0;
            double x1, x2, y1, y2;
            for (int i = 0; i < number_students; i++) {
              static double xw = size_x * 0.75, yw = size_y * 0.5, r;
              r = min(size_x / 2.2, size_y / 2.2);
              first_angle = second_angle;
              second_angle = students[i].mark * step2 + first_angle;

              x1 = (xw + r * cos(first_angle));
              y1 = (yw - r * sin(first_angle));
              x2 = (xw + r * cos(second_angle));
              y2 = (yw - r * sin(second_angle));

              brush = CreateSolidBrush(Color);
              SelectObject(hdc, brush);
              Pie(hdc, xw - r, yw - r, xw + r, yw + r, x1, y1, x2, y2);

              TextOut(hdc, x1, y1 - size_y / 20, students[i].surname.c_str(),
                      (students[i].surname).length());
              TextOut(
                  hdc, x1 + size_x / 20, y1 - size_y / 20,
                  _itoa(students[i].mark, text, radix),
                  strlen(_itoa(students[i].mark, text, radix)));
            }
            UpdateWindow(hWnd);
            DeleteObject(brush);
            DeleteObject(pen);
            EndPaint(hWnd, &ps);
        }
        break;
        
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
void SelectColor(HWND hwndDlg, COLORREF& color) {
  static CHOOSECOLOR ccs;
  static COLORREF acrCustClr[16];
  ccs.lStructSize = sizeof(CHOOSECOLOR);
  ccs.hwndOwner = hwndDlg;
  ccs.rgbResult = color;
  ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
  ccs.lpCustColors = (LPDWORD)acrCustClr;
  if (ChooseColor(&ccs) == TRUE) color = ccs.rgbResult;
}
BOOL CALLBACK Edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_INITDIALOG:
      SetDlgItemText(hwndDlg, ID_FILL_SURNAME, "Enter surname of a student");
      SetDlgItemText(hwndDlg, IDC_FILL_MARK, "Enter mark of a student");
      break;
    case WM_COMMAND: {
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hwndDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
      }
      switch (LOWORD(wParam)) {
        case IDC_BUTTON_SAVE: {
          CHAR surname[10];
          GetDlgItemText(hwndDlg, ID_FILL_SURNAME, surname, sizeof(surname));
          CHAR text[20];
          int mark;
          GetDlgItemText(hwndDlg, IDC_FILL_MARK, text, sizeof(text));
          mark = atoi(text);
          Student student;
          student.mark = mark;
          student.surname = (std::string)surname;
          students.push_back(student);
          number_students++;
          full_mark += mark;
        }
          break;
         
          return TRUE;
      }
      break;
    }
    case WM_CLOSE:
      EndDialog(hwndDlg, 0);
      break;

    default:
      return false;
  }
}