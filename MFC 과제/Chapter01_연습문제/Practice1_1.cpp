#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	/*const char * ������ ���� ����Ͽ� "LPTSTR" ������ ����Ƽ�� �ʱ�ȭ�� �� ����. (VS 2017)
	"EasyText" ��� LPTSTR("EasyText")�� ����ϴ�.*/
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
	LPTSTR szMsg2 = LPTSTR("Ű���尡 ���������ϴ�.");
	LPTSTR szMsg3 = LPTSTR("Ű���尡 ���������ϴ�.");

	// �������� 1�� ���ڿ� ���� szMsg4, szMsg5
	LPTSTR szMsg4 = LPTSTR("���콺�� ���������ϴ�.");
	LPTSTR szMsg5 = LPTSTR("���콺�� �̵� ���Դϴ�.");

	// �������� 2��
	POINT MousePoint;	// ���콺 ��ǥ�� ������ POINT���� ����
	LPTSTR szMsg6 = new char[10];	// �޽����� ����� ���ڿ� ����

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));	//�����ڵ� ��� ��Ƽ����Ʈ �������� ���.
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
		MessageBox(hwnd, "���콺 ���� Ŭ��!", "���콺�޽���", MB_OK | MB_ICONASTERISK);
		break;

		// ���콺 ���� ��ư�� �������� ��
	case WM_LBUTTONDOWN:	
		hdc = GetDC(hwnd);	// ����̽� ���ؽ�Ʈ �ڵ� ���
		GetClientRect(hwnd, &rect);	// �簢�� ����ü ��ǥ���ϱ�
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);	// ȭ�� �߾ӿ� szMsg4 ���
		
		// �������� 2
		MousePoint.x = LOWORD(lParam);	// ���콺 x��ǥ��
		MousePoint.y = HIWORD(lParam);	// ���콺 y��ǥ��
		wsprintf(szMsg6, "X:%ld, Y:%ld", MousePoint.x, MousePoint.y);	// szMsg6, X:%ld, Y:%ld ���Ŀ� ���콺 x, y��ǥ�� �̿�
		TextOut(hdc, MousePoint.x, MousePoint.y, szMsg6, strlen(szMsg6));	// ���콺 ��ġ�� szMsg6 ���

		ReleaseDC(hwnd, hdc);	// ����̽� ���ؽ�Ʈ ����
		break;

		// ���콺 ���� ��ư�� �������� ��
	case WM_LBUTTONUP:	
		InvalidateRect(hwnd, NULL, true);	// ������ Ŭ���̾�Ʈ ���� �ٽ� �׸���
		break;
	
		// ���콺�� �̵� ���϶�
		// WM_LBUTTONDOWN case�� ���ڿ� ������ ���� ����
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