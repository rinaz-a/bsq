/*
** bsq.c for bsq in /home/rinaz_a/rendu/CPE_2015_bsq
** 
** Made by Selim RINAZ
** Login   <rinaz_a@epitech.net>
** 
** Started on  Thu Dec 10 10:22:51 2015 selim rinaz
** Last update Mon Dec 21 22:33:09 2015 
*/

#include "bsq.h"

void		bsq(char *pathname)
{
  struct stat	sb;
  t_bsq		*data;
  int		filedesc;
  char		*buf;
  int		verif;
  
  if (stat(pathname, &sb) == -1)
    exit(EXIT_FAILURE);
  if ((buf = malloc(sb.st_size)) == NULL)
    exit(EXIT_FAILURE);
  if ((data = malloc(sizeof(t_bsq))) == NULL)
    exit(EXIT_FAILURE);
  if ((filedesc = open(pathname, O_RDWR)) == -1)
    exit(EXIT_FAILURE);
  if ((verif = read(filedesc, buf, sb.st_size)) == -1)
    exit(EXIT_FAILURE);
  check_map(buf);
  lines_counter(buf, data);
  create_tab_2d(buf, data, 0, 0);
  create_int_2d(data);
  put_my_square(data);
  my_putstr_2d(data->map);
  if (close(filedesc) == -1)
    exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    bsq(av[1]);
  else
    my_puterr("usage : ./bsq <map file>\n");
  return (0);
}
