/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:40:30 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 20:45:42 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_stack(t_list *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

void	check_befor(t_list **stack_a, t_list **stack_b)
{
	if (check_if_sorted(*stack_a) == 1)
	{
		free_stack(*stack_a);
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;
	int		*tab;
	int		*longest;
	int		max;

	stack_b = NULL;
	stack_a = NULL;
	tab = NULL;
	longest = NULL;
	stack_a = fill_stack(ac, av);
	if (check_if_sorted(stack_a) == 1
		|| ft_lstsize(stack_a) == 3 || ft_lstsize(stack_a) == 5)
		check_befor(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) != 3 && ft_lstsize(stack_a) != 5)
	{
		tab = tab_stack_a(stack_a, ft_lstsize(stack_a));
		longest = long_in_s(tab, ft_lstsize(stack_a), &max);
		puch_to_stack_b(longest, &stack_a, &stack_b, max);
		push_stack_a(&stack_a, &stack_b);
	}
	free(tab);
	free(longest);
	free_stack(stack_b);
	free_stack(stack_a);
}
