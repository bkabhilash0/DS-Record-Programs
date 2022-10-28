#include <stdio.h>
#include "sample.h"

extern int extern_variable;

void main(){
    int i;
    printf("The value of extern variable is %d\n",extern_variable);
    extern_variable = 10;
    printf("After Modification => The value of the extern variable is %d\n",extern_variable);
}