/* --- Generated the 22/11/2022 at 16:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. nov. 22 1:0:13 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control.h"

void Control__convertMsToRpm_step(float ms, Control__convertMsToRpm_out* _out) {
  _out->rpm = (3.472472*ms);
}

void Control__convertRpmToDps_step(float rpm,
                                   Control__convertRpmToDps_out* _out) {
  _out->dps = (rpm*6.000000);
}

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out) {
  Control__convertMsToRpm_out Control__convertMsToRpm_out_st;
  Control__convertRpmToDps_out Control__convertRpmToDps_out_st;
  
  float v;
  Control__convertMsToRpm_step(ms, &Control__convertMsToRpm_out_st);
  v = Control__convertMsToRpm_out_st.rpm;
  Control__convertRpmToDps_step(v, &Control__convertRpmToDps_out_st);
  _out->dps = Control__convertRpmToDps_out_st.dps;;
}

void Control__power2_step(int value1, Control__power2_out* _out) {
  _out->v = (value1*value1);
}

void Control__compare_colors_step(Globals__color color1,
                                  Globals__color color2,
                                  Control__compare_colors_out* _out) {
  Mathext__float_out Mathext__float_out_st;
  Control__power2_out Control__power2_out_st;
  Mathext__sqrt_out Mathext__sqrt_out_st;
  
  float v_17;
  float v_16;
  int v_15;
  int v_14;
  float v_13;
  float v_12;
  int v_11;
  int v_10;
  float v_9;
  int v_8;
  int v_7;
  v_14 = (color1.blue-color2.blue);
  Control__power2_step(v_14, &Control__power2_out_st);
  v_15 = Control__power2_out_st.v;
  Mathext__float_step(v_15, &Mathext__float_out_st);
  v_16 = Mathext__float_out_st.o;
  v_10 = (color1.green-color2.green);
  v_7 = (color1.red-color2.red);
  Control__power2_step(v_10, &Control__power2_out_st);
  v_11 = Control__power2_out_st.v;
  Mathext__float_step(v_11, &Mathext__float_out_st);
  v_12 = Mathext__float_out_st.o;
  Control__power2_step(v_7, &Control__power2_out_st);
  v_8 = Control__power2_out_st.v;
  Mathext__float_step(v_8, &Mathext__float_out_st);
  v_9 = Mathext__float_out_st.o;
  v_13 = (v_9+v_12);
  v_17 = (v_13+v_16);
  Mathext__sqrt_step(v_17, &Mathext__sqrt_out_st);
  _out->v = Mathext__sqrt_out_st.o;;
}

void Control__getDistances_step(Globals__sensors sens,
                                Control__getDistances_out* _out) {
  Mathext__float_out Mathext__float_out_st;
  Mathext__int_out Mathext__int_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  
  int v_35;
  float v_34;
  float v_33;
  float v_32;
  float v_31;
  float v_30;
  int v_29;
  float v_28;
  float v_27;
  float v_26;
  float v_25;
  float v_24;
  int v_23;
  float v_22;
  float v_21;
  float v_20;
  float v_19;
  float v_18;
  Globals__color targetColor;
  Control__compare_colors_step(sens.s_road, Globals__magenta,
                               &Control__compare_colors_out_st);
  _out->right = Control__compare_colors_out_st.v;
  Control__compare_colors_step(sens.s_road, Globals__cyan,
                               &Control__compare_colors_out_st);
  _out->left = Control__compare_colors_out_st.v;
  Mathext__float_step(Globals__blue.blue, &Mathext__float_out_st);
  v_32 = Mathext__float_out_st.o;
  v_33 = (v_32*Control__ratioR);
  Mathext__float_step(Globals__cyan.blue, &Mathext__float_out_st);
  v_30 = Mathext__float_out_st.o;
  v_31 = (v_30*Control__ratioL);
  v_34 = (v_31+v_33);
  Mathext__int_step(v_34, &Mathext__int_out_st);
  v_35 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.green, &Mathext__float_out_st);
  v_26 = Mathext__float_out_st.o;
  v_27 = (v_26*Control__ratioR);
  Mathext__float_step(Globals__cyan.green, &Mathext__float_out_st);
  v_24 = Mathext__float_out_st.o;
  v_25 = (v_24*Control__ratioL);
  v_28 = (v_25+v_27);
  Mathext__int_step(v_28, &Mathext__int_out_st);
  v_29 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.red, &Mathext__float_out_st);
  v_20 = Mathext__float_out_st.o;
  v_21 = (v_20*Control__ratioR);
  Mathext__float_step(Globals__cyan.red, &Mathext__float_out_st);
  v_18 = Mathext__float_out_st.o;
  v_19 = (v_18*Control__ratioL);
  v_22 = (v_19+v_21);
  Mathext__int_step(v_22, &Mathext__int_out_st);
  v_23 = Mathext__int_out_st.o;
  targetColor.red = v_23;
  targetColor.green = v_29;
  targetColor.blue = v_35;
  Control__compare_colors_step(sens.s_road, targetColor,
                               &Control__compare_colors_out_st);
  _out->mid = Control__compare_colors_out_st.v;;
}

void Control__getDirection_step(float left, float mid, float right,
                                float action, float obs,
                                Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  float v_36;
  float v;
  float min;
  Utilities__min_float_step(action, right, &Utilities__min_float_out_st);
  v_36 = Utilities__min_float_out_st.o;
  Utilities__min_float_step(left, mid, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, v_36, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_43 = (min==right);
  if (v_43) {
    v_44 = -1;
  } else {
    v_44 = 0;
  };
  v_41 = (min==obs);
  v_39 = (min==action);
  v_38 = (min==mid);
  v_40 = (v_38||v_39);
  v_42 = (v_40||v_41);
  if (v_42) {
    v_45 = 0;
  } else {
    v_45 = v_44;
  };
  v_37 = (min==left);
  if (v_37) {
    _out->direction = 1;
  } else {
    _out->direction = v_45;
  };;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_50;
  float v_49;
  float v_48;
  float v_47;
  float v_46;
  float v;
  float left;
  float right;
  v_50 = -(tp);
  v_48 = (tp-turn);
  Utilities__min_float_step(v_48, tp, &Utilities__min_float_out_st);
  v_49 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_49, v_50, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_47 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_46 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_46, v_47, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_53;
  float v_52;
  float v_51;
  float v;
  float circumference;
  float arcLength;
  v_53 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_51 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_51*circumference);
  v_52 = (arcLength/100.000000);
  _out->time = (v_52/v_53);;
}

void Control__d_pid_step(string msg, float left, float mid, float right,
                         float error, float turn, Control__d_pid_out* _out) {
  Debug__d_init_out Debug__d_init_out_st;
  Debug__d_float_out Debug__d_float_out_st;
  Debug__d_string_out Debug__d_string_out_st;
  
  Debug__world v;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__world w3;
  Debug__world w4;
  Debug__world w5;
  Debug__world w6;
  Debug__world w7;
  Debug__world w8;
  Debug__world w9;
  Debug__world w10;
  Debug__world w11;
  Debug__d_init_step(&Debug__d_init_out_st);
  v = Debug__d_init_out_st.n;
  Debug__d_string_step(v, msg, &Debug__d_string_out_st);
  w0 = Debug__d_string_out_st.n;
  Debug__d_string_step(w0, "{ LEFT = ", &Debug__d_string_out_st);
  w1 = Debug__d_string_out_st.n;
  Debug__d_float_step(w1, left, &Debug__d_float_out_st);
  w2 = Debug__d_float_out_st.n;
  Debug__d_string_step(w2, "; MID = ", &Debug__d_string_out_st);
  w3 = Debug__d_string_out_st.n;
  Debug__d_float_step(w3, mid, &Debug__d_float_out_st);
  w4 = Debug__d_float_out_st.n;
  Debug__d_string_step(w4, "; RIGHT = ", &Debug__d_string_out_st);
  w5 = Debug__d_string_out_st.n;
  Debug__d_float_step(w5, right, &Debug__d_float_out_st);
  w6 = Debug__d_float_out_st.n;
  Debug__d_string_step(w6, " }\n{ ERRROR : ", &Debug__d_string_out_st);
  w7 = Debug__d_string_out_st.n;
  Debug__d_float_step(w7, error, &Debug__d_float_out_st);
  w8 = Debug__d_float_out_st.n;
  Debug__d_string_step(w8, "; TURN = ", &Debug__d_string_out_st);
  w9 = Debug__d_string_out_st.n;
  Debug__d_float_step(w9, turn, &Debug__d_float_out_st);
  w10 = Debug__d_float_out_st.n;
  Debug__d_string_step(w10, " }\n", &Debug__d_string_out_st);
  w11 = Debug__d_string_out_st.n;;
}

void Control__dbg_int_step(string msg, int v, Control__dbg_int_out* _out) {
  Debug__d_init_out Debug__d_init_out_st;
  Debug__d_int_out Debug__d_int_out_st;
  Debug__d_string_out Debug__d_string_out_st;
  
  Debug__world v_54;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_54 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_54, msg, &Debug__d_string_out_st);
  w0 = Debug__d_string_out_st.n;
  Debug__d_int_step(w0, v, &Debug__d_int_out_st);
  w1 = Debug__d_int_out_st.n;
  Debug__d_string_step(w1, "\n", &Debug__d_string_out_st);
  w2 = Debug__d_string_out_st.n;;
}

void Control__dbg_bool_step(string msg, int v, Control__dbg_bool_out* _out) {
  Debug__d_init_out Debug__d_init_out_st;
  Debug__d_bool_out Debug__d_bool_out_st;
  Debug__d_string_out Debug__d_string_out_st;
  
  Debug__world v_55;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_55 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_55, msg, &Debug__d_string_out_st);
  w0 = Debug__d_string_out_st.n;
  Debug__d_bool_step(w0, v, &Debug__d_bool_out_st);
  w1 = Debug__d_bool_out_st.n;
  Debug__d_string_step(w1, "\n", &Debug__d_string_out_st);
  w2 = Debug__d_string_out_st.n;;
}

void Control__dbg_float_step(string msg, float v,
                             Control__dbg_float_out* _out) {
  Debug__d_init_out Debug__d_init_out_st;
  Debug__d_float_out Debug__d_float_out_st;
  Debug__d_string_out Debug__d_string_out_st;
  
  Debug__world v_56;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_56 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_56, msg, &Debug__d_string_out_st);
  w0 = Debug__d_string_out_st.n;
  Debug__d_float_step(w0, v, &Debug__d_float_out_st);
  w1 = Debug__d_float_out_st.n;
  Debug__d_string_step(w1, "\n", &Debug__d_string_out_st);
  w2 = Debug__d_string_out_st.n;;
}

void Control__dbg_pid_step(string msg, float error, float integral,
                           float derivative, Control__dbg_pid_out* _out) {
  Control__dbg_float_out Control__dbg_float_out_st;
  Control__dbg_float_step(msg, integral, &Control__dbg_float_out_st);
}

void Control__calculateKp_step(float kc, Control__calculateKp_out* _out) {
  _out->kp = (0.600000*kc);
}

void Control__calculateKi_step(float kp, float dt, float pc,
                               Control__calculateKi_out* _out) {
  
  float v_57;
  float v;
  v = (2.000000*kp);
  v_57 = (v*dt);
  _out->ki = (v_57/pc);;
}

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out) {
  
  float v_58;
  float v;
  v_58 = (8.000000*dt);
  v = (kp*2.350000);
  _out->kd = (v/v_58);;
}

void Control__controller_reset(Control__controller_mem* self) {
  self->v_111 = 0.000000;
  self->v_110 = 0.000000;
  self->v_109 = 0.000000;
  self->v_108 = 0.000000;
  self->v_107 = 0.000000;
  self->v_106 = 0.000000;
  self->v_105 = 0.000000;
  self->v_104 = 0.000000;
  self->v_103 = 0.000000;
  self->v_70 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_60 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Control__calculateKi_out Control__calculateKi_out_st;
  Control__getDirection_out Control__getDirection_out_st;
  Control__calculateKd_out Control__calculateKd_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__calculateKp_out Control__calculateKp_out_st;
  Control__getTimeAngle_out Control__getTimeAngle_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  Control__getDistances_out Control__getDistances_out_st;
  Mathext__float_out Mathext__float_out_st;
  Globals__dbg_sensors_out Globals__dbg_sensors_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__setSpeed_out Control__setSpeed_out_st;
  
  int v_63;
  float v_62;
  Globals__wheels v_80;
  float v_79;
  Globals__wheels v_78;
  float v_77;
  int v_76;
  Globals__itielt v_75;
  Globals__itielt v_74;
  int v_73;
  float v_72;
  int v_71;
  int v_69;
  int v_68;
  float v_67;
  Globals__itielt v_66;
  int v_65;
  Globals__itielt v_64;
  int cpt;
  float time;
  float speed;
  int v_102;
  float v_101;
  int v_100;
  int v_99;
  float v_98;
  int v_97;
  float v_96;
  float v_95;
  Globals__itielt v_94;
  int v_93;
  Globals__itielt v_92;
  float v_91;
  float v_90;
  float v_89;
  float v_88;
  float v_87;
  float v_86;
  int v_85;
  float v_84;
  float v_83;
  int v_82;
  Control__st v_81;
  float dt_3;
  float pc_3;
  float derivative_1;
  float integral_1;
  float lastError_1;
  float error_1;
  float kd_2;
  float ki_2;
  float kp_4;
  int actionMark;
  int tLight;
  float left;
  float mid;
  float right;
  float turn;
  float kp;
  float ki;
  float kd;
  float error;
  float lastError;
  float integral;
  float derivative;
  float pc;
  float dt;
  Globals__itielt v_119;
  int v_118;
  Control__st v_117;
  int v_116;
  Control__st v_115;
  int v_114;
  int v_113;
  int v_112;
  Globals__action act;
  int nr_St_Arrived;
  Control__st ns_St_Arrived;
  float tp_St_Arrived;
  float lastActionTime_St_Arrived;
  int actionIndex_St_Arrived;
  int arriving_St_Arrived;
  Globals__wheels rspeed_St_Arrived;
  int nr_St_TrafficLight;
  Control__st ns_St_TrafficLight;
  float tp_St_TrafficLight;
  float lastActionTime_St_TrafficLight;
  int actionIndex_St_TrafficLight;
  int arriving_St_TrafficLight;
  Globals__wheels rspeed_St_TrafficLight;
  int nr_St_Turn;
  Control__st ns_St_Turn;
  float tp_St_Turn;
  float lastActionTime_St_Turn;
  int actionIndex_St_Turn;
  int arriving_St_Turn;
  Globals__wheels rspeed_St_Turn;
  int nr_St_Running;
  Control__st ns_St_Running;
  float tp_St_Running;
  float lastActionTime_St_Running;
  int actionIndex_St_Running;
  int arriving_St_Running;
  Globals__wheels rspeed_St_Running;
  int nr_St_Action;
  Control__st ns_St_Action;
  float tp_St_Action;
  float lastActionTime_St_Action;
  int actionIndex_St_Action;
  int arriving_St_Action;
  Globals__wheels rspeed_St_Action;
  float v_61;
  int v_59;
  Control__st ns;
  int r;
  int nr;
  int compt;
  float timez;
  int actionIndex;
  float lastActionTime;
  float tp;
  r = self->pnr;
  if (true) {
    v_59 = 1;
  } else {
    v_59 = 0;
  };
  compt = (v_59+self->v_60);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_61 = Mathext__float_out_st.o;
  timez = (Globals__timestep*v_61);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = timez;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_119 = iti[between(actionIndex, Globals__itinum)];
      act = v_119.act;
      v_114 = (act==Globals__Stop);
      if (v_114) {
        v_116 = true;
        v_115 = Control__St_Arrived;
      } else {
        v_116 = false;
        v_115 = Control__St_Action;
      };
      v_113 = (act==Globals__Go);
      if (v_113) {
        v_118 = true;
        v_117 = Control__St_Running;
      } else {
        v_118 = v_116;
        v_117 = v_115;
      };
      v_112 = (act==Globals__Turn);
      if (v_112) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_118;
        ns_St_Action = v_117;
      };
      rspeed_St_Action.right = 0.000000;
      rspeed_St_Action.left = 0.000000;
      tp = tp_St_Action;
      ns = ns_St_Action;
      nr = nr_St_Action;
      _out->rspeed = rspeed_St_Action;
      break;
    case Control__St_Running:
      if (r) {
        dt_3 = 0.000000;
        pc_3 = 0.000000;
        derivative_1 = 0.000000;
        integral_1 = 0.000000;
        lastError_1 = 0.000000;
        error_1 = 0.000000;
        kd_2 = 0.000000;
        ki_2 = 0.000000;
        kp_4 = 0.000000;
      } else {
        dt_3 = self->v_111;
        pc_3 = self->v_110;
        derivative_1 = self->v_109;
        integral_1 = self->v_108;
        lastError_1 = self->v_107;
        error_1 = self->v_106;
        kd_2 = self->v_105;
        ki_2 = self->v_104;
        kp_4 = self->v_103;
      };
      lastActionTime_St_Running = self->lastActionTime_1;
      actionIndex_St_Running = self->actionIndex_1;
      Globals__dbg_sensors_step("sensor", sens, &Globals__dbg_sensors_out_st);
      arriving_St_Running = false;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_101 = Utilities__compare_colors_out_st.correlation;
      v_102 = (v_101>=1.000000);
      if (v_102) {
        tLight = true;
      } else {
        tLight = false;
      };
      Utilities__compare_colors_step(sens.s_road, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_96 = Utilities__compare_colors_out_st.correlation;
      v_97 = (v_96>=1.000000);
      lastError = error_1;
      v_87 = (0.666667*integral_1);
      Control__compare_colors_step(sens.s_road, Globals__blue,
                                   &Control__compare_colors_out_st);
      v_84 = Control__compare_colors_out_st.v;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_83 = Control__compare_colors_out_st.v;
      Control__getDistances_step(sens, &Control__getDistances_out_st);
      left = Control__getDistances_out_st.left;
      mid = Control__getDistances_out_st.mid;
      right = Control__getDistances_out_st.right;
      Control__getDirection_step(left, mid, right, v_83, v_84,
                                 &Control__getDirection_out_st);
      v_85 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_85, &Mathext__float_out_st);
      v_86 = Mathext__float_out_st.o;
      error = (mid*v_86);
      derivative = (error-lastError);
      integral = (v_87+error);
      Control__calculateKp_step(0.775000, &Control__calculateKp_out_st);
      kp = Control__calculateKp_out_st.kp;
      v_88 = (kp*error);
      pc = 2.370000;
      dt = 0.016000;
      Control__calculateKd_step(kp, dt, pc, &Control__calculateKd_out_st);
      kd = Control__calculateKd_out_st.kd;
      v_91 = (kd*derivative);
      Control__calculateKi_step(kp, dt, pc, &Control__calculateKi_out_st);
      ki = Control__calculateKi_out_st.ki;
      v_89 = (ki*integral);
      v_90 = (v_88+v_89);
      turn = (v_90+v_91);
      if (tLight) {
        v_82 = true;
        v_81 = Control__St_TrafficLight;
      } else {
        v_82 = false;
        v_81 = Control__St_Running;
      };
      _out->arriving = arriving_St_Running;
      actionIndex = actionIndex_St_Running;
      lastActionTime = lastActionTime_St_Running;
      v_98 = (timez-lastActionTime);
      v_99 = (v_98>0.500000);
      v_100 = (v_97&&v_99);
      if (v_100) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Running = true;
        ns_St_Running = Control__St_Action;
      } else {
        nr_St_Running = v_82;
        ns_St_Running = v_81;
      };
      v_94 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_94.param,
                                   &Control__convertMsToDps_out_st);
      v_95 = Control__convertMsToDps_out_st.dps;
      v_92 = iti[between(actionIndex, Globals__itinum)];
      v_93 = (v_92.act==Globals__Go);
      if (v_93) {
        tp_St_Running = v_95;
      } else {
        tp_St_Running = self->tp_2;
      };
      tp = tp_St_Running;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Running = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Running;
      nr = nr_St_Running;
      _out->rspeed = rspeed_St_Running;
      self->v_111 = dt;
      self->v_110 = pc;
      self->v_109 = derivative;
      self->v_108 = integral;
      self->v_107 = lastError;
      self->v_106 = error;
      self->v_105 = kd;
      self->v_104 = ki;
      self->v_103 = kp;
      break;
    case Control__St_TrafficLight:
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_62 = Utilities__compare_colors_out_st.correlation;
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      v_63 = (v_62<1.000000);
      if (v_63) {
        nr_St_TrafficLight = true;
        ns_St_TrafficLight = Control__St_Running;
      } else {
        nr_St_TrafficLight = false;
        ns_St_TrafficLight = Control__St_TrafficLight;
      };
      _out->arriving = arriving_St_TrafficLight;
      actionIndex = actionIndex_St_TrafficLight;
      lastActionTime = lastActionTime_St_TrafficLight;
      tp = tp_St_TrafficLight;
      ns = ns_St_TrafficLight;
      nr = nr_St_TrafficLight;
      rspeed_St_TrafficLight.right = 0.000000;
      rspeed_St_TrafficLight.left = 0.000000;
      _out->rspeed = rspeed_St_TrafficLight;
      break;
    case Control__St_Turn:
      tp_St_Turn = self->tp_2;
      lastActionTime_St_Turn = self->lastActionTime_1;
      actionIndex_St_Turn = self->actionIndex_1;
      arriving_St_Turn = false;
      if (r) {
        v_71 = 0;
      } else {
        v_71 = self->v_70;
      };
      if (true) {
        v_69 = 1;
      } else {
        v_69 = 0;
      };
      cpt = (v_69+v_71);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_72 = Mathext__float_out_st.o;
      time = (Globals__timestep*v_72);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_73 = (actionIndex-1);
      v_65 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_75 = iti[between(actionIndex, Globals__itinum)];
      v_76 = (v_75.param>0.000000);
      v_74 = iti[between(v_73, Globals__itinum)];
      Control__convertMsToDps_step(v_74.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_79 = -(speed);
      v_77 = -(speed);
      v_80.left = speed;
      v_80.right = v_79;
      v_78.left = v_77;
      v_78.right = speed;
      if (v_76) {
        rspeed_St_Turn = v_78;
      } else {
        rspeed_St_Turn = v_80;
      };
      v_66 = iti[between(v_65, Globals__itinum)];
      v_64 = iti[between(actionIndex, Globals__itinum)];
      Control__getTimeAngle_step(v_64.param, v_66.param,
                                 &Control__getTimeAngle_out_st);
      v_67 = Control__getTimeAngle_out_st.time;
      v_68 = (time>v_67);
      if (v_68) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_70 = cpt;
      break;
    case Control__St_Arrived:
      tp_St_Arrived = self->tp_2;
      lastActionTime_St_Arrived = self->lastActionTime_1;
      actionIndex_St_Arrived = self->actionIndex_1;
      arriving_St_Arrived = true;
      nr_St_Arrived = false;
      ns_St_Arrived = Control__St_Arrived;
      _out->arriving = arriving_St_Arrived;
      actionIndex = actionIndex_St_Arrived;
      lastActionTime = lastActionTime_St_Arrived;
      tp = tp_St_Arrived;
      ns = ns_St_Arrived;
      nr = nr_St_Arrived;
      rspeed_St_Arrived.right = 0.000000;
      rspeed_St_Arrived.left = 0.000000;
      _out->rspeed = rspeed_St_Arrived;
      break;
    default:
      break;
  };
  self->tp_2 = tp;
  self->lastActionTime_1 = lastActionTime;
  self->actionIndex_1 = actionIndex;
  self->pnr = nr;
  self->ck = ns;
  self->v_60 = compt;;
}

