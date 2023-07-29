/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:15:20 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/17 22:30:02 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	get_stack(t_stack **stack, int size, char **a)
{
	int	i;
	int	y;

	if (!check_stack(size, a))
		return (0);
	i = 1;
	y = 0;
	(*stack)->size_a = size - 1;
	(*stack)->size_b = 0;
	(*stack)->a = (int *)malloc(sizeof(int) * (*stack)->size_a);
	(*stack)->b = (int *)malloc(sizeof(int) * (*stack)->size_a);
	while (i < size)
	{
		(*stack)->a[y] = ft_atoi(a[i]);
		i++;
		y++;
	}
	if (!check_duplicates((*stack)->a, (*stack)->size_a))
		return (0);
	return (1);
}

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

long long int	ft_atoi_new(const char *nptr)
{
	long long int	sum;
	int				i;
	int				negative;

	i = 0;
	negative = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	sum = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	if (negative < 0)
		sum = sum * -1;
	return (sum);
}

int	check_stack(int size, char **a)
{
	char	*c;
	int		i;
	int		y;

	c = "-0123456789";
	i = 1;
	while (i < size)
	{
		y = 0;
		if (ft_atoi_new(a[i]) < -2147483648 || ft_atoi_new(a[i]) > 2147483647)
			return (0);
		while (a[i][y])
		{
			if (!ft_strchr(c, a[i][y]))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
