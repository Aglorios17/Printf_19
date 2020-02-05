/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:36:49 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_num12_2_2u(t_list *list, char *n, char *tmp, int i)
{
	if (list->num2 > ft_strlen2(list->result))
	{
		i = list->num2 - ft_strlen2(list->result);
		if (!(n = (char *)malloc(i + 1)))
			return ;
		if (list->starneg2)
		{
			if (list->zero)
				n = ft_strcpy2(n, '0', i);
			tmp = list->result;
			if (list->zero)
				list->result = ft_strjoin(n, tmp);
			else
				list->result = ft_strjoin(tmp, ft_strcpy2(n, ' ', i));
			free(tmp);
		}
		if (!list->starneg2)
		{
			tmp = list->result;
			n = ft_strcpy2(n, '0', i);
			list->result = ft_strjoin(n, tmp);
			free(tmp);
			free(n);
		}
	}
}

int		ft_num12_2_u(t_list *list, char *n, char *tmp, int i)
{
	if (list->num1 > list->num2 && list->num1 > ft_strlen2(list->result))
	{
		ft_num12_2_2u(list, n, tmp, i);
		i = list->num1 - ft_strlen(list->result);
		if (list->neg)
			i -= 1;
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		if ((list->zero && list->starneg2))
			n = ft_strcpy2(n, '0', i);
		else
			n = ft_strcpy2(n, ' ', i);
		tmp = list->result;
		if (list->negatif || list->starneg1)
			list->result = ft_strjoin(tmp, n);
		if (!list->negatif && !list->starneg1)
			list->result = ft_strjoin(n, tmp);
		free(tmp);
		free(n);
		return (1);
	}
	return (0);
}

void	ft_num12_3_2u(t_list *list, char *n, char *tmp, int i)
{
	if (list->num2 > ft_strlen2(list->result) && !list->starneg2)
	{
		i = list->num2 - ft_strlen2(list->result);
		if (!(n = (char *)malloc(i + 1)))
			return ;
		n = ft_strcpy2(n, '0', i);
		tmp = list->result;
		list->result = ft_strjoin(n, tmp);
		free(tmp);
		free(n);
	}
}

int		ft_num12_3_u(t_list *list, char *n, char *tmp, int i)
{
	ft_num12_3_2u(list, n, tmp, i);
	if (list->num1 > ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen2(list->result);
		if (list->neg)
			i -= 1;
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		if (list->zero)
			n = ft_strcpy2(n, '0', i);
		else
			n = ft_strcpy2(n, ' ', i);
		tmp = list->result;
		if (!list->starneg2 || list->negatif)
			list->result = ft_strjoin(tmp, n);
		if (list->starneg2 && !list->negatif)
			list->result = ft_strjoin(n, tmp);
		free(tmp);
		free(n);
		list->count = list->num1;
	}
	return (1);
}

int		ft_numneg12_u(t_list *list, char *n, char *tmp, int i)
{
	if (list->starneg1 && list->starneg2)
	{
		if (list->num1 < ft_strlen2(list->result))
			return (1);
		i = list->num1 - ft_strlen2(list->result);
		if (list->neg)
			i -= 1;
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		n = ft_strcpy2(n, ' ', i);
		tmp = list->result;
		list->result = ft_strjoin(tmp, n);
		free(n);
		free(tmp);
		return (1);
	}
	return (0);
}
