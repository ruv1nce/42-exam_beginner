#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*s;
	char	c;
	if (argc == 2)
	{
		s = *(argv + 1);
		while (*s)
		{
			if (*s >= 'A' && *s <= 'Z')
			{
				c = 'A' + 'Z' - *s;
				write(1, &c, 1);
			}
			else if (*s >= 'a' && *s <= 'z')
			{
				c = 'a' + 'z' - *s;
				write(1, &c, 1);
			}
			s++;
		}
	}
	write(1, "\n", 1);
}
