/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:17:00 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 10:10:11 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	count_tab_color(char **color);

int	check_charac(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ',')
			count++;
		if ((s[i] < '0' || s[i] > '9') && s[i] != ',' \
		&& s[i] != ' ' && s[i] != '\t')
			return (printf("Error\nColor elements only accept numbers\n"), 1);
		i++;
	}
	if (count != 2)
		return (printf("Error\n"), 1);
	return (0);
}

void	remove_space(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}

int	convert_color_rgb(char **s, t_cub *cub, int index)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (s[i])
	{
		rgb[i] = ft_atoi(s[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (printf("Error\nInvalid RGB\n"), 1);
		i++;
	}
	if (index == 1)
		cub->t.rgb_f = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	else if (index == 2)
		cub->t.rgb_c = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (0);
}

int	verif_argument_color(t_cub *cub, char *color, int index)
{
	char	**s;
	int		nb_color;

	s = NULL;
	if (check_charac(color) == 1)
		return (ft_free_all(cub), 1);
	remove_space(color);
	s = ft_split(color, ',');
	if (!s)
		return (ft_free_all(cub), printf("Error malloc\n"), 1);
	nb_color = count_tab_color(s);
	if (nb_color != 3)
		return (free_2d(s), ft_free_all(cub), \
		printf("Error\nThe number of color arguments is invalid\n"), 1);
	if (convert_color_rgb(s, cub, index) == 1)
		return (free_2d(s), ft_free_all(cub), 1);
	free_2d(s);
	return (0);
}

int	check_color(t_cub *cub)
{
	if (verif_argument_color(cub, cub->t.f, 1) == 1)
		return (1);
	if (verif_argument_color(cub, cub->t.c, 2) == 1)
		return (1);
	return (0);
}
