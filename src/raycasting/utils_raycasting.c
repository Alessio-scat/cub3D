/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:56:52 by lveloso           #+#    #+#             */
/*   Updated: 2023/06/27 11:39:36 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	free_img_refresh(t_ray *ray)
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
	mlx_clear_window(ray->data.mlx, ray->data.win);
	mlx_destroy_window(ray->data.mlx, ray->data.win);
	mlx_destroy_display(ray->data.mlx);
	free(ray->data.mlx);
	exit(EXIT_SUCCESS);
}

int	close_win(t_ray *ray)
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

int	refresh(t_ray *ray)
{
	mlx_destroy_image(ray->data.mlx, ray->data.img);
	ray->data.img = mlx_new_image(ray->data.mlx, 1920, 1080);
	if (!ray->data.img)
		free_img_refresh(ray);
	ray->data.addr = (int *)mlx_get_data_addr \
	(ray->data.img, \
	&ray->data.bits_per_pixel, &ray->data.line_length, &ray->data.endian);
	ft_raycasting(ray);
	return (0);
}

void	move_print(t_ray *ray)
{
	print_gun(ray);
	mlx_put_image_to_window(ray->data.mlx, ray->data.win, ray->data.img, 0, 0);
	minimap(ray);
	move_w_s(ray);
	move_a_d(ray);
	rotate_right_left(ray);
	gun(ray);
}

int	reset_move(int keycode, t_ray *ray)
{
	if (keycode == FORWARD_W_Z)
		ray->data.forward = 0;
	else if (keycode == BACK_S_S)
		ray->data.back = 0;
	else if (keycode == RIGHT_D_D)
		ray->data.right = 0;
	else if (keycode == LEFT_A_Q)
		ray->data.left = 0;
	else if (keycode == ROTATE_RIGHT)
		ray->data.rotate_right = 0;
	else if (keycode == ROTATE_LEFT)
		ray->data.rotate_left = 0;
	else if (keycode == 32)
		ray->data.gun = 0;
	return (0);
}
