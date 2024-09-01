/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:43:32 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/01 02:47:33 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_next(t_list *stack_a, int data)
{
	int		count;
	int		i;
	int		*tab;
	t_list	*temp;

	i = 0;
	count = 0;
	temp = stack_a;
	count = re_count(stack_a, data);
	if (count == 0)
		return (re_min(temp));
	tab = malloc(sizeof(int) * count);
	if (!tab)
		exit(1);
	while (temp)
	{
		if (temp->data > data)
			tab[i++] = temp->data;
		temp = temp->next;
	}
	i = f_min(tab, count);
	free(tab);
	return (i);
}

int	move_count(t_list *stack_a, int data)
{
	int	size;
	int	index;
	int	count;

	count = 0;
	size = ft_lstsize(stack_a);
	index = get_index(stack_a, data);
	while (index != 0 && index != size)
	{
		if (index > (size / 2))
		{
			index++;
			count++;
		}
		else
		{
			index--;
			count++;
		}
	}
	return (count);
}

int	*re_tab_count(t_list *stack_a, t_list *stack_b, int *tab)
{
	int		num_a;
	t_list	*temp;
	int		j;

	j = 0;
	temp = stack_b;
	while (stack_b)
	{
		num_a = get_next(stack_a, stack_b->data);
		tab[j] = move_count(temp, stack_b->data) + move_count(stack_a, num_a);
		stack_b = stack_b->next;
		j++;
	}
	return (tab);
}

int	tota_mouve(t_list *stack_a, t_list *stack_b)
{
	int		*tab;
	int		min;
	t_list	*temp;
	int		i;

	temp = stack_b;
	i = ft_lstsize(stack_b);
	tab = malloc(sizeof(int) * i);
	if (!tab)
		exit(1);
	tab = re_tab_count(stack_a, stack_b, tab);
	min = f_min(tab, i);
	i = 0;
	while (tab[i] != min)
	i++;
	free(tab);
	return (i);
}
