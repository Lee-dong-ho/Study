#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

#define MAX_LOTTO_NUM   45
#define MIX_COUNT       50
#define Y_GAP           2
#define X_MAX           50
#define RESULT          1
#define HORSERACE       2
#define EXIT            3

vector<int> hspeed(MAX_LOTTO_NUM);

void MakeLottoNum()
{
    for(int i=0; i < hspeed.size(); i++) hspeed[i] = i + 1;
    mt19937 gen(time(NULL));
    uniform_int_distribution<int> dis(0, MAX_LOTTO_NUM-1);
    int temp, x, y;
    for(int i=0; i < MIX_COUNT; i++)
    {
        x = dis(gen);
        y = dis(gen);
        if (x != y)
        {
            temp = hspeed[x];
            hspeed[x] = hspeed[y];
            hspeed[y] = temp;
        }
    }
}

void gotoxy(int x, int y)
{
    COORD Cursor = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

void PrintRace()
{
    vector<int> finished(hspeed.size());
    vector<int> horse(MAX_LOTTO_NUM);
    for(int i=0; i < MAX_LOTTO_NUM; i++) horse[i] = i+1;
    int x, finish_cnt = 0;
    int t = -1;
    vector<int> fhorse;
    do
    {        
        t++;
        for(int i=0; i < MAX_LOTTO_NUM; i++)
        {
            if(finished[i]) continue;
            if(hspeed[i]*t/MAX_LOTTO_NUM >= X_MAX - 3)
            {
                finished[i] = 1;
                finish_cnt++;
                gotoxy(X_MAX - 3, i*Y_GAP);
                printf("[%2d]", horse[i]);
                fhorse.push_back(horse[i]);
                gotoxy(X_MAX + 5, 7);
                for(int j=0; j < fhorse.size(); j++)
                    printf("%2d  ", fhorse[j]);
                if(finish_cnt >= 7) break;
            }
            else
            {
                gotoxy(hspeed[i]*t/MAX_LOTTO_NUM, i*Y_GAP);
                printf("[%2d]", horse[i]);
            }            
        }
        Sleep(100);
        for(int i=0; i < MAX_LOTTO_NUM; i++)
        {
            if(finished[i]) continue;
            gotoxy(hspeed[i]*t/MAX_LOTTO_NUM, i*Y_GAP);
            printf("    ");
        }
    } while (finish_cnt < 7);    
}

void HorseRaceStart()
{
    system("mode con: cols=100 lines=100");
    for(int i=0; i < MAX_LOTTO_NUM; i++)
    {
        gotoxy(0, i*Y_GAP + 1);
        for(int j=0; j < X_MAX; j++) printf("=");
        gotoxy(X_MAX + 1, i);
        printf("|");
        gotoxy(X_MAX + 1, i + MAX_LOTTO_NUM);
        printf("|");
    }
    gotoxy(X_MAX + 5, 5);
    printf("Today Lotto Number");
    PrintRace();
}

void PrintResult()
{
    printf("\n\n");
    printf("     Today Lotto Number\n   ");
    for(int i=0; i < 6; i++) printf("  %2d", hspeed[i]);
    printf("   + %2d", hspeed[6]);
}

void CmdInit()
{
    system("title LOTTO");
    system("mode con: cols=50 lines=15");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void DrawInitWindow()
{
    printf("\n\n\n\n");
    printf("     ##       ###    ######  ######   ###\n");
    printf("     ##      #   #     ##      ##    #   #\n");
    printf("     ##      #   #     ##      ##    #   #\n");
    printf("     #####    ###      ##      ##     ###\n\n");
    printf("                  1. Start\n");
    printf("                  2. Race\n");
    printf("                  3. Exit\n");
}

int keyControl()
{
    char temp = _getch();
    if(temp == '1') return RESULT;
    else if (temp == '2') return HORSERACE;
    else if (temp == '3') return EXIT;
    return -1;
}

int main()
{
    // 1부터 45까지 6개 숫자 + 보너스 1개
    CmdInit();
    while(1)
    {
        system("cls");
        DrawInitWindow();
        int keycode = keyControl();
        MakeLottoNum();
        switch(keycode)
        {
            case HORSERACE:
                system("cls");
                HorseRaceStart();
                system("PAUSE>null");
            break;
            case RESULT:
                system("cls");
                PrintResult();
                system("PAUSE>null");
            break;
            case EXIT:
                return 1;
            break;
        }
    }
    return 1;
}