/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:17:47 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/11 17:57:18 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;
	void const	*tmp;
	size_t		tempa;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		tmp = ft_strdup((char *)content);
		tempa = content_size;
		elem->content = (void *)tmp;
		elem->content_size = tempa;
	}
	elem->next = NULL;
	return (elem);
}
