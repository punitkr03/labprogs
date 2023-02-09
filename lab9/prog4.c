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
    st s1={1,9.6,"IT"};
    st s2={2,9,"CSE"};
    st s3={3,5.3,"EEE"};
    st s4={4,8.1,"CSE"};
    st s5={5,7.2,"ETC"};
    st s[5]={s1,s2,s3,s4,s5};
    int j,k;
    int maxindx=0;
    for(j=0;j<5;j++)
    {
        k=stcompare(s[maxindx],s[j]);
        if(k==-1) 
        maxindx=j;
    }
    printf("Topper of the class is Roll no. %d of %s branch with %0.2f gpa.\n",s[maxindx].rno, s[maxindx].br, 
    s[maxindx].gpa);

    return 0;
}