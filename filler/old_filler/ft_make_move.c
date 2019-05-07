/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 11:44:13 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/29 17:25:07 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_move(t_fill *strct, int x, int y)
{
	int		i;
	int		con;

	i = 0;
	con = 0;
	while (i < strct->p_size)
	{
		if (strct->map[y + strct->piece[i][1]][x + strct->piece[i][0]] \
		== strct->c)
			con++;
		if (strct->map[y + strct->piece[i][1]][x + strct->piece[i][0]] \
		== strct->c - 32)
			con++;
		i++;
	}
	return (con);
}

void	ft_make_move(t_fill *strct)
{
	int		i;
	int		x;
	int		y;
	i = 0;
	while (i < strct->max_y * strct->max_x)
	{
		x = i % strct->max_x;
		y = i / strct->max_x;
		if (x + strct->p_x < strct->max_x || \
		y + strct->p_x < strct->max_y)
		{
			if (ft_check_move(strct, x, y) == 1)
				break ;
		}
		i++;
	}
	printf("%d %d\n", y - strct->p_y_offset, x - strct->p_x_offset);
}