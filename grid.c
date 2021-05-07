#include "grid.h"

void open_cell(Grid *p_grille, int row, int col){
	int tot=0;
	int width, height;
	width=p_grille->width;
	height=p_grille->height;
	tot=row*width +col;
	(p_grille->cells[tot]).open=true;
	
	if (row==0) {merge(&(p_grille->cells[tot]), &(p_grille->cells[height*width]));}
	if (row==height-1) {merge(&(p_grille->cells[tot]), &(p_grille->cells[height*width + 1]));}
	if ((row<height-1) && (p_grille->cells[tot+width].open)) {merge(&(p_grille->cells[tot]), &(p_grille->cells[tot + width]));}
	if ((row>0) && (p_grille->cells[tot-width].open)) {merge(&(p_grille->cells[tot]), &(p_grille->cells[tot - width]));}
	if ((col<width-1) && (p_grille->cells[tot+1].open)) {merge(&(p_grille->cells[tot]), &(p_grille->cells[tot + 1]));}
	if ((col>0) && (p_grille->cells[tot-1].open)) {merge(&(p_grille->cells[tot]), &(p_grille->cells[tot -1]));}
	}

void print_grid(Grid grille){
	int i,j;
	int w=grille.width, h=grille.height;
	for (i=0;i<h;i++)
	{
		printf("\n|");
		for (j=0;j<w;j++)
		{
			if (grille.cells[i*w+j].open)
			{
				if (grille.cells[i*w+j].checked)
				{
					printf(" X ");
				}
				else
				{
					printf("   ");
				}
				
			}
			else
			{
			printf(" # ");
			}
		}
				
	
		printf("|");
	}
	printf("\n");
	}

Grid create_grid(int width, int height, bool ouv){
	int i;
	Grid grid={width, height,malloc(sizeof(Cell)*(height*width+2))};
	for (i=0;i<height*width +2 ;i++)
	{
		grid.cells[i].row=i/width;
		grid.cells[i].column=i%width;
		grid.cells[i].checked=false;
		grid.cells[i].open=ouv;
		grid.cells[i].parent=&(grid.cells[i]);
		grid.cells[i].rank=0;
	}
	grid.cells[width*height].open=true;
	grid.cells[width*height+1].open=true;

	return grid;
	}
	
Grid copy_grid(Grid gr1)
{
	Grid gr2;
	int i;
	gr2=create_grid(gr1.width,gr1.height, true);
	for (i=0;i<gr1.height * gr1.width;i++)
	{
		gr2.cells[i].row=i / gr1.width;
		gr2.cells[i].column=i % gr1.width;
		gr2.cells[i].checked= gr1.cells[i].checked;
		gr2.cells[i].open= gr1.cells[i].open;
		gr2.cells[i].parent=gr1.cells[i].parent;
		gr2.cells[i].rank=gr1.cells[i].rank;
	}
	return gr2;
	}

void unsee(Grid* gr)
{
	int i;
	for (i=0;i<gr->height * gr->width;i++)
	{
		gr->cells[i].checked=false;
	}
	}

void free_grid(Grid grille)
{
	free(grille.cells);
	}

Cell* get_rep(Cell* p_cell)
{
	if (p_cell != p_cell->parent)  {p_cell->parent=get_rep(p_cell->parent);}
	return p_cell->parent;
	}
void merge(Cell *p_1, Cell *p_2)
{
	p_1=get_rep(p_1);
	p_2=get_rep(p_2);
	if (p_1->rank>p_2->rank)
	{
		p_2->parent=p_1;
	}
	else if (p_1->rank<p_2->rank)
	{
		p_1->parent=p_2;
	}
	else if (p_1->rank==p_2->rank)
	{
		p_2->parent=p_1;
		p_1->rank++;
	}
	}
