/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:04:24 by ctogoe            #+#    #+#             */
/*   Updated: 2021/10/25 02:53:45 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(int **i, va_list ap, int **len)
{
	int	d;

	(**i)++;
	d = va_arg(ap, int);
	ft_putchar(d);
	(**len)++;
}

void	ft_check_c(int *i, char c, va_list ap, int *len)
{
	if (c == 'c')
		ft_char(&i, ap, &len);
	else if (c == 's')
		ft_string(&i, ap, &len);
	else if (c == 'd' || c == 'i')
		ft_int(&i, ap, &len);
	else if (c == 'u')
		ft_unsigned(&i, ap, &len);
	else if (c == 'p')
		ft_arg_ptr(&i, ap, &len);
	else if (c == 'x' || c == 'X')
		ft_hexa(&i, ap, &len, c);
	else if (c == '%')
	{
		(*i)++;
		ft_putchar('%');
		(*len)++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, s);
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if ((s[i] == '%'))
		{
			i++;
			ft_check_c(&i, s[i], ap, &len);
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
