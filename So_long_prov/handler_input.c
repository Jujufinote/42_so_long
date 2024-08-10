/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:57 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:05 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		go_forward(data);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		go_left(data);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		go_backward(data);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		go_right(data);
	ft_printf("\nTotal moves : %d", data->total_mov);
	if (keysym == XK_Escape \
	|| (data->map.str[data->player.i] == CEXIT && data->map.nb_item == 0))
	{
		ft_close(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
