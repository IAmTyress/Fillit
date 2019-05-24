/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:41:56 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:43:07 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*mem;

	if (!s || !(mem = ft_memalloc(len + 1)))
		return (NULL);
	mem = ft_strncpy(mem, (char *)s + start, len);
	return (mem);
}
