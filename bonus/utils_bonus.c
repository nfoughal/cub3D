/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:08:18 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/01 02:48:17 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_len(char **av)
{
	int	i;
	int	len;

	len = 0;
	i = 1;
	while (av[i])
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

char	*str_join(int size, char **av, char *sep)
{
	char	*p;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	p = malloc(sizeof(char) * ft_len(av));
	if (!p)
		exit(1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			p[k++] = av[i][j++];
		}
		j = 0;
		if (i < size)
			while (sep[j])
			p[k++] = sep[j++];
		i++;
	}
	p[k] = '\0';
	return (p);
}

int	check_is_int(char **split, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		if ((split[i][0] == '-' || split[i][0] == '+'))
			j++;
		if (split[i][j] == '\0')
			return (0);
		while (split[i][j] != '\0')
		{
			if (!((split[i][j] >= '0') && (split[i][j] <= '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_list *stack_a)
{
	t_list	*node;
	t_list	*node1;

	node = stack_a;
	node1 = stack_a;
	while (node->next)
	{
		node1 = node->next;
		while (node1)
		{
			if (node->data == node1->data)
				return (0);
			node1 = node1->next;
		}
		node = node->next;
	}
	return (1);
}
