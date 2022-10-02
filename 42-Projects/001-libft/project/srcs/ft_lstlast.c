/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:30:00 by maalexan          #+#    #+#             */
/*   Updated: 2022/10/01 21:30:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
		lst = lst->next;
	return (lst);
}
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	if (!lst)
		return (NULL);
	cur = lst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return (cur);
}
