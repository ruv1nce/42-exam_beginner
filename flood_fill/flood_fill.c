#include "flood_fill.h"
#include <stdio.h>	//KILLME
#include "test_functions.h"	//KILLME

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
//	printf("x %i, y %i\n", begin.x, begin.y);	//KILLME
//	print_tab(tab);	//KILLME
	if ((begin.x+1 < size.x) && (tab[begin.y][begin.x+1] == c))
	{
		begin.x = begin.x+1;
		flood_fill(tab, size, begin);
		begin.x = begin.x-1;
	}
	if (begin.x > 0 && (tab[begin.y][begin.x-1] == c))
	{
		begin.x = begin.x-1;
		flood_fill(tab, size, begin);
		begin.x = begin.x+1;
	}
	if ((begin.y+1 < size.y) && (tab[begin.y+1][begin.x] == c))
	{
		begin.y = begin.y+1;
		flood_fill(tab, size, begin);
		begin.y = begin.y-1;
	}
	if (begin.y > 0 && (tab[begin.y-1][begin.x] == c))
	{
		begin.y = begin.y-1;
		flood_fill(tab, size, begin);
		begin.y = begin.y+1;
	}	
}
