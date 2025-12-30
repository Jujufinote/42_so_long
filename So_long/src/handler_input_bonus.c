/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:40 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/09 11:24:23 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	close_close(t_mlx_data *data)
{
	close_map(data);
	close_nums(data);
	close_player(data);
	close_window(data);
	exit(EXIT_SUCCESS);
}

int	handle_key_input(int keysym, t_mlx_data *data)
{
	int	mov;
	int	item;

	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		go_forward(data, data->player.i);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		go_left(data, data->player.i);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		go_backward(data, data->player.i);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		go_right(data, data->player.i);
	count(data);
	mov = data->total_mov;
	item = data->map.nb_item;
	ft_printf("\nTotal moves : %d, item remaining : %d\n", mov, item);
	if (keysym == XK_Escape \
	|| (data->map.str[data->player.i] == CEXIT && data->map.nb_item == 0) \
	|| data->map.str[data->player.i] == CENNEMY)
	{
		ft_close(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
