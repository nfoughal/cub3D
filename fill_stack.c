/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:47:48 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 18:46:01 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	check_max_min(char **split, int i)
{
	if (ft_atoi(split[i]) > 2147483647
		|| ft_atoi(split[i]) < -2147483647 || ft_strlen(split[i]) > 11)
	{
		ft_free(split);
		write(2, "Error\n", 6);
		exit (1);
	}
}

t_list	*fill(t_list *stack, char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		check_max_min(split, i);
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	ft_free(split);
	if (check_duplicates(stack) == 0)
	{
		free_stack(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (stack);
}

void	check_av(char **av, int count)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (j <= count)
	{
		if (av[j][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (av[j][i] && av[j][i] == ' ')
			i++;
		if (av[j][i] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}

t_list	*fill_stack(int ac, char **av)
{
	char	**split;
	char	*s;
	t_list	*stack_a;
	int		count;

	split = NULL;
	stack_a = NULL;
	count = 0;
	if (ac == 1)
		exit(0);
	check_av(av, ac - 1);
	if (ac > 1)
	{
		s = str_join((ac - 1), av, " ");
		split = ft_split(s, ' ');
		free(s);
		while (split[count])
			count++;
		if (check_is_int(split, count) == 1)
			return (stack_a = fill(stack_a, split, count));
		ft_free(split);
	}
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
