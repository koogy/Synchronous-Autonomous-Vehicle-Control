/* --- Generated the 18/12/2022 at 18:27 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_TYPES_H
#define CONTROL_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "globals_types.h"
#include "mathext_types.h"
#include "utilities_types.h"
typedef enum {
  Control__St_Turn,
  Control__St_TrafficLight,
  Control__St_Obstacle,
  Control__St_Go,
  Control__St_Arrived,
  Control__St_Action
} Control__st;

Control__st Control__st_of_string(char* s);

char* string_of_Control__st(Control__st x, char* buf);

static const int Control__obstacleDistance = 10;

static const float Control__dt = 0.016000;

static const float Control__cMAXSPEED_fix = 20.000000;

#endif // CONTROL_TYPES_H
