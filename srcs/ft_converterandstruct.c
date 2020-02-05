/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converterandstruct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:30:54 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:25:55 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_structinit(t_list *list)
{
	list->zero = 0;
	list->converter = 0;
	list->num1 = 0;
	list->num2 = 0;
	list->point = 0;
	list->negatif = 0;
	list->result = NULL;
	list->star1 = 0;
	list->starneg1 = 0;
	list->star2 = 0;
	list->starneg2 = 0;
	list->neg = 0;
	list->count = 0;
	list->n = 0;
}
