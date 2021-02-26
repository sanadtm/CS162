// Sanad Thapa
// CS 162 - Program 5
//The purpose of the 5th program is to implement the new concepts learned which include linear linked lists. 
//Our goal is to continue to create programs with a small main function that delegates to a series of functions where the real work takes place. 
//Unlike the previous programs,this program should focus in on creating, modifying and removing data from a linear linked list. 

#include "header.h"
list::list() // COnstructor that initializes the Data members
{
	head =NULL;

}
list::~list() // Destructor that deletes all the allocated memory
{
	if(head) // If there is a LIST call the Delete ALL FUNCTION TO DEALLOCATE the MEMORY
		delete_all();
}

// The Function that Inserts the item in the list
void list::insert(char * favorite, char *description, char *how_often )
{ 
	int len0=0,len1=0,len2=0;
	// CASE 1 : NO LIST
	if(!head)// If there is no HEAD Start the list by making a new node
	{
		head =new node;
		// COPYING THE DATA into the node	
		len0=strlen(favorite);
		head->fav = new char[len0+1]; //Dynamiclly Allocating array
		strcpy(head->fav,favorite);

		len1= strlen(description);
		head->des = new char[len1+1]; //Dynamically Allocated array
		strcpy(head->des,description);

		len2= strlen(how_often);
		head->often = new char[len2+1]; // Dynamically Allocated Array
		strcpy(head->often,how_often);
		head->next =NULL;
		return;
	}
	else
		// CASE 2 : If there is Already an Existing LIST
	{
		node * temp =new node;
		// COPYING THE DATA into the node	
		len0=strlen(favorite);
		temp->fav = new char[len0+1]; // Dynamically Allocated Araay  
		strcpy(temp->fav,favorite);

		len1= strlen(description);
		temp->des = new char[len1+1]; // Dynamically Allocated Array
		strcpy(temp->des,description);

		len2= strlen(how_often);
		temp->often= new char[len2+1]; // Dynamic Allocated Array
		strcpy(temp->often,how_often);
	
		temp->next =head;
		head =temp;
		return;
	}
}

// THE Function that searches and deletes the item in the list
void list::search_delete(char *activity)
{
	if(!head)// Base Case check to avoid SEG FAULT
	{
		cout << "There is no item in the list to SEARCH \n";	
		return;
	}
	if(!head->next && strcmp(head->fav,activity)==0) // Checking if there if only one Node with matching data inside
	{
		delete head;
		head=NULL;
		return;
	}
	// Checking if head has the Matching data
	if(strcmp(activity,head->fav)==0)
	{
		node * temp = head->next;
		delete head;
		head=temp;
		return;
	}

	// Checking matching data for the rest of the list 
	node * curr=head->next;
	node * prev = head;

	while(curr)// Checking until the end of the LIST
	{
		if(strcmp(activity,curr->fav)==0)// Comparing the Activity NAMES
		{
			cout << "Acvitivity Found!! \n";
			cout << "****Deleting IT NOW!!!!!!!\n";
			if(curr->next)// Checking if the curr's next is NULL before moving it
			{
				prev->next=curr->next;// Previous next pointer is skipping curr and pointing to curr next node
				delete curr;
				curr = prev;
				return;
			}else if(!curr->next)// IF curr next if NULL then no need to move it
			{
				delete curr;
				prev->next =NULL;
				return;
			}
			return;	
		}
		// Traversing Both pointers
		prev=curr;	
		curr = curr->next;
	}
	cout << "ACTIVITY NOT FOUND \n";
}
// Function to display all the items from the LIST
void list::display_all()
{
	if(!head)// Base Case Check
	{
		cout << "THe List is EMPTY\n";
		return;
	}else // IF there is a LIST start Displaying the LIST
	{
		node * curr =head;
		while(curr !=NULL)
		{
			cout <<" :: "<< curr->fav <<endl;
			cout <<" :: "<< curr->des <<endl;
			cout <<" :: "<< curr->often <<endl;
			cout << "-----------------\n";
			curr=curr->next;
		}
	}
}
// Function that Deletes  all the Items in the LIST
void list::delete_all()
{
	while(head) // IF there is a LIST START DETELING THE ITEMS
	{
		node * curr=head->next;
		delete head;
		head=curr;
	}
	if(!head)
		cout << "ALL ITEMS ARE DELETED and the LIST IS EMPTY\n";
}

// THE Function that Counts TOTAL Item on the LIST
int list::cnt()
{
	int count=0;
	if(!head)return 0;
	node * curr = head;
	while(curr)
	{
		++count;
		curr =curr->next;	
	}
	return count; // Returning the COUNT
}
