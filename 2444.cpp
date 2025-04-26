#include <vector>
#include <iostream>
#include <algorithm>

// ==================================== FIRST SOLUTION TLE ====================================

long long	count( std::vector<int> &nums, int minK, int maxK, size_t i )
{
	long long			result = 0;
	int					start = 1;
	std::vector<int>	temp;
	
	for (size_t j = i; j < nums.size(); j++)
	{
		temp.insert(temp.begin(), nums.begin() + i, nums.begin() + i + start);
		if (*std::max_element(temp.begin(), temp.end()) == maxK
			&& *std::min_element(temp.begin(), temp.end()) == minK)
			result++;
		start++;
		temp.clear();
	}
	return result;
}

long long	countSubarrays( std::vector<int> &nums, int minK, int maxK )
{
	long long	result = 0;

	for (size_t i = 0; i < nums.size(); i++)
		result += count(nums, minK, maxK, i);
	return result;
}

// ==================================== SECOND SOLUTION ====================================

long long	countSubarrays1( std::vector<int> &nums, int minK, int maxK )
{
	long long	result = 0;
	int			lastOK = -1, min = -1, max = -1;
	
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] < minK || nums[i] > maxK)
			lastOK = i;
		if (nums[i] == minK)
			min = i;
		if (nums[i] == maxK)
			max = i;
		int	difference = std::min(min, max);
		result += std::max(0, (difference - lastOK));
	}
	return result;
}


int	main()
{
	std::vector<int>	nums = {1, 1, 1, 1};
	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << countSubarrays1(nums, 1, 1) << std::endl;
	return 0;
}
