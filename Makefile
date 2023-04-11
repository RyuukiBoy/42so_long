NAME=so_long
NAME_BONUS=so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = mandatory/src/so_long.c mandatory/src/key_code.c mandatory/src/player_moves.c mandatory/gnl/gnl.c mandatory/gnl/gnl_u.c mandatory/map_pars/walls.c mandatory/map_pars/items.c\
	  mandatory/map_pars/map_checks.c mandatory/src/additional_func.c mandatory/src/flood_fill.c mandatory/moves/up_action.c mandatory/moves/down_action.c mandatory/moves/right_action.c \
	  mandatory/moves/left_action.c mandatory/src/window_and_images.c mandatory/errors_and_free/free_map.c mandatory/errors_and_free/put_errors.c \
	  mandatory/ft_printf/ft_printf.c mandatory/ft_printf/ft_putchar.c mandatory/ft_printf/ft_putstr.c mandatory/ft_printf/ft_putnbr.c \
	  mandatory/ft_printf/ft_puthexa_low.c mandatory/ft_printf/ft_puthexa_upp.c mandatory/ft_printf/ft_putptr.c mandatory/ft_printf/ft_putunbr.c \

SRC_BONUS = bonus/ft_itoa.c bonus/so_long_bonus.c bonus/additional_func_bonus.c bonus/ghost_animation.c bonus/flood_fill_bonus.c bonus/key_code_bonus.c bonus/player_moves_bonus.c \
			bonus/windows_and_images_bonus.c bonus/errors_and_free_bonus/free_map_bonus.c bonus/errors_and_free_bonus/put_errors_bonus.c bonus/map_pars_bonus/items_bonus.c \
			bonus/map_pars_bonus/map_check_bonus.c bonus/map_pars_bonus/walls_bonus.c bonus/moves_bonus/down_action_bonus.c bonus/moves_bonus/left_action_bonus.c \
			bonus/moves_bonus/right_action_bonus.c bonus/moves_bonus/up_action_bonus.c mandatory/gnl/gnl.c mandatory/gnl/gnl_u.c mandatory/ft_printf/ft_printf.c \
			mandatory/ft_printf/ft_putchar.c mandatory/ft_printf/ft_putstr.c mandatory/ft_printf/ft_putnbr.c mandatory/ft_printf/ft_puthexa_low.c \
			mandatory/ft_printf/ft_puthexa_upp.c mandatory/ft_printf/ft_putptr.c mandatory/ft_printf/ft_putunbr.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
re: fclean all bonus

.PHONY: all clean fclean re
