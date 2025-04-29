#include <vector>
#include <iostream>
#include <algorithm>

std::ostream	&operator<<( std::ostream &output, std::vector<int> &vector )
{
	for (size_t i = 0; i < vector.size(); i++)
		output << vector[i];
	return output;
}

std::vector<int>	plusOne( std::vector<int> &digits )
{
	int	retenu, last;

	retenu = 0;
	last = digits.size() - 1;
	if (digits[last] + 1 >= 10)
		retenu = 1;
	digits[last] = (digits[last] + 1) % 10;
	for (int i = last - 1; i >= 0; i--)
	{
		if (digits[i] + retenu >= 10)
		{
			digits[i] = (digits[i] + retenu) % 10;
			retenu = 1;
		}
		else
		{
			digits[i] = (digits[i] + retenu) % 10;
			retenu = 0;
		}
	}
	if (retenu)
		digits.insert(digits.begin(), retenu);
	return digits;
}

int	main()
{
	std::vector<int>	nums = { 1, 9 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::vector<int>	vector = plusOne(nums);
	std::cout << "RESULT = " << vector << std::endl;
	return 0;
}
