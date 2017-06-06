/*
** my_putchar.c for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
** 
** Made by Killian Gardahaut
** Login   <Killian.Gardahaut@epitech.net>
** 
** Started on  jeu. mai 11 23:38:47 2017 Killian Gardahaut
** Last update jeu. mai 11 23:38:47 2017 Killian Gardahaut
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
