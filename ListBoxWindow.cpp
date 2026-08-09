// ListBoxWindow.cpp

#include "ListBoxWindow.h"

// Global variables
static HWND g_hWndListBox;

int ListBoxWindowAddText( LPCTSTR lpszText )
{
	// Add text to list box window
	return SendMessage( g_hWndListBox, LB_ADDSTRING, ( WPARAM )NULL, ( LPARAM )lpszText );

} // End of function ListBoxWindowAddText

BOOL ListBoxWindowCreate( HWND hWndParent, HINSTANCE hInstance, HFONT hFont )
{
	BOOL bResult = FALSE;

	// Create list box window
	g_hWndListBox = CreateWindowEx( LIST_BOX_WINDOW_EXTENDED_STYLE, LIST_BOX_WINDOW_CLASS_NAME, LIST_BOX_WINDOW_TEXT, LIST_BOX_WINDOW_STYLE, 0, 0, 0, 0, hWndParent, ( HMENU )NULL, hInstance, NULL );

	// Ensure that list box window was created
	if( g_hWndListBox )
	{
		// Successfully created list box window

		// Set list box window font
		SendMessage( g_hWndListBox, WM_SETFONT, ( WPARAM )hFont, ( LPARAM )TRUE );

		// Update return value
		bResult = TRUE;

	} // End of successfully created list box window

	return bResult;

} // End of function ListBoxWindowCreate

BOOL ListBoxWindowMove( int nLeft, int nTop, int nWidth, int nHeight )
{
	// Move list box window
	return MoveWindow( g_hWndListBox, nLeft, nTop, nWidth, nHeight, TRUE );

} // End of function ListBoxWindowMove

int ListBoxWindowPopulate()
{
	int nResult;

	// Add text to list box window
	ListBoxWindowAddText( "1234567890" );
	ListBoxWindowAddText( "qwertyuiop" );
	ListBoxWindowAddText( "asdfghjkl" );
	ListBoxWindowAddText( "zxcvbnm" );

	// Update return value
	nResult = SendMessage( g_hWndListBox, LB_GETCOUNT, ( WPARAM )NULL, ( LPARAM )NULL );

	return nResult;

} // End of function ListBoxWindowPopulate
