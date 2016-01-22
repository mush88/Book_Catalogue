////���� � �����������

#include "stdafx.h"
#include "book_list.h"
#include "stack.h"
//���������� ��� ������... - cout
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//������� ��������� �����
void List::add(int num, char *author, char *bookName)
{
	//�������� ����� ��� ����� �����
	node *current = new node;
	//����������� ����� �����
	current->number = num;
	//����������� ��� ������
	strcpy_s(current->authors, author);
	//����������� �������� �����
	strcpy_s(current->book_names, bookName);
	//����. ����. ������
	current->next = NULL;
	//���� ������ �� ����, ��
	if(head != NULL)
	{
		//����� ��������� �� ������� �����
		tail->next = current;
		//����� ���� ������� �����
		tail = current;
	} else head = tail = current;	//���� ������ ����, �� ������ ������ = �����(������) = ��������
}

//������� ������ ������ ����
void List::show()
{
	//�������� ������ ��� �������� �����
	//��������� ����� - ������ ����� �� ������
	node *temp = head;
	while(temp != NULL)
	{
		//����� ������ �����
		cout << temp->number << " ";
		//����� ����� ������
		puts(temp->authors);
		cout << " ";
		//����� �������� �����
		puts(temp->book_names);
		cout << endl;
		//������ ������� ������� ���������� ��������� � ������(����. ������)
		temp = temp->next;
	}
}

//������� ������
void List::search(char *author)
{
	//��������� ������� ����� ������ ������
	node *temp = head;
	while(temp != NULL)
	{
	//���������� ���������� ������������� ������ � ������ �� ���������� ������ ����
	//���� �������, �� ������� ��� ������ �� ������
	if(strcmp(temp->authors, author) == 0)
		{
			//��������������� ����� ������, ����� ������, �������� �����
			printf("%d %5s %5s \n", temp->number, temp->authors, temp->book_names); 
		}
		temp = temp->next;
	}
};

template <class T>
//������� ���������� � ������ ���� ������� ��� ���� �������
void Stack<T>::push (T const& elem, node *addr)
{
	//�������� � ������ ������ Stack ��� ������||�������� �����
	elems.push_back(elem);
	//��������� ����� ������� �����
	addrs.push_back(addr);
}

//���������� ���� ���� �������||�������� ����
template <class T>
T Stack<T>::show_elem () const 
{ 
	//���� ���� ����, �� ������� �� ���� ������ �������������� ���������
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	
	//������� ��������� ��������� �����, ����� ����� ���� 
	node *te = new node;
	for ( int i = 0; i < 6; i++) 
	{
		te = addrs[i];
		//��������������� �����
		printf("%d %5s %5s \n", te->number, te->authors, te->book_names); 
		//��������� �����
		//cout << te->number << " ";
		//puts(te->authors); 
		//puts(te->book_names);
	}

    return elems.back();      
} 


//������ ����� ���������� �� ���� ������ ���� � ������� ������ ����,
//��� �� ����� ������ ��� �������� ��� ��������� ������� �����. 
//����� ����������� �� �����(�������� �����). ����� ����� - �������
//��������������� ����� ���� ����� � ������ ������ � ���
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
				//����� �� �����
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