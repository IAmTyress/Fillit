/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:15:55 by rrosaura          #+#    #+#             */
/*   Updated: 2019/07/05 16:23:39 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	cntr(void)
{
	static int	i;

	i++;
	return (i);
}

int	check_last_n(int fd)
{
	char	*buf;
	int		count;
	int		rdr;

	buf = ft_memalloc(21);
	count = 0;
	while ((rdr = read(fd, buf, 21)) > 0)
	{
		if (rdr == 20)
			count++;
	}
	return (count == 1 ? 0 : 1);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		exit(1);
	}
	if ((list = ft_read_file(open(av[1], O_RDONLY))) == NULL
			|| check_last_n((fd = open(av[1], O_RDONLY))) != 0)
	{
		ft_putendl("error");
		exit(1);
	}
	map = ft_solution(list);
	ft_print_map(map);
	ft_free_map(map);
	free_list(list);
	return (0);
}
