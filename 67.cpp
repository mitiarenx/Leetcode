#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <algorithm>

std::string	addBinary( std::string a, std::string b )
{
	int			retenu = 0;
	std::string	min, max, result;

	(a.size() >= b.size()) ? (max = a, min = b) : (max = b, min = a);
	for (int i = min.size() - 1, j = max.size() - 1; i >= 0; i--, j--)
	{
		int sum = (min[i] - '0') + (max[j] - '0') + retenu;
		if (sum >= 2)
			retenu = 1;
		if (sum < 2)
			retenu = 0;
		result.insert(result.begin(), (sum % 2) + '0');
	}
	for (int i = max.size() - min.size() - 1; i >= 0; i--)
	{
		int	sum = (max[i] - '0') + retenu;
		if (sum >= 2)
			retenu = 1;
		if (sum < 2)
			retenu = 0;
		result.insert(result.begin(), (sum % 2) + '0');
	}
	if (retenu)
		result.insert(result.begin(), '1');
	return result;
}

int	main()
{
	std::string	first = "100";
	std::string	second = "110010";

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "RESULT = " << addBinary(first, second) << std::endl;
	return 0;
}
