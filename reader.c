/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:10:24 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/04 17:10:49 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	min_max(char *str, t_point *min, t_point *max)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_etris		*get_figure(char *str, char value)
{
	t_point	*min;
	t_point	*max;
	char	**pos;
	int		i;
	t_etris	*tetri;

	min = ft_point_new(3, 3);
	max = ft_point_new(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char*) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x)
			+ (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetri = ft_tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void**)&min);
	ft_memdel((void**)&max);
	return (tetri);
}

int		check_figure(char *str)
{
	int	i;
	int	blocks;

	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				blocks++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				blocks++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				blocks++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				blocks++;
		}
		i++;
	}
	return (blocks == 6 || blocks == 8);
}

int		validator(char *str, int count)
{
	int	i;
	int	blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (1);
		}	
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!check_figure(str))
		return (1);
	return (0);
}

t_list	*ft_read_file(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	t_etris	*tetris;
	char	cur;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (validator(buf, count) != 0
				|| (tetris = get_figure(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void**)&tetris);
	}
	ft_memdel((void**)&buf);
	if (count > 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
