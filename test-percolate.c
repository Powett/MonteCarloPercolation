#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"
#include <stdbool.h>

int main(int argc, char *argv[])
{
	Grid grille;
	bool test=false;
	grille=read_grid(argv[1]);
	test=test_perco(grille);
	create_image_grid(grille, "im.ppm");
	
	if (test) {printf("Ca percole !\n");}
	else {printf("Ca ne percole pas\n");}
	free_grid(grille);
	}
