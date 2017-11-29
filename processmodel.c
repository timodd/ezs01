# include <stdio.h>
# include <stdlib.h>
# include "processmodel.h"
# include "queue.h"
void print(pctx *ctx)
{
   printf("\n");
   p_print(ctx->running);
   printf("queue:\n");
   q_print(ctx->qready);
}

void step (pctx *ctx)
{
   p_switch_state(ctx->running);
   q_add(ctx->qready,ctx->running);
   ctx->running = q_remove(ctx->qready);
   p_switch_state(ctx->running);
}
