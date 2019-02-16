#include <unistd.h>

static void	rcapit(char *s)
{
	while (*s)
	{
		/* for capitals: if next char is not a space or \0 - lowerize */
		if ((*s >= 'A' && *s <= 'Z') && (*(s + 1) != ' ' && *(s + 1) != '\t' && *(s + 1)))
			*s += 32;
		/* for lowers: if next char is a space - capitalize */
		if ((*s >= 'a' && *s <= 'z') && (*(s + 1) == ' ' || *(s + 1) == '\t' || !*(s + 1)))
			*s -= 32;
		write(1, s, 1);
		s++;
	}
}

int			main(int argc, char **argv)
{
	int	k;

	if (argc > 1)
	{
		k = 0;
		while (++k < argc)
		{
			rcapit(argv[k]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
}
