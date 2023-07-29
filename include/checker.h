/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:20:13 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:34 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct t_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

// checker.c
int				main(int argc, char **argv);
void			free_stacks(t_stack *stack);
void			print_result(int i);

// get_stack.c
int				get_stack(t_stack **stack, int size, char **a);
int				check_sorted(t_stack *stack);
int				check_stack(int size, char **a);
int				check_duplicates(int *a, int size);
long long int	ft_atoi_new(const char *nptr);

// move.c
void			move(t_stack **stack, int moves);
void			move_extra(t_stack **stack, int moves);
void			push_a_extra(t_stack *stack);
void			push_b_extra(t_stack *stack);

// move_rules.c
void			do_switch(t_stack **stack, char array);
void			do_rotate(t_stack **stack, char array);
void			do_reverse_rotate(t_stack **stack, char array);
void			do_push_a(t_stack **stack);
void			do_push_b(t_stack **stack);

// move_read.c
char			*read_move(void);
char			*ft_new_save(char *save);
char			*ft_get_line(char *save);
char			*ft_read(int fd, char *save);
char			*ft_join(char *s1, char *s2);

// do_moves.c
int				do_moves(t_stack **stack);
int				get_move(char *str);
int				ft_strcmp(const char *s1, const char *s2);

#endif