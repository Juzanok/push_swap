/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:15 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:43 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_switch(t_stack *stack, char array)
{
	int	temp;

	if (array == 'a')
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	else
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
}

void	do_rotate(t_stack *stack, char array)
{
	int	temp;
	int	i;

	i = 0;
	if (array == 'a')
	{
		temp = stack->a[0];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = temp;
	}
	else
	{
		temp = stack->b[0];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = temp;
	}
}

void	do_reverse_rotate(t_stack *stack, char array)
{
	int	temp;
	int	i;

	if (array == 'a')
	{
		i = stack->size_a - 1;
		temp = stack->a[i];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = temp;
	}
	else
	{
		i = stack->size_b - 1;
		temp = stack->b[i];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = temp;
	}
}

void	do_push_a(t_stack *stack)
{
	int	*temp;
	int	i;
	int	y;

	temp = (int *)malloc(sizeof(int) * stack->size_a);
	i = 0;
	while (i < stack->size_a)
	{
		temp[i] = stack->a[i];
		i++;
	}
	i = 0;
	y = 1;
	stack->a[0] = stack->b[0];
	while (i < stack->size_a)
	{
		stack->a[y] = temp[i];
		y++;
		i++;
	}
	push_a_extra(stack);
	free(temp);
}

void	do_push_b(t_stack *stack)
{
	int	*temp;
	int	i;
	int	y;

	temp = (int *)malloc(sizeof(int) * stack->size_b);
	i = 0;
	while (i < stack->size_b)
	{
		temp[i] = stack->b[i];
		i++;
	}
	i = 0;
	y = 1;
	stack->b[0] = stack->a[0];
	while (i < stack->size_b)
	{
		stack->b[y] = temp[i];
		y++;
		i++;
	}
	push_b_extra(stack);
	free(temp);
}
