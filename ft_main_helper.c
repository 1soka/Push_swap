/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:15:12 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:20:36 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

double	ft_count_disorder(int *stack_a, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] > stack_a[j])
				mistakes += 1;
			total_pairs++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

int	ft_check_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_check(char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if ((result * sign > 2147483647) || (result * sign < -2147483648))
		{
			*error = 1;
			return (0);
		}
	}
	return (result * sign);
}

int	ft_check_double(int *stack_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i] == stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	adaptivechoice(int *stack_a, int *stack_b, int size_a)
{
	double	disorder;
	int		count;

	disorder = ft_count_disorder(stack_a, size_a);
	if ((disorder < 0.2))
		count = ft_bubble_sort(stack_a, size_a);
	else if (disorder < 0.5)
		count = ft_bucket_sort(stack_a, stack_b, size_a, 0);
	else
		count = ft_radix_sort(stack_a, stack_b, size_a, 0);
	return (count);
}
