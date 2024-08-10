/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:51:46 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/06 11:51:48 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_forward(t_mlx_data *data)
{
	if (data->map.str[data->player.i - data->map.width - 1] != CWALL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y - 48);
		if (data->map.str[data->player.i - data->map.width - 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[data->player.i - data->map.width - 1] = ITEM_VALID;
		}
		if (data->map.str[data->player.i] == CEXIT)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.exit, data->player.x, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.floor, data->player.x, data->player.y);
		data->total_mov++;
		data->player.y -= 48;
		data->player.i = data->player.i - 1 - data->map.width;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_left(t_mlx_data *data)
{
	if (data->map.str[data->player.i - 1] != CWALL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x - 48, data->player.y);
		if (data->map.str[data->player.i - 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[data->player.i - 1] = ITEM_VALID;
		}
		if (data->map.str[data->player.i] == CEXIT)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.exit, data->player.x, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.floor, data->player.x, data->player.y);
		data->total_mov++;
		data->player.x -= 48;
		data->player.i -= 1;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_backward(t_mlx_data *data)
{
	if (data->map.str[data->player.i + data->map.width + 1] != CWALL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y + 48);
		if (data->map.str[data->player.i + data->map.width + 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[data->player.i + data->map.width + 1] = ITEM_VALID;
		}
		if (data->map.str[data->player.i] == CEXIT)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.exit, data->player.x, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.floor, data->player.x, data->player.y);
		data->total_mov++;
		data->player.y += 48;
		data->player.i = data->player.i + data->map.width + 1;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_right(t_mlx_data *data)
{
	if (data->map.str[data->player.i + 1] != CWALL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x + 48, data->player.y);
		if (data->map.str[data->player.i + 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[data->player.i + 1] = ITEM_VALID;
		}
		if (data->map.str[data->player.i] == CEXIT)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.exit, data->player.x, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.floor, data->player.x, data->player.y);
		data->total_mov++;
		data->player.x += 48;
		data->player.i += 1;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}
