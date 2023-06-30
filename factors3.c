#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * fact_num - Factorizes a number into two smaller nums
 * @n: The num to factorize
 * 
 */

void fact_num(unsigned long long n)
{
	unsigned long long i, j, k;
	for (i=2; i <= n / i; i++)
	{
		/* Check if i divide n */
		if (n % i == 0)
		{
			/* The factors have been found */
			j = i;
			k = n / i;
			printf("%llu=%llu*%llu\n", n, k, j);
			return;
		}
	}
	printf("%llu=%llu*%llu\n", n, n, (unsigned long long)1);
}

/**
 * main - Entry point
 * @argc: Num of cmd line args
 * @argv: An array of cmd line strings
 *
 * Return: 1 on error, 0 on succes
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[100];
	size_t len;
	unsigned long long number;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return 1;
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Failed to open file\n");
		return (1);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		number = atoll(line);
		fact_num(number);
	}
	fclose(file);
	return (0);
}
