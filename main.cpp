// Sanad Thapa
// CS 162 - Program 5
//The purpose of the 5th program is to implement the new concepts learned which include linear linked lists. 
//Our goal is to continue to create programs with a small main function that delegates to a series of functions where the real work takes place. 
//Unlike the previous programs,this program should focus in on creating, modifying and removing data from a linear linked list. 

#include "header.h"
int main()
{
	list my_list;// Declaring the List variable;
	int choice;
	int res=0, len3=0;
	//Declaring the required char variable
	char favorite[SIZE], description[SIZE], how_often[SIZE];
	char *search;
	cout << "**********MENU**********\n";
	cout << "1. ADD item to the LIST\n";
	cout << "2. Search Item in the list AND DELETE IT \n";
	cout << "3. DISPLAY ALL the Items \n";	
	cout << "4. Count ALL ITEMS\n";
	cout << "5. Delete THE WHOLE LIST \n";
	cout << "6. EXIT \n";

	do{
		cout << "Enter Choice :: \n";
		cin >>  choice;
		cin.ignore();
		switch(choice)
		{
			case 1: 
				// ADD ITEM in LINKED LIST
				cout << "Enter you favorite thing to do \n";
				cin.get(favorite,SIZE,'\n');
				cin.ignore();

				cout << "Enter Description for this\n";
				cin.get(description,SIZE,'\n');
				cin.ignore();
				
				cout << "Enter HOw often do you want to do it\n";
				cin.get(how_often,SIZE,'\n');
				cin.ignore();
				my_list.insert(favorite,description, how_often);
				break;
			case 2:
				char s[SIZE];
				// SEARCH FOR ITEM IN LINKED  LIST to DELETE	
				cout << "Enter ACtivity TITLE to Delete \n";
				cin.get(s,SIZE,'\n');
				cin.ignore();
				len3= strlen(s);
				search = new char[len3+1];
				strcpy(search, s);
				my_list.search_delete(search);
				break;
			case 3:
				// Display all the EXISTING ITEM
				my_list.display_all();
				break;

			case 4:
				// Counting Total Items in the LIST
				res=my_list.cnt(); // Catching the value from te Function to a Variable
				if(res == 0)
					cout <<"There are NO items in the list to COUNT :: " << res <<endl;
				else 
					cout << "Number of Items in the List:: " <<res <<endl;
				break;
			case 5:
				// Delete all the items
				my_list.delete_all();
				break;
			case 6:
				cout << "Exiting PROGRAM!!! \n";
				break;
			default:
				cout << "Invalid Input Enter Again\n";
				break;
		}
	}while (choice !=6);
	return 0;
}
