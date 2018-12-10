#include <iostream>
#include <string>
#include <fstream>
#ifndef THISISATEST_H
#define THISISATEST_H

using namespace std;

class Reader
{
	private:
	int id[15];
	string n[15];
	int test1[15];
	int test2[15];
	int test3[15];
	
	public:
		void setdata();
		void AscendSort();	
		template <class T>
			void Swap(T &, T &);
		void PrintPass();
};

#include "thisisatest.cpp"
#endif
