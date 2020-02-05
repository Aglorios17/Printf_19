/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:34:21 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:36:12 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef	struct	s_list
{
	char		*result;
	char		converter;
	int			negatif;
	int			zero;
	int			num1;
	int			num2;
	int			point;
	int			neg;
	int			star1;
	int			star2;
	int			starneg1;
	int			starneg2;
	int			n;
	int			count;
}				t_list;

typedef	struct	s_flag
{
	int			r;
	int			a;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*ft_utoa_base(size_t n, size_t base, t_list *list);
char			*ft_ltoa_base(unsigned long long n);
char			*ft_charconverter(char c);
int				ft_flagcheck(const char *format, int i, t_list *list,
		va_list pa);
void			ft_structinit(t_list *list);
char			*ft_strcpy2(char *dest, int c, size_t n);
void			ft_star(t_list *list, va_list pa);
int				ft_strlen2(const char *str);
void			ft_scut(t_list *list);
void			ft_zeroneg(t_list *list, char *tmp);

int				ft_converter(va_list pa, t_list *list, const char *format);

int				ft_converter_s(va_list pa, t_list *list);
int				ft_norme1_s(t_list *list);
int				ft_norme2_s(t_list *list, char *n, int i, char *tmp);
int				ft_point_s(t_list *list, char *n, int i);
int				ft_point2_s(t_list *list, char *n);
int				ft_num12_1_s(t_list *list, char *n, int i, char *tmp);
int				ft_num12_2_s(t_list *list, char *n, int i, char *tmp);
int				ft_num1_point_s(t_list *list, char *n, int i);

int				ft_converter_c(va_list pa, t_list *list);

int				ft_converter_i(va_list pa, t_list *list);
int				ft_listnum1_i(t_list *list);
int				ft_listnum2_i(t_list *list);
void			ft_num12_1_ii(t_list *list, int i, char *n, char *tmp);
int				ft_liststarneg12_ii(t_list *list);
int				ft_diffnegatif_ii(t_list *list, char *tmp, char *n);
void			ft_num12_22_ii(t_list *list, char *tmp, char *n, int i);
void			ft_num12_23_ii(t_list *list, char *tmp, char *n, int i);
int				ft_num12_2_ii(t_list *list, char *tmp, char *n, int i);
int				ft_num12_12_i(t_list *list, char *tmp, char *n, int i);

int				ft_converter_x(va_list pa, t_list *list);
int				ft_listnum1_x(t_list *list);
int				ft_listnum2_x(t_list *list);
void			ft_num2neg(t_list *list);
int				ft_norme12_1_x(t_list *list, char *n, char *tmp, int i);
int				ft_norme12_2_x(t_list *list, char *n, char *tmp, int i);
void			ft_norme12_3_1x(t_list *list, char *n, char *tmp, int i);
int				ft_norme12_3_x(t_list *list, char *n, char *tmp, int i);
int				ft_listnum12_1_x(t_list *list);
int				ft_norme1_2x(t_list *list);
int				ft_norme1_3x(t_list *list, char *n, int i);
void			ft_norme1_4x(t_list *list, char *n, int i);
int				ft_norme1_x(t_list *list, char *n, int i);
int				ft_norme2_2x(t_list *list, char *n);
int				ft_norme2_3x(t_list *list, char *n);
void			ft_norme12_11_x(t_list *list, char *n, char *tmp);
void			ft_norme2_22x(t_list *list, char *n);
void			ft_norme1_33x(t_list *list, char *n);

int				ft_converter_u(va_list pa, t_list *list);
int				ft_listnum1_u(t_list *list);
int				ft_listnum2_u(t_list *list);
void			ft_num12_2_2u(t_list *list, char *n, char *tmp, int i);
int				ft_num12_2_u(t_list *list, char *n, char *tmp, int i);
void			ft_num12_3_2u(t_list *list, char *n, char *tmp, int i);
int				ft_num12_3_u(t_list *list, char *n, char *tmp, int i);
int				ft_numneg12_u(t_list *list, char *n, char *tmp, int i);
int				ft_listnum12_1_u(t_list *list);
void			ft_norme1_u(t_list *list, char *n, int i, int a);
int				ft_norme2_2u(t_list *list);

int				ft_converter_p(va_list pa, t_list *list);

int				ft_converter_modulo(t_list *list);
void			ft_norme1_p(t_list *list, char *n);
void			ft_norme2_p(t_list *list, char *tmp, char *n, char *tmp2);
void			ft_norme3_p(t_list *list, char *n);

#endif
