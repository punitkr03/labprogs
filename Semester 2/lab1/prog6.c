//Program to compare two strings.
#include <stdio.h>

int main() {
    char str1[100]="Bello!";
    char str2[100]="Hello!";
    int i;

    // Compare each character of both strings
    for(i=0; str1[i]!='\0' || str2[i]!='\0'; i++) {
        if(str1[i] < str2[i]) {
            printf("%s occurs first in both strings.\n", str1);
            break;
        } else if(str1[i] > str2[i]) {
            printf("%s occurs first in both strings.\n", str2);
            break;
        }
    }

    if(str1[i] == '\0' && str2[i] == '\0') {
        printf("Both strings are equal");
    }

    return 0;
}
