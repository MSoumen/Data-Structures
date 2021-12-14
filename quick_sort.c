#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 25

int part_when_pivot_last(int[], int, int); //arr, l, h
int part_when_pivot_first(int[], int, int); // --do--
void quickSort(int[], int, int, int); // arr, low, high, pivotPos

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int arr[], int len){
	int i=0; 
	for(; i<len; i++) printf("%d, ", arr[i]);
	printf("\n");
}

int main(){
	printf("QuickSort \n by Soumen Mahata(CSE3 71)\n");
	printf("1. Last element as Pivot\n");
	printf("2. First element as Pivot\n");
	printf("3. Exit\n");
	printf("______________________________________________________\n\n");
	
	int arr[MAXLEN];
	int ch=99;
	char c;
	do{
		int len,i;
		printf("\nEnter how many items you want to insert: ");
		scanf("%d", &len);
		printf("Enter values: ");
		for(i=0; i<len; i++) scanf("%d", &arr[i]);
		fflush(stdin);
		
		printf("Enter Your Choice :");
		scanf("%d", &ch);
		switch(ch){
			case 1: quickSort(arr, 0, len-1, 1);
					break;
			case 2: quickSort(arr, 0, len-1, 0);
					break;
			case 3: exit(0);
		}
		printArray(arr, len);		
		printf("\nPress Ctrl+C to exit...\n ");
		
		fflush(stdin);
	}while(1);
	
	return 0;	
}

void quickSort(int arr[], int l, int h, int pos){
//	printf("inside QUICK\n");
	if(l<h){
		int partPos;
		if(pos==1) partPos = part_when_pivot_last(arr, l, h);
		else partPos = part_when_pivot_first(arr, l, h);
		
		quickSort(arr, l, partPos-1, pos);
		quickSort(arr, partPos+1, h, pos);
	}
}
int part_when_pivot_last(int arr[], int low, int high){
//	printf("inside part\n");
	int pivot = arr[high];
	int pivotIdx = low-1, j;
	
	for(j=0; j<high; j++){
		if(arr[j]<pivot){
			pivotIdx++;
			swap(&arr[j], &arr[pivotIdx]);
		}
	}
	swap(&arr[++pivotIdx], &arr[high]);
	
	return pivotIdx;
}

int part_when_pivot_first(int arr[], int low, int high){
//	printf("inside part\n");
	int pivot = arr[low];
	int pivotIdx = high+1, j;
	
	for(j=high; j>low; j--){
		if(arr[j]>pivot){
			pivotIdx--;
			swap(&arr[j], &arr[pivotIdx]);
		}
	}
	swap(&arr[--pivotIdx], &arr[low]);
	
	return pivotIdx;
}
