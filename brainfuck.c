#include <unistd.h>

int	main(int argc, char **argv)
{
	char	string[2048];
	char	*str;
	char	*ptr;
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (i < 2048)
	{
		string[i] = 0;
		i++;
	}
	ptr = *(argv + 1);
	str = &string[0];
	while (*ptr)
	{
		if (*ptr == '>')
			str++;
		else if (*ptr == '<')
			str--;
		else if (*ptr == '+')
			(*str)++;
		else if (*ptr == '-')
			(*str)--;
		else if (*ptr == '.')
			write(1, str, 1);
		else if (*ptr == '[' && !*str)
		{

			i = 1;
			while (i > 0)
			{
				ptr++;
				if (*ptr == '[')
					i++;
				else if (*ptr == ']')
					i--;
			}
		}
		else if (*ptr == ']' && *str)
		{
			i = 1;
			while (i > 0)
			{
				ptr--;
				if (*ptr == ']')
					i++;
				else if (*ptr == '[')
					i--;
			}
		}
		ptr++;
	}
}
