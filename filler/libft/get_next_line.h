/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 08:11:26 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/01 19:40:10 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

int		get_next_line(const int fd, char **line);

#endif
