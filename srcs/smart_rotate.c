/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:51:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:47 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_best(t_stack *stack, int *best)
{
	if (best[0] * best[1] > 0)
	{
		if (best[0] < 0)
		{
			while (best[0] < 0 && best[1] < 0)
			{
				move(stack, "rrr");
				best[0]++;
				best[1]++;
			}		
		}
		else
		{
			while (best[0] > 0 && best[1] > 0)
			{
				move(stack, "rr");
				best[0]--;
				best[1]--;
			}
		}
	}
	finish_push_best(stack, best);
}

void	finish_push_best(t_stack *stack, int *best)
{
	char	*move_a;
	char	*move_b;

	move_a = "rra";
	if (best[0] < 0)
		best[0] = best[0] * -1;
	else
		move_a = "ra";
	move_b = "rrb";
	if (best[1] < 0)
		best[1] = best[1] * -1;
	else
		move_b = "rb";
	while (best[0] > 0)
	{
		move(stack, move_a);
		best[0]--;
	}
	while (best[1] > 0)
	{
		move(stack, move_b);
		best[1]--;
	}
	move(stack, "pa");
}
