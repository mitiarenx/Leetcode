#include <vector>
#include <iostream>
#include <algorithm>

long long	countSubarrays( std::vector<int> &nums, int k )
{
	int			max, lastOK, left;
	long long	count;

	left = 0;
	count = 0;
	lastOK = 0;
	max = *std::max_element(nums.begin(), nums.end());
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == max)
			lastOK++;
		while (lastOK >= k)
		{
			if (nums[left] == max)
				lastOK--;
			left++;
		}
		count += left;
	}
	return count;
}

int	main()
{
	std::vector<int>	nums = { 1, 3, 2, 3, 3 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "SUBARRAYS = " << countSubarrays(nums, 2) << std::endl;
	return 0;
}
