#include "grid.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
	
	int tot=0;
	bool test=true;
	int taille=100;
	Grid grille=create_grid(taille,taille,true);
	
	for (int i=0;i<taille;i++)
	{
		for (int j=0;j<taille;j++)
		{
			tot=i*taille+j;
			merge(&(grille.cells[tot]), &(grille.cells[tot%4]));
			}
	}
	for (int i=0;i<taille;i++)
	{
		for (int j=0;j<taille;j++)
		{
			tot=i*taille+j;
			test= test && (get_rep(&(grille.cells[tot])) == get_rep(&(grille.cells[tot%4])));
			}
	}
	printf("%d\n", test);
	/*
	printf("%p, %p\n", grille.cells[5].parent, &grille.cells[5]);
	merge(&grille.cells[6], &grille.cells[5]);
	printf("%p, %p\n", grille.cells[5].parent, &grille.cells[5]);
	printf("%d,%d\n", get_rep(&(grille.cells[5]))->row,get_rep(&(grille.cells[5]))->column);
	*/
	free_grid(grille);
	}
