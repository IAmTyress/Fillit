/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:23:44 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/11 18:01:00 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!(ft_strlen(str2)))
		return ((char *)str1);
	while (*(str1 + ++i) && i < len)
	{
		j = 0;
		if (*(str1 + i) == *(str2 + 0))
		{
			k = i;
			found = 1;
			while (*(str1 + k) && *(str2 + j) && j < len && k < len)
				if (*(str1 + k++) != *(str2 + j++))
					found = 0;
			if (found && !*(str2 + j))
				return ((char *)str1 + i);
		}
	}
	return (NULL);
}
