#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_uf.h"
#include "monte_carlo_uf.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	int i;
	int nb=50;
	int size=300;
	if (argc>1) {nb= *argv[1]  - '0';}
	int results[nb];
	run_monte_multiple_uf(size,size,nb,1024,results);
	for (i=0;i<nb;i++)
	{
		printf("\n%d", results[i]);
	}
	printf("\n");
}
