#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <algorithm>

int	findNumbers( std::vector<int> &nums )
{
	int	count;

	count = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::string result = std::to_string(nums[i]);
		if (result.size() % 2 == 0)
			count++;
	}
	return count;
}

int	main()
{
	std::vector<int>	test = { 12, 345, 2, 6, 7896 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "RESULT = " << findNumbers(test) << std::endl;
	return 0;
}
