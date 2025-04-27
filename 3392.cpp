#include <vector>
#include <iostream>
#include <algorithm>

int	countSubarrays( std::vector<int> &nums )
{
	int	result = 0, end = nums.size() - 2;

	for (int i = 0; i < end; i++)
	{
		if ((nums[i] + nums[i + 2]) == (nums[i + 1] / 2.0f))
			result++;
	}
	return result;
}

int	main()
{
	std::vector<int>	test = { -1, -4, -1, 4 };
	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "SUBARRAYS = " << countSubarrays(test) << std::endl;
	return 0;
}
