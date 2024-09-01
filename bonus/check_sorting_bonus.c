/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:59:00 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:59:25 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
