/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:16:48 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/21 11:41:34 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	draw_mini_map(int i, int j, int color, t_data *data)
{
	int	x;
	int	y;
	int	posx;
	int	posy;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			posy = y + (j * 10);
			posx = x + (i * 10);
			data->addr[posx * 1920 + posy] = color;
			y++;
		}
		x++;
	}
}

void	draw_player(double i, double j, int color, t_data *data)
{
	int	x;
	int	y;
	int	posx;
	int	posy;

	x = 0;
	while (x < 7)
	{
		y = 0;
		while (y < 7)
		{
			posy = y + (j * 10 - 3);
			posx = x + (i * 10 - 3);
			data->addr[posx * 1920 + posy] = color;
			y++;
		}
		x++;
	}
}

void	minimap(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (ray->cub->map[i])
	{
		j = 0;
		while (ray->cub->map[i][j])
		{
			if (ray->cub->map[i][j] == '1')
				draw_mini_map(i + 1, j + 1, 0x808080, &ray->data);
			else if (ray->cub->map[i][j] != '1' && ray->cub->map[i][j] != ' ')
				draw_mini_map(i + 1, j + 1, 0xFFFFFF, &ray->data);
			j++;
		}
		i++;
	}
	draw_player(ray->posx + 1, ray->posy + 1, 0x00FF0000, &ray->data);
}
