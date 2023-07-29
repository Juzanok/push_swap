/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:37:50 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:37 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct t_stack
{
	int	*a;
	int	*b;
	int	*lis;
	int	size_a;
	int	size_b;
	int	size_lis;
}	t_stack;

// push_swap.c
int				main(int argc, char **argv);
void			free_stacks(t_stack *stack);

// stack_get.c
int				get_stack(t_stack **stack, int size, char **a);
int				check_stack(int size, char **a);
int				pre_check(t_stack *stack);
long long int	ft_atoi_new(const char *nptr);
int				check_duplicates(int *a, int size);

// move.c
void			move(t_stack *stack, char *moves);
void			move_extra(t_stack *stack, char *moves);
int				ft_strcmp(const char *s1, const char *s2);
void			push_a_extra(t_stack *stack);
void			push_b_extra(t_stack *stack);

// move_rules.c
void			do_switch(t_stack *stack, char array);
void			do_rotate(t_stack *stack, char array);
void			do_reverse_rotate(t_stack *stack, char array);
void			do_push_a(t_stack *stack);
void			do_push_b(t_stack *stack);

// sort.c
void			sort(t_stack *stack);
void			very_small_sort(t_stack *stack);
void			small_sort(t_stack *stack);
void			big_sort(t_stack *stack);

//sort_utils.c
int				find_biggest(int *a, int size);
int				find_smallest(int *a, int size);
void			put_top_a(t_stack *stack, int value);
void			clear_lis(t_stack *stack);

// sort_big.c
int				*find_best(t_stack *stack);
int				best_1(int *a, int size, int value);
int				best_2(int *b, int size, int value);
int				best_compare(int *arr);

// sort_big_utils.c
void			get_lis(t_stack *stack);
void			take_lis(t_stack *stack, int *a, int size);
void			save_lis(t_stack *stack, int *arr, int *lis, int len);
void			get_lis_array(t_stack *stack, int *arr, int *lis, int pos);
void			rotate(int *a, int size);

// smart_rotate.s
void			push_best(t_stack *stack, int *best);
void			finish_push_best(t_stack *stack, int *best);

#endif