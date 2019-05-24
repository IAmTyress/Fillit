/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:30:46 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/11 15:13:01 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		(*alst) = (*alst)->next;
		ft_lstdelone(&tmp, del);
		tmp = *alst;
	}
}
