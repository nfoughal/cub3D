/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:19:41 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/01 19:11:49 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_3(t_list **stack_a)
{
	t_list	*temp;
	int		last;
	int		first;
	int		next;

	temp = *stack_a;
	last = ft_lstlast(temp)->data;
	first = temp->data;
	next = temp->next->data;
	if (first > next && next < last && last > first)
		sa_swap_a(stack_a);
	if (first > next && next > last && last < first)
	{
		sa_swap_a(stack_a);
		rra_revers(stack_a);
	}
	if (first > next && next < last && last < first)
		ra_rotate_a(stack_a);
	if (first < next && next > last && last > first)
	{
		sa_swap_a(stack_a);
		ra_rotate_a(stack_a);
	}
	if (first < next && next > last && last < first)
		rra_revers(stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	data;

	data = re_max(*stack_a);
	puch_top_a(stack_a, data, 1);
	pb_push_b(stack_a, stack_b);
	data = re_max(*stack_a);
	puch_top_a(stack_a, data, 1);
	pb_push_b(stack_a, stack_b);
	sort_3(stack_a);
	pa_push_a(stack_a, stack_b);
	ra_rotate_a(stack_a);
	pa_push_a(stack_a, stack_b);
	ra_rotate_a(stack_a);
}

int	check_if_sorted(t_list *stack_a)
{
	if (ft_lstsize(stack_a) == 0)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	display_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d  ", stack->data);
		stack = stack->next;
	}
}
