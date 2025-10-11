/*
 ============================================================================
 Name        : LL_using_Stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <stdbool.h>
uint8_t count1 =0,count2=0,temp;
int num;
#define MAX 5
#define s1 0
#define s2 1
	int stack1[5];
	int stack2[5];
void push(bool a,int n){

	if(a){
		if(count1>=5){
			printf("Queue is full\n");
		}
		else{
		stack1[count1++]=n;
		}

	}
	else{

		if(count2>=5){
					printf("Queue is full\n");
				}
				else{
				stack2[count2++]=n;
				}

	}

}
int pop(bool a){
	if(a){
		if(count1==0){
			printf("queue is empty\n");
			return -1;
		}
		else
		return stack1[--count1];

	}
	else{
		if(count2==0){
					printf("queue is empty\n");
					return -1;
				}
				else
				return stack2[--count2];

	}



}

void enqueue(int a){
	push(s1,a);


}
void dequeue(void){
//	temp=count1;
	while(count1!=0){
		num=pop(s1);
		push(s2,num);

	}
	num=pop(s2);
	printf("dequed element is %d\n",num);

//	temp=count2;
	while(count2!=0){
		num=pop(s2);
		push(s1,num);

	}


}
int main(void) {

	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	dequeue();
	dequeue();


	return 0;
}
