#include "../includes/pile.h"

int     ft_lowest(Pile *pile)
{
    int lowest;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    lowest = actuel->nombre;
    while (actuel != NULL)
    {
        if (actuel->nombre < lowest)
            lowest = actuel->nombre;
        actuel = actuel->suivant;
    }
    return lowest;
}

int     ft_second_lowest(Pile *pile, int l)
{
    int lowest;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    lowest = 10000;
    while (actuel != NULL)
    {   
        if (actuel->nombre < lowest && actuel->nombre > l)
            lowest = actuel->nombre;
        actuel = actuel->suivant;
    }
    return lowest;
}

int     ft_lowest_pos(Pile *pile)
{
    int lowest;
    int i = 0;
    int pos = 0;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    lowest = actuel->nombre;
    while (actuel != NULL)
    {   
        i++;
        if (actuel->nombre < lowest)
        {
            pos = i;
            lowest = actuel->nombre;
        }
        actuel = actuel->suivant;
    }
    return pos;
}

int     ft_number_pos(Pile *pile, int h)
{
    int i;

    i = 1;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    while (actuel != NULL)
    {
        if (actuel->nombre == h)
            return i;
        i++;
        actuel = actuel->suivant;
    }
    return -1;
}