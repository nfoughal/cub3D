/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_f_moves_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:05:30 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:05:40 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	f_min(int *tab, int size)
{
	int	min;
	int	i;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	re_min(t_list *stack_a)
{
	int	i;

	i = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < i)
			i = stack_a->data;
		stack_a = stack_a->next;
	}
	return (i);
}

int	re_max(t_list *stack_a)
{
	int	i;

	i = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > i)
			i = stack_a->data;
		stack_a = stack_a->next;
	}
	return (i);
}

int	re_count(t_list *stack, int data)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->data > data)
			count++;
		stack = stack->next;
	}
	return (count);
}
