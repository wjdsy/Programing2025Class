#include <stdio.h>

int main(void) 
{
	printf("=== Char/String & Escapes ===\n");
	printf("Char : %c, code: %d\n", 'A', 65);
	printf("Message:\n");
	printf("First line\n");
	printf("\tIndented second line\n");
	printf("Third line\n");
	printf("Quotes: \"double quotes\" and 'single quotes'\n");
	printf("Backslash: \\\n");
	printf("Average: [%8.2f]\n", 87.35);

	return 0;
}