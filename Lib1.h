#pragma once

const int sbs_max = 10;

struct tovar {
	int tovnum;
	char tovname[50];
	int tkol;
}; //структуры описывающая 1 товар

enum stortype { StProdov = 1, StHosyast = 2 }; // тип склада
enum sobstf { Firma = 1, Gos = 2, Fislitso = 3 }; // форма собственности

struct storage {
	int stnum; // уникальный номер склада
	stortype sttype; // тип склада
	tovar tovars[100]; //на одном складе можно разместить до 100 видов товара
	int tovkol; // кол-во видов товара на складе (позиций)
}; //структура описывающая 1 склад


struct sobst {
	int sobstnum; // уникальный номер собственника
	char sobstname[30]; //имя собственника
	sobstf sobstforma;
	storage prodsp[10]; // список продовольственных складов
	int prodkol; // кол-во продовольственных складов
	storage hossp[10]; // список хозяйственных складов
	int hoskol; // кол-во хозяйственных складов
	int stkol; // кол-во всех складов
};

void printtype();
// вывод информации по продовольственным складам
void prodinfo();
// вывод информации по хозяйственным складам
void hosinfo();
// Вывод полной информации о собственнике
void printinfo();
void vvod(sobst asbs[], int n);
void fileout(sobst asbs[], int kol);
void poisk(sobst asbs[], int kol);
void filein(sobst asbs[], int kol);
