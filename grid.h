#include <stdio.h>
#include <stdlib.h>
#ifndef DEF_STRUCTURES
#define DEF_STRUCTURES
#define bool unsigned int
#define true 1
#define false 0

typedef struct Cell Cell;
struct Cell{
	int row, column;
	int rank;
	bool open;
	bool checked;
	Cell* parent;
	};
	
typedef struct Grid Grid;
struct Grid{
	int width;
	int height;
	Cell* cells;
	};


Grid create_grid(int width,int height,bool);
void free_grid(Grid);
void open_cell(Grid*, int row, int col);
void print_grid(Grid);
Grid copy_grid(Grid grille1);
void unsee(Grid* grille);
Cell *get_rep(Cell*);
void merge(Cell *p_1, Cell *p_2);
#endif
