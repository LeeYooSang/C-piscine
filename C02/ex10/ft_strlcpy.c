/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:20:11 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/20 06:03:42 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	while (*src && size)
	{
		if (--size > 0)
			*dest = *src;
		else
		{
			*dest = '\0';
			break ;
		}
		dest++;
		src++;
		i++;
	}
	if (!*src && size)
		*dest = '\0';
	return (j);
}
