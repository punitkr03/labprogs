#include <stdio.h>
#include <stdlib.h>

struct timestamp
{
    int hr;
    int min;
    int sec;
};
typedef struct timestamp T;

int main()
{
    T t1={7,45,36};
    T t2={8,30,00};
    printf("%d hrs : %d min : %d sec \n", t1.hr,t1.min,t1.sec);
    printf("%d hrs : %d min : %d sec \n", t2.hr,t2.min,t2.sec);

    return 0;
}
