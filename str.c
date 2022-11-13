#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

    char letter;
    char name[20];

    // Case 1: No input taken before char or string inputs
    printf("Enter a Letter: ");
    letter = getc(stdin);

    // Since there is an input taken before this use getc before next input statement
    printf("Enter a String: ");
    getc(stdin);
    fgets(name,20,stdin);

    // fgets includes a new line char also at the last so to prevent it make the last character 
    // of the string to '\0'
    int l = strlen(name);
    name[l-1] = '\0';

    printf("Letter is %c letter and name is %s", letter, name);
}