#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "lib2.h"

tovar::tovar() {
	tovnum = 0;
	strcpy(tovname, "");
	tkol = 0;
};

storage::storage() {
	int stnum = 0;
	int tovkol = 0;
};
void storage::printtype()
{
	switch (this->sttype) {
	case 1: printf("Продовольственный"); break;
	case 2: printf("Хозяйственный"); break;
	}
}

void storage::tovinfo()
{
	int it;
	//printf("\n-- Склад %d --", this->stnum);
	printf("\nТип склада: ");
	this->printtype();
	printf("\nКоличество видов товаров на %d складе: %d", this->stnum, this->tovkol);
	for (it = 0; it < this->tovkol; it++) {
		printf("\nНомер товара: %d", this->tovars[it].tovnum);
		printf("\nНаименование товара: %s", this->tovars[it].tovname);
		printf("Количество в наличии: %d", this->tovars[it].tkol);
	}

}




sobst::sobst() {
	int sobstnum = 0; // уникальный номер собственника
	int prodkol = 0; // кол-во продовольственных складов
	int hoskol = 0; // кол-во хозяйственных складов
	int stkol = 0; // кол-во всех складов
}

void sobst::printtype()
{
	switch (this->sobstforma) {
	case 1: printf("Фирма"); break;
	case 2: printf("Государственная"); break;
	case 3: printf("Физлицо"); break;
	}
}

	// вывод информации по продовольственным складам
void sobst::prodinfo() {
	printf("\nНомер собственника: %d", this->sobstnum);
	printf("\nНаименование собственника: %s", this->sobstname);
	printf("\nКоличество продовольственных складов собственника: %d", this->prodkol);
	for (int ip = 0; ip < this->prodkol; ip++) {
		printf("\n\n-Номер склада: %d-", this->prodsp[ip].stnum);
		printf("\nКоличество видов товаров на %d складе: %d", this->prodsp[ip].stnum, this->prodsp[ip].tovkol);
	}
}

	// вывод информации по хозяйственным складам
void sobst::hosinfo() {
	printf("\nНомер собственника: %d", this->sobstnum);
	printf("\nНаименование собственника: %s", this->sobstname);
	printf("\nКоличество хозяйственных складов собственника: %d", this->hoskol);
	for (int ih = 0; ih < this->hoskol; ih++) {
		printf("\n\n-Номер склада: %d-", this->hossp[ih].stnum);
		printf("\nКоличество видов товаров на %d складе: %d", this->hossp[ih].stnum, this->hossp[ih].tovkol);
	}
}

	// Вывод полной информации о собственнике
void sobst::printinfo()
{
	printf("\nНомер собственника: %d", this->sobstnum);
	printf("\nНаименование собственника: %s", this->sobstname);
	printf("\nФорма собственности: ");
	this->printtype();
	printf("\nКоличество продовольственных складов собственника: %d", this->prodkol);
	printf("\nКоличество хозяйственных складов собственника: %d", this->hoskol);
	printf("\nКоличество всех складов собственника: %d", this->stkol);
	printf("\n\n--Склады собственника--");
	for (int ip = 0; ip < this->prodkol; ip++) {
		printf("\n\n-Номер склада: %d-", this->prodsp[ip].stnum);
		printf("\nТип склада: ");
		this->prodsp[ip].printtype();
		printf("\nКоличество видов товаров на %d складе: %d", this->prodsp[ip].stnum, this->prodsp[ip].tovkol);
		printf("\n=Товары склада %d=", this->prodsp[ip].stnum);
		for (int it = 0; it < this->prodsp[ip].tovkol; it++) {
			printf("\nНомер товара: %d", this->prodsp[ip].tovars[it].tovnum);
			printf("\nНаименование товара: %s", this->prodsp[ip].tovars[it].tovname);
			printf("Количество в наличии: %d", this->prodsp[ip].tovars[it].tkol);
		}
	}
	for (int ih = 0; ih < this->hoskol; ih++) {
		printf("\n\n-Номер склада: %d-", this->hossp[ih].stnum);
		printf("\nТип склада: ");
		this->hossp[ih].printtype();
		printf("\nКоличество видов товаров на %d складе: %d", this->hossp[ih].stnum, this->hossp[ih].tovkol);
		printf("\n=Товары склада %d=", this->hossp[ih].stnum);
		for (int it = 0; it < this->hossp[ih].tovkol; it++) {
			printf("\nНомер товара: %d", this->hossp[ih].tovars[it].tovnum);
			printf("\nНаименование товара: %s", this->hossp[ih].tovars[it].tovname);
			printf("Количество в наличии: %d", this->hossp[ih].tovars[it].tkol);
		}
	}
}


void sobst::vvod(sobst asbs[], int n) {
	int i = 0, d;
	do {
		printf("\nВведите кол-во собственников (1-%d): ", sbs_max);
		scanf("%d", &n);
		while (getchar() != '\n');
	} while (n < 1 || n > sbs_max);
	for (i = 0; i < n; i++) {
		system("cls");
		printf("\n=== Ввод собственника: -%d- ===\n", i + 1);
		printf("\nВведите номер: ");
		scanf("%d", this->sobstnum);
		while (getchar() != '\n');
		printf("\nВведите название: ");
		gets_s(this->sobstname);
		printf("\nВведите форму собственности (1 - фирма, 2 - гос, 3 - физлицо): ");
		scanf("%d", &d);
		while (getchar() != '\n');
		switch (d) {
		case 1: this->sobstforma= sobstf::Firma; break;
		case 2: this->sobstforma = sobstf::Gos; break;
		case 3: this->sobstforma = sobstf::Fislitso; break;
		};
		printf("\nВведите кол-во продовольственных складов: ");
		scanf("%d", &this->prodkol);
		printf("\nВведите кол-во хозяйственных складов: ");
		scanf("%d", &this->hoskol);

		// цикл ввода продовольственных складов i-го собственника
		for (int ip = 0; ip < prodkol; ip++) {
			printf("\n--- Ввод прод склада: -%d- ---\n", ip + 1);
			printf("\nВведите номер: ");
			scanf("%d", &asbs[i].prodsp[ip].stnum);
			while (getchar() != '\n');
			asbs[i].prodsp[ip].sttype = stortype::StProdov;
			printf("\nВведите кол-во видов товара на складе %d: ", asbs[i].prodsp[ip].stnum, ": ");
			scanf("%d", &asbs[i].prodsp[ip].tovkol);
			while (getchar() != '\n');

			// цикл ввода товара ip-го склада i-го собственника
			for (int it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
				printf("\nВведите номер товара: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\nВведите наименование товара: ");
				gets_s(asbs[i].prodsp[ip].tovars[it].tovname);
				printf("\nВведите кол-во данного товара: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tkol);
				while (getchar() != '\n');
			}

		}

		printf("\nВведите кол-во хозяйственных складов: ");
		scanf("%d", &asbs[i].hoskol);
		while (getchar() != '\n');

		// цикл ввода хозяйственных складов i-го собственника
		for (int ih = 0; ih < asbs[i].hoskol; ih++) {
			printf("\n--- Ввод хоз склада: -%d- ---\n", ih + 1);
			printf("\nВведите номер: ");
			scanf("%d", &asbs[i].hossp[ih].stnum);
			while (getchar() != '\n');
			asbs[i].hossp[ih].sttype = stortype::StHosyast;
			printf("\nВведите кол-во видов товара на складе %d: ", asbs[i].hossp[ih].stnum, ": ");
			scanf("%d", &asbs[i].hossp[ih].tovkol);
			while (getchar() != '\n');

			// цикл ввода товара ih-го склада i-го собственника
			for (int it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
				printf("\nВведите номер товара: ");
				scanf("%d", &asbs[i].hossp[ih].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\nВведите наименование товара: ");
				gets_s(asbs[i].hossp[ih].tovars[it].tovname);
				printf("\nВведите кол-во данного товара: ");
				scanf("%d", &asbs[i].hossp[ih].tovars[it].tkol);
				while (getchar() != '\n');
			}


		}

		asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
	}

}
void sobst::fileout(sobst asbs[], int kol) {
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	fin = fopen("sobst.txt", "w"); //открытие файла
	if (fin != NULL) { //проверка - открыт ли файл
	// главный цикл вывода собственников
		for (i = 0; i < kol; i++) {
			fprintf(fin, "=== Собственник -%d/%d- ===\n", i + 1, kol);
			fprintf(fin, "%d\n", asbs[i].sobstnum);
			fprintf(fin, "%s\n", asbs[i].sobstname);
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
					fprintf(fin, "%s\n", asbs[i].prodsp[ip].tovars[it].tovname);
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
					fprintf(fin, "%s\n", asbs[i].hossp[ih].tovars[it].tovname);
					fprintf(fin, "%d\n", asbs[i].hossp[ih].tovars[it].tkol);
				}

			}

		}
	}

	fclose(fin);
}


void sobst::poisk(sobst asbs[], int kol) {
	int i = 0, n = 0, ip = 0, ih = 0, it = 0;
	int pk = 0, d, z, q, sobstnum, prodkol, hoskol, sobstforma, stnum, sttype, tovkol;
	char sobstname[30];
	system("cls");
	printf("Выберите с какого уровня хотите провести поиск \n(1 уровень - Структура собственника, 2 уровень - структура склада, 3 уровень - структура товара): ");
	scanf("%d", &z);
	switch (z)
	{
	case 1: // 1 уровень - структура собственнка
		printf("\n\nВыберите поле по которому хотите провести поиск \n(1 - по номеру собственника, 2 - по имени собственника, 3 - по форме собственности): ");
		scanf("%d", &d);
		switch (d)
		{
		case 1: //1 - по номеру собственника
			printf("\nВведите номер собственника: ");
			scanf("%d", &sobstnum);
			for (i = 0; i < kol; i++) {
				if (sobstnum == asbs[i].sobstnum) {
					printf("\n\n---Информация по %d собственнику---", i + 1);
					asbs[i].printinfo();
				}
			}
			break;
		case 2: //2 - по имени собственника
			printf("\nВведите имя собственника: ");
			while (getchar() != '\n');
			gets_s(sobstname, 30);
			for (i = 0; i < kol; i++) {
				if (strcmp(sobstname, asbs[i].sobstname) == 0) {
					printf("\n\n---Информация по %d собственнику---", i + 1);
					asbs[i].printinfo();
				}
			}
			break;
		case 3: //3 - по форме собственности
			printf("\nВведите форму собственности для поиска \n ( 1 - фирма, 2 - гос.предприятие, 3 - физическое лицо ): ");
			scanf("%d", &q);
			for (i = 0; i < kol; i++) {
				if (asbs[i].sobstforma == q) {
					printf("\n\n---Информация по %d собственнику---", i + 1);
					asbs[i].printinfo();
				}
			}
			q = 0;

		default:
			printf("\n\nТакого варианта нет!\n\n");
			break;
		}

		break;
	case 2: //уровень - структура склада
		printf("\nВведите номер поля для поиска ( 1 - поиск по номеру склада, \n2 - вывод информации о продовольственных складах, 3 - вывод информации о хозяйственных складах): ");
		scanf("%d", &q);
		switch (q)
		{
		case 1: //поиск по номеру склада
			printf("\nВведите тип склада для поиска ( 1 - продовольственный, 2 - хозяйственный ): ");
			scanf("%d", &sttype);
			switch (sttype)
			{

			case 1: // поиск по номеру по продовольственным
				printf("\nВведите номер склада для поиска: ");
				scanf("%d", &stnum);
				for (i = 0; i < kol; i++) {
					for (ip = 0; ip < kol; ip++) {
						if (stnum == asbs[i].prodsp[ip].stnum) {
							printf("\n== Информация по складу: %d ==", asbs[i].prodsp[ip].stnum);
							printf("\nНомер собственника: %d", asbs[i].sobstnum);
							printf("\nНаименование собственника: %s", asbs[i].sobstname);
							asbs[i].prodsp[ip].tovinfo();
						}
					}
				}
				break;
			case 2: // поиск по номеру по хозяйственным
				printf("Введите номер склада для поиска: ");
				scanf("%d", &stnum);
				for (i = 0; i < kol; i++) {
					for (ih = 0; ih < kol; ih++) {
						if (stnum == asbs[i].hossp[ih].stnum) {
							printf("\n== Информация по складу: %d ==", asbs[i].hossp[ih].stnum);
							printf("\nНомер собственника: %d", asbs[i].sobstnum);
							printf("\nНаименование собственника: %s", asbs[i].sobstname);
							asbs[i].hossp[ih].tovinfo();
						}
					}
				}
				break;
			}

			break;
		case 2: //вывод информации о продовольственных складах
			for (i = 0; i < kol; i++) {
				printf("\n\n---Информация по %d собственнику---", i + 1);
				asbs[i].prodinfo();
			}
			break;
		case 3: //вывод информации о хозяйственных складах
			for (i = 0; i < kol; i++) {
				printf("\n\n---Информация по %d собственнику---", i + 1);
				asbs[i].hosinfo();
			}
			break;
		default:
			printf("\n\nТакого варианта нет!\n\n");
			break;
		}

	case 3: //уровень - структура товара

		break;

	default:
		printf("\n\nТакого варианта нет!\n\n");
		break;
	}
	printf("\n\nПоиск завершен\n\n");

}

void sobst::filein(sobst asbs[], int kol) {
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	char k[40];
	fin = fopen("sobst.txt", "r"); //открытие файла
	if (fin != NULL) { //проверка - открыт ли файл
	// главный цикл ввода собственников
		for (i = 0; i < kol; i++) {
			fgets(k, 40, fin);
			fscanf(fin, "%d", &asbs[i].sobstnum);
			fgets(k, 40, fin);
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
			asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
		}
	}
	else printf("\nОшибка открытия файла");

	fclose(fin);
}


