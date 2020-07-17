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
	int		j;
	int		flag;
	int		error;
	int		player;
	int		int_my_char;
	int		int_opponent;
	int		x_map;
	int		y_map;
	int		y_int_map;
	int		x_figura;
	int		y_figura;
	int		y_int_figura;
	double	summ_of_numbers;
	int		y_coor;
	int		x_coor;
	char	**map;
	int		**int_map;
	char	**figura;
	int		**int_figura;
	int		h1;
	int		w1;
	int		count;
	double	summ;
	int		co;
	int		er_flag;
}					t_filler;

int					player(t_filler *fil);
void				filler(t_filler *fil);
int					place_output(t_filler *fil);
int					make_clean(t_filler *fil);
int					figura(t_filler *fil, char *line);
int					map(t_filler *fil, char *line);
int					fill_numbers(t_filler *fil);
int					fill_piece_numbers(t_filler *fil);
void				the_rest_numbers(t_filler *fil, int *flag);
void				place_the_rest(t_filler *fil, int h, int w);
void				perimetr(t_filler *fil);
void				place_one(t_filler *fil, int h, int w);
int					placer_int(t_filler *fil);
int					try_to_place(t_filler *fil, int h, int w);
int					result_conditions(t_filler *fil, int h, int w);
int					step_conditions(t_filler *fil, int h, int w);
int					clear_error(void **g, int x);
int					sokr_str_int_clear(t_filler *fil, int len);
#endif
