/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:44:58 by mmahasim          #+#    #+#             */
/*   Updated: 2020/05/22 11:22:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		place_one(t_filler *fil, int h, int w)
{
	if (h > 0)
		if (fil->int_map[h - 1][w] == 0)
			fil->int_map[h - 1][w] = 1;
	if (w > 0)
		if (fil->int_map[h][w - 1] == 0)
			fil->int_map[h][w - 1] = 1;
	if (h + 1 < fil->y_map)
		if (fil->int_map[h + 1][w] == 0)
			fil->int_map[h + 1][w] = 1;
	if (w + 1 < fil->x_map)
		if (fil->int_map[h][w + 1] == 0)
			fil->int_map[h][w + 1] = 1;
}

void		perimetr(t_filler *fil)
{
	int		h;
	int		w;

	h = 0;
	while (h < fil->y_map)
	{
		w = 0;
		while (w < fil->x_map)
		{
			if (fil->int_map[h][w] == fil->int_opponent)
				place_one(fil, h, w);
			w++;
		}
		h++;
	}
}

int			sokr_str_int_clear(t_filler *fil, int len)
{
	if (fil->er_flag > 3)
		fil->y_int_figura = len;
	else if (fil->er_flag > 2)
		fil->y_int_map = len;
	make_clean(fil);
	return (0);
}

int			make_clean(t_filler *fil)
{
	clear_error((void **)fil->map, fil->y_map);
	if (fil->er_flag > 1)
		clear_error((void **)fil->figura, fil->y_figura);
	if (fil->er_flag > 2)
		clear_error((void **)fil->int_map, fil->y_int_map);
	if (fil->er_flag > 3)
		clear_error((void **)fil->int_figura, fil->y_int_figura);
	return (0);
}

int			clear_error(void **g, int x)
{
	int		i;

	i = 0;
	while (x - ++i >= 0)
		free(g[x - i]);
	free(g);
	return (0);
}
