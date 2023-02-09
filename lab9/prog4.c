#include<stdio.h>
struct student{
    int rno;
    float gpa;
    char br[25];
};

typedef struct student st;

int stcompare(st st1, st st2)
{
    if (st1.gpa > st2.gpa)
    return 1;
    else if (st1.gpa <  st2.gpa)
    return -1;
    else
    return 0;

}
int main()
{
    st s[5];
    int j,k;
    for(j=0;j<5;j++)
    {
        printf("Enter rno, gpa and brach.\n");
        scanf("%d",&s[j].rno);
        scanf("%f",&s[j].gpa);
        scanf("%s",&s[j].br);
    }
    int maxindx=0;
    for(j=0;j<5;j++)
    {
        k=stcompare(s[maxindx],s[j]);
        if(k==-1) 
        maxindx=j;
    }
    printf("Topper of the class is Roll no. %d of %s branch.\n",s[maxindx].rno, s[maxindx].br);

    return 0;
}