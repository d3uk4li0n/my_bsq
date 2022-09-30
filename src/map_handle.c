#include "../include/my_bsq.h"

//reads size of the map, meaning the first line, from file 
int read_size(char *file_name){
	int size = 0;
	char buf[5];
	
	int fd = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("couldn't open map file\n");
		return -1;
	}
	
	read(fd, &buf, 5);
	
	int i = 0;
	//convert size to int
	while(buf[i] != '\n' && i < 5){
		size = size * 10 + (buf[i] - '0');
		i++;
	}

	//buf[i] = '\0';
	close(fd);
	//printf("%d\n", size);
	return size;
}

//read map from file and writes into char **array
char_map get_map(char *map_file){
	char_map map;
	int fd;
	char c = '\0';
	
	map.size = read_size(map_file);
	if(map.size <= 0){
		printf("error getting map size\n");
		return map;
	}
	
	fd = open(map_file, O_RDONLY);	
	if(fd == -1){
		printf("error opening map file\n");
		return map;
	}
	map.map = (malloc(sizeof(char *) * map.size));

	//wanna skip the first line
	while(c != '\n') read(fd, &c, 1);

	for(int i = 0; i < map.size; i++){
		map.map[i] = malloc(sizeof(char)*map.size);
		for(int n = 0; n< map.size; n++){
			read(fd, &c, 1);
			map.map[i][n] = c;
		};
		read(fd, &c, 1); //ignore the \n
	}
	close(fd);
	return map;
}

void print_map(char_map map){
	for(int i = 0; i < map.size; i++){
		for(int j = 0; j< map.size; j++){
			printf("%c", map.map[i][j]);
		}
		printf("\n");
	}
}

void free_map(char_map map){
	for(int i = 0; i < map.size; i++) free(map.map[i]);
	free(map.map);
}
