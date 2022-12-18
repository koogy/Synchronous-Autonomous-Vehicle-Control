/* --- Generated the 18/12/2022 at 7:1 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_H
#define CONTROL_H

#include "control_types.h"
#include "globals.h"
#include "mathext.h"
#include "utilities.h"
typedef struct Control__convertMsToDps_out {
  float dps;
} Control__convertMsToDps_out;

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out);

typedef struct Control__getTurnTime_out {
  float time;
} Control__getTurnTime_out;

void Control__getTurnTime_step(float deg, float ms,
                               Control__getTurnTime_out* _out);

typedef struct Control__calculateK_out {
  float kp;
  float ki;
  float kd;
} Control__calculateK_out;

void Control__calculateK_step(float kc, float pc,
                              Control__calculateK_out* _out);

typedef struct Control__isActionMark_out {
  int res;
} Control__isActionMark_out;

void Control__isActionMark_step(Globals__color c,
                                Control__isActionMark_out* _out);

typedef struct Control__isTrafficLightMark_out {
  int res;
} Control__isTrafficLightMark_out;

void Control__isTrafficLightMark_step(Globals__color c,
                                      Control__isTrafficLightMark_out* _out);

typedef struct Control__controller_mem {
  int v_22;
  float v_69;
  float v_68;
  float v_67;
  int v_66;
  int v_65;
  Control__st ck;
  int v_6;
  int pnr;
  float tp_1;
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
