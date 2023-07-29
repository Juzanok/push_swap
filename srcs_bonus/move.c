/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:25:23 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:30:06 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	move(t_stack **stack, int moves)
{
	if (moves == 1)
		do_switch(stack, 'a');
	else if (moves == 11)
		do_switch(stack, 'b');
	else if (moves == 111)
	{
		do_switch(stack, 'a');
		do_switch(stack, 'b');
	}
	else if (moves == 2)
	{
		if ((*stack)->size_a != 0)
			do_rotate(stack, 'a');
	}
	else if (moves == 22)
	{
		if ((*stack)->size_b != 0)
			do_rotate(stack, 'b');
	}
	else
		move_extra(stack, moves);
}

void	move_extra(t_stack **stack, int moves)
{
	if (moves == 222)
	{
		do_rotate(stack, 'a');
		do_rotate(stack, 'b');
	}
	else if (moves == 3)
	{
		if ((*stack)->size_a != 0)
			do_reverse_rotate(stack, 'a');
	}
	else if (moves == 33)
	{
		if ((*stack)->size_b != 0)
			do_reverse_rotate(stack, 'b');
	}
	else if (moves == 333)
	{
		do_reverse_rotate(stack, 'a');
		do_reverse_rotate(stack, 'b');
	}
	else if (moves == 4)
		do_push_a(stack);
	else if (moves == 44)
		do_push_b(stack);
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
