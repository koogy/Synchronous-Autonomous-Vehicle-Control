/* --- Generated the 21/11/2022 at 18:42 --- */
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
                                Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  float v;
  float min;
  Utilities__min_float_step(left, mid, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, right, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_37 = (min==right);
  if (v_37) {
    v_38 = -1;
  } else {
    v_38 = 0;
  };
  v_36 = (min==mid);
  if (v_36) {
    v_39 = 0;
  } else {
    v_39 = v_38;
  };
  v_35 = (min==left);
  if (v_35) {
    _out->direction = 1;
  } else {
    _out->direction = v_39;
  };;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_44;
  float v_43;
  float v_42;
  float v_41;
  float v_40;
  float v;
  float left;
  float right;
  v_44 = -(tp);
  v_42 = (tp-turn);
  Utilities__min_float_step(v_42, tp, &Utilities__min_float_out_st);
  v_43 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_43, v_44, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_41 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_40 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_40, v_41, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__getTimeAngle_step(float deg, Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_46;
  float v_45;
  float v;
  float circumference;
  float arcLength;
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_45 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_45*circumference);
  v_46 = (arcLength/100.000000);
  _out->time = (v_46/0.239983);;
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
  
  Debug__world v_47;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_47 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_47, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_48;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_48 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_48, msg, &Debug__d_string_out_st);
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
  
  Debug__world v_49;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_49 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_49, msg, &Debug__d_string_out_st);
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
  
  float v_50;
  float v;
  v = (2.000000*kp);
  v_50 = (v*dt);
  _out->ki = (v_50/pc);;
}

void Control__calculateKd_step(float kp, float dt, float pc,
                               Control__calculateKd_out* _out) {
  
  float v_51;
  float v;
  v_51 = (8.000000*dt);
  v = (kp*2.370000);
  _out->kd = (v/v_51);;
}

void Control__controller_reset(Control__controller_mem* self) {
  self->v_95 = 0.000000;
  self->v_94 = 0.000000;
  self->v_93 = 0.000000;
  self->v_92 = 0.000000;
  self->v_91 = 0.000000;
  self->v_90 = 0.000000;
  self->v_89 = 0.000000;
  self->v_88 = 0.000000;
  self->v_87 = 0.000000;
  self->v_60 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_52 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Control__calculateKi_out Control__calculateKi_out_st;
  Control__getDistances_out Control__getDistances_out_st;
  Mathext__float_out Mathext__float_out_st;
  Control__getDirection_out Control__getDirection_out_st;
  Control__calculateKd_out Control__calculateKd_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__calculateKp_out Control__calculateKp_out_st;
  Control__setSpeed_out Control__setSpeed_out_st;
  Control__getTimeAngle_out Control__getTimeAngle_out_st;
  
  int v_55;
  float v_54;
  Globals__wheels v_66;
  Globals__wheels v_65;
  int v_64;
  Globals__itielt v_63;
  float v_62;
  int v_61;
  int v_59;
  int v_58;
  float v_57;
  Globals__itielt v_56;
  int cpt;
  float time;
  int v_86;
  float v_85;
  int v_84;
  int v_83;
  float v_82;
  int v_81;
  float v_80;
  float v_79;
  Globals__itielt v_78;
  int v_77;
  Globals__itielt v_76;
  float v_75;
  float v_74;
  float v_73;
  float v_72;
  float v_71;
  float v_70;
  int v_69;
  int v_68;
  Control__st v_67;
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
  Globals__itielt v_103;
  int v_102;
  Control__st v_101;
  int v_100;
  Control__st v_99;
  int v_98;
  int v_97;
  int v_96;
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
  float v_53;
  int v;
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
    v = 1;
  } else {
    v = 0;
  };
  compt = (v+self->v_52);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_53 = Mathext__float_out_st.o;
  timez = (Globals__timestep*v_53);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = timez;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_103 = iti[between(actionIndex, Globals__itinum)];
      act = v_103.act;
      v_98 = (act==Globals__Stop);
      if (v_98) {
        v_100 = true;
        v_99 = Control__St_Arrived;
      } else {
        v_100 = false;
        v_99 = Control__St_Action;
      };
      v_97 = (act==Globals__Go);
      if (v_97) {
        v_102 = true;
        v_101 = Control__St_Running;
      } else {
        v_102 = v_100;
        v_101 = v_99;
      };
      v_96 = (act==Globals__Turn);
      if (v_96) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_102;
        ns_St_Action = v_101;
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
        dt_3 = self->v_95;
        pc_3 = self->v_94;
        derivative_1 = self->v_93;
        integral_1 = self->v_92;
        lastError_1 = self->v_91;
        error_1 = self->v_90;
        kd_2 = self->v_89;
        ki_2 = self->v_88;
        kp_4 = self->v_87;
      };
      lastActionTime_St_Running = self->lastActionTime_1;
      actionIndex_St_Running = self->actionIndex_1;
      arriving_St_Running = false;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_85 = Utilities__compare_colors_out_st.correlation;
      v_86 = (v_85>=1.000000);
      if (v_86) {
        tLight = true;
      } else {
        tLight = false;
      };
      Utilities__compare_colors_step(sens.s_road, Globals__green,
                                     &Utilities__compare_colors_out_st);
      v_80 = Utilities__compare_colors_out_st.correlation;
      v_81 = (v_80>=1.000000);
      lastError = error_1;
      v_71 = (0.666667*integral_1);
      Control__getDistances_step(sens, &Control__getDistances_out_st);
      left = Control__getDistances_out_st.left;
      mid = Control__getDistances_out_st.mid;
      right = Control__getDistances_out_st.right;
      Control__getDirection_step(left, mid, right,
                                 &Control__getDirection_out_st);
      v_69 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_69, &Mathext__float_out_st);
      v_70 = Mathext__float_out_st.o;
      error = (mid*v_70);
      derivative = (error-lastError);
      integral = (v_71+error);
      Control__calculateKp_step(0.775000, &Control__calculateKp_out_st);
      kp = Control__calculateKp_out_st.kp;
      v_72 = (kp*error);
      pc = 2.370000;
      dt = 0.016000;
      Control__calculateKd_step(kp, dt, pc, &Control__calculateKd_out_st);
      kd = Control__calculateKd_out_st.kd;
      v_75 = (kd*derivative);
      Control__calculateKi_step(kp, dt, pc, &Control__calculateKi_out_st);
      ki = Control__calculateKi_out_st.ki;
      v_73 = (ki*integral);
      v_74 = (v_72+v_73);
      turn = (v_74+v_75);
      if (tLight) {
        v_68 = true;
        v_67 = Control__St_TrafficLight;
      } else {
        v_68 = false;
        v_67 = Control__St_Running;
      };
      _out->arriving = arriving_St_Running;
      actionIndex = actionIndex_St_Running;
      lastActionTime = lastActionTime_St_Running;
      v_82 = (timez-lastActionTime);
      v_83 = (v_82>0.500000);
      v_84 = (v_81&&v_83);
      if (v_84) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Running = true;
        ns_St_Running = Control__St_Action;
      } else {
        nr_St_Running = v_68;
        ns_St_Running = v_67;
      };
      v_78 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_78.param,
                                   &Control__convertMsToDps_out_st);
      v_79 = Control__convertMsToDps_out_st.dps;
      v_76 = iti[between(actionIndex, Globals__itinum)];
      v_77 = (v_76.act==Globals__Go);
      if (v_77) {
        tp_St_Running = v_79;
      } else {
        tp_St_Running = self->tp_2;
      };
      tp = tp_St_Running;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Running = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Running;
      nr = nr_St_Running;
      _out->rspeed = rspeed_St_Running;
      self->v_95 = dt;
      self->v_94 = pc;
      self->v_93 = derivative;
      self->v_92 = integral;
      self->v_91 = lastError;
      self->v_90 = error;
      self->v_89 = kd;
      self->v_88 = ki;
      self->v_87 = kp;
      break;
    case Control__St_TrafficLight:
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_54 = Utilities__compare_colors_out_st.correlation;
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      v_55 = (v_54<1.000000);
      if (v_55) {
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
        v_61 = 0;
      } else {
        v_61 = self->v_60;
      };
      if (true) {
        v_59 = 1;
      } else {
        v_59 = 0;
      };
      cpt = (v_59+v_61);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_62 = Mathext__float_out_st.o;
      time = (Globals__timestep*v_62);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_66.right = -1500.000000;
      v_66.left = 1500.000000;
      v_65.right = 1500.000000;
      v_65.left = -1500.000000;
      v_63 = iti[between(self->actionIndex_1, Globals__itinum)];
      v_64 = (v_63.param>0.000000);
      if (v_64) {
        rspeed_St_Turn = v_65;
      } else {
        rspeed_St_Turn = v_66;
      };
      v_56 = iti[between(self->actionIndex_1, Globals__itinum)];
      Control__getTimeAngle_step(v_56.param, &Control__getTimeAngle_out_st);
      v_57 = Control__getTimeAngle_out_st.time;
      v_58 = (time>v_57);
      if (v_58) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_60 = cpt;
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
  self->v_52 = compt;;
}

