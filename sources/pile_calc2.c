#include "../includes/pile.h"

int     ft_before_highest(Pile *pile, int s_h, int h)
{   
    if (pile == NULL)
        exit( EXIT_FAILURE );
    Element *actuel = pile->premier;

    while (actuel->nombre != h)
    {
        if (actuel->nombre == s_h)
            return 1;
        actuel = actuel->suivant;
    }
    return 0;
}