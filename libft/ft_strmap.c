/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:09:49 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/12 19:46:17 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char				*mem;
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	mem = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!mem)
		return (NULL);
	while (s[i])
	{
		mem[i] = f(s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
