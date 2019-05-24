/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:34:59 by rrosaura          #+#    #+#             */
/*   Updated: 2019/05/23 20:52:34 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_new_line(char **tmp, char **line, int fd, int rdr)
{
	char	*var;
	int		len;

	len = 0;
	while (tmp[fd][len] != '\n' && tmp[fd][len] != '\0')
		len++;
	if (tmp[fd][len] == '\n')
	{
		*line = ft_strsub(tmp[fd], 0, len);
		var = ft_strdup(tmp[fd] + len + 1);
		free(tmp[fd]);
		tmp[fd] = var;
		if (tmp[fd][0] == '\0')
			ft_strdel(&tmp[fd]);
	}
	else if (tmp[fd][len] == '\0')
	{
		if (rdr == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(tmp[fd]);
		ft_strdel(&tmp[fd]);
	}
	return (1);
}

char		*ft_strjoinnew(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	r = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (r == NULL)
		return (NULL);
	while (s1[j] != '\0')
		r[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	return (r);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*tmp[M_F];
	int			rdr;
	char		*new;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((rdr = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rdr] = '\0';
		if (tmp[fd] == NULL)
			tmp[fd] = ft_strnew(0);
		new = ft_strjoinnew(tmp[fd], buf);
		if (tmp[fd])
			free(tmp[fd]);
		tmp[fd] = new;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rdr < 0)
		return (-1);
	else if (rdr == 0 && (tmp[fd] == NULL || tmp[fd][0] == '\0'))
		return (0);
	else
		return (ft_new_line(tmp, line, fd, rdr));
}
