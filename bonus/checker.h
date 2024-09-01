/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:53:09 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 21:00:48 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <math.h>

t_list	*fill_stack(int ac, char **av);
void	sa_swap_a(t_list **stack_a);
void	sb_swap_b(t_list **stack_b);
void	ss_swap_a_b(t_list **stack_a, t_list **stack_b);
void	ra_rotate_a(t_list **stack_a);
void	rb_rotate_b(t_list **stack_b);
void	rr_rotate_a_b(t_list **stack_a, t_list **stack_b);
void	rra_revers(t_list **stack_a);
void	rrb_revers(t_list **stack_b);
void	rrr_ra_rb(t_list **stack_a, t_list **stack_b);
void	pb_push_b(t_list **stack_a, t_list **stack_b);
void	pa_push_a(t_list **stack_a, t_list **stack_b);
void	check_max_min(char **split, int i);
void	read_and_cmp_2(t_list **stack_a, t_list **stack_b, char *instr);
void	read_and_cmp_1(t_list **stack_a, t_list **stack_b, char *instr);
int		ft_len(char **av);
char	*str_join(int size, char **av, char *sep);
int		check_is_int(char **split, int count);
int		check_duplicates(t_list *stack_a);
int		check_if_sorted(t_list *stack_a);
void	ft_free(char **split);
void	free_stack(t_list *stack);

#endif
