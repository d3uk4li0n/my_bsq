CC=gcc 
CFLAGS+=-Wall -Wextra -Werror 
DEPS+=./include/my_bsq.h \
	./include/map.h
OBJ+=src/my_bsq.o src/main.o src/map_handle.o
TARGET=my_bsq

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

.PHONY: all clean fclean re
clean:
	rm -f src/*.o 

fclean: clean
	rm -f $(TARGET)

re: fclean all
