#include "../includes/pile.h"

void    push_b(Pile *pile_a, Pile *pile_b, int bool, t_params *params)
{
    int i = 0;
    Element *actuel_a = pile_a->premier;
    Element *first_a = pile_a->premier;
    Element *first_b = pile_b->premier;    

    while (i < 1)
    {
        actuel_a = actuel_a->suivant;
        i++;
    }
    pile_a->premier = actuel_a;
    pile_b->premier = first_a;
    first_a->suivant = first_b;

    if (bool)
        write(1, "pb", 2);
    else
        write(1, "pa", 2);
    write(1, "\n", 1);
    params->nb_op++;
}