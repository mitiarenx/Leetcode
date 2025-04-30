#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <algorithm>

std::string	addBinary( std::string a, std::string b )
{
	int			sa, sb, retenu;
	std::string	result;

	sa = a.size();
	sb = b.size();
	if (sa < sb)
		addBinary(b, a);
	retenu = 0;
	for (int i = sb - 1; i >= 0; i--)
	{
		int	sum = a[i] + b[i] - 2 * 48 + retenu;
		if (sum >= 2)
			retenu = 1;
		else
			retenu = 0;
		std::cout << (sum % 2) << std::endl;
		a[i] = (sum % 2) + 48;
	}
	result = a;
	if (retenu)
		result.insert(result.begin() , '1');
	return result;
}

int	main()
{
	std::string	first = "11";
	std::string	second = "1";

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << "RESULT = " << addBinary(first, second) << std::endl;
	return 0;
}
