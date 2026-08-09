// ListBoxWindow.h

#pragma once

#include <windows.h>
#include <commctrl.h>

#define LIST_BOX_WINDOW_CLASS_NAME												WC_LISTBOX

#define LIST_BOX_WINDOW_EXTENDED_STYLE											0
#define LIST_BOX_WINDOW_STYLE													( WS_CHILD | WS_VISIBLE | LBS_NOINTEGRALHEIGHT )
#define LIST_BOX_WINDOW_TEXT													NULL

int ListBoxWindowAddText( LPCTSTR lpszText );

BOOL ListBoxWindowCreate( HWND hWndParent, HINSTANCE hInstance, HFONT hFont );

BOOL ListBoxWindowMove( int nLeft, int nTop, int nWidth, int nHeight );

int ListBoxWindowPopulate();
