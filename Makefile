NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -lpthread

SRCS = src/actions.c src/extras.c src/philo.c src/read_args.c src/status.c src/threads.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(OBJS) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
