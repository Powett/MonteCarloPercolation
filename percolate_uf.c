#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_uf.h"

bool test_perco_uf(Grid grille)
{
	int taille=grille.width * grille.height;
	return (get_rep(&(grille.cells[taille])) == get_rep(&(grille.cells[taille+1])));	
}
