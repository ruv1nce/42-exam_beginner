#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sum;
	int	posneg;

	i = 0;
	sum = 0;
	posneg = 1;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		posneg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum * posneg);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%i\n", ft_atoi(argv[1]));  // killme
	}
}
