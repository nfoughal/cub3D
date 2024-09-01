/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:07:49 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/30 22:51:23 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_record(int fd, char *record)
{
	int		bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (ftt_strchr(record, '\n') && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		record = ftt_strjoin(record, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (record);
}

char	*ft_line(char *record)
{
	char	*p;
	int		i;

	i = 0;
	if (!record || record[i] == '\0')
		return (NULL);
	while (record[i] && record[i] != '\n')
		i++;
	p = malloc(sizeof(char) * (i + 2));
	if (!p)
		return (NULL);
	i = 0;
	while (record[i] && record[i] != '\n')
	{
		p[i] = record[i];
		i++;
	}
	if (record[i] == '\n')
	{
		p[i] = record[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*new_record(char *record)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!record)
		return (NULL);
	while (record[i] && record[i] != '\n')
		i++;
	if ((record == NULL) || (record[i] == '\0'))
	{
		free (record);
		return (NULL);
	}
	p = malloc(sizeof(char) * ftt_strlen(record) - i + 1);
	if (!p)
		return (NULL);
	i++;
	while (record[i])
		p[j++] = record[i++];
	p[j] = '\0';
	free (record);
	record = (NULL);
	return (p);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*record[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	record[fd] = read_record(fd, record[fd]);
	line = ft_line(record[fd]);
	record[fd] = new_record(record[fd]);
	return (line);
}
