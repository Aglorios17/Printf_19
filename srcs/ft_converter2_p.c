/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:31:30 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			ft_norme1_p(t_list *list, char *n)
{
	if (list->negatif || list->starneg1)
	{
		ft_putstr(list->result);
		ft_putstr(n);
	}
	if (!list->negatif && !list->starneg1)
	{
		ft_putstr(n);
		ft_putstr(list->result);
	}
}

void			ft_norme2_p(t_list *list, char *tmp, char *n, char *tmp2)
{
	tmp = list->result;
	ft_putstr(tmp2);
	ft_putstr(n);
	free(n);
	free(tmp);
}

void			ft_norme3_p(t_list *list, char *n)
{
	if (list->negatif)
	{
		ft_putstr(list->result);
		ft_putstr(n);
	}
	if (!list->negatif)
	{
		ft_putstr(n);
		ft_putstr(list->result);
	}
}
