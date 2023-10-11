/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:53:54 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/27 14:48:11 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int		recup_flag(char *line, t_cub *cub, int fd);
int		verif_map_empty(char *map);
void	ft_error_map(char *gnl, int fd);
void	init_map(t_cub *cub);
void	ft_error_map(char *gnl, int fd);
int		verif_element(t_cub *cub);

int	verif_map(t_cub *cub, char *l, int fd)
{
	if (cub->count != 6)
		return (ft_free_all(cub), \
		printf("Error\nInvalid element\n"), 1);
	if (verif_map_empty(cub->lmap) == 1)
		return (ft_free_all(cub), 1);
	free(l);
	close(fd);
	return (0);
}

int	loop_gnl(t_cub *cub, char **gnl, int fd)
{
	while (*gnl)
	{
		cub->lmap = ft_strjoin(cub->lmap, *gnl);
		if (!cub->lmap)
			return (ft_free_all(cub), ft_error_map(*gnl, fd), 1);
		free(*gnl);
		*gnl = get_next_line(fd);
	}
	return (0);
}

char	*ft_gnl(char *gnl, char *l, int fd, t_cub *cub)
{
	while (gnl)
	{
		if (recup_flag(gnl, cub, fd) == 1)
			return (NULL);
		free(gnl);
		gnl = get_next_line(fd);
		if (cub->count == 6)
		{
			if (verif_element(cub) == 1)
				return (ft_error_map(gnl, fd), ft_free_all(cub), NULL);
			if (gnl)
			{
				if (gnl[0] != '\n')
				{
					while (gnl)
						if (loop_gnl(cub, &gnl, fd) == 1)
							return (NULL);
				}
			}
		}
	}
	if (verif_map(cub, l, fd) == 1)
		return (NULL);
	return (cub->lmap);
}

int	parsing_map(char *av[], t_cub *cub)
{
	int		fd;

	init_map(cub);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
		return (free(cub->lmap), printf("Error fd\n"), 1);
	cub->l = get_next_line(fd);
	if (!cub->l)
		return (free(cub->lmap), close(fd), printf("Error map\n"), 1);
	cub->gnl = get_next_line(fd);
	if (!cub->gnl)
		return (ft_error_map(cub->l, fd), free(cub->lmap), close(fd), \
		printf("Error\n"), 1);
	if (recup_flag(cub->l, cub, fd) == 1)
		return (free(cub->lmap), free(cub->gnl), close(fd), 1);
	cub->tmp = ft_gnl(cub->gnl, cub->l, fd, cub);
	if (!cub->tmp)
		return (free(cub->l), free(cub->lmap), close(fd), 1);
	cub->map = ft_split(cub->tmp, '\n');
	if (!cub->map)
		return (ft_free_all(cub), free(cub->tmp), printf("Error malloc\n"), 1);
	free(cub->tmp);
	return (0);
}
