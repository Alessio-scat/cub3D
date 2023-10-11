/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:02:16 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/22 14:07:19 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	rotation_mouse(t_ray *ray, double olddirx, double oldplanx, int i)
{
	if (i == 0)
	{
		ray->dirx = ray->dirx * cos(-ray->rotspeed) - \
		ray->diry * sin(-ray->rotspeed);
		ray->diry = olddirx * sin(-ray->rotspeed) + \
		ray->diry * cos(-ray->rotspeed);
		ray->planx = ray->planx * cos(-ray->rotspeed) - \
		ray->plany * sin(-ray->rotspeed);
		ray->plany = oldplanx * sin(-ray->rotspeed) + \
		ray->plany * cos(-ray->rotspeed);
	}
	else if (i == 1)
	{
		ray->dirx = ray->dirx * cos(ray->rotspeed) - \
		ray->diry * sin(ray->rotspeed);
		ray->diry = olddirx * sin(ray->rotspeed) + \
		ray->diry * cos(ray->rotspeed);
		ray->planx = ray->planx * cos(ray->rotspeed) - \
		ray->plany * sin(ray->rotspeed);
		ray->plany = oldplanx * sin(ray->rotspeed) + \
		ray->plany * cos(ray->rotspeed);
	}
}

int	mouse_move(int x, int y, t_ray *ray)
{
	double		olddirx;
	double		oldplanx;
	static int	i = 0;

	ray->rotspeed = 0.03;
	(void)y;
	if ((x > 960 && i == 0) || (i < x && i != 0))
	{
		olddirx = ray->dirx;
		oldplanx = ray->planx;
		rotation_mouse(ray, olddirx, oldplanx, 0);
	}
	if ((x < 960 && i == 0) || (i > x && i != 0))
	{
		olddirx = ray->dirx;
		oldplanx = ray->planx;
		rotation_mouse(ray, olddirx, oldplanx, 1);
	}
	if (x > 1500 || x < 400 || y > 850 || y < 250)
		mlx_mouse_move(ray->data.mlx, ray->data.win, 1920 / 2, 1080 / 2);
	i = x;
	return (0);
}
