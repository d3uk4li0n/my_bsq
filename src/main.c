#include "../include/my_bsq.h"

int main(int argc, char **argv){
	if(argc < 2){
		printf("map file needed\n");
		return 1;
	}
	if(open(argv[1], O_RDONLY) == -1){
		printf("invalid map file given\n");
		return -1;
	}
	my_bsq(argv[1]);

	return 0;
}