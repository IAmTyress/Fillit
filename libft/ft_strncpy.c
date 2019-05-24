/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:21:08 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/12 19:45:19 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		if (*(src + i))
			*(dest + i) = *(src + i);
		else
			while (i < n)
				*(dest + i++) = '\0';
	}
	return (dest);
}
