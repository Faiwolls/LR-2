#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "lib2.h"




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int w = 0, n = 0;
    sobst sbs[sbs_max];

    do {
        printf("\n������� ���-�� ������������� (1-%d): ", sbs_max);
        scanf("%d", &n);
        while (getchar() != '\n');
    } while (n < 1 || n > sbs_max);


    do {
        printf("\n��������� �� �����? (1 - ��, 2 - ���): ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2);
    if (w == 1) sbs->filein(sbs, n);
    else sbs->vvod(sbs, n);
    w = 0;
    do {
        printf("\n�������� � ����? (1 - ��, 2 - ���): ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2);
    if (w == 1) sbs->fileout(sbs, n);
    w = 0;
    do {
        system("cls");
        do {
            printf("\n�������� �����? (1 - ��, 2 - ���): ");
            scanf("%d", &w);
            while (getchar() != '\n');
        } while (w != 1 && w != 2);
        if (w == 1) sbs->poisk(sbs, n);
        system("pause");
    } while (w == 1);

}