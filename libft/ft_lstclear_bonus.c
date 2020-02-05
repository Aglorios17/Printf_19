/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:27:23 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/20 14:42:28 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list1 **lst, void (*del)(void*))
{
	t_list1 *buffer;

	if (*lst == NULL || del == NULL)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		*lst = buffer;
		ft_lstdelone(*lst, del);
		buffer = buffer->next;
	}
	*lst = NULL;
}
