/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:24:20 by spzona            #+#    #+#             */
/*   Updated: 2021/10/15 18:10:04 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	if (ndl[0] == '\0')
		return ((char *)stack);
	while (stack[i] != '\0')
	{
		j = 0;
		if (stack[i] == ndl[j])
			x = i;
		while (stack[i] == ndl[j] && stack[i] != '\0' && len > i)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(ndl))
			return ((char *)stack + x);
		if (j > 0)
			i = x + 1;
		else
			i++;
	}
	return (NULL);
}
