#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_replace()
{
	FILE *fp_in, *fp_out;
	char word[100], temp[100], replace[100];

	fp_in = fopen("text.txt", "r");
	fp_out = fopen("text_replaced.txt", "w+");
	if (fp_in == NULL || fp_out == NULL) {
		printf("Can't open file.");
		exit(EXIT_FAILURE);
	}

	puts("Enter the word to replace:");
	fgets(word, 100, stdin);
	word[strlen(word) - 1] = word[strlen(word)];

	puts("Enter the word to replace it with :");
	fgets(replace, 100, stdin);
	replace[strlen(replace) - 1] = replace[strlen(replace)];

	rewind(fp_in);
	while (!feof(fp_in)) 
	{
		fscanf(fp_in, "%s", temp);

		if (strcmp(temp, word) == 0)
		strcpy(temp, replace);

		fprintf(fp_out, "%s ", temp);
	}
	puts("Operation successful.\n");

	fclose(fp_in);
	fclose(fp_out);
}

void main()
{
	find_replace();
}
