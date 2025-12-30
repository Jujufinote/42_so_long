/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:52:16 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:33 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *map_str, char *buffer)
{
	char	*map_str_v2;
	int		total_length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_length = ft_len(map_str) + ft_len(buffer) + 1;
	map_str_v2 = malloc(sizeof(char) * total_length);
	if (map_str_v2 == NULL)
	{
		ft_printf("\nError in memory allocation\n\n");
		exit(EXIT_FAILURE);
	}
	while (map_str != NULL && map_str[i])
		map_str_v2[j++] = map_str[i++];
	free(map_str);
	i = 0;
	while (buffer[i])
		map_str_v2[j++] = buffer[i++];
	map_str_v2[j] = '\0';
	return (map_str_v2);
}

char	*reading(int fd)
{
	int		result;
	char	*buffer;
	char	*map_str;

	map_str = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		ft_printf("\nError in memory allocation\n\n");
		exit(EXIT_FAILURE);
	}
	result = 1;
	while (result > 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			ft_printf("\nReading error\n\n");
			exit(EXIT_FAILURE);
		}
		buffer[result] = '\0';
		map_str = ft_join(map_str, buffer);
	}
	free(buffer);
	return (map_str);
}

char	*map_reading(char *map)
{
	char	*map_str;
	int		fd;

	if (ft_strnstr(map, ".", ft_strlen(map)) != NULL \
	&& ft_strnstr(map, ".ber", ft_strlen(map)) == NULL)
	{
		ft_printf("\nNot the right extension\n\n");
		exit(EXIT_FAILURE);
	}
	fd = open(map, O_RDWR);
	if (fd == -1)
	{
		ft_printf("\nMap does not exist\n\n");
		exit(EXIT_FAILURE);
	}
	map_str = reading(fd);
	if (map_str == NULL)
	{
		ft_printf("\nError in the reading or memory allocation of the map\n\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (map_str);
}
