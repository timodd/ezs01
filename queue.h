#pragma once
#include "process.h"

struct q_node
{
    struct q_node *next;
    process *p;
};

typedef struct q_node q_node;



typedef struct
{
    q_node *start;
    q_node *end;
}queue;

q_node* q_add(queue *q, process *p);
process* q_remove(queue *q);
void q_print(queue *q);
void q_init(queue *q);
int queue_test();
void test_1();
