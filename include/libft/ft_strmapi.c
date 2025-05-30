/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:22:58 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:23:06 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	offset;
	char			*res;

	offset = 0;
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (*(s++))
	{
		offset++;
		*(res++) = f(offset - 1, (s - offset)[offset - 1]);
	}
	*res = '\0';
	return (res - offset);
}
