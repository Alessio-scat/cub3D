/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:12:22 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/19 14:06:00 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	check_nb_character(t_cub *cub, int count)
{
	if (count == 0)
		return (ft_free_all(cub), \
		printf("Error\nThe player description is missing\n"), 1);
	if (count > 1)
		return (ft_free_all(cub), \
		printf("Error\nA description of the player is required\n"), 1);
	return (0);
}

int	check_character(char **map, t_cub *cub)
{
	int	x;
	int	y;
	int	count;

	x = -1;
	count = 0;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'N' \
			&& map[x][y] != 'S' && map[x][y] != 'E' && map[x][y] != 'W' && \
			map[x][y] != ' ' && map[x][y] != '\t')
				return (ft_free_all(cub), \
				printf("The map must contain only 1, 0, N, S, W, E\n"), 1);
			if (map[x][y] == 'N' || map[x][y] == 'S' \
			|| map[x][y] == 'E' || map[x][y] == 'W')
				count++;
		}
	}
	if (check_nb_character(cub, count) == 1)
		return (1);
	return (0);
}
