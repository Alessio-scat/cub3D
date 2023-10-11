/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lveloso <lveloso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:39:17 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/27 10:17:56 by lveloso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	raycasting_init(t_ray *ray)
{
	ray->x = 0;
	ray->data.rotate_left = 0;
	ray->data.rotate_right = 0;
	ray->data.left = 0;
	ray->data.right = 0;
	ray->data.back = 0;
	ray->data.gun = 0;
	ray->data.forward = 0;
	ray->data.mlx = NULL;
	ray->data.win = NULL;
	ray->data.img = NULL;
}

void	init_direction_player_e_w(t_ray *ray)
{
	if (ray->player == 'W')
	{
		ray->dirx = 0;
		ray->diry = -1;
		ray->planx = -0.66;
		ray->plany = 0;
	}
	else if (ray->player == 'E')
	{
		ray->dirx = 0;
		ray->diry = 1;
		ray->planx = 0.66;
		ray->plany = 0;
	}
}

void	init_direction_player(t_ray *ray)
{
	if (ray->player == 'N')
	{
		ray->dirx = -1;
		ray->diry = 0;
		ray->planx = 0;
		ray->plany = 0.66;
	}
	else if (ray->player == 'S')
	{
		ray->dirx = 1;
		ray->diry = 0;
		ray->planx = 0;
		ray->plany = -0.66;
	}
	else if (ray->player == 'W' || ray->player == 'E')
		init_direction_player_e_w(ray);
}
