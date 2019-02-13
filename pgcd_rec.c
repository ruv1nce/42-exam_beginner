#include <stdio.h>
#include <stdlib.h>
  
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return (b); 
    if (b == 0) 
       return (a); 
    if (a == b) 
        return (a); 
    if (a > b) 
        return (gcd(a-b, b));
    return (gcd(a, b-a)); 
} 
  
int main(int argc, char **argv) 
{
	if (argc == 3)
	{
		printf("%i", gcd(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
} 
