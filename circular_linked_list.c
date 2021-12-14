#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
} *start=NULL, *end=NULL;

void displayCLL(){
	if(start==NULL) {printf("Empty List !\n"); return;}

	struct node *ptr = start;

	printf("\nstart->");
	while(ptr->next != start){
		printf("%d-> ", ptr->data);
		ptr = ptr->next;
	}

	printf("%d->start\n\n", ptr->data);
}

void createCLL(){
	if(start!=NULL) {printf("You already Created one.\nAborted."); return;} //clearCLL(start);
	int usrData;
	do{
		printf("\nEnter data for this node: ");
		scanf("%d", &usrData);
		struct node *newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = usrData;	
		if(start==NULL) {start = newNode; end = start;}
		else {end->next = newNode; end = end->next;}
		newNode->next = start;

		char c;
		printf("\nInsert another ? (Y/N): "); fflush(stdin);
		scanf(" %c", &c);
		
		if(c!='y') {printf("Okay..\n"); break;}

	}while(1);

}

void insertBegin(int usrData){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	newNode->next = start;
	start = newNode;
}
void insertEnd(int usrData){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	end->next = newNode;
	end = newNode;
	newNode->next = start;
}

void delBegin(){
	if(start==NULL) {printf("There is no List! UNDERFLOW!\n"); return;}
	// printf("1.END[%d | %p]\n", end->data, end->next);
	// printf("1.START[%d | %p]\n", start->data, start->next);
	end->next = start->next;

	// printf("2.END[%d | %p]\n", end->data, end->next);
	// printf("2.START[%d | %p]\n", start->data, start->next);

	printf("%d Deleted Successfully.\n", start->data);
	free(start);

	// printf("3.END[%d | %p]\n", end->data, end->next);
	// printf("3.START[%d | %p]\n", start->data, start->next);

	start = end->next;

	// printf("4.END[%d | %p]\n", end->data, (void*)end->next);
	// printf("4.START[%d | %p]\n\n", start->data, (void*)start->next);
}

void delEnd(){
	if(start==NULL) {printf("There is no List! UNDERFLOW!\n"); return;}

	struct node *tmp = start;
	while(tmp->next != end) tmp = tmp->next;

	end = tmp;
	tmp = tmp->next;
	printf("%d Deleted Successfully.\n", tmp->data);
	free(tmp);

	end->next = start;
}

void delAll(){
	if(start==NULL) {printf("There is no List! UNDERFLOW!\n"); return;}
	while(start!=NULL)	delBegin();
	// end->next = NULL;
	// delBegin();
	printf("Entire list deletion completed.\n");
}


int main(){
	printf("Circular LinkedList\n by Soumen Mahata(CSE3 71)\n");
	printf("1. Create a Circular LinkedList\n");
	printf("2. Insert element at First\n");
	printf("3. Insert Element at Last\n");
	printf("4. Delete element at First\n");
	printf("5. Delete element at Last\n");
	printf("6. Delete the Circular LinkedList\n");
	printf("7. Display the List\n");
	printf("8. Exit\n");
	printf("______________________________________________________\n");
	
	int ch=99;
	do{
		switch(ch){
			int usrData;
			case 1:
					createCLL();
					break;

			case 2: printf("Enter Data for your node: ");
					scanf("%d", &usrData); 
					insertBegin(usrData);
					break;

			case 3: printf("Enter Data for your node: ");
					scanf("%d", &usrData); 
					insertEnd(usrData);
					break;

			case 4: delBegin();
					break;

			case 5: delEnd();
					break;

			case 6: delAll();
					break;

			case 7: displayCLL();
					break;
			case 8: printf("\nBye Bye ..\n");
					exit(0);

		}

		printf("\nEnter your choice OR \npress Ctrl+c anytime to close : ");
		fflush(stdin);
		scanf("%d", &ch);

	}while(1);

	return 0;
}
