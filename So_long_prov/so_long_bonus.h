/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:58:53 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/09 11:23:22 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 42
# define CFLOOR '0'
# define CWALL '1'
# define CEXIT 'E'
# define CPLAYER 'P'
# define CITEM 'C'
# define ITEM_VALID 'S'
# define CENNEMY 'T'
# define NUM0 '0'
# define NUM1 '1'
# define NUM2 '2'
# define NUM3 '3'
# define NUM4 '4'
# define NUM5 '5'
# define NUM6 '6'
# define NUM7 '7'
# define NUM8 '8'
# define NUM9 '9'

# include "Ft_printf/ft_printf.h"
# include "Libft/libft.h"

# include <mlx.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <X11/keysym.h>

typedef struct s_nums
{
	void	*n0;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;
	void	*mov;
}			t_nums;

typedef struct s_player
{
	int		x;
	int		y;
	int		i;
	int		m;
	void	*start;
	void	*w1;
	void	*w2;
	void	*a1;
	void	*a2;
	void	*s1;
	void	*s2;
	void	*d1;
	void	*d2;
}			t_player;

typedef struct s_map
{
	char	*str;
	char	*dup;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*item1;
	void	*item2;
	void	*ennemy;
	int		nb_item;
	int		width;
	int		height;
}					t_map;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			total_mov;
	t_map		map;
	t_player	player;
	t_nums		nums;
	int			bin;
}					t_mlx_data;

/*main.c*/
int		main(int argc, char **argv);

/*reading.c*/
int		ft_len(char *str);
char	*ft_join(char *map_str, char *buffer);
char	*reading(int fd);
char	*map_reading(char *map);

/*main_checks.c*/
int		is_exit(char *map_str);
int		is_item(t_mlx_data *data);
int		is_player(char *map_str);
int		is_rectangular(char *map_str, int k);
void	map_checking(t_mlx_data *data);

/*checks_bonus.c*/
int		is_strange(char *map_str);
int		is_walls(char *map_dup);
void	flood(char *map_dup, int i, int width);
int		check_flood(t_mlx_data *data);

/*init_struct_bonus.c*/
void	init_nums(t_mlx_data *data);
void	init_img(t_mlx_data *data);

/*renderring_bonus.c*/
void	renderring(t_mlx_data *data);

/*window_renderring_bonus.c*/
void	dimensions(t_mlx_data *data);
void	window_renderring(t_mlx_data *data);

/*map_renderring_bonus.c*/
void	env(t_mlx_data *data, char chr, int x, int y);
void	map_renderring(t_mlx_data *data, int i, int x, int y);

/*init_img_bonus.c*/
int		nums_img2(t_mlx_data *data);
int		nums_img(t_mlx_data *data);
int		player_img(t_mlx_data *data);
int		map_img(t_mlx_data *data);

/*handler_input_bonus.c*/
int		close_close(t_mlx_data *data);
int		handle_key_input(int keysym, t_mlx_data *data);

/*close_bonus.c*/
void	close_map(t_mlx_data *data);
void	close_nums(t_mlx_data *data);
void	close_player(t_mlx_data *data);
void	close_window(t_mlx_data *data);
int		ft_close(t_mlx_data *data);

/*movements_bonus.c*/
void	go_forward(t_mlx_data *data, int i);
void	go_left(t_mlx_data *data, int i);
void	go_backward(t_mlx_data *data, int i);
void	go_right(t_mlx_data *data, int i);

/*count.c*/
int		count(t_mlx_data *data);
void	ifs(t_mlx_data *data, int x, int i, char *nb);
void	ifs2(t_mlx_data *data, int x, int i, char *nb);

#endif
