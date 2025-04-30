#include <stdio.h>
#include <math.h>
#include <unistd.h>

int	findNumbers( int *nums, int numsSize )
{
	int	count;

	count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (((int)log10(nums[i]) + 1) % 2 == 0)
			count++;
	}
	return (count);
}

int	main( void )
{
	int	nums[] = { 12, 345, 2, 6, 789 };

	printf("=================== RESULT ===================\n");
	printf("RESULT = %d\n", findNumbers(nums, 5));
	return (0);
}
