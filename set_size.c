/*
** set_size.c for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
** 
** Made by Killian Gardahaut
** Login   <Killian.Gardahaut@epitech.net>
** 
** Started on  jeu. mai 11 21:23:42 2017 Killian Gardahaut
** Last update jeu. mai 11 21:23:42 2017 Killian Gardahaut
*/

#include <stdlib.h>
#include "bsq.h"

void	check(t_size *size, char *map)
{
  if (size->nb_columns == 1 || size->nb_lines == 1)
  {
    print_map(special(map), size);
    exit(84);
  }
}

t_size		*set_size(char *map)
{
  t_size	*size;
  int		i;
  int		columns;
  int		lines;

  if ((size = malloc(sizeof(t_size))) == NULL)
    return (NULL);
  i = 0;
  columns = 0;
  lines = 0;
  while (map[i] != 0)
  {
    if (map[i] == '\n')
      lines++;
    if (lines == 0)
      columns++;
    i++;
  }
  size->nb_columns = columns;
  size->nb_lines = lines;
  check(size, map);
  return (size);
}
