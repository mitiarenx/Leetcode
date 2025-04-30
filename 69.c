#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	mySqrt( int x )
{
	int	high, low;

	low = 1;
	high = x;
	if (x == 0)
		return 0;
	while (low <= high)
	{
		int	mid = low + (high - low) / 2;
		if (mid == (x / mid))
			return mid;
		else if (mid > x / mid)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return high;
}

int	main( void )
{
	printf("=================== RESULT ===================\n");
	printf("RESULT = %d\n", mySqrt(8));
}
