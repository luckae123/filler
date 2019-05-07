/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 15:29:11 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/07 13:19:33 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_player(t_fill *strct)
{
	char	*first;

	get_next_line(0, &first);
	if (ft_strstr(first, "p1") == NULL)
	{
		strct->c = 'x';
		strct->nme = "oO";
	}
	else
	{
		strct->c = 'o';
		strct->nme = "xX";
	}
	free(first);
}

void	filler(t_fill *strct)
{
	char	**line;
	int		ret;
	int		i;
	int		p;

	ret = 1;
	i = 0;
	line = (char**)ft_memalloc(sizeof(char*) * 999);
	while (ret > 0)
	{
		ret = get_next_line(0, &line[i]);
		i++;
		if (ft_strstr(line[i - 1], "Piece") != NULL)
		{
			p = i + ft_atoi(&line[i - 1][6]);
			while (i < p)
			{
				get_next_line(0, &line[i]);
				i++;
			}
			line[i] = NULL;
			ft_set_strct(strct, line);
			i = 0;
		}
	}
}

int     main(void)
{
	t_fill	*strct;

	strct = (t_fill*)ft_memalloc(sizeof(t_fill));
	strct->fd = open("test.txt", O_WRONLY);
	set_player(strct);
    filler(strct);
    return (0);
}
