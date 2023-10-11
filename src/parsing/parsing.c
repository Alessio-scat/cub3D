/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:40:57 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/15 15:50:45 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int		extension(char *av[]);
void	init_var(t_cub *cub);
int		parsing_map(char *av[], t_cub *cub);
int		check_map(char **map, t_cub *cub);
int		check_color(t_cub *cub);

int	parsing(char *av[], t_cub *cub)
{
	if (extension(av) == 1)
		return (1);
	init_var(cub);
	if (parsing_map(av, cub) == 1)
		return (1);
	if (check_map(cub->map, cub) == 1)
		return (1);
	if (check_color(cub) == 1)
		return (1);
	return (0);
}
