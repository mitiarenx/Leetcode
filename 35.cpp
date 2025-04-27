#include <vector>
#include <iostream>
#include <algorithm>

int	searchInsert( std::vector<int> &nums, int target )
{
	std::vector<int>::iterator	it;

	nums.push_back(target);
	std::sort(nums.begin(), nums.end());
	it = std::find(nums.begin(), nums.end(), target);
	return it - nums.begin();
}

int	main()
{
	std::vector<int>	test = { 1, 3, 5, 6 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "INDEX = " << searchInsert(test, 7) << std::endl;
	return 0;
}
