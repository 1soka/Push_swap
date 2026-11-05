/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:49:15 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 20:35:42 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	sa(int *a, int size);
void	sb(int *b, int size);
void	ss(int *a, int *b, int size);
void	pa(int *a, int *b, int *sizea, int *sizeb);
void	pb(int *a, int *b, int *sizea, int *sizeb);
void	ra(int *a, int size);
void	rb(int *b, int size);
void	rr(int *a, int *b, int sizea, int sizeb);
void	rra(int *a, int size);
void	rrb(int *b, int size);
void	rrr(int *a, int *b, int sizea, int sizeb);
void	eeee(int *tab, int taille);

int		ft_radix_sort(int *stack_a, int *stack_b, int size_a, int size_b);
int		ft_index(int *stack_a, int size_a);
int		ft_radix_helper(int *stack_a, int *stack_b, int size_a, int size_b);
int		ft_bucket_transfert(int *stack_a, int *stack_b, int *size_a,
			int *size_b);
int		ft_is_sort(int *stack, int size_a);
int		ft_check_alpha(char *str);
int		iafterparam(int argc, char *argv[]);
int		ft_get_width(int *stack_a, int size_a, int min);
int		have_buckets(int *stack_a, int size_a, int buckets_index,
			int buckets_size);
int		ft_check_double(int *stack_a, int size_a);
int		ft_atoi_check(char *str, int *error);
int		ft_bucket_helper(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		ft_smallest_number(int *stack_a, int size_a);
int		ft_index(int *stack, int size);
int		ft_bubble_sort(int *stack, int size_a);
int		ft_bucket_sort(int *stack_a, int *stack_b, int size_a, int size_b);
int		ft_biggest_number(int *stack, int size_a);
int		ft_bench_mode(int fd, double disorder, int count, int force);
int		ft_argv_size(char **argv);
int		*ft_iterative_argv(int i, char **argv, int *stack_a, int size_a);
int		adaptivechoice(int *stack_a, int *stack_b, int size_a);
double	ft_count_disorder(int *stack_a, int size_a);
int		ft_sqrt(int n);
int		paramhandler(int *stack_a, int *stack_b, int argc, char **argv);
int		ft_rank(int *stack, int size, int value);
int		move1l(int *arr, int size);
int		move1r(int *arr, int size);

#endif
