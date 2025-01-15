CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = ./Mandatory/so_long.c ./Mandatory/get_next_line.c ./Mandatory/get_next_line_utils.c \
      ./Mandatory/check_map.c ./Mandatory/ft_split.c ./Mandatory/ft_strncmp.c ./Mandatory/draw_map.c \
      ./Mandatory/events.c ./Mandatory/flood_fill.c ./Mandatory/free_data.c ./Mandatory/ft_putchar.c \
      ./Mandatory/ft_unsigned_putnbr.c ./Mandatory/ft_printf.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = ./Bonus/so_long_bonus.c ./Bonus/get_next_line.c ./Bonus/get_next_line_utils.c \
            ./Bonus/check_map.c ./Bonus/ft_split.c ./Bonus/ft_strncmp.c ./Bonus/load_img.c \
            ./Bonus/render_map.c ./Bonus/events.c ./Bonus/flood_fill.c ./Bonus/free_data.c \
            ./Bonus/enemy.c ./Bonus/move_count.c ./Bonus/move_enemy.c
BONUS_OBJ = $(SRC_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(NAME) created (mandatory mode)."

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ)
	@$(CC) $(BONUS_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) created (bonus mode)."

./Mandatory/%.o: ./Mandatory/%.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

./Bonus/%.o: ./Bonus/%.c ./Bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "Executables removed."

re: fclean all
