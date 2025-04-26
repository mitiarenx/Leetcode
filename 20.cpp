#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

bool	ok( char op, char end )
{
	return	(op == '(' && end == ')') ||
			(op == '{' && end == '}') ||
			(op == '[' && end == ']');
}

bool	isValid( std::string s )
{
	std::stack<char>	stack;

	stack.push(s[0]);
	for (size_t i = 1; i < s.size(); i++)
	{
		if (stack.size() && ok(stack.top(), s[i]))
			stack.pop();
		else
			stack.push(s[i]);
	}
	if (stack.size() != 0)
		return false;
	return true;
}

int	main()
{
	std::string	test = "()[";
	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	std::cout << isValid(test) << std::endl;
	return 0;
}
