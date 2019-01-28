/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 14:38:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:49:22 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE	1
# define MAX_FD		150
# define PKMCHAR	'*'

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

/*
** List
*/

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

/*
********************************************************************************
**                                                       Fonction obligatoires *
********************************************************************************
*/

/*
** A
*/

int					ft_atoi(const char *str);

/*
** B
*/

void				ft_bzero(void *s, size_t n);

/*
** I
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int i);

/*
** L
*/

void				ft_lstadd(t_list **alst, t_list *nex);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** M
*/

void				*ft_memalloc(size_t c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t l);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t l);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t l);
void				*ft_memset(void *b, int c, size_t l);

/*
** P
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int n);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);

/*
** S
*/

char				*ft_strcat(char *dest, char *str);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *str);
void				ft_strdel(char **str);
char				*ft_strdup(const char *s);
int					ft_strequ(const char *s, const char *s1);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int i, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int i, char));
char				*ft_strncat(char *dest, char *str, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *str, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t i);
char				*ft_strnew(size_t l);
char				*ft_strnstr(const char *str, const char *tofind, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *str, const char *tofind);
char				*ft_strsub(char const *s, unsigned int i, size_t len);
char				*ft_strtrim(const char *s);

/*
** T
*/

int					ft_tolower(int c);
int					ft_toupper(int c);

/*
********************************************************************************
**                                                               Mes Fonctions *
********************************************************************************
*/

int					ft_chartotrim(char c);
int					get_next_line(int fd, char **line);
int					ft_intlen_base(int i, int base);
char				ft_inttochar(int i);
int					ft_isalldigit(char *str);
char				*ft_itoa_base(int i, int base);
void				ft_putnbr_base(int nb, int base);
void				ft_puttab2d(char **tab);
int					ft_split_elem_count(char **tab);
int					ft_strisalnum(char *str);
char				*ft_strjoinfree(char **s2, char *s1);
void				*ft_voidrev(void *s);
void				ft_voidswap(void *s, void *d);
void				ft_strsplit_free(char **tab);

/*
** Garbage collector addition
*/

# define GC_LIMIT 100

typedef struct		s_collector
{
	void			**ptr_array;
	short			*tag_array;
	int				size;
}					t_collector;

t_collector			*get_collector(void);
void				*gc_alloc(size_t size, short tag);
void				gc_add(void *ptr, short tag);
void				gc_error(char *error_msg);
void				gc_exit(int exit_sig);
void				gc_free(void *ptr, short tag);
void				gc_free_all(void);

#endif
