/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:34:08 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/27 11:30:44 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_all(t_cub *cub)
{
	if (cub->map)
		free_2d(cub->map);
	if (cub->t.c)
		free(cub->t.c);
	if (cub->t.ea)
		free(cub->t.ea);
	if (cub->t.f)
		free(cub->t.f);
	if (cub->t.no)
		free(cub->t.no);
	if (cub->t.so)
		free(cub->t.so);
	if (cub->t.we)
		free(cub->t.we);
}

void	ft_free_esc(t_ray *ray)
{
	ft_free_all(ray->cub);
	mlx_destroy_image(ray->data.mlx, ray->data.img);
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
	mlx_clear_window(ray->data.mlx, ray->data.win);
	mlx_destroy_window(ray->data.mlx, ray->data.win);
	mlx_destroy_display(ray->data.mlx);
	free(ray->data.mlx);
	exit(EXIT_SUCCESS);
}
