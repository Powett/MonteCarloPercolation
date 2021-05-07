#include "generate-image.h"
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"

bool test_perco(Grid grille)
{
	int width;
	int i=0;
	bool percolated= false;
	width= grille.width;
	for (i=0;i<width;i++)
	{
		percolated=fill(&grille,0,i);
		if (percolated) {return true;}
	}
	return false;	
}

bool fill(Grid* grille, int row, int col)
{
	int height=grille->height,width=grille->width;
	if (grille->cells[row * width + col].checked)
	{return false;}
	grille->cells[row * width + col].checked=true;
	if (!(grille->cells[row * width + col].open))
	{return false;}
	if (row+1== height)
	{return true;}
	if (row+1<height && fill(grille,row+1,col)) {return true;}
	if (col-1>0 && fill(grille,row,col-1)) {return true;}
	if (col+1< width && fill(grille,row,col+1)) {return true;}
	if (row-1>0 && fill(grille,row-1,col)) {return true;}
	return false;
}
