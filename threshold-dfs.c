#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"
#include "monte_carlo_dfs.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
	int nb=10;
	if (argc>1) {nb= *argv[1]  - '0';}
	int results[nb];
	run_monte_multiple(300,300,nb,1024,results);
	for (i=0;i<nb;i++)
	{
		printf("\n%d", results[i]);
	}
	printf("\n");
	}
