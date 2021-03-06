/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:36 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/24 03:22:24 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct		s_list1
{
	void			*content;
	struct s_list1	*next;
}					t_list1;

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strcat(char *dest, char const *src);
char				*ft_protect(void);
t_list1				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list1 **alst, t_list1 *new);
int					ft_lstsize(t_list1 *lst);
t_list1				*ft_lstlast(t_list1 *lst);
void				ft_lstdelone(t_list1 *lst, void (*del)(void*));
void				ft_lstclear(t_list1 **lst, void (*del)(void*));
void				ft_lstiter(t_list1 *lst, void (*f)(void *));
char				*ft_vide(void);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
void				ft_putchar(char c);
void				ft_swap(int *a, int *b);
void				ft_putstr(char *str);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strstr(char *str, char *to_find);
int					ft_get_next_line(int fd, char **line);
char				*ft_strndup(const char *s1, size_t n);
int					ft_line(int fd, char **line, char **str);
int					ft_read(int fd, char **line);
char				*ft_strchrgnl(const char *s, int c);

#endif
