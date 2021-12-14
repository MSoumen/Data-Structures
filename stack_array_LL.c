#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int TOP=-1;

struct node{
	int data;
	struct node *next, *prev;

} *START=NULL, *END_AS_TOP=NULL;

void linkedList_append(int usrData){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = usrData;
	newNode->prev = NULL;

	if(START==NULL){
		START = newNode;
		END_AS_TOP = newNode;
	}else{
		END_AS_TOP->next = newNode;
		newNode->prev = END_AS_TOP;
		END_AS_TOP = newNode;
	}
	newNode->next = NULL;
}

void linkedList_pop(){
	if(START==NULL) {printf("\nStack Underflow!\n"); return;}

	struct node *tmp = END_AS_TOP;
	END_AS_TOP = END_AS_TOP->prev;
	
	printf("\n%d popped successfully!\n", tmp->data);
	free(tmp);

	if(END_AS_TOP==NULL) START=NULL;

}

void linkedList_display(){
	if(START==NULL) {printf("\nStack is Empty!\n"); return;}

	struct node *ptr = END_AS_TOP;
	printf("\n_____\n");
	while(ptr!=NULL){
		printf("\n%d\n_____\n", ptr->data);
		ptr = ptr->prev;
	}
	printf("\n");
}

int get_menu_input(){
	int opcode;
		printf("\n - - Stack Operations - - \n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf(" - - - - - - -\n");
		printf("Enter You choice or press Ctrl+c to exit. : ");
		scanf("%d", &opcode);

	return opcode;
}

void push(int mode, int stack[], int value){
	if(mode==1){
		if(TOP >= SIZE) {printf("\nStack Overflow!\n"); return;}
		stack[++TOP] = value;
	}
	else linkedList_append(value);
}

void pop(int mode, int stack[]){
	if(mode==1){
		if(TOP<=-1) {printf("\nStack Underflow!\n"); return;}
		printf("\n%d removed successfully.\n", stack[TOP--]);
	}
	else linkedList_pop();
}

void display(int mode, int stack[]){
	if(mode!=1) {linkedList_display(); return;}
	if(TOP<=-1) printf("\nStack is Empty!\n");

	int i;
	printf("\n_____\n");
	for(i=TOP; i>=0; i--) printf("\n%d\n_____\n", stack[i]);
	printf("\n");
}


int main(){
	int mode, stack[SIZE];
	printf("\n - - - - Stacks - - - - \n");
	printf("1. Create a Stack using Array\n");
	printf("2. Create a Stack using LinkedList\n");
	printf("3. Exit\n");
	printf("\nEnter your choice: ");
	scanf("%d", &mode);
	
	if(mode!=3){
		do{
			int data, opcode;
			opcode = get_menu_input();

		switch(opcode){
			case 1:
				printf("Enter value to push in stack: ");
				scanf("%d", &data);
				push(mode, stack, data);
				break;

			case 2: pop(mode, stack); break;

			case 3: display(mode, stack); break;

			case 4: printf("\n\nGood Bye!\n\n"); exit(0);

			default: printf("Wrong input!\n"); break;
		}

		}while(1);
	}

}