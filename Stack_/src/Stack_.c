/*
 ============================================================================
 Name        : Stack_.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
uint8_t curr_pos=0;
uint8_t max_stack=5;
struct node {
		int data ;
		struct node * nextnode;
	};
struct node *newnode,*temp,*top=NULL;

void display(void){
	temp=top;

	while(temp!=NULL){
		printf("content of stack is %d\n",temp->data);
		temp=temp->nextnode;


	}


}
void peek(void){
	printf("top element is %d\n",top->data);

}

void pop(void){

	if(curr_pos<=0){
	    printf("bsdk abh kya gand mai ghusega ?? underflow hojayega! \n");

	}
	else{
	temp=top;
	top=top->nextnode;
	printf("%d\n",temp->data);
	free(temp);
	 curr_pos--;
	}



}
void push(void){

	if(curr_pos>max_stack){
	    printf("bsdk overflow hojeyega /n!! ");

	}
	else{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->nextnode=NULL;
	printf("enter the data you want to push into stack \n");
	scanf("%d",&newnode->data);
    newnode->nextnode=top;
	top=newnode;
	curr_pos++;
	}

}

int main(void){

push();
push();
display();
peek();
push();
display();
peek();
//pop();

//

	return 0;
}
