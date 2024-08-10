.PHONY : all clean fclean re bonus

CFLAGS = -Wall -Werror -Wextra -g

LDFLAGS = -L.mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -LFt_printf -lftprintf -LLibft -lft -lXext -lX11 -lm -lz

NAME = so_long

NAME_BONUS = so_long_bonus

INCLUDE = ./so_long.h

INCLUDE_BONUS = ./so_long_bonus.h

BONUS = ./main_bonus.c \
		./reading.c \
		./main_checks_bonus.c \
		./checks_bonus.c \
		./init_struct_bonus.c \
		./renderring_bonus.c \
		./window_renderring_bonus.c \
		./map_renderring_bonus.c \
		./init_img_bonus.c \
		./handler_input_bonus.c \
		./close_bonus.c \
		./movements_bonus.c \
		./count.c

SRC = ./main.c \
		./reading.c \
		./main_checks.c \
		./checks.c \
		./init_struct.c \
		./renderring.c \
		./window_renderring.c \
		./map_renderring.c \
		./init_img.c \
		./handler_input.c \
		./close.c \
		./movements.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${BONUS:.c=.o}

%.o : %.c
	cc $(CFLAGS) -I/usr/include -I.mlx_linux -O3 -c $< -o $@

$(NAME) : $(OBJ)
	cd Ft_printf && make all
	cd Libft && make all
	cc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
# linkage options must be positioned next the file objects and sources

$(NAME_BONUS) : $(OBJ_BONUS)
	cd Ft_printf && make all
	cd Libft && make all
	cc $(CFLAGS) $(OBJ_BONUS) $(LDFLAGS) -o $(NAME_BONUS)

all : $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)
	cd Ft_printf && make clean
	cd Libft && make clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	cd Ft_printf && make fclean
	cd Libft && make fclean

re : fclean all

bonus : ${NAME_BONUS}