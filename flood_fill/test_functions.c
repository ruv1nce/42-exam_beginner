#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **make_area(char **zone)
{
	int		cols;
	int		colcnt;
	int		colcnt2;
	int		rows;
	int		rowcnt;
	char	**area;

	rows = 0;
	while (zone[rows])
		rows++;
	cols = 0;
	if (zone[0])
		while (zone[0][cols])
			cols++;
//	printf("cols %i, rows %i\n", cols, rows);	//	KILLME
	/* allocate for pointer array + 1 for terminating pointer */
	if (!(area = malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	rowcnt = 0;
	/* allocate for each string */
	while (rowcnt < rows)
	{
		/* columns discounted by spaces + \0 */
		area[rowcnt] = malloc((cols / 2) + 2);
		rowcnt++;
	}
	*(area + rows) = NULL;
	rowcnt = 0;
	/* fill array */
	while (rowcnt < rows)
	{
		colcnt = 0;
		colcnt2 = 0;
		while (colcnt < cols)
		{
			if (zone[rowcnt][colcnt] != ' ')
			{
				area[rowcnt][colcnt2] = zone[rowcnt][colcnt];
				colcnt2++;
			}
			colcnt++;
		}
		area[rowcnt][colcnt2] = '\0';
		rowcnt++;
	}
	return (area);
}

void	print_tab(char **area)
{
	int	i;
	int	j;

	i = 0;
	while (area[i])
	{
//		printf("%s\n", *area);
		j = 0;
		while (area[i][j])
		{
			write(1, &area[i][j], 1);
			if (area[i][j])
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
