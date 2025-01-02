NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = so_long.c get_next_line.c get_next_line_utils.c check_map.c ft_split.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "Library $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."
re: fclean all
