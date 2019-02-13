#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int		tmp;
	int		len;
	int		posneg;
	char	*str;

	if (nbr == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	tmp = nbr;
	len = 0;
	while (tmp)
	{
		len++;
		tmp /=10;
	}
	posneg = 1;
	if (nbr < 0)
	{
		len++;
		posneg = -1;
		nbr *= -1;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len] = nbr % 10 + '0';
		len--;
		nbr /= 10;
	}
	if (posneg == -1)
		str[len] = '-';
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_itoa(atoi(argv[1])));
}
