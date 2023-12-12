#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "lib1.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	int w = 0, n = 0;
	struct sobst sbs[sbs_max];

	do {
		printf("\nВведите кол-во собственников (1-%d): ", sbs_max);
		scanf("%d", &n);
		while (getchar() != '\n');
	} while (n < 1 || n > sbs_max);

	do {
		printf("\nХотите считать из файла? (1 - да, 2 - нет): ");
		scanf("%d", &w);
		while (getchar() != '\n');
	} while (w != 1 && w != 2);
	if (w == 1) filein(sbs, n);
	else if (w == 2) vvod(sbs, n);

	do {
		printf("\nЗаписать в файл? (1 - да, 2 - нет): ");
		scanf("%d", &w);
		while (getchar() != '\n');
	} while (w != 1 && w != 2);
	if (w == 1) fileout(sbs, n);

	do {
		system("cls");
		poisk(sbs, 2);
		printf("\n\nПоиск завершен");
		printf("\n\nЕще поиск? (1 - да, 2 - нет):  ");
		scanf("%d", &w);
		while (getchar() != '\n');
	} while (w == 1);



}

