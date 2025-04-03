NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
OBJS = philosophers.o fork.o init.o routine.o utils.o monitor.o philosophers_dinning.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

philosophers.o: philosophers.c philosophers.h
	$(CC) $(CFLAGS) -c philosophers.c -o philosophers.o

fork.o: fork.c philosophers.h
	$(CC) $(CFLAGS) -c fork.c -o fork.o

init.o: init.c philosophers.h
	$(CC) $(CFLAGS) -c init.c -o init.o

routine.o: routine.c philosophers.h
	$(CC) $(CFLAGS) -c routine.c -o routine.o

utils.o: utils.c philosophers.h
	$(CC) $(CFLAGS) -c utils.c -o utils.o

monitor.o: monitor.c philosophers.h
	$(CC) $(CFLAGS) -c monitor.c -o monitor.o

philosophers_dinning.o: philosophers_dinning.c philosophers.h
	$(CC) $(CFLAGS) -c philosophers_dinning.c -o philosophers_dinning.o

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re