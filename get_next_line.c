/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:42:16 by xel               #+#    #+#             */
/*   Updated: 2022/04/24 12:42:16 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	tmp = malloc((i + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (j <= i)
	{
		tmp[j] = stash[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_get_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	i = 0;
	k = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	tmp = malloc((ft_strlen(stash) - i) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = i + 1;
	while (stash[j])
		tmp[k++] = stash[j++];
	tmp[k] = '\0';
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			buffer[BUFFER_SIZE + 1];
	int				readed;
	char			*line_to_return;

	readed = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (readed && !ft_have_newline(stash))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line_to_return = ft_get_line(stash);
	stash = ft_get_stash(stash);
	return (line_to_return);
}
