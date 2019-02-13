#include <unistd.h>

static int	match_brackets(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
		return (1);
	return (0);
}

static int	count_brackets(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}')
			len++;
		i++;
	}
	return (len);
}

static int	brackets(char *s, int len)
{
	char	br[len + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	br[len] = '\0';
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			br[j] = s[i];
			j++;
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (!j)
				return (0);
			else
			{
				if (match_brackets(br[j - 1], s[i]))
				   br[--j] = '0';
				else
					return (0);
			}
		}
		i++;
	}
	if (j == 0 && br[j] == '0')
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int	i;
	int len;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			if (!(len = count_brackets(argv[i])))
				write(1, "OK\n", 3);
			else
				brackets(argv[i], len) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
		}
	else
		write(1, "\n", 1);
}
