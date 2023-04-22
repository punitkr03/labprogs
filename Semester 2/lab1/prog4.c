//Program to print characters of a string.
#include <stdio.h>

int main() {
    char str[100]="Hello!";
    int i;

    printf("Characters of the string are:\n");
    for(i=0; str[i]!='\0'; i++) {
        printf("%c\n", str[i]); // Print each character of the string
    }

    return 0;
}
