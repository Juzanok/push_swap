/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:20:43 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:46 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->lis);
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 3)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (!get_stack(&stack, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stacks(stack);
		return (0);
	}
	if (!pre_check(stack))
	{
		free_stacks(stack);
		return (0);
	}
	sort(stack);
	free_stacks(stack);
	return (0);
}
