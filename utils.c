/*
** get_min.c for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
** 
** Made by Killian Gardahaut
** Login   <Killian.Gardahaut@epitech.net>
** 
** Started on  jeu. mai 11 22:23:52 2017 Killian Gardahaut
** Last update jeu. mai 11 22:23:52 2017 Killian Gardahaut
*/

char	*special(char *map)
{
  int	i;

  i = 0;
  while (map[i] != '\0')
  {
    if (map[i] == '.')
    {
      map[i] = 'x';
      return (map);
    }
    i++;
  }
  return (map);
}

int	get_min(int a, int b, int c)
{
  int	smallest;

  smallest = a;
  if (smallest > b)
    smallest = b;
  if (smallest > c)
    smallest = c;
  return (smallest);
}
