/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:52:26 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/06 12:14:48 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	nums_img2(t_mlx_data *data)
{
	data->nums.n6 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/6.xpm",
			&data->bin, &data->bin);
	data->nums.n7 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/7.xpm",
			&data->bin, &data->bin);
	data->nums.n8 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/8.xpm",
			&data->bin, &data->bin);
	data->nums.n9 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/9.xpm",
			&data->bin, &data->bin);
	data->nums.mov = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/mov.xpm",
			&data->bin, &data->bin);
	if (data->nums.n6 == NULL || data->nums.n7 == NULL \
	|| data->nums.n8 == NULL || data->nums.n9 == NULL \
	|| data->nums.mov == NULL)
		return (1);
	return (0);
}

int	nums_img(t_mlx_data *data)
{
	data->nums.n0 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/0.xpm",
			&data->bin, &data->bin);
	data->nums.n1 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/1.xpm",
			&data->bin, &data->bin);
	data->nums.n2 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/2.xpm",
			&data->bin, &data->bin);
	data->nums.n3 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/3.xpm",
			&data->bin, &data->bin);
	data->nums.n4 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/4.xpm",
			&data->bin, &data->bin);
	data->nums.n5 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/5.xpm",
			&data->bin, &data->bin);
	if (data->nums.n0 == NULL || data->nums.n1 == NULL || data->nums.n2 == NULL \
	|| data->nums.n3 == NULL || data->nums.n4 == NULL || data->nums.n5 == NULL \
	|| nums_img2(data) == 1)
		return (1);
	return (0);
}

int	player_img(t_mlx_data *data)
{
	data->player.start = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/start.xpm", &data->bin, &data->bin);
	data->player.w1 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/w1.xpm",
			&data->bin, &data->bin);
	data->player.w2 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/w2.xpm",
			&data->bin, &data->bin);
	data->player.a1 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/a1.xpm",
			&data->bin, &data->bin);
	data->player.a2 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/a2.xpm",
			&data->bin, &data->bin);
	data->player.s1 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/s1.xpm",
			&data->bin, &data->bin);
	data->player.s2 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/s2.xpm",
			&data->bin, &data->bin);
	data->player.d1 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/d1.xpm",
			&data->bin, &data->bin);
	data->player.d2 = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/d2.xpm",
			&data->bin, &data->bin);
	if (data->player.start == NULL || data->player.w1 == NULL \
	|| data->player.w2 == NULL || data->player.a1 == NULL \
	|| data->player.a2 == NULL || data->player.s1 == NULL \
	|| data->player.s2 == NULL || data->player.d1 == NULL \
	|| data->player.d2 == NULL)
		return (1);
	return (0);
}

int	map_img(t_mlx_data *data)
{
	data->map.wall = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/wall.xpm",
			&data->bin, &data->bin);
	data->map.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/floor.xpm", &data->bin, &data->bin);
	data->map.exit = mlx_xpm_file_to_image(data->mlx_ptr, "Textures/exit.xpm",
			&data->bin, &data->bin);
	data->map.item1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/fox1.xpm", &data->bin, &data->bin);
	data->map.item2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/fox2.xpm", &data->bin, &data->bin);
	data->map.ennemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/ennemy.xpm", &data->bin, &data->bin);
	if (data->map.wall == NULL || data->map.floor == NULL \
	|| data->map.exit == NULL || data->map.item1 == NULL \
	|| data->map.item2 == NULL || data->map.ennemy == NULL)
		return (1);
	return (0);
}
