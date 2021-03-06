/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:19:45 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int		ft_listnum1norme1_x(t_list *list)
{
	if (list->result[0] == '-' && list->num1 > ft_strlen2(list->result))
	{
		list->result[0] = '0';
		list->neg = 1;
		return (1);
	}
	return (0);
}

static	void	ft_listnum1norme2_x(t_list *list, char *n)
{
	if (list->negatif || list->starneg1)
	{
		ft_putstr(list->result);
		ft_putstr(n);
	}
	else
	{
		if (list->neg)
			ft_putchar('-');
		ft_putstr(n);
		ft_putstr(list->result);
	}
}

int				ft_listnum1_x(t_list *list)
{
	char	*n;
	int		i;

	n = 0;
	if (list->num1 && !list->num2 && list->num1 >= ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen2(list->result);
		if (list->zero && !list->point && !list->starneg1)
		{
			i -= ft_listnum1norme1_x(list);
			if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
				return (1);
		}
		else if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
		ft_listnum1norme2_x(list, n);
		if (list->neg)
			list->count = 1 + (ft_strlen2(list->result) + ft_strlen2(n));
		else
			list->count = (ft_strlen2(list->result) + ft_strlen2(n));
		free(n);
		free(list->result);
		return (1);
	}
	return (0);
}

static	void	ft_listnum2norme_x(t_list *list, char *n)
{
	if (!list->negatif || list->point)
	{
		if (list->neg)
			ft_putchar('-');
		ft_putstr(n);
		ft_putstr(list->result);
	}
	list->count = (ft_strlen2(list->result) + ft_strlen2(n));
	free(n);
}

int				ft_listnum2_x(t_list *list)
{
	char	*n;
	int		i;

	if (list->num2 && !list->num1 && list->num2 >= ft_strlen2(list->result))
	{
		if (list->starneg2)
		{
			list->count = ft_strlen2(list->result);
			return (0);
		}
		i = list->num2 - ft_strlen2(list->result);
		ft_num2neg(list);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return (1);
		if (list->negatif && !list->point)
		{
			ft_putstr(list->result);
			ft_putstr(n);
		}
		ft_listnum2norme_x(list, n);
		free(list->result);
		return (1);
	}
	return (0);
}
