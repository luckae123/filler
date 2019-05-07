/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mastermind.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:45:38 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/07 14:13:32 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		make_absolute(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int		set_value(t_fill *strct, int x, int y)
{
	int		up;
	int		ret;
	int		i;

	up = 0;
	i = 0;
	ret = 9999;
	while (up < strct->max_y)
	{
		if (ft_strchr(strct->map[up], 'x') || ft_strchr(strct->map[up], 'X'))
		{
			while (ft_strchr(strct->nme, strct->map[up][i]) == NULL && i < strct->max_x)
				i++;
		}
		if (ret > make_absolute(x - i) + make_absolute(y - up))
			ret = make_absolute(x - i) + make_absolute(y - up);//make better
		i = 0;
		up++;
	}
	return (ret);
}

void	filler_moves(t_fill *strct, t_piece *mv)
{
	int		x;
	int		y;
	int		v;

	y = 0;
	v = 1000;
	while (y < strct->max_y - strct->p_y)
	{
		x = 0;
		while (x < strct->max_x - strct->p_x)
		{
			if (check_move(strct, x, y) == 1)
				v = set_value(strct, x, y);
			if (v < mv->v)
			{
				mv->x = x;
				mv->y = y;
				mv->v = v;
			}
			x++;
		}
		y++;
	}
}

void	ft_mastermind(t_fill *strct)
{
	t_piece	*mv;

	mv = (t_piece*)ft_memalloc(sizeof(t_piece));
	mv->v = 999;
	filler_moves(strct, mv);
	ft_printf("%d %d\n", mv->y - strct->p_y_offset, mv->x - strct->p_x_offset);
	ft_delmap(strct->map);
	free(strct->map);
	free(mv);
	ft_delpiece(strct);
}
