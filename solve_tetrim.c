/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:36:17 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/04 17:19:27 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_map(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_etris	*tetris;

	if (list == NULL)
		return (1);
	y = 0;
	tetris = (t_etris*)(list->content);
	while (y < map->size - tetris->height + 1)
	{
		x = 0;
		while (x < map->size - tetris->width + 1)
		{
			if (ft_put_tetrim(tetris, map, x, y))
			{
				if (ft_get_map(map, list->next))
					return (1);
				else
					set_figure(tetris, map, ft_point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_sqrt(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map	*ft_solution(t_list *list)
{
	t_map	*map;
	int		size;

	size = ft_sqrt(ft_lstcount(list) * 4);
	map = ft_create_map(size);
	while (!ft_get_map(map, list))
	{
		size++;
		ft_free_map(map);
		map = ft_create_map(size);
	}
	return (map);
}
