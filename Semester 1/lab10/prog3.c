#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *f1 ,*f2, *f3;
    f1=fopen("text.txt", "r");
    f2=fopen("text2.txt", "r");
    f3=fopen("textappend.txt", "w");
    if (f1 == NULL || f2==NULL || f3==NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char ch;
    while((ch=fgetc(f1))!=EOF)
    {
        fputc(ch, f3);
    }
    fprintf(f3, "\n");
    while((ch=fgetc(f2))!=EOF)
    {
        fputc(ch, f3);
    }
    printf("Both files are merged \n");

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}