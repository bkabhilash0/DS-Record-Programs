// Use calloc to read n numbers and find the mode.

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

int mode(int *arr,int n){
	int max = 0,result = 0,i,j,c=0;
	
	for(i=0;i<n;i++){
		c = 0;
		for(j=0;j<n;j++){
			if(arr[i] == arr[j]){
				c++;
			}
		}
		if(c > max){
			max = c;
			result = arr[i];
		}
	}
	return result;
}

void main(){
	int *arr,n;
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	
	arr = (int*)calloc(n,sizeof(int));
	
	read(arr,n);
	display(arr,n);
	printf("The mode of the given Array is %d\n",mode(arr,n));
	
	free(arr);
}
