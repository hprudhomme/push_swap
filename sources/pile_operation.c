#include "../includes/pile.h"

void    swap_first_last(Pile *pile, int bool, t_params *params)
{
    int tmp;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    Element *first = pile->premier;
    Element *last;


    while (actuel != NULL)
    {
        last = actuel;
        actuel = actuel->suivant;
    }
    tmp = last->nombre;
    last->nombre = first->nombre;
    first->nombre = tmp;
    if (bool)
        write(1, "sa", 2);
    else
        write(1, "sb", 2);
    write(1, "\n", 1);
    params->nb_op++;
}

void    swap(Pile *pile, int bool, t_params *params)
{
    int i = 0;
    int tmp;

    Element *actuel = pile->premier;
    Element *first = pile->premier;

    while (i < 1)
    {
        actuel = actuel->suivant;
        i++;
    }
    tmp = actuel->nombre;
    actuel->nombre = first->nombre;
    first->nombre = tmp;
    if (bool)
        write(1, "sa", 2);
    else
        write(1, "sb", 2);
    write(1, "\n", 1);
    params->nb_op++;
}

void    rotate(Pile *pile, int bool, t_params *params)
{   
    int i = 0;
    Element *actuel = pile->premier;
    Element *first = pile->premier;
    Element *last;

    while (i < 1)
    {
        actuel = actuel->suivant;
        i++;
    }
    pile->premier = actuel;

    while (actuel != NULL)
    {
        last = actuel;
        actuel = actuel->suivant;
    }
    last->suivant = first;
    first->suivant = NULL;
    if (bool)
        write(1, "ra", 2);
    else
        write(1, "rb", 2);
    write(1, "\n", 1);
    params->nb_op++;
}

void    reverse_rotate(Pile *pile, int bool, t_params *params)
{   
    int i = 0;
    int stuct_len = ft_stuct_len(pile);
    Element *actuel = pile->premier;
    Element *first = pile->premier;
    Element *before_last;
    Element *last;

    pile->premier = actuel;
    while (i < stuct_len - 1)
    {   
        before_last = actuel;
        actuel = actuel->suivant;
        i++;
    }
    while (actuel != NULL)
    {   
        last = actuel;
        actuel = actuel->suivant;
    }
    pile->premier = last;
    last->suivant = first;
    before_last->suivant = NULL;
    if (bool)
        write(1, "rra", 3);
    else
        write(1, "rrb", 3);
    write(1, "\n", 1);
    params->nb_op++;
}