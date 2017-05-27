/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:32:24 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/01 18:42:48 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 15
# define TETRIS  fillit->tetris
# define MAP	 fillit->map

typedef struct		s_fillit
{
	size_t			count;
	int				map_size;
	char			***tetris;
	char			**map;
}					t_fillit;

int					ft_check(char *file, t_fillit *fillit);
int					ft_put_tetrim(t_fillit *fillit, int tetrim, int x, int y);
int					ft_fillit(t_fillit *fillit, int tetrim, int x, int y);
int					ft_resolve(t_fillit *fillit);
void				ft_putendl(char const *s);
void				ft_clean_map(char **map, int size, char c);
void				ft_free_map(char **map, int size);
void				ft_fill_map(int size, char **map);
char				**ft_create_map(int size);
int					ft_get_line(char **tetrim);
int					ft_isalpha(int c);
int					ft_get_col(char **tetrim);
int					ft_split_tetrim(char *map, t_fillit *tetrim, size_t count);
int					check_tetris(char *map);
int					check_map(char *map, int i, int j);
char				*read_map(char *av);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *dst, const char *src);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strcpy(char *dst, const char *src);
void				ft_push_top(char **tetrim);
void				ft_push_left(char **tetrim);
void				ft_put_letter(char **tetrim, char letter);
void				ft_clear_fillit(t_fillit *fillit);
void				ft_print(t_fillit *fillit);

#endif
