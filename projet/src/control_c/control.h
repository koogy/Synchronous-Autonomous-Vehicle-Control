/* --- Generated the 17/11/2022 at 18:35 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. sep. 29 16:55:19 CET 2022) --- */
/* --- Command line: /home/alex/.opam/4.11.1/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_H
#define CONTROL_H

#include "control_types.h"
#include "debug.h"
#include "globals.h"
#include "mathext.h"
#include "trace.h"
#include "utilities.h"
typedef struct Control__power2_out {
  int v;
} Control__power2_out;

void Control__power2_step(int value1, Control__power2_out* _out);

typedef struct Control__compare_colors_out {
  float v;
} Control__compare_colors_out;

void Control__compare_colors_step(Globals__color color1,
                                  Globals__color color2,
                                  Control__compare_colors_out* _out);

typedef struct Control__getDistances_out {
  float left;
  float middle;
  float right;
} Control__getDistances_out;

void Control__getDistances_step(Globals__sensors sens,
                                Control__getDistances_out* _out);

typedef struct Control__getDirection_out {
  int direction;
} Control__getDirection_out;

void Control__getDirection_step(Globals__sensors sens,
                                Control__getDirection_out* _out);

typedef struct Control__adjustSpeed_out {
  float s;
} Control__adjustSpeed_out;

void Control__adjustSpeed_step(float speed, Control__adjustSpeed_out* _out);

typedef struct Control__setMotorSpeed_out {
  float ls;
  float rs;
} Control__setMotorSpeed_out;

void Control__setMotorSpeed_step(float leftSpeed, float rightSpeed,
                                 Control__setMotorSpeed_out* _out);

typedef struct Control__controller_mem {
  Trace__trace_float_mem trace_float;
  Trace__trace_float_mem trace_float_2;
  Trace__trace_float_mem trace_float_3;
  Trace__trace_int_mem trace_int;
  Trace__trace_float_mem trace_float_1;
} Control__controller_mem;

typedef struct Control__controller_out {
  Globals__wheels rspeed;
  int arriving;
} Control__controller_out;

void Control__controller_reset(Control__controller_mem* self);

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self);

#endif // CONTROL_H
