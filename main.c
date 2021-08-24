#include "./includes/pile.h"

void    ft_solve_three(Pile *pile, t_params *params)
{
    int l;
    int l2;
    int l3;

    l =  ft_number_pos(pile, ft_lowest(pile));
    l2 =  ft_number_pos(pile, ft_second_lowest(pile, ft_lowest(pile)));
    l3 =  ft_number_pos(pile, ft_second_lowest(pile, ft_second_lowest(pile, ft_lowest(pile))));
        if (l == 1 && l3 == 2 && l2 == 3)
        {
            reverse_rotate(pile, 1, params);
            swap(pile, 1, params);
        }
        if (l2 == 1 && l == 2 && l3 == 3)
            swap(pile, 1, params);
        if (l2 == 1 && l3 == 2 && l == 3)
            reverse_rotate(pile, 1, params);
        if (l3 == 1 && l == 2 && l2 == 3)
            rotate(pile, 1, params);
        if (l3 == 1 && l2 == 2 && l == 3)
        {
            swap(pile, 1, params);
            reverse_rotate(pile, 1, params);
        }
}

void    ft_solve_five(Pile *pile_a, Pile *pile_b, t_params *params)
{
        params->highest = ft_highest(pile_a);
        params->lowest = ft_lowest(pile_a);
        while (ft_stuct_len(pile_b) != 2)
        {
            while (pile_a->premier->nombre == params->highest || pile_a->premier->nombre == params->lowest)
               push_b(pile_a, pile_b, 1, params);
            if (ft_stuct_len(pile_b) == 2)
                break ;
            rotate(pile_a, 1, params);
        }
        ft_solve_three(pile_a, params);
        if (pile_b->premier->nombre < pile_a->premier->nombre)
        {
            push_b(pile_b, pile_a, 0, params);
            push_b(pile_b, pile_a, 0, params);
            rotate(pile_a, 1, params);
        }
        else
        {
            push_b(pile_b, pile_a, 0, params);
            rotate(pile_a, 1, params);
            push_b(pile_b, pile_a, 0, params);
        }
}

void    ft_solve_five_plus(Pile *pile_a, Pile *pile_b, t_params *params)
{       
        int x;

        x = 0;
        params->lowest = ft_lowest(pile_b);
        params->lowest_pos = ft_lowest_pos(pile_b);
        while (1)
        {   
            params->struct_len = ft_stuct_len(pile_b);
            params->lowest = ft_lowest(pile_b);
            params->nb_rotate = 0;
            if (ft_stuct_len(pile_a) == params->struct_len_max - 1)
                break ;
            params->lowest_pos = ft_lowest_pos(pile_b);
            if (params->lowest_pos <=  params->struct_len / 2)
                ft_inf_part(pile_a, pile_b, params);
            else
                ft_sup_part(pile_a, pile_b, params); 
            if (x != 0)
                while (params->nb_rotate != 0)
                {
                    rotate(pile_a, 1 , params);
                    params->nb_rotate--;
                }
            x = 1;
        }
}

void    ft_solve_five_plus_start(Pile *pile_a, Pile *pile_b, t_params *params)
{
    int i;

    i = 0;
    while (i < params->struct_len)
    {   
        push_b(pile_a, pile_b, 1, params);
        i++;
    }
    ft_solve_five_plus(pile_a, pile_b, params);
    push_b(pile_b, pile_a, 0, params);
    rotate(pile_a, 1, params);
}

int main(int ac, char **av)
{   
    t_params	params;
    Pile *pile_a;
    Pile *pile_b;
    
    if (is_ok(ac, av))
    {
        pile_a = malloc(sizeof(*pile_a));
        pile_a->premier = NULL;
        pile_b = malloc(sizeof(*pile_b));
        pile_b->premier = NULL;
        ft_empiler(pile_a, av, ac);
        params = ft_init_params(pile_a);
        if (params.struct_len == 3) 
            ft_solve_three(pile_a, &params);
        if (params.struct_len == 5)
            ft_solve_five(pile_a, pile_b, &params);
        if (params.struct_len > 5)
            ft_solve_five_plus_start(pile_a, pile_b, &params);
    }
    printf("\nEtat de la pile a :\n");
    afficherPile(pile_a);
    printf("\nEtat de la pile b :\n");
    afficherPile(pile_b);

    printf("--------------------- %d -------------------------\n", params.nb_op);
    
    while (ft_stuct_len(pile_a) != 0)
        ft_depiler(pile_a);
    free(pile_b);
    free(pile_a);

    return 0;
}