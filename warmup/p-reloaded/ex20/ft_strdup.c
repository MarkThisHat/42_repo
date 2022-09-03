#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_strcpy(char *src, char *dst);

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src) + 1;
	dst = malloc(len * sizeof(char));
	ft_strcpy(src, dst);
	return (dst);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *src, char *dst)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = *src;
}