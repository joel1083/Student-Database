#include "Node.h"
#include "thisisatest.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// This function relies on the use of the Reader class to sort the file prior to adding it into the linked list
void LinkedList :: Add() 
{   
	Reader r1;
	r1.setdata();
	r1.AscendSort();
	r1.PrintPass();
	
	ifstream fin ("sort.txt");
	
	int idnum[15];
	string n[15];
    int t1[15];
	int t2[15];
	int t3[15];
	
	for (int i = 0; i < 15; i++){
	   	fin >> idnum[i];
	   	fin.get();
	   	getline(fin, n[i]);
	   	fin >> t1[i];
	    fin >> t2[i];
   	    fin >> t3[i];
	}
	
	// Instantiates a new pre-sorted node
	for ( int i =0; i < 15; i++){
    	Node* newnode = new Node(idnum[i],n[i],t1[i],t2[i],t3[i]);
    	newnode->setpointer(head);
    	head = newnode;
    	counter++;
	}
}	

// This method will traverse through the linked list to find the average of all entries fiound in the sorted linked list
void LinkedList :: Average()
{
	Node *current = head;

	int average;
	
	while(current != NULL)
	{
		average = ( current->getTest1() + current->getTest2() + current->getTest3() ) / 3;
		cout << "\n\tStudent ID: " << current->getID() <<" Average : " << average;
		current = current->nextpointer();
	}
	
	cin.get();	
}

// This method will traverse through the linked list to find the grade of all entries fiound in the sorted linked list
void LinkedList :: Grade()
{

	Node *current = head;
	
	int average;
	
	while(current != NULL)
	{
		average = ( current->getTest1() + current->getTest2() + current->getTest3() ) / 3;
		if(average > 90 )
			cout << "\n\tStudent ID: "<< current->getID() << " has a(n) A!";
		else if(average > 80 )
			cout << "\n\tStudent ID: "<< current->getID() << " has a(n) B!" ;	
		else if(average > 70 )
			cout << "\n\tStudent ID: "<< current->getID() << " has a(n) C!";
		else if(average > 60 )
			cout << "\n\tStudent ID: "<< current->getID() << " has a(n) D!";
		else
			cout << "\n\tStudent ID: " << current->getID() << " has failed :(";
		current = current->nextpointer();
	}
	cin.get();
}

// This method takes the necessary precaution of checking to see if the list is empty, to which will set a flag detailing that the list is empty
bool LinkedList :: isEmpty()
{
	if (head == NULL)
		return true;
	return false;	
}

// This method will ask the client for a specified name to distinguish where the targeted location is in the linked list and will then print the user's target.
void LinkedList :: Peek()
{
	string n;
	cout << "\n\tPlease enter a Student Name: ";
	getline(cin,n);
	
	Node *current = head;
	
	while(current != NULL)
	{
		if (n == current->getName())
		{
			cout << "\n\tHere's His/Her Grade on Test 1 : " << current->getTest1();
			cout << "\n\tHere's His/Her Grade on Test 2 : " << current->getTest2();
			cout << "\n\tHere's His/Her Grade on Test 3 : " << current->getTest3();
			cin.get();
			return;
		}
		current = current->nextpointer();
	}
	cout << "\n\tList is Unchanged... Your Entry does NOT EXIST!";	
	cin.get();	
}


// This prints the linked list until it reaches NULL
void LinkedList :: Print(Node *temp)
{ 
	if ( temp == NULL ) 
    	{
        cout << "\n\tYour information ends here...." << endl;
    	}															
    	else
			{
          	temp->getnode();
		  	Print(temp->nextpointer()); // recursive function call to the next temp node   
        	}
}
		
// This function will clear the linked list and will display a message after it has finished removing all nodes
void LinkedList :: Clear()
{ 
	Print(head);
	Node *temp = head;
	
    while(temp != NULL) 
	{
           temp = head->nextpointer();
           delete head;
           head = temp;
   }
    cout << "\n\tThe information has been cleared.";
}	

// This function will first call the isEmpty method and will return false if either category returns false; if the node is empty or if the position the user is looking for is out of bounds.
// If the user wants to remove the function will remove the selected data in the linked list
bool LinkedList :: Remove() 
{
	Node *temp;
	Node *curr=head;
	int position;
	
	if (isEmpty() == true )
	{
		return false; 
	}
  
  cout << "Please enter the position you'd like to delete: (0-14) "; cin >> position;
  
  if (position >= counter) // Position is out of bounds
  {
  	return false;
  }
  
  while (counter < position)
  {
  		curr = curr->nextpointer();
  }
  
  temp = curr->nextpointer();
  curr->setpointer(temp->nextpointer());
  
  delete temp;
  head = curr;
  
  return true;
  
}

