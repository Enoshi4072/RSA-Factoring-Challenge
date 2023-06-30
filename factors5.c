#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check_prime(unsigned long long n)
{
	unsigned long long i;
	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
	{
		return (0);
	}
	if (n <= 3)
	{
		return (1);
	}
	for (i = 5; i * i <= n; i+= 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
		{
			return (0);
		}
	}
	return (1);
}

void fact_num(unsigned long long n)
{
	unsigned long long j = 0, k = 0, i;
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0 && check_prime(i))
		{
			j = i;
			break;
		}
	}
	k = n / j;
	printf("%llu=%llu*%llu\n", n, k, j);
}
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	size_t len;
	unsigned long long number;
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Failed to open file\n");
		return (1);
	}
	if (fgets(line, sizeof(line), file) != NULL)
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		number = atoll(line);
		fact_num(number);
	}
	fclose(file);
	return (0);
}
