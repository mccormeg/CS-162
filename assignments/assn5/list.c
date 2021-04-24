/*********************************************************************************
** Program: list.c
** Author: Megan McCormick
** Date: 06/06/2015
** Description: All functions for list
** Input: None
** Output: None
**********************************************************************************/
#include "list.h"
/*********************************************************************************
** Function: length
** Description: returns the length of the linked list 
** Parameters: struct node *head
** Pre-Conditions: none
** Post-conditions: returns length
*********************************************************************************/
int length(struct node *head){
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
	count++;
	current = current->next;
	}
	return count;
}
/*********************************************************************************
** Function: newNode
** Description: creates a new node
** Parameters: int x 
** Pre-Conditions: no node
** Post-conditions: new node
*********************************************************************************/
struct node* newnode(int x) {
	//creates a new node and sets all pointers to NULL for the time being
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
/*********************************************************************************
** Function: print
** Description: Prints the linked list
** Parameters: struct node *head, int num
** Pre-Conditions: none
** Post-conditions: Printed linked list
*********************************************************************************/
void print(struct node *head, int num){
	printf("Length: %d \n", num);
	struct node* current = head;
	printf("Your list: ");
	while (current != NULL){
		printf(" %d ",current->val);
		current = current->next;
	}
	printf("\n");
}
/*********************************************************************************
** Function: push
** Description: pushes a new node to the head of the list
** Parameters: struct node *headRef, int data
** Pre-Conditions: Normal list
** Post-conditions: List with a new head
*********************************************************************************/
struct node * push(struct node *headRef, int data){
	struct node* newNode = newnode( data);
	newNode->next = headRef; 
	headRef = newNode; 
	return newNode;
}
/*********************************************************************************
** Function: append
** Description: puts a new node at the end
** Parameters: struct node *headRef,struct node *tailRef, int num
** Pre-Conditions: Normal list
** Post-conditions: List with new tail
*********************************************************************************/
struct node * append(struct node *headRef,struct node *tailRef, int num){
	struct node* current = headRef;
	struct node* newNode;
	newNode = newnode(num);
	//Appends to the front if the first node
	if (current == NULL) {
		headRef = newNode;
		newNode->prev = current;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
	return headRef;

}
/*********************************************************************************
** Function: clear
** Description: Clears the entier linked list
** Parameters: struct node *headRef
** Pre-Conditions: Full linked list
** Post-conditions: No linked list
*********************************************************************************/
struct node * clear(struct node *headRef){
	//Clears all nodes
   struct node* current = headRef;
   struct node* next;
 
   while (current != NULL) 
   {
       next = current->next;
       free(current);
       current = next;
   }
   
  
   headRef = NULL;
}
/*********************************************************************************
** Function: removenode
** Description: removes a single node from the list
** Parameters: struct node *headRef, int num
** Pre-Conditions: Linked list
** Post-conditions: Linked list minus 1 node
*********************************************************************************/
struct node * removenode(struct node *headRef, int num){
	//Takes in the value of the node
	int counter = 0,pos;
	struct node* current = headRef;
	struct node* rest = headRef;
	//Finds the value
	while (current != NULL) {
		if(current->val == num){
			pos = counter;
			break;
		}
		else{
			current = current->next;
			counter++;
		}
		
	}
	counter = 0;
	current = headRef;
	//If the position is at the beginning, uses the next node as the head
	if (pos == 0){
		rest= rest->next;
		headRef = rest;
	}
	//Otherwise find the node before it and reconnect to the node after it.
	else{
		while(counter != pos-1){
			current= current->next;
			rest = rest->next;
			counter++;
		}
		rest = rest->next;
		rest = rest->next;
		current->next = rest;
	}
	return headRef;
}
/*********************************************************************************
** Function: sort_ascending
** Description: Sorts in ascending order
** Parameters: struct node *headRef
** Pre-Conditions: Linked list
** Post-conditions: Sorted linked list
*********************************************************************************/
struct node * sort_ascending(struct node *headRef){
	int holder;
	struct node* current = headRef;
	struct node* nextnode = current->next;
	do{
		while(nextnode !=NULL){
			if(current->val < nextnode->val){
				current = nextnode;
				nextnode = nextnode->next;
			}
			else if(current->val > nextnode->val){
				holder = current->val;
				current->val = nextnode->val;
				nextnode->val = holder;
				current = nextnode;
				nextnode = nextnode->next;
			}
			else {
				current = nextnode;
				nextnode = nextnode->next;
			}
		}
		current = headRef;
		nextnode=current->next;
	}while(ascending(headRef)!= 1);
	return headRef;
}
/*********************************************************************************
** Function: sort_descending
** Description: Sorts descending
** Parameters: struct node *headRef
** Pre-Conditions: Unsorted list
** Post-conditions: Sorted list in descending order
*********************************************************************************/
struct node * sort_descending(struct node *headRef){
	int holder;
	struct node* current = headRef;
	struct node* nextnode = current->next;
	do{
		//Keeps sorting until the number are in order
		while(nextnode !=NULL){
			//Switches values if the one before is bigger than the next one
			if(current->val > nextnode->val){
				current = nextnode;
				nextnode = nextnode->next;
			}
			else if(current->val < nextnode->val){
				holder = current->val;
				current->val = nextnode->val;
				nextnode->val = holder;
				current = nextnode;
				nextnode = nextnode->next;
			}
			else {
				current = nextnode;
				nextnode = nextnode->next;
			}
		}
		current = headRef;
		nextnode=current->next;
	}while(descending(headRef)!= 1);
	return headRef;
}
/*********************************************************************************
** Function: insert_middle
** Description: Inserts a node in the position that the user specifies. 
** Parameters: struct node *headRef, int pos, int num
** Pre-Conditions: Linked list
** Post-conditions: Linked list plus new node in the middle
*********************************************************************************/
//insert into a specific location in the list
struct node * insert_middle(struct node *headRef, int pos, int num){
	int counter = 1;
	struct node* current = headRef;
	struct node* rest = headRef;
	struct node* newNode;
	newNode = malloc(sizeof(struct node));
	newNode->val = num;
	//Puts node in the position specified by the user 
	if (pos <= length(headRef)-1) {
		while (counter != pos) {
			current = current->next;
			rest = rest->next;
			counter++;
		}
		rest = rest->next;
		newNode->next = rest;
		current->next = newNode;
		
	}
	else{
		printf("That position isn't in the list. \n");
	}
	return headRef;
}
/*********************************************************************************
** Function: ascending
** Description: Checks that the list is ascending correctly
** Parameters: struct node*headRef
** Pre-Conditions: None
** Post-conditions: Value corresponding to if the list is sorted.
*********************************************************************************/
int ascending(struct node*headRef){
	int first,next, i = 0;
	first = headRef->val;
	//Checks that all the nodes are in the correct place 
	struct node* current = headRef;
	while(current->next != NULL){
		current = current->next;
		next = current->val;
		if(first >next){
			i = 0;
			break;
		}
		else {
			i = 1;
		}
		first = next;
	}
	if (i == 1){
		return 1;
	}
	else{
		return 0;
	}
}
/*********************************************************************************
** Function: descending
** Description: Checks that the list is descending correctly
** Parameters: struct node*headRef
** Pre-Conditions: None
** Post-conditions: Value corresponding to if the list is sorted.
*********************************************************************************/
int descending(struct node*headRef){
	int first,next, i = 0;
	first = headRef->val;
	struct node* current = headRef;
	//Checks that all the nodes are in the correct place 
	while(current->next != NULL){
		current = current->next;
		next = current->val;
		if(first<next){
			i = 0;
			break;
		}
		else {
			i = 1;
		}
		first = next;
	}
	if (i == 1){
		return 1;
	}
	else{
		return 0;
	}
}