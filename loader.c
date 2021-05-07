#include "grid.h"
#include "loader.h"

Grid read_grid(char access[])
{
	FILE *p_file=fopen(access, "r");
	Grid grille;
	int height,width;
	int result;
	char val;
	int row=0,col=0;
	fscanf(p_file, "%d %d\n", &width, &height);
	grille=create_grid(width,height,true);	
	while (result != EOF)
	{
		result=fscanf(p_file,"%c",&val);
		switch (val)
		{
		case '\n':
				row++;
				col=-1;
				break;
		case '#':
				grille.cells[row*width+col].open=false;
				grille.cells[row*width+col].checked=false;
				break;
		case ' ':
				grille.cells[row*width+col].open=true;
				grille.cells[row*width+col].checked=false;
				break;
		case 'X':
				grille.cells[row*width+col].open=true;
				grille.cells[row*width+col].checked=true;
				break;
		default:
				grille.cells[row*width+col].open=true;
				grille.cells[row*width+col].checked=false;
				break;
		}
		col++;
	}
	fclose(p_file);
	return grille;
	}

