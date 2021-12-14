#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
int FRONT=-1, REAR=-1;

void enq(int que[], int data){
	if(REAR>=SIZE)	{printf("\nQueue Overflow !\n"); return;}
	if(FRONT=-1) FRONT=0;
	que[++REAR]=data;
}

void deq(int que[]){
	if(FRONT>=SIZE || FRONT<0) { printf("\nQueue Underflow !\n"); return;}
	
	printf("\n%d deleted Succesfully.\n", que[FRONT++]);
}

void display(int que[]){
	if(FRONT==-1) {printf("\n-X- Queue is not Initialized ! Initialize it by pressing 1.\n"); return;}
	
	int i;
	printf("\n[");
	for(i=FRONT; i<=REAR; i++) printf(" %d, ", que[i]);
	printf("]\n");
}

int main(){
	int q[SIZE], ch, data;
	do{
		printf("\n - - - - - QUEUE - - - - - \n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Choose Your Option: ");
		scanf("%d", &ch);
		
		switch(ch){
			int no;
			case 1:
				printf("\nHow Many data you want to insert: ");
				scanf("%d", &no);
				printf("\nEnter %d Data to insert in Queue: ", no);
				while(no-->0) { scanf("%d", &data); enq(q, data);}
				
				break;
			case 2:
				deq(q);
				break;
			case 3:
				display(q);
				break;
			case 4:
				printf("\nExiting . .\n");
				exit(0);
				break;
		}
	}while(1);
	
	return 0;
}
