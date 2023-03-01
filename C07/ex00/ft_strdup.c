/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:57:09 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/20 03:03:56 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*tmp;
	char	*dest;
	int		i;

	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * i);
	tmp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (tmp);
}
