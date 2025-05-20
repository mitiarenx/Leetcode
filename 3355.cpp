#include <vector>
#include <iostream>
#include <algorithm>

bool	isZeroArray( std::vector<int> &nums, std::vector<std::vector<int>> &queries )
{
	int					delta = 0;
	std::vector<int>	diff(nums.size(), 0);

	for (size_t i = 0; i < queries.size(); i++)
	{
		diff[queries[i][0]] -= 1;
		int	right = queries[i][1];
		if (right + 1 < diff[i])
			diff[right + 1] += 1;
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		delta += diff[i];
		nums[i] += delta;
		if (nums[i] > 0)
			return false;
	}
	return true;
}

int	main()
{
	std::vector<int>				nums = { 1, 0, 1 };
	std::vector<std::vector<int>>	queries = { { 0, 2 } };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	if (isZeroArray(nums, queries))
		std::cout << "It's zero array" << std::endl;
	else
		std::cout << "NO !" << std::endl;
	return 0;
}
