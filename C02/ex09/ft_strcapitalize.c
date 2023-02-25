/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:47:19 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/20 05:47:08 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft(char *str, int isfirst)
{
	if (isfirst)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9')))
		{
			*str = *str - 32;
		}
	}
	else
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9')))
			*str = *str + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*tmp;
	int		isfirst;

	isfirst = 1;
	tmp = str;
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
		{
			if (!(*str >= '0' && *str <= '9'))
			{
				isfirst = 1;
				str++;
				continue ;
			}
		}
		ft(str, isfirst);
		str++;
		isfirst = 0;
	}	
	return (tmp);
}
