/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:31:33 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/27 11:45:34 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	free_mlx_win(t_ray *ray);
void	free_mlx(t_ray *ray);

void	draw(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = fabs((ray->mapx - \
		ray->posx + (1 - ray->stepx) / 2) / ray->raydirx);
	else
		ray->perpwalldist = fabs((ray->mapy - \
		ray->posy + (1 - ray->stepy) / 2) / ray->raydiry);
	ray->lineheight = (int)(1080 / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + 1080 / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + 1080 / 2;
	if (ray->drawend >= 1080 || ray->drawend < 0)
		ray->drawend = 1080;
}

void	hit_wall(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->cub->map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
	draw(ray);
}

void	side_dist(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else if (ray->raydirx > 0)
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.00 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else if (ray->raydiry > 0)
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.00 - ray->posy) * ray->deltadisty;
	}
	hit_wall(ray);
}

int	ft_raycasting(t_ray *ray)
{
	int	w;

	ray->x = 0;
	w = 1920;
	while (ray->x < w)
	{
		ray->camerax = 2 * ray->x / (double)w - 1;
		ray->raydirx = ray->dirx + ray->planx * ray->camerax;
		ray->raydiry = ray->diry + ray->plany * ray->camerax;
		ray->mapx = (int)ray->posx;
		ray->mapy = (int)ray->posy;
		ray->movespeed = 0.06;
		ray->rotspeed = 0.06;
		ray->deltadistx = sqrt(1 + \
		(ray->raydiry * ray->raydiry) / (ray->raydirx * ray->raydirx));
		ray->deltadisty = sqrt(1 + \
		(ray->raydirx * ray->raydirx) / (ray->raydiry * ray->raydiry));
		ray->hit = 0;
		ray->perpwalldist = 0;
		side_dist(ray);
		put_texture(ray, ray->x);
		ray->x++;
	}
	move_print(ray);
	return (0);
}

int	create_window(t_ray *ray)
{
	init_direction_player(ray);
	raycasting_init(ray);
	ray->data.mlx = mlx_init();
	if (!ray->data.mlx)
		free_mlx(ray);
	get_texture(ray);
	ray->data.win = mlx_new_window(ray->data.mlx, 1920, 1080, "CUB3D");
	if (!ray->data.win)
		free_mlx_win(ray);
	mlx_mouse_hide(ray->data.mlx, ray->data.win);
	ray->data.img = mlx_new_image(ray->data.mlx, 1920, 1080);
	if (!ray->data.img)
		ft_free_esc(ray);
	mlx_mouse_move(ray->data.mlx, ray->data.win, 1920 / 2, 1080 / 2);
	ray->data.addr = (int *)mlx_get_data_addr(ray->data.img, \
	&ray->data.bits_per_pixel, &ray->data.line_length, &ray->data.endian);
	mlx_hook(ray->data.win, 6, 1L << 6, mouse_move, ray);
	mlx_hook(ray->data.win, 2, 1L << 0, move, ray);
	mlx_loop_hook(ray->data.mlx, refresh, ray);
	mlx_hook(ray->data.win, 3, 1L << 1, reset_move, ray);
	mlx_hook(ray->data.win, 17, 1L << 17, close_win, ray);
	mlx_loop(ray->data.mlx);
	return (0);
}
