/*
** bsq.h for bsq in /home/rinaz_a/rendu/CPE_2015_bsq
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Mon Dec 14 17:25:12 2015 selim rinaz
** Last update Sat Dec 19 16:40:43 2015 
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

#endif /* !BSQ_H_ */
