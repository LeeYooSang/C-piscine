/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:39:35 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/17 18:56:43 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	hex(int t, char *pt)
{
	pt[0] = t / 16;
	if (pt[0] < 10)
		pt[0] = pt[0] + 48;
	else
		pt[0] = pt[0] + 87;
	pt[1] = t % 16;
	if (pt[1] < 10)
		pt[1] = pt[1] + 48;
	else
		pt[1] = pt [1] + 87;
}

void	ft_putstr_non_printable(char *str)
{
	char			temp[3];
	unsigned char	*pt;
	int				t;

	pt = (unsigned char *)str;
	temp[0] = '0';
	while (*pt)
	{
		t = *pt;
		if (t < 32 || t > 126)
		{
			hex(t, temp);
			write(1, "\\", 1);
			write(1, &temp, 2);
			pt++;
			continue ;
		}
		write(1, pt, 1);
		pt ++;
	}
}
