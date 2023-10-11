/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:18:47 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/27 09:25:29 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	count_tab_color(char **color)
{
	int	i;

	i = 0;
	while (color[i])
		i++;
	return (i);
}

void	skipp_space(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
	{
		(*i)++;
	}
}

int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
	{
		i++;
	}
	return (i);
}

int	skip_space_inverse(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
	{
		i--;
	}
	return (i);
}

int	number_tab(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count - 1);
}
