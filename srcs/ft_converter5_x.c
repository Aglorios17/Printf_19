/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:10:54 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_norme12_11_x(t_list *list, char *n, char *tmp)
{
	if (!list->starneg2 || list->zero)
		list->result = ft_strjoin(n, tmp);
	if (list->starneg2 && !list->zero)
		list->result = ft_strjoin(tmp, n);
}

void	ft_norme1_33x(t_list *list, char *n)
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

void	ft_norme2_22x(t_list *list, char *n)
{
	if (list->negatif)
	{
		ft_putchar('0');
		ft_putstr(n);
	}
	else
	{
		ft_putstr(n);
		ft_putchar('0');
	}
}
