#include <vector>
#include <iostream>
#include <algorithm>

std::ostream	&operator<<( std::ostream &o, std::vector<int> &one )
{
	for (int i = 0; i < (int)one.size(); i++)
		o << one[i] << " ";
	return o;
}

void	merge( std::vector<int> &nums1, int m, std::vector<int> &nums2, int n )
{
	nums1.resize(m);
	if (n != 0)
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
	std::sort(nums1.begin(), nums1.end());
}

int	main()
{
	std::vector<int>	one = { 1, 2, 3, 0, 0, 0 };
	std::vector<int>	two = { 2, 5, 6 };

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	merge(one, 3, two, 3);
	std::cout << "RESULT = " << one << std::endl;
	return 0;
}