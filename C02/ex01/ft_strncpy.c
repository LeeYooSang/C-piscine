/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:45:31 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/20 05:27:41 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*tmp;

	tmp = dest;
	while (*src && n)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	if (*src == '\0' && n)
		*dest = '\0';
	return (tmp);
}
