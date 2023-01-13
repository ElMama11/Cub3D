/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:36:01 by mverger           #+#    #+#             */
/*   Updated: 2022/11/24 04:25:23 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef OPEN_MAX
#  define OPEN_MAX 1000
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *hay, const char *nee, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ft_printf */

int		ft_putnbrr(int n);
int		ft_putcharr(int c);
int		ft_putstr(char *s);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_convert_low_hexa(unsigned int n);
int		ft_convert_upper_hexa(unsigned int n);
int		ft_convert_ptr(unsigned long n);
int		ft_printf(const char *format, ...);
int		check_type(char c, int counter, va_list args);

/* Custom funcs */

size_t	ft_tablen(char **tab);
void	ft_free_tab(char **tab);
void	*ft_memallocexit(size_t size);
long	ft_atol(const char *str);
t_list	*ft_lstsecondlast(t_list *lst);
int		ft_strstr(char *str, char *to_find);

/*		GET NEXT LINE		*/
void			*ft_memmove_gnl(char *dest, char *src, int n);
int				ft_strlen2(const char *s);
char			*ft_strjoin_gnl(char *s1, char *s2, int size);
void			buf_mem_move(char *buf, char *c);
char			*read_buf(char *buf);
char			*str_fill(char *buf, char *str, int fd);
char			*get_next_line(int fd);

#endif