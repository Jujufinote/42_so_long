/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_renderring_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:54:10 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:47 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	dimensions(t_mlx_data *data)
{
	int	nl;
	int	len;
	int	i;

	nl = 1;
	len = 0;
	while (data->map.str[len] != '\n')
		len++;
	i = len;
	while (data->map.str[i] != '\0')
	{
		if (data->map.str[i] == '\n' && data->map.str[i + 1] != '\0')
			nl++;
		i++;
	}
	data->map.width = len;
	data->map.height = nl;
	data->win_width = len * 48;
	data->win_height = nl * 48;
	return ;
}

void	window_renderring(t_mlx_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "so_long_bonus");
	if (data->win_ptr == NULL)
	{
		ft_printf("\nError in the window's instance creation\n\n");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->map.str);
		exit(EXIT_FAILURE);
	}
	return ;
}
