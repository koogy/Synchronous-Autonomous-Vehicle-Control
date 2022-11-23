/* --- Generated the 23/11/2022 at 19:15 --- */
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
  
  float v_20;
  float v_19;
  int v_18;
  int v_17;
  float v_16;
  float v_15;
  int v_14;
  int v_13;
  float v_12;
  int v_11;
  int v_10;
  v_17 = (color1.blue-color2.blue);
  Control__power2_step(v_17, &Control__power2_out_st);
  v_18 = Control__power2_out_st.v;
  Mathext__float_step(v_18, &Mathext__float_out_st);
  v_19 = Mathext__float_out_st.o;
  v_13 = (color1.green-color2.green);
  v_10 = (color1.red-color2.red);
  Control__power2_step(v_13, &Control__power2_out_st);
  v_14 = Control__power2_out_st.v;
  Mathext__float_step(v_14, &Mathext__float_out_st);
  v_15 = Mathext__float_out_st.o;
  Control__power2_step(v_10, &Control__power2_out_st);
  v_11 = Control__power2_out_st.v;
  Mathext__float_step(v_11, &Mathext__float_out_st);
  v_12 = Mathext__float_out_st.o;
  v_16 = (v_12+v_15);
  v_20 = (v_16+v_19);
  Mathext__sqrt_step(v_20, &Mathext__sqrt_out_st);
  _out->v = Mathext__sqrt_out_st.o;;
}

void Control__getDistances_step(Globals__sensors sens,
                                Control__getDistances_out* _out) {
  Mathext__float_out Mathext__float_out_st;
  Mathext__int_out Mathext__int_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  
  int v_38;
  float v_37;
  float v_36;
  float v_35;
  float v_34;
  float v_33;
  int v_32;
  float v_31;
  float v_30;
  float v_29;
  float v_28;
  float v_27;
  int v_26;
  float v_25;
  float v_24;
  float v_23;
  float v_22;
  float v_21;
  Globals__color targetColor;
  Control__compare_colors_step(sens.s_road, Globals__magenta,
                               &Control__compare_colors_out_st);
  _out->right = Control__compare_colors_out_st.v;
  Control__compare_colors_step(sens.s_road, Globals__blue,
                               &Control__compare_colors_out_st);
  _out->mid = Control__compare_colors_out_st.v;
  Control__compare_colors_step(sens.s_road, Globals__cyan,
                               &Control__compare_colors_out_st);
  _out->left = Control__compare_colors_out_st.v;
  Mathext__float_step(Globals__blue.blue, &Mathext__float_out_st);
  v_35 = Mathext__float_out_st.o;
  v_36 = (v_35*Control__ratioR);
  Mathext__float_step(Globals__cyan.blue, &Mathext__float_out_st);
  v_33 = Mathext__float_out_st.o;
  v_34 = (v_33*Control__ratioL);
  v_37 = (v_34+v_36);
  Mathext__int_step(v_37, &Mathext__int_out_st);
  v_38 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.green, &Mathext__float_out_st);
  v_29 = Mathext__float_out_st.o;
  v_30 = (v_29*Control__ratioR);
  Mathext__float_step(Globals__cyan.green, &Mathext__float_out_st);
  v_27 = Mathext__float_out_st.o;
  v_28 = (v_27*Control__ratioL);
  v_31 = (v_28+v_30);
  Mathext__int_step(v_31, &Mathext__int_out_st);
  v_32 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.red, &Mathext__float_out_st);
  v_23 = Mathext__float_out_st.o;
  v_24 = (v_23*Control__ratioR);
  Mathext__float_step(Globals__cyan.red, &Mathext__float_out_st);
  v_21 = Mathext__float_out_st.o;
  v_22 = (v_21*Control__ratioL);
  v_25 = (v_22+v_24);
  Mathext__int_step(v_25, &Mathext__int_out_st);
  v_26 = Mathext__int_out_st.o;
  targetColor.red = v_26;
  targetColor.green = v_32;
  targetColor.blue = v_38;;
}

void Control__getDirection_step(float left, float mid, float right,
                                float action, float obs,
                                Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  float v_39;
  float v;
  float min;
  Utilities__min_float_step(action, right, &Utilities__min_float_out_st);
  v_39 = Utilities__min_float_out_st.o;
  Utilities__min_float_step(left, mid, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, v_39, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_46 = (min==right);
  if (v_46) {
    v_47 = -1;
  } else {
    v_47 = 0;
  };
  v_44 = (min==obs);
  v_42 = (min==action);
  v_41 = (min==mid);
  v_43 = (v_41||v_42);
  v_45 = (v_43||v_44);
  if (v_45) {
    v_48 = 0;
  } else {
    v_48 = v_47;
  };
  v_40 = (min==left);
  if (v_40) {
    _out->direction = 1;
  } else {
    _out->direction = v_48;
  };;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_53;
  float v_52;
  float v_51;
  float v_50;
  float v_49;
  float v;
  float left;
  float right;
  v_53 = -(tp);
  v_51 = (tp-turn);
  Utilities__min_float_step(v_51, tp, &Utilities__min_float_out_st);
  v_52 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_52, v_53, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_50 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_49 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_49, v_50, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_56;
  float v_55;
  float v_54;
  float v;
  float circumference;
  float arcLength;
  v_56 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_54 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_54*circumference);
  v_55 = (arcLength/100.000000);
  _out->time = (v_55/v_56);;
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
  
  Debug__world v_57;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_57 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_57, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_58;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_58 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_58, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_59;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_59 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_59, msg, &Debug__d_string_out_st);
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
  
  float v_60;
  float v;
  v = (2.000000*kp);
  v_60 = (v*dt);
  _out->ki = (v_60/pc);;
}

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out) {
  
  float v_61;
  float v;
  v_61 = (8.000000*dt);
  v = (kp*2.350000);
  _out->kd = (v/v_61);;
}

void Control__controller_reset(Control__controller_mem* self) {
  Trace__trace_float_reset(&self->trace_float);
  Trace__trace_float_reset(&self->trace_float_1);
  self->v_123 = 0.000000;
  self->v_122 = 0.000000;
  self->v_121 = 0.000000;
  self->v_120 = 0.000000;
  self->v_119 = 0.000000;
  self->v_118 = 0.000000;
  self->v_117 = 0.000000;
  self->v_116 = 0.000000;
  self->v_115 = 0.000000;
  self->v_73 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_63 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Control__calculateKi_out Control__calculateKi_out_st;
  Control__getDirection_out Control__getDirection_out_st;
  Control__calculateKd_out Control__calculateKd_out_st;
  Trace__trace_float_out Trace__trace_float_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__calculateKp_out Control__calculateKp_out_st;
  Control__getTimeAngle_out Control__getTimeAngle_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  Control__getDistances_out Control__getDistances_out_st;
  Mathext__float_out Mathext__float_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__setSpeed_out Control__setSpeed_out_st;
  
  int v_66;
  float v_65;
  Globals__wheels v_83;
  float v_82;
  Globals__wheels v_81;
  float v_80;
  int v_79;
  Globals__itielt v_78;
  Globals__itielt v_77;
  int v_76;
  float v_75;
  int v_74;
  int v_72;
  int v_71;
  float v_70;
  Globals__itielt v_69;
  int v_68;
  Globals__itielt v_67;
  int cpt;
  float time;
  float speed;
  int v_114;
  float v_113;
  int v_112;
  int v_111;
  float v_110;
  int v_109;
  float v_108;
  float v_107;
  Globals__itielt v_106;
  int v_105;
  Globals__itielt v_104;
  float v_103;
  float v_102;
  float v_101;
  float v_100;
  float v_99;
  int v_98;
  float v_97;
  float v_96;
  float v_95;
  int v_94;
  float v_93;
  float v_92;
  float v_91;
  int v_90;
  float v_89;
  float v_88;
  int v_87;
  float v_86;
  int v_85;
  Control__st v_84;
  int r_2;
  int r_1;
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
  Globals__itielt v_131;
  int v_130;
  Control__st v_129;
  int v_128;
  Control__st v_127;
  int v_126;
  int v_125;
  int v_124;
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
  float v_64;
  int v_62;
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
    v_62 = 1;
  } else {
    v_62 = 0;
  };
  compt = (v_62+self->v_63);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_64 = Mathext__float_out_st.o;
  timez = (Globals__timestep*v_64);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = timez;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_131 = iti[between(actionIndex, Globals__itinum)];
      act = v_131.act;
      v_126 = (act==Globals__Stop);
      if (v_126) {
        v_128 = true;
        v_127 = Control__St_Arrived;
      } else {
        v_128 = false;
        v_127 = Control__St_Action;
      };
      v_125 = (act==Globals__Go);
      if (v_125) {
        v_130 = true;
        v_129 = Control__St_Running;
      } else {
        v_130 = v_128;
        v_129 = v_127;
      };
      v_124 = (act==Globals__Turn);
      if (v_124) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_130;
        ns_St_Action = v_129;
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
        dt_3 = self->v_123;
        pc_3 = self->v_122;
        derivative_1 = self->v_121;
        integral_1 = self->v_120;
        lastError_1 = self->v_119;
        error_1 = self->v_118;
        kd_2 = self->v_117;
        ki_2 = self->v_116;
        kp_4 = self->v_115;
      };
      lastActionTime_St_Running = self->lastActionTime_1;
      actionIndex_St_Running = self->actionIndex_1;
      arriving_St_Running = false;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_113 = Utilities__compare_colors_out_st.correlation;
      v_114 = (v_113>=1.000000);
      if (v_114) {
        tLight = true;
      } else {
        tLight = false;
      };
      Utilities__compare_colors_step(sens.s_road, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_108 = Utilities__compare_colors_out_st.correlation;
      v_109 = (v_108>=1.000000);
      lastError = error_1;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_97 = Control__compare_colors_out_st.v;
      v_98 = (v_97>=1.000000);
      v_95 = (0.666667*integral_1);
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_93 = Control__compare_colors_out_st.v;
      v_94 = (v_93>=1.000000);
      Control__compare_colors_step(sens.s_road, Globals__blue,
                                   &Control__compare_colors_out_st);
      v_89 = Control__compare_colors_out_st.v;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_88 = Control__compare_colors_out_st.v;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_86 = Control__compare_colors_out_st.v;
      v_87 = (v_86>=1.000000);
      Control__getDistances_step(sens, &Control__getDistances_out_st);
      left = Control__getDistances_out_st.left;
      mid = Control__getDistances_out_st.mid;
      right = Control__getDistances_out_st.right;
      Control__getDirection_step(left, mid, right, v_88, v_89,
                                 &Control__getDirection_out_st);
      v_90 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_90, &Mathext__float_out_st);
      v_91 = Mathext__float_out_st.o;
      v_92 = (mid*v_91);
      if (v_87) {
        error = v_92;
      } else {
        error = error_1;
      };
      v_99 = (error-lastError);
      if (v_98) {
        derivative = v_99;
      } else {
        derivative = derivative_1;
      };
      v_96 = (v_95+error);
      if (v_94) {
        integral = v_96;
      } else {
        integral = integral_1;
      };
      Control__calculateKp_step(0.700000, &Control__calculateKp_out_st);
      kp = Control__calculateKp_out_st.kp;
      v_100 = (kp*error);
      pc = 2.370000;
      dt = 0.016000;
      Control__calculateKd_step(kp, dt, pc, &Control__calculateKd_out_st);
      kd = Control__calculateKd_out_st.kd;
      v_103 = (kd*derivative);
      Control__calculateKi_step(kp, dt, pc, &Control__calculateKi_out_st);
      ki = Control__calculateKi_out_st.ki;
      v_101 = (ki*integral);
      v_102 = (v_100+v_101);
      turn = (v_102+v_103);
      if (tLight) {
        v_85 = true;
        v_84 = Control__St_TrafficLight;
      } else {
        v_85 = false;
        v_84 = Control__St_Running;
      };
      r_1 = r;
      if (r_1) {
        Trace__trace_float_reset(&self->trace_float);
      };
      Trace__trace_float_step("ERROR", error, &Trace__trace_float_out_st,
                              &self->trace_float);
      r_2 = r;
      if (r_2) {
        Trace__trace_float_reset(&self->trace_float_1);
      };
      Trace__trace_float_step("TIME", timez, &Trace__trace_float_out_st,
                              &self->trace_float_1);
      _out->arriving = arriving_St_Running;
      actionIndex = actionIndex_St_Running;
      lastActionTime = lastActionTime_St_Running;
      v_110 = (timez-lastActionTime);
      v_111 = (v_110>0.500000);
      v_112 = (v_109&&v_111);
      if (v_112) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Running = true;
        ns_St_Running = Control__St_Action;
      } else {
        nr_St_Running = v_85;
        ns_St_Running = v_84;
      };
      v_106 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_106.param,
                                   &Control__convertMsToDps_out_st);
      v_107 = Control__convertMsToDps_out_st.dps;
      v_104 = iti[between(actionIndex, Globals__itinum)];
      v_105 = (v_104.act==Globals__Go);
      if (v_105) {
        tp_St_Running = v_107;
      } else {
        tp_St_Running = self->tp_2;
      };
      tp = tp_St_Running;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Running = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Running;
      nr = nr_St_Running;
      _out->rspeed = rspeed_St_Running;
      self->v_123 = dt;
      self->v_122 = pc;
      self->v_121 = derivative;
      self->v_120 = integral;
      self->v_119 = lastError;
      self->v_118 = error;
      self->v_117 = kd;
      self->v_116 = ki;
      self->v_115 = kp;
      break;
    case Control__St_TrafficLight:
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_65 = Utilities__compare_colors_out_st.correlation;
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      v_66 = (v_65<1.000000);
      if (v_66) {
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
        v_74 = 0;
      } else {
        v_74 = self->v_73;
      };
      if (true) {
        v_72 = 1;
      } else {
        v_72 = 0;
      };
      cpt = (v_72+v_74);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_75 = Mathext__float_out_st.o;
      time = (Globals__timestep*v_75);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_76 = (actionIndex-1);
      v_68 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_78 = iti[between(actionIndex, Globals__itinum)];
      v_79 = (v_78.param>0.000000);
      v_77 = iti[between(v_76, Globals__itinum)];
      Control__convertMsToDps_step(v_77.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_82 = -(speed);
      v_80 = -(speed);
      v_83.left = speed;
      v_83.right = v_82;
      v_81.left = v_80;
      v_81.right = speed;
      if (v_79) {
        rspeed_St_Turn = v_81;
      } else {
        rspeed_St_Turn = v_83;
      };
      v_69 = iti[between(v_68, Globals__itinum)];
      v_67 = iti[between(actionIndex, Globals__itinum)];
      Control__getTimeAngle_step(v_67.param, v_69.param,
                                 &Control__getTimeAngle_out_st);
      v_70 = Control__getTimeAngle_out_st.time;
      v_71 = (time>v_70);
      if (v_71) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_73 = cpt;
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
  self->v_63 = compt;;
}

