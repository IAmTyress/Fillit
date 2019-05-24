/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:56:05 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/12 17:25:22 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	size;
	unsigned int	spaces;
	unsigned int	start;
	char			*str;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char *)s);
	spaces = ft_findstart((char *)s, " \n\t");
	start = spaces;
	if (size > spaces)
		spaces += ft_findend((char *)s, " \n\t");
	size -= spaces;
	if (!(str = ft_memalloc((size_t)size + 1)))
		return (NULL);
	str = ft_strncpy(str, (char *)s + start, size);
	return (str);
}
