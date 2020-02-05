/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:33:40 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_num12_1_ii(t_list *list, int i, char *n, char *tmp)
{
	if (list->num2 >= ft_strlen2(list->result) && !list->starneg2)
	{
		i = list->num2 - ft_strlen2(list->result);
		tmp = list->result;
		if (tmp[0] == '-')
		{
			list->neg = 1;
			tmp[0] = '0';
		}
		if (!(n = (char *)malloc(i + 1)))
			return ;
		n = ft_strcpy2(n, '0', i);
		list->result = ft_strjoin(n, tmp);
		free(tmp);
		free(n);
	}
}

int		ft_liststarneg12_ii(t_list *list)
{
	char	*n;
	int		i;
	char	*tmp;

	n = 0;
	i = 0;
	tmp = 0;
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

int		ft_diffnegatif_ii(t_list *list, char *tmp, char *n)
{
	if (!list->negatif)
	{
		if (list->starneg1)
			list->result = ft_strjoin(tmp, n);
		else
			list->result = ft_strjoin(n, tmp);
		free(n);
		free(tmp);
		if (!list->starneg1 && list->neg)
		{
			tmp = list->result;
			list->result = ft_strjoin("-", tmp);
			free(tmp);
		}
		return (1);
	}
	return (0);
}

void	ft_num12_22_ii(t_list *list, char *tmp, char *n, int i)
{
	if (tmp[0] == '-' && !list->negatif)
		i -= 1;
	if (list->zero)
	{
		ft_zeroneg(list, tmp);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return ;
	}
	if (!list->zero)
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return ;
	if (list->zero && list->starneg2)
		list->result = ft_strjoin(n, tmp);
	else
		list->result = ft_strjoin(tmp, n);
	free(tmp);
	free(n);
	if (list->neg)
	{
		tmp = list->result;
		list->result = ft_strjoin("-", tmp);
		free(tmp);
	}
}

void	ft_num12_23_ii(t_list *list, char *tmp, char *n, int i)
{
	if (list->neg)
	{
		tmp = list->result;
		list->result = ft_strjoin("-", tmp);
		free(tmp);
		i -= 1;
	}
	if (list->num1 > ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen2(list->result);
		tmp = list->result;
		ft_num12_22_ii(list, tmp, n, i);
	}
}
