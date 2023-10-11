/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:24:40 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 09:25:12 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	verif_line_map(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (map[x + 1][i])
	{
		if (i == y)
			break ;
		i++;
	}
	if (i != y)
		return (1);
	i = 0;
	while (map[x - 1][i])
	{
		if (i == y)
			break ;
		i++;
	}
	if (i != y)
		return (1);
	return (0);
}

int	condition_map_err(char **map, int x, int y)
{
	if (verif_line_map(map, x, y) == 1)
		return (1);
	else
	{
		if (map[x + 1][y] == ' ' || map[x + 1][y] == '\0')
			return (1);
		if (map[x - 1][y] == ' ' || map[x - 1][y] == '\0')
			return (1);
		if (map[x][y + 1] == ' ' || map[x][y + 1] == '\0')
			return (1);
		if (map[x][y - 1] == ' ' || map[x][y - 1] == '\0')
			return (1);
	}
	return (0);
}
