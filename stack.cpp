////файл с реализацией

#include "stdafx.h"
#include "book_list.h"
#include "stack.h"

//библиотека для вывода... - cout
#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <class T>
void Stack<T>::push (T const& elem, node *addr)
{
	elems.push_back(elem);
	addrs.push_back(addr);
}

template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	
	node *te = new node;
	//te = addrs.back();
	//te = elems[0];
	for ( int i = 0; i < 6; i++) 
	{
		te = addrs[i];
		printf("%d %5s %5s \n", te->number, te->authors, te->book_names); 
		//cout << te->number << " ";
		//puts(te->authors); 
		//puts(te->book_names);
	}
	// return copy of last element 
    return elems.back();      
} 

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
				break;
			}
	}
}