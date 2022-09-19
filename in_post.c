#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void display(int *stack,int top);

char operators[10] = {'(',')','/','*','+','-'};

// Convert an expression from infix to postfix

void push(int *stack,int *top,char element){
	*top = *top + 1;
	stack[*top] = element;
}

void popTillBracket(int *stack,int *top){
	int i;
	for(i = *top;i > -1;i--,*top = *top - 1){
		if(stack[*top] == '('){
			*top = *top - 1;
			break;
		}else{
			printf("%c",stack[*top]);
		}
	}
}

void checkPrecedence(int *stack,int *top,char element){
	char ch = stack[*top];
	
	if(*top == -1 || ch == '('){
		push(stack,top,element);
//		display(stack,*top);
//		printf("Precedence - > %c -> Top = %d => %c\n",element,*top,ch);
		return;
	}
	if(ch==')'){
		return;
	}
	if(ch == element){
		push(stack,top,element);
	}else if((ch == '+' && element == '-') || (ch == '-' && element == '+')) {
		push(stack,top,element);	
	}
	else if((ch == '*' && element == '/') || (ch == '/' && element == '*')) {
		push(stack,top,element);	
	}
	else if((ch == '+' && element == '*') || (ch == '-' && element == '*')) {
		push(stack,top,element);	
	}
	else if((ch == '+' && element == '/') || (ch == '-' && element == '/')) {
		push(stack,top,element);	
	}
	else{
		printf("%c",ch);
		*top = *top - 1;
		checkPrecedence(stack,top,element);
	}
//	display(stack,*top);
//	printf("Precedence - > %c -> Top = %d => %c\n",element,*top,ch);
}

void display(int *stack,int top){
	printf("The Stack: \n");
	int i;
	printf("-----\n");
	for(i = top;i > -1;i--){
		printf("| %c |\n",stack[i]);
		printf("-----\n");
	}
}

void popAll(int *stack,int *top){
	int i;
	for(i = *top;i > -1;i--){
		printf("%c",stack[i]);
	}
}

void main(){
	int *stack,size,top=-1;
	char expression[20] = "1+2*3+4";;
	// printf("Enter the String: \n");
	// scanf("%s",expression);
	size = strlen(expression);
	stack = (int*)calloc(size,sizeof(int));
	printf("The Expression Given is: %s\n",expression);
	
	int i=0;
	for(i=0;i<size;i++){
		char ch = expression[i];
		if(isdigit(ch)){
			printf("%c",ch);
		}else{
			switch(ch){
				case '(' : push(stack,&top,ch);
							break;
				case ')' : popTillBracket(stack,&top);
							break;
				default: checkPrecedence(stack,&top,ch);
			}		
		}
	}
	if(top > -1){
		popAll(stack,&top);
	}
	
	free(stack);
}
