#include "process.h"
#include <stdio.h>
#include <stdlib.h>
void p_switch_state(process *p)
{
   if (p == NULL) return;

     if (p->p_state==READY)p->p_state=RUNNING;
     else p->p_state=READY;
}

void p_print(process *p)
{
   if (p == NULL) return;


   printf("Process: %d ", p->p_id);

   if(p->p_state == READY)
      puts("(READY)");
   else
      puts("(RUNNING)");
}
