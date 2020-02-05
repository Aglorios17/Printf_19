/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:10:07 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_norme1_2x(t_list *list)
{
	if (list->result != NULL && !list->num1)
	{
		ft_putstr(list->result);
		list->count = ft_strlen2(list->result);
		free(list->result);
		return (1);
	}
	return (0);
}

int		ft_norme1_3x(t_list *list, char *n, int i)
{
	if (list->result)
	{
		if (list->num1 <= ft_strlen2(list->result))
		{
			ft_putstr(list->result);
			list->count = ft_strlen2(list->result);
			return (1);
		}
		i = list->num1 - ft_strlen2(list->result);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
		ft_norme1_33x(list, n);
		free(n);
		free(list->result);
		list->count = list->num1;
		return (1);
	}
	return (0);
}

void	ft_norme1_4x(t_list *list, char *n, int i)
{
	free(list->result);
	i = list->num1;
	if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
		return ;
	ft_putstr(n);
	list->count = list->num1;
	free(list->result);
	free(n);
}

int		ft_norme1_x(t_list *list, char *n, int i)
{
	if (list->point && !list->num2)
	{
		if (ft_norme1_2x(list))
			return (1);
		if (list->num1 && list->num1)
		{
			if (ft_norme1_3x(list, n, i))
				return (1);
			else
			{
				ft_norme1_4x(list, n, i);
				return (1);
			}
		}
		else
		{
			free(list->result);
			list->result = "";
			ft_putstr(list->result);
			list->count = 0;
		}
		return (1);
	}
	return (0);
}

int		ft_norme2_2x(t_list *list, char *n)
{
	int i;

	i = list->num1;
	if (list->num1 && !list->num2)
	{
		if (list->zero)
		{
			if (!(n = ft_strcpy2((char *)malloc(i), '0', i - 1)))
				return (1);
		}
		else if (!(n = ft_strcpy2((char *)malloc(i), ' ', i - 1)))
			return (1);
		ft_norme2_22x(list, n);
		free(n);
		list->count = list->num1;
		return (1);
	}
	return (0);
}
