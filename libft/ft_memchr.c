/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:25:35 by spzona            #+#    #+#             */
/*   Updated: 2021/10/15 18:20:55 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sc;
	size_t	i;

	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)sc[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
