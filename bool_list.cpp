////файл с реализацией

#include "stdafx.h"
#include "book_list.h"
#include "stack.h"
//библиотека для вывода... - cout
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//функция доавления книги
void List::add(int num, char *author, char *bookName)
{
	//выделяем место для новой книги
	node *current = new node;
	//присваиваем номер книге
	current->number = num;
	//присваиваем имя автора
	strcpy_s(current->authors, author);
	//присваиваем название книги
	strcpy_s(current->book_names, bookName);
	//след. элем. пустой
	current->next = NULL;
	//если список не пуст, то
	if(head != NULL)
	{
		//хвост указывает на текущую книгу
		tail->next = current;
		//хвост есть текущая книга
		tail = current;
	} else head = tail = current;	//если список пуст, то начало списка = концу(хвосту) = текущему
}

//функция вывода списка книг
void List::show()
{
	//выделяем память для временой книги
	//временная книга - первая книга из списка
	node *temp = head;
	while(temp != NULL)
	{
		//вывод номера книги
		cout << temp->number << " ";
		//вывод имени автора
		puts(temp->authors);
		cout << " ";
		//вывод названия книги
		puts(temp->book_names);
		cout << endl;
		//теперь текущий элемент заменяется следующим в списке(след. книгой)
		temp = temp->next;
	}
}

//функция поиска
void List::search(char *author)
{
	//временный элемент равен голове списка
	node *temp = head;
	while(temp != NULL)
	{
	//сравниваем введенного пользователем автора и автора из имеющегося списка книг
	//если совпали, то выводим все данные по автору
	if(strcmp(temp->authors, author) == 0)
		{
			//форматированный вывод номера, имени автора, названия книги
			printf("%d %5s %5s \n", temp->number, temp->authors, temp->book_names); 
		}
		temp = temp->next;
	}
};

template <class T>
//функция добавления в список всех авторов или имен авторов
void Stack<T>::push (T const& elem, node *addr)
{
	//добавяем в обьект класса Stack имя автора||название книги
	elems.push_back(elem);
	//добавляем адрес обьекта книги
	addrs.push_back(addr);
}

//статистика всех имен авторов||названий книг
template <class T>
T Stack<T>::show_elem () const 
{ 
	//если стек пуст, то говорим об этом выводя соответстующее сообщение
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	
	//создаем временную структуру книги, чтобы можно было 
	node *te = new node;
	for ( int i = 0; i < 6; i++) 
	{
		te = addrs[i];
		//форматированный вывод
		printf("%d %5s %5s \n", te->number, te->authors, te->book_names); 
		//потоковый вывод
		//cout << te->number << " ";
		//puts(te->authors); 
		//puts(te->book_names);
	}

    return elems.back();      
} 


//гибкий поиск реализован за счет поиска книг в обьекте класса Стек,
//где не нужно каждый раз подымать всю структуру обьекта книги. 
//поиск произодится по имени(названии книги). нашли книгу - достали
//соответствующий адрес этой книги и вывели данные о ней
template <class T>
void Stack<T>::search1 (char *author)
{ 
	node *te = new node;
	
	for ( int i = 0; i < 6; i++) 
	{
		if(strcmp(elems[i], author) == 0)
			{
				te = addrs[i];
				printf("%d %5s %5s \n", te->number, te->authors, te->book_names); 
				//выход из цикла
				break;
			}
	}
}

void List::getStatistik()
{
	Stack<int> numbers;
	Stack<char *> authors;
	Stack<char *> book_names;

	int choose;
	cout << endl << "Click 2 - authors, 3 - book_names ";
	cin >> choose;

	node *temp = head;
	while(temp != NULL)
	{
		if(choose == 1) numbers.push(temp->number, temp);
		else if(choose == 2) authors.push(temp->authors, temp);
		else book_names.push(temp->book_names, temp);

		temp = temp->next;
	}
	
	/*
	if(choose == 1)	cout << numbers.show_elem();
	else if(choose == 2) puts(authors.show_elem());
	else if(choose == 3) puts(book_names.show_elem());
	*/
	

	char elem[256];
	
	if(choose == 2) 
	{
		cout << "Write the author you search ";
		cin.ignore();
		
		gets_s(elem);
		authors.search1(elem);
	}
	if(choose == 3) 
		{
			cout << "Write the name of book you search ";
			cin.ignore();
			gets_s(elem);
			book_names.search1(elem);
		}
}