/* --- Generated the 21/11/2022 at 21:57 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. oct. 5 14:31:43 CET 2022) --- */
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
  
  float v_16;
  float v_15;
  int v_14;
  int v_13;
  float v_12;
  float v_11;
  int v_10;
  int v_9;
  float v_8;
  int v_7;
  int v_6;
  v_13 = (color1.blue-color2.blue);
  Control__power2_step(v_13, &Control__power2_out_st);
  v_14 = Control__power2_out_st.v;
  Mathext__float_step(v_14, &Mathext__float_out_st);
  v_15 = Mathext__float_out_st.o;
  v_9 = (color1.green-color2.green);
  v_6 = (color1.red-color2.red);
  Control__power2_step(v_9, &Control__power2_out_st);
  v_10 = Control__power2_out_st.v;
  Mathext__float_step(v_10, &Mathext__float_out_st);
  v_11 = Mathext__float_out_st.o;
  Control__power2_step(v_6, &Control__power2_out_st);
  v_7 = Control__power2_out_st.v;
  Mathext__float_step(v_7, &Mathext__float_out_st);
  v_8 = Mathext__float_out_st.o;
  v_12 = (v_8+v_11);
  v_16 = (v_12+v_15);
  Mathext__sqrt_step(v_16, &Mathext__sqrt_out_st);
  _out->v = Mathext__sqrt_out_st.o;;
}

void Control__getDistances_step(Globals__sensors sens,
                                Control__getDistances_out* _out) {
  Mathext__float_out Mathext__float_out_st;
  Mathext__int_out Mathext__int_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  
  int v_34;
  float v_33;
  float v_32;
  float v_31;
  float v_30;
  float v_29;
  int v_28;
  float v_27;
  float v_26;
  float v_25;
  float v_24;
  float v_23;
  int v_22;
  float v_21;
  float v_20;
  float v_19;
  float v_18;
  float v_17;
  Globals__color targetColor;
  Control__compare_colors_step(sens.s_road, Globals__magenta,
                               &Control__compare_colors_out_st);
  _out->right = Control__compare_colors_out_st.v;
  Control__compare_colors_step(sens.s_road, Globals__cyan,
                               &Control__compare_colors_out_st);
  _out->left = Control__compare_colors_out_st.v;
  Mathext__float_step(Globals__blue.blue, &Mathext__float_out_st);
  v_31 = Mathext__float_out_st.o;
  v_32 = (v_31*Control__ratioR);
  Mathext__float_step(Globals__cyan.blue, &Mathext__float_out_st);
  v_29 = Mathext__float_out_st.o;
  v_30 = (v_29*Control__ratioL);
  v_33 = (v_30+v_32);
  Mathext__int_step(v_33, &Mathext__int_out_st);
  v_34 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.green, &Mathext__float_out_st);
  v_25 = Mathext__float_out_st.o;
  v_26 = (v_25*Control__ratioR);
  Mathext__float_step(Globals__cyan.green, &Mathext__float_out_st);
  v_23 = Mathext__float_out_st.o;
  v_24 = (v_23*Control__ratioL);
  v_27 = (v_24+v_26);
  Mathext__int_step(v_27, &Mathext__int_out_st);
  v_28 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.red, &Mathext__float_out_st);
  v_19 = Mathext__float_out_st.o;
  v_20 = (v_19*Control__ratioR);
  Mathext__float_step(Globals__cyan.red, &Mathext__float_out_st);
  v_17 = Mathext__float_out_st.o;
  v_18 = (v_17*Control__ratioL);
  v_21 = (v_18+v_20);
  Mathext__int_step(v_21, &Mathext__int_out_st);
  v_22 = Mathext__int_out_st.o;
  targetColor.red = v_22;
  targetColor.green = v_28;
  targetColor.blue = v_34;
  Control__compare_colors_step(sens.s_road, targetColor,
                               &Control__compare_colors_out_st);
  _out->mid = Control__compare_colors_out_st.v;;
}

void Control__getDirection_step(float left, float mid, float right,
                                float action, Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  float v_35;
  float v;
  float min;
  Utilities__min_float_step(action, right, &Utilities__min_float_out_st);
  v_35 = Utilities__min_float_out_st.o;
  Utilities__min_float_step(left, mid, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, v_35, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_40 = (min==right);
  if (v_40) {
    v_41 = -1;
  } else {
    v_41 = 0;
  };
  v_38 = (min==action);
  v_37 = (min==mid);
  v_39 = (v_37||v_38);
  if (v_39) {
    v_42 = 0;
  } else {
    v_42 = v_41;
  };
  v_36 = (min==left);
  if (v_36) {
    _out->direction = 1;
  } else {
    _out->direction = v_42;
  };;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_47;
  float v_46;
  float v_45;
  float v_44;
  float v_43;
  float v;
  float left;
  float right;
  v_47 = -(tp);
  v_45 = (tp-turn);
  Utilities__min_float_step(v_45, tp, &Utilities__min_float_out_st);
  v_46 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_46, v_47, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_44 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_43 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_43, v_44, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_50;
  float v_49;
  float v_48;
  float v;
  float circumference;
  float arcLength;
  v_50 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_48 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_48*circumference);
  v_49 = (arcLength/100.000000);
  _out->time = (v_49/v_50);;
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
  
  Debug__world v_51;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_51 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_51, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_52;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_52 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_52, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_53;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_53 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_53, msg, &Debug__d_string_out_st);
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
  
  float v_54;
  float v;
  v = (2.000000*kp);
  v_54 = (v*dt);
  _out->ki = (v_54/pc);;
}

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out) {
  
  float v_55;
  float v;
  v_55 = (8.000000*dt);
  v = (kp*2.350000);
  _out->kd = (v/v_55);;
}

void Control__controller_reset(Control__controller_mem* self) {
  self->v_107 = 0.000000;
  self->v_106 = 0.000000;
  self->v_105 = 0.000000;
  self->v_104 = 0.000000;
  self->v_103 = 0.000000;
  self->v_102 = 0.000000;
  self->v_101 = 0.000000;
  self->v_100 = 0.000000;
  self->v_99 = 0.000000;
  self->v_67 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_57 = 0;
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
  
  int v_60;
  float v_59;
  Globals__wheels v_77;
  float v_76;
  Globals__wheels v_75;
  float v_74;
  int v_73;
  Globals__itielt v_72;
  Globals__itielt v_71;
  int v_70;
  float v_69;
  int v_68;
  int v_66;
  int v_65;
  float v_64;
  Globals__itielt v_63;
  int v_62;
  Globals__itielt v_61;
  int cpt;
  float time;
  float speed;
  int v_98;
  float v_97;
  int v_96;
  int v_95;
  float v_94;
  int v_93;
  float v_92;
  float v_91;
  Globals__itielt v_90;
  int v_89;
  Globals__itielt v_88;
  float v_87;
  float v_86;
  float v_85;
  float v_84;
  float v_83;
  float v_82;
  int v_81;
  float v_80;
  int v_79;
  Control__st v_78;
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
  Globals__itielt v_115;
  int v_114;
  Control__st v_113;
  int v_112;
  Control__st v_111;
  int v_110;
  int v_109;
  int v_108;
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
  float v_58;
  int v_56;
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
    v_56 = 1;
  } else {
    v_56 = 0;
  };
  compt = (v_56+self->v_57);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_58 = Mathext__float_out_st.o;
  timez = (Globals__timestep*v_58);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = timez;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_115 = iti[between(actionIndex, Globals__itinum)];
      act = v_115.act;
      v_110 = (act==Globals__Stop);
      if (v_110) {
        v_112 = true;
        v_111 = Control__St_Arrived;
      } else {
        v_112 = false;
        v_111 = Control__St_Action;
      };
      v_109 = (act==Globals__Go);
      if (v_109) {
        v_114 = true;
        v_113 = Control__St_Running;
      } else {
        v_114 = v_112;
        v_113 = v_111;
      };
      v_108 = (act==Globals__Turn);
      if (v_108) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_114;
        ns_St_Action = v_113;
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
        dt_3 = self->v_107;
        pc_3 = self->v_106;
        derivative_1 = self->v_105;
        integral_1 = self->v_104;
        lastError_1 = self->v_103;
        error_1 = self->v_102;
        kd_2 = self->v_101;
        ki_2 = self->v_100;
        kp_4 = self->v_99;
      };
      lastActionTime_St_Running = self->lastActionTime_1;
      actionIndex_St_Running = self->actionIndex_1;
      Globals__dbg_sensors_step("SENSOR", sens, &Globals__dbg_sensors_out_st);
      arriving_St_Running = false;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_97 = Utilities__compare_colors_out_st.correlation;
      v_98 = (v_97>=1.000000);
      if (v_98) {
        tLight = true;
      } else {
        tLight = false;
      };
      Utilities__compare_colors_step(sens.s_road, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_92 = Utilities__compare_colors_out_st.correlation;
      v_93 = (v_92>=1.000000);
      lastError = error_1;
      v_83 = (0.666667*integral_1);
      Control__compare_colors_step(sens.s_road, Globals__green,
                                   &Control__compare_colors_out_st);
      v_80 = Control__compare_colors_out_st.v;
      Control__getDistances_step(sens, &Control__getDistances_out_st);
      left = Control__getDistances_out_st.left;
      mid = Control__getDistances_out_st.mid;
      right = Control__getDistances_out_st.right;
      Control__getDirection_step(left, mid, right, v_80,
                                 &Control__getDirection_out_st);
      v_81 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_81, &Mathext__float_out_st);
      v_82 = Mathext__float_out_st.o;
      error = (mid*v_82);
      derivative = (error-lastError);
      integral = (v_83+error);
      Control__calculateKp_step(0.775000, &Control__calculateKp_out_st);
      kp = Control__calculateKp_out_st.kp;
      v_84 = (kp*error);
      pc = 2.370000;
      dt = 0.016000;
      Control__calculateKd_step(kp, dt, pc, &Control__calculateKd_out_st);
      kd = Control__calculateKd_out_st.kd;
      v_87 = (kd*derivative);
      Control__calculateKi_step(kp, dt, pc, &Control__calculateKi_out_st);
      ki = Control__calculateKi_out_st.ki;
      v_85 = (ki*integral);
      v_86 = (v_84+v_85);
      turn = (v_86+v_87);
      if (tLight) {
        v_79 = true;
        v_78 = Control__St_TrafficLight;
      } else {
        v_79 = false;
        v_78 = Control__St_Running;
      };
      _out->arriving = arriving_St_Running;
      actionIndex = actionIndex_St_Running;
      lastActionTime = lastActionTime_St_Running;
      v_94 = (timez-lastActionTime);
      v_95 = (v_94>0.500000);
      v_96 = (v_93&&v_95);
      if (v_96) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Running = true;
        ns_St_Running = Control__St_Action;
      } else {
        nr_St_Running = v_79;
        ns_St_Running = v_78;
      };
      v_90 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_90.param,
                                   &Control__convertMsToDps_out_st);
      v_91 = Control__convertMsToDps_out_st.dps;
      v_88 = iti[between(actionIndex, Globals__itinum)];
      v_89 = (v_88.act==Globals__Go);
      if (v_89) {
        tp_St_Running = v_91;
      } else {
        tp_St_Running = self->tp_2;
      };
      tp = tp_St_Running;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Running = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Running;
      nr = nr_St_Running;
      _out->rspeed = rspeed_St_Running;
      self->v_107 = dt;
      self->v_106 = pc;
      self->v_105 = derivative;
      self->v_104 = integral;
      self->v_103 = lastError;
      self->v_102 = error;
      self->v_101 = kd;
      self->v_100 = ki;
      self->v_99 = kp;
      break;
    case Control__St_TrafficLight:
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_59 = Utilities__compare_colors_out_st.correlation;
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      v_60 = (v_59<1.000000);
      if (v_60) {
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
        v_68 = 0;
      } else {
        v_68 = self->v_67;
      };
      if (true) {
        v_66 = 1;
      } else {
        v_66 = 0;
      };
      cpt = (v_66+v_68);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_69 = Mathext__float_out_st.o;
      time = (Globals__timestep*v_69);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_70 = (actionIndex-1);
      v_62 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_72 = iti[between(actionIndex, Globals__itinum)];
      v_73 = (v_72.param>0.000000);
      v_71 = iti[between(v_70, Globals__itinum)];
      Control__convertMsToDps_step(v_71.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_76 = -(speed);
      v_74 = -(speed);
      v_77.left = speed;
      v_77.right = v_76;
      v_75.left = v_74;
      v_75.right = speed;
      if (v_73) {
        rspeed_St_Turn = v_75;
      } else {
        rspeed_St_Turn = v_77;
      };
      v_63 = iti[between(v_62, Globals__itinum)];
      v_61 = iti[between(actionIndex, Globals__itinum)];
      Control__getTimeAngle_step(v_61.param, v_63.param,
                                 &Control__getTimeAngle_out_st);
      v_64 = Control__getTimeAngle_out_st.time;
      v_65 = (time>v_64);
      if (v_65) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_67 = cpt;
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
  self->v_57 = compt;;
}

