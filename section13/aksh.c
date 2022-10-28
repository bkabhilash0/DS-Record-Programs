#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node list;
list *head = NULL;
void insert(int e)
{
    list *t;
    if (head == NULL)
    {
        head = (list *)malloc(sizeof(list));
        head->data = e;
        head->next = NULL;
    }
    else
    {
        t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = (list *)malloc(sizeof(list));
        t->next->data = e;
        t->next->next = NULL;
    }
}
void disp()
{
    list *t;
    if (head == NULL)
    {
        printf("List is EMPTY");
    }
    else
    {
        t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
    printf("\n");
}
int menu()
{
    int ch;
    printf("1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    // int ch;
    // for(ch=menu();ch!=3;ch=menu())
    // {
    // 	switch(ch)
    // 	{
    // 		case 1:
    // 			printf("Enter the value: ");
    // 			scanf("%d",&ch);
    // 			insert(ch);
    // 			break;
    // 		case 2:
    // 			disp();
    // 			break;
    // 		case 3:
    // 			break;
    // 		default:
    // 			printf("Wrong choice\n");
    // 			break;
    // 	}
    // }
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    disp();
    return 0;
}