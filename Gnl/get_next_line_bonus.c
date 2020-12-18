/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:34:37 by ji-park           #+#    #+#             */
/*   Updated: 2020/11/20 18:41:12 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_newline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		separate(char **line, char **storage, int cut_idx)
{
	int		remain_len;
	char	*temp;

	(*storage)[cut_idx] = 0;
	remain_len = ft_strlen(*storage + cut_idx + 1);
	*line = ft_strdup(*storage);
	if (remain_len == 0)
	{
		free(*storage);
		*storage = 0;
		return (1);
	}
	temp = ft_strdup(*storage + cut_idx + 1);
	free(*storage);
	*storage = temp;
	return (1);
}

int		remain_return(char **line, char **storage)
{
	int	cut_idx;

	if (*storage && (cut_idx = check_newline(*storage)) >= 0)
		return (separate(line, storage, cut_idx));
	else if (*storage)
	{
		*line = *storage;
		*storage = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*storage[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				cut_idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (storage[fd] == 0)
			storage[fd] = ft_strdup("");
		buf[read_size] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buf);
		if ((cut_idx = check_newline(storage[fd])) >= 0)
			return (separate(line, &storage[fd], cut_idx));
	}
	if (read_size < 0)
		return (-1);
	return (remain_return(line, &storage[fd]));
}
