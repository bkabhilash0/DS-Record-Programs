#include <stdio.h>
#include <stdlib.h>

void myFn(){
    static int value = 0;
    value = value + 1;
    printf("value = %d\n", value);
}

void main(){
    myFn();
    myFn();
    myFn();
}