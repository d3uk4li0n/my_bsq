#include "../include/my_bsq.h"

void my_bsq(char *map_file){
	char_map map = get_map(map_file);

	// top right of the square
	int max_i = -1;
	int max_j = -1;
	int max_square_size = 0; //size of the largest square

	//find the largest possible square
	for(int i = 0; i < map.size; i++){
		for(int j = 0; j < map.size; j++){
			//check the square with top-left (i,j)
			if (map.map[i][j] == '.'){
				//current size of square
				int size = 1;
				//extend the size of square until it is invalid (reach obstacle or outside of board)
				int accept = 1;
				while (accept){
					for(int k = 0; accept == 1 && k < size + 1; k++){					
						for(int l = 0; accept == 1 && l < size + 1; l++){
							if (i + k < map.size && j + l < map.size &&
								map.map[i + k][j + l] == '.'){}//is .
							else accept = 0; //it is obstacle
						}
					}
					if (accept == 1){
						size += 1;
					}
				}
				//update size
				if (max_square_size < size){
					max_i = i;
					max_j = j;
					max_square_size = size;
				}
			}			
		}
	}	

	//update map, fill with 'x' representing the square
	if (max_square_size > 0){
		for(int i = 0; i < max_square_size; i++){
			for(int j = 0; j < max_square_size; j++){
				map.map[max_i + i][max_j + j] = 'x';
			}
		}
	}
	print_map(map);
	free_map(map);
}
