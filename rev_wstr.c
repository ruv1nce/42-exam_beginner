#include <unistd.h>
static void	print_word(char *s)
{
	while (*s && *s != ' ')
	{
		write(1, s, 1);
		s++;
	}
}

int	main(int argc, char **argv)
{
	char	*s;

	if (argc == 2)
	{
		if (*(s = *(argv + 1)))
		{
			while (*s)
				s++;
			s--;
			while (s != *(argv + 1))
			{
				if (*s == ' ')
				{
					print_word(s + 1);
					write(1, " ", 1);
				}
				s--;
			}
			print_word(s);
		}
	}
	write(1, "\n", 1);
}
