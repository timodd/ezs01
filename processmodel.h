#pragma once

typedef struct
{
queue *qready;
process *running;
} pctx;

void print (pctx *ctx);
void step(pctx *ctx);

