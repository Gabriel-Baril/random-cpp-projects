#include <windows.h>
#define FILE_MENU_NEW 1
#define FILE_MENU_SAVE 2
#define FILE_MENU_OPEN 3
#define FILE_MENU_EXIT 4
#define FILE_MENU_HELP 5
#define FILE_MENU_OPTIONS 6
#define FILE_MENU_PROJECTS 7
#define CHANGE_TITLE 8

/*
The windows API made it not just MessageBox , but many different functions of message box such as MessageBoxA which is being used in the video ,but the one that is trying to be used is MessageBoxW probably so you can't put in the "TEXT" for the type it is looking for. So instead of putting MessageBox just place an A after Box. MessageBoxA looks for text while MessageBoxW looks for type LPCWSTR and since MessageBox defaults to MessageBoxW you cannot run the code since "TEXT" or const char[] is not of type LPCWSTR. Also side note, when making any windows applications make sure you change the linker setting to windows applications (Right click Project name->Click Properties->Click Linker->Click System->Click SubSystem->Then change to Windows on ALL CONFIGURATIONS and ALL PLATFORMS ) Even with a blank project Visual Studio 2019 uses the console subsystem which can cause errors when making any windows applications. This is true as of 3/19/20 (Visual Studio 2019 -Version 16.5.0)
*/

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);

HMENU hMenu;
HWND hEdit;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInbs, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // Set the background
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Set the cursor
	wc.hInstance = hInst; // link the instance
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowClass", L"My Window Nname", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 800, 600, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//MessageBoxA(NULL, "BONJOUR", "MY GUI", MB_OK);
	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND: // When a menu button is clicked
		switch (wp)
		{
		case FILE_MENU_OPEN:
			MessageBeep(MB_OK);
			break;
		case FILE_MENU_EXIT:
			DestroyWindow(hWnd);
			break;
		case CHANGE_TITLE:
			wchar_t text[100];
			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, text);
			break;
		}
		break;
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	
	AppendMenu(hSubMenu, MF_STRING, NULL, L"Recent1");
	AppendMenu(hSubMenu, MF_STRING, NULL, L"Recent2");
	AppendMenu(hSubMenu, MF_STRING, NULL, L"Recent3");

	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, L"New");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_SAVE, L"Save");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, L"Open");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, L"Recent");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, CHANGE_TITLE, L"Change Title");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
	AppendMenu(hMenu, MF_STRING, FILE_MENU_HELP, L"Help");
	AppendMenu(hMenu, MF_STRING, FILE_MENU_OPTIONS, L"Options");
	AppendMenu(hMenu, MF_MENUBREAK, NULL, NULL);
	AppendMenu(hMenu, MF_STRING, FILE_MENU_PROJECTS, L"Projects");

	SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd)
{
	CreateWindowW(L"static", L"Enter text here : ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 20, 20, 150, 50, hWnd, NULL, NULL, NULL);
	hEdit = CreateWindowW(L"edit", L"Default Text", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 20, 80, 150, 50, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"button", L"Change Title", WS_VISIBLE | WS_CHILD, 300, 20, 150, 30, hWnd, (HMENU)CHANGE_TITLE, NULL, NULL);
	
}