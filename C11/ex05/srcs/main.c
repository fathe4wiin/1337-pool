/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:57:30 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/03 21:40:05 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	op_index;
	int	(*ops[5])(int, int);

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	ops[0] = &add;
	ops[1] = &sub;
	ops[2] = &mul;
	ops[3] = &divide;
	ops[4] = &modulo;
	op_index = get_op_index(argv[2][0]);
	if (op_index == -1)
		ft_putnbr(0);
	else if (op_index == 3 && b == 0)
		write(1, "Stop : division by zero", 23);
	else if (op_index == 4 && b == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(ops[op_index](a, b));
	write(1, "\n", 1);
	return (0);
}
