/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 17:49:06 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/23 17:50:16 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
}