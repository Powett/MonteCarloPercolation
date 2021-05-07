#include <stdio.h>
#include "generate-image.h"
#include "grid.h"
#include "loader.h"

void create_image(char *argv[])
{
	
	int i=0;
	int extension=0;
	int taille=0;
	int debut=0;
	char *nom;
	while (argv[1][i] != '\0') {i++;}
	while (argv[1][i-taille-extension] != '/') 
	{
		taille++;
		if (argv[1][i-taille-extension]=='.') {extension=taille;taille=0;}
	}
	taille--;
	debut=i-taille-extension;
	i=0;
	nom=malloc(sizeof(char)*(taille+4));
	while (argv[1][debut+i] != '.' && argv[1][debut+i] != '\0') 
	{
		nom[i]=argv[1][debut+i];
		i++;
		}
	nom[taille]='.';
	nom[taille+1]='p';
	nom[taille+2]='p';
	nom[taille+3]='m';
	create_image_grid(read_grid(argv[1]), nom);
	free(nom);
}

void create_image_grid(Grid grille, char name[])
{
		FILE *p_file=NULL;
		int width, height;
		width=grille.width;
		height=grille.height;
		int i=0,j=0;
		int color[3]={0,0,0};
		p_file=fopen(name, "w");
		fprintf(p_file, "P3\n%d %d\n255\n", width, height);
		for (i=0;i<height;i++)
		{
			for (j=0;j<width;j++)
			{
				if (grille.cells[i*width+j].open)
				{
					if (grille.cells[i*width+j].checked)
					{
						color[0]=255;
						color[1]=0;
						color[2]=0;
					}
					else
					{
						color[0]=255;
						color[1]=255;
						color[2]=255;
					}
				}
				else
					{
						color[0]=0;
						color[1]=0;
						color[2]=0;
					}
					
				fprintf(p_file,"%d %d %d ", color[0], color[1], color[2]);
			}
			fprintf(p_file,"\n");	
		}
		
		fclose(p_file);		
	}
