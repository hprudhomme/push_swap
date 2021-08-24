#include "../includes/pile.h"

int     is_double(char **av, int s, int x)
{
    int i;
    int n;

    n = 0;
    i = 1;
    while (i < x)
    {   
        n = ft_atoi(av[i]);
        if (n == s)
            return 1;
        i++;
    }
    return 0;
}

int     is_not_number(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-')
        i++;
    while (s[i])
    {
        if (!(ft_isdigit(s[i])))
            return 1;
        i++;
    }
    return 0;
}

int     is_not_int(char *s)
{   
    if (ft_strlen(s) > 11 && s[0] == '-')
        return 1;
    if (ft_strlen(s) > 10 && s[0] != '-')
        return 1;
    if (ft_strlen(s) < 11 && s[0] == '-')
        return 0;
    if (ft_strlen(s) < 10 && s[0] != '-')
        return 0;
    if (ft_strlen(s) == 10 || ft_strlen(s) == 11)
    {
        if (s[0] == '-')
        {
            if (ft_strncmp("-2147483648", s, 11) < 0)
                return 1;
        }
        else
        {
             if (ft_strncmp("2147483647", s, 10) < 0)
                return 1;
        }
    }
    return 0;
}

int     is_ok(int ac, char **av)
{
    int i;
    int n;

    i = 1;
    n = 0;
    while (i < ac)
    {   
        n = ft_atoi(av[i]);
        if (is_double(av, n, i))
            return 0;
        if (is_not_number(av[i]))
            return 0;
        if (is_not_int(av[i]))
            return 0;
        i++;
    }
    return 1;
}