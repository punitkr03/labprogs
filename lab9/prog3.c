#include<stdio.h>
struct complex{
    float rl;
    float im;
};
typedef struct complex cn;

cn add(cn a, cn b)
{
    cn c={(a.rl + b.rl),(a.im + b.im)};
    return c;
}

cn sub(cn a, cn b)
{
    cn c={(a.rl - b.rl),(a.im - b.im)};
    return c;
}

cn divcn(cn a , cn b)
{
    float k=a.rl, l=a.im , m=b.rl , n=b.im;
    float num1=(k*m)+(l*n);
    float num2=(l*m)-(k*n);
    float denom= (m*m)+(n*n);

    cn c={(num1/denom), (num2/denom)};
    return c;
}

cn mulcn(cn a , cn b)
{ 
    cn c= {(a.rl*b.rl - a.im*b.im),(a.rl*b.im + a.im*b.rl)};
    return c;
}



void printcn(cn c)
{
    printf("%0.2f + i%0.2f\n", c.rl ,c.im);
}
int main(){
    cn a={4,5};
    cn b={3,2};
    printcn((add(a,b)));
    printcn((sub(a,b)));
    printcn((divcn(a,b)));
    printcn((mulcn(a,b)));

    return 0;
}