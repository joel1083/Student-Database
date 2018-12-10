#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
	private:
		int ID;
		string name;
		int test1,test2,test3;
		Node *nextptr;
		 // pointer that will be used to locate the next available class' address!
		
	public:
		Node(int a, string b, int c, int d, int e)
		{
			this->ID=a;
			this->name=b;
			this->test1=c;
			this->test2=d;
			this->test3=e;
		}
	
		Node *nextpointer() 
		{
			return nextptr;
		}
		
		void getnode() const 
		{
			cout << "\n\tStudent ID: " << ID <<endl; 
			cout << "\tStudent's Name:"  << name << endl;
			cout << "\t1st test score: " << test1 << endl;
			cout << "\t2nd test score: " << test2 << endl;
			cout << "\t3rd test score: " << test3 << endl;
		}
		
		int getID() const // used for the peak function
		{
			return ID;
		}
		
		string getName() const
		{
			return name;
		}
		
		int getTest1() const
		{
			return test1;
		}
		
		int getTest2() const
		{
			return test2;
		}

		int getTest3() const
		{
			return test3;
		}
				
		void setpointer (Node *address) // sets the pointer to the current address
		{
			nextptr = address;
		}
};
#endif


