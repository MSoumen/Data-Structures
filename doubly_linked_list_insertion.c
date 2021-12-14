#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
} *START=NULL, *END=NULL;

void printDLL(){
	struct node *ptr = START;
	while(ptr !=NULL){
		printf("%d<->", ptr->data);
		ptr = ptr->next;
	}
	printf("X\n\n");
}

void createDLL(){
	if(START!=NULL) {printf("You already Created one.\nAborted."); return;} //clearCLL(start);
	int usrData;
	do{
		printf("\nEnter data for this node: ");
		scanf("%d", &usrData);
		struct node *newNode = (struct node*) malloc(sizeof(struct node));

		newNode->data = usrData;

		if(START==NULL){
			START = newNode;
			newNode->prev = NULL;
			END=newNode;
		}else{
			END->next = newNode;
			newNode->prev = END;
			END = newNode;
		}
		newNode->next = NULL;

		char c;
		printf("\nInsert another ? (Y/N): "); fflush(stdin);
		scanf(" %c", &c);
		
		if(c!='y') {printf("Okay..\n"); break;}

	}while(1);
}

void insertBeg(int usrData){
	if(START==NULL) {printf("Please create a list first.\nExiting..."); return;}
	
	// int usrData;
	// printf("Enter data : ");
	// scanf("%d", &usrData);
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	newNode->prev = NULL;
	newNode->next = START;
	START->prev = newNode;
	START = newNode;
}

void insertLast(int usrData){
	if(START==NULL) {printf("Please create a list first.\nExiting..."); return;}
	
	// int usrData;
	// printf("Enter data : ");
	// scanf("%d", &usrData);
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	newNode->next = NULL;
	newNode->prev = END;
	END->next = newNode;
	END = newNode;
}

void insertAfterGiven(int givenNode, int usrData){
	if(START==NULL) {printf("Please create a list first.\nExiting..."); return;}
	
	// int usrData;
	// printf("Enter Node value after which you want to insert : ");
	// scanf("%d", &givenNode);
	

	struct node *ptr = START;
	while(ptr->data!= givenNode) ptr = ptr->next;

	if(ptr==NULL) {printf("Not found! Try again."); return;}

	if(ptr->next==NULL) {insertLast(usrData); return;}

	// printf("Enter data to insert: ");
	// scanf("%d", &usrData);
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	
	newNode->prev = ptr;
	newNode->next = ptr->next;
	ptr->next->prev = newNode;
	ptr->next = newNode;

}

void insertBeforeGiven(int givenNode, int usrData){
	if(START==NULL) {printf("Please create a list first.\nExiting..."); return;}
	
	// int usrData;
	// printf("Enter Node value before which you want to insert : ");
	// scanf("%d", &givenNode);
	

	struct node *ptr = START;
	while(ptr->data!= givenNode) ptr = ptr->next;

	if(ptr==NULL) {printf("Not found! Try again."); return;}

	if(ptr->prev==NULL) {insertBeg(usrData); return;}

	// printf("Enter data to insert: ");
	// scanf("%d", &usrData);
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	
	newNode->next = ptr;
	newNode->prev = ptr->prev;
	ptr->prev->next = newNode;
	ptr->prev = newNode;

}

int main(){
	printf(" - - - Doubly Linked List - - -\n\n");
	printf("1. Create a Doubly LinkedList\n");
	printf("2. Insert Node at beginning\n");
	printf("3. Insert Node at the end\n");
	printf("4. Insert Node after a given node\n");
	printf("5. Insert Node before a given node\n");
	printf("6. Print the List\n");
	printf("7. Exit\n");

	int ch=99, usrData, givenNode;
	do{
		switch(ch){
			case 1:
				createDLL(); break;
			
			case 2:
				printf("\nEnter data to insert: ");
				scanf("%d", &usrData);
				insertBeg(usrData);
				break;
			
			case 3:
				printf("\nEnter data to insert: ");
				scanf("%d", &usrData);
				insertLast(usrData);
				break;

			case 4:
				printf("\nEnter Node value after which you want to insert : ");
				scanf("%d", &givenNode);
				printf("Enter Data which you want to insert : ");
				scanf("%d", &usrData);
				insertAfterGiven(givenNode, usrData);
				break;

			case 5:
				printf("\nEnter Node value before which you want to insert : ");
				scanf("%d", &givenNode);
				printf("Enter Data which you want to insert : ");
				scanf("%d", &usrData);
				insertBeforeGiven(givenNode, usrData);
				break;

			case 6:
				printDLL(); break;
			case 7:
				printf("\nBye Bye !\n\n");
				exit(10);
		}
		printf("Choose Your Option OR press Ctrl+c to exit : ");
		scanf("%d", &ch);

	}while(1);

	return 0;
}