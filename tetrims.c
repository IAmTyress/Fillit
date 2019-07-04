/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrims.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:49:56 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/04 17:22:53 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*free_list(t_list *list)
{
	t_etris	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_etris*)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void**)&list);
		list = next;
	}
	return (NULL);
}

void	free_tetris(t_etris *tetri)
{
	int	i;

	i = 0;
	while (i < tetri->height)
	{
		ft_memdel((void**)(&(tetri->pos[i])));
		i++;
	}
	ft_memdel((void**)(&(tetri->pos)));
	ft_memdel((void**)&tetri);
}

t_etris	*ft_tetris_new(char **pos, int width, int height, char value)
{
	t_etris	*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_point	*ft_point_new(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
