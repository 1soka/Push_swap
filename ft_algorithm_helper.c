/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:15:07 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:12:59 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_biggest_number(int *stack, int size_a)
{
	int	i;
	int	max;

	max = stack[0];
	i = 1;
	while (i < size_a)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	ft_sqrt(int nb)
{
	int	index;

	index = 0;
	while (index * index <= nb)
	{
		if ((index * index) == nb)
			return (index);
		index++;
	}
	return (index - 1);
}

int	ft_smallest_number(int *stack_a, int size_a)
{
	int	i;
	int	min;

	i = 1;
	min = stack_a[0];
	while (i < size_a)
	{
		if (stack_a[i] < min)
			min = stack_a[i];
		i++;
	}
	return (min);
}

int	ft_index(int *stack, int size)
{
	int	i;
	int	*copy;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return (-1);
	i = 0;
	while (i < size)
	{
		copy[i] = stack[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		stack[i] = ft_rank(copy, size, copy[i]);
		i++;
	}
	free(copy);
	return (0);
}
