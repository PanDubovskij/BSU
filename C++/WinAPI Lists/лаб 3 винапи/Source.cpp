#include <windows.h>

#include <fstream>
#include <sstream>
#include <string>

#include "resource1.h"


INT_PTR CALLBACK DlgMain(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_INITDIALOG:
      ShowWindow(GetDlgItem(hwnd, IDC_BUTTON9), SW_HIDE);
      break;
    case WM_CLOSE:
      EndDialog(hwnd, 0);
      break;
    case WM_COMMAND:
      switch (LOWORD(wParam)) {
        case IDC_BUTTON1: {
          OPENFILENAME ofn;
          ZeroMemory(&ofn, sizeof(ofn));
          TCHAR FileName[300] = {'\0'};
          ofn.lStructSize = sizeof(ofn);
          ofn.hwndOwner = NULL;
          ofn.lpstrFile = FileName;
          ofn.nMaxFile = sizeof(FileName);
          ofn.lpstrFilter = "All Files\0*.*\0.TXT\0";
          ofn.nFilterIndex = 1;
          ofn.lpstrFileTitle = NULL;
          ofn.nMaxFileTitle = NULL;
          ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
          if (GetOpenFileName(&ofn) == TRUE) {
            std::ifstream in(FileName);

            CHAR str[300];
            std::string temp;
            while (!in.eof()) {
              getline(in, temp);
              SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0,
                                 (LPARAM)temp.c_str());
            }
          }
        } break;

        case IDC_BUTTON6: {
          TCHAR text[256];
          GetDlgItemText(hwnd, IDC_EDIT1, text, 256);
          SetDlgItemText(hwnd, IDC_EDIT1, "");
          SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_ADDSTRING, 0,
                      (LPARAM)text);
          SetFocus(GetDlgItem(hwnd, IDC_EDIT1));
          return TRUE;
        } break;
        case IDC_BUTTON7: {
          TCHAR text[256];
          GetDlgItemText(hwnd, IDC_EDIT1, text, 256);
          SetDlgItemText(hwnd, IDC_EDIT1, "");
          SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_ADDSTRING, 0,
                      (LPARAM)text);
          SetFocus(GetDlgItem(hwnd, IDC_EDIT1));
          return TRUE;
        } break;
         TCHAR text[256];
          static int index;
        case IDC_BUTTON8: {
          index = SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
          SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETTEXT, index,
                      (LPARAM)text);
          SetDlgItemText(hwnd, IDC_EDIT1, text);
          ShowWindow(GetDlgItem(hwnd, IDC_BUTTON8), SW_HIDE);
          ShowWindow(GetDlgItem(hwnd, IDC_BUTTON9), SW_SHOW);        
        } break;
        case IDC_BUTTON9: {
          SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_DELETESTRING, (WPARAM)index,
                        0);
          GetDlgItemText(hwnd, IDC_EDIT1, text, 256);
          SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, (WPARAM)index,
                      (LPARAM)text);
        }
        case IDC_BUTTON3: {
          TCHAR text[256];
          DlgDirSelectExA(hwnd, text, 256, IDC_LIST1);
         SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_ADDSTRING, 0,
                     (LPARAM)text);
         SetFocus(GetDlgItem(hwnd, IDC_LIST1));
          return TRUE;
        } break;
        case IDC_BUTTON4: {
          TCHAR text[256];
          DlgDirSelectExA(hwnd, text, 256, IDC_LIST2);
          SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_ADDSTRING, 0,
                      (LPARAM)text);
          SetFocus(GetDlgItem(hwnd, IDC_LIST2));
          return TRUE;
        } break;
        case IDC_BUTTON5: {
         int k = SendMessage(GetDlgItem(hwnd,IDC_LIST1), LB_GETCURSEL, 0, 0);
          SendMessage(GetDlgItem(hwnd, IDC_LIST1)
                      , LB_DELETESTRING, (WPARAM)k, 0);
         int n = SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_GETCURSEL, 0, 0);
         SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_DELETESTRING, (WPARAM)n,
                     0);
          return TRUE;
        } break;
          case IDC_BUTTON2: {
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            TCHAR FileName[300] = {'\0'};
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = FileName;
            ofn.nMaxFile = sizeof(FileName);
            ofn.lpstrFilter = "All Files\0*.*\0.TXT\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
            if (GetOpenFileName(&ofn) == TRUE) {
              std::ifstream in(FileName);

              CHAR str[300];
              std::string temp;
              while (!in.eof()) {
                getline(in, temp);
                SendDlgItemMessage(hwnd, IDC_LIST2, LB_ADDSTRING, 0,
                                   (LPARAM)temp.c_str());
              }
          } break;
        }
        default:
          break;
      }
      break;
      return TRUE;
    default:
      return FALSE;
      break;
  }
  return TRUE;
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgMain);
  return 0;
}