/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 14:25:43 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 15:39:31 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_data
{
	char	**array;
	int		count;
	int		*stack_a;
	int		*stack_b;
}	t_data;

int	main(int argc, char **argv);

#endif
