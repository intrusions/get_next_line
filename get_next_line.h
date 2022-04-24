/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:44:39 by xel               #+#    #+#             */
/*   Updated: 2022/04/24 12:44:39 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_have_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *stash);
char	*ft_get_stash(char *stash);
char	*get_next_line(int fd);

#endif