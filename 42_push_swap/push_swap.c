/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 14:20:27 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/13 18:22:38 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
// verifier les cas derreur "" " " et a priori ya des soucis sur tes doublons
#include "push_swap.h"
#include <stdio.h>
static int	check_int(t_data *data)
{
	int	i;
	int	y;
	int	len;

	len = 0;
	i = 0;
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
	while(i < data->count)
	{
	ft_printf("array %d = %s\n", i, data->array[i]);
	temp = ft_atol(data->array[i]);
		printf("temp %d = %ld\n", i, temp);
		if (temp < -2147483648 || temp > 2147483647)
			return (ft_printf ("min or max\n"),0);
		data->stack_a[i] = (int)temp;
		i++;
	}
	return (1);
}

static int	check_duplicates(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < data->count)
	{
		while (y < data ->count)
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
	int	i;
	t_data	data;

	if (argc == 1)
		return(1);
	if(argc != 2)
	{
		data.array = argv + 1;
		data.count = argc - 1;
	}
	else
	{
		data.array = ft_split(argv[1], ' ');
		while (data.array[i])
			i++;
		data.count = i;
	}
	i = 0;
	while (i < data.count)
	{
		ft_printf("line array %d =%s\n", i, data.array[i]);
		i++;
	}
	if (check_int(&data) == 0)
	return (ft_printf("error1\n", 1));
	data.stack_a = ft_calloc(argc, sizeof(int ));
	data.stack_b = ft_calloc(argc, sizeof(int ));
	if(fill_stack_a(&data) == 0 || check_duplicates(&data) == 0)
		return (ft_printf("error2\n"), 1);

	i = 0;
	while (i < data.count)
	{
		ft_printf("line %d =%d\n", i, data.stack_a[i]);
		i++;
	}
	return (ft_printf("the end tkt\n", 0));
}
