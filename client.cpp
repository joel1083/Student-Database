/*
	Name: Joel Rivas
	Class: CIS 260
	Date: 12/14/17
		Program Name: Final Project 
		Program Description: This program will read data from a file and sort the file to then place the data into a linked list. This program has a sorting class called "thisisatest" 
		which will document the initial file into ascending order. THe linklist.h manipulates all of the data prior to the client using it's functions. 
*/

#include <iostream>
#include "LinkList.h"

using namespace std;

void menu(LinkedList &);

int main()
{
    // New list
    LinkedList list;
    menu(list); 
    cout << "\n\tThank you for using PCCC software\n";
    return 0;
}

void menu(LinkedList &list)
{   char choice;
    while ( choice != 'E' ){   // additional escape key 
        system("CLS"); 
        cout << "\n\tMain Menu\n\n";
		cout << "\tHere are the available Options()\n";
        cout << "\t(1)--Insert Students-----------(I)\n";
        cout << "\t(2)--Remove A Student----------(R)\n";
        cout << "\t(3)--Peek A Student's Grades---(P)\n";
        cout << "\t(4)--Find Students Average-----(A)\n";
        cout << "\t(5)--Find Students Grade-------(G)\n";
        cout << "\t(6)--Clear Student Roster------(C)\n";
        cout << "\t(7)--Exit----------------------(E)\n";
        cout << "\n\tWhat would you like to do? ";cin >>choice;
        choice = toupper(choice);
        cin.ignore();
        if (choice == '1' || choice == 'I')
            list.Add();
        else if ( choice == '2' || choice == 'R') {
            if( list.Remove() == true)
			{ cout << "\n\tYour input has been removed"; cin.get(); }
            else { cout << "\n\tYour List is either empty \n\tOr you attempted to delete from out of Bounds";cin.get();}
		}
 		else if ( choice == '3' || choice == 'P')
            list.Peek();
        else if ( choice == '4' || choice == 'A')
            list.Average(); 
        else if ( choice == '5' || choice == 'G')
            list.Grade();
        else if ( choice == '6' || choice == 'C'){
            list.Clear(); cin.get();}
        else if( choice == '7')
        		return;
        }
}

