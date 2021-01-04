/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calle <calle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:22:54 by calle             #+#    #+#             */
/*   Updated: 2020/12/10 14:44:09 by calle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;
	size_t	i;
	size_t	j;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(r = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	while (s1 && i < l1 && s1[j])
		r[i++] = s1[j++];
	i = 0;
	while (s2 && i < l2 && s2[i])
		r[l1++] = s2[i++];
	r[l1] = '\0';
	return (r);
}

char			*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	c = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] || s[i] == c)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
