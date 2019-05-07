/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:34:10 by lvan-vlo      #+#    #+#                 */
/*   Updated: 2019/01/13 15:36:25 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		write(1, &s[c], 1);
		c++;
	}
}