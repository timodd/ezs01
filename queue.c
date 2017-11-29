#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

q_node* q_add(queue *q, process *p)
{
   if (q == NULL || p == NULL)
      return NULL;
   q_node *node = calloc(1, sizeof(q_node));
   node->p = p;
   node->next = NULL;
   if (q->start == NULL) //if this is the first node
   {
      q->start = node; //q->start points to first node
      q->end = node; //last = first on first call
   }
   else
   {
	 q->end->next = node; //end still points to previous node(next is current)
   	 q->end = node; // now end points to current node (end->next to NULL)
   }
   return node;
}



process* q_remove(queue *q)
{
   process* removed;
   q_node* tmp;
   removed = q->start->p;
   tmp = q->start;
   if (removed == NULL || tmp == NULL) return NULL;
   q->start = q->start->next; 
   free(tmp);
   return removed;
}


void q_print(queue *q)
{
   q_node* tmp = q->start;
   while(tmp)
   {
      p_print(tmp->p);	   
      tmp = tmp->next;
   }
   printf("\n");
}


void q_init(queue *q)
{
   q->start = NULL;
   q->end = NULL;
}
