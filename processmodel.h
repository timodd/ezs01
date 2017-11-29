#pragma once
# include "queue.h"
# include "process.h"
struct pctx
{
queue *qready;
process *running;
};
typedef struct pctx pctx;

void print (pctx *ctx);
void step(pctx *ctx);

