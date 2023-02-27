/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:58:20 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/19 19:04:10 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	to_int(char *str, int cnt)
{
	int	result;
	int	pos;

	result = 0;
	pos = 1;
	str --;
	while (*str >= '0' && *str <= '9')
	{
		result = result + ((int)*str - 48) * pos;
		pos = pos * 10;
		str--;
	}
	if (cnt % 2 == 1)
		result = -result;
	return (result);
}

int	ft_atoi(char *str)
{
	int	cnt;
	int	isok;

	cnt = 0;
	isok = 1;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				cnt++;
			isok = 0;
		}
		else if (*str >= '0' && *str <= '9')
			isok = 0;
		else if (isok == 0)
			break ;
		else if ((*str == 32 || (*str >= 9 && *str <= 13)) && isok)
			isok = 1;
		else
			break ;
		str++;
	}
	isok = to_int(str, cnt);
	return (isok);
}
