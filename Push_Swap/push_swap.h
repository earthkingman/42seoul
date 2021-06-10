#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node       t_node;

struct s_node
{
    int value;
    t_node *next;
};

typedef struct s_record
{
    int count;
    int argc;
    char **argv;
    int max;
    int min;
    int pa_num;
    int rra_num;
    int rrb_num;
    int a_now_num;
    int b_now_num;
    t_node *check_overlap;
    t_node *a_info;
    t_node *b_info;
}             t_record;

void sa(t_node **a);
void sb(t_node **b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rr(t_node **a, t_node **b);
long integer_Conversion(char *argv);
int duplicateCheck(t_record *r, t_node **a, int value);
void add_Node(t_record *r, t_node **a, int value);
void fill_stack(t_record *r, t_node **a_stack);
void set_record(t_record *r, int argc, char **argv);
int isItSorted(t_node **a);
void sort_three(t_record *r, t_node **a);
void swap_sort(t_record *r, t_node **a, t_node **b);
long integer_Conversion(char *argv);
int get_mid_value(t_node **node, int len);
void moveA(t_record *r, t_node **a, t_node **b, int mid);
void recordA(t_record *r);
void recordB(t_record *r);
void	sort_fixA(t_record *r, t_node **a);
void sort_many(t_record *r, t_node **a, t_node **b);
void divide_moveA(t_record *r, t_node **a, t_node **b);
void divide_moveB(t_record *r, t_node **a, t_node **b);
int		arrange_descending(t_record *r, t_node **a, t_node **b);
int		is_descending(t_record *r, t_node **a);

#endif