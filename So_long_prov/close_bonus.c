/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:45:01 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:12:57 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	close_nums(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->nums.n0);
	mlx_destroy_image(data->mlx_ptr, data->nums.n1);
	mlx_destroy_image(data->mlx_ptr, data->nums.n2);
	mlx_destroy_image(data->mlx_ptr, data->nums.n3);
	mlx_destroy_image(data->mlx_ptr, data->nums.n4);
	mlx_destroy_image(data->mlx_ptr, data->nums.n5);
	mlx_destroy_image(data->mlx_ptr, data->nums.n6);
	mlx_destroy_image(data->mlx_ptr, data->nums.n7);
	mlx_destroy_image(data->mlx_ptr, data->nums.n8);
	mlx_destroy_image(data->mlx_ptr, data->nums.n9);
	mlx_destroy_image(data->mlx_ptr, data->nums.mov);
	return ;
}

void	close_player(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.start);
	mlx_destroy_image(data->mlx_ptr, data->player.w1);
	mlx_destroy_image(data->mlx_ptr, data->player.w2);
	mlx_destroy_image(data->mlx_ptr, data->player.a1);
	mlx_destroy_image(data->mlx_ptr, data->player.a2);
	mlx_destroy_image(data->mlx_ptr, data->player.s1);
	mlx_destroy_image(data->mlx_ptr, data->player.s2);
	mlx_destroy_image(data->mlx_ptr, data->player.d1);
	mlx_destroy_image(data->mlx_ptr, data->player.d2);
	return ;
}

void	close_map(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.exit);
	mlx_destroy_image(data->mlx_ptr, data->map.floor);
	mlx_destroy_image(data->mlx_ptr, data->map.wall);
	mlx_destroy_image(data->mlx_ptr, data->map.item1);
	mlx_destroy_image(data->mlx_ptr, data->map.item2);
	mlx_destroy_image(data->mlx_ptr, data->map.ennemy);
	return ;
}

void	close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->map.str);
	return ;
}

int	ft_close(t_mlx_data *data)
{
	close_map(data);
	close_nums(data);
	close_player(data);
	close_window(data);
	return (0);
}
