/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:43:13 by mmahasim          #+#    #+#             */
/*   Updated: 2020/05/11 15:23:13 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			make_field_int(t_filler *fil)
{
	fil->j = 0;
	fil->er_flag++;
	if (!(fil->int_map = (int **)malloc(sizeof(int *) * (fil->y_map))))
		return (sokr_str_int_clear(fil, fil->j));
	fil->y_int_map = fil->y_map;
	while (fil->j < fil->y_map)
	{
		fil->i = 0;
		if (!(fil->int_map[fil->j] = (int *)malloc(sizeof(int) * (fil->x_map))))
			return (sokr_str_int_clear(fil, fil->j + 1));
		while (fil->i < fil->x_map)
		{
			if (fil->map[fil->j][fil->i] == '.')
				fil->int_map[fil->j][fil->i] = 0;
			else if (fil->map[fil->j][fil->i] == 'O')
				fil->int_map[fil->j][fil->i] = -1;
			else if (fil->map[fil->j][fil->i] == 'X')
				fil->int_map[fil->j][fil->i] = -2;
			fil->i++;
		}
		fil->j++;
	}
	return (1);
}

void		place_the_rest(t_filler *fil, int h, int w)
{
	int		nu;

	nu = 0;
	if (h > 0)
		if (fil->int_map[h - 1][w] > 0)
			if (nu == 0)
				nu = fil->int_map[h - 1][w];
	if (w > 0)
		if (fil->int_map[h][w - 1] > 0)
			if (nu == 0 || fil->int_map[h][w - 1] < nu)
				nu = fil->int_map[h][w - 1];
	if (h + 1 < fil->y_map)
		if (fil->int_map[h + 1][w] > 0)
			if (nu == 0 || fil->int_map[h + 1][w] < nu)
				nu = fil->int_map[h + 1][w];
	if (w + 1 < fil->x_map)
		if (fil->int_map[h][w + 1] > 0)
			if (nu == 0 || fil->int_map[h][w + 1] < nu)
				nu = fil->int_map[h][w + 1];
	nu = nu == 0 ? 0 : nu + 1;
	fil->int_map[h][w] = nu;
}

void		the_rest_numbers(t_filler *fil, int *flag)
{
	int		h;
	int		w;
	int		count;

	h = 0;
	count = 0;
	while (h < fil->y_map)
	{
		w = 0;
		while (w < fil->x_map)
		{
			if (fil->int_map[h][w] == 0)
			{
				place_the_rest(fil, h, w);
				count++;
			}
			w++;
		}
		h++;
	}
	if (count == 0)
		*flag = 1;
}

int			fill_piece_numbers(t_filler *fil)
{
	fil->j = 0;
	fil->er_flag++;
	if (!(fil->int_figura = (int **)malloc(sizeof(int *) * (fil->y_figura))))
		return (sokr_str_int_clear(fil, fil->j));
	fil->y_int_figura = fil->y_figura;
	while (fil->j < fil->y_figura)
	{
		fil->i = 0;
		if (!(fil->int_figura[fil->j] =
				(int *)malloc(sizeof(int) * (fil->x_map))))
			return (sokr_str_int_clear(fil, fil->j + 1));
		while (fil->i < fil->x_figura)
		{
			if (fil->figura[fil->j][fil->i] == '.')
				fil->int_figura[fil->j][fil->i] = 0;
			else
				fil->int_figura[fil->j][fil->i] = fil->int_my_char;
			fil->i++;
		}
		fil->j++;
	}
	return (1);
}

int			fill_numbers(t_filler *fil)
{
	int		flag;
	int		kostil;

	flag = 0;
	kostil = 0;
	fil->int_my_char = fil->player == 1 ? -1 : -2;
	fil->int_opponent = fil->player == 1 ? -2 : -1;
	if (!make_field_int(fil) || !fill_piece_numbers(fil))
		return (0);
	perimetr(fil);
	while (flag == 0 && kostil < 100)
	{
		the_rest_numbers(fil, &flag);
		kostil++;
	}
	return (1);
}
