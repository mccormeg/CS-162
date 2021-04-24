#include "merge.h"
#include<stdio.h>
#include<stdlib.h>

int length(struct node *);
void print(struct node *,int );
struct node * push(struct node *, int); //put at front


int main(){
	char ans[2];
	int num,pos;
	//pointer to the head
	struct node *head=NULL;
	struct node *first1 = NULL;
	struct node *first2 = NULL;

		
		do {
			//creates initial list
			printf("Enter a number: ");
			scanf("%d", &num);
			head= push(head, num);//Can change to append
			printf("Do you want another num (y or n): ");
			scanf("%1s",ans);
		} while(ans[0] == 'y');
		first1 = head;
	
		mergeSort(&first1,&first2);
		printf("Sorted List: \n");
		print(first1, length(first1));	
		printf("End of list: \n");
		print(first2, length(first2));	
 return 0;
}
int length(struct node *head){
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
	count++;
	current = current->next;
	}
	return count;
}
void print(struct node *head, int num){
	printf("Length: %d \n", num);
	struct node* current = head;
	printf("Your list: ");
	while (current != NULL){
		printf(" %d ",current->info);
		current = current->next;
	}
	printf("\n");
}
struct node * push(struct node *headRef, int data){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->info = data;
	newNode->next = headRef; 
	headRef = newNode; 
	return newNode;
}