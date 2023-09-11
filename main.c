/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddidenko <ddidenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:57:54 by ddidenko          #+#    #+#             */
/*   Updated: 2023/08/02 14:54:52 by ddidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_sorting(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, 1);
		else if (stack_len(*a) == 3)
			tiny_sort(a);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_init(&a, args + 1, 2 == argc);
	}
	else
		stack_init(&a, argv + 1, 2 == argc);
	check_for_sorting(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
