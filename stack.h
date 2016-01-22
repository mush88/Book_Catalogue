//файл с интерфейсом
#pragma once

//библиотека для вывода... - cout
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Stack { 
  private: 
    vector<T> elems;     // elements 
	vector<node *> addrs;
  public: 
    void push(T const&, node *addr);  // push element 
    void search1(char *author);            
    T show_elem() const;            // return top element 
    bool empty() const{       // return true if empty.
        return elems.empty(); 
    } 
}; 
