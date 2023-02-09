#include<stdio.h>
struct metric{
    float mt;
    float cm;
};
typedef struct metric metric;
struct imperial{
    float ft;
    float in;
};
typedef struct imperial imperial;
void mtf(metric m){
    metric k={m.mt*3.3,m.cm*0.3};
    printf("feet %f inch %f\n",k.mt,k.cm);
}
void ftm(imperial m){
    imperial k={m.ft/3.3,m.in/0.3};
    printf("meter %f cm %f\n",k.ft,k.in);
}
int main(){
    metric m1={3,4};
    imperial m2={5,6};
    mtf(m1);
    ftm(m2);

    return 0;
}