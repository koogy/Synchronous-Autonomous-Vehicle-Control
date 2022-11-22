/* --- Generated the 22/11/2022 at 16:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. nov. 22 1:0:13 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_TYPES_H
#define CONTROL_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "debug_types.h"
#include "globals_types.h"
#include "mathext_types.h"
#include "utilities_types.h"
typedef enum {
  Control__St_Turn,
  Control__St_TrafficLight,
  Control__St_Running,
  Control__St_Arrived,
  Control__St_Action
} Control__st;

Control__st Control__st_of_string(char* s);

char* string_of_Control__st(Control__st x, char* buf);

static const float Control__ratioL = 0.500000;

static const float Control__ratioR = 0.500000;

#endif // CONTROL_TYPES_H
