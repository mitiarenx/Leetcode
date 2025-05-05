#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MOD 1000000007

int	specialCase( int n )
{
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (5);
	return (0);
}

void	pushBack( long long **num, int *size, long long n )
{
	*num = realloc(*num, sizeof(long long) * (*size + 1));
	(*num)[*size] = n;
	(*size)++;
}

int	numTilings( int n )
{
	int			i, size;
	long long	*num;
	long long	result;

	if (n == 1 || n == 2 || n == 3)
		return (specialCase(n));
	num = malloc(sizeof(long long) * 3);
	num[0] = 1; num[1] = 2; num[2] = 5;
	i = 3; size = 3;
	while (i < n)
	{
		pushBack(&num, &size, (num[i - 1] % MOD) * 2 + (num[i - 3] % MOD));
		i++;
	}
	result = num[n - 1];
	return (result % MOD);
}

int	main( void )
{
	printf("=================== RESULT ===================\n");
	printf("RESULT = %d\n", numTilings(100));
	return (0);
}
