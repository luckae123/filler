/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 15:30:47 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/07 11:31:40 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>//
#include <fcntl.h>//

typedef struct	s_fill
{
	char		**map;
	int			**piece;
	char		c;
	char		*nme;
	int			max_y;
	int			max_x;
	int			p_y;
	int			p_x;
	int			p_size;
	int			p_x_offset;
	int			p_y_offset;
	int			fd;
}				t_fill;

typedef struct s_piece
{
	int			x;
	int			y;
	int			v;
}				t_piece;

void			filler(t_fill *strct);
void			ft_set_strct(t_fill *strct, char **line);
void			ft_set_max(int *y, int *x, char *line);
void			ft_set_piece(t_fill *strct, char **line);
void			ft_mastermind(t_fill *strct);
int				check_move(t_fill *strct, int x, int y);
void			ft_delpiece(t_fill *strct);

void			output_strct(t_fill *strct, int x, int y);

#endif
