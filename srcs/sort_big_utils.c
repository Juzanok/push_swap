/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:01:09 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:51:50 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_lis(t_stack *stack)
{
	int	small;
	int	i;
	int	*a;

	i = 0;
	a = (int *)malloc(sizeof(int) * stack->size_a);
	while (i < stack->size_a)
	{
		a[i] = stack->a[i];
		i++;
	}
	small = find_smallest(a, stack->size_a);
	while (a[0] != small)
		rotate(a, stack->size_a);
	take_lis(stack, a, stack->size_a);
	free(a);
}

void	take_lis(t_stack *stack, int *arr, int len)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		lis[i] = 1;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] <= lis[j])
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	save_lis(stack, arr, lis, len);
	free(lis);
}

void	save_lis(t_stack *stack, int *arr, int *lis, int len)
{
	int	max;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	max = lis[i];
	while (++i < len)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			pos = i;
		}
	}
	stack->size_lis = max;
	get_lis_array(stack, arr, lis, pos);
}

void	get_lis_array(t_stack *stack, int *arr, int *lis, int pos)
{
	int	i;
	int	max;

	max = stack->size_lis;
	i = max - 1;
	stack->lis = (int *)malloc(sizeof(int) * max);
	stack->lis[i] = arr[pos];
	while (i >= 0)
	{
		if (lis[pos] == max - 1)
		{
			max--;
			i--;
			stack->lis[i] = arr[pos];
		}
		pos--;
	}
}

void	rotate(int *a, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
}
