/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:18:35 by ctogoe            #+#    #+#             */
/*   Updated: 2021/10/25 00:31:29 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(int **i, va_list ap, int **len)
{
	char	*str;

	(**i)++;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr(str);
	(**len) += ft_strlen(str);
}

void	ft_arg_ptr(int **i, va_list ap, int **len)
{
	char			*str;
	unsigned long	nbr;

	(**i)++;
	nbr = (unsigned long)va_arg(ap, void *);
	str = ft_unsigned_itoa_base(nbr, "0123456789abcdef");
	ft_putstr("0x");
	(**len) += 2;
	ft_putstr(str);
	(**len) += ft_strlen(str);
	free(str);
}

void	ft_hexa(int **i, va_list ap, int **len, char c)
{
	char			*str;
	unsigned int	hexa;

	(**i)++;
	hexa = va_arg(ap, unsigned int);
	if (c == 'x')
		str = ft_unsigned_itoa_base(hexa, "0123456789abcdef");
	if (c == 'X')
		str = ft_unsigned_itoa_base(hexa, "0123456789ABCDEF");
	ft_putstr(str);
	(**len) += ft_strlen(str);
	free(str);
}

void	ft_int(int **i, va_list ap, int **len)
{
	char		*str;
	long int	nbr;

	(**i)++;
	nbr = va_arg(ap, int);
	str = ft_itoa_base(nbr, "0123456789");
	ft_putstr(str);
	(**len) += ft_strlen(str);
	free(str);
}

void	ft_unsigned(int **i, va_list ap, int **len)
{
	char			*str;
	unsigned int	nbr;

	(**i)++;
	nbr = va_arg(ap, unsigned int);
	str = ft_itoa_base(nbr, "0123456789");
	ft_putstr(str);
	(**len) += ft_strlen(str);
	free(str);
}
