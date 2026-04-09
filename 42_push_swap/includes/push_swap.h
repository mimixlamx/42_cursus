/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 14:25:43 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/09 15:45:08 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**array;
	int		size_a;
	int		size_b;
	int		*stack_a;
	int		*stack_b;
	int		*cost_b;
	int		*cost_a;
	int		*total_cost;
}	t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_5(t_data *data);
void	turk(t_data *data);
void	rush_b(t_data *data);
void	move_pos(t_data *data, int index);
void	move_neg(t_data *data, int index);
void	move_both(t_data *data, int index);
void	free_all(t_data *data);
void	exec_order(t_data *data, char *order);
void	cost_a(t_data *data);
void	cost_b(t_data *data);
void	total_cost(t_data *data);
int		main(int argc, char **argv);
int		index_min(t_data *data);
int		ft_max(int cost_a, int cost_b);
int		ft_min(int cost_a, int cost_b);
int		ft_abs(int cost);
int		best_choice(t_data *data);
int		check_int(t_data *data);
int		check_duplicates(t_data *data);
int		is_sorted(t_data *data);

#endif
