/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:11:54 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:51 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*find_best(t_stack *stack)
{
	int	*best;
	int	*temp;
	int	i;

	temp = (int *)malloc(sizeof(int) * 2);
	best = (int *)malloc(sizeof(int) * 2);
	best[0] = best_1(stack->a, stack->size_a, stack->b[0]);
	best[1] = best_2(stack->b, stack->size_b, stack->b[0]);
	i = 1;
	while (i < stack->size_b)
	{
		temp[0] = best_1(stack->a, stack->size_a, stack->b[i]);
		temp[1] = best_2(stack->b, stack->size_b, stack->b[i]);
		if (best_compare(best) > best_compare(temp))
		{
			best[0] = temp[0];
			best[1] = temp[1];
		}
		i++;
	}
	free(temp);
	return (best);
}

int	best_1(int *a, int size, int value)
{
	int	i;

	if (value > a[size - 1] && value < a[0])
		return (0);
	i = 0;
	while (i <= size / 2)
	{
		if (value > a[i] && value < a[i + 1])
			return (i + 1);
		i++;
	}
	i = size - 1;
	while (i > size / 2)
	{
		if (value > a[i - 1] && value < a[i])
			return (i - size);
		i--;
	}
	return (best_2(a, size, find_smallest(a, size)));
}

int	best_2(int *b, int size, int value)
{
	int	i;

	i = 0;
	while (i <= size / 2)
	{
		if (b[i] == value)
			return (i);
		i++;
	}
	i = size - 1;
	while (i > size / 2)
	{
		if (b[i] == value)
			return (i - size);
		i--;
	}
	return (size - 1);
}

int	best_compare(int *arr)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (arr[0] >= 0)
		a += arr[0];
	else
		a += (arr[0] * -1);
	if (arr[1] >= 0)
		b += arr[1];
	else
		b += (arr[1] * -1);
	return (a + b);
}
