/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:25:30 by ctogoe            #+#    #+#             */
/*   Updated: 2021/10/25 00:28:28 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_count_size(unsigned int nbr, size_t len_base)
{
	int		i;

	i = 0;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		i++;
	}
	return (++i);
}

void	ft_check(int *i, unsigned int *nbr, long int n)
{
	if (n < 0)
	{
		(*nbr) *= -1;
		(*i) = 1;
	}
}

char	*ft_itoa_base(long int n, char *base)
{
	int				i;
	unsigned int	nbr;
	char			*str;
	size_t			len_base;

	len_base = ft_strlen(base);
	i = 0;
	nbr = n;
	ft_check(&i, &nbr, n);
	i += ft_count_size(nbr, len_base);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (i--)
	{
		if (nbr >= 0)
			str[i] = base[nbr % len_base];
		if (i == 0 && n < 0)
			str[i] = '-';
		nbr /= len_base;
	}
	return (str);
}

int	ft_u_count_size(unsigned long int nbr, unsigned long int len_base)
{
	int		i;

	i = 0;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		i++;
	}
	return (++i);
}

char	*ft_unsigned_itoa_base(unsigned long int n, char *base)
{
	int					i;
	unsigned long int	nbr;
	char				*str;
	int					len_base;

	len_base = ft_strlen(base);
	i = 0;
	nbr = n;
	i += ft_u_count_size(nbr, len_base);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (i--)
	{
		if (nbr >= 0)
			str[i] = base[nbr % len_base];
		nbr /= len_base;
	}
	return (str);
}
