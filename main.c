/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:00:53 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:56:39 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printfd.h"

int	ft_bench_mode(int fd, double disorder, int count, int force)
{
	int		decimal;

	decimal = (int)(disorder * 100);
	ft_printfd(fd, "[bench] disorder: %d%%\n", decimal);
	if ((decimal < 20 && force == 0) || force == 1)
		ft_printfd(fd, "[bench] strategy: Adaptive / O(n2)\n");
	else if (((decimal >= 20 && decimal < 50) && force == 0) || force == 2)
		ft_printfd(fd, "[bench] strategy: Adaptive / O(n√n)\n");
	else if ((decimal >= 50 && force == 0) || force == 3)
		ft_printfd(fd, "[bench] strategy: Adaptive / O(n log n)\n");
	ft_printfd(fd, "[bench] total_ops: %d\n", count);
	close(fd);
	return (0);
}

int	iafterparam(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp("--simple", argv[i], 9) != 0
			&& ft_strncmp("--medium", argv[i], 9) != 0
			&& ft_strncmp("--complex", argv[i], 10) != 0
			&& ft_strncmp("--bench", argv[i], 8) != 0
			&& ft_strncmp("--adaptive", argv[i], 11) != 0)
			return (i);
		i++;
	}
	return (-1);
}

int	*paramstart(int *stack_a, int *stack_b, int i, char **argv)
{
	int	*countnforce;
	int	size_a;

	countnforce = ft_calloc(2, sizeof(int));
	size_a = ft_argv_size(argv) - iafterparam(ft_argv_size(argv), argv);
	if (ft_strncmp("--simple", argv[i], 9) == 0)
	{
		countnforce[0] = ft_bubble_sort(stack_a, size_a);
		countnforce[1] = 1;
	}
	else if (ft_strncmp("--medium", argv[i], 9) == 0)
	{
		countnforce[0] = ft_bucket_sort(stack_a, stack_b, size_a, 0);
		countnforce[1] = 2;
	}
	else if (ft_strncmp("--complex", argv[i], 10) == 0)
	{
		countnforce[0] = ft_radix_sort(stack_a, stack_b, size_a, 0);
		countnforce[1] = 3;
	}
	else
		countnforce[0] = adaptivechoice(stack_a, stack_b, size_a);
	return (countnforce);
}

int	paramhandler(int *stack_a, int *stack_b, int argc, char **argv)
{
	int			i;
	int			*countnforce;
	int			size_a;
	double		disorder;
	int			bench;

	size_a = argc - iafterparam(argc, argv);
	countnforce = NULL;
	bench = 0;
	disorder = ft_count_disorder(stack_a, size_a);
	i = 1;
	while (i < iafterparam(argc, argv))
	{
		if (ft_strncmp("--bench", argv[i], 8) == 0)
			bench = 1;
		else
			countnforce = paramstart(stack_a, stack_b, i, argv);
		i++;
	}
	if (!countnforce)
		countnforce = paramstart(stack_a, stack_b, i, argv);
	if (bench)
		ft_bench_mode(2, disorder, countnforce[0], countnforce[1]);
	return (countnforce[0]);
}

int	main(int argc, char *argv[])
{
	int		*stack_a;
	int		*stack_b;
	int		i;
	int		size_a;
	int		count;

	if (argc < 2 || iafterparam(argc, argv) == -1)
		return (0);
	i = iafterparam(argc, argv);
	size_a = argc - i;
	stack_a = malloc(sizeof(int) * (size_a));
	stack_b = malloc(sizeof(int) * (size_a));
	stack_a = ft_iterative_argv(i, argv, stack_a, size_a);
	if (!stack_a)
		return (1);
	count = paramhandler(stack_a, stack_b, argc, argv);
	return (0);
}
