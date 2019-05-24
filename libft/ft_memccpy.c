/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:00:12 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:10:13 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t count)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = dest;
	while (i < count)
	{
		*(s1 + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
