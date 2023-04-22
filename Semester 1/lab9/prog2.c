#include <stdio.h>
#include <stdlib.h>

struct date{
    int year;
    int month;
    int day;
};

int main()
{
    typedef struct date D;

    D a={2003,8,4};
    D b={2023,2,9};

    if (a.day > b.day) 
    {
        int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        b.day = b.day + month[a.month - 1];
        b.month = b.month - 1;
    }
    if (a.month > b.month)
    {
        b.year = b.year - 1;
        b.month = b.month + 12;
    }
    printf("Your age is %d years %d months %d days.\n",(b.year-a.year),(b.month-a.month),(b.day-a.day));
    return 0;
}
