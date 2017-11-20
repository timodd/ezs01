#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "queue.h"
#include "processmodel.h"

int queue_test()
{
   q_node* rn1 = malloc(sizeof(q_node));
   queue q1, q2;
   q_init(&q1, 1);
   q_init(&q2, 2);
   process p1, p2, p3, p4, p5, p6;
   p1.p_state = READY;
   p2.p_state = RUNNING;
   p3.p_state = READY;
   p4.p_state = READY;
   p5.p_state = RUNNING;
   p6.p_state = READY;
   p1.p_id = 1001;
   p2.p_id = 1002;
   p3.p_id = 1111;
   p4.p_id = 1222;
   p5.p_id = 1345;
   p6.p_id = 7658;
//   q_node *n1 = q_add(&q1, &p1);
   q_add(&q1, &p1);
   q_add(&q1, &p2);
   q_add(&q1, &p3);
   q_add(&q1, &p4);
   q_add(&q1, &p5);
   q_add(&q1, &p6);
   q_add(&q2, &p6);
   q_add(&q2, &p5);
   q_add(&q2, &p4);
   q_add(&q2, &p3);
   q_add(&q2, &p2);
   q_add(&q2, &p1);
//   printf("%d %d %d %d %d %d", n1->p->p_id, n2->p->p_id, n3->p->p_id, n4->p->p_id, n5->p->p_id, n6->p->p_id);
   q_print(&q1);
   q_print(&q2);
   rn1 = q_remove(&q1);
   p_print(rn1->p);
   q_print(&q1);
   free(rn1);
   return 0;
}

void test_1()
{
   process p1, p2;
   p1.p_id = 1001;
   p1.p_state = READY;
   p2.p_state = READY;
   p2.p_id = 1002;
   p_print(&p1);
   p_switch_state(&p1);
   p_print(&p1);
   p_switch_state(&p1);
   p_print(&p1);
   p_print(&p2);
   p_switch_state(&p2);
   p_print(&p2);
   p_switch_state(NULL);
   p_print(NULL);

}

