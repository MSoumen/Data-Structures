#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
	int data
	struct node *prev;// = NULL;;
	struct node *next;// = NULL;
} *START=NULL, *END=NULL;


void flush_stdin(void){
//replacement of fflush, as fflush is not working in Linux
	int c;
	do{
		c = getchar();
	}while(c!='\n' && c!=EOF);
}

void createDLL(){
	if(START!=NULL) {printf("A list is already exist!\nExiting..."); exit(11);}
	
	int usrData;
	printf("Enter items to insert in list, press x to stop : ");
	// int validity;
	while((scanf("%d", &usrData))!=0){

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

		//printf("usrData=%d\n", usrData);
		//validity = scanf("%d", &usrData);
	}

	flush_stdin();
}

void delFirst(){
	if(START==NULL) {printf("No List exist!\nExiting...\n"); exit(404);}

	struct node *ptr = START->next;
	printf("\n%d deleted successfully.\n", START->data);
	free(START);
	if(ptr==NULL){START=NULL; END=NULL; return;}

	ptr->prev = NULL;
	START = ptr;
}

void delLast(){
	if(START==NULL) {printf("No List exist!\nExiting...\n"); exit(404);}
	struct node *ptr = END->prev;
	printf("\n%d deleted successfully.\n", END->data);
	free(END);
	if(ptr==NULL){START=NULL; END=NULL;  return;}
	
	ptr->next = NULL;
	END = ptr;
}

void delNext(int nodeData){
	if(START==NULL) {printf("No List exist!\nExiting...\n"); exit(404);}

	struct node *ptr = START;
	while(ptr->data!=nodeData) ptr = ptr->next;
	
	if(ptr->next==NULL){ printf("Can't Delete! (Last node is given)\n"); return;}

	ptr = ptr->next; //points the node to be deleted
	//given value is 2nd last node
	if(ptr->next==NULL) {delLast(); return;}

	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	printf("\n%d deleted successfully.\n", ptr->data);
	free(ptr);
}

void delPrev(int nodeData){
	if(START==NULL) {printf("No List exist!\nExiting...\n"); exit(404);}
	struct node *ptr = START;

	while(ptr->data!=nodeData) ptr = ptr->next;
	if(ptr->prev==NULL){ printf("Can't Delete! (First node is given)\n"); return;}

	if(ptr->prev->prev == NULL){delFirst(); return;}

	ptr=ptr->prev;
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	
	printf("\n%d deleted successfully.\n", ptr->data);
	free(ptr);
}

void printDLL(){
	struct node *ptr = START;
	printf("\n[ ");
	while(ptr !=NULL){
		printf("%d<->", ptr->data);
		ptr = ptr->next;
	}
	printf("]\n\n");
}

int main(){
	printf("\n - - - Doubly Linked List - - -\n");
	printf("1. Create a Doubly LinkedList\n");
	printf("2. Exit\n");

	bool notFirstTime = false;
	int ch=99, usrData, givenNode;
	do{

		switch(ch){
			case 1:
				createDLL(); 
				break;
			
			case 2:
				delFirst();
				break;
			
			case 3:
				delLast();
				break;

			case 4:
				printf("\nEnter Node value which next node will be deleted : ");
				scanf("%d", &givenNode);
				delNext(givenNode);
				break;

			case 5:
				printf("\nEnter Node value which previous node will be deleted : ");
				scanf("%d", &givenNode);
				delPrev(givenNode);
				break;

			case 6:
				printDLL(); break;
			case 7:
				printf("\nBye Bye !\n\n");
				exit(10);
		}

		if(notFirstTime){
			printf("\n- - - - - - - DLL Operations - - - - - - \n");
			printf("1. Delete the 1st Node\n");
			printf("2. Delete the Last Node\n");
			printf("3. Delete Node after a given node\n");
			printf("4. Delete Node before a given node\n");
			printf("5. Print the List\n");
			printf("6. Exit\n");
			printf("- - - - - - - - - - - - - - - - - - - - \n");
		}
		printf("Choose Your Option OR press Ctrl+c to exit : ");
		scanf("%d", &ch);
		if(notFirstTime) ch+=1;
		else {notFirstTime=true; if(ch==2) ch+=5;}


	}while(1);

	return 0;
}

//another makeDLL implementation
/*void createDLL_S(){
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
*/