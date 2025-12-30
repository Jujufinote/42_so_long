/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:53:07 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/09 11:25:00 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	renderring(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("\nError in the mlx's instance creation\n\n");
		free(data->map.str);
		exit(EXIT_FAILURE);
	}
	window_renderring(data);
	if (nums_img(data) == 1 || player_img(data) == 1 || map_img(data) == 1)
	{
		ft_printf("\nError in memory allocation for the images\n\n");
		ft_close(data);
		exit(EXIT_FAILURE);
	}
	map_renderring(data, 0, 0, 0);
	mlx_hook(data->win_ptr, 17, 0, close_close, data);
	mlx_hook(data->win_ptr, 02, 1L << 0, handle_key_input, data);
	mlx_loop(data->mlx_ptr);
	return ;
}
