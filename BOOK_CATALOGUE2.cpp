// BOOK_CATALOGUE2.cpp : Defines the entry point for the console application.
//

//������������ ���������
#include "stdafx.h"
#include "book_list.h"

//���������� ��� ������... - cout
#include <iostream>
//����. ��� �������� ������ � ������
#include <vector>
//����. ��� ������ �� ��������
#include <string>


//������������ ����. ���� �������� �� �����/����...
using namespace std;

//������ � ��������. ��������� ������
//�������� � ������ �������(30) �������� �� ���������� ������� � �������
//�������� �� ������ ���-�(256) �������� �� ���������� �������� � ������ ������,
//���� �� ���-�� ���� � ����� ��������
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

//����� ���������� ���������� ����, ������ � ����� �������� - ��� ������ �������� ����
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
	//������� ������ ����
	List ls;
	//������ �������� ��� ����� ������
	char author[256];
	//������� ���-�� ����
	int count = 0;
	//���������� ������ ����
	//���������� �� ������� authors[30][256] � bookNames[30][256]
	for(int i = count; i < 6; i++) 
		{
			//��������� �����
			ls.add(i, authors[i], bookNames[i]);
			//���� ����� �� ���� ������
			count++;
		}
	//����� ������ � �������
	ls.show();
	//����������, �������� ������� ������������ ������ �������,
	//������� ����� �����������
	int choose = 0;
	//������ ��� ����� ������ � ������ � ��������� �����
	char author_find[256], book_name_find[256];

	while(choose != 4)
	{
		cout << endl << "Clisk 1 for adding author, 2 - searching author, 3 - statistic, 4 - exit " << endl;
		//cin.ignore();
		cin >> choose;

		//���������� ������
		if(choose == 1) 
		{
			cout << "Put the author ";
			//������� �����
			cin.ignore();
			//���� ����� ������
			gets_s(author_find);
			cout << "Put the book name ";
			cin.ignore();
			//���� �������� ����� �����
			gets_s(book_name_find);
			//����-� ���������� �����
			ls.add(count, author_find, book_name_find);
			//����� ������������ ������ ����
			ls.show();
		}
		else if(choose == 2)
		{
			cout << "Put the author you want to find ";
			cin.ignore();
			//���� ����� ������
			gets_s(author);
			//����� ����� �� ���������� ������
			ls.search(author);
		}
		else if (choose == 3) ls.getStatistik();
		
	}

	system("pause");
	return 0;
}


