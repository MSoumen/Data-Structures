#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *nxt;
} *start = NULL, *end=NULL, *prevEnd = NULL;

void createList(){
	int val;
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	printf("Enter data for the newly created node: ");
	scanf("%d", &val);
	newNode->data = val;
	
	if(start==NULL) {start = newNode; end = newNode;}
	else{
		printf("There exist a LinkedList! So adding the new node to the list.\n");
		prevEnd = end;
		end->nxt = newNode;
		end = newNode;
	}
	newNode->nxt = NULL;
}

void delLast(){
	struct node *ptr = start;
	struct node *del = end;
	
	prevEnd->nxt = NULL;
	end = prevEnd;
	while(ptr->nxt != NULL){
		prevEnd = ptr;	ptr = ptr->nxt;
	}
	printf("%d deleted successfully.\n", del->data);
	free(del);
}

void delFirst(){
	struct node *del = start;
	start = start->nxt;
	printf("%d deleted successfully.\n", del->data);
	free(del);
}

int search(int key){
	struct node *ptr= start;
	int count=1;
	
	while(ptr!=NULL){
		if(ptr->data==key) return count;
		count++;
		ptr = ptr->nxt;
	}
	
	return -404;
}

void delAtKey(int key){
	if(start->data==key) {delFirst(); return;}
	if(end->data==key) { delLast(); return;}
	
	struct node *ptr = start;
	int c = search(key);
	
	while(c-->2) ptr = ptr->nxt;
	
	struct node *del = ptr->nxt;
	ptr->nxt = del->nxt;
	free(del);
	printf("%d deleted successfully.\n", key);
}

void delAfterKey(int key){
	struct node *ptr = start;
	int c = search(key);
	
	while(c-->1) ptr = ptr->nxt;
	
	struct node *del = ptr->nxt;
	printf("%d deleted successfully.\n", del->data);
	ptr->nxt = del->nxt;
	free(del);
}

void printList(){
	if(start==NULL){
		printf("Empty list!\n"); return;
	}
	struct node *ptr=start;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr = ptr->nxt;
	}
	printf("NULL\n");
}

int main(){
	printf("LinkedList Extended (Assignment 4) \n by Soumen Mahata(CSE3 71)\n");
	printf("1. Create a LinkedList\n");
	printf("2. Delete element at First\n");
	printf("3. Delete Element at Last\n");
	printf("4. Search for a Key Element\n");
	printf("5. Delete any element\n");
	printf("6. Delete an element after a given key\n");
	printf("7. Display the List\n");
	printf("8. Exit\n");
	printf("______________________________________________________\n");
	int ch=99, key, count;
	
	do{
		switch(ch){
			case 1: createList();
					break;
			
			case 2: delFirst();
					break;
			
			case 3: delLast();
					break;
			
			case 4: printf("\nEnter the Key to search the List: ");
					scanf("%d", &key);
					count = search(key);
					count!=-404 ? printf("%d present at %d position.\n", key, count) : printf("Not Found!\n");
					break;
					
			case 5: printf("\nEnter the Key to delete from List: ");
					scanf("%d", &key);
					delAtKey(key);
					break;
					
			case 6: printf("\nEnter the Key to delete its next element : ");
					scanf("%d", &key);
					delAfterKey(key);
					break;
					
			case 7: printList();
					break;
					
			case 8: exit(0);
		}
		
		printf("\nChoose your choice OR \nPress q to EXIT  : ");
		scanf("%d", &ch); fflush(stdin);
//		printf("%d\n", ch);
		if(ch==99) exit(1);
		
	}while(1);
}
