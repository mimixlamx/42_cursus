/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 14:20:27 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 17:41:18 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	check_int(t_data *data)
{
	int	i;
	int	y;
	int	len;

	len = 0;
	i = 1;
	while (i < data->count)
	{
		y = 0;
		if (!data->array[i] || !data->array[i][0])
			return (0);
		len = ft_strlen(data->array[i]);
		if (data->array[i][y] == '-' || data->array[i][y] == '+')
			y++;
		if (!data->array[i][y])
			return (0);
		while (y < len)
		{
			if (data->array[i][y] < '0' || data->array[i][y] > '9')
				return (ft_printf("not a digit\n"), 0);
			y++;
		}
		i++;
	}
	return (1);
}

static int	fill_stack_a(t_data	*data)
{
	int		i;
	long	temp;

	i = 0;
	while(i < data->count - 1)
	{
	ft_printf("array %d = %s\n", i+1, data->array[i+1]);
	temp = ft_atol(data->array[i+1]);
		printf("temp %d = %ld\n", i+1, temp);
		if (temp < -2147483648 || temp > 2147483647)
			return (ft_printf ("min or max\n"),0);
		data->stack_a[i] = (int)temp;
		i++;
	}
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < data->count - 1)
	{
		while (y < data ->count - 1)
		{
			 if (data->stack_a[i] == data->stack_a[y])
				return (ft_printf("duplicate\n"), 0);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.array = argv;
	data.count = argc;
	if (check_int(&data) == 0)
		return (ft_printf("error\n", 1));
	data.stack_a = ft_calloc(argc, sizeof(int ));
	data.stack_b = ft_calloc(argc, sizeof(int ));
	if(fill_stack_a(&data) == 0 || check_duplicates(&data) == 0)
		return (ft_printf("error\n"), 1);
	int	i;
	i = 0;
	while (i < data.count - 1)
	{
		ft_printf("line %d =%d\n", i, data.stack_a[i]);
		i++;
	}
	return (ft_printf("the end tkt\n", 0));
}
