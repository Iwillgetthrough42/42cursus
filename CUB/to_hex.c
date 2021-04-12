/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:21:52 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 13:19:02 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static	int		count(unsigned long n, unsigned int basesize)
{
	int count;

	count = (n > 0 ? 0 : 1);
	while (n != 0)
	{
		n /= basesize;
		count++;
	}
	return (count);
}

char			*ft_anybase(unsigned long n, const char *base)
{
	unsigned	int	base_size;
	int				cnt;
	char			*new;
	int				i;

	base_size = ft_strlen(base);
	cnt = count(n, base_size);
	if (!(new = malloc(sizeof(char) * (cnt + 1))))
		return (0);
	new[cnt] = '\0';
	i = 0;
	if (n == 0)
		new[cnt - i - 1] = '0';
	while (n != 0)
	{
		new[cnt - i - 1] = base[n % base_size];
		n /= base_size;
		i++;
	}
	return (new);
}
