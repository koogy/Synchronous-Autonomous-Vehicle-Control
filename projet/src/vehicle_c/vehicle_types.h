/* --- Generated the 17/11/2022 at 18:35 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. sep. 29 16:55:19 CET 2022) --- */
/* --- Command line: /home/alex/.opam/4.11.1/bin/heptc -c -target c vehicle.ept --- */

#ifndef VEHICLE_TYPES_H
#define VEHICLE_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "control_types.h"
#include "globals_types.h"
#include "mathext_types.h"
#include "utilities_types.h"
typedef enum {
  Vehicle__St_1_Positioning,
  Vehicle__St_1_On
} Vehicle__st_1;

Vehicle__st_1 Vehicle__st_1_of_string(char* s);

char* string_of_Vehicle__st_1(Vehicle__st_1 x, char* buf);

typedef enum {
  Vehicle__St_Stopped,
  Vehicle__St_Running,
  Vehicle__St_Preparing,
  Vehicle__St_Arrived
} Vehicle__st;

Vehicle__st Vehicle__st_of_string(char* s);

char* string_of_Vehicle__st(Vehicle__st x, char* buf);

#endif // VEHICLE_TYPES_H