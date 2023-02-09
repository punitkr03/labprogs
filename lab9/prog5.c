#include<stdio.h>
struct cars{
    char brand[20];
    char model[20];
    float milage;
    int sc;
};
typedef struct cars car;
int main(){
    car c1={"Suzuki", "Swift", 20, 5};
    car c2={"Suzuki", "Swift", 20, 5};
    car c3={"Suzuki", "Swift", 20, 5};
    car c4={"Suzuki", "Swift", 20, 5};
    printf("Property\t\tC1\t\tC2\t\tC3\t\tC4\t\t\n");
    printf("Brand\t %s \t %s \t %s \t %s\n",c1.brand,c2.brand,c3.brand,c4.brand);
    printf("Model\t %s\t %s\t %s\t %s\n",c1.model,c2.model,c3.model,c4.model);
    printf("Milage\t %0.2f\t %0.2f\t %0.2f\t %0.2f\n",c1.milage,c2.milage,c3.milage,c4.milage);
    printf("Capacity\t %d\t %d\t %d\t %d\n",c1.sc,c2.sc,c3.sc,c4.sc);
    return 0;

}