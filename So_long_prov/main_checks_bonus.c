/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:48:44 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:16 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_exit(char *map_str)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (map_str[i])
	{
		if (map_str[i] == CEXIT)
			e++;
		i++;
	}
	if (e == 0)
	{
		ft_printf("\nError in configuration : no exit detected\n\n");
		return (1);
	}
	else if (e > 1)
	{
		ft_printf("\nError in configuration : too much exits detected\n\n");
		return (1);
	}
	return (0);
}

int	is_item(t_mlx_data *data)
{
	int	i;
	int	item;

	i = 0;
	item = 0;
	while (data->map.str[i])
	{
		if (data->map.str[i] == CITEM)
			item++;
		i++;
	}
	if (item == 0)
	{
		ft_printf("\nError in configuration : no item detected\n\n");
		return (1);
	}
	data->map.nb_item = item;
	return (0);
}

int	is_player(char *map_str)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map_str[i])
	{
		if (map_str[i] == CPLAYER)
			p++;
		i++;
	}
	if (p == 0)
	{
		ft_printf("\nError in configuration : no start detected\n\n");
		return (1);
	}
	else if (p > 1)
	{
		ft_printf("\nError in configuration : too much starts detected\n\n");
		return (1);
	}
	return (0);
}

int	is_rectangular(char *map_str, int k)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map_str[i] != '\n')
		i++;
	while (map_str[k] != '\0')
	{
		j = 0;
		while (map_str[k] != '\n' && map_str[k] != '\0')
		{
			j++;
			k++;
		}
		if (k < ft_len(map_str))
			k++;
		if (i != j)
		{
			ft_printf("\nError in configuration : map is not rectangular\n\n");
			return (1);
		}
	}
	return (0);
}

void	map_checking(t_mlx_data	*data)
{
	if (is_exit(data->map.str) == 1 || is_player(data->map.str) == 1)
	{
		free(data->map.str);
		exit(EXIT_FAILURE);
	}
	if (is_item(data) == 1 || is_rectangular(data->map.str, 0) == 1)
	{
		free(data->map.str);
		exit(EXIT_FAILURE);
	}
	dimensions(data);
	if (is_strange(data->map.str) == 1 || check_flood(data) == 1)
	{
		free(data->map.str);
		exit(EXIT_FAILURE);
	}
	if (is_walls(data->map.dup) == 1)
	{
		ft_printf("\nError in configuration : not surrounded by walls\n\n");
		free(data->map.str);
		free(data->map.dup);
		exit(EXIT_FAILURE);
	}
	free(data->map.dup);
	return ;
}
