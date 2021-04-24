/*********************************************************************************
** Program: list.h
** Author: Megan McCormick
** Date: 06/06/2015
** Description: All functions for list
** Input: None
** Output: None
**********************************************************************************/
#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>
struct node {
	int val;
	struct node *next;
	struct node *prev;
};
//Implemented in Lab #9, but now return new head address
int length(struct node *);
void print(struct node *,int );
struct node * push(struct node *, int); //put at front
struct node * append(struct node *,struct node *, int); //put at back
struct node * clear(struct node *);
struct node * removenode(struct node *, int);
struct node * sort_ascending(struct node *);
struct node * sort_descending(struct node *);
//insert into a specific location in the list
struct node * insert_middle(struct node *, int, int);
int ascending(struct node*);
int descending(struct node*);
#endif 