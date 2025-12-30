/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:00:57 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/09 11:21:35 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42
# define CFLOOR '0'
# define CWALL '1'
# define CEXIT 'E'
# define CPLAYER 'P'
# define CITEM 'C'
# define ITEM_VALID 'S'

# include "Ft_printf/ft_printf.h"
# include "Libft/libft.h"

# include <mlx.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <X11/keysym.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		i;
	int		m;
	void	*start;
}			t_player;

typedef struct s_map
{
	char	*str;
	char	*dup;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*item1;
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

/*checks.c*/
int		is_strange(char *map_str);
int		is_walls(char *map_dup);
void	flood(char *map_dup, int i, int width);
int		check_flood(t_mlx_data *data);

/*init_struct.c*/
void	init_img(t_mlx_data *data);

/*renderring.c*/
void	renderring(t_mlx_data *data);

/*window_renderring.c*/
void	dimensions(t_mlx_data *data);
void	window_renderring(t_mlx_data *data);

/*map_renderring.c*/
void	map_renderring(t_mlx_data *data, int i, int x, int y);

/*init_img.c*/
int		player_img(t_mlx_data *data);
int		map_img(t_mlx_data *data);

/*handler_input.c*/
int		handle_key_input(int keysym, t_mlx_data *data);

/*close.c*/
void	close_map(t_mlx_data *data);
void	close_player(t_mlx_data *data);
void	close_window(t_mlx_data *data);
int		ft_close(t_mlx_data *data);
int		close_close(t_mlx_data *data);

/*movements.c*/
void	go_forward(t_mlx_data *data);
void	go_left(t_mlx_data *data);
void	go_backward(t_mlx_data *data);
void	go_right(t_mlx_data *data);

#endif
