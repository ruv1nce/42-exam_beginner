#include <unistd.h>

int	main(int argc, char **argv)
{
	char	string[2048];
	char	*str = &string[0];
	char	*ptr;
	char	*tmp;
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (i < 2048)
	{
		str[i] = '\0';
		i++;
	}
	ptr = *(argv + 1);
	while (*ptr)
	{
		if (*ptr == '>')
			str++;
		else if (*ptr == '<')
			str--;
		else if (*ptr == '+')
			(*str)++;
		else if (*ptr == '-')
			(*str)++;
		else if (*ptr == '.')
			write(1, str, 1);
		else if (*ptr == '[' && *str == 0)
			tmp = ptr;
		else if (*ptr == ']' && *str != 0)
			ptr = tmp;
		ptr++;
	}
}
