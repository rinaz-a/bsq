/*
** goto_int_2d.c for goto_int_2d in /home/rinaz_a/rendu/CPE_2015_BSQ
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Mon Dec 21 22:09:42 2015 selim rinaz
** Last update Mon Dec 21 22:13:25 2015 
*/

#include "bsq.h"

int		first_fill(char c, int x, int y, t_bsq *data)
{
  if (c == '.')
    {
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

void		put_my_square(t_bsq *data)
{
  int		y;
  int		x;

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
