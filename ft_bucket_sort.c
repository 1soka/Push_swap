/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 23:42:32 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:51:02 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ft_free_stack(int **stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

int	**ft_bucket_initialization(int *stack_a, int size_a)
{
	int	i;
	int	**stack;

	i = 0;
	stack = malloc(size_a * sizeof(int *));
	if (!stack)
		return (NULL);
	while (i < size_a)
	{
		stack[i] = malloc(2 * sizeof(int));
		if (!stack[i])
		{
			ft_free_stack(stack, i);
			return (NULL);
		}
		stack[i][0] = stack_a[i];
		stack[i][1] = 0;
		i++;
	}
	return (stack);
}

int	have_buckets(int *stack_a, int size_a, int buckets_index, int buckets_size)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		if (stack_a[i] / buckets_size == buckets_index)
			return (1);
		i++;
	}
	return (0);
}

int	ft_rank(int *stack, int size, int value)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < size)
	{
		if (stack[i] < value)
			rank++;
		i++;
	}
	return (rank);
}

int	ft_bucket_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	count;
	int	*copy;
	int	n_buckets;
	int	buckets_size;

	count = 0;
	if (size_a < 2)
		return (0);
	copy = malloc(size_a * sizeof(int));
	if (!copy)
		return (-1);
	i = -1;
	while (++i < size_a)
		copy[i] = stack_a[i];
	i = -1;
	while (++i < size_a)
		stack_a[i] = ft_rank(copy, size_a, copy[i]);
	free(copy);
	n_buckets = ft_sqrt(size_a);
	buckets_size = (size_a + n_buckets - 1) / n_buckets;
	count += ft_bucket_helper(stack_a, stack_b, &size_a, &size_b);
	count += ft_bucket_transfert(stack_a, stack_b, &size_a, &size_b);
	return (count);
}
