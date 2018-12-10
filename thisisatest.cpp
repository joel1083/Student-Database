#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Reads and sets the data in an array
void Reader :: setdata()
{
	ifstream fin ("data1.txt");
	for (int i = 0; i < 15; i++)
	   {
	   	fin >> id[i];
	   	fin.get();
	   	getline(fin, n[i]);
	   	fin >> test1[i];
	    fin >> test2[i];
   	    fin >> test3[i];
	}
}

// Sorts previous data using the swap method in the following method
void Reader :: AscendSort()
{
	int j = 1;
	while (j < 15)
	  {
		for (int i = 0; i < 15 - j; i++)
	   		if (id[i] > id[i+1])
	   		{	
			   Swap(id[i], id[i+1]);
			   Swap(n[i], n[i+1]);
			   Swap(test1[i], test1[i+1]);
			   Swap(test2[i], test2[i+1]);
			   Swap(test3[i], test3[i+1]);
		    } 
		j++;
	  }
}

template <class T>
void Reader :: Swap(T &x, T & y)
{ 	T temp = x;
		x = y;
		y = temp;
}

// This method will place the file of the list in a new document called 'sort.txt' .
void Reader :: PrintPass(){
	
	ofstream fout("sort.txt");
	for(int i=0; i < 15; i++)
	{
		fout << id[i] << "\n" << n[i] << "\n" << test1[i] << " " << test2[i] << " " << test3[i] << endl;
	}
}
