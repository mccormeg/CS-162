#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int length(struct node *head){
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
	count++;
	current = current->next;
	}
	return count;

}
void push(struct node **headRef, int data){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = data;
	newNode->next = *headRef; 
	*headRef = newNode; 
}
void append(struct node **headRef, int num){
	struct node* current = *headRef;
	struct node* newNode;
	newNode = malloc(sizeof(struct node));
	newNode->val = num;
	newNode->next = NULL;
	if (current == NULL) {
		*headRef = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

}
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