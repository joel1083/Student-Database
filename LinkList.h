#include "Node.h"
#include "thisisatest.h"
#include <iostream>
#include <string>
#include <fstream>
#ifndef LINKLIST_H
#define LINKLIST_H

using namespace std;

class LinkedList
{
	private: 
		Node *head;
		static int counter;
	public: 
		LinkedList() // default constructor
		{
		head = NULL;
		}
		~LinkedList(){}
				
		void Add();
    	void Average();
    	void Clear();
    	void Grade();
    	bool isEmpty();
    	void Peek();
        void Print(Node*);
        bool Remove();
};
		
int LinkedList :: counter = 0;
	
#include "LinkList.cpp"
#endif

