#include <stdlib.h>
#include <stdio.h> //killme

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

int	*ft_range(int start, int end)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	if (start > end)
	{
		size = start - end + 1;
		tab = malloc(sizeof(int) * size);
		while (i < size)
		{
			tab[i] = start - i;
			i++;
		}
	}
	else
	{
		size = end - start + 1;
		tab = malloc(sizeof(int) * size);
		while (i < size)
		{
			tab[i] = start + i;
			i++;
		}
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	i;
	int start;
	int end;
	int	size;

	if (argc == 3)
	{
		start = ft_atoi(argv[1]);
		end = ft_atoi(argv[2]);
		tab = ft_range(start, end);
		i = 0;
		if (start > end)
			size = start - end + 1;
		else
			size = end - start + 1;
		while (i < size)
		{
			printf("%i ", tab[i]);
				i++;
		}
	}
}
