#include <stdio.h>
#include <stdlib.h>

struct Book
{
    char author_name[100];
    char book_name[100];
};

void read(struct Book *books, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the Details of Book %d\n", i + 1);
        printf("Enter the Author Name: ");
        scanf("%s", (books + i)->author_name);
        printf("Enter the Book Name: ");
        scanf("%s", (books + i)->book_name);
    }
}

void display(struct Book *books, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Author %d\n", i + 1);
        printf("Book Name: %s\n", (books + i)->book_name);
        printf("Author Name: %s\n", (books + i)->author_name);
        printf("---------------------------------------------\n");
    }
}

void main()
{
    struct Book *books;

    int n;
    printf("Enter the number of Books: ");
    scanf("%d", &n);

    books = (struct Book *)calloc(n, sizeof(struct Book));

    read(books, n);
    display(books, n);

    free(books);
}