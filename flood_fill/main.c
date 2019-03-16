#include <stdlib.h>
#include <stdio.h>	//killme
#include "flood_fill.h"
#include "test_functions.h"

int main(void)
{
    char **area;
    t_point size = {8, 5};
    t_point begin = {2, 2};
    char *zone[] = {
        "1 1 1 1 1 1 0 1",
        "0 0 0 0 1 0 0 0",
        "1 0 0 0 0 0 1 1",
        "1 0 1 1 0 1 1 0",
        "0 0 1 0 0 0 0 0",
    };
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin.x, begin.y);
	printf("\n");
    print_tab(area);
    return (0);
}
