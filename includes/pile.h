#ifndef H_PILE
#define H_PILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct		s_params
{
    int nb_op;
    int lowest;
    int next_l;
    int lowest_pos;
    int second_lowest;
    int highest;
    int struct_len;
    int struct_len_max;
    int nb_rotate;
    int nb_action;
    char *push_list[20];
}					t_params;

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

// Pile *initialiser();
void empiler(Pile *pile, int nvNombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);
int     ft_stuct_len(Pile *pile);

// pile operation
void    swap_first_last(Pile *pile, int bool, t_params *params);
void    swap(Pile *pile, int bool, t_params *params);
void    rotate(Pile *pile, int bool, t_params *params);
void    reverse_rotate(Pile *pile, int bool, t_params *params);
void    push_b(Pile *pile_a, Pile *pile_b, int bool, t_params *params);

//pile calc
int     ft_lowest(Pile *pile);
int     ft_second_lowest(Pile *pile, int l);
int     ft_lowest_pos(Pile *pile);
int     ft_highest(Pile *pile);
int     ft_highest_pos(Pile *pile);
int     ft_second_highest(Pile *pile, int h);
int     ft_before_highest(Pile *pile, int s_h, int h);
int     ft_after_highest(Pile *pile, int s_h, int h);
int     ft_number_pos(Pile *pile, int h);

// checker params
int     is_double(char **av, int s, int x);
int     is_not_number(char *s);
int     is_not_int(char *s);
int     is_ok(int ac, char **av);

// utils2
t_params	ft_init_params(Pile *pile_a);
void        ft_empiler(Pile *pile_a, char **av, int ac);
int         ft_depiler(Pile *pile);

//utils solve_more_five
void    ft_action(Pile *pile_a, Pile *pile_b, t_params *params, int i);
void     ft_inf_part(Pile *pile_a, Pile *pile_b, t_params *params);
void     ft_sup_part(Pile *pile_a, Pile *pile_b, t_params *params);

int     ft_str_len(char *s);

char		*ft_itoa(int num);
int	        ft_atoi(const char *str);
int	        ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
