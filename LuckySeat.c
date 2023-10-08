/*LuckySeat is for teachers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <windows.h>

#define ID_InBox         101
#define ID_OutBox        102
#define ID_LuckyButton   103
#define ID_ViewButton    104


HINSTANCE hInst;
HWND hInBox, hOutBox, hLuckyButton, hViewButton;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        PSTR szCmdLine, int iCmdShow)
{ 
    HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;
    char *title = "LuckySeat v 1.0  Copyright [C] 2018 - 2023 "\
                   "David He(老何)  e-mail: david_he2008@126.com";

    wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = NULL;
	wndclass.lpszClassName = TEXT("LuckySeat");
	if(!RegisterClass(&wndclass))
	{
        return 0;
	}
    hwnd = CreateWindow(TEXT("LuckySeat"),
            title,
            WS_OVERLAPPEDWINDOW,
            0,
            0,
            1024,
            690,
            NULL,
            NULL,
            hInstance,
            NULL);

    ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
		DispatchMessage(&msg);
    }

    return msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    char *app_name = "LuckySeat v 1.0";
    char *mottoA = "每棵苗都需要阳光雨露！";
    char *mottoB = "教育公平从这里开始！";
    char *input ="请输入学生人数：";

    LOGFONT logFont;
    HFONT hFont, hFontOld;
      
    switch (message)
    {
        case WM_CREATE:
            hInBox = CreateWindow("EDIT",
                    NULL,
                    WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER |
                    ES_AUTOHSCROLL,
                    260,
                    180,
                    200,
                    36,
                    hwnd,
                    (HMENU)ID_InBox,
                    hInst,
                    NULL);

            hLuckyButton = CreateWindow("BUTTON",
                    TEXT("开始摇号"),
                    WS_CHILD | WS_VISIBLE,
                    640,
                    180,
                    128,
                    40,
                    hwnd,
                    (HMENU)ID_LuckyButton,
                    hInst,
                    NULL);
            hViewButton = CreateWindow("BUTTON",
                    TEXT("查看结果"),
                    WS_CHILD | WS_VISIBLE,
                    820,
                    180,
                    128,
                    40,
                    hwnd,
                    (HMENU)ID_ViewButton,
                    hInst,
                    NULL);


            hOutBox = CreateWindow("EDIT",
                    NULL,
                    WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER | ES_MULTILINE | 
                    WS_VSCROLL | WS_HSCROLL | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                    20,
                    250,
                    960,
                    380,
                    hwnd,
                    (HMENU)ID_OutBox,
                    hInst,
                    NULL);

            hdc = GetDC(hwnd);
            logFont.lfHeight = MulDiv(20, GetDeviceCaps(hdc, LOGPIXELSY), 72);
            ReleaseDC(hwnd, hdc);
            logFont.lfWidth = 0;
            logFont.lfEscapement = 0;
            logFont.lfOrientation = 0;
            logFont.lfWeight = FW_REGULAR;
            logFont.lfItalic = 0;
            logFont.lfUnderline = 0;
            logFont.lfStrikeOut = 0;
            logFont.lfCharSet = GB2312_CHARSET;
            logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
            logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
            logFont.lfQuality = PROOF_QUALITY;
            logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
            strcpy(logFont.lfFaceName, "宋体");
            hFont = CreateFontIndirect(&logFont);
            SendMessage(hLuckyButton, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hViewButton, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hInBox, WM_SETFONT, (WPARAM)hFont, TRUE);

            hdc = GetDC(hwnd);
            logFont.lfHeight = MulDiv(16, GetDeviceCaps(hdc, LOGPIXELSY), 72);
            ReleaseDC(hwnd, hdc);
            logFont.lfWidth = 0;
            logFont.lfEscapement = 0;
            logFont.lfOrientation = 0;
            logFont.lfWeight = FW_REGULAR;
            logFont.lfItalic = 0;
            logFont.lfUnderline = 0;
            logFont.lfStrikeOut = 0;
            logFont.lfCharSet = GB2312_CHARSET;
            logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
            logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
            logFont.lfQuality = PROOF_QUALITY;
            logFont.lfPitchAndFamily = VARIABLE_PITCH  | FF_ROMAN;
            strcpy(logFont.lfFaceName, "宋体");
            hFont = CreateFontIndirect(&logFont);
            SendMessage(hOutBox, WM_SETFONT, (WPARAM)hFont, TRUE);

            break;

        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            GetClientRect(hwnd, &rect);
            SetBkMode(hdc, TRANSPARENT);

            hFont = CreateFont(32,
                    16,
                    0,
                    0,
                    FW_REGULAR,
                    FALSE,
                    FALSE,
                    FALSE,
                    GB2312_CHARSET,
                    OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS,
                    PROOF_QUALITY,
                    FIXED_PITCH | FF_MODERN,
                    "宋体");
            hFontOld = (HFONT)SelectObject(hdc, hFont);
            SetTextColor(hdc, RGB(0, 0, 255));
            TextOut(hdc, 330, 20, app_name, strlen(app_name));
            TextOut(hdc, 330, 65, mottoA, strlen(mottoA));
            TextOut(hdc, 330, 110, mottoB, strlen(mottoB));
            TextOut(hdc, 20, 180, input, strlen(input));
            SelectObject(hdc, hFontOld);
            DeleteObject(hFont);

            EndPaint(hwnd, &ps);
            break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_InBox:
                    if(HIWORD(wParam) == EN_SETFOCUS)
                    {
                        SetFocus(hInBox);
                    }
                    break;

                case ID_OutBox:
                    if(HIWORD(wParam) == EN_SETFOCUS)
                    {
                        SetFocus(hOutBox);
                    }
                    break;

                case ID_LuckyButton:
                    unsigned int seed = 0;
                    struct _timeb timeBuf;
                    int  i = 0, j = 0, stu_qty = 0, count = 0;
                    long in_len = 0, str_len = 0;

                    char *str_input = (char *)malloc(1024);
                    memset(str_input, 0, 1024);

                    char *temp = (char *)malloc(1024);
                    memset(temp, 0, 1024);

                    unsigned long *result = (unsigned long *)
                        malloc(20000 * sizeof(unsigned long));
                    memset(result, 0, 20000 * sizeof(unsigned long));

                    char *buffer = (char *)malloc(1048576);
                    memset(buffer, 0, 1048576);

                   
                    in_len = GetWindowTextLength(hInBox) + 1;
                    GetWindowText(hInBox, str_input, in_len);
                    stu_qty = atoi(str_input);
                    if((stu_qty <= 0) || (stu_qty > 10000) ||
                            (strlen(itoa(stu_qty, temp, 10)) != 
                             strlen(str_input)))
                    {
                        
                        Beep(1200, 100);
                        MessageBox(NULL, "请输入10000以内的正整数 !",
                                "温馨提示!", MB_OK);
                        break;
                    }

                    _ftime(&timeBuf);
                    seed = ((((unsigned int)timeBuf.time&0xFFFF) 
                                + (unsigned int)timeBuf.millitm)
                            ^ (unsigned int)timeBuf.millitm);
                    srand((unsigned int)seed);
                    for(i = 0; i < stu_qty; ++i)
                    {
                        *(result + i) = rand()%(stu_qty + 1);
                        if(*(result +i) < 1 || *(result + i) > stu_qty)
                        {
                            --i;
                            continue;
                        }
                        for(j = 0; j < i; ++j)
                        {
                            if(*(result + i) == *(result + j))
                            {
                                --i;
                            }
                        }
                    }

                    str_len += sprintf(buffer + str_len, "温馨提示：摇号之前，"\
                            "请先把座位编号，摇号结果同步输出到 result.txt "\
                            "文件！\r\n摇号结果：(学号->座号)\r\n\r\n");
                    for(i = 0; i < stu_qty; ++i)
                    {
                        str_len += sprintf(buffer + str_len, "(学%d->座%lu), ",
                                (i + 1), *(result + i));
                        count++;
                        if(count % 10 == 0)str_len += sprintf(buffer + str_len,
                                "\r\n");
                    }

                    SetWindowText(hOutBox, buffer);
                    if(strlen(buffer))
                    {
                        FILE *fp = fopen("result.txt", "w");
                        if(fp == NULL)
                        {
                            MessageBox(NULL, "未能把摇号结果保存到文件!",
                                    "温馨提示!", MB_OK);
                            return 1;
                        }
                        fputs(buffer, fp);
                        fclose(fp);
                    }
                    ShellExecuteA(0, "open", "result.txt", 0, 0, 1);

                    free(str_input);
                    free(temp);
                    free(result);
                    free(buffer);

                    break;
                    
                case ID_ViewButton:
                    ShellExecuteA(0, "open", "result.txt", 0, 0, 1);
                    break;

            }

            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);

}
