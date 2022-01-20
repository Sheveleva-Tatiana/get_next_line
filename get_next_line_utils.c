/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:29:55 by sshera            #+#    #+#             */
/*   Updated: 2021/11/18 11:24:59 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int ch)
{
	size_t	i;
	char	*str2;

	i = 0;
	str2 = str;
	while (str2[i] != '\0')
	{
		if (str2[i] == (char) ch)
			return (str2 + i);
		i++;
	}
	if (ch == '\0')
		return (str2 + i);
	return (NULL);
}

size_t	ft_strlen(char const *s, char c)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != c)
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0')) + 1);
	if (s == NULL)
	{
		free(s1);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	free(s1);
	s1 = NULL;
	return (s);
}

void	ft_bzero(char *s, size_t n)
{
	char	*bz;

	bz = s;
	while (n-- > 0)
	{
		*(bz++) = '\0';
	}
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*res;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s, '\0')) < (start + len))
		len = ft_strlen(s, '\0') - start;
	res = (char *)malloc((sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	k = 0;
	if (start >= 0 && (ft_strlen((char *)s, '\0') > start))
	{
		i = start;
		while (s[i] && k < len)
			res[k++] = s[i++];
		res[k] = '\0';
		return (res);
	}
	res[k] = '\0';
	return (res);
}
