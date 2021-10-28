/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:23:13 by ctogoe            #+#    #+#             */
/*   Updated: 2021/10/25 00:15:42 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_char(int **i, va_list ap, int **len);
void		ft_string(int **i, va_list ap, int **len);
void		ft_int(int **i, va_list ap, int **len);
void		ft_unsigned(int **i, va_list ap, int **len);
void		ft_hexa(int **i, va_list ap, int **len, char c);
void		ft_arg_ptr(int **i, va_list ap, int **len);
void		ft_check_c(int *i, char c, va_list ap, int *len);
void		ft_check(int *i, unsigned int *nbr, long int n);
size_t		ft_strlen(const char *str);
char		*ft_unsigned_itoa_base(unsigned long int n, char *base);
char		*ft_itoa_base(long int n, char *base);
int			ft_u_count_size(unsigned long int nbr, unsigned long int len_base);
int			ft_count_size(unsigned int nbr, size_t len_base);
int			ft_printf(const char *s, ...);

#endif
