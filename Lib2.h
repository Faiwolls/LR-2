#pragma once
using namespace std;

const int sbs_max = 10;

enum stortype { StProdov = 1, StHosyast = 2 }; // ��� ������
enum sobstf { Firma = 1, Gos = 2, Fislitso = 3 }; // ����� �������������

class tovar {
public:
	int tovnum;
	char tovname[50];
	int tkol;
	tovar();
};

class storage {
public:
	int stnum; // ���������� ����� ������
	stortype sttype; // ��� ������
	tovar tovars[100]; //�� ����� ������ ����� ���������� �� 100 ����� ������
	int tovkol; // ���-�� ����� ������ �� ������ (�������)
public:
	storage();
	void printtype();
	void tovinfo();

};


class sobst {
public:
	int sobstnum; // ���������� ����� ������������
	char sobstname[30]; //��� ������������
	sobstf sobstforma;
	storage prodsp[10]; // ������ ����������������� �������
	int prodkol; // ���-�� ����������������� �������
	storage hossp[10]; // ������ ������������� �������
	int hoskol; // ���-�� ������������� �������
	int stkol; // ���-�� ���� �������
public:
	sobst();
	void printtype();
	// ����� ���������� �� ����������������� �������
	void prodinfo();
	// ����� ���������� �� ������������� �������
	void hosinfo();
	// ����� ������ ���������� � ������������
	void printinfo();
	void vvod(sobst asbs[], int n);
	void fileout(sobst asbs[], int kol);
	void poisk(sobst asbs[], int kol);
	void filein(sobst asbs[], int kol);
};
