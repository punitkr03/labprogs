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
    car c2={"Tata", "Nexon", 15, 7};
    car c3={"Tata", "Tiago", 23, 4};
    car c4={"Jaguar", "Ipace", 8.6, 2};
    car c5={"Toyota", "Sresso", 11.2, 4};
    printf("Property\t\tC1\t\tC2\t\tC3\t\tC4\t\tC5\n");
    printf("Brand\t\t\t%s \t%s \t%s \t%s\t%s\n",c1.brand,c2.brand,c3.brand,c4.brand,c5.brand);
    printf("Model\t\t\t%s\t%s\t%s\t%s\t%s\n",c1.model,c2.model,c3.model,c4.model,c5.model);
    printf("Milage\t\t\t%0.1f\t%0.1f\t%0.1f\t%0.1f \t%0.1f\n",c1.milage,c2.milage,c3.milage,c4.milage,c5.milage);
    printf("Capacity\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",c1.sc,c2.sc,c3.sc,c4.sc,c5.sc);
    return 0;

}