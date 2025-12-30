/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:21:15 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/06 12:15:15 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_img(t_mlx_data *data)
{
	data->map.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/wall.xpm", &data->bin, &data->bin);
	data->map.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/floor.xpm", &data->bin, &data->bin);
	data->map.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/exit.xpm", &data->bin, &data->bin);
	data->map.item1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/fox1.xpm", &data->bin, &data->bin);
	if (data->map.wall == NULL || data->map.floor == NULL \
	|| data->map.exit == NULL || data->map.item1 == NULL)
		return (1);
	return (0);
}

int	player_img(t_mlx_data *data)
{
	data->player.start = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/start.xpm", &data->bin, &data->bin);
	if (data->player.start == NULL)
		return (1);
	return (0);
}
