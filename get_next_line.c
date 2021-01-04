/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calle <calle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:22:29 by calle             #+#    #+#             */
/*   Updated: 2020/12/15 14:24:30 by calle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_error(char **s)
{
	if (s)
		*s = NULL;
	return (-1);
}

static int	free_all(char *s, long int ret)
{
	free(s);
	if (ret == 0)
		return (0);
	else
		return (-1);
}

static char	*handle_leftover(char *s, long int ret)
{
	char	*tmp;

	tmp = NULL;
	if (ret > 0)
	{
		tmp = ft_strdup(s);
		free((void*)s);
		if (!(s = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		{
			free((void*)tmp);
			return (NULL);
		}
		free((void*)tmp);
		return (s);
	}
	else
	{
		s = NULL;
		return (s);
	}
}

static char	*make_line(char *s, long int ret)
{
	int		i;
	char	*line;

	i = 0;
	if (ret == 0)
		return (s);
	while (s[i] && s[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int			get_next_line(int fd, char **line)
{
	long int			ret;
	char				buf[BUFFER_SIZE + 1];
	char				*tmp;
	static char			*str_lftvr;

	ret = 1;
	if (!line || fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (handle_error(line));
	while (ret > 0 && !(ft_strchr(str_lftvr, '\n')))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (handle_error(line));
		buf[ret] = '\0';
		tmp = ft_strjoin(str_lftvr, buf);
		free(str_lftvr);
		str_lftvr = ft_strdup(tmp);
		free(tmp);
	}
	if (!(*line = make_line(str_lftvr, ret)))
		return (handle_error(line));
	if (!(str_lftvr = handle_leftover(str_lftvr, ret)))
		return (free_all(str_lftvr, ret));
	return (1);
}
