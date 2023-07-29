/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:45:35 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:54 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack *stack)
{
	if (stack->size_a == 2)
		move(stack, "sa");
	else if (stack->size_a == 3)
		very_small_sort(stack);
	else if (stack->size_a <= 5)
		small_sort(stack);
	else
		big_sort(stack);
}

void	very_small_sort(t_stack *stack)
{
	int	big;

	big = find_biggest(stack->a, stack->size_a);
	if (stack->a[0] == big)
	{
		move(stack, "ra");
		if (stack->a[0] > stack->a[1])
			move(stack, "sa");
	}
	else if (stack->a[1] == big)
	{
		move(stack, "rra");
		if (stack->a[0] > stack->a[1])
			move(stack, "sa");
	}
	else
	{
		if (stack->a[0] > stack->a[1])
			move(stack, "sa");
	}
}

void	small_sort(t_stack *stack)
{
	while (stack->size_a != 3)
	{
		put_top_a(stack, find_smallest(stack->a, stack->size_a));
		move(stack, "pb");
	}
	very_small_sort(stack);
	while (stack->size_b != 0)
		move(stack, "pa");
}

void	big_sort(t_stack *stack)
{
	int	*best;

	clear_lis(stack);
	while (stack->size_b != 0)
	{
		best = find_best(stack);
		push_best(stack, best);
		free(best);
	}
	put_top_a(stack, find_smallest(stack->a, stack->size_a));
}
