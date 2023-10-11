/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:57:19 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 10:08:29 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	skipp_space(char *line, int *i);
void	ft_error_map(char *gnl, int fd);
int		parse_element(char **element, t_cub *cub, char *line, int i);
int		recup_element_we_ea(char *l, t_cub *cub);

char	*path(char *line, size_t i)
{
	unsigned int	l;
	int				start;
	char			*path;

	l = 0;
	start = i;
	path = NULL;
	if (line[start] == ' ')
		skipp_space(line, &start);
	i = start;
	while (line[i] && line[i + 1] != '\n' && line[i + 1] != '\0')
	{
		i++;
		l++;
	}
	path = ft_substr(line, start, l + 1);
	if (!path)
		return (NULL);
	return (path);
}

int	condition_texture(int index, char *line, int i)
{
	if (index == 1)
		if (line[i] != 'N' && line[i + 1] != 'O' && line[i + 2] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	if (index == 2)
		if (line[i] != 'S' && line[i + 1] != 'O' && line[i + 2] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	if (index == 3)
		if (line[i] != 'W' && line[i + 1] != 'E' && line[i + 2] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	if (index == 4)
		if (line[i] != 'E' && line[i + 1] != 'A' && line[i + 2] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	if (index == 5)
		if (line[i] != 'F' && line[i + 1] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	if (index == 6)
		if (line[i] != 'C' && line[i + 1] != ' ')
			return (printf("Error\nInvalid arguments\n"), 1);
	return (0);
}

int	check_line(char *line, int i)
{
	static int	index = 1;

	if (line[i] == '\n')
		return (0);
	if (line[i] == ' ' || line[i] == '\t')
	{
		skipp_space(line, &i);
		if (line[i] == '\n')
			return (0);
		if (condition_texture(index, line, i) == 1)
			return (1);
	}
	if (condition_texture(index, line, i) == 1)
		return (1);
	index++;
	return (0);
}

int	recup_element(char *l, t_cub *cub)
{
	if (l[cub->i] == 'N' && l[cub->i + 1] == 'O' \
	&& l[cub->i + 2] == ' ' && cub->t.i_no == 0)
	{
		if (parse_element(&cub->t.no, cub, l, cub->i + 3) == 1)
			return (1);
		cub->t.i_no++;
	}
	if (l[cub->i] == 'S' && l[cub->i + 1] == 'O' \
	&& l[cub->i + 2] == ' ' && cub->t.i_so == 0)
	{
		if (parse_element(&cub->t.so, cub, l, cub->i + 3) == 1)
			return (1);
		cub->t.i_so++;
	}
	if (recup_element_we_ea(l, cub) == 1)
		return (1);
	return (0);
}

int	recup_flag(char *l, t_cub *cub, int fd)
{
	if (check_line(l, 0) == 1)
	{
		ft_error_map(l, fd);
		return (ft_free_all(cub), 1);
	}
	cub->i = 0;
	if (l[cub->i] == ' ' || l[cub->i] == '\t')
		skipp_space(l, &cub->i);
	if (recup_element(l, cub) == 1)
		return (1);
	if (l[cub->i] == 'F' && l[cub->i + 1] == ' ' )
	{
		if (cub->t.i_f > 0)
			free(cub->t.f);
		if (parse_element(&cub->t.f, cub, l, cub->i + 2) == 1)
			return (1);
		cub->t.i_f++;
	}
	if (l[cub->i] == 'C' && l[cub->i + 1] == ' ' && cub->t.i_c == 0)
	{
		if (parse_element(&cub->t.c, cub, l, cub->i + 2) == 1)
			return (1);
		cub->t.i_c++;
	}
	return (0);
}
