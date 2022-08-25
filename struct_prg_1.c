/*
    Define a structure for date having dd/mm/yyyy.
    Provide functions for reading, displaying and comparing two dates are equal or not
*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

// Function Prototypes
void validate(struct date *myDate);
void read(struct date *myDate);
void display(struct date myDate);

void validate(struct date *myDate)
{
    if (myDate->day > 31 || myDate->month > 12 || myDate->day <= 0 || myDate->month <= 0)
    {
        printf("Enter a Valid Date!\n");
        read(myDate);
    }
}

void read(struct date *myDate)
{
    printf("Enter the Date: ");
    scanf("%d", &myDate->day);
    printf("Enter the Month: ");
    scanf("%d", &myDate->month);
    printf("Enter the Year: ");
    scanf("%d", &myDate->year);
    validate(myDate);
}

void display(struct date myDate)
{
    char month[2];
    if (myDate.month < 10)
    {
        month[0] = '0';
        month[1] = myDate.month + '0';
        month[2] = '\0';
    }
    else
    {
        month[0] = (myDate.month) / 10 + '0';
        month[1] = (myDate.month) % 10 + '0';
        month[2] = '\0';
    }
    printf("The date is %d/%s/%d\n", myDate.day, month, myDate.year);
}

int compare(struct date date1, struct date date2)
{
    if (date1.day != date2.day || date1.month != date2.month || date1.year != date2.year)
    {
        return 0;
    }
    return 1;
}

void main()
{
    struct date date1, date2;
    printf("Enter the First Date: \n");
    read(&date1);
    display(date1);
    printf("Enter the Second Date: \n");
    read(&date2);
    display(date2);
    if (compare(date1, date2))
    {
        printf("Both Dates are Equal!");
    }
    else
    {
        printf("Dates aren't Equal!");
    }
}