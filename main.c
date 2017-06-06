/*
** main.c for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
** 
** Made by Killian Gardahaut
** Login   <Killian.Gardahaut@epitech.net>
** 
** Started on  mar. mai 09 11:34:16 2017 Killian Gardahaut
** Last update mar. mai 09 11:34:16 2017 Killian Gardahaut
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	print_map(char *map, t_size *size)
{
  int	size_real;

  size_real = (size->nb_columns + 1) * size->nb_lines;
  write(1, map, size_real);
}

char	*rm_firstline(char *str)
{
  while (str[0] != '\n')
    str++;
  str++;
  return (str);
}

char		*read_file(char *name)
{
  int		fd;
  char		*buffer;
  struct stat	info;

  if ((stat(name, &info)) == -1)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * info.st_size + 1)) == NULL)
    return (NULL);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  read(fd, buffer, info.st_size);
  buffer[info.st_size] = 0;
  close(fd);
  buffer = rm_firstline(buffer);
  return (buffer);
}

int	*convert(char *buff, t_size *size)
{
  int	i;
  int	*map;

  map = malloc(((size->nb_columns + 1) * size->nb_lines + 1) * sizeof(int));
  map[0] = 0;
  i = 0;
  while (buff[i] != 0)
  {
    map[i] = 0;
    if (i < size->nb_columns)
      if (buff[i] == '.')
	map[i] = 1;
    if (buff[i] == '\n')
    {
      map[i] = -1;
      if (buff[i + 1] == '.')
	map[++i] = 1;
    }
   i++;
  }
  map[i] = -84;
  return (map);
}

int		main(int ac, char **av)
{
  char		*buff;
  t_size	*size;

  if (ac <= 1)
    exit(84);
  buff = read_file(av[1]);
  size = set_size(buff);
  bomb(convert(buff, size), size, buff);
}
