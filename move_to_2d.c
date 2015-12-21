/*
** move_to_2d.c for move_to_2d in /home/rinaz_a/rendu/CPE_2015_BSQ
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Mon Dec 21 22:07:48 2015 selim rinaz
** Last update Mon Dec 21 22:15:30 2015 
*/

#include "bsq.h"

void		create_tab_2d(char *buf, t_bsq *data, int x, int y)
{
  int		idx;

  if ((data->map = malloc(sizeof(char *) * data->lines)) == NULL)
    exit(EXIT_FAILURE);
  idx = 0;
  while (buf[idx] != '\0')
    {
      if ((data->map[y] = malloc(sizeof(char) * data->cols)) == NULL)
	exit(EXIT_FAILURE);
      while (buf[idx] != '\n' && buf[idx] != '\0')
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

void		check_map(char *buf)
{
  int		idx;

  idx = 0;
  while (buf[idx] != '\n')
    {
      if (buf[idx] <= '0' && buf[idx] >= '9')
	{
	  my_puterr("number of lines is missing\n");
	  exit(EXIT_FAILURE);
	}
      idx = idx + 1;
    }
  while (buf[idx] != '\0')
    {
      if (buf[idx] != '.' && buf[idx] != 'o'
	  && buf[idx] != '\n' && buf[idx] != '\0')
	{
	  my_puterr("invalid map\n");
	  exit(EXIT_FAILURE);
	}
      idx = idx + 1;
    }
}
