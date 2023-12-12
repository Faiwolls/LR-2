// ���. ���� 2.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
	case 1: printf("�����"); break;
	case 2: printf("���������������"); break;
	case 3: printf("�������"); break;
	}
}

void prnstortype(struct storage stor)
{
	switch (stor.sttype) {
	case 1: printf("�����������������"); break;
	case 2: printf("�������������"); break;
	}
}

void vvod(struct sobst asbs[], int kol) {
	int i = 0, n = 0, ip = 0, ih = 0, it = 0;
	int pk = 0, d;

	// ������� ���� ����� �������������
	for (i = 0; i < kol; i++) {
		system("cls");
		printf("\n=== ���� ������������: -%d- ===\n", i + 1);
		printf("\n������� �����: ");
		scanf("%d", &asbs[i].sobstnum);
		while (getchar() != '\n');
		printf("\n������� ��������: ");
		gets_s(asbs[i].sobstname, 30);
		printf("\n������� ����� ������������� (1 - �����, 2 - ���, 3 - �������): ");
		scanf("%d", &d);
		while (getchar() != '\n');
		switch (d) {
		case 1: asbs[i].sobstforma = Firma; break;
		case 2: asbs[i].sobstforma = Gos; break;
		case 3: asbs[i].sobstforma = Fislitso; break;
		};
		printf("\n������� ���-�� ����������������� �������: ");
		scanf("%d", &asbs[i].prodkol);

		// ���� ����� ����������������� ������� i-�� ������������
		for (ip = 0; ip < asbs[i].prodkol; ip++) {
			printf("\n--- ���� ���� ������: -%d- ---\n", ip + 1);
			printf("\n������� �����: ");
			scanf("%d", &asbs[i].prodsp[ip].stnum);
			while (getchar() != '\n');
			asbs[i].prodsp[ip].sttype = StProdov;
			printf("\n������� ���-�� ����� ������ �� ������ %d: ", asbs[i].prodsp[ip].stnum, ": ");
			scanf("%d", &asbs[i].prodsp[ip].tovkol);
			while (getchar() != '\n');

			// ���� ����� ������ ip-�� ������ i-�� ������������
			for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
				printf("\n������� ����� ������: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\n������� ������������ ������: ");
				gets_s(asbs[i].prodsp[ip].tovars[it].tovname, 30);
				printf("\n������� ���-�� ������� ������: ");
				scanf("%d", &asbs[i].prodsp[ip].tovars[it].tkol);
				while (getchar() != '\n');
			}

		}

		printf("\n������� ���-�� ������������� �������: ");
		scanf("%d", &asbs[i].hoskol);
		while (getchar() != '\n');

		// ���� ����� ������������� ������� i-�� ������������
		for (ih = 0; ih < asbs[i].hoskol; ih++) {
			printf("\n--- ���� ��� ������: -%d- ---\n", ih + 1);
			printf("\n������� �����: ");
			scanf("%d", &asbs[i].hossp[ih].stnum);
			while (getchar() != '\n');
			asbs[i].hossp[ih].sttype = StHosyast;
			printf("\n������� ���-�� ����� ������ �� ������ %d: ", asbs[i].hossp[ih].stnum, ": ");
			scanf("%d", &asbs[i].hossp[ih].tovkol);
			while (getchar() != '\n');

			// ���� ����� ������ ih-�� ������ i-�� ������������
			for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
				printf("\n������� ����� ������: ");
				scanf("%d", &asbs[i].hossp[ih].tovars[it].tovnum);
				while (getchar() != '\n');
				printf("\n������� ������������ ������: ");
				gets_s(asbs[i].hossp[ih].tovars[it].tovname, 30);
				printf("\n������� ���-�� ������� ������: ");
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
	printf("�������� � ������ ������ ������ �������� ����� (1 ������� - ��������� ������������, 2 ������� - ��������� ������, 3 ������� - ��������� ������): \n");
	scanf("%d", &z);
	switch (z)
	{
	case 1:
		printf("\n�������� ���� �� �������� ������ �������� ����� (1 - �� ������ ������������, 2 - �� ����� ������������, 3 - �� ����� �������������\n, 4 - ����� ���������� � ����������������� �������, 5 - ����� ���������� � ������������� �������): \n");
		scanf("%d", &d);
		switch (d)
		{
		case 1:
			printf("\n������� ����� ������������: \n");
			scanf("%d", &sobstnum);
			for (i = 0; i < kol; i++) {
				if (sobstnum == asbs[i].sobstnum) {
					printf("\n---���������� �� %d ������������---", i + 1);
					printf("\n������������ ������������: %s", asbs[i].sobstname);
					printf("\n����� �������������: ");
					prnsobforma(asbs[i]);
					printf("\n���������� ����������������� ������� ������������: %d", asbs[i].prodkol);
					printf("\n���������� ������������� ������� ������������: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\n����� ������: %d", asbs[i].prodsp[ip].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\n���������� ����� ������� �� %d ������: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("���������� � �������: %d\n", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\n����� ������: %d", asbs[i].hossp[ih].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 2:
			printf("\n������� ������������ ������������: \n");
			while (getchar() != '\n');
			gets_s(sobstname);
			for (i = 0; i < kol; i++) {
				if (strcmp(sobstname, asbs[i].sobstname) == 0) {
					printf("\n---���������� �� %d ������������---", i + 1);
					printf("\n����� ������������: %d", asbs[i].sobstnum);
					printf("\n������������ ������������: %s", asbs[i].sobstname);
					printf("\n����� �������������: ");
					prnsobforma(asbs[i]);
					printf("\n���������� ����������������� ������� ������������: %d", asbs[i].prodkol);
					printf("\n���������� ������������� ������� ������������: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\n����� ������: %d", asbs[i].prodsp[ip].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\n����� ������: %d", asbs[i].hossp[ih].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 3:
			printf("\n������� ����� ������������� ��� ������(1-�����,2-���.�����������,3-���������� ����):\n");
			scanf("%d", &q);
			for (i = 0; i < kol; i++) {
				if (asbs[i].sobstforma == q) {
					printf("\n---���������� �� %d ������������---", i + 1);
					printf("\n����� ������������: %d", asbs[i].sobstnum);
					printf("\n������������ ������������: %s", asbs[i].sobstname);
					printf("\n����� �������������: ");
					prnsobforma(asbs[i]);
					printf("\n���������� ����������������� ������� ������������: %d", asbs[i].prodkol);
					printf("\n���������� ������������� ������� ������������: %d\n", asbs[i].hoskol);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\n����� ������: %d", asbs[i].prodsp[ip].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\n����� ������: %d", asbs[i].hossp[ih].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].hossp[ih].tovars[it].tkol);
						}
					}
				}
			}


			break;
			q = 0;
		case 4:
			printf("\n������� ���-�� ����������������� �������: ");
			scanf("%d", &prodkol);
			for (i = 0; i < kol; i++) {
				if (prodkol == asbs[i].prodkol) {
					printf("\n---���������� �� %d ������������---", i + 1);
					printf("\n����� ������������: %d", asbs[i].sobstnum);
					printf("\n������������ ������������: %s", asbs[i].sobstname);
					printf("\n����� �������������: ");
					prnsobforma(asbs[i]);
					for (ip = 0; ip < asbs[i].prodkol; ip++) {
						printf("\n����� ������: %d", asbs[i].prodsp[ip].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].prodsp[ip]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 5:
			printf("\n������� ���-�� ������������� �������: \n");
			scanf("%d", &hoskol);
			for (i = 0; i < kol; i++) {
				if (hoskol == asbs[i].hoskol) {
					printf("\n---���������� �� %d ������������---", i + 1);
					printf("\n����� ������������: %d", asbs[i].sobstnum);
					printf("\n������������ ������������: %s", asbs[i].sobstname);
					printf("\n����� �������������: ");
					prnsobforma(asbs[i]);
					for (ih = 0; ih < asbs[i].hoskol; ih++) {
						printf("\n����� ������: %d", asbs[i].hossp[ih].stnum);
						printf("\n��� ������: ");
						prnstortype(asbs[i].hossp[ih]);
						printf("\n���������� ������� �� %d ������: %d\n", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].hossp[ih].tovars[it].tkol);
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
		printf("\n������� ��� ������ ��� ������(1-�����������������,2-�������������):\n");
		scanf("%d", &sttype);
		switch (sttype)
		{
		case 1:
			printf("\n������� ����� ������������������ ������ ��� ������:\n");
			scanf("%d", &stnum);
			for (i = 0; i < kol; i++) {
				for (ip = 0; ip < asbs[i].prodkol; ip++) {
					if (stnum == asbs[i].prodsp[ip].stnum) {
						printf("\n���������� ������� �� %d ������: %d", asbs[i].prodsp[ip].stnum, asbs[i].prodsp[ip].tovkol);
						for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].prodsp[ip].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].prodsp[ip].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].prodsp[ip].tovars[it].tkol);
						}
					}
				}
			}
			break;
		case 2:
			printf("\n������� ����� �������������� ������ ��� ������:\n");
			scanf("%d", &stnum);
			for (i = 0; i < kol; i++) {
				for (ih = 0; ih < asbs[i].hoskol; ih++) {
					if (stnum == asbs[i].hossp[ih].stnum) {
						printf("\n���������� ������� �� %d ������: %d", asbs[i].hossp[ih].stnum, asbs[i].hossp[ih].tovkol);
						for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
							printf("\n����� ������: %d", asbs[i].hossp[ih].tovars[it].tovnum);
							printf("\n������������ ������: %s", asbs[i].hossp[ih].tovars[it].tovname);
							printf("\n���������� � �������: %d", asbs[i].hossp[ih].tovars[it].tkol);
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
	fin = fopen("sobst.txt", "r"); //�������� �����
	if (fin != NULL) { //�������� - ������ �� ����
	// ������� ���� ����� �������������
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
			// ���� ����� ����������������� ������� i-�� ������������
			for (ip = 0; ip < asbs[i].prodkol; ip++) {
				fgets(k, 40, fin);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].stnum);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].sttype);
				fscanf(fin, "%d", &asbs[i].prodsp[ip].tovkol);

				// ���� ����� ������ ip-�� ������ i-�� ������������
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
			// ���� ����� ������������� ������� i-�� ������������
			for (ih = 0; ih < asbs[i].hoskol; ih++) {
				fgets(k, 40, fin);
				fscanf(fin, "%d", &asbs[i].hossp[ih].stnum);
				fscanf(fin, "%d", &asbs[i].hossp[ih].sttype);
				fscanf(fin, "%d", &asbs[i].hossp[ih].tovkol);

				// ���� ����� ������ ip-�� ������ i-�� ������������
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
	else printf("\n������ �������� �����");

	fclose(fin);
}

void fileout(struct sobst asbs[], int kol) {
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	fin = fopen("sobst_.txt", "w"); //�������� �����
	if (fin != NULL) { //�������� - ������ �� ����
	// ������� ���� ������ �������������
		for (i = 0; i < kol; i++) {
			fprintf(fin, "=== ����������� -%d/%d- ===\n", i + 1, kol);
			fprintf(fin, "%d\n", asbs[i].sobstnum);
			fprintf(fin, "%s", asbs[i].sobstname);
			fprintf(fin, "%d\n", asbs[i].sobstforma);

			fprintf(fin, "%d\n", asbs[i].prodkol);
			// ���� ������ ����������������� ������� i-�� ������������
			for (ip = 0; ip < asbs[i].prodkol; ip++) {
				fprintf(fin, "--- ���� ����� -%d/%d- ---\n", ip + 1, asbs[i].prodkol);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].stnum);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].sttype);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovkol);

				// ���� ������ ������ ip-�� ������ i-�� ������������
				fprintf(fin, "- ������ ������� (%d) -\n", asbs[i].prodsp[ip].tovkol);
				for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tovnum);
					fprintf(fin, "%s", asbs[i].prodsp[ip].tovars[it].tovname);
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tkol);
				}

			}

			fprintf(fin, "%d\n", asbs[i].hoskol);
			// ���� ������ ������������� ������� i-�� ������������
			for (ih = 0; ih < asbs[i].hoskol; ih++) {
				fprintf(fin, "--- ��� ����� -%d/%d- ---\n", ih + 1, asbs[i].hoskol);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].stnum);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].sttype);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].tovkol);

				// ���� ������ ������ ip-�� ������ i-�� ������������
				fprintf(fin, "- ������ ������� (%d) -\n", asbs[i].hossp[ih].tovkol);
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















