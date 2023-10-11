/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:40:21 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/27 15:18:58 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	last_img(t_ray *ray, int i)
{
	if (i == 5)
	{
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
		mlx_destroy_image(ray->data.mlx, ray->gun[1].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[0].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[1].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[2].img);
	}
}

void	protect_img(t_ray *ray, int i)
{
	ft_free_all(ray->cub);
	if (i == 1)
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
	if (i == 2)
	{
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
		mlx_destroy_image(ray->data.mlx, ray->gun[1].img);
	}
	if (i == 3)
	{
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
		mlx_destroy_image(ray->data.mlx, ray->gun[1].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[0].img);
	}
	if (i == 4)
	{
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
		mlx_destroy_image(ray->data.mlx, ray->gun[1].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[0].img);
		mlx_destroy_image(ray->data.mlx, ray->texture[1].img);
	}
	last_img(ray, i);
	mlx_destroy_display(ray->data.mlx);
	free(ray->data.mlx);
	exit(EXIT_FAILURE);
}

void	free_mlx(t_ray *ray)
{
	ft_free_all(ray->cub);
	exit(EXIT_FAILURE);
}

void	free_mlx_win(t_ray *ray)
{
	ft_free_all(ray->cub);
	if (ray->texture[0].img)
		mlx_destroy_image(ray->data.mlx, ray->texture[0].img);
	if (ray->texture[1].img)
		mlx_destroy_image(ray->data.mlx, ray->texture[1].img);
	if (ray->texture[2].img)
		mlx_destroy_image(ray->data.mlx, ray->texture[2].img);
	if (ray->texture[3].img)
		mlx_destroy_image(ray->data.mlx, ray->texture[3].img);
	if (ray->gun[0].img)
		mlx_destroy_image(ray->data.mlx, ray->gun[0].img);
	if (ray->gun[1].img)
		mlx_destroy_image(ray->data.mlx, ray->gun[1].img);
	mlx_destroy_display(ray->data.mlx);
	free(ray->data.mlx);
	exit(EXIT_FAILURE);
}
