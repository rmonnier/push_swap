/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:04:27 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/05 16:55:49 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ps_reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (-1);
	tmp = *lst;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	return (1);
}

int		ps_rotate(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (-1);
	tmp = *lst;
	*lst = (*lst)->next;
	while ((*lst)->next != NULL)
		lst = &((*lst)->next);
	(*lst)->next = tmp;
	tmp->next = NULL;
	return (1);
}

int		ps_push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b == NULL || a == NULL || *b == NULL)
		return (-1);
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int		ps_swap(t_list **lst)
{
	t_list	*first;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (-1);
	first = (*lst)->next;
	(*lst)->next = first->next;
	first->next = *lst;
	*lst = first;
	return (1);
}
