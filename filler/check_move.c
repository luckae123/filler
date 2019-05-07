/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:41:29 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/07 12:07:10 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_move(t_fill *strct, int x, int y)
{
	int		i;
	int		con;

	i = 0;
	con = 0;
	while (i < strct->p_size)
	{
		if (strct->map[strct->piece[i][1] + y][strct->piece[i][0] + x] == strct->c \
		|| strct->map[strct->piece[i][1] + y][strct->piece[i][0] + x] == strct->c - 32)
			con++;
		else if (ft_strchr(strct->nme, strct->map[strct->piece[i][1] + y][strct->piece[i][0] + x]))
			return (0);
		i++;
	}
	return (con);
}

void	ft_delpiece(t_fill *strct)
{
	int		i;

	i = 0;
	while (i < strct->p_size)
	{
		free(strct->piece[i]);
		i++;
	}
	free(strct->piece);
}
