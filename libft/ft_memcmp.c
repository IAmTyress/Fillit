/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:45:03 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:10:43 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	while (++i < n && *(str1 + i) == *(str2 + i))
		;
	if (i == n)
		return (0);
	return (*(str1 + i) - *(str2 + i));
}
