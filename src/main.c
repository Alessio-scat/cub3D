/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:48:30 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 09:26:51 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	position_player(char **map, t_ray *ray)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'W' \
			|| map[x][y] == 'E' || map[x][y] == 'S')
			{
				ray->posx = x + 0.5;
				ray->posy = y + 0.5;
				ray->player = map[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}

int	main(int ac, char *av[])
{
	t_cub	cub;
	t_ray	ray;

	(void)ac;
	if (ac != 2)
		return (printf("Error\nInvalid Arguments\n"), 0);
	if (parsing(av, &cub) == 1)
		return (0);
	position_player(cub.map, &ray);
	ray.cub = &cub;
	create_window(&ray);
	ft_free_all(&cub);
}
