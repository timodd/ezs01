#pragma once
#include <stdint-gcc.h>
typedef enum { READY = 0, RUNNING = 1 } state;
typedef struct
{
   uint32_t p_id;
   state p_state;
} process;

void p_switch_state(process *p);
void p_print(process *p);

