/* --- Generated the 18/12/2022 at 0:54 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control.h"

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out) {
  
  float v;
  v = (3.472472*ms);
  _out->rpm = (v*6.000000);;
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
  
  float v_18;
  float v_17;
  int v_16;
  int v_15;
  float v_14;
  float v_13;
  int v_12;
  int v_11;
  float v_10;
  int v_9;
  int v_8;
  v_15 = (color1.blue-color2.blue);
  Control__power2_step(v_15, &Control__power2_out_st);
  v_16 = Control__power2_out_st.v;
  Mathext__float_step(v_16, &Mathext__float_out_st);
  v_17 = Mathext__float_out_st.o;
  v_11 = (color1.green-color2.green);
  v_8 = (color1.red-color2.red);
  Control__power2_step(v_11, &Control__power2_out_st);
  v_12 = Control__power2_out_st.v;
  Mathext__float_step(v_12, &Mathext__float_out_st);
  v_13 = Mathext__float_out_st.o;
  Control__power2_step(v_8, &Control__power2_out_st);
  v_9 = Control__power2_out_st.v;
  Mathext__float_step(v_9, &Mathext__float_out_st);
  v_10 = Mathext__float_out_st.o;
  v_14 = (v_10+v_13);
  v_18 = (v_14+v_17);
  Mathext__sqrt_step(v_18, &Mathext__sqrt_out_st);
  _out->v = Mathext__sqrt_out_st.o;;
}

void Control__getDirection_step(float left, float mid, float right,
                                float action, Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  float v_19;
  float v;
  float min;
  Utilities__min_float_step(action, right, &Utilities__min_float_out_st);
  v_19 = Utilities__min_float_out_st.o;
  Utilities__min_float_step(left, mid, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, v_19, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_22 = (min==right);
  if (v_22) {
    v_23 = -1;
  } else {
    v_23 = 0;
  };
  v_21 = (min==mid);
  if (v_21) {
    v_24 = 0;
  } else {
    v_24 = v_23;
  };
  v_20 = (min==left);
  if (v_20) {
    _out->direction = 1;
  } else {
    _out->direction = v_24;
  };;
}

void Control__getTimeAngle_step(float deg, float ms,
                                Control__getTimeAngle_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_27;
  float v_26;
  float v_25;
  float v;
  float circumference;
  float arcLength;
  v_27 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_25 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_25*circumference);
  v_26 = (arcLength/100.000000);
  _out->time = (v_26/v_27);;
}

void Control__calculateK_step(float kc, float pc,
                              Control__calculateK_out* _out) {
  
  float v_29;
  float v_28;
  float v;
  _out->kp = (0.600000*kc);
  v_29 = (_out->kp*pc);
  _out->kd = (v_29/0.128000);
  v = (2.000000*_out->kp);
  v_28 = (v*Control__dt);
  _out->ki = (v_28/pc);;
}

void Control__setSpeed_step(float turn, float tp, Control__setSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v_34;
  float v_33;
  float v_32;
  float v_31;
  float v_30;
  float v;
  float left;
  float right;
  v_34 = -(tp);
  v_32 = (tp-turn);
  Utilities__min_float_step(v_32, tp, &Utilities__min_float_out_st);
  v_33 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_33, v_34, &Utilities__max_float_out_st);
  right = Utilities__max_float_out_st.o;
  v_31 = -(tp);
  v = (tp+turn);
  Utilities__min_float_step(v, tp, &Utilities__min_float_out_st);
  v_30 = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v_30, v_31, &Utilities__max_float_out_st);
  left = Utilities__max_float_out_st.o;
  _out->rspeed.left = left;
  _out->rspeed.right = right;;
}

void Control__isAction_step(Globals__color c, Control__isAction_out* _out) {
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  
  float v;
  Utilities__compare_colors_step(c, Globals__green,
                                 &Utilities__compare_colors_out_st);
  v = Utilities__compare_colors_out_st.correlation;
  _out->res = (v==1.000000);;
}

void Control__dbg_float_step(string msg, float v,
                             Control__dbg_float_out* _out) {
  Debug__d_init_out Debug__d_init_out_st;
  Debug__d_float_out Debug__d_float_out_st;
  Debug__d_string_out Debug__d_string_out_st;
  
  Debug__world v_35;
  Debug__world w0;
  Debug__world w1;
  Debug__world w2;
  Debug__d_init_step(&Debug__d_init_out_st);
  v_35 = Debug__d_init_out_st.n;
  Debug__d_string_step(v_35, msg, &Debug__d_string_out_st);
  w0 = Debug__d_string_out_st.n;
  Debug__d_float_step(w0, v, &Debug__d_float_out_st);
  w1 = Debug__d_float_out_st.n;
  Debug__d_string_step(w1, "\n", &Debug__d_string_out_st);
  w2 = Debug__d_string_out_st.n;;
}

void Control__controller_reset(Control__controller_mem* self) {
  self->v_98 = 0.000000;
  self->v_97 = 0.000000;
  self->v_96 = 0.000000;
  self->v_52 = 0;
  self->tp_2 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_37 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Control__dbg_float_out Control__dbg_float_out_st;
  Control__getDirection_out Control__getDirection_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__isAction_out Control__isAction_out_st;
  Control__getTimeAngle_out Control__getTimeAngle_out_st;
  Control__compare_colors_out Control__compare_colors_out_st;
  Mathext__float_out Mathext__float_out_st;
  Control__calculateK_out Control__calculateK_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__setSpeed_out Control__setSpeed_out_st;
  
  int v_45;
  int v_44;
  int v_43;
  float v_42;
  int v_41;
  int v_40;
  float v_39;
  Globals__wheels v_62;
  float v_61;
  Globals__wheels v_60;
  float v_59;
  int v_58;
  Globals__itielt v_57;
  Globals__itielt v_56;
  int v_55;
  float v_54;
  int v_53;
  int v_51;
  int v_50;
  float v_49;
  Globals__itielt v_48;
  int v_47;
  Globals__itielt v_46;
  int cpt;
  float turn_time;
  float speed;
  int v_63;
  int v_95;
  int v_94;
  int v_93;
  float v_92;
  int v_91;
  float v_90;
  int v_89;
  int v_88;
  float v_87;
  int v_86;
  Globals__itielt v_85;
  float v_84;
  float v_83;
  float v_82;
  float v_81;
  float v_80;
  int v_79;
  float v_78;
  float v_77;
  int v_76;
  float v_75;
  float v_74;
  int v_73;
  float v_72;
  int v_71;
  float v_70;
  float v_69;
  float v_68;
  int v_67;
  Control__st v_66;
  int v_65;
  Control__st v_64;
  float derivative_1;
  float integral_1;
  float error_1;
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
  float lastError;
  float error;
  float integral;
  float derivative;
  Globals__itielt v_106;
  int v_105;
  Control__st v_104;
  int v_103;
  Control__st v_102;
  int v_101;
  int v_100;
  int v_99;
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
  float v_38;
  int v_36;
  Control__st ns;
  int r;
  int nr;
  int compt;
  float time;
  int actionIndex;
  float lastActionTime;
  float tp;
  r = self->pnr;
  if (true) {
    v_36 = 1;
  } else {
    v_36 = 0;
  };
  compt = (v_36+self->v_37);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_38 = Mathext__float_out_st.o;
  time = (Globals__timestep*v_38);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_2;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = time;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_106 = iti[between(actionIndex, Globals__itinum)];
      act = v_106.act;
      v_101 = (act==Globals__Stop);
      if (v_101) {
        v_103 = true;
        v_102 = Control__St_Arrived;
      } else {
        v_103 = false;
        v_102 = Control__St_Action;
      };
      v_100 = (act==Globals__Go);
      if (v_100) {
        v_105 = true;
        v_104 = Control__St_Go;
      } else {
        v_105 = v_103;
        v_104 = v_102;
      };
      v_99 = (act==Globals__Turn);
      if (v_99) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_105;
        ns_St_Action = v_104;
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
        derivative_1 = 0.000000;
        integral_1 = 0.000000;
        error_1 = 0.000000;
      } else {
        derivative_1 = self->v_98;
        integral_1 = self->v_97;
        error_1 = self->v_96;
      };
      lastActionTime_St_Go = self->lastActionTime_1;
      actionIndex_St_Go = self->actionIndex_1;
      arriving_St_Go = false;
      Control__dbg_float_step("TIME 1 ", time, &Control__dbg_float_out_st);
      v_95 = (sens.s_sonar<=Control__obstacleDistance);
      if (v_95) {
        isObstacle = true;
      } else {
        isObstacle = false;
      };
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_92 = Utilities__compare_colors_out_st.correlation;
      v_93 = (v_92>=1.000000);
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_90 = Utilities__compare_colors_out_st.correlation;
      v_91 = (v_90>=1.000000);
      v_94 = (v_91||v_93);
      if (v_94) {
        tLight = true;
      } else {
        tLight = false;
      };
      Control__isAction_step(sens.s_road, &Control__isAction_out_st);
      v_86 = Control__isAction_out_st.res;
      lastError = error_1;
      Control__isAction_step(sens.s_road, &Control__isAction_out_st);
      v_79 = Control__isAction_out_st.res;
      v_77 = (0.666667*integral_1);
      Control__isAction_step(sens.s_road, &Control__isAction_out_st);
      v_76 = Control__isAction_out_st.res;
      Control__compare_colors_step(sens.s_road, Globals__red,
                                   &Control__compare_colors_out_st);
      v_72 = Control__compare_colors_out_st.v;
      Control__isAction_step(sens.s_road, &Control__isAction_out_st);
      v_71 = Control__isAction_out_st.res;
      Control__compare_colors_step(sens.s_road, Globals__magenta,
                                   &Control__compare_colors_out_st);
      v_70 = Control__compare_colors_out_st.v;
      right = v_70;
      Control__compare_colors_step(sens.s_road, Globals__blue,
                                   &Control__compare_colors_out_st);
      v_69 = Control__compare_colors_out_st.v;
      mid = v_69;
      Control__compare_colors_step(sens.s_road, Globals__cyan,
                                   &Control__compare_colors_out_st);
      v_68 = Control__compare_colors_out_st.v;
      left = v_68;
      Control__getDirection_step(left, mid, right, v_72,
                                 &Control__getDirection_out_st);
      v_73 = Control__getDirection_out_st.direction;
      Mathext__float_step(v_73, &Mathext__float_out_st);
      v_74 = Mathext__float_out_st.o;
      v_75 = (mid*v_74);
      if (v_71) {
        error = error_1;
      } else {
        error = v_75;
      };
      v_80 = (error-lastError);
      if (v_79) {
        derivative = derivative_1;
      } else {
        derivative = v_80;
      };
      v_78 = (v_77+error);
      if (v_76) {
        integral = integral_1;
      } else {
        integral = v_78;
      };
      Control__calculateK_step(0.700000, 2.360000,
                               &Control__calculateK_out_st);
      kp = Control__calculateK_out_st.kp;
      ki = Control__calculateK_out_st.ki;
      kd = Control__calculateK_out_st.kd;
      v_84 = (kd*derivative);
      v_82 = (ki*integral);
      v_81 = (kp*error);
      v_83 = (v_81+v_82);
      turn = (v_83+v_84);
      if (isObstacle) {
        v_65 = true;
      } else {
        v_65 = false;
      };
      if (tLight) {
        v_67 = true;
      } else {
        v_67 = v_65;
      };
      if (isObstacle) {
        v_64 = Control__St_Obstacle;
      } else {
        v_64 = Control__St_Go;
      };
      if (tLight) {
        v_66 = Control__St_TrafficLight;
      } else {
        v_66 = v_64;
      };
      _out->arriving = arriving_St_Go;
      actionIndex = actionIndex_St_Go;
      lastActionTime = lastActionTime_St_Go;
      v_87 = (time-lastActionTime);
      v_88 = (v_87>0.500000);
      v_89 = (v_86&&v_88);
      if (v_89) {
        actionMark = true;
      } else {
        actionMark = false;
      };
      if (actionMark) {
        nr_St_Go = true;
        ns_St_Go = Control__St_Action;
      } else {
        nr_St_Go = v_67;
        ns_St_Go = v_66;
      };
      v_85 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_85.param,
                                   &Control__convertMsToDps_out_st);
      tp_St_Go = Control__convertMsToDps_out_st.rpm;
      tp = tp_St_Go;
      Control__setSpeed_step(turn, tp, &Control__setSpeed_out_st);
      rspeed_St_Go = Control__setSpeed_out_st.rspeed;
      ns = ns_St_Go;
      nr = nr_St_Go;
      _out->rspeed = rspeed_St_Go;
      self->v_98 = derivative;
      self->v_97 = integral;
      self->v_96 = error;
      break;
    case Control__St_Obstacle:
      tp_St_Obstacle = self->tp_2;
      lastActionTime_St_Obstacle = self->lastActionTime_1;
      actionIndex_St_Obstacle = self->actionIndex_1;
      arriving_St_Obstacle = false;
      v_63 = (sens.s_sonar>Control__obstacleDistance);
      if (v_63) {
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
    case Control__St_Turn:
      tp_St_Turn = self->tp_2;
      lastActionTime_St_Turn = self->lastActionTime_1;
      actionIndex_St_Turn = self->actionIndex_1;
      arriving_St_Turn = false;
      if (r) {
        v_53 = 0;
      } else {
        v_53 = self->v_52;
      };
      if (true) {
        v_51 = 1;
      } else {
        v_51 = 0;
      };
      cpt = (v_51+v_53);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_54 = Mathext__float_out_st.o;
      turn_time = (Globals__timestep*v_54);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_55 = (actionIndex-1);
      v_47 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_57 = iti[between(actionIndex, Globals__itinum)];
      v_58 = (v_57.param>0.000000);
      v_56 = iti[between(v_55, Globals__itinum)];
      Control__convertMsToDps_step(v_56.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.rpm;
      v_61 = -(speed);
      v_59 = -(speed);
      v_62.left = speed;
      v_62.right = v_61;
      v_60.left = v_59;
      v_60.right = speed;
      if (v_58) {
        rspeed_St_Turn = v_60;
      } else {
        rspeed_St_Turn = v_62;
      };
      v_48 = iti[between(v_47, Globals__itinum)];
      v_46 = iti[between(actionIndex, Globals__itinum)];
      Control__getTimeAngle_step(v_46.param, v_48.param,
                                 &Control__getTimeAngle_out_st);
      v_49 = Control__getTimeAngle_out_st.time;
      v_50 = (turn_time>v_49);
      if (v_50) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_52 = cpt;
      break;
    case Control__St_TrafficLight:
      tp_St_TrafficLight = self->tp_2;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_42 = Utilities__compare_colors_out_st.correlation;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_39 = Utilities__compare_colors_out_st.correlation;
      v_43 = (v_42==1.000000);
      v_44 = !(v_43);
      v_40 = (v_39==1.000000);
      v_41 = !(v_40);
      v_45 = (v_41&&v_44);
      if (v_45) {
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
  self->v_37 = compt;;
}

