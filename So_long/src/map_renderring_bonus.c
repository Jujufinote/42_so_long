/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderring_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:51:19 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/08 11:21:45 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	env(t_mlx_data *data, char chr, int x, int y)
{
	if (chr == CWALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.wall, x, y);
	if (chr == CFLOOR)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.floor, x, y);
	if (chr == CEXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.exit, x, y);
	if (chr == CITEM)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.item1, x, y);
	if (chr == ITEM_VALID)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.item2, x, y);
	if (chr == CPLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.floor, x, y);
	return ;
}

void	map_renderring(t_mlx_data *data, int i, int x, int y)
{
	env(data, data->map.str[i], x, y);
	if (data->map.str[i] == CENNEMY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.ennemy, x, y);
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
