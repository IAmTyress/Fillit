/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:10:28 by rrosaura          #+#    #+#             */
/*   Updated: 2019/05/23 20:41:27 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

char	**rdr(int fd)
{
	char	*line;
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		matrix[i] = ft_strnew(0);
		if (line == 0)
			matrix[i][0] = 0;
		else
			matrix[i] = line;
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}

int		main(int ac, char **av)
{
	int		i;
	int		val;
	char	**matrix;
	int		fd;

	val = 0;
	i = 0;
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	matrix = rdr(fd);
	while (matrix[i])
		i++;
	if ((i + 1) % 5 != 0 || (val = validate(matrix)) < 0)
		ft_putstr("error\n");
	return (0);
}
