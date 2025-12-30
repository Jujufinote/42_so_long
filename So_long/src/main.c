/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:50:59 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:21 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc < 2)
	{
		ft_printf("\nPut the name of the map please\n\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_printf("\nPut only one map please\n\n");
		return (1);
	}
	data.map.str = map_reading(argv[1]);
	map_checking(&data);
	data.total_mov = 0;
	init_img(&data);
	renderring(&data);
	return (0);
}
