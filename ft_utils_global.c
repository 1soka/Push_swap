/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:39:25 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:13:44 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_bucket_helper(int *s_a, int *s_b, int *sz_a, int *sz_b)
{
	int	j;
	int	count;
	int	n_buckets;
	int	buckets_size;

	j = 0;
	count = 0;
	buckets_size = ft_get_width(s_a, *sz_a, ft_smallest_number(s_a, *sz_a));
	n_buckets = ft_biggest_number(s_a, *sz_a) / buckets_size + 1;
	while (j < n_buckets)
	{
		if (!have_buckets(s_a, *sz_a, j, buckets_size))
			j++;
		else if (s_a[0] / buckets_size == j)
		{
			pb(s_a, s_b, sz_a, sz_b);
			count++;
		}
		else
		{
			ra(s_a, *sz_a);
			count++;
		}
	}
	return (count);
}

int	ft_bucket_transfert(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	count;

	count = 0;
	while (*size_b > 0)
	{
		while (stack_b[0] != ft_biggest_number(stack_b, *size_b))
		{
			rb(stack_b, *size_b);
			count++;
		}
		pa(stack_a, stack_b, size_a, size_b);
		count++;
	}
	return (count);
}

int	ft_is_sort(int *stack, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_width(int *stack_a, int size_a, int min)
{
	int	m;

	m = ft_biggest_number(stack_a, size_a) - min;
	return ((m + 1) / ft_sqrt(ft_biggest_number(stack_a, size_a)));
}
