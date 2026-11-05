/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:38:43 by ********          #+#    #+#             */
/*   Updated: 2026/10/31 22:16:45 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putptr(void *ptr, int *count, int fd);
void	ft_putchar(char c, int *count, int fd);
void	ft_putunbr(unsigned int nb, int *count, int fd);
void	ft_puthex(unsigned long int nb, int *count, int fd, int upper);
void	ft_putnbr(int nb, int *count, int fd);
void	ft_putstr(char *str, int *count, int fd);
int		ft_printfd(int fd, const char *str, ...);

#endif
