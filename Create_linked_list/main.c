/*
 * main.c
 *
 *  Created on: Sep 10, 2025
 *      Author: nishant
 */
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node *head , *nextptr, *temp;
uint8_t Y_N=1;

void Reverse_Linked_List(void){
	struct node *Prev_Ptr , *Curr_Ptr , * Next_Ptr;
	Prev_Ptr=head;
	Curr_Ptr=Prev_Ptr->next;
	Next_Ptr=Curr_Ptr;
	Prev_Ptr->next=NULL;
	while(Next_Ptr !=NULL){
		Next_Ptr=Next_Ptr->next;
		Curr_Ptr->next=Prev_Ptr;
		Prev_Ptr=Curr_Ptr;
		Curr_Ptr=Next_Ptr;

	}
	head=Prev_Ptr;
	temp=head;
		while(temp!=NULL){
			printf("element of reversed linked list is %d \n\n", temp->data);
			temp=temp->next;
		}


}

void Create_Linked_List(){

	head=NULL;
	while(Y_N){

		nextptr=(struct node * )malloc(sizeof(struct node));
		printf("enter the data you want to put into linkedlist ");
		scanf("%d",&nextptr->data);
		nextptr->next=NULL;

	if (head==NULL){
		head=nextptr;
		temp=head;
	}
	else{
	 temp->next=nextptr;
	 temp=nextptr;
	}
	printf("you wanna add more data into linkedlist?(0,1) ");
	scanf("%d",(int*)&Y_N);
	}
	temp=head;
	while(temp!=NULL){
		printf("element of linked list is %d \n\n", temp->data);
		temp=temp->next;
	}
}
void Add_Element_On_Start(){
	Y_N=1;
	while(Y_N){
	nextptr=(struct node *)malloc(sizeof(struct node *));
	nextptr->next=NULL;
	printf("enter the element you want to add on start of linked list ");
	scanf("%d",& nextptr->data);
	nextptr->next=head;
	head=nextptr;
	printf(" you wanna add more ? (1,0)");
		scanf("%d",&Y_N);
	}

}
void Add_Element_On_End(){

	Y_N=1;
	while(Y_N){
		temp=head;
			while(temp->next !=NULL){
				temp=temp->next;

			}
	nextptr=(struct node *)malloc(sizeof(struct node *));
	nextptr->next=NULL;
	printf("enter the element you want to add on start of linked list ");
	scanf("%d",& nextptr->data);
	temp->next=nextptr;
	printf(" you wanna add more ? (1,0)");
	scanf("%d",&Y_N);
	}


}
void Add_Element_Inbw(){}

int main(void){



Create_Linked_List();
Add_Element_On_Start();
Add_Element_On_End();
 Add_Element_Inbw();


return 0;
}

