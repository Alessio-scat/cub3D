/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:15:35 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/15 15:20:29 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	check_character(char **map, t_cub *cub);
int	check_first_and_last_wall(char *map, t_cub *cub);
int	check_wall_extremity(char **map, t_cub *cub);
int	check_map_err(char **map, t_cub *cub);

int	check_map(char **map, t_cub *cub)
{
	if (check_character(map, cub) == 1)
		return (1);
	if (check_first_and_last_wall(map[0], cub) == 1)
		return (1);
	if (check_wall_extremity(map, cub) == 1)
		return (1);
	if (check_map_err(map, cub) == 1)
		return (1);
	return (0);
}
