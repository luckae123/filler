/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filler.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:06:35 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/29 17:24:03 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_char(t_fill *strct, char *line)
{
	if (ft_strstr(line, "p1") == NULL)
		strct->c = 'x';
	else
		strct->c = 'o';
}

void	ft_set_map(t_fill *strct, char **line)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < strct->max_y)
	{
		while (line[y][i] != ' ')
			i++;
		i++;
		strct->map[y] = ft_strdup(&line[y][i]);
		i = 0;
		y++;
	}
	strct->map[y] = NULL;
}

void	ft_set_max(int *y, int *x, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ':')
		i++;
	while (line[i] != ' ')
		i--;
	*x = ft_atoi(&line[i + 1]);
	i--;
	while (line[i] != ' ')
		i--;
	*y = ft_atoi(&line[i + 1]);
}

void	ft_set_strct(t_fill *strct, char **line)
{
	ft_set_max(&strct->max_y, &strct->max_x, line[0]);
	strct->map = (char**)ft_memalloc(sizeof(char*) * strct->max_y + 1);
	ft_set_map(strct, &line[2]);
	ft_set_piece(strct, &line[2 + strct->max_y]);
	ft_delmap(line);
	ft_make_move(strct);
}
