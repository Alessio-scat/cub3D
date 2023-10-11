/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:35:15 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/27 11:46:01 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	protect_img(t_ray *ray, int i);

int	get_texture_addr(t_ray *ray)
{
	ray->texture[0].addr = (int *)mlx_get_data_addr \
	(ray->texture[0].img, &ray->texture[0].bits_per_pixel, \
	&ray->texture[0].line_length, &ray->texture[0].endian);
	ray->texture[1].addr = (int *)mlx_get_data_addr \
	(ray->texture[1].img, &ray->texture[1].bits_per_pixel, \
	&ray->texture[1].line_length, &ray->texture[1].endian);
	ray->texture[2].addr = (int *)mlx_get_data_addr \
	(ray->texture[2].img, &ray->texture[2].bits_per_pixel, \
	&ray->texture[2].line_length, &ray->texture[2].endian);
	ray->texture[3].addr = (int *)mlx_get_data_addr \
	(ray->texture[3].img, &ray->texture[3].bits_per_pixel, \
	&ray->texture[3].line_length, &ray->texture[3].endian);
	return (0);
}

void	get_texture_gun(t_ray *ray)
{
	int	width;
	int	height;

	ray->gun[0].img = mlx_xpm_file_to_image \
	(ray->data.mlx, "./texture/1.xpm", &width, &height);
	if (!ray->gun[0].img)
		protect_img(ray, 0);
	ray->gun[1].img = mlx_xpm_file_to_image \
	(ray->data.mlx, "./texture/2.xpm", &width, &height);
	if (!ray->gun[1].img)
		protect_img(ray, 1);
	ray->gun[0].addr = (int *)mlx_get_data_addr \
	(ray->gun[0].img, &ray->gun[0].bits_per_pixel, \
	&ray->gun[0].line_length, &ray->gun[0].endian);
	ray->gun[1].addr = (int *)mlx_get_data_addr \
	(ray->gun[1].img, &ray->gun[1].bits_per_pixel, \
	&ray->gun[1].line_length, &ray->gun[1].endian);
}

int	get_texture(t_ray *ray)
{
	get_texture_gun(ray);
	ray->texture[0].img = mlx_xpm_file_to_image(ray->data.mlx, ray->cub->t.no, \
	&ray->texture[0].width, &ray->texture[0].height);
	if (!ray->texture[0].img)
		protect_img(ray, 2);
	ray->texture[1].img = mlx_xpm_file_to_image(ray->data.mlx, ray->cub->t.so, \
	&ray->texture[1].width, &ray->texture[1].height);
	if (!ray->texture[1].img)
		protect_img(ray, 3);
	ray->texture[2].img = mlx_xpm_file_to_image(ray->data.mlx, ray->cub->t.we, \
	&ray->texture[2].width, &ray->texture[2].height);
	if (!ray->texture[2].img)
		protect_img(ray, 4);
	ray->texture[3].img = mlx_xpm_file_to_image(ray->data.mlx, ray->cub->t.ea, \
	&ray->texture[3].width, &ray->texture[3].height);
	if (!ray->texture[3].img)
		protect_img(ray, 5);
	get_texture_addr(ray);
	return (0);
}

void	what_texture(t_ray *ray, int x)
{
	int	j;
	int	i;

	j = -1;
	i = ray->drawend - 1;
	ray->text_num = 0;
	if (ray->side == 0 && ray->raydirx < 0)
		ray->text_num = 0;
	if (ray->side == 0 && ray->raydirx >= 0)
		ray->text_num = 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->text_num = 2;
	if (ray->side == 1 && ray->raydiry >= 0)
		ray->text_num = 3;
	while (++j < ray->drawstart)
		ray->data.addr[j * ray->data.line_length / 4 + x] = ray->cub->t.rgb_c;
	while (++i < 1080)
		ray->data.addr[i * ray->data.line_length / 4 + x] = ray->cub->t.rgb_f;
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = ray->posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)(ray->texture[0].width));
}

int	put_texture(t_ray *ray, int x)
{
	int	y;

	y = ray->drawstart - 1;
	what_texture(ray, x);
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = ray->texture[ray->text_num].width - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = ray->texture[ray->text_num].width - ray->texx - 1;
	ray->step = 1.0 * ray->texture[0].height / ray->lineheight;
	ray->texpos = (ray->drawstart - 1080 / 2 + ray->lineheight / 2) * ray->step;
	while (++y <= ray->drawend)
	{
		ray->texy = (int)ray->texpos & (ray->texture[ray->text_num].height - 1);
		ray->texpos += ray->step;
		if (y < 1080 && x < 1920)
		{
			ray->data.addr[y * ray->data.line_length / 4 + x] \
			= ray->texture[ray->text_num].addr[ray->texy * \
			ray->texture[ray->text_num].line_length / 4 + ray->texx];
		}
	}
	return (0);
}
