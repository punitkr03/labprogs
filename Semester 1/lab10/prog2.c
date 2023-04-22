#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *f1 ,*f2;
    f1=fopen("text.txt", "r");
    f2=fopen("text2.txt", "r");
    if (f1==NULL || f2==NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int flag=1;
    while(feof(f1)==0)
    {
        char ch=fgetc(f1);
        char ch2=fgetc(f2);

        if(ch!=ch2)
        {
            printf("Both files are not same.\n");
            flag=0;
            break;
        }
    }
    if(flag)
    printf("Both files are same.\n");

    fclose(f1);
    fclose(f2);
    return 0;
}