/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:11:21 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/20 14:42:51 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list1 *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	if (lst != NULL)
	{
		f(lst->content);
		lst->next = lst;
	}
}
