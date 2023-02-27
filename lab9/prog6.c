#include<stdio.h>
struct metric{
    float mt;
    float cm;
};
typedef struct metric met;
struct imperial{
    float ft;
    float in;
};
typedef struct imperial imp;

void mtf(met m)
{
    float mt = m.mt+m.cm/100;
    float inches=mt*39.37;
    int f=inches/12;
    float i=inches/12-f;
    printf("Metric values %0.2fm %0.2fcm\n", m.mt,m.cm);
    printf("Imperial values %d feet %0.2f inches\n", f,i*12);
}
void ftm(imp m)
{
    float cm =m.ft*30.48+m.in*2.48;
    int mtr=cm/100;
    float rem=cm/100-mtr;
    printf("Imperial values %0.2f feet %0.2f inches\n", m.ft,m.in);
    printf("Metric values %dm %0.2fcm\n", mtr, rem*100);
}
int main(){
    met m1={3,4};
    imp m2={5,6};
    mtf(m1);
    ftm(m2);
    return 0;
}