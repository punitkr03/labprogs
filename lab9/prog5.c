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
    car a[5]={c1,c2,c3,c4,c5};
    printf("Property\t\tC1\t\tC2\t\tC3\t\tC4\t\tC5\n");
    printf("Brand\t\t\t%s \t%s \t%s \t%s\t%s\n",a[0].brand,a[1].brand,a[2].brand,a[3].brand,a[4].brand);
    printf("Model\t\t\t%s\t%s\t%s\t%s\t%s\n",a[0].model,a[1].model,a[2].model,a[3].model,a[4].model);
    printf("Milage\t\t\t%0.1f\t%0.1f\t%0.1f\t%0.1f \t%0.1f\n",a[0].milage,a[1].milage,a[2].milage,a[3].milage,a[4].milage);
    printf("Capacity\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[0].sc,a[1].sc,a[2].sc,a[3].sc,a[4].sc);
    return 0;

}
