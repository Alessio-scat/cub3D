/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:25:05 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/22 11:23:38 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	init_var(t_cub *cub)
{
	cub->t.c = NULL;
	cub->t.ea = NULL;
	cub->t.f = NULL;
	cub->t.no = NULL;
	cub->t.so = NULL;
	cub->t.we = NULL;
	cub->count = 0;
	cub->lmap = ft_strdup("");
	if (!cub->lmap)
		exit(EXIT_FAILURE);
	cub->t.i_c = 0;
	cub->t.i_ea = 0;
	cub->t.i_f = 0;
	cub->t.i_no = 0;
	cub->t.i_so = 0;
	cub->t.i_we = 0;
	cub->i = 0;
	cub->map = NULL;
}

void	init_map(t_cub *cub)
{
	cub->l = NULL;
	cub->gnl = NULL;
	cub->tmp = NULL;
}
