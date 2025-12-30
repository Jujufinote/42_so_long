/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:34 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:12:55 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_strange(char *map_dup)
{
	int	i;

	i = 0;
	while (map_dup[i])
	{
		if (map_dup[i] != CEXIT && map_dup[i] != CFLOOR && map_dup[i] != CWALL \
				&& map_dup[i] != CITEM && map_dup[i] != CPLAYER \
				&& map_dup[i] != '\n' && map_dup[i] != '\0')
		{
			ft_printf("\nError in configuration : unknown element\n\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_walls(char *map_dup)
{
	int	i;

	i = 0;
	while (map_dup[i] != '\n' && map_dup[i] != 'F')
		i++;
	if (map_dup[i] != '\n')
		return (1);
	while (map_dup[i++] != '\0')
	{
		if (map_dup[i] == '\n' && map_dup[i + 1] != '\0')
		{
			if (map_dup[i - 1] == 'F' || map_dup[i + 1] == 'F')
				return (1);
		}
	}
	i--;
	while (map_dup[i] != '\n')
	{
		if (map_dup[i] == '\0' && map_dup[i - 1] == '\n')
			i -= 2;
		i--;
		if (map_dup[i] == 'F')
			return (1);
	}
	return (0);
}

void	flood(char *map_dup, int i, int width)
{
	if (map_dup[i] == CFLOOR || map_dup[i] == CPLAYER || map_dup[i] == CEXIT \
	|| map_dup[i] == CITEM)
	{
		map_dup[i] = 'F';
		if (map_dup[i + 1] != '\0')
			flood(map_dup, i + 1, width);
		if (i + width + 1 < ft_len(map_dup))
			flood(map_dup, i + width + 1, width);
		if (i > 0)
			flood(map_dup, i - 1, width);
		if (i > width + 1)
			flood(map_dup, i - width - 1, width);
	}
	return ;
}

int	check_flood(t_mlx_data *data)
{
	int	i;

	i = 0;
	data->map.dup = ft_strdup(data->map.str);
	if (data->map.dup == NULL)
	{
		ft_printf("\nError in memory allocation\n\n");
		return (1);
	}
	while (data->map.dup[i] != CPLAYER)
		i++;
	flood(data->map.dup, i, data->map.width);
	while (data->map.dup[i] != '\0')
	{
		if (data->map.dup[i] == CPLAYER || data->map.dup[i] == CEXIT \
		|| data->map.dup[i] == CITEM)
		{
			ft_printf("\nError in configuration : map is not resolvable\n\n");
			free(data->map.dup);
			return (1);
		}
		i++;
	}
	return (0);
}
