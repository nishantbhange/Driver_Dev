/*
 * main.c
 *
 *  Created on: Sep 12, 2025
 *      Author: nisha
 */


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
 struct node {
	int data ;
	struct node *Prev_Node;
	struct node *Next_Node;
};
 int Y_N=1;
 struct node *head=NULL,*nextnode,*temp,*tail;
 void Reverse_Doubly_Linked_List(void){
	 temp=head;
	 head=tail;
	 tail=temp;
	 while(temp!=NULL){

		 nextnode=temp->Next_Node;
		 temp->Next_Node=temp->Prev_Node;
		 temp->Prev_Node=nextnode;
		 temp= temp->Next_Node;

	 }
	 temp=head;
	 while(temp!=NULL){
	  printf("content of reversed doubly linked list is %d\n\n",temp->data);
	  temp=temp->Next_Node;
	 }
 }

void Insert_Element_Anywhere(void){
	int pos=0;
	int size=0;
	int count=1;
	temp=head;
	while(temp!=NULL){
		size++;
		temp=temp->Next_Node;
		}
	        nextnode=(struct node *)malloc(sizeof(struct node));
	        nextnode->Next_Node=NULL;
	        nextnode->Prev_Node=NULL;
		 	printf("#enter the data you want to insert in random position of doubly linked list\n");
		 	scanf("%d",&nextnode->data);
		 	printf("#enter the position at which you want to insert element in doubly linked list\n");
		 	scanf("%d",&pos);
		 	if (pos>size||pos<1){
		 		printf("BSDK Gand mar lunga agar agli baar Backchodi ki toh!\n");

		 	}
		 	else{
		 		temp=head;
		 		while(count<pos-1){
		 			count++;
		 			temp=temp->Next_Node;
		 			}
		 	nextnode->Next_Node=temp->Next_Node;
		 	nextnode->Prev_Node=temp;
		 	temp->Next_Node=nextnode;
		 	temp=nextnode->Next_Node;
		 	temp->Prev_Node=nextnode;
	}
	temp=head;
while(temp!=NULL){
 printf("content of doubly linked list is %d\n\n",temp->data);
 temp=temp->Next_Node;
}

}
 void Insert_Element_Front(void){
	 Y_N=1;
	while(Y_N){

	 nextnode=(struct node *)malloc(sizeof(struct node));
	 	printf("#enter the data you want to insert in front of doubly linked list\n");
	 	scanf("%d",&nextnode->data);
	 	nextnode->Next_Node=NULL;
	 	nextnode->Prev_Node=NULL;

	 	nextnode->Next_Node=head;
	 	head=nextnode;
	 	printf("you still wanna continue(1/0)?");
	 	scanf("%d",&Y_N);

	}
		temp=head;
	while(temp!=NULL){
 printf("content of doubly linked list is %d\n\n",temp->data);
 temp=temp->Next_Node;
}
 }

 void Create_Doubly_Linked_List(void){
	while(Y_N){
	nextnode=(struct node *)malloc(sizeof(struct node));
	printf("#enter the data you want to put in doubly linked list\n");
	scanf("%d",&nextnode->data);
	nextnode->Next_Node=NULL;
	nextnode->Prev_Node=NULL;
	if(head==NULL){
		head=nextnode;
		temp=head;


	}
	else{
		temp->Next_Node=nextnode;
		nextnode->Prev_Node=temp;
		temp=temp->Next_Node;

	}
	printf("you want to add more ? (0,1)\n");
	scanf("%d",&Y_N);
	}
	tail=temp;
	temp=head;
while(temp!=NULL){
 printf("content of doubly linked list is %d\n\n",temp->data);
 temp=temp->Next_Node;
}}



int main (){
	Create_Doubly_Linked_List();
	Insert_Element_Front();
	Insert_Element_Anywhere();

	return 0 ;
}
