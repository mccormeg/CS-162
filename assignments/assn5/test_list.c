/******************************************************
** Program: test_list.c
** Author: Megsn McCormick
** Date: 06/06/2015
** Description: Creates a linked list
** Input: value
** Output: Ordered values
******************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main (){
	char ans[2];
	int num,pos;
	//pointer to the head
	struct node *head = NULL;
	//pointer to the tail
	struct node *tail = NULL;

	do {
		do {
			//creates initial list
			printf("Enter a number: ");
			scanf("%d", &num);
			head = append(head,tail, num);//Can change to append
			printf("Do you want another num (y or n): ");
			scanf("%1s",ans);
		} while(ans[0] == 'y');
		//sorts list
		printf("Sort ascending or descending (a or d)? ");
		scanf("%1s",ans);
		if(ans[0] == 'a') 
			head=sort_ascending(head);
		else if(ans[0] == 'd') 
			head=sort_descending(head);
		else{
			printf("That was not an option, stop breaking things \n");
			exit(-1);
		}
		print(head, length(head));
			do {
				//removes unwanted nodes
			printf("Would you like to remove a node?(y or n)");
			scanf("%1s", ans);
			if(ans[0] == 'y'){
				printf("Which node would you like to remove(value of that node)?");
				scanf("%d",&num);
				head = removenode(head,num);
				print(head, length(head));
			}
			else{
				break;
			}
				
			printf("Do you want to remove another node(y or n): ");
			scanf("%1s",ans);
			print(head, length(head));
		} while(ans[0] == 'y');

		do {
			//adds extra nodes
			printf("Would you like to add a node?(y or n)");
			scanf("%1s", ans);
			if(ans[0] == 'y'){
				printf("Where would you like to place it?");
				scanf("%d",&pos);
				printf("What is the value?");
				scanf("%d",&num);
				head = insert_middle(head,pos,num);
				print(head, length(head));
			}
			else{
				break;
			}
				
			printf("Do you want to add another node?(y or n): ");
			scanf("%1s",ans);
			print(head, length(head));
		} while(ans[0] == 'y');
		
		//will run untill the user doesn't want to 
		printf("Do you want to do this again (y or n)? ");
		scanf("%1s",ans);
		if(ans[0] == 'y') head = clear(head);
	} while(ans[0] == 'y');
 return 0;
}
