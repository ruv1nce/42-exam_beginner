#include "flood_fill.h"
#include <stdio.h>	//KILLME
#include "test_functions.h"	//KILLME

void	flood_fill(char **tab, t_point size, int x, int y)
{
	char	c;

	c = tab[y][x];
	tab[y][x] = 'F';
	if ((x+1 < size.x) && (tab[y][x+1] == c))
		flood_fill(tab, size, x+1, y);
	if (x > 0 && (tab[y][x-1] == c))
		flood_fill(tab, size, x-1, y);
	if ((y+1 < size.y) && (tab[y+1][x] == c))
		flood_fill(tab, size, x, y+1);
	if (y > 0 && (tab[y-1][x] == c))
		flood_fill(tab, size, x, y-1);
}
