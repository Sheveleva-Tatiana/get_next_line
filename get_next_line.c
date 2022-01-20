/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:14:28 by sshera            #+#    #+#             */
/*   Updated: 2021/11/18 11:23:12 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*res;
	int			flag;

	flag = 0;
	temp = check_stat(buf);
	if (!temp)
	{
		temp = malloc(1);
		ft_bzero(temp, 1);
	}
	flag = ft_read_file(fd, &temp, buf);
	if (ft_strchr(temp, '\n'))
		res = ft_substr(temp, 0, (ft_strlen(temp, '\n') + 1));
	else
		res = ft_substr(temp, 0, (ft_strlen(temp, '\0') + 1));
	free(temp);
	if (!flag && buf[0] == '\0' && res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	ft_read_file(int fd, char **temp, char *buf)
{
	int	count_read;

	count_read = 1;
	while (!(ft_strchr(*temp, '\n')) && count_read)
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		buf[count_read] = '\0';
		if (count_read == -1)
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (0);
		}
		if (count_read)
			*temp = ft_strjoin(*temp, buf);
		else
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (0);
		}
	}
	return (1);
}

char	*check_stat(char *buf)
{
	char	*temp;
	int		len_buf;
	int		len_buf_end;

	temp = NULL;
	if (*buf)
	{
		if (ft_strchr(buf, '\n'))
		{
			len_buf = ft_strlen(buf, '\n') + 1;
			len_buf_end = ft_strlen(buf, '\0') + 1;
			temp = ft_substr(buf, len_buf, len_buf_end);
			ft_memmove(&buf[0], &buf[len_buf], (len_buf_end - len_buf));
			ft_bzero(&buf[len_buf_end - len_buf + 1], 1);
		}
		else
		{
			temp = ft_substr(buf, 0, (ft_strlen(buf, '\0') + 1));
			ft_bzero(buf, (BUFFER_SIZE + 1));
		}
	}
	else
		ft_bzero(buf, (BUFFER_SIZE + 1));
	return (temp);
}

void	*ft_memmove(void *d, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (source < d)
	{
		while (n-- > 0)
			*((unsigned char *)d + n) = *((unsigned char *)source + n);
		return (d);
	}
	if (source > d)
	{
		while (i < n)
		{
			*((unsigned char *)d + i) = *((unsigned char *)source + i);
			i++;
		}
		return (d);
	}
	return (d);
}
