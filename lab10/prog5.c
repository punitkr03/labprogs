#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *f1;
    int i;
    f1=fopen("student.bin", "wb");
    if (f1 == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    typedef struct Student{
        int rno;
        char name[25];
        float gpa;
    }St;

    St s1={1, "Ayush", 8.1};
    St s2={2, "Bull", 2.1};
    St s3={3, "Ayan", 1.1};
    St s4={4, "Andrew", 3.1};
    St s5={5, "Eve", 7.7};
    St s6={6, "Adam", 1.1};
    St s7={7, "Apple", 8.1};
    St s8={8, "Drew", 7.1};
    St s9={9, "Dom", 6.1};
    St s10={10, "Tom", 9.8};

    St arr[10]={s1,s2,s3,s4,s5,s6,s7,s8,s9,s10};

    for (i = 0; i < 10; i++)
    {
        fwrite(&arr[i], sizeof(arr[i]), 1, f1);
    }
    printf("Data enterd successfully.\n");
    
    fclose(f1);
    return 0;
}
