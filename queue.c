#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
/*why comes the warning: assignement from incompatible pointer-type [-W[...]] on line 20, 28,29 and 38 ?*/
q_node* q_add(queue *q, process *p)
{
   if (q == NULL || p == NULL)
      return NULL;
   /*a new node is dynamically added to the queue on each call of q_add. */
   q_node *node = calloc(1, sizeof(q_node));
   node->p = p;
   node->next = NULL; //the first node->next will always point to NULL
   if (q->start == NULL) //if this is the first node
   {
      q->start = node; //q->start points to first node
      q->end = node; //last = first on first call
   }
   else
   {
      node->next = q->end; // points to node which was created on the previous call of q_add
      q->end = node; // points to the current node
//      if (q->start->next == NULL)
//         q->start->next = node;
   }
   return node;
}
q_node* q_remove(queue *q)
{
   q_node* qn_removed = calloc(1, sizeof(q_node));
   q_node* tmp = calloc(1, sizeof(q_node));
   qn_removed = q->start;
   tmp = q->end;
   q->start = NULL;
   while(tmp->next)
   {
      tmp = tmp->next;
   }
   q->start = tmp;
   free(tmp);
   return qn_removed;
}
void q_print(queue *q)
{
   char *st[] = {"READY", "RUNNING"};
   printf("Warteschlange: %d\n\n", q->id);
   q_node* tmp = calloc(1, sizeof(q_node));
   tmp = q->end;
   while(tmp)
   {
      printf("Prozess_ID: %d  Status: %s\n", tmp->p->p_id, st[tmp->p->p_state]);
      tmp = tmp->next;
   }
   printf("\n");
   free(tmp);
}
void q_init(queue *q, int id)
{
   q->start = NULL;
   q->end = NULL;
   q->id = id;
}
