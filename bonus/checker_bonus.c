/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:57:10 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 19:50:17 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_list *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->next;
	}
}

void	read_and_cmp_2(t_list **stack_a, t_list **stack_b, char *instr)
{
	if (ft_strncmp(instr, "sa\n") == 0)
		sa_swap_a(stack_a);
	else if (ft_strncmp(instr, "sb\n") == 0)
		sb_swap_b(stack_b);
	else if (ft_strncmp(instr, "ra\n") == 0)
		ra_rotate_a(stack_a);
	else if (ft_strncmp(instr, "rb\n") == 0)
		rb_rotate_b(stack_b);
	else if (ft_strncmp(instr, "rra\n") == 0)
		rra_revers(stack_a);
	else if (ft_strncmp(instr, "rrb\n") == 0)
		rrb_revers(stack_b);
	else if (ft_strncmp(instr, "pa\n") == 0)
		pa_push_a(stack_a, stack_b);
	else if (ft_strncmp(instr, "pb\n") == 0)
		pb_push_b(stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		free_stack(*stack_a);
		free_stack(*stack_b);
		exit(1);
	}
}

void	read_and_cmp_1(t_list **stack_a, t_list **stack_b, char *instr)
{
	if (ft_strncmp(instr, "rr\n") == 0)
		rr_rotate_a_b(stack_a, stack_b);
	else if (ft_strncmp(instr, "rrr\n") == 0)
		rrr_ra_rb(stack_a, stack_b);
	else if (ft_strncmp(instr, "ss\n") == 0)
		ss_swap_a_b(stack_a, stack_b);
	else
		read_and_cmp_2(stack_a, stack_b, instr);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;

	stack_b = NULL;
	if (ac == 1)
		exit(0);
	stack_a = fill_stack(ac, av);
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		read_and_cmp_1(&stack_a, &stack_b, instruction);
		free(instruction);
	}
	if (check_if_sorted(stack_a) == 1 && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}
