/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:33:12 by mmahasim          #+#    #+#             */
/*   Updated: 2020/05/21 12:12:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_filler
{
	int		i;
	int		flag;
	int		error;
	int		p;
	int		player;
	int		my_char;
	int		int_my_char;
	int		opponent;
	int		int_opponent;
	char	*line;
	int		x_map;
	int		y_map;
	int		x_int_map;
	int		y_int_map;
	int		x_figura;
	int		y_figura;
	int		x_int_figura;
	int		y_int_figura;
	double	summ_of_numbers;
	int		count_cross;
	int		y_coor;
	int		x_coor;
	char	*map[1024];
	int		*int_map[1024];
	char	*figura[1024];
	int		*int_figura[1024];
	int		h1;
	int		w1;
	int		count;
	double	summ;
	int		co;
}					t_filler;

int					filler(t_filler *fil);
int					place_output(t_filler *fil, int how);
void				make_clean(t_filler *fil);
int					figura(t_filler *fil, char *line);
int					map(t_filler *fil, char *line);
int 				fill_numbers(t_filler *fil);
void				fill_piece_numbers(t_filler *fil);
void				the_rest_numbers(t_filler *fil, int *flag);
void				place_the_rest(t_filler *fil, int h, int w);
int					make_map_int(t_filler *fil);
int					player(t_filler *fil);
void				perimetr(t_filler *fil);
void				place_one(t_filler *fil, int h, int w);
int					placer_int(t_filler *fil);
int					try_to_place(t_filler *fil, int h, int w);
int					result_conditions(t_filler *fil, int h, int w);
int					step_conditions(t_filler *fil, int h, int w);
int					ft_error(t_filler *fil);
#endif
