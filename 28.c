#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	strStr( char *haystack, char *needle )
{
	int	index = -1;
	
	for (int i = 0; i < (int)strlen(haystack); i++)
	{
		int	j = i, k = 0;
		while (haystack[i] && needle[k] && haystack[j] == needle[k])
		{
			j++;
			k++;
		}
		if (k == (int)(strlen(needle)))
		{
			index = i;
			break ;
		}
	}
	return (index);
}

int	main( void )
{
	char	haystack[] = "a", needle[] = "a";

	printf("=================== RESULT ===================\n");
	printf("%d\n", strStr(haystack, needle));
	return (0);
}
