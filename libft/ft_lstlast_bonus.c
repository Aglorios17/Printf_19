/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:52:17 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/20 14:41:56 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstlast(t_list1 *lst)
{
	t_list1 *new;

	if (!lst)
		return (0);
	while (lst)
	{
		new = lst;
		lst = lst->next;
	}
	return (new);
}
