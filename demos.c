#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "queue.h"
#include "processmodel.h"


#define PROCESSES 10
int pmoddemo()
{
   queue q;
   q_init(&q);
   process p[PROCESSES];
   for(int i = 0; i < PROCESSES; i++)
   {
      p[i].p_state = READY;
      p[i].p_id = i+1000;
      q_add(&q, p + i);
   }
   pctx c;
   pctx *pc= &c;
   pc->qready = &q;
   pc->running = NULL;
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   step(pc);
   print(pc);
   return 0;
}

int queuedemo()
{
   queue q1, q2;
   q_init(&q1);
   q_init(&q2);
   process p[PROCESSES];
   for(int i = 0; i < PROCESSES; i++)
   {
      p[i].p_state = READY;
      p[i].p_id = i;
      q_add(&q1, p + i);
   }


   for(int i = PROCESSES - 1; i >= 0; i--)
   {
      q_add(&q2, p + i);
   }

   process *rn = q_remove(&q1);
   puts("from this queue:");
   q_print(&q2);
   rn = q_remove(&q2);
   puts("removed:");
   p_print(rn);
   puts("from this queue:");
   q_print(&q2);

   rn = q_remove(&q1);
   puts("removed:");
   p_print(rn);
   q_print(&q1);
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

int main()
{
   pmoddemo();
//   queuedemo();
}

