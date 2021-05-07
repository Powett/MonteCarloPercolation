# MonteCarloPercolation
Checks wether a grid percolates or not, and estimates the threshold of open cases to do so using Monte-Carlo approach.

Compile using the makefile

All "df" refers to a naive implementation of a grid, and "uf" to an implementation using union-find architecture

Run :
  test-percolate-uf [grid_file] : tests wether the grid given in argument percolates and draws the result
  Format of grid_file : like map3, COLUMNS LINES\n### ###... ('#' = closed, ' '=open)
  
 
  threshold-uf [nb_iterations] : estimates the number of opened cases needed to make a size*size (change in the .c file before compilation, default 300) grid percolates,
  using nb_iterations iterations of "opening a random case - testing-..."
  
"Monte_carlos" directory contains a set of examples of 1024*1024 grids percolated using dfs or uf architectures.
