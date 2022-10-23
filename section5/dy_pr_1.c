// Using malloc,calloc and free enter n elements in an int array

#include <stdio.h>
#include <stdlib.h>

void read(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("Enter the element %d: ",i+1);
		scanf("%d",(arr+i));
	}
}

void display(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("Element %d is: %d\n",i+1,arr[i]);
	}
}

void main(){
	int *arr1,*arr2,n,i;
	printf("Enter the size of both the Arrays: ");
	scanf("%d",&n);
	// malloc allocates the memory and doesn't initializes
	arr1 = (int*)malloc(n*sizeof(int));
	// calloc allocates contiguous memory and initializes the value to 0
	arr2 = (int*)calloc(n,sizeof(int));
	
	printf("Enter the elements of the Array 1\n");
	read(arr1,n);
	
	printf("Enter the elements of Array 2\n");
	read(arr2,n);
	
	printf("The Elements of Array 1 are:\n");
	display(arr1,n);
	
	printf("The Elements of Array 2 are:\n");
	display(arr2,n);
	
	free(arr1);
	free(arr2);
}
