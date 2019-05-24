/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:16:05 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/12 17:18:37 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_findstart(char *ptr, const char *pool)
{
	int				j;
	char			*str;
	unsigned int	tmp;
	unsigned int	counter;

	str = ptr;
	counter = 0;
	while (*str)
	{
		j = 0;
		tmp = counter;
		while (pool[j])
			if (pool[j++] == *str)
				++counter;
		if (tmp == counter)
			return (counter);
		++str;
	}
	return (counter);
}
