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
	int		i;
	int		j;

	j = 0;
//	if (!(fil->int_map = (int **)malloc(sizeof(int *) * (fil->y_map))))
//		exit(0);
	fil->y_int_map = fil->y_map;
	while (j < fil->y_map)
	{
		i = 0;
		if (!(fil->int_map[j] = (int *)malloc(sizeof(int) * (fil->x_map))))
			exit(0);
		while (i < fil->x_map)
		{
			if (fil->map[j][i] == '.')
				fil->int_map[j][i] = 0;
			else if (fil->map[j][i] == 'O')
				fil->int_map[j][i] = -1;
			else if (fil->map[j][i] == 'X')
				fil->int_map[j][i] = -2;
			i++;
		}
		j++;
	}
	return 1;
}

void		place_the_rest(t_filler *fil, int h, int w)
{
	int		nu;

	nu = 0;
	if (h > 0)
		if (fil->int_map[h - 1][w] > 0)
			if (nu == 0 || fil->int_map[h - 1][w] < nu)
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
		w = 0;
		h++;
	}
	if (count == 0)
		*flag = 1;
}

void		fill_piece_numbers(t_filler *fil)
{
	int		h;
	int		w;

	h = 0;
//	if (!(fil->int_figura = (int **)malloc(sizeof(int *) * (fil->y_figura))))
//		exit(0);
//	fil->y_int_figura = fil->y_figura;
	while (h < fil->y_figura)
	{
		w = 0;
		if (!(fil->int_figura[h] = (int *)malloc(sizeof(int) * (fil->x_map))))
			exit(0);
		while (w < fil->x_figura)
		{
			if (fil->figura[h][w] == '.')
				fil->int_figura[h][w] = 0;
			else
				fil->int_figura[h][w] = fil->int_my_char;
			w++;
		}
		h++;
	}
}

int			fill_numbers(t_filler *fil)
{
	int		flag;
	int		kostil;

	flag = 0;
	kostil = 0;
	fil->my_char = fil->player == 1 ? 'O' : 'X';
	fil->opponent = fil->player == 1 ? 'X' : 'O';
	fil->int_my_char = fil->player == 1 ? -1 : -2;
	fil->int_opponent = fil->player == 1 ? -2 : -1;
	make_field_int(fil);
	perimetr(fil);
	while (flag == 0 && kostil < 100)
	{
		the_rest_numbers(fil, &flag);
		kostil++;
	}
	fill_piece_numbers(fil);
	return 1;
}
