/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 02:04:47 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:14:20 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pa(int *a, int *b, int *sizea, int *sizeb)
{
	int	felem;

	felem = move1l(b, *sizeb);
	(void)move1r(a, *sizea + 1);
	a[0] = felem;
	*sizeb -= 1;
	*sizea += 1;
	ft_putstr_fd("pa\n", 1);
}

void	pb(int *a, int *b, int *sizea, int *sizeb)
{
	int	felem;

	if (*sizea < 1)
		return ;
	felem = move1l(a, *sizea);
	(void)move1r(b, *sizeb + 1);
	b[0] = felem;
	*sizea -= 1;
	*sizeb += 1;
	ft_putstr_fd("pb\n", 1);
}

void	ra(int *a, int size)
{
	if (size < 2)
		return ;
	a[size - 1] = move1l(a, size);
	ft_putstr_fd("ra\n", 1);
}

void	rb(int *b, int size)
{
	if (size < 2)
		return ;
	b[size - 1] = move1l(b, size);
	ft_putstr_fd("rb\n", 1);
}

void	rr(int *a, int *b, int sizea, int sizeb)
{
	ra(a, sizea);
	rb(b, sizeb);
}
