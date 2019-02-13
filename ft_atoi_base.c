#include <stdio.h>

int	ft_value(char c, int base)
{
	if ((base <= 10 && c >= '0' && c <= '0' + base - 1) || (base >= 11 && c >= '0' && c <= '9'))
		return (c - '0');
	else if (base >= 11 && c >= 'a' && c <= 'a' + base - 11)
		return (c - 87);
	else if (base >= 11 && c >= 'A' && c <= 'A' + base - 11)
		return (c - 55);
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	posneg;
	int res;

	res = 0;
	while (*str <= ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		posneg = -1;
		str++;
	}
	while (ft_value(*str, str_base) != -1)
	{
		res = res * str_base + ft_value(*str, str_base);
		str++;
	}
	return (res * posneg);
}

int	main(void)
{
	char	*s = "   -1233afby";
	printf("%i\n", ft_atoi_base(s, 4));
}
