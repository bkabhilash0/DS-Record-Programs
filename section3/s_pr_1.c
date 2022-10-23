#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
    int l = strlen(str) - 1;
    while (l >= 0)
    {
        printf("%c", str[l]);
        l--;
    }
}

void reverseInArray(char *str)
{
    int i;
    char ch;
    int l = strlen(str);

    for (i = 0; i < l / 2; i++)
    {
        ch = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = ch;
    }
}

void main()
{
    char str[10];
    printf("Enter a String: ");
    scanf("%s",str);
    reverse(str);
    printf("\n");
    reverseInArray(str);
    printf("%s", str);
}