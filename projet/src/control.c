/* --- Generated the 17/12/2022 at 21:7 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

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
                                float action, Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
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
  v_42 = (min==right);
  if (v_42) {
    v_43 = -1;
  } else {
    v_43 = 0;
  };
  v_41 = (min==mid);
  if (v_41) {
    v_44 = 0;
  } else {
    v_44 = v_43;
  };
  v_40 = (min==left);
  if (v_40) {
    _out->direction = 1;
  } else {
    _out->direction = v_44;
  };;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_49;
  float v_48;
  float v_47;
  float v_46;
  float v_45;
  float v;
  float left;
  float right;
  v_49 = -(tp);
  v_47 = (tp-turn);
  Utilities__min_float_step(v_47, tp, &Utilities__min_float_out_st);
  v_48 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_48, v_49, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_46 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_45 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_45, v_46, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_52;
  float v_51;
  float v_50;
  float v;
  float circumference;
  float arcLength;
  v_52 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_50 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_50*circumference);
  v_51 = (arcLength/100.000000);
  _out->time = (v_51/v_52);;
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
  
  Debug__world v_53;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_53 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_53, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_54;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_54 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_54, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_55;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_55 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_55, msg, &Debug__d_string_out_st);
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
  
  float v_56;
  float v;
  v = (2.000000*kp);
  v_56 = (v*dt);
  _out->ki = (v_56/pc);;
}

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out) {
  
  float v_57;
  float v;
  v_57 = (8.000000*dt);
  v = (kp*pc);
  _out->kd = (v/v_57);;
}

void Control__controller_reset(Control__controller_mem* self) {
  Trace__trace_float_reset(&self->trace_float);
  Trace__trace_float_reset(&self->trace_float_1);
  self->v_125 = 0.000000;
  self->v_124 = 0.000000;
  self->v_123 = 0.000000;
  self->v_122 = 0.000000;
  self->v_121 = 0.000000;
  self->v_120 = 0.000000;
  self->v_119 = 0.000000;
  self->v_118 = 0.000000;
  self->v_117 = 0.000000;
  self->v_69 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_59 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Control__calculateKi_out Control__calculateKi_out_st;
  Control__dbg_int_out Control__dbg_int_out_st;
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
  
  int v_62;
  float v_61;
  Globals__wheels v_79;
  float v_78;
  Globals__wheels v_77;
  float v_76;
  int v_75;
  Globals__itielt v_74;
  Globals__itielt v_73;
  int v_72;
  float v_71;
  int v_70;
  int v_68;
  int v_67;
  float v_66;
  Globals__itielt v_65;
  int v_64;
  Globals__itielt v_63;
  int cpt;
  float time;
  float speed;
  int v_80;
  int v_116;
  int v_115;
  int v_114;
  float v_113;
  int v_112;
  float v_111;
  int v_110;
  int v_109;
  float v_108;
  int v_107;
  float v_106;
  float v_105;
  Globals__itielt v_104;
  int v_103;
  Globals__itielt v_102;
  float v_101;
  float v_100;
  float v_99;
  float v_98;
  float v_97;
  int v_96;
  float v_95;
  float v_94;
  float v_93;
  int v_92;
  float v_91;
  float v_90;
  float v_89;
  int v_88;
  float v_87;
  int v_86;
  float v_85;
  int v_84;
  Control__st v_83;
  int v_82;
  Control__st v_81;
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
  int isObstacle;
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
  Globals__itielt v_133;
  int v_132;
  Control__st v_131;
  int v_130;
  Control__st v_129;
  int v_128;
  int v_127;
  int v_126;
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
  int nr_St_Obstacle;
  Control__st ns_St_Obstacle;
  float tp_St_Obstacle;
  float lastActionTime_St_Obstacle;
  int actionIndex_St_Obstacle;
  int arriving_St_Obstacle;
  Globals__wheels rspeed_St_Obstacle;
  int nr_St_Go;
  Control__st ns_St_Go;
  float tp_St_Go;
  float lastActionTime_St_Go;
  int actionIndex_St_Go;
  int arriving_St_Go;
  Globals__wheels rspeed_St_Go;
  int nr_St_Action;
  Control__st ns_St_Action;
  float tp_St_Action;
  float lastActionTime_St_Action;
  int actionIndex_St_Action;
  int arriving_St_Action;
  Globals__wheels rspeed_St_Action;
  float v_60;
  int v_58;
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
    v_58 = 1;
  } else {
    v_58 = 0;
  };
  compt = (v_58+self->v_59);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_60 = Mathext__float_out_st.o;
  timez = (Globals__timestep*v_60);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = timez;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_133 = iti[between(actionIndex, Globals__itinum)];
      act = v_133.act;
      v_128 = (act==Globals__Stop);
      if (v_128) {
        v_130 = true;
        v_129 = Control__St_Arrived;
      } else {
        v_130 = false;
        v_129 = Control__St_Action;
      };
      v_127 = (act==Globals__Go);
      if (v_127) {
        v_132 = true;
        v_131 = Control__St_Go;
      } else {
        v_132 = v_130;
        v_131 = v_129;
      };
      v_126 = (act==Globals__Turn);
      if (v_126) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_132;
        ns_St_Action = v_131;
      };
      rspeed_St_Action.right = 0.000000;
      rspeed_St_Action.left = 0.000000;
      tp = tp_St_Action;
      ns = ns_St_Action;
      nr = nr_St_Action;
      _out->rspeed = rspeed_St_Action;
      break;
    case Control__St_Go:
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
        dt_3 = self->v_125;
        pc_3 = self->v_124;
        derivative_1 = self->v_123;
        integral_1 = self->v_122;
        lastError_1 = self->v_121;
        error_1 = self->v_120;
        kd_2 = self->v_119;
        ki_2 = self->v_118;
        kp_4 = self->v_117;
      };
      lastActionTime_St_Go = self->lastActionTime_1;
      actionIndex_St_Go = self->actionIndex_1;
      arriving_St_Go = false;
      v_116 = (sens.s_sonar<=Control__obstacleDistance);
      if (v_116) {
        isObstacle = true;
      } else {
        isObstacle = false;
      };
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_113 = Utilities__compare_colors_out_st.correlation;
      v_114 = (v_113>=1.000000);
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_111 = Utilities__compare_colors_out_st.correlation;
      v_112 = (v_111>=1.000000);
      v_115 = (v_112||v_114);
      if (v_115) {
        tLight = true;
      } else {
        tLight = false;
      };
      Utilities__compare_colors_step(sens.s_road, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_106 = Utilities__compare_colors_out_st.correlation;
      v_107 = (v_106>=1.000000);
      lastError = error_1;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_95 = Control__compare_colors_out_st.v;
      v_96 = (v_95>=1.000000);
      v_93 = (0.666667*integral_1);
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_91 = Control__compare_colors_out_st.v;
      v_92 = (v_91>=1.000000);
      Control__compare_colors_step(sens.s_road, Globals__red,
                                   &Control__compare_colors_out_st);
      v_87 = Control__compare_colors_out_st.v;
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_85 = Control__compare_colors_out_st.v;
      v_86 = (v_85>=1.000000);
      Control__getDistances_step(sens, &Control__getDistances_out_st);
      left = Control__getDistances_out_st.left;
      mid = Control__getDistances_out_st.mid;
      right = Control__getDistances_out_st.right;
      Control__getDirection_step(left, mid, right, v_87,
                                 &Control__getDirection_out_st);
      v_88 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_88, &Mathext__float_out_st);
      v_89 = Mathext__float_out_st.o;
      v_90 = (mid*v_89);
      if (v_86) {
        error = v_90;
      } else {
        error = error_1;
      };
      v_97 = (error-lastError);
      if (v_96) {
        derivative = v_97;
      } else {
        derivative = derivative_1;
      };
      v_94 = (v_93+error);
      if (v_92) {
        integral = v_94;
      } else {
        integral = integral_1;
      };
      Control__calculateKp_step(0.700000, &Control__calculateKp_out_st);
      kp = Control__calculateKp_out_st.kp;
      v_98 = (kp*error);
      pc = 2.370000;
      dt = 0.016000;
      Control__calculateKd_step(kp, dt, pc, &Control__calculateKd_out_st);
      kd = Control__calculateKd_out_st.kd;
      v_101 = (kd*derivative);
      Control__calculateKi_step(kp, dt, pc, &Control__calculateKi_out_st);
      ki = Control__calculateKi_out_st.ki;
      v_99 = (ki*integral);
      v_100 = (v_98+v_99);
      turn = (v_100+v_101);
      if (isObstacle) {
        v_82 = true;
      } else {
        v_82 = false;
      };
      if (tLight) {
        v_84 = true;
      } else {
        v_84 = v_82;
      };
      if (isObstacle) {
        v_81 = Control__St_Obstacle;
      } else {
        v_81 = Control__St_Go;
      };
      if (tLight) {
        v_83 = Control__St_TrafficLight;
      } else {
        v_83 = v_81;
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
      _out->arriving = arriving_St_Go;
      actionIndex = actionIndex_St_Go;
      lastActionTime = lastActionTime_St_Go;
      v_108 = (timez-lastActionTime);
      v_109 = (v_108>0.500000);
      v_110 = (v_107&&v_109);
      if (v_110) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Go = true;
        ns_St_Go = Control__St_Action;
      } else {
        nr_St_Go = v_84;
        ns_St_Go = v_83;
      };
      v_104 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_104.param,
                                   &Control__convertMsToDps_out_st);
      v_105 = Control__convertMsToDps_out_st.dps;
      v_102 = iti[between(actionIndex, Globals__itinum)];
      v_103 = (v_102.act==Globals__Go);
      if (v_103) {
        tp_St_Go = v_105;
      } else {
        tp_St_Go = self->tp_2;
      };
      tp = tp_St_Go;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Go = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Go;
      nr = nr_St_Go;
      _out->rspeed = rspeed_St_Go;
      self->v_125 = dt;
      self->v_124 = pc;
      self->v_123 = derivative;
      self->v_122 = integral;
      self->v_121 = lastError;
      self->v_120 = error;
      self->v_119 = kd;
      self->v_118 = ki;
      self->v_117 = kp;
      break;
    case Control__St_Obstacle:
      tp_St_Obstacle = self->tp_2;
      lastActionTime_St_Obstacle = self->lastActionTime_1;
      actionIndex_St_Obstacle = self->actionIndex_1;
      Control__dbg_int_step("IN OBSTACLE", 0, &Control__dbg_int_out_st);
      arriving_St_Obstacle = false;
      v_80 = (sens.s_sonar>Control__obstacleDistance);
      if (v_80) {
        nr_St_Obstacle = true;
        ns_St_Obstacle = Control__St_Go;
      } else {
        nr_St_Obstacle = false;
        ns_St_Obstacle = Control__St_Obstacle;
      };
      _out->arriving = arriving_St_Obstacle;
      actionIndex = actionIndex_St_Obstacle;
      lastActionTime = lastActionTime_St_Obstacle;
      tp = tp_St_Obstacle;
      rspeed_St_Obstacle.right = 0.000000;
      rspeed_St_Obstacle.left = 0.000000;
      ns = ns_St_Obstacle;
      nr = nr_St_Obstacle;
      _out->rspeed = rspeed_St_Obstacle;
      break;
    case Control__St_TrafficLight:
      Utilities__compare_colors_step(sens.s_front, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_61 = Utilities__compare_colors_out_st.correlation;
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      v_62 = (v_61>=1.000000);
      if (v_62) {
        nr_St_TrafficLight = true;
        ns_St_TrafficLight = Control__St_Go;
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
        v_70 = 0;
      } else {
        v_70 = self->v_69;
      };
      if (true) {
        v_68 = 1;
      } else {
        v_68 = 0;
      };
      cpt = (v_68+v_70);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_71 = Mathext__float_out_st.o;
      time = (Globals__timestep*v_71);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_72 = (actionIndex-1);
      v_64 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_74 = iti[between(actionIndex, Globals__itinum)];
      v_75 = (v_74.param>0.000000);
      v_73 = iti[between(v_72, Globals__itinum)];
      Control__convertMsToDps_step(v_73.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_78 = -(speed);
      v_76 = -(speed);
      v_79.left = speed;
      v_79.right = v_78;
      v_77.left = v_76;
      v_77.right = speed;
      if (v_75) {
        rspeed_St_Turn = v_77;
      } else {
        rspeed_St_Turn = v_79;
      };
      v_65 = iti[between(v_64, Globals__itinum)];
      v_63 = iti[between(actionIndex, Globals__itinum)];
      Control__getTimeAngle_step(v_63.param, v_65.param,
                                 &Control__getTimeAngle_out_st);
      v_66 = Control__getTimeAngle_out_st.time;
      v_67 = (time>v_66);
      if (v_67) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_69 = cpt;
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
  self->v_59 = compt;;
}

