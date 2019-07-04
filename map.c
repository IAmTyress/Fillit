/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:40:43 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/04 17:22:17 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&(map->array[i]));
		i++;
	}
	ft_memdel((void**)&(map->array));
	ft_memdel((void**)&map);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*ft_create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		ft_put_tetrim(t_etris *tetrim, t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetrim->width)
	{
		j = 0;
		while (j < tetrim->height)
		{
			if (tetrim->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_figure(tetrim, map, ft_point_new(x, y), tetrim->value);
	return (1);
}

void	set_figure(t_etris *tetrim, t_map *map, t_point *point, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetrim->width)
	{
		j = 0;
		while (j < tetrim->height)
		{
			if (tetrim->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}
