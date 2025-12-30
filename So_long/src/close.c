/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:45:36 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/09 11:24:04 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_player(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.start);
	return ;
}

void	close_map(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.exit);
	mlx_destroy_image(data->mlx_ptr, data->map.floor);
	mlx_destroy_image(data->mlx_ptr, data->map.wall);
	mlx_destroy_image(data->mlx_ptr, data->map.item1);
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
	close_player(data);
	close_window(data);
	return (0);
}

int	close_close(t_mlx_data *data)
{
	close_map(data);
	close_player(data);
	close_window(data);
	exit(EXIT_SUCCESS);
}
