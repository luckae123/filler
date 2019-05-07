/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:21:52 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/05 17:07:12 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fix_piece_size(t_fill *strct)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i < strct->p_size)
	{
		if (strct->piece[i][0] > x)
			x = strct->piece[i][0];
		if (strct->piece[i][1] > y)
			y = strct->piece[i][1];
		i++;
	}
	strct->p_x = x + 1;
	strct->p_y = y + 1;
}

void	ft_offset_piece(t_fill *strct)
{
	int		i;

	i = 0;
	strct->p_x_offset = strct->piece[0][0];
	strct->p_y_offset = strct->piece[0][1];
	while (i < strct->p_size)
	{
		if (strct->p_x_offset > strct->piece[i][0])
			strct->p_x_offset = strct->piece[i][0];
		if (strct->p_y_offset > strct->piece[i][1])
			strct->p_y_offset = strct->piece[i][1];
		i++;	
	}
	i = 0;
	while (i < strct->p_size)
	{
		strct->piece[i][0] -= strct->p_x_offset;
		strct->piece[i][1] -= strct->p_y_offset;
		i++;
	}
}

void	ft_piece_coords(char **piece, t_fill *strct)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (y < strct->p_y)
	{
		while (x < strct->p_x)
		{
			if (piece[y][x] == '*')
			{
				strct->piece[i] = (int*)ft_memalloc(sizeof(int) * 2);
				strct->piece[i][0] = x;
				strct->piece[i][1] = y;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_count_piece(char **piece, t_fill *strct)
{
	int		ret;
	int		i;
	int		x;
	int		y;

	ret = 0;
	i = 0;
	while (i < strct->p_y * strct->p_x)
	{
		x = i % strct->p_x;
		y = i / strct->p_x;
		if (piece[y][x] == '*')
			ret++;
		i++;
	}
	strct->p_size = ret;
	return (ret);
}

void	ft_set_piece(t_fill *strct, char **line)
{
	char	**piece;
	int		y;

	y = 0;
	ft_set_max(&strct->p_y, &strct->p_x, *line);
	piece = (char**)ft_memalloc(sizeof(char*) * strct->p_y + 1);
	while (y < strct->p_y)
	{
		piece[y] = ft_strdup(line[y + 1]);
		y++;
	}
	piece[y] = NULL;
	strct->piece = (int**)ft_memalloc(sizeof(int*) * ft_count_piece(piece, strct));
	ft_piece_coords(piece, strct);
	ft_delmap(piece);
	free(piece);
	ft_offset_piece(strct);
	fix_piece_size(strct);
}