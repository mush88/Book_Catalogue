//файл с интерфейсом
#pragma once

//библиотека для вывода... - cout
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node 
{
	int number;
	char authors[256];
	char book_names[256];
	node *next;
};

class List
{
	node *head, *tail;
public:
	List():head(NULL), tail(NULL){};
	void add(int num, char *author, char *bookName);
	void show();
	void search(char *author);
	void getStatistik();
};

