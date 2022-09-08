#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char s1[] = "abcE";
	char s2[] = "abcde";

	printf("Original %i\nFarseta %i\n", strncmp(s1, s2, 3), ft_strncmp(s1, s2, 3));
}