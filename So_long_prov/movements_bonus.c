/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:51:29 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/08 11:21:22 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_forward(t_mlx_data *data, int i)
{
	if (data->map.str[i - data->map.width - 1] != CWALL)
	{
		if (data->player.m % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.w1, data->player.x, data->player.y - 48);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.w2, data->player.x, data->player.y - 48);
		if (data->map.str[i - data->map.width - 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[i - data->map.width - 1] = ITEM_VALID;
		}
		env(data, data->map.str[i], data->player.x, data->player.y);
		data->total_mov++;
		data->player.y -= 48;
		data->player.i = i - 1 - data->map.width;
		data->player.m++;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_left(t_mlx_data *data, int i)
{
	if (data->map.str[i - 1] != CWALL)
	{
		if (data->player.m % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.a1, data->player.x - 48, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.a2, data->player.x - 48, data->player.y);
		if (data->map.str[i - 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[i - 1] = ITEM_VALID;
		}
		env(data, data->map.str[i], data->player.x, data->player.y);
		data->total_mov++;
		data->player.x -= 48;
		data->player.i -= 1;
		data->player.m++;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_backward(t_mlx_data *data, int i)
{
	if (data->map.str[i + data->map.width + 1] != CWALL)
	{
		if (data->player.m % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.s1, data->player.x, data->player.y + 48);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.s2, data->player.x, data->player.y + 48);
		if (data->map.str[i + data->map.width + 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[i + data->map.width + 1] = ITEM_VALID;
		}
		env(data, data->map.str[i], data->player.x, data->player.y);
		data->total_mov++;
		data->player.y += 48;
		data->player.i = i + data->map.width + 1;
		data->player.m++;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}

void	go_right(t_mlx_data *data, int i)
{
	if (data->map.str[i + 1] != CWALL)
	{
		if (data->player.m % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.d1, data->player.x + 48, data->player.y);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player.d2, data->player.x + 48, data->player.y);
		if (data->map.str[i + 1] == CITEM)
		{
			data->map.nb_item--;
			data->map.str[i + 1] = ITEM_VALID;
		}
		env(data, data->map.str[i], data->player.x, data->player.y);
		data->total_mov++;
		data->player.x += 48;
		data->player.i += 1;
		data->player.m++;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.start, data->player.x, data->player.y);
	return ;
}
