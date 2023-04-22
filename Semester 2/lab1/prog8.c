//Program to reverse a string.
#include <stdio.h>

int main() {
    char str[100] = "Hello!";
    int i, j;

    // Find the length of the string
    for(i=0; str[i]!='\0'; i++);

    //Swapping characters
    for(j=0; j<i/2; j++) {
        char temp = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = temp;
    }

    printf("Reversed string: %s", str);

    return 0;
}
