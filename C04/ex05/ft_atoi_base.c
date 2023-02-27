/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:15:29 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/19 19:06:23 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
{
	char	check[128];
	int		i;

	i = 0;
	while (i <= 127)
		check[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (check[(int)base[i]] != 0)
			return (0);
		else if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		check[(int)base[i]]++;
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (i);
}

int	findin_base(char *base, char s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (base[i])
		i++;
	while (tmp < i)
	{
		if (base[tmp] == s)
			return (tmp);
		tmp ++;
	}
	if (tmp == i)
		return (-1);
	return (tmp);
}

int	to_int(char *str, char *base, int bs, int cnt)
{
	unsigned int	result;
	unsigned int	pos;
	unsigned int	bs_num;

	result = 0;
	pos = 1;
	str --;
	bs_num = findin_base(base, *str);
	while (bs_num != -1)
	{
		result = result + bs_num * pos;
		pos = pos * bs;
		str --;
		bs_num = findin_base(base, *str);
	}
	if (cnt % 2 == 1)
		result = -result;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	bs;
	int	cnt;
	int	isok;

	isok = 1;
	cnt = 0;
	bs = base_check(base);
	if (!bs)
		return (0);
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				cnt++;
		}
		else if (*str >= base[0] && *str <= base[bs - 1])
			isok = 0;
		else if ((*str == 32 || (*str >= 9 && *str <= 13)) && isok == 1)
			isok = 1;
		else
			break ;
		str ++;
	}
	return (to_int(str, base, bs, cnt));
}
