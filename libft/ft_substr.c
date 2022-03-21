/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:53:16 by spzona            #+#    #+#             */
/*   Updated: 2021/10/15 15:56:30 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;
	unsigned int	len_s;
	unsigned int	len_n;

	if (s == NULL)
		return (NULL);
	len_s = (unsigned int)ft_strlen((char *)s);
	len_n = (unsigned int)ft_strlen((char *)s + start);
	i = 0;
	if (len_s < start)
		return (ft_strdup(""));
	if (len_n < len)
		len = len_n;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy (dst, s + start, len + 1);
	return (dst);
}
