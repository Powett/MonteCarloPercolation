#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"
#include <stdlib.h>

int run_monte_carlo_solo(int width, int height, int nb, int seed)
{
	Grid grille;
	int row, col;
	int nb_cellules_ouvertes=0;
	char nom[35];
	bool test=false;
	sprintf(nom,"./Monte_carlos/test-mc-dfs-%d-%d.ppm",nb, seed);
	grille=create_grid(width, height, false);

	while  (!test)
	{
		do
		{
		col=rand()%width;
		row=rand()%height;
		} while (grille.cells[row*width+col].open==true);
		open_cell(&grille, row, col);
		nb_cellules_ouvertes++;
		test=test_perco(grille);
		unsee(&grille);			
	}
	test_perco(grille);
	create_image_grid(grille, nom);
	free_grid(grille);
	return nb_cellules_ouvertes;

}

void run_monte_multiple(int width, int height, int nb, int seed, int resultats[])
{
	int i;
	srand(seed);
	for (i=1;i<nb+1;i++)
	{
		resultats[i-1]=run_monte_carlo_solo(width, height, i, seed);
	}
	return;
	}


