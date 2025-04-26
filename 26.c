#include <stdio.h>
#include <unistd.h>

static void	move( int *nums, int numsSize, int index )
{
	int	temp = nums[index];

	for (int i = index; i < numsSize - 1; i++)
		nums[i] = nums[i + 1];
	nums[numsSize - 1] = temp;
}

int	removeDuplicates( int *nums, int numsSize )
{
	int	result = numsSize;

	for (int i = 1; i < result; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			move(nums, numsSize, i);
			result--;
			i--;
		}
	}
	return result;
}

int	main( void )
{
	int	nums[] = { 1, 2, 2, 2, 2, 2, 2, 3, 4, 5, 10 };
	printf("=================== RESULT ===================\n");
	printf("%d\n", removeDuplicates(nums, 11));
	for (int i = 0; i < 11; i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
}
