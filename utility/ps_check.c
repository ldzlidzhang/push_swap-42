/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:09:16 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/03/14 08:21:11 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	if ((num[0] == '-' || num[0] == '+') && !num[1])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**argc2(char *av)
{
	char	**args;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && av[i] != ' ' && av[i] != '-' && av[i] != '+')
			ps_error("Error");
		i++;
	}
	args = ft_split(av, ' ');
	return (args);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
	{
		args = argc2(argv[1]);
		i = 0;
	}
	else
		args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ps_error("Error");
		if (ft_contains(tmp, args, i) == 1)
			ps_error("Error");
		if (tmp < INT32_MIN || tmp > 2147483647)
			ps_error("Error");
		i++;
	}
	if (argc == 2)
		ps_free(args);
}
