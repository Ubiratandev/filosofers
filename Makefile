NAME = filosofers
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = filosofers.o fork.o init.o routine.o  # Adicione filosofers.o aqui

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  # Isso vai linkar todos os .o

# Regras para compilar cada .c em .o
filosofers.o: filosofers.c filosofers.h
	$(CC) $(CFLAGS) -c filosofers.c -o filosofers.o

fork.o: fork.c filosofers.h
	$(CC) $(CFLAGS) -c fork.c -o fork.o

init.o: init.c filosofers.h
	$(CC) $(CFLAGS) -c init.c -o init.o

routine.o: routine.c filosofers.h
	$(CC) $(CFLAGS) -c routine.c -o routine.o

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re