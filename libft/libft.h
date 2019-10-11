/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:21:00 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/10 16:12:28 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# define BUFF_SIZE 7

typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		s_buff_h
{
	int					fd;
	char				*lost;
}					t_buff_h;

typedef struct		s_room
{
	void			*addr;
	struct s_room	*next;
}					t_room;

typedef struct		s_mem
{
	t_room			**full_stack;
	t_room			**temp;
}					t_mem;

typedef struct		s_g
{
	void	*env;
	t_mem	*mem;
}					t_g;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				*ft_memset(void	*b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack
					, const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(t_g *grh, char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
int					ft_whitespace(char c);
void				*ft_alloc(t_mem *mem, size_t t);
void				*ft_alloc_t(t_mem *mem, size_t t);
void				ft_free(t_mem *mem, void *addr);
void				ft_free_t(t_mem *mem, void *addr);
t_room				*in_room(void *addr);
void				link_to_stack(t_mem *mem, t_room *room, int pass);
void				free_addr(t_room *room);
void				free_stack_t(t_mem *mem);
void				free_stack(t_mem *mem);
void				ft_error(t_mem *mem);
t_g					*init_env(void);
void				on_error_exit(void);
char				*ft_to_stack(t_g *g, char *str);
int					ft_strfind(char *str, char c);
char				*cut_until(t_g *g, char *str, int n, int pass);
char				*get_text(t_g *g, int fd, int size);
char				int_to_hex(int n);
void				print_hex(char *str, int size);
int					ft_isnum(char *str);

#endif
