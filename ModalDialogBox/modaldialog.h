//
//  Modal Dialog
//

#pragma once

#include "resource.h"

class CModalDialog
{
private:
	HWND hDialog;
	wchar_t str[100];
	wchar_t* p;

public:
	CModalDialog();
	~CModalDialog();

	wchar_t*  Show(HWND hWnd, HINSTANCE hInstance, DLGPROC pDlgProc);
	INT_PTR DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

