void	flood_fill(int x, int y, char **map, int size, int *cnt, t_coord *dogs)
{
	map[y][x] = '@';
	dogs[*cnt].x = x;
	dogs[*cnt].y = y;
	(*cnt)++;
	if ((x + 1 < size) && (map[y][x + 1] == '.') && *cnt < 4)
		flood_fill(x + 1, y, map, size, cnt, dogs);
	if (x > 0 && (map[y][x - 1] == '.') && *cnt < 4)
		flood_fill(x - 1, y, map, size, cnt, dogs);
	if ((y + 1 < size) && (map[y + 1][x] == '.') && *cnt < 4)
		flood_fill(x, y + 1, map, size, cnt, dogs);
	if (y > 0 && (map[y - 1][x] == '.') && *cnt < 4)
		flood_fill(x, y - 1, map, size, cnt, dogs);
}
