#include <stdio.h>	//killme
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int	val;
	int				sign;
	int				len;
	char			sym[] = "0123456789ABCDEF";
	char			*str;

	sign = 1;
	len = 0;
	if (value < 0)
	{
		if (base == 10)
		{
			sign = -1;
			len++;
		}
		val = value * -1;
	}
	else
		val = value;
	while (value)
	{
		len++;
		value /= base;
	}
	str = malloc(len + 1);
	str[len] = '\0';
	len--;
	while (val)
	{
		str[len] = sym[val % base];
		val /= base;
		len--;
	}
	if (sign == -1)
		str[len] = '-';
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	}
}
