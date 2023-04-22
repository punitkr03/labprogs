#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f1;
    int i;
    f1=fopen("student.bin", "rb");
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
    float max=0;
    St s;
    char *n = NULL;
    while(fread(&s, sizeof(St), 1, f1))
    {
        if(s.gpa>max)
        {
            max=s.gpa;
            if(n != NULL)
            free(n);
            n = malloc(strlen(s.name) + 1);
            strcpy(n, s.name);
        }
    }
    printf("Topper of the class is %s with %0.2f gpa.", n, max);
    fclose(f1);
    return 0;
}