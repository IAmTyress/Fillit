/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:16:09 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:10:07 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = dest;
	s2 = (char *)source;
	i = -1;
	while (++i < count)
		*(s1 + i) = *(s2 + i);
	return (dest);
}
