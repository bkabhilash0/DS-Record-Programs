#include <stdio.h>
// Usage of Storage classes in C

int students = 10;

void modifyLocal(int n){
	// The arguments are local to the function only
	// The updates are reflected inside the scope of a local variable
	printf("The argument variable i.e the local variable value is %d\n",n);
	n = n + 10;
	printf("Inside the function - modified value of n is %d\n",n);
}

void showStatic(){
	// The value of static variable retains in all function calls
	static int value;
	printf("Static Variable Value is %d\n",value);
	value++;
}

void printGlobal(){
	printf("The value of Global Variable is %d\n",students);
}

void main(){
	int n = 10;
	printf("The Value of Global Variable Initially is %d\n",students);
	// Now we are modifying the global variable
	students = 20;
	// The value of the global variable changes throughout the program
	printf("After Modifying the Global Variable: %d\n",students);
	
	// The value of Local variable n is printed
	printf("The value of Local Variable is %d\n",n);
	
	// Modifying the local varible using a function
	modifyLocal(n);
	
	// Changes to Local Variable inside a function dont reflect into the main fn
	printf("The value of Local Variable after Updation is %d\n",n);
	
	// Static Variable - has a default value of 0
	showStatic();
	showStatic();
	showStatic();
	showStatic();
	
	// Register Variable - scoped to fn and is stored in register
	register int num = 10;
	printf("The value of Register variable is %d\n",num);
	// Register variables are faster in access time as they are stored in register
	
	extern int students;
	printf("The value of Extern Variable is %d\n",students);
	students = 100;
	printf("The value of Extern Variable is %d\n",students);
	printGlobal();
}
