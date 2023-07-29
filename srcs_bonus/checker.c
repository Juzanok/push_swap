/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:22:52 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	print_result(int i)
{
	if (i == -1)
		write(2, "Error\n", 6);
	else if (i == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	free_stacks(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc < 3)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (!get_stack(&stack, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stacks(stack);
		return (0);
	}
	i = do_moves(&stack);
	print_result(i);
	free_stacks(stack);
	return (0);
}
