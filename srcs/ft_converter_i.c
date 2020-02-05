/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:14:28 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int		ft_num12_1_i(t_list *list, char *tmp, char *n, int i)
{
	if (list->num1 > list->num2 && list->num1 > ft_strlen2(list->result))
	{
		ft_num12_1_ii(list, i, n, tmp);
		i = list->num1 - ft_strlen2(list->result);
		if (list->neg)
		{
			tmp = list->result;
			list->result = ft_strjoin("-", tmp);
			list->neg = 0;
			free(tmp);
			i -= 1;
		}
		tmp = list->result;
		if (tmp[0] == '-' && list->zero && list->starneg2)
			i -= 1;
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		if (ft_num12_12_i(list, tmp, n, i))
			return (1);
	}
	return (0);
}

static	int		ft_listnum12_1_i(t_list *list)
{
	int		i;
	char	*n;
	char	*tmp;

	i = 0;
	n = 0;
	tmp = 0;
	if (ft_liststarneg12_ii(list))
		return (0);
	if (list->num1 && list->num2 && list->num1 > list->num2)
	{
		if (ft_num12_1_i(list, tmp, n, i))
			return (0);
		return (0);
	}
	if (list->num1 && list->num2 && list->num1 <= list->num2)
		if (ft_num12_2_ii(list, tmp, n, i))
			return (0);
	return (0);
}

static	int		ft_choice_i(t_list *list)
{
	if (!list->num1 && !list->num2)
	{
		ft_putstr(list->result);
		list->count = ft_strlen2(list->result);
		free(list->result);
		return (1);
	}
	if (ft_listnum1_i(list))
		return (1);
	if (ft_listnum2_i(list))
		return (1);
	if (ft_listnum12_1_i(list))
		return (1);
	return (0);
}

static	int		ft_point_i(t_list *list, int id, char *n)
{
	if (list->point && !list->num2)
	{
		if (list->num1 && list->result[0] == '0')
		{
			free(list->result);
			id = list->num1;
			if (!(list->result = ft_strcpy2((char *)malloc(id + 1), ' ', id)))
				return (1);
			ft_putstr(list->result);
			free(n);
			list->count = list->num1;
			free(list->result);
			return (1);
		}
		if (!list->num1 && list->result[0] == '0')
		{
			free(list->result);
			list->result = "";
			ft_putstr(list->result);
			list->count = 0;
			return (1);
		}
	}
	return (0);
}

int				ft_converter_i(va_list pa, t_list *list)
{
	int		id;
	char	*n;

	n = 0;
	id = va_arg(pa, int);
	free(list->result);
	list->result = ft_itoa(id);
	if (ft_point_i(list, id, n))
		return (0);
	if (ft_choice_i(list))
		return (0);
	ft_putstr(list->result);
	list->count = ft_strlen(list->result);
	free(list->result);
	return (0);
}
