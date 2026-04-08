/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 14:20:27 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/08 15:09:14 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	fill_stack_a(t_data	*data)
{
	int		i;
	long	temp;

	i = 0;
	while (i < data->size_a)
	{
		temp = ft_atol(data->array[i]);
		if (temp < -2147483648 || temp > 2147483647)
			return (0);
		data->stack_a[i] = (int)temp;
		i++;
	}
	return (1);
}

static int	run(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a)
		i++;
	if (check_int(data) == 0)
		return (ft_printf("Error\n", 0));
	data->stack_a = ft_calloc(data->size_a, sizeof(int));
	data->stack_b = ft_calloc(data->size_a, sizeof(int));
	if (fill_stack_a(data) == 0 || check_duplicates(data) == 0)
		return (ft_printf("Error\n"), 0);
	if (is_sorted(data) == 1)
		return (0);
	if (data->size_a == 2)
		sort_2(data);
	else if (data->size_a == 3)
		sort_3(data);
	else if (data->size_a > 3 && data->size_a <= 5)
		sort_5(data);
	else
		turk(data);
	free(data->stack_a);
	free(data->stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	data.size_b = 0;
	i = 0;
	if (argc == 1)
		return (1);
	if (argc != 2)
	{
		data.array = argv + 1;
		data.size_a = argc - 1;
	}
	else
	{
		data.array = ft_split(argv[1], ' ');
		while (data.array[i])
			i++;
		data.size_a = i;
	}
	run(&data);
	return (0);
}
