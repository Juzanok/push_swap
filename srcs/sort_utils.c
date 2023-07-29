/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:45:32 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:52 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_biggest(int *a, int size)
{
	int	big;
	int	i;

	i = 1;
	big = a[0];
	while (i < size)
	{
		if (a[i] > big)
			big = a[i];
		i++;
	}
	return (big);
}

int	find_smallest(int *a, int size)
{
	int	small;
	int	i;

	i = 1;
	small = a[0];
	while (i < size)
	{
		if (a[i] < small)
			small = a[i];
		i++;
	}
	return (small);
}

void	put_top_a(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack->a[i] != value)
		i++;
	if (i >= stack->size_a / 2)
	{
		while (stack->a[0] != value)
			move(stack, "rra");
	}
	else
	{
		while (stack->a[0] != value)
			move(stack, "ra");
	}
}

void	clear_lis(t_stack *stack)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	get_lis(stack);
	while (i < stack->size_a)
	{
		count = 0;
		j = 0;
		while (j < stack->size_lis)
		{
			if (stack->a[i] == stack->lis[j])
				count++;
			j++;
		}
		if (count == 0)
		{
			put_top_a(stack, stack->a[i]);
			move(stack, "pb");
			i = -1;
		}
		i++;
	}
}
