/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:38:16 by ahamrad           #+#    #+#             */
/*   Updated: 2023/06/26 01:44:49 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_input(char **av, t_stack **a, int ac)
{
	char	**tab;
	int		i;
	int		tab_size;

	i = 0;
	tab = join_args(av, ac);
	tab_size = ft_tablen(tab);
	while (tab[i])
	{
		ft_check_number(tab[i], tab);
		ft_check_limits(tab[i], tab);
		i++;
	}
	ft_check_duplicates(tab, ft_tablen(tab));
	while (tab_size > 0)
	{
		push(a, ft_atoi(tab[tab_size - 1]));
		tab_size--;
	}
	free_tab2d(tab);
	if (is_sorted(*a))
	{
		free_stack(a);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		s_size;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	ft_get_input(argv, &a, argc - 1);
	s_size = stack_size(a);
	if (s_size == 2)
		sa(&a);
	else if (s_size == 3)
		sort_three(&a);
	else if (s_size == 5)
		sort_five(&a, &b);
	else
	{
		algorithm1(&a, &b);
		algorithm2(&a, &b);
	}
	free_stack(&a);
	free(b);
}
