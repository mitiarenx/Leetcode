#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	lengthOfLastWord( char *s )
{
	int	i = strlen(s) - 1, count = 0;

	while (s[i] && s[i] == ' ')
		i--;
	while (i >= 0 && s[i] && s[i] != ' ')
	{
		i--;
		count++;
	}
	return count;
}

int	main( void )
{
	char	test[] = "Hello World  ";

	printf("=================== RESULT ===================\n");
	printf("%d\n", lengthOfLastWord(test));
	return (0);
}
