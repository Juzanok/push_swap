/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:35:25 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 23:48:31 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	do_moves(t_stack **stack)
{
	char	moves[100];
	int		i;
	int		y;

	i = 0;
	while (i >= 0)
	{
		y = i;
		i += read(0, moves + i, 1);
		if (y == i)
			break ;
		if (moves[y] == '\n')
		{
			moves[y] = 0;
			if (get_move(moves) == -1)
				return (-1);
			move(stack, get_move(moves));
			i = 0;
		}
	}
	if ((*stack)->size_b == 0)
		return (check_sorted((*stack)));
	return (1);
}

int	get_move(char *str)
{
	if (ft_strcmp(str, "sa\n") || ft_strcmp(str, "sa"))
		return (1);
	else if (ft_strcmp(str, "sb\n") || ft_strcmp(str, "sb"))
		return (11);
	else if (ft_strcmp(str, "ss\n") || ft_strcmp(str, "ss"))
		return (111);
	else if (ft_strcmp(str, "ra\n") || ft_strcmp(str, "ra"))
		return (2);
	else if (ft_strcmp(str, "rb\n") || ft_strcmp(str, "rb"))
		return (22);
	else if (ft_strcmp(str, "rr\n") || ft_strcmp(str, "rr"))
		return (222);
	else if (ft_strcmp(str, "rra\n") || ft_strcmp(str, "rra"))
		return (3);
	else if (ft_strcmp(str, "rrb\n") || ft_strcmp(str, "rrb"))
		return (33);
	else if (ft_strcmp(str, "rrr\n") || ft_strcmp(str, "rrr"))
		return (333);
	else if (ft_strcmp(str, "pa\n") || ft_strcmp(str, "pa"))
		return (4);
	else if (ft_strcmp(str, "pb\n") || ft_strcmp(str, "pb"))
		return (44);
	else
		return (-1);
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
