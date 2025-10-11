/*
 ============================================================================
 Name        : Queue_Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#define MAX_SIZE 5
	int queue[MAX_SIZE];
	uint32_t *Head=(uint32_t*)queue,*Tail=(uint32_t*)queue;
     uint8_t count=0;
void enqueue(uint32_t data ){
	if (count==MAX_SIZE){
		printf("overflow hogya !!\n");
	}
	else{
	    	*Tail=data;
	Tail++;
	count++;

	}

}
void dequeue(void ){
	if(Tail==0&&Head==0){
		printf("underflow condition ");

	}
	else if (Head=Tail){
		Head=0;
		Tail=0;
	}
	else{
		printf("%d\n",*Head);
		count--;
		Head++;

	}


}

int main(void) {
enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
enqueue(5);
enqueue(6);
dequeue();
dequeue();
dequeue();
dequeue();
dequeue();
dequeue();



	return 0;
}
