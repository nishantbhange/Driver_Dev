/*
 ============================================================================
 Name        : Queue_LL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

struct node{
	int data ;
	struct node * nextnode;

};

struct node *newnode,*head=NULL,*tail=NULL,*temp;

void enqueue(int a ){

	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->nextnode=NULL;
	 newnode->data=a;
	if(head==NULL&&tail==NULL){
   head=newnode;
   tail=newnode;
   tail->nextnode=newnode;


	}
	else{
	   tail->nextnode=newnode;
	   tail=newnode;

       newnode->nextnode=head;
         }



}

void dequeue(void){
	if(head==NULL&&tail==NULL ){
		printf("nothing in a queue\n");
		head=NULL;
		tail=NULL;
	}
	else if(head==tail){
		printf("%d\n",head->data);
		free(head);
		head=NULL;
		tail=NULL;
	}

	else{
		printf("%d\n",head->data);
		temp=head;
		head=head->nextnode;
		tail->nextnode=head;
		free(temp);
	}
}
int main(void) {

	dequeue();
	enqueue(1);
	enqueue(2);
	dequeue();
	dequeue();
	dequeue();
	enqueue(3);

    dequeue();
	dequeue();
	dequeue();


	return 0;
}
