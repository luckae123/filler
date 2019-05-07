/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:56:32 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/05/05 18:17:19 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		output_strct(t_fill *strct, int x, int y)
{
	ft_putnbr_fd(x, strct->fd);
	ft_putstr_fd(", ", strct->fd);
	ft_putnbr_fd(y, strct->fd);
	ft_putendl_fd("", strct->fd);
}