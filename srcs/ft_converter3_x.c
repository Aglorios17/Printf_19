/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:48:47 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_norme12_1_x(t_list *list, char *n, char *tmp, int i)
{
	if (list->num2 >= list->num1 && list->num2 > ft_strlen2(list->result))
	{
		if (list->starneg2 && list->num1 < ft_strlen2(list->result))
			return (1);
		if (list->num2 > ft_strlen2(list->result))
		{
			if (list->starneg2)
				i = list->num1 - ft_strlen2(list->result);
			else
				i = list->num2 - ft_strlen2(list->result);
			if (!(n = (char *)malloc(i + 1)))
				return (1);
			if (list->starneg2 && !list->zero)
				n = ft_strcpy2(n, ' ', i);
			if (!list->starneg2 || list->zero)
				n = ft_strcpy2(n, '0', i);
			tmp = list->result;
			ft_norme12_11_x(list, n, tmp);
			free(tmp);
			free(n);
		}
	}
	return (0);
}

int		ft_norme12_2_x(t_list *list, char *n, char *tmp, int i)
{
	if (list->starneg1 && list->starneg2)
	{
		if (list->num1 < ft_strlen2(list->result))
			return (1);
		i = list->num1 - ft_strlen2(list->result);
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		n = ft_strcpy2(n, ' ', i);
		tmp = list->result;
		list->result = ft_strjoin(tmp, n);
		list->count = list->num1;
		free(tmp);
		free(n);
		return (1);
	}
	return (0);
}

void	ft_norme12_3_1x(t_list *list, char *n, char *tmp, int i)
{
	if (list->num2 > ft_strlen2(list->result))
	{
		i = list->num2 - ft_strlen2(list->result);
		if (!(n = (char *)malloc(i + 1)))
			return ;
		tmp = list->result;
		if (list->starneg2 && !list->zero)
		{
			n = ft_strcpy2(n, ' ', i);
			list->result = ft_strjoin(tmp, n);
		}
		if (!list->starneg2 || list->zero)
		{
			n = ft_strcpy2(n, '0', i);
			list->result = ft_strjoin(n, tmp);
		}
		free(tmp);
		free(n);
	}
}

int		ft_norme12_3_x(t_list *list, char *n, char *tmp, int i)
{
	if (list->num1 > list->num2 && list->num1 > ft_strlen2(list->result))
	{
		ft_norme12_3_1x(list, n, tmp, i);
		i = list->num1 - ft_strlen2(list->result);
		if (list->neg)
			i -= 1;
		if (!(n = (char *)malloc(i + 1)))
			return (1);
		if ((list->starneg2 && list->zero))
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
		list->count = list->num1;
		return (1);
	}
	return (0);
}

int		ft_listnum12_1_x(t_list *list)
{
	int		i;
	char	*n;
	char	*tmp;

	i = 0;
	n = 0;
	tmp = 0;
	if (ft_norme12_2_x(list, n, tmp, i))
		return (0);
	if (list->num1 && list->num2 && list->num1 > list->num2)
		if (ft_norme12_3_x(list, n, tmp, i))
			return (0);
	if (list->num1 && list->num2 && list->num1 <= list->num2)
		if (ft_norme12_1_x(list, n, tmp, i))
		{
			list->count = list->num1;
			return (0);
		}
	return (0);
}
