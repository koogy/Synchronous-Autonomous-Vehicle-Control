/* --- Generated the 18/12/2022 at 0:54 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_H
#define CONTROL_H

#include "control_types.h"
#include "debug.h"
#include "globals.h"
#include "mathext.h"
#include "utilities.h"
typedef struct Control__convertMsToDps_out {
  float rpm;
} Control__convertMsToDps_out;

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out);

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

typedef struct Control__getDirection_out {
  int direction;
} Control__getDirection_out;

void Control__getDirection_step(float left, float mid, float right,
                                float action, Control__getDirection_out* _out);

typedef struct Control__getTimeAngle_out {
  float time;
} Control__getTimeAngle_out;

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out);

typedef struct Control__calculateK_out {
  float kp;
  float ki;
  float kd;
} Control__calculateK_out;

void Control__calculateK_step(float kc, float pc,
                              Control__calculateK_out* _out);

typedef struct Control__setSpeed_out {
  Globals__wheels rspeed;
} Control__setSpeed_out;

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out);

typedef struct Control__isAction_out {
  int res;
} Control__isAction_out;

void Control__isAction_step(Globals__color c, Control__isAction_out* _out);

typedef struct Control__dbg_float_out {
} Control__dbg_float_out;

void Control__dbg_float_step(string msg, float v,
                             Control__dbg_float_out* _out);

typedef struct Control__controller_mem {
  int v_52;
  float v_98;
  float v_97;
  float v_96;
  Control__st ck;
  int v_37;
  int pnr;
  float tp_2;
  float lastActionTime_1;
  int actionIndex_1;
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
