#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *fp;
    fp=fopen("text.txt", "r");
    if (fp == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int count, words, lines;
    count = words = lines = 0;
    char ch;
    while(feof(fp)==0)
    {
        ch=fgetc(fp);
        count++;
        if(ch==' ' || ch=='\0' || ch=='\n')
        words++;
        if(ch=='\n')
        lines++;
    }
    printf("Total characters = %d\n", count-words-1);
    printf("Total words = %d\n", words+1);
    printf("Total lines = %d\n", lines+1);

    fclose(fp);
    return 0;
}
