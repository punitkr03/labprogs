//Program to concatenate two strings.
#include <stdio.h>

int main() {
    char str1[100] = "Hello!";
    char str2[100] = "Hello!";
    char result[200];
    int i, j;

    for(i=0; str1[i]!='\0'; i++)
        result[i] = str1[i];

    for(j=0; str2[j]!='\0'; j++)
        result[i+j] = str2[j];
    
    // Add null character at the end otherwise it takes garbage value.
    result[i+j] = '\0';

    printf("Concatenated string: %s", result);

    return 0;
}
