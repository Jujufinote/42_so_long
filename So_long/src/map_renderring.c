/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:51:23 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/08 10:34:10 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_renderring(t_mlx_data *data, int i, int x, int y)
{
	if (data->map.str[i] == CWALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.wall, x, y);
	if (data->map.str[i] == CFLOOR)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.floor, x, y);
	if (data->map.str[i] == CEXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.exit, x, y);
	if (data->map.str[i] == CITEM)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.item1, x, y);
	if (data->map.str[i] == CPLAYER)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, x, y);
		data->player.x = x;
		data->player.y = y;
		data->player.i = i;
	}
	if (data->map.str[i] == '\n')
		map_renderring(data, i + 1, 0, y + 48);
	else if (data->map.str[i] != '\0')
		map_renderring(data, i + 1, x + 48, y);
	return ;
}
