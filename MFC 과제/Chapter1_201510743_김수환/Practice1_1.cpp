#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	/*const char * 형식의 값을 사용하여 "LPTSTR" 형식의 엔터티를 초기화할 수 없음. (VS 2017)
	"EasyText" 대신 LPTSTR("EasyText")를 썼습니다.*/
	static LPTSTR szAppName = LPTSTR("EasyText");
	static LPTSTR szTitleName = LPTSTR("Practice1-1");

	HWND hwnd;
	MSG msg;
	WNDCLASSEX WndClass;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = szAppName;
	WndClass.hIconSm = 0;

	RegisterClassEx(&WndClass);

	hwnd = CreateWindow
	(szAppName, szTitleName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	LPTSTR szMsg1 = LPTSTR("I love Window Programming!");
	LPTSTR szMsg2 = LPTSTR("키보드가 눌러졌습니다.");
	LPTSTR szMsg3 = LPTSTR("키보드가 떼어졌습니다.");

	// 연습문제 1번 문자열 변수 szMsg4, szMsg5
	LPTSTR szMsg4 = LPTSTR("마우스가 눌러졌습니다.");
	LPTSTR szMsg5 = LPTSTR("마우스가 이동 중입니다.");

	// 연습문제 2번
	POINT MousePoint;	// 마우스 좌표를 저장할 POINT형식 변수
	LPTSTR szMsg6 = new char[10];	// 메시지를 출력할 문자열 변수

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));	//유니코드 대신 멀티바이트 문자집합 사용.
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hwnd, "마우스 더블 클릭!", "마우스메시지", MB_OK | MB_ICONASTERISK);
		break;

		// 마우스 왼쪽 버튼이 눌러졌을 때
	case WM_LBUTTONDOWN:	
		hdc = GetDC(hwnd);	// 디바이스 컨텍스트 핸들 얻기
		GetClientRect(hwnd, &rect);	// 사각형 구조체 좌표구하기
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);	// 화면 중앙에 szMsg4 출력
		
		// 연습문제 2
		MousePoint.x = LOWORD(lParam);	// 마우스 x좌표값
		MousePoint.y = HIWORD(lParam);	// 마우스 y좌표값
		wsprintf(szMsg6, "X:%ld, Y:%ld", MousePoint.x, MousePoint.y);	// szMsg6, X:%ld, Y:%ld 형식에 마우스 x, y좌표값 이용
		TextOut(hdc, MousePoint.x, MousePoint.y, szMsg6, strlen(szMsg6));	// 마우스 위치에 szMsg6 출력

		ReleaseDC(hwnd, hdc);	// 디바이스 컨텍스트 해제
		break;

		// 마우스 왼쪽 버튼이 떼어졌을 때
	case WM_LBUTTONUP:	
		InvalidateRect(hwnd, NULL, true);	// 윈도우 클라이언트 영역 다시 그리기
		break;
	
		// 마우스가 이동 중일때
		// WM_LBUTTONDOWN case와 문자열 변수만 빼고 같음
	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}