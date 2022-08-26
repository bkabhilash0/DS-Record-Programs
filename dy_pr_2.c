// Use malloc to read n integers and find the mean.

#include <stdio.h>
#include <stdlib.h>

void read(int *arr, int n){
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

float mean(int *arr,int n){
	int i;
	float mean=0,sum=0,m=n;
	for(i=0;i<n;i++){
		sum += arr[i];
	}
	mean = sum / m;
	return mean;
}

void main(){
	int *arr,n;
	
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	
	arr = (int*)malloc(n*sizeof(int));
	
	read(arr,n);
	display(arr,n);
	
	printf("The Mean of all the elements in the array is %.2f",mean(arr,n));
	
	free(arr);
	
}
