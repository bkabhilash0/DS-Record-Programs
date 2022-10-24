#include <stdio.h>
#include<stdlib.h>
int main ()
{
	int i,m,r,size=0;
	char *ptr;
	printf("\nHow many characters: ");
	scanf("%d",&m);
	ptr=(char*)malloc(m*sizeof(char));
	if(ptr==NULL)
	{
        printf("Error unable to allocate the memory");
	}
	else 
	{
	    printf("\nEnter %d characters:",m);
	    for(i=0;i<m;i++)
    	{
    	   getchar();
	        ptr[i]=getchar();
		}
    	printf("\n\nCharacters by Malloc : \n");
    	for(i=0;i<m;i++)
    	{
    		printf("\t");
    	    putchar(ptr[i]);
            printf(" @: %p\n",(ptr+i));//'%p' for printing the address    
			size++; //assigning the size of array to size
		}
	}
	while(1)
	{
    	printf("\n\nDo you wish to reallocate memory (Y/N)?: ");
   	getc(stdin);
    	if((getchar()=='y')||(getchar()=='Y'))
     	{
     		printf("\n\nBy Addition or Substraction: (A/S)?: ");
     	    getchar();
     		if((getchar()=='a')||(getchar()=='A'))
     	    {
			    printf("\nHow many characters more: ");
            	scanf("%d",&r);
				ptr=(char*)realloc(ptr, r*sizeof(char));
				if(ptr==NULL)
	            {
                    printf("Unable to allocate the memory");
	            }
	            else 
	            {                
	                printf("\nEnter %d characters: ",r);
	    	        for(i=0;i<r;i++)
		            {
		                getchar();
		                ptr[size+i]=getchar();//receiving the new elements 
		            }
		            size=size+r;//new size of the array assigned to size
		        }
	        }
	        else
			{	        	
	        	printf("\nHow many characters: ");
            	scanf("%d",&r);
				ptr=(char*)realloc(ptr, r*sizeof(char));
	        	size=size-r;
			}	
			printf("All characters after the reallocation of memory by realloc:\n");
            for(i=0;i<size;i++)
            {
    	        printf("\t");
    	   		putchar(ptr[i]);
           		printf(" @: %p\n",(ptr+i));  
	        }   
     	}
	    else
	    {
	        return 0;
	    }
	}
	free (ptr);
	return 0;
}
