/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:47:10 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:08 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_nums(t_mlx_data *data)
{
	data->nums.n0 = NULL;
	data->nums.n1 = NULL;
	data->nums.n2 = NULL;
	data->nums.n3 = NULL;
	data->nums.n4 = NULL;
	data->nums.n5 = NULL;
	data->nums.n6 = NULL;
	data->nums.n7 = NULL;
	data->nums.n8 = NULL;
	data->nums.n9 = NULL;
	data->nums.n9 = NULL;
	data->nums.mov = NULL;
	return ;
}

void	init_img(t_mlx_data *data)
{
	data->map.exit = NULL;
	data->map.floor = NULL;
	data->map.item1 = NULL;
	data->map.item2 = NULL;
	data->map.wall = NULL;
	data->map.ennemy = NULL;
	data->player.start = NULL;
	data->player.a1 = NULL;
	data->player.a2 = NULL;
	data->player.d1 = NULL;
	data->player.d2 = NULL;
	data->player.s1 = NULL;
	data->player.s2 = NULL;
	data->player.w1 = NULL;
	data->player.w2 = NULL;
	init_nums(data);
	return ;
}
