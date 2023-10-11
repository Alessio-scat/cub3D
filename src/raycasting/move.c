/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:08:09 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/27 11:00:36 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_free_esc(t_ray *ray);

int	move(int keycode, t_ray *ray)
{
	if (keycode == FORWARD_W_Z)
		ray->data.forward = 1;
	else if (keycode == BACK_S_S)
		ray->data.back = 1;
	else if (keycode == RIGHT_D_D)
		ray->data.right = 1;
	else if (keycode == LEFT_A_Q)
		ray->data.left = 1;
	else if (keycode == ROTATE_RIGHT)
		ray->data.rotate_right = 1;
	else if (keycode == ROTATE_LEFT)
		ray->data.rotate_left = 1;
	else if (keycode == 65307)
		ft_free_esc(ray);
	else if (keycode == 32)
		ray->data.gun = 1;
	return (0);
}

void	move_w_s(t_ray *ray)
{
	if (ray->data.forward == 1)
	{
		if (ray->cub->map[(int)(ray->posx + (ray->dirx * ray->movespeed * 6))] \
		[(int)(ray->posy)] != '1')
			ray->posx += ray->dirx * ray->movespeed;
		if (ray->cub->map[(int)(ray->posx)] \
		[(int)(ray->posy + (ray->diry * ray->movespeed * 6))] != '1')
			ray->posy += ray->diry * ray->movespeed;
	}
	if (ray->data.back == 1)
	{
		if (ray->cub->map[(int)(ray->posx - (ray->dirx * ray->movespeed * 6))] \
		[(int)(ray->posy)] != '1')
			ray->posx -= ray->dirx * ray->movespeed;
		if (ray->cub->map[(int)(ray->posx)] \
		[(int)(ray->posy - (ray->diry * ray->movespeed * 6))] != '1')
			ray->posy -= ray->diry * ray->movespeed;
	}
}

void	move_a_d(t_ray *ray)
{
	if (ray->data.right == 1)
	{
		if (ray->cub->map[(int)(ray->posx + (ray->diry * ray->movespeed * 6))] \
		[(int)(ray->posy)] != '1')
			ray->posx += ray->diry * ray->movespeed;
		if (ray->cub->map[(int)(ray->posx)] \
		[(int)(ray->posy - (ray->dirx * ray->movespeed * 6))] != '1')
			ray->posy -= ray->dirx * ray->movespeed;
	}
	if (ray->data.left == 1)
	{
		if (ray->cub->map[(int)(ray->posx - (ray->diry * ray->movespeed * 6))] \
		[(int)(ray->posy)] != '1')
			ray->posx -= ray->diry * ray->movespeed;
		if (ray->cub->map[(int)(ray->posx)] \
		[(int)(ray->posy + (ray->dirx * ray->movespeed * 6))] != '1')
			ray->posy += ray->dirx * ray->movespeed;
	}
}

void	move_rotation(t_ray *ray, double olddirx, double oldplanx, int i)
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
	if (i == 1)
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

void	rotate_right_left(t_ray *ray)
{
	double	olddirx;
	double	oldplanx;

	if (ray->data.rotate_right == 1)
	{
		olddirx = ray->dirx;
		oldplanx = ray->planx;
		move_rotation(ray, olddirx, oldplanx, 0);
	}
	if (ray->data.rotate_left == 1)
	{
		olddirx = ray->dirx;
		oldplanx = ray->planx;
		move_rotation(ray, olddirx, oldplanx, 1);
	}
}
