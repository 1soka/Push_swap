/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 04:44:36 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:14:02 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	move1l(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	if (size > 0)
	{
		tmp = arr[0];
		while (i < size - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
	}
	else
		return (-1);
	return (tmp);
}

int	move1r(int *arr, int size)
{
	int	i;
	int	tmp;

	tmp = 0;
	if (size > 0)
	{
		tmp = arr[size - 1];
		i = size - 1;
		while (i > 0)
		{
			arr[i] = arr[i - 1];
			i--;
		}
	}
	return (tmp);
}

void	sa(int *a, int size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(int *b, int size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(int *a, int *b, int size)
{
	sa(a, size);
	sb(b, size);
}
