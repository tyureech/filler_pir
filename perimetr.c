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

//void		make_clean(t_filler *fil)
//{
//	int		i;
//
//	i = 0;
//	while (fil->y_map - ++i >= 0)
//		free(fil->map[fil->y_map - i]);
////	free(fil->map);
//	i = 0;
//	while (fil->y_int_map - ++i >= 0)
//		free(fil->int_map[fil->y_map - i]);
////	free(fil->int_map);
//	i = 0;
//	while (fil->y_figura - ++i >= 0)
//		free(fil->figura[fil->y_figura - i]);
////	free(fil->figura);
//	i = 0;
//	while (fil->y_int_figura - ++i >= 0)
//		free(fil->int_figura[fil->y_figura - i]);
////	free(fil->int_figura);
//}

void		make_clean(t_filler *fil)
{
	int		i;

	i = 1;
	while (fil->y_map - i >= 0)
	{
		free(fil->map[fil->y_map - i]);
		free(fil->int_map[fil->y_map - i]);
		i++;
	}
	i = 1;
	while (fil->y_figura - i >= 0)
	{
		free(fil->figura[fil->y_figura - i]);
		free(fil->int_figura[fil->y_figura - i]);
		i++;
	}
}

int			player(t_filler *fil)
{
	char	*line;

	get_next_line(0, &line);
	fil->player = line[10] - 48;
	ft_strdel(&line);
	return (0);
}
