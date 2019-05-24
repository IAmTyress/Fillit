/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:36:41 by rrosaura          #+#    #+#             */
/*   Updated: 2019/05/23 20:34:07 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_and_check(char **matrix)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (matrix[i])
	{
		if ((i + 1) % 5 == 0)
		{
			if (matrix[i][0] == 0)
				counter++;
			else
				return (-1);
		}
		i++;
	}
	counter++;
	return ((counter > 0 && counter < 26) ? counter : -2);
}

int	count_sharps(char **matrix)
{
	int	i;
	int	j;
	int	co;

	i = 0;
	j = -1;
	co = 0;
	while (matrix[i])
	{
		if ((i + 1) % 5 == 0)
		{
			if (co != 4)
				return (-3);
			co = 0;
		}
		else
		{
			j = -1;
			while (matrix[i][j++])
				(matrix[i][j] == '#') ? co++ : co;
		}
		i++;
	}
	return (co);
}

int	check_tetrim(char **matrix)
{
	int	co;
	int	checker;
	int	i;
	int	j;

	checker = 0;
	i = 0;
	if ((co = count_and_check(matrix)) == -1)
		return (-4);
	while (i < (co * 5 - 1))
	{
		if ((i + 1) % 5 != 0)
		{
			if (ft_strlen(matrix[i]) != 4)
				return (-5);
			j = 0;
			while (matrix[i][j] == '#' || matrix[i][j] == '.')
				j++;
			if (j != 4)
				return (-6);
		}
		i++;
	}
	return (0);
}

int	check_sharps(char **matrix, int i)
{
	int	j;
	int	cons;

	j = 0;
	cons = 0;
	while (j < 4)
	{
		if (matrix[i - 1])
			if (matrix[i][j] == '#' && matrix[i - 1][j] == '#')
				cons++;
		if (matrix[i + 1])
			if (matrix[i][j] == '#' && matrix[i + 1][j] == '#')
				cons++;
		if (matrix[i][j - 1])
			if (matrix[i][j] == '#' && matrix[i][j - 1] == '#')
				cons++;
		if (matrix[i][j + 1])
			if (matrix[i][j] == '#' && matrix[i][j + 1] == '#')
				cons++;
		j++;
	}
	return (cons);
}

int	validate(char **matrix)
{
	int	co;
	int	cons;
	int	i;

	i = 0;
	if (check_tetrim(matrix) < 0 || count_sharps(matrix) != 4)
		return (-1);
	co = count_and_check(matrix);
	while (i < (co * 5) - 1)
	{
		cons = 0;
		while ((i + 1) % 5 != 0)
		{
			cons += check_sharps(matrix, i);
			i++;
		}
		if (cons != 6 && cons != 8)
			return (-1);
		i++;
	}
	return (0);
}
