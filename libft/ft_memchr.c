/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:46:17 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:10:29 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	symb;

	i = -1;
	symb = (char)c;
	s1 = (char *)arr;
	while (++i < n)
		if (*(s1 + i) == symb)
			return ((void *)s1 + i);
	return (NULL);
}
