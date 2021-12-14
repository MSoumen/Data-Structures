#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
int FRONT=-1,REAR=-1;

void enq(int q[], int data){
	if((FRONT==0 && REAR==(SIZE-1)) || (FRONT==REAR+1)) { printf("\nOverflow!\n"); return;}
	if(FRONT!=0 && REAR==(SIZE-1)) {REAR=0; q[REAR]=data;}
	else q[++REAR]=data;
	
	if(FRONT==-1) FRONT=0;
	
}

void deq(int q[]){	
	if(FRONT==-1) {printf("\nUnderflow !\n"); return;}
	int tmp;
	if(FRONT == REAR){
		tmp=q[REAR];
		FRONT=REAR=-1;
	}
	else if(FRONT==(SIZE-1)){
		tmp = q[FRONT];
		FRONT=0;
	}
	else tmp=q[FRONT++];
	
	printf("\n%d deleted Sucessfully.\n", tmp);
}

void display(int q[]){
	if(FRONT==-1 && REAR==-1) { printf("\nERROR: Queue is not initialized.\n"); return;}
	int i;
	printf("\n[ ");
	if(FRONT>REAR){
		i=FRONT;
		while(i!= REAR){
			printf("%d, ", q[i++]);
			if(i>=SIZE) i=0;
		}
		printf("%d, ", q[i]);
	}
	else if(FRONT==REAR) printf("%d ", q[REAR]);
	else{
		for(i=FRONT; i<=REAR; i++) printf("%d, ", q[i]);
	}
	printf("]\n");
}

int main(){
	int q[SIZE], ch, data;
	do{
		printf("\n - - - Circular Queue  - - - \n");
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
				printf("\nData Inserted successfully.\n");
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
