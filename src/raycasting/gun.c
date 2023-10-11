/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:53:28 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/22 14:01:31 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	gun(t_ray *ray)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ray->data.gun == 1)
	{
		while (i++ < 600)
		{
			j = 0;
			while (j++ < 482)
			{
				if (ray->gun[1].addr[j * ray->gun[1].line_length / 4 + i] != 0)
					ray->data.addr[(j + 600) * ray->data.line_length / 4 \
					+ (i + 600)] \
					= ray->gun[1].addr[j * ray->gun[1].line_length / 4 + i];
			}
		}
	}
}

void	print_gun(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	if (ray->data.gun == 0)
	{
		while (i++ < 600)
		{
			j = 0;
			while (j++ < 592)
			{
				if (ray->gun[0].addr[j * ray->gun[0].line_length / 4 + i] != 0)
					ray->data.addr[(j + 500) * \
					ray->data.line_length / 4 + (i + 630)] = \
					ray->gun[0].addr[j * ray->gun[0].line_length / 4 + i];
			}
		}
	}
}
