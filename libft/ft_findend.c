/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:17:03 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/12 17:18:52 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_findend(char *str, const char *pool)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	tmp;
	unsigned int	counter;

	counter = 0;
	i = (unsigned int)ft_strlen(str) - 1;
	while (str[i])
	{
		j = 0;
		tmp = counter;
		while (pool[j])
			if (pool[j++] == str[i])
				++counter;
		if (tmp == counter)
			return (counter);
		--i;
	}
	return (counter);
}
