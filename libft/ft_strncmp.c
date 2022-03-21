/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:24:14 by spzona            #+#    #+#             */
/*   Updated: 2021/10/13 17:15:20 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			counter;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	counter = 0;
	while (n--)
	{
		if (str1[counter] != str2[counter] || str1[counter] == '\0'
			|| str2[counter] == '\0')
			return (str1[counter] - str2[counter]);
		counter++;
	}
	return (0);
}
