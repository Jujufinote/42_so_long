/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:47:33 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:10 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_mlx_data *data)
{
	data->map.exit = NULL;
	data->map.floor = NULL;
	data->map.item1 = NULL;
	data->map.wall = NULL;
	data->player.start = NULL;
	return ;
}
