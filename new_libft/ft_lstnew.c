/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstnew.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/20 15:48:13 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/20 15:48:19 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *rtn;

	rtn = malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}
