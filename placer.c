/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:29:18 by mmahasim          #+#    #+#             */
/*   Updated: 2020/05/22 11:23:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			step_conditions(t_filler *fil, int h, int w)
{
	if (fil->int_figura[fil->h1][fil->w1] == 0)
		fil->w1 = fil->w1 + 0;
	else if (fil->int_figura[fil->h1][fil->w1] == fil->int_my_char &&
			fil->int_map[h + fil->h1][w + fil->w1] == fil->int_opponent)
		return (0);
	else if (fil->int_figura[fil->h1][fil->w1] == fil->int_my_char &&
			fil->int_map[h + fil->h1][w + fil->w1] == fil->int_my_char)
		fil->count++;
	else if (fil->int_map[h + fil->h1][w + fil->w1] == 0)
	{
		fil->summ = fil->summ + (fil->y_map * fil->x_map);
		fil->co++;
	}
	else
	{
		fil->summ = fil->summ + fil->int_map[h + fil->h1][w + fil->w1];
		fil->co++;
	}
	return (1);
}

int			result_conditions(t_filler *fil, int h, int w)
{
	if (fil->count > 1)
		return (0);
	if (fil->summ_of_numbers == 0 && fil->count == 1 && fil->flag == 0)
	{
		fil->flag = 1;
		fil->summ_of_numbers = fil->summ;
		fil->count_cross = fil->count;
		fil->y_coor = h;
		fil->x_coor = w;
	}
	else if (fil->summ < fil->summ_of_numbers && fil->count == 1)
	{
		fil->summ_of_numbers = fil->summ;
		fil->count_cross = fil->count;
		fil->y_coor = h;
		fil->x_coor = w;
	}
	else
		return (0);
	return (1);
}

int			try_to_place(t_filler *fil, int h, int w)
{
	fil->h1 = 0;
	fil->count = 0;
	fil->summ = 0;
	fil->co = 0;
	while (fil->h1 < fil->y_figura)
	{
		fil->w1 = 0;
		while (fil->w1 < fil->x_figura)
		{
			if (step_conditions(fil, h, w) == 0)
				return (0);
			fil->w1++;
		}
		fil->h1++;
	}
	fil->summ = fil->summ / fil->co;
	if (result_conditions(fil, h, w) == 0)
		return (0);
	return (1);
}

int			placer_int(t_filler *fil)
{
	int		h;
	int		w;
	int		b;

	h = 0;
	b = 0;
	fil->flag = 0;
	fil->summ_of_numbers = 0;
	fil->count_cross = 0;
	fil->y_coor = 0;
	fil->x_coor = 0;
	while (h < fil->y_map - fil->y_figura + 1)
	{
		w = 0;
		while (w < fil->x_map - fil->x_figura + 1)
		{
			if (try_to_place(fil, h, w) == 1)
				b = 1;
			w++;
		}
		h++;
	}
	return (b);
}
