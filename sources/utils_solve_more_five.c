#include "../includes/pile.h"

void     ft_action(Pile *pile_a, Pile *pile_b, t_params *params, int i)
{
    while (params->nb_action >= 0)
    {
        while (pile_b->premier->nombre != ft_atoi(params->push_list[params->nb_action]))
        {   
            if (i)
                rotate(pile_b, 0, params);
            else
                reverse_rotate(pile_b, 0, params);
        }
        push_b(pile_b, pile_a, 0, params);
        params->nb_action--;
    }
}

void     ft_inf_part(Pile *pile_a, Pile *pile_b, t_params *params)
{   
    params->nb_action = 1;
    params->next_l = ft_second_lowest(pile_b, params->lowest);
    params->push_list[0] = ft_itoa(params->lowest);   
    while (ft_before_highest(pile_b, params->next_l, params->lowest))
    {   
        params->push_list[params->nb_action] = ft_itoa(params->next_l);
        params->lowest = params->next_l;
        params->next_l = ft_second_lowest(pile_b, params->lowest);
        params->nb_action++;
    }
    params->push_list[params->nb_action] = NULL;
    params->nb_rotate += params->nb_action;
    params->nb_action--;
    ft_action(pile_a, pile_b, params, 1);
}

void     ft_sup_part(Pile *pile_a, Pile *pile_b, t_params *params)
{   
    params->nb_action = 1;
    params->next_l = ft_second_lowest(pile_b, params->lowest);
    params->push_list[0] = ft_itoa(params->lowest);
    
    while (ft_after_highest(pile_b, params->next_l, params->lowest))
    {   
        params->push_list[params->nb_action] = ft_itoa(params->next_l);
        params->lowest = params->next_l;
        params->next_l = ft_second_lowest(pile_b, params->lowest);
        params->nb_action++;
    }
    params->push_list[params->nb_action] = NULL;
    params->nb_rotate += params->nb_action;
    params->nb_action--;
    ft_action(pile_a, pile_b, params, 0);
}