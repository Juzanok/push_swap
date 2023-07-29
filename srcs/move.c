/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:16:37 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:44 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move(t_stack *stack, char *moves)
{
	ft_printf("%s\n", moves);
	if (ft_strcmp(moves, "sa"))
		do_switch(stack, 'a');
	else if (ft_strcmp(moves, "sb"))
		do_switch(stack, 'b');
	else if (ft_strcmp(moves, "ss"))
	{
		do_switch(stack, 'a');
		do_switch(stack, 'b');
	}
	else if (ft_strcmp(moves, "ra"))
		do_rotate(stack, 'a');
	else if (ft_strcmp(moves, "rb"))
		do_rotate(stack, 'b');
	else if (ft_strcmp(moves, "rr"))
	{
		do_rotate(stack, 'a');
		do_rotate(stack, 'b');
	}
	else
		move_extra(stack, moves);
}

void	move_extra(t_stack *stack, char *moves)
{
	if (ft_strcmp(moves, "rra"))
		do_reverse_rotate(stack, 'a');
	else if (ft_strcmp(moves, "rrb"))
		do_reverse_rotate(stack, 'b');
	else if (ft_strcmp(moves, "rrr"))
	{
		do_reverse_rotate(stack, 'a');
		do_reverse_rotate(stack, 'b');
	}
	else if (ft_strcmp(moves, "pa"))
		do_push_a(stack);
	else if (ft_strcmp(moves, "pb"))
		do_push_b(stack);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0' && s2[i] == '\0')
		return (0);
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	push_a_extra(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
}

void	push_b_extra(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
}
