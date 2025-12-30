/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdier <jverdier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:23:48 by jverdier          #+#    #+#             */
/*   Updated: 2024/07/06 14:01:11 by jverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ifs2(t_mlx_data *data, int x, int i, char *nb)
{
	if (nb[i] == NUM6)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n6, x, 0);
	else if (nb[i] == NUM7)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n7, x, 0);
	else if (nb[i] == NUM8)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n8, x, 0);
	else if (nb[i] == NUM9)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n9, x, 0);
	return ;
}

void	ifs(t_mlx_data *data, int x, int i, char *nb)
{
	if (nb[i] == NUM0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n0, x, 0);
	else if (nb[i] == NUM1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n1, x, 0);
	else if (nb[i] == NUM2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n2, x, 0);
	else if (nb[i] == NUM3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n3, x, 0);
	else if (nb[i] == NUM4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n4, x, 0);
	else if (nb[i] == NUM5)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->nums.n5, x, 0);
	return ;
}

int	count(t_mlx_data *data)
{
	int		x;
	int		i;
	char	*nb;

	x = 0;
	i = 0;
	nb = ft_itoa(data->total_mov);
	if (nb == NULL)
	{
		ft_printf("\nError in memory allocation for numbers\n\n");
		ft_close(data);
		exit(EXIT_FAILURE);
	}
	while (nb[i] != '\0')
	{
		ifs(data, x, i, nb);
		ifs2(data, x, i, nb);
		i++;
		x += 48;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->nums.mov, x, 0);
	free(nb);
	return (0);
}
