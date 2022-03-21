/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:09:31 by spzona            #+#    #+#             */
/*   Updated: 2021/10/13 13:25:55 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;

	if ((dest == src) || (n == 0))
		return (dest);
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	if (dest > src)
	{
		n_dest = (unsigned char *)dest + n - 1;
		n_src = (unsigned char *)src + n - 1;
		while (n--)
			*(n_dest--) = *(n_src--);
	}
	else
	{
		n_dest = (unsigned char *)dest;
		n_src = (unsigned char *)src;
		while (n--)
			*(n_dest++) = *(n_src++);
	}
	return (dest);
}
