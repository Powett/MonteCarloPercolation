#include "grid.h"
#include "loader.h"


int main(int argc, char *argv[])
{
	Grid grille;
	grille=read_grid(argv[1]);
	print_grid(grille);
	free_grid(grille);
	}
