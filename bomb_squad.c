/*
** bomb_squad.c for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
** 
** Made by Killian Gardahaut
** Login   <Killian.Gardahaut@epitech.net>
** 
** Started on  jeu. mai 11 22:28:45 2017 Killian Gardahaut
** Last update jeu. mai 11 22:28:45 2017 Killian Gardahaut
*/

#include "bsq.h"

int	*bomb(int *map, t_size *size, char *buff)
{
  int	i;

  i = size->nb_columns + 2;
  while (map[i] != -84)
  {
    if (map[i] != -1 && map[i - 1] != -1 && buff[i] != 'o')
      map[i] = get_min(map[i - 1], map[i - size->nb_columns - 1],
	  map[i - size->nb_columns - 2]) + 1;
    i++;
  }
  modify_map(buff, map, size);
  return (map);
}

int	get_max_pos(int *map)
{
  int	i;
  int	max;

  i = 1;
  max = 0;
  while (map[i] != -84)
  {
    if (map[i] > map[max])
      max = i;
    i++;
  }
  return (max);
}

void	modify_map(char *buff, int *map, t_size *size)
{
  int	i;
  int	j;
  int	max_pos;
  int	max_value;

  max_pos = get_max_pos(map);
  max_value = map[max_pos];
  j = 0;;
  while (j != max_value)
  {
    i = 0;
    while (i != max_value)
    {
      buff[max_pos - i - (j * size->nb_columns) - j] = 'x';
      i++;
    }
    j++;
  }
  print_map(buff, size);
}
