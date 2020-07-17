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

int			player(t_filler *fil)
{
	char	*line;

	if ((get_next_line(0, &line)) != 1)
		return (0);
	if (ft_strncmp(line, "$$$ exec p", 10))
	{
		ft_strdel(&line);
		return (0);
	}
	fil->player = line[10] - 48;
	ft_strdel(&line);
	return (1);
}

void		filler(t_filler *fil)
{
	char	*line;

	fil->er_flag = 0;
	while ((get_next_line(0, &line)) > 0)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			if ((fil->error = map(fil, line)) == 0)
				break ;
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			if (!figura(fil, line) || !fill_numbers(fil))
				break ;
			placer_int(fil);
			place_output(fil);
			make_clean(fil);
		}
		else
			free(line);
	}
	if (fil->error == 0)
		free(line);
}

int			map(t_filler *fil, char *line)
{
	fil->i = 0;
	fil->er_flag++;
	fil->y_map = ft_atoi(line + 8);
	ft_strdel(&line);
	if (!(fil->map = (char **)malloc(sizeof(char *) * fil->y_map)))
		return (clear_error((void **)fil->map, fil->i));
	get_next_line(0, &line);
	line == NULL ? line : free(line);
	while (fil->i < fil->y_map)
	{
		get_next_line(0, &line);
		if (!(fil->map[fil->i] = ft_strdup(line + 4)))
		{
			fil->y_map = fil->i + 1;
			free(line);
			return (make_clean(fil));
		}
		free(line);
		fil->i++;
	}
	fil->x_map = ft_strlen(fil->map[0]);
	return (1);
}

int			figura(t_filler *fil, char *line)
{
	fil->i = 0;
	fil->er_flag++;
	fil->y_figura = ft_atoi(line + 6);
	free(line);
	if (!(fil->figura = (char **)malloc(sizeof(char *) * fil->y_map)))
	{
		fil->y_figura = 0;
		return (make_clean(fil));
	}
	while (fil->i < fil->y_figura)
	{
		if (get_next_line(0, &line) != 1)
			return (make_clean(fil));
		if (!(fil->figura[fil->i] = ft_strdup(line)))
		{
			fil->y_figura = fil->i + 1;
			free(line);
			return (make_clean(fil));
		}
		free(line);
		fil->i++;
	}
	fil->x_figura = ft_strlen(fil->figura[0]);
	return (1);
}

int			main(void)
{
	t_filler	fil;

	if (!player(&fil))
		return (0);
	filler(&fil);
	return (0);
}
