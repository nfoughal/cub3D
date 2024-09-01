/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:27:41 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 16:28:33 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_data(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	push_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	min;
	int	next;
	int	num;

	while (ft_lstsize(*stack_b) != 0)
	{
		i = tota_mouve(*stack_a, *stack_b);
		min = get_data(*stack_b, i);
		next = get_next(*stack_a, min);
		puch_top_a(stack_b, min, 0);
		puch_top_a(stack_a, next, 1);
		pa_push_a(stack_a, stack_b);
	}
	num = re_min(*stack_a);
	puch_top_a(stack_a, num, 1);
}
