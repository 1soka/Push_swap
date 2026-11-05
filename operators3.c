/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 02:06:28 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:14:16 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rra(int *a, int size)
{
	a[0] = move1r(a, size);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(int *b, int size)
{
	b[0] = move1r(b, size);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(int *a, int *b, int sizea, int sizeb)
{
	rra(a, sizea);
	rrb(b, sizeb);
}
