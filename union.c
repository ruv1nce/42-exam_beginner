#include <unistd.h>

int	check_first_occ(char *str, int cnt, char c)
{
	int	k;

	k = 0;
	if (cnt == -1)
	{
		while (str[k])
		{
			if (str[k] == c)
				return (1);
			k++;
		}
	}
	while (k < cnt)
	{
		if (str[k] == str[cnt])
			return (1);
		k++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (check_first_occ(argv[1], i, argv[1][i]) == 0)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (check_first_occ(argv[1], -1, argv[2][i]) == 0 && check_first_occ(argv[2], i, argv[2][i]) == 0)
			write(1, &argv[2][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
