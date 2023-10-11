/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:26:38 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 10:08:16 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

char	*path(char *line, size_t i);

void	ft_error_map(char *gnl, int fd)
{
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
}

int	verif_element(t_cub *cub)
{
	if (cub->t.i_c != 1 || cub->t.i_ea != 1 || cub->t.i_f != 1 \
	|| cub->t.i_no != 1 || cub->t.i_so != 1 || cub->t.i_we != 1)
		return (printf("Error\nInvalid element\n"), 1);
	return (0);
}

int	parse_element(char **element, t_cub *cub, char *line, int i)
{
	*element = path(line, i);
	if (!*element)
		return (printf("Error Malloc\n"), 1);
	cub->count++;
	return (0);
}

int	recup_element_we_ea(char *l, t_cub *cub)
{
	if (l[cub->i] == 'W' && l[cub->i + 1] == 'E' \
	&& l[cub->i + 2] == ' ' && cub->t.i_we == 0)
	{
		if (parse_element(&cub->t.we, cub, l, cub->i + 3) == 1)
			return (1);
		cub->t.i_we++;
	}
	if (l[cub->i] == 'E' && l[cub->i + 1] == 'A' \
	&& l[cub->i + 2] == ' ' && cub->t.i_ea == 0)
	{
		if (parse_element(&cub->t.ea, cub, l, cub->i + 3) == 1)
			return (1);
		cub->t.i_ea++;
	}
	return (0);
}
