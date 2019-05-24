/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:25:43 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/10 17:33:40 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	ft_putstr_fd((char *)s, fd);
	ft_putchar_fd('\n', fd);
}
