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
	if(head==NULL&&tail==NULL){
    head=newnode;
	   tail=newnode;
	    tail->data=a;
	}
	else{
	    temp=tail;
	 tail=newnode;
    tail->data=a;
    //temp=tail;
    temp->nextnode=newnode;


	}

    //temp->nextnode=tail;}

}

void dequeue(void){
	if(head==NULL&&tail==NULL || head==NULL){
		printf("nothing in a queue\n");
		head=NULL;
		tail=NULL;
	}
	else{
		temp=head;
		printf("%d\n",head->data);
		head=head->nextnode;
		free(temp);
	}
}
int main(void) {

	dequeue();
	enqueue(1);
	enqueue(2);
	enqueue(3);

	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	enqueue(3);
	enqueue(4);
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
