/*
** bsq.h for bsq in /home/rinaz_a/rendu/CPE_2015_bsq
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Mon Dec 14 17:25:12 2015 selim rinaz
** Last update Mon Dec 21 22:16:18 2015 
*/

#ifndef BSQ_H_
# define BSQ_H_
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_bsq
{
  int		lines;
  int		cols;
  char		**map;
  int		**int_map;
  int		XLUP;
  int		YUP;
  int		width;
}		t_bsq;

void		bsq(char *pathname);
int		main(int ac, char **av);
void		my_putstr_2d(char **str);
int		my_strlen(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterr(char *str);
void		put_my_square(t_bsq *data);
void		lines_counter(char *str, t_bsq *data);
void		create_int_2d(t_bsq *data);
int		map_to_int(int x, int y, t_bsq *data);
int		second_fill(int x, int y, t_bsq *data);
int		first_fill(char c, int x, int y, t_bsq *data);
void		create_tab_2d(char *buf, t_bsq *data, int x, int y);
void		check_map(char *buf);

#endif /* !BSQ_H_ */
