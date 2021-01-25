/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:17:50 by arastepa          #+#    #+#             */
/*   Updated: 2021/01/25 14:53:54 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	int step;
	unsigned char *dest;
	unsigned char *source;

	step = 1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (src < dst)
	{
		step = -1;
		dest = (unsigned char *)(dst + len - 1);
		source = (unsigned char *)(src + len - 1);
	}
	i = 0;
	while(i < len)
	{
		*dest = *source;
		dest += step;
		source += step;
		i++;
	}
	return (dst);
}
