#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			if (!argv[2][j])
			{
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
		write(1, argv[1], ft_strlen(argv[1]));
	}
	write(1, "\n", 1);
}
