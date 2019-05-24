/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:21:32 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:10:21 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = -1;
	s1 = dest;
	s2 = (char *)source;
	if (s1 < s2)
		while (++i < count)
			*(s1 + i) = *(s2 + i);
	else
		while ((int)--count >= 0)
			*(s1 + count) = *(s2 + count);
	return (dest);
}
