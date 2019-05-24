/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:39:30 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/08 18:08:37 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	make_res(const char *str, _Bool sign)
{
	long long	res;
	long long	max;

	res = 0;
	max = 9223372036854775807;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if ((sign && (res <= ((max - (*str - '0')) / 10))) ||
			(!sign && (-res >= ((-max - 1 + (*str - '0')) / 10))))
				res = res * 10 + (*str - '0');
			else if (sign)
				return (-1);
			else if (!sign)
				return (0);
		}
		else
			break ;
		str++;
	}
	if (sign == 0)
		res = -res;
	return ((int)res);
}

int			ft_atoi(const char *str)
{
	_Bool	is_neg;

	is_neg = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'
				|| *str == '\f' || *str == '\v' || *str == '\n'))
		++str;
	if (*str == '-')
	{
		is_neg = 0;
		++str;
	}
	else if (*str == '+')
	{
		is_neg = 1;
		++str;
	}
	return (make_res(str, is_neg));
}
