/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:15:55 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/02 14:42:09 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		exit (1);
	}
	if ((list = ft_read_file(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putendl("error");
		exit (1);
	}
	map = ft_solution(list);
	ft_print_map(map);
	ft_free_map(map);
	free_list(list);
	return (0);
}
