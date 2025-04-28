#include <vector>
#include <iostream>
#include <algorithm>

long long	countSubarrays( std::vector<int> &nums, long long k )
{
	long long	result = 0;
	int			lastOk = -1, index = -1;

	for (size_t i = 0; i < nums.size(); i++)
	{
	}
	return result;
}

int	main()
{
	std::vector<int>	nums = { 2, 1, 3, 4, 5 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "SUBARRAYS = " << countSubarrays(nums, 10) << std::endl;
	return 0;
}
