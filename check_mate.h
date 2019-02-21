#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# define UCELL grid[kpos.y-i][kpos.x]
# define DCELL grid[kpos.y+i][kpos.x]
# define LCELL grid[kpos.y][kpos.x-i]
# define RCELL grid[kpos.y][kpos.x+i]
# define ULCELL grid[kpos.y-i][kpos.x-i]
# define URCELL grid[kpos.y-i][kpos.x+i]
# define DRCELL grid[kpos.y+i][kpos.x+i]
# define DLCELL grid[kpos.y+i][kpos.x-i]


typedef struct	position
{
	int	x;
	int	y;
}				pos;

#endif
