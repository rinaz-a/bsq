/*
** bsq.c for bsq in /home/rinaz_a/rendu/CPE_2015_bsq
** 
** Made by Selim RINAZ
** Login   <rinaz_a@epitech.net>
** 
** Started on  Thu Dec 10 10:22:51 2015 selim rinaz
** Last update Mon Dec 21 12:18:11 2015 
*/

#include "bsq.h"

int		put_my_nb_of_lines(char *buf, int idx)
{
  if (buf[idx] >= '0' && buf[idx] <= '9')
    {
      while (buf[idx] >= '0' && buf[idx] <= '9')
	{
	  my_putchar(buf[idx]);
	  idx = idx + 1;
	}
      my_putchar('\n');
    }
  return (idx);
}

void		create_tab_2d(char *buf, t_bsq *data, int x, int y)
{
  int		idx;

  if ((data->map = malloc(sizeof(char *) * data->lines)) == NULL)
    exit(EXIT_FAILURE);
  idx = 0;
  idx = put_my_nb_of_lines(buf, idx);
  while (buf[idx] != '\0')
    {
      if ((data->map[y] = malloc(sizeof(char) * data->cols)) == NULL)
	exit(EXIT_FAILURE);
      while (buf[idx] != '\n')
	{
	  data->map[y][x] = buf[idx];
	  idx = idx + 1;
	  x = x + 1;
	}
      data->map[y][x] = '\n';
      y = y + 1;
      x = 0;
      idx = idx + 1;
    }
  if ((data->map[y] = malloc(sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  data->map[y] = NULL;
}

int		first_fill(char c, int x, int y, t_bsq *data)
{
  if (c == '.')
    {
      //my_putchar('c');
      if (data->width < 1)
	{
	  data->width = 1;
	  data->XLUP = x;
	  data->YUP = y;
	}
      return (1);
    }
  else
    return (0);
}

int		second_fill(int x, int y, t_bsq *data)
{
  int		scan[4];
  int		idx;

  idx = 0;
  scan[0] = data->int_map[y][x - 1];
  scan[1] = data->int_map[y - 1][x - 1];
  scan[2] = data->int_map[y - 1][x];
  scan[3] = 2147483647;
  while (idx < 3)
    {
      if (scan[3] > scan[idx])
	scan[3] = scan[idx];
      idx = idx + 1;
    }
  scan[3] = scan[3] + 1;
  if (data->width < scan[3])
    {
      data->width = scan[3];
      data->XLUP = x - (scan[3] - 1);
      data->YUP = y - (scan[3] - 1);
    }
  return (scan[3]);
}

int		map_to_int(int x, int y, t_bsq *data)
{
  if (y == 0 || x == 0)
    return (first_fill(data->map[y][x], x, y, data));
  else if (data->map[y][x] == 'o' || data->map[y][x] == '\n')
    return (0);
  else
    return (second_fill(x, y, data));
}

void		create_int_2d(t_bsq *data)
{
  int		y;
  int		x;

  x = 0;
  y = 0;
  if ((data->int_map = malloc(sizeof(int *) * data->lines)) == NULL)
    exit(EXIT_FAILURE);
  while (x < data->cols && y < data->lines)
    {
      if ((data->int_map[y] = malloc(sizeof(int) * data->cols)) == NULL)
	exit(EXIT_FAILURE);
      while (x < data->cols)
	{
	  data->int_map[y][x] = map_to_int(x, y, data);
	  x = x + 1;
	}
      y = y + 1;
      x = 0;
    }
}

void		lines_counter(char *str, t_bsq *data)
{
  int		i;

  i = 0;
  data->lines = 0;
  data->cols = 0;
  while (str[i] != '\0')
    {
      while (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      if (str[i] == '\n' && str[i + 1] != '\0')
	{
	  data->cols = 0;
	  data->lines = data->lines + 1;
	}
      data->cols = data->cols + 1;
      i = i + 1;
    }
  data->cols = data->cols - 1;
}

void		put_my_square(t_bsq *data)
{
  int y;
  int x;

  x = data->XLUP;
  y = data->YUP;
  if (data->width == 1)
    data->map[y][x] = 'x';
  else
    while (x < (data->XLUP + data->width) && y < (data->YUP + data->width))
      {
	while (x < (data->XLUP + data->width))
	  {
	    data->map[y][x] = 'x';
	    x = x + 1;
	  }
	y = y + 1;
	x = data->XLUP;
      }
}

void		bsq(char *pathname)
{
  struct stat	sb;
  t_bsq		*data;
  int		filedesc;
  char		*buf;
  int		verif;
  char		**map;
  
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
  lines_counter(buf, data);
  create_tab_2d(buf, data, 0, 0);
  create_int_2d(data);
  /*
    int y = 0;
    int x = 0;
    while (x < data->cols && y < data->lines)
    {
    while (x < data->cols)
    {
    printf("%d", data->int_map[y][x]);
    x = x + 1;
    }
    printf("\n");
    y = y + 1;
    x = 0;
    }
    printf("%d x %d\n", data->XLUP, data->YUP);*/
  put_my_square(data);
  my_putstr_2d(data->map);
  if (close(filedesc) == -1);
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
