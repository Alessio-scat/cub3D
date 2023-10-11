/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:57:00 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 09:25:28 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	skip_space(char *line);
int	skip_space_inverse(char *line);
int	number_tab(char **map);
int	condition_map_err(char **map, int x, int y);
int	verif_line_map(char **map, int x, int y);

int	verif_map_empty(char *map)
{
	int	i;
	int	count;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			count = 0;
			while (map[i] && (map[i] == '\n' || map[i] == ' '))
			{
				if (map[i] == '\n')
					count++;
				i++;
			}
			if ((map[i] == '1' || map[i] == '0') && count >= 2)
				return (printf("Error\nInvalid map\n"), 1);
		}
		if (map[i])
			i++;
	}
	return (0);
}

int	check_first_and_last_wall(char *map, t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = number_tab(cub->map);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			return (ft_free_all(cub), \
			printf("Error\nThe map is not closedd\n"), 1);
		i++;
	}
	i = 0;
	while (cub->map[count][i])
	{
		if (cub->map[count][i] != '1' && cub->map[count][i] != ' ')
			return (ft_free_all(cub), \
			printf("Error\nThe map is not closed\n"), 1);
		i++;
	}
	return (0);
}

int	check_last_wall_extremity(char **map, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (map[++x])
	{
		if (map[x][ft_strlen(map[x]) - 1] != '1' && \
			map[x][ft_strlen(map[x]) - 1] != ' ')
			return (ft_free_all(cub), \
			printf("Error\nThe map is not closed\n"), 1);
		if (map[x][ft_strlen(map[x]) - 1] == ' ' || \
			map[x][ft_strlen(map[x]) - 1] == '\t')
		{
			y = skip_space_inverse(map[x]);
			if (map[x][y] != '1' && map[x][y] != ' ')
				return (ft_free_all(cub), \
				printf("Error\nThe map is not closed\n"), 1);
		}
	}
	return (0);
}

int	check_wall_extremity(char **map, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (map[++x])
	{
		if (map[x][0] == ' ' || map[x][0] == '\t')
		{
			y = skip_space(map[x]);
			if (map[x][y] != '1' && map[x][y] != ' ')
				return (ft_free_all(cub), \
				printf("Error\nThe map is not closed\n"), 1);
		}
		if (map[x][0] != '1' && map[x][0] != ' ')
			return (ft_free_all(cub), \
			printf("Error\nThe map is not closed\n"), 1);
	}
	if (check_last_wall_extremity(map, cub) == 1)
		return (1);
	return (0);
}

int	check_map_err(char **map, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' \
			|| map[x][y] == 'E' || map[x][y] == 'W')
			{
				if (condition_map_err(map, x, y) == 1)
					return (ft_free_all(cub), printf("Error\nInvalid map\n"), 1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
