/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddidenko <ddidenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:49:36 by ddidenko          #+#    #+#             */
/*   Updated: 2023/08/03 14:34:34 by ddidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
	{
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
	{
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
	{
		write(1, "ss\n", 3);
	}
}
