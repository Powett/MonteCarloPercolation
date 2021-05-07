all : test-loader test-generate-image test-percolate

test-loader : grid.c loader.c test-loader.c
	gcc -std=c99 -I -Wall -Werror -o test-loader "test-loader.c" "grid.c" "loader.c"
test-generate-image : grid.c loader.c generate-image.c test-generate-image.c
	gcc -std=c99 -I -Wall -Werror -o test-generate-image "test-generate-image.c" "generate-image.c" "grid.c" "loader.c"
test-percolate : grid.c loader.c generate-image.c test-percolate.c percolate_dfs.c
	gcc -std=c99 -I -Wall -Werror -o test-percolate "test-percolate.c" "percolate_dfs.c" "generate-image.c" "grid.c" "loader.c"
threshold-dfs : grid.c loader.c generate-image.c threshold-dfs.c percolate_dfs.c monte_carlo_dfs.c
	gcc -std=c99 -Wall -Werror -o threshold-dfs "grid.c" "loader.c" "generate-image.c" "threshold-dfs.c" "percolate_dfs.c" "monte_carlo_dfs.c"
test-correctness : grid.c test-correctness.c
	gcc -std=c99 -I -Wall -Werror -o test-correctness "test-correctness.c" "grid.c"
	
test-percolate-uf : grid.c loader.c generate-image.c test-percolate.c percolate_uf.c
	gcc -std=c99 -I -Wall -Werror -o test-percolate-uf "test-percolate-uf.c" "percolate_uf.c" "generate-image.c" "grid.c" "loader.c"
threshold-uf : grid.c loader.c generate-image.c threshold-uf.c percolate_uf.c monte_carlo_uf.c percolate_dfs.c
	gcc -std=c99 -I -Wall -Werror -o threshold-uf "grid.c" "loader.c" "generate-image.c" "threshold-uf.c" "percolate_dfs.c" "percolate_uf.c" "monte_carlo_uf.c"
