/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_0_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 12:54:35 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/04 16:49:01 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_0_1(t_fill *strct)
{
	int		x;
	int		y;

	y = strct->max_y - strct->p_y;
	while (y >= 0)
	{
		x = strct->max_x - strct->p_x;
		while (x >= 0)
		{
			if (check_move(strct, x, y) == 1)
			{
				ft_printf("%d %d\n", x, y);
				return ;
			}
			x--;
		}
		y--;
	}
}

void	side_0_1(t_fill *strct, int x, int o)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (ft_strchr("xX", strct->map[x][a]) == NULL)
		a++;
	while (ft_strchr("oO", strct->map[o][b]) == NULL)
		b++;
	if (b > a)
		ft_move(strct, b, o);
	else
	{
		while (ft_strchr("oO", strct->map[o][b]) != NULL)
			b++;
		ft_move(strct, b, o);
	}
}

void	down_0_1(t_fill *strct, int x, int o)
{
	int		i;

	i = 0;
	while (i < strct->max_x - strct->p_x)
	{
		if (check_move(strct, i, o) == 1)
			break ;
		i++;
	}
	if (i == strct->max_x - strct->p_x)
	{
		i = 0;
		while (i < strct->max_x - strct->p_x)
		{
			if (check_move(strct, i, o - 1) == 1)
				break ;
			i++;
		}
	}
	ft_move(strct, i, o);
}

void	filler_0_1(t_fill *strct)
{
	int		x;
	int		o;
	int		i;

	i = 0;
	x = -1;
	o = -1;
	while (i < strct->max_y)
	{
		if ((ft_strchr(strct->map[i], 'x') || ft_strchr(strct->map[i], 'X')) && x < 0)
			x = i;
		i++;
	}
	i--;
	while (i > 0)
	{
		if ((ft_strchr(strct->map[i], 'o') || ft_strchr(strct->map[i], 'O')) && o < 0)
			o = i;
		i--;
	}
	if (o + 3 < x)
		down_0_1(strct, x, o);
	else if (o < x)
		side_0_1(strct, x, o);//go sideways toward enemy
	else
		fill_0_1(strct);//cut off enemy
}
