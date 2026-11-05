/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:01:08 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:13:06 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_bubble_sort(int *stack, int size_a)
{
	int	i;
	int	count;

	if (!stack || size_a < 2)
		return (0);
	count = 0;
	while (!ft_is_sort(stack, size_a))
	{
		i = 0;
		while (i < size_a - 1)
		{
			if (stack[0] > stack[1])
			{
				sa(stack, size_a);
				count++;
			}
			ra(stack, size_a);
			count++;
			i++;
		}
		ra(stack, size_a);
		count++;
	}
	return (count);
}

int	ft_transfert_a(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	count;

	count = 0;
	while (size_b > 0)
	{
		pa(stack_a, stack_b, &size_a, &size_b);
		count++;
	}
	return (count);
}

int	ft_radix_helper(int *stack_a, int *stack_b, int size_a, int max_bits)
{
	int	i;
	int	j;
	int	count;
	int	size_a_sauv;
	int	size_b;

	i = -1;
	count = 0;
	while (++i < max_bits)
	{
		j = 0;
		size_b = 0;
		size_a_sauv = size_a;
		while (j < size_a_sauv)
		{
			if ((stack_a[0] >> i & 1) == 0)
				pb(stack_a, stack_b, &size_a, &size_b);
			else
				ra(stack_a, size_a);
			j++;
		}
		count += ft_transfert_a(stack_a, stack_b, size_a, size_b);
		size_a = size_a_sauv;
	}
	return (count + j);
}

int	ft_radix_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	max_bits;
	int	count;
	int	i;

	if (!stack_a || !stack_b || size_a < 2)
		return (-1);
	if (ft_index(stack_a, size_a) == -1)
		return (-1);
	(void)size_b;
	max_bits = 0;
	count = 0;
	while (((ft_biggest_number(stack_a, size_a)) >> max_bits) != 0)
		max_bits++;
	i = 0;
	count += ft_radix_helper(stack_a, stack_b, size_a, max_bits);
	return (count);
}
