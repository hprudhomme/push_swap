#include "../includes/pile.h"

t_params	ft_init_params(Pile *pile_a)
{
	t_params	params;

	params.nb_op = 0;
    params.lowest = 0;
    params.lowest_pos = 0;
    params.second_lowest = 0;
    params.highest = ft_highest(pile_a);;
    params.struct_len = ft_stuct_len(pile_a);
    params.struct_len_max = ft_stuct_len(pile_a);
    params.nb_rotate = 0;
	return (params);
}

void    ft_empiler(Pile *pile_a, char **av, int ac)
{
    int n;

    n = 0;
    ac--;
    while (ac > 0)
    {   
        n = ft_atoi(av[ac]);
        empiler(pile_a, n);
        ac--;
    }
}

int ft_depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}