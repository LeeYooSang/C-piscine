/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:48:45 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/20 02:09:12 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	sort_params(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (i <= argc)
	{
		j = i + 1;
		while (j <= argc)
		{
			if (compare(argv[i], argv[j]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[i];
				argv[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	sort_params(argc - 1, argv);
	while (argv[i])
	{
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}
