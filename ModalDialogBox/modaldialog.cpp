//
//  Modal Dialog
//

#include "stdafx.h"
#include "modaldialog.h"

// constructor
CModalDialog::CModalDialog()
{
	hDialog = NULL;
	p = NULL;
}

// destructor
CModalDialog::~CModalDialog()
{
}

// display dialog box
wchar_t*  CModalDialog::Show(HWND hWnd, HINSTANCE hInstance, DLGPROC pDlgProc)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, pDlgProc);

	return p;
}

// dialog procedure
INT_PTR CModalDialog::DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (message)
	{
	case WM_INITDIALOG:

	return (INT_PTR)TRUE;

	case WM_COMMAND:

		switch (LOWORD(wParam)) 
		{
                case IDOK:

					// get the text from the control
					GetDlgItemText(hDlg, IDC_EDIT1, str, 100);

					// set pointer to string str
					p = str;

					// close dialog box
 					EndDialog(hDlg, LOWORD(wParam));

					return (INT_PTR)TRUE;

                case IDCANCEL: 

					// set pointer to null
					p = NULL;

					// close dialog box
					EndDialog(hDlg, LOWORD(wParam));

					return (INT_PTR)TRUE;
		}
	}

	return (INT_PTR)FALSE;
}

//