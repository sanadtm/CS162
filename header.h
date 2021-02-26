// Sanad Thapa
// CS 162 - Program 5
//The purpose of the 5th program is to implement the new concepts learned which include linear linked lists. 
//Our goal is to continue to create programs with a small main function that delegates to a series of functions where the real work takes place. 
//Unlike the previous programs,this program should focus in on creating, modifying and removing data from a linear linked list. 
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
// GLOBAL CONSTANTS
int const SIZE = 200;
int const LIST_SIZE=20;
struct node
{
	char *fav, *des, *often; //Dynamically Allocated CHAR ARRAYS
	node *next;
};

// MY CLASS for the Linked LIST
class list
{
	public:
		// Functions prototypes
		list();
		~list();
		void insert(char [],char [],char []);
		void search_delete(char *);
		void display_all();
		void delete_all();
		int cnt();

	private:
		node *head;// POinter to a head node
};
