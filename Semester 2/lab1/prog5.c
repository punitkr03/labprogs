//Program to find total number of character in a string.
#include <stdio.h>

int main() {
    char str[100] = "Hello!";
    int i, count = 0;

    // Count the number of characters in the string
    for(i=0; str[i]!='\0'; i++) {
        count++;
    }

    printf("Total number of characters : %d\n", count);

    return 0;
}
