/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:33:18 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_num12_2_ii(t_list *list, char *tmp, char *n, int i)
{
	if (list->num2 >= list->num1 && list->num2 >= ft_strlen2(list->result))
	{
		if (list->num2 >= ft_strlen2(list->result) && !list->starneg2)
		{
			i = list->num2 - ft_strlen2(list->result);
			if (!(n = (char *)malloc(i + 1)))
				return (1);
			tmp = list->result;
			if (tmp[0] == '-')
			{
				list->neg = 1;
				tmp[0] = '0';
			}
			n = ft_strcpy2(n, '0', i);
			list->result = ft_strjoin(n, tmp);
			free(tmp);
			free(n);
		}
		ft_num12_23_ii(list, tmp, n, i);
		return (1);
	}
	return (0);
}

int		ft_num12_12_i(t_list *list, char *tmp, char *n, int i)
{
	if (list->zero && list->starneg2)
	{
		if (tmp[0] == '-')
		{
			list->neg = 1;
			tmp[0] = '0';
		}
		n = ft_strcpy2(n, '0', i);
	}
	else
		n = ft_strcpy2(n, ' ', i);
	if (ft_diffnegatif_ii(list, tmp, n))
		return (1);
	if (list->negatif)
		list->result = ft_strjoin(tmp, n);
	free(n);
	free(tmp);
	return (1);
}

void	ft_zeroneg(t_list *list, char *tmp)
{
	if (tmp[0] == '-')
	{
		list->neg = 1;
		tmp[0] = '0';
	}
}
