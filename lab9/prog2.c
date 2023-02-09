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

    D a={2004,11,3};
    D b={2023,2,9};

    printf("Your age is %d years\n",(b.year-a.year)-1);
    return 0;
}