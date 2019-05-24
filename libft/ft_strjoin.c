/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:55:52 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 15:43:37 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	size;

	if (s1 && s2)
		size = (size_t)(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	else if (s1)
		size = (size_t)(ft_strlen((char *)s1));
	else if (s2)
		size = (size_t)(ft_strlen((char *)s2));
	else
		return (NULL);
	if (!(mem = ft_memalloc(size)))
		return (NULL);
	if (s1)
		mem = ft_strcpy(mem, (char *)s1);
	else
		mem = ft_strcpy(mem, (char *)s2);
	if (s1 && s2)
		mem = ft_strcat(mem, (char *)s2);
	return (mem);
}
