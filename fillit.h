/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:20:26 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/02 14:10:24 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "fcntl.h"
# include <stdio.h>
# include <string.h>

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;

//MAIN.c
int				main(int ac, char **av);
//READER.c
t_list			*ft_read_file(int fd);
int				validator(char *str, int count);
int				check_figure(char *str);
void			min_max(char *str, t_point *min, t_point *max);
t_etris			*get_figure(char *str, char value);
//TETRIMS.c
void			free_tetris(t_etris *tetri);
t_list			*free_list(t_list *list);
t_etris			*ft_tetris_new(char **pos, int width, int height, char value);
t_point			*ft_point_new(int x, int y);
//SOLVE_TETRIM.c
int				ft_get_map(t_map *map, t_list *list);
int				ft_sqrt(int n);
t_map			*ft_solution(t_list *list);
//MAP.c
void			ft_free_map(t_map *map);
void			ft_print_map(t_map *map);
int				ft_put_tetrim(t_etris *tetrim, t_map *map, int x, int y);
void			set_figure(t_etris *tetrim, t_map *map, t_point *point, char c);
t_map			*ft_create_map(int size);
#endif
