/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:32:19 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/08 18:19:56 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	if (count == 0)
		return (0);
	while (s1[i] && s2[i] && n < count - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
