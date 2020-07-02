/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:23:49 by mmahasim          #+#    #+#             */
/*   Updated: 2020/05/15 12:22:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler(t_filler *fil)
{
	char *line;

	while ((fil->p = get_next_line(0, &line)) > 0)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
			fil->error = map(fil, line);
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			fil->error = figura(fil, line);
//			if (fil->error == 0)
//			{
//				make_clean(fil);
//				return (place_output(fil, 1));
//			}
			fill_numbers(fil);
			placer_int(fil);
			place_output(fil, 0);
			make_clean(fil);
		}
		else
			free(line);
	}
	return (0);
}

int			map(t_filler *fil, char *line)
{
	fil->i = 0;
	fil->y_map = ft_atoi(line + 8);
	ft_strdel(&line);
//	if (!(fil->map = (char **)malloc(sizeof(char *) * fil->y_map)))
//		return (0);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (fil->i < fil->y_map)
	{
		get_next_line(0, &line);
		fil->map[fil->i] = ft_strdup(line + 4);
		free(line);
		fil->i++;
	}
	fil->x_map = ft_strlen(fil->map[0]);
	return (1);
}

int			figura(t_filler *fil, char *line)
{
	fil->i = 0;

	fil->y_figura = ft_atoi(line + 6);
	free(line);
//	if (!(fil->figura = (char **)malloc(sizeof(char *) * fil->y_map)))
//		return (0);
	while (fil->i < fil->y_figura)
	{
		get_next_line(0, &line);
		fil->figura[fil->i] = ft_strdup(line);
		free(line);
		fil->i++;
	}
	fil->x_figura = ft_strlen(fil->figura[0]);
	return (1);
}

int			place_output(t_filler *fil, int how)
{
	if (how == 1)
	{
		fil->y_coor = 0;
		fil->x_coor = 0;
	}
	ft_putnbr(fil->y_coor);
	ft_putchar(' ');
	ft_putnbr(fil->x_coor);
	ft_putchar('\n');
	return (0);
}

int			main()
{
	t_filler	fil;

	fil.y_int_map = 0;
	fil.y_int_figura = 0;
	player(&fil);
	filler(&fil);
	return (0);
}
