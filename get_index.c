/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:24:19 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 16:26:31 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_index(t_list *stack_a, int num)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->data == num)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

void	puch_top_a(t_list **stack_a, int data, int st)
{
	int	size;
	int	index;

	size = ft_lstsize(*stack_a);
	index = get_index(*stack_a, data);
	while (index != 0 && index != size)
	{
		if (index > (size / 2))
		{
			if (st)
				rra_revers(stack_a);
			else
				rrb_revers(stack_a);
			index++;
		}
		else
		{
			if (st)
				ra_rotate_a(stack_a);
			else
				rb_rotate_b(stack_a);
			index--;
		}
	}
}

int	check_stack(int *tab, int num, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (tab[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	puch_to_stack_b(int *tab, t_list **stack_a, t_list **stack_b, int max)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (check_stack(tab, temp->data, max) == 0)
		{
			puch_top_a(stack_a, temp->data, 1);
			pb_push_b(stack_a, stack_b);
		}
		temp = temp->next;
	}
}
