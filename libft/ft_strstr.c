/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:14:02 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 17:01:50 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;
	int		k;
	int		check;

	check = 0;
	i = -1;
	if (!ft_strlen(str2))
		return ((char *)str1);
	while (*(str1 + ++i) && !check)
	{
		if (*(str1 + i) == *(str2 + 0))
		{
			j = 0;
			k = i;
			check = 1;
			while (*(str2 + j))
				if (*(str2 + j++) != *(str1 + k++))
					check = 0;
			if (check)
				return ((char *)str1 + i);
		}
	}
	return (NULL);
}
