#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <string>

#include "resource.h"
#include "MyContainer.h"
#include "Iterator.h"
#include "Visitor.h"
#include "SumVisitor.h"
#include "VisitorToString.h"

class EditView {
 public:
  EditView(HWND hDlg_, UINT ID, MyContainer* model_)
      : hDlg(hDlg_), editID(ID), model(model_){};
  void update() {
    std::string str;
    VisitorToString vts;
    model->Accept(&vts);
    str = vts.GetString();
    SetDlgItemText(hDlg, editID, str.c_str());
  }

 private:
  HWND hDlg;
  UINT editID;
  MyContainer* model;
};
class EditViewSet {
public:
 EditViewSet(HWND hDlg_, UINT ID, MyContainer* model_)
  : hDlg(hDlg_), editID(ID), model(model_) {};
 void update() {
  std::string str;
  str = model->ToStringSet();
  SetDlgItemText(hDlg, editID, str.c_str());
 }

private:
 HWND hDlg;
 UINT editID;
 MyContainer* model;
};

INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam,
                            LPARAM lParam) {
  static MyContainer model;
  static EditView view(hDlg, IDC_EDIT_ARRAY, &model);
  static EditViewSet view1(hDlg, IDC_EDIT_SET, &model);
  switch (message) {
    case WM_INITDIALOG: {
      //view.update();
      return (INT_PTR)TRUE;
    } break;

    case WM_COMMAND:
      switch (LOWORD(wParam)) {
      case IDC_TOFILE: {
       model.save("Text.txt");
      }break;
        case IDC_BUTTON1: {
          int data;
          data = GetDlgItemInt(hDlg, IDC_EDIT_ADD, NULL, true);
          model.add(data);
          view.update();
          view1.update();
          SetDlgItemText(hDlg, IDC_EDIT_ADD, "");
        } break;
        case IDC_CARDINALITY: {
          char buf[100];
          CardinalityVisitor vst;
          model.Accept(&vst);
          wsprintf(buf, "Cardinality = %d", vst.GetCardinality());
          MessageBox(0, TEXT(buf), TEXT("CARDINALITY"), MB_OK);
        } break;
      }
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
      }
  }
  UNREFERENCED_PARAMETER(lParam);
  return (INT_PTR)FALSE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow) {
  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Controller);
  return 0;
} 