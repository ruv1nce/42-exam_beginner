#include <unistd.h>

static void	capit(char *s)
{
	char	*start;

	start = s;
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			/* if *s is not first char and previous char is not a space - lowerize */
			if (s != start && (*(s - 1) != ' ' && *(s - 1) != '\t'))
				*s += 32;
		}
		else if (*s >= 'a' && *s <= 'z')
			/* if *s is first char or previous char is a space - capitalize  */
			if (s == start || (*(s - 1) == ' ' || *(s - 1) == '\t'))
				*s -= 32;
		write(1, s, 1);
		s++;
	}
}

int	main(int argc, char **argv)
{
	int	k;

	if (argc > 1)
	{
		k = 0;
		while (++k < argc)
		{
			capit(argv[k]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
}
