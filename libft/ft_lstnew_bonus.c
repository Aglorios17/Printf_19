/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bunus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:44:44 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/20 14:43:09 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstnew(void *content)
{
	t_list1 *lst;

	lst = malloc(sizeof(t_list1));
	if (lst == 0)
		return (0);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
