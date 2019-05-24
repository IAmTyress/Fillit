/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:38:36 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/11 12:57:38 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++i;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*str;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	size = (unsigned int)nb_size(nbr);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	str[i] = (char)(nbr % 10 + 48);
	str[size] = '\0';
	return (str);
}
