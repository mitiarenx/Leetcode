#include <vector>
#include <iostream>
#include <algorithm>

int	removeElement( std::vector<int> &nums, int val )
{
	int	count = nums.size();

	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < count; i++)
	{
		if (nums[i] == val)
		{
			count--;
			nums.erase(nums.begin() + i);
			i--;
		}
	}
	return count;
}

int	main()
{
	std::vector<int>	test = { 1 };
	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "SUBARRAYS = " << removeElement(test, 1) << std::endl;
	for (int i = 0; i < (int)test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << std::endl;
	return 0;
}
