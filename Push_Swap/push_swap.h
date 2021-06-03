#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    struct s_list *next;
}             t_list;

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
    t_list *a_info;
    t_list *b_info;
}             t_record;


#endif