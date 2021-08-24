#include "../includes/pile.h"

int     ft_highest(Pile *pile)
{
    int highest;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    highest = actuel->nombre;
    while (actuel != NULL)
    {
        if (actuel->nombre > highest)
            highest = actuel->nombre;
        actuel = actuel->suivant;
    }
    return highest;
}

int     ft_highest_pos(Pile *pile)
{
    int highest;
    int i = 0;
    int pos = 0;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    highest = actuel->nombre;
    while (actuel != NULL)
    {   
        i++;
        if (actuel->nombre > highest)
        {
            pos = i;
            highest = actuel->nombre;
        }
        actuel = actuel->suivant;
    }
    return pos;
}

int     ft_second_highest(Pile *pile, int h)
{
    int highest;

    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;
    highest = actuel->nombre;
    while (actuel != NULL)
    {
        if (actuel->nombre > highest && actuel->nombre < h)
            highest = actuel->nombre;
        actuel = actuel->suivant;
    }
    return highest;
}

int     ft_after_highest(Pile *pile, int s_h, int h)
{   
    if (pile == NULL)
        exit( EXIT_FAILURE );
    Element *actuel = pile->premier;

    while (actuel->nombre != h)
    {   
        if (actuel->nombre == s_h)
            return 0;
        actuel = actuel->suivant;
    }
    return 1;
}