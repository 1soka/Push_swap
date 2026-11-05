/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:39:32 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:21:09 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printfd.h"

int	ft_argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	*ret_error(void)
{
	ft_printfd(2, "Error\n");
	return (NULL);
}

int	*ft_iterative_argv(int i, char **argv, int *stack_a, int size_a)
{
	int	error;
	int	argc;

	argc = ft_argv_size(argv);
	error = 0;
	while (i < ft_argv_size(argv))
	{
		if (ft_check_alpha(argv[i]))
			return (ret_error());
		stack_a[i - iafterparam(argc, argv)] = ft_atoi_check(argv[i], &error);
		if (error == 1)
			return (ret_error());
		i++;
	}
	if (ft_check_double(stack_a, size_a))
		return (ret_error());
	return (stack_a);
}
