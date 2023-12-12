// ООП. Лаба 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <windows.h>
#include<string.h>
#include "lib1.h"


void prnsobforma(struct sobst asbs)
{
	switch (asbs.sobstforma) {
	case 1: printf("Фирма"); break;
	case 2: printf("Государственная"); break;
	case 3: printf("Физлицо"); break;
	}
}

void prnstortype(struct storage stor)
{
	switch (stor.sttype) {
	case 1: printf("Продовольственный"); break;
	case 2: printf("Хозяйственный"); break;
	}
}

void vvod(struct sobst asbs[], int kol) {
	int i = 0, n = 0, ip = 0, ih = 0, it = 0;
	int pk = 0, d;

	// главный цикл ввода собственников
	for (i = 0; i < kol; i++) {
		system("cls");
		printf("\n=== Ввод собственника: -%d- ===\n", i + 1);
		printf("\nВведите номер: ");
		scanf("%d", &asbs[i].sobstnum);
		while (getchar() != '\n');
		printf("\nВведите название: ");
		gets_s(asbs[i].sobstname, 30);
		printf("\nВведите форму собственности (1 - фирма, 2 - гос, 3 - физлицо): ");
		scanf("%d", &d);
		while (getchar() != '\n');
		switch (d) {
		case 1: asbs[i].sobstforma = Firma; break;
		case 2: asbs[i].sobstforma = Gos; break;
		case 3: asbs[i].sobstforma = Fislitso; break;
		};
		printf("\nВведите кол-во продовольственных складов: ");
		scanf("%d", &asbs[i].prodkol);

		// цикл ввода продовольственных складов i-го собственника
		for (ip = 0; ip < asbs[i].prodkol; ip++) {
			printf("\n--- Ввод прод склада: -%d- ---\n", ip + 1);
			printf("\nВведите номер: ");
			scanf("%d", &asbs[i].prodsp[ip].stnum);
			while (getchar() != '\n');
			asbs[i].prodsp[ip].sttype = StProdov;
			printf("\nВведите кол-во видов товара на складе %d: ", asbs[i].prodsp[ip].stnum, ": ");
			scanf("%d", &asbs[i].prodsp[ip].tovkol);
			while (getchar() != '\n');

			// цикл ввода товара ip-го склада i-го собственника
			for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
				printf("\nВведите номер товара: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\nВведите наименование товара: ");
				gets_s(asbs[i].prodsp[ip].tovars[it].tovname, 30);
				printf("\nВведите кол-во данного товара: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tkol);
				while (getchar() != '\n');
			}

		}

		printf("\nВведите кол-во хозяйственных складов: ");
		scanf("%d", &asbs[i].hoskol);
		while (getchar() != '\n');

		// цикл ввода хозяйственных складов i-го собственника
		for (ih = 0; ih < asbs[i].hoskol; ih++) {
			printf("\n--- Ввод хоз склада: -%d- ---\n", ih + 1);
			printf("\nВведите номер: ");
			scanf("%d", &asbs[i].hossp[ih].stnum);
			while (getchar() != '\n');
			asbs[i].hossp[ih].sttype = StHosyast;
			printf("\nВведите кол-во видов товара на складе %d: ", asbs[i].hossp[ih].stnum, ": ");
			scanf("%d", &asbs[i].hossp[ih].tovkol);
			while (getchar() != '\n');

			// цикл ввода товара ih-го склада i-го собственника
			for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
				printf("\nВведите номер товара: ");
				scanf("%d", &asbs[i].hossp[ih].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\nВведите наименование товара: ");
				gets_s(asbs[i].hossp[ih].tovars[it].tovname, 30);
				printf("\nВведите кол-во данного товара: ");
				scanf("%d", &asbs[i].hossp[ih].tovars[it].tkol);
				while (getchar() != '\n');
			}


		}

		asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
	}


}

void poisk(struct sobst asbs[], int kol) {
	setlocale(LC_CTYPE, "Russian");
	int i = 0, n = 0, ip = 0, ih = 0, it = 0;
	int pk = 0, d, z, q, sobstnum, prodkol, hoskol, sobstforma, stnum, sttype, tovkol;
	char sobstname[50];
	system("cls");
	printf("Выберите с какого уровня хотите провести поиск (1 уровень - Структура собственника, 2 уровень - структура склада, 3 уровень - структура товара): \n");
	scanf("%d", &z);
	switch (z)
	{
	case 1:
		printf("\nВыберите поле по которому хотите провести поиск (1 - по номеру собственника, 2 - по имени собственника, 3 - по форме собственности\n, 4 - вывод информации о продовольственных складах, 5 - вывод информации о хозяйственных складах): \n");
		scanf("%d", &d);
		switch (d)
		{
		case 1:
			printf("\nВведите номер собственника: \n");
			scanf("%d", &sobstnum);
			for (i = 0; i < kol; i++) {
				if (sobstnum == asbs[i].sobstnum) {
					printf("\n---Информация по %d собственнику---", i + 1);
					printf("\nНаименование собственника: %s", asbs[i].sobstname);
					printf("\nФорма собственности: ");
					prnsobforma(asbs[i]);
					printf("\nКоличество продовольственных складов собственника: %d", asbs[i].prodkol);
					printf("\nКоличество хозяйственных складов собственника: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\nНомер склада: %d", asbs[i].prodsp[ip].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\nКоличество видов товаров на %d складе: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("Количество в наличии: %d\n", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\nНомер склада: %d", asbs[i].hossp[ih].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 2:
			printf("\nВведите наименование собственника: \n");
			while (getchar() != '\n');
			gets_s(sobstname);
			for (i = 0; i < kol; i++) {
				if (strcmp(sobstname, asbs[i].sobstname) == 0) {
					printf("\n---Информация по %d собственнику---", i + 1);
					printf("\nНомер собственника: %d", asbs[i].sobstnum);
					printf("\nНаименование собственника: %s", asbs[i].sobstname);
					printf("\nФорма собственности: ");
					prnsobforma(asbs[i]);
					printf("\nКоличество продовольственных складов собственника: %d", asbs[i].prodkol);
					printf("\nКоличество хозяйственных складов собственника: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\nНомер склада: %d", asbs[i].prodsp[ip].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\nНомер склада: %d", asbs[i].hossp[ih].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 3:
			printf("\nВведите форму собственности для поиска(1-фирма,2-гос.предприятие,3-физическое лицо):\n");
			scanf("%d", &q);
			for (i = 0; i < kol; i++) {
				if (asbs[i].sobstforma == q) {
					printf("\n---Информация по %d собственнику---", i + 1);
					printf("\nНомер собственника: %d", asbs[i].sobstnum);
					printf("\nНаименование собственника: %s", asbs[i].sobstname);
					printf("\nФорма собственности: ");
					prnsobforma(asbs[i]);
					printf("\nКоличество продовольственных складов собственника: %d", asbs[i].prodkol);
					printf("\nКоличество хозяйственных складов собственника: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\nНомер склада: %d", asbs[i].prodsp[ip].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\nНомер склада: %d", asbs[i].hossp[ih].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}


			break;
			q = 0;
		case 4:
			printf("\nВведите кол-во продовольственных складов: ");
			scanf("%d", &prodkol);
			for (i = 0; i < kol; i++) {
				if (prodkol == asbs[i].prodkol) {
					printf("\n---Информация по %d собственнику---", i + 1);
					printf("\nНомер собственника: %d", asbs[i].sobstnum);
					printf("\nНаименование собственника: %s", asbs[i].sobstname);
					printf("\nФорма собственности: ");
					prnsobforma(asbs[i]);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\nНомер склада: %d", asbs[i].prodsp[ip].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 5:
			printf("\nВведите кол-во хозяйственных складов: \n");
			scanf("%d", &hoskol);
			for (i = 0; i < kol; i++) {
				if (hoskol == asbs[i].hoskol) {
					printf("\n---Информация по %d собственнику---", i + 1);
					printf("\nНомер собственника: %d", asbs[i].sobstnum);
					printf("\nНаименование собственника: %s", asbs[i].sobstname);
					printf("\nФорма собственности: ");
					prnsobforma(asbs[i]);
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\nНомер склада: %d", asbs[i].hossp[ih].stnum);
						printf("\nТип склада: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\nКоличество товаров на %d складе: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;


		default:
			break;
		}

		break;
	case 2:
		printf("\nВведите тип склада для поиска(1-продовольственный,2-хозяйственный):\n");
		scanf("%d", &sttype);
		switch (sttype)
		{
		case 1:
			printf("\nВведите номер продовольственного склада для поиска:\n");
			scanf("%d", &stnum);
			for (i = 0; i < kol; i++) {
				for (ip = 0; ip < asbs[i].prodkol; ip++) {
					if (stnum == asbs[i].prodsp[ip].stnum) {
						printf("\nКоличество товаров на %d складе: %d", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 2:
			printf("\nВведите номер хозяйствееного склада для поиска:\n");
			scanf("%d", &stnum);
			for (i = 0; i < kol; i++) {
				for (ih = 0; ih < asbs[i].hoskol; ih++) {
					if (stnum == asbs[i].hossp[ih].stnum) {
						printf("\nКоличество товаров на %d складе: %d", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\nНомер товара: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\nНаименование товара: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\nКоличество в наличии: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;

		default:
			break;
		}
		break;
	}

}

void filein(struct sobst asbs[], int kol) {
	setlocale(LC_CTYPE, "Russian");
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	char k[40];
	char sobstname[30];
	fin = fopen("sobst.txt", "r"); //открытие файла
	if (fin != NULL) { //проверка - открыт ли файл
	// главный цикл ввода собственников
		for (i = 0; i < kol; i++) {
			fgets(k, 40, fin);
			fscanf(fin, "%d", &asbs[i].sobstnum);
			fgets(k, 40, fin);
			//fgets(sobstname, 30, fin);
			//i = strlen(sobstname);
			fgets(asbs[i].sobstname, 30, fin);
			*(asbs[i].sobstname + strlen(asbs[i].sobstname) - 1) = '\0';
			fscanf(fin, "%d", &asbs[i].sobstforma);
			fscanf(fin, "%d", &asbs[i].prodkol);
			fgets(k, 40, fin);
			// цикл ввода продовольственных складов i-го собственника
			for (ip = 0; ip < asbs[i].prodkol; ip++) {
				fgets(k, 40, fin);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].stnum);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].sttype);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].tovkol);

				// цикл ввода товара ip-го склада i-го собственника
				fgets(k, 40, fin);
				fgets(k, 40, fin);
				for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
					fscanf(fin, "%d", &asbs[i].prodsp[ip].tovars[it].tovnum);
					fgets(k, 40, fin);
					fgets(asbs[i].prodsp[ip].tovars[it].tovname, 50, fin);
					fscanf(fin, "%d", &asbs[i].prodsp[ip].tovars[it].tkol);
				}
				fgets(k, 40, fin);
			}
			fscanf(fin, "%d", &asbs[i].hoskol);
			fgets(k, 40, fin);
			// цикл ввода хозяйственных складов i-го собственника
			for (ih = 0; ih < asbs[i].hoskol; ih++) {
				fgets(k, 40, fin);
				fscanf(fin, "%d", &asbs[i].hossp[ih].stnum);
				fscanf(fin, "%d", &asbs[i].hossp[ih].sttype);
				fscanf(fin, "%d", &asbs[i].hossp[ih].tovkol);

				// цикл ввода товара ip-го склада i-го собственника
				fgets(k, 40, fin);
				fgets(k, 40, fin);
				for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
					fscanf(fin, "%d", &asbs[i].hossp[ih].tovars[it].tovnum);
					fgets(k, 40, fin);
					fgets(asbs[i].hossp[ih].tovars[it].tovname, 50, fin);
					fscanf(fin, "%d", &asbs[i].hossp[ih].tovars[it].tkol);
				}
				fgets(k, 40, fin);
			}

		}
	}
	else printf("\nОшибка открытия файла");

	fclose(fin);
}

void fileout(struct sobst asbs[], int kol) {
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	fin = fopen("sobst_.txt", "w"); //открытие файла
	if (fin != NULL) { //проверка - открыт ли файл
	// главный цикл вывода собственников
		for (i = 0; i < kol; i++) {
			fprintf(fin, "=== Собственник -%d/%d- ===\n", i + 1, kol);
			fprintf(fin, "%d\n", asbs[i].sobstnum);
			fprintf(fin, "%s", asbs[i].sobstname);
			fprintf(fin, "%d\n", asbs[i].sobstforma);

			fprintf(fin, "%d\n", asbs[i].prodkol);
			// цикл вывода продовольственных складов i-го собственника
			for (ip = 0; ip < asbs[i].prodkol; ip++) {
				fprintf(fin, "--- Прод склад -%d/%d- ---\n", ip + 1, asbs[i].prodkol);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].stnum);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].sttype);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovkol);

				// цикл вывода товара ip-го склада i-го собственника
				fprintf(fin, "- Список товаров (%d) -\n", asbs[i].prodsp[ip].tovkol);
				for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tovnum);
					fprintf(fin, "%s", asbs[i].prodsp[ip].tovars[it].tovname);
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tkol);
				}

			}

			fprintf(fin, "%d\n", asbs[i].hoskol);
			// цикл вывода хозяйственных складов i-го собственника
			for (ih = 0; ih < asbs[i].hoskol; ih++) {
				fprintf(fin, "--- Хоз склад -%d/%d- ---\n", ih + 1, asbs[i].hoskol);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].stnum);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].sttype);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].tovkol);

				// цикл вывода товара ip-го склада i-го собственника
				fprintf(fin, "- Список товаров (%d) -\n", asbs[i].hossp[ih].tovkol);
				for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
					fprintf(fin, "%d\n", asbs[i].hossp[ih].tovars[it].tovnum);
					fprintf(fin, "%s", asbs[i].hossp[ih].tovars[it].tovname);
					fprintf(fin, "%d\n", asbs[i].hossp[ih].tovars[it].tkol);
				}

			}

		}
	}

	fclose(fin);
}















