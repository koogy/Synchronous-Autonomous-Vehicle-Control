/* --- Generated the 20/11/2022 at 17:48 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. oct. 5 14:31:43 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c control.ept --- */

#ifndef CONTROL_H
#define CONTROL_H

#include "control_types.h"
#include "debug.h"
#include "globals.h"
#include "mathext.h"
#include "utilities.h"
typedef struct Control__convertMsToRpm_out {
  float rpm;
} Control__convertMsToRpm_out;

void Control__convertMsToRpm_step(float ms, Control__convertMsToRpm_out* _out);

typedef struct Control__convertRpmToDps_out {
  float dps;
} Control__convertRpmToDps_out;

void Control__convertRpmToDps_step(float rpm,
                                   Control__convertRpmToDps_out* _out);

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

void Control__getDirection_step(float left, float middle, float right,
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

typedef struct Control__d_pid_out {
} Control__d_pid_out;

void Control__d_pid_step(string msg, float left, float mid, float right,
                         float error, float turn, Control__d_pid_out* _out);

typedef struct Control__dbg_direction_out {
} Control__dbg_direction_out;

void Control__dbg_direction_step(string msg, int direction,
                                 Control__dbg_direction_out* _out);

typedef struct Control__controller_mem {
  float v_50;
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
