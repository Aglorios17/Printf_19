/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:50:29 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:14:14 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_norme1_s(t_list *list)
{
	if (list->point && !list->num1 && !list->num2)
	{
		ft_putstr("");
		free(list->result);
		return (1);
	}
	return (0);
}

int	ft_norme2_s(t_list *list, char *n, int i, char *tmp)
{
	if (list->point)
	{
		if (ft_point_s(list, n, i))
			return (1);
	}
	if (ft_num1_point_s(list, n, i))
		return (1);
	ft_scut(list);
	if (list->num1 && list->num2)
	{
		if (ft_num12_1_s(list, n, i, tmp))
			return (1);
		if (ft_num12_2_s(list, n, i, tmp))
			return (1);
	}
	return (0);
}

int	ft_point2_s(t_list *list, char *n)
{
	if (list->num1 && !list->num2)
	{
		ft_putstr(n);
		free(n);
		list->count = list->num1;
		free(list->result);
		return (1);
	}
	return (0);
}
