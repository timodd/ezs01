#pragma once
#include "process.h"

typedef struct
{
    struct q_node *next;
    process *p;
}q_node;



typedef struct
{
    uint32_t id;
    q_node *start;
    q_node *end;
}queue;

q_node* q_add(queue *q, process *p);
q_node* q_remove(queue *q);
void q_print(queue *q);
void q_init(queue *q, int id);
int queue_test();
void test_1();
