#include <vector>
#include <iostream>
#include <algorithm>

long long	countSubarrays( std::vector<int> &nums, long long k )
{
	int			lastOk = 0;
	long long	result = 0, count = 0;

	for (size_t i = 0; i < nums.size(); i++)
	{
		result += nums[i];
		while (result * (i - lastOk + 1) >= (unsigned long long)k)
		{
			result -= nums[lastOk];
			lastOk++;
		}
		count += (i - lastOk + 1);
	}
	return count;
}

int	main()
{
	std::vector<int>	nums = { 2, 1, 4, 3, 5 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "SUBARRAYS = " << countSubarrays(nums, 10) << std::endl;
	return 0;
}
