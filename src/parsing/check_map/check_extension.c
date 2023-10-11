/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:21:29 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/15 15:50:41 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	extension(char *av[])
{
	int	len;

	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'c'
		|| av[1][len - 2] != 'u' || av[1][len - 1] != 'b')
		return (printf("Error\nThe file must end with .cub\n"), 1);
	return (0);
}
