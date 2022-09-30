## Description  

my_bsq -- finds and prints the biggest square in a map


## SYNOPSIS  

./my_bsq mapfile.txt

## DESCRIPTION  
You must find the largest possible square on a board while avoiding obstacles. The board is represented by a file passed as the program’s argument, respecting those constraints: 

• Its first line contains the number of lines on the board (and only that),  
• . (representing an empty place) and "o" (representing an obstacle) are the only two allowed characters for the other lines  
• All of the lines will be the same length (except the first one)  
• There will always be at least one line  
• Each line is terminated by \n.  

You program must print the board, with some "." replaced by "x" to represent the largest square you found.  

## Requirements  

Your code must be compiled with the flags -Wall -Wextra -Werror

## Technical specification

you must create a Makefile, and the ouput is the command itself  

You can use:  
malloc(3)  
free(3)  
open(2)  
read(2)  
close(2)  
printf(3)   
write(2)  

You can NOT use:  
Any functions / syscalls which does not appear in the previous list  
Yes, it includes exit  
 
## Usage
1. perl mapgen.pl [x] [y] [density] > map.txt  
	"perl mapgen.pl 10 10 4 > map.txt"  
	
2. compile with "make"  
3. ./my_bsq map.txt  
	see the map printed with 'x' representing the biggest square

5. you can clean up after usage with "make fclean"
