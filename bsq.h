//
// bsq.h for CPE_2016_BSQ in /home/gardah_k/Semester1/c_prog_elem/CPE_2016_BSQ
// 
// Made by Killian Gardahaut
// Login   <Killian.Gardahaut@epitech.net>
// 
// Started on  jeu. mai 11 21:22:30 2017 Killian Gardahaut
// Last update jeu. mai 11 21:22:30 2017 Killian Gardahaut
//

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_size
{
  int	nb_columns;
  int	nb_lines;
}	t_size;

char	*special(char *);
int	*bomb(int *, t_size *, char *);
void	my_putchar(char);
void	print_map(char *, t_size *);
void	modify_map(char *, int *, t_size *);
int	get_min(int, int, int);
t_size	*set_size(char *);

#endif /* !BSQ_H_ */
