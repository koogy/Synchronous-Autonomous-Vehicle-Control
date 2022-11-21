/* --- Generated the 21/11/2022 at 21:57 --- */
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

typedef struct Control__convertMsToDps_out {
  float dps;
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

typedef struct Control__getDistances_out {
  float left;
  float mid;
  float right;
} Control__getDistances_out;

void Control__getDistances_step(Globals__sensors sens,
                                Control__getDistances_out* _out);

typedef struct Control__getDirection_out {
  int direction;
} Control__getDirection_out;

void Control__getDirection_step(float left, float mid, float right,
                                float action, Control__getDirection_out* _out);

typedef struct Control__setSpeed_out {
  Globals__wheels rspeed;
} Control__setSpeed_out;

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out);

typedef struct Control__getTimeAngle_out {
  float time;
} Control__getTimeAngle_out;

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out);

typedef struct Control__d_pid_out {
} Control__d_pid_out;

void Control__d_pid_step(string msg, float left, float mid, float right,
                         float error, float turn, Control__d_pid_out* _out);

typedef struct Control__dbg_int_out {
} Control__dbg_int_out;

void Control__dbg_int_step(string msg, int v, Control__dbg_int_out* _out);

typedef struct Control__dbg_bool_out {
} Control__dbg_bool_out;

void Control__dbg_bool_step(string msg, int v, Control__dbg_bool_out* _out);

typedef struct Control__dbg_float_out {
} Control__dbg_float_out;

void Control__dbg_float_step(string msg, float v,
                             Control__dbg_float_out* _out);

typedef struct Control__dbg_pid_out {
} Control__dbg_pid_out;

void Control__dbg_pid_step(string msg, float error, float integral,
                           float derivative, Control__dbg_pid_out* _out);

typedef struct Control__calculateKp_out {
  float kp;
} Control__calculateKp_out;

void Control__calculateKp_step(float kc, Control__calculateKp_out* _out);

typedef struct Control__calculateKi_out {
  float ki;
} Control__calculateKi_out;

void Control__calculateKi_step(float kp, float dt, float pc,
                               Control__calculateKi_out* _out);

typedef struct Control__calculateKd_out {
  float kd;
} Control__calculateKd_out;

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out);

typedef struct Control__controller_mem {
  int v_67;
  float v_107;
  float v_106;
  float v_105;
  float v_104;
  float v_103;
  float v_102;
  float v_101;
  float v_100;
  float v_99;
  Control__st ck;
  int v_57;
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
