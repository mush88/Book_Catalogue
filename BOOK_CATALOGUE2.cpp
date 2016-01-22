// BOOK_CATALOGUE2.cpp : Defines the entry point for the console application.
//

//обязательная директива
#include "stdafx.h"
#include "book_list.h"

//библиотека для вывода... - cout
#include <iostream>
//библ. для упаковки данных в массив
#include <vector>
//библ. для работы со строками
#include <string>


//пространство имен. тоже отвечает за вывод/ввод...
using namespace std;

//массив с авторами. двумерный массив
//значение в первых скобках(30) отвечает за количество авторов в массиве
//значение во вторых ско-х(256) отвечает за количество символов в имение автора,
//типа за кол-во букв в имени отвечает
char authors[30][256] =
{
	"John Warting ",
	"Bizly Denwork",
	"Martin Freemn",
	"Terry Pratche",
	"Lewis Kerrolo",
	"Karry Borland",
	"Enid Blytoner"
};

//почти аналогично обьяснению выше, только с одним отличием - это массив названий книг
char bookNames[30][256] =
{
	"Katy`s adventure in Python",
	"C++ in yur life",
	"C#. How to cook with it",
	"Magic in programming",
	"Lazy F#",
	"Java in our life",
	"What for CoffeScript"
};

int _tmain(int argc, _TCHAR* argv[])
{
	//создаем список книг
	List ls;
	//массив символов для имени автора
	char author[256];
	//счетчик кол-ва книг
	int count = 0;
	//заполнение списка книг
	//значениями из массива authors[30][256] и bookNames[30][256]
	for(int i = count; i < 6; i++) 
		{
			//добавляем книгу
			ls.add(i, authors[i], bookNames[i]);
			//книг стало на одну больше
			count++;
		}
	//вывод списка с книгами
	ls.show();
	//переменная, значение которой соответсвует номеру функции,
	//которая будет выполняться
	int choose = 0;
	//строка для имени автора и строка с названием книги
	char author_find[256], book_name_find[256];

	while(choose != 4)
	{
		cout << endl << "Clisk 1 for adding author, 2 - searching author, 3 - statistic, 4 - exit " << endl;
		//cin.ignore();
		cin >> choose;

		//добавление автора
		if(choose == 1) 
		{
			cout << "Put the author ";
			//очищает поток
			cin.ignore();
			//ввод имени автора
			gets_s(author_find);
			cout << "Put the book name ";
			cin.ignore();
			//ввод названия новой книги
			gets_s(book_name_find);
			//функ-я добавления книги
			ls.add(count, author_find, book_name_find);
			//вывод обновленного списка книг
			ls.show();
		}
		else if(choose == 2)
		{
			cout << "Put the author you want to find ";
			cin.ignore();
			//ввод имени автора
			gets_s(author);
			//поиск книги по введенному автору
			ls.search(author);
		}
		else if (choose == 3) ls.getStatistik();
		
	}

	system("pause");
	return 0;
}


