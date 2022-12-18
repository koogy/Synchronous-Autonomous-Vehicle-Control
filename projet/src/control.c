/* --- Generated the 18/12/2022 at 18:27 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control.h"

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out) {
  Mathext__floor_out Mathext__floor_out_st;
  Utilities__min_float_out Utilities__min_float_out_st;
  
  float v_2;
  float v_1;
  float v;
  Utilities__min_float_step(ms, Control__cMAXSPEED_fix,
                            &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  v_1 = (3.472472*v);
  v_2 = (v_1*6.000000);
  Mathext__floor_step(v_2, &Mathext__floor_out_st);
  _out->dps = Mathext__floor_out_st.o;;
}

void Control__getTurnTime_step(float deg, float ms,
                               Control__getTurnTime_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_4;
  float v_3;
  float v;
  float circumference;
  float arcLength;
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_3 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_3*circumference);
  v_4 = (arcLength/ms);
  _out->time = (v_4-Globals__timestep);;
}

void Control__calculateK_step(float kc, float pc,
                              Control__calculateK_out* _out) {
  
  float v_6;
  float v_5;
  float v;
  _out->kp = (0.600000*kc);
  v_6 = (_out->kp*pc);
  _out->kd = (v_6/0.128000);
  v = (2.000000*_out->kp);
  v_5 = (v*Control__dt);
  _out->ki = (v_5/pc);;
}

void Control__isActionMark_step(Globals__color c,
                                Control__isActionMark_out* _out) {
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  
  float v;
  Utilities__compare_colors_step(c, Globals__green,
                                 &Utilities__compare_colors_out_st);
  v = Utilities__compare_colors_out_st.correlation;
  _out->res = (v==1.000000);;
}

void Control__isTrafficLightMark_step(Globals__color c,
                                      Control__isTrafficLightMark_out* _out) {
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  
  float v;
  Utilities__compare_colors_step(c, Globals__red,
                                 &Utilities__compare_colors_out_st);
  v = Utilities__compare_colors_out_st.correlation;
  _out->res = (v==1.000000);;
}

void Control__controller_reset(Control__controller_mem* self) {
  self->v_56 = 0.000000;
  self->v_55 = 0.000000;
  self->v_54 = 0.000000;
  self->v_53 = false;
  self->v_52 = false;
  self->v_19 = 0;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Mathext__float_out Mathext__float_out_st;
  Control__getTurnTime_out Control__getTurnTime_out_st;
  Control__calculateK_out Control__calculateK_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__isTrafficLightMark_out Control__isTrafficLightMark_out_st;
  Control__isActionMark_out Control__isActionMark_out_st;
  
  int v_12;
  int v_11;
  int v_10;
  float v_9;
  int v_8;
  int v_7;
  float v;
  int v_13;
  Globals__wheels v_29;
  float v_28;
  Globals__wheels v_27;
  float v_26;
  int v_25;
  Globals__itielt v_24;
  Globals__itielt v_23;
  int v_22;
  float v_21;
  int v_20;
  int v_18;
  float v_17;
  Globals__itielt v_16;
  int v_15;
  Globals__itielt v_14;
  int cpt;
  float turn_time;
  float speed;
  int v_51;
  float v_50;
  int v_49;
  float v_48;
  int v_47;
  float v_46;
  float v_45;
  Globals__itielt v_44;
  float v_43;
  float v_42;
  float v_41;
  float v_40;
  float v_39;
  float v_38;
  int v_37;
  int v_36;
  int v_35;
  int v_34;
  int v_33;
  Control__st v_32;
  int v_31;
  Control__st v_30;
  float derivative_1;
  float integral_1;
  float error_1;
  int outActionMark_1;
  int onActionMark_1;
  int onTrafficLight;
  int isObstacle;
  int onActionMark;
  int outActionMark;
  float tp;
  float turn;
  float kp;
  float ki;
  float kd;
  float lastError;
  float error;
  float integral;
  float derivative;
  Globals__itielt v_64;
  int v_63;
  Control__st v_62;
  int v_61;
  Control__st v_60;
  int v_59;
  int v_58;
  int v_57;
  Globals__action act;
  int nr_St_Arrived;
  Control__st ns_St_Arrived;
  int actionIndex_St_Arrived;
  int arriving_St_Arrived;
  Globals__wheels rspeed_St_Arrived;
  int nr_St_TrafficLight;
  Control__st ns_St_TrafficLight;
  int actionIndex_St_TrafficLight;
  int arriving_St_TrafficLight;
  Globals__wheels rspeed_St_TrafficLight;
  int nr_St_Obstacle;
  Control__st ns_St_Obstacle;
  int actionIndex_St_Obstacle;
  int arriving_St_Obstacle;
  Globals__wheels rspeed_St_Obstacle;
  int nr_St_Turn;
  Control__st ns_St_Turn;
  int actionIndex_St_Turn;
  int arriving_St_Turn;
  Globals__wheels rspeed_St_Turn;
  int nr_St_Go;
  Control__st ns_St_Go;
  int actionIndex_St_Go;
  int arriving_St_Go;
  Globals__wheels rspeed_St_Go;
  int nr_St_Action;
  Control__st ns_St_Action;
  int actionIndex_St_Action;
  int arriving_St_Action;
  Globals__wheels rspeed_St_Action;
  Control__st ns;
  int r;
  int nr;
  int actionIndex;
  r = self->pnr;
  switch (self->ck) {
    case Control__St_Action:
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      v_64 = iti[between(actionIndex, Globals__itinum)];
      act = v_64.act;
      v_59 = (act==Globals__Stop);
      if (v_59) {
        v_61 = true;
        v_60 = Control__St_Arrived;
      } else {
        v_61 = false;
        v_60 = Control__St_Action;
      };
      v_58 = (act==Globals__Go);
      if (v_58) {
        v_63 = true;
        v_62 = Control__St_Go;
      } else {
        v_63 = v_61;
        v_62 = v_60;
      };
      v_57 = (act==Globals__Turn);
      if (v_57) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_63;
        ns_St_Action = v_62;
      };
      rspeed_St_Action.right = 0.000000;
      rspeed_St_Action.left = 0.000000;
      ns = ns_St_Action;
      nr = nr_St_Action;
      _out->rspeed = rspeed_St_Action;
      break;
    case Control__St_Go:
      if (r) {
        derivative_1 = 0.000000;
        integral_1 = 0.000000;
        error_1 = 0.000000;
        outActionMark_1 = false;
        onActionMark_1 = false;
      } else {
        derivative_1 = self->v_56;
        integral_1 = self->v_55;
        error_1 = self->v_54;
        outActionMark_1 = self->v_53;
        onActionMark_1 = self->v_52;
      };
      actionIndex_St_Go = self->actionIndex_1;
      arriving_St_Go = false;
      isObstacle = (sens.s_sonar<=Control__obstacleDistance);
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_50 = Utilities__compare_colors_out_st.correlation;
      v_51 = (v_50>=1.000000);
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_48 = Utilities__compare_colors_out_st.correlation;
      v_49 = (v_48>=1.000000);
      onTrafficLight = (v_49||v_51);
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      onActionMark = Control__isActionMark_out_st.res;
      v_47 = !(onActionMark);
      outActionMark = (onActionMark_1&&v_47);
      lastError = error_1;
      v_39 = (0.666667*integral_1);
      v_37 = (sens.s_road.red-sens.s_road.green);
      Mathext__float_step(v_37, &Mathext__float_out_st);
      v_38 = Mathext__float_out_st.o;
      Control__isTrafficLightMark_step(sens.s_road,
                                       &Control__isTrafficLightMark_out_st);
      v_35 = Control__isTrafficLightMark_out_st.res;
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      v_34 = Control__isActionMark_out_st.res;
      v_36 = (v_34||v_35);
      if (v_36) {
        error = error_1;
      } else {
        error = v_38;
      };
      derivative = (error-lastError);
      integral = (v_39+error);
      Control__calculateK_step(0.700000, 2.350000,
                               &Control__calculateK_out_st);
      kp = Control__calculateK_out_st.kp;
      ki = Control__calculateK_out_st.ki;
      kd = Control__calculateK_out_st.kd;
      v_43 = (kd*derivative);
      v_41 = (ki*integral);
      v_40 = (kp*error);
      v_42 = (v_40+v_41);
      turn = (v_42+v_43);
      if (isObstacle) {
        v_31 = true;
      } else {
        v_31 = false;
      };
      if (onTrafficLight) {
        v_33 = true;
      } else {
        v_33 = v_31;
      };
      if (outActionMark) {
        nr_St_Go = true;
      } else {
        nr_St_Go = v_33;
      };
      if (isObstacle) {
        v_30 = Control__St_Obstacle;
      } else {
        v_30 = Control__St_Go;
      };
      if (onTrafficLight) {
        v_32 = Control__St_TrafficLight;
      } else {
        v_32 = v_30;
      };
      if (outActionMark) {
        ns_St_Go = Control__St_Action;
      } else {
        ns_St_Go = v_32;
      };
      _out->arriving = arriving_St_Go;
      actionIndex = actionIndex_St_Go;
      v_44 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_44.param,
                                   &Control__convertMsToDps_out_st);
      tp = Control__convertMsToDps_out_st.dps;
      v_46 = (tp+turn);
      v_45 = (tp-turn);
      rspeed_St_Go.left = v_45;
      rspeed_St_Go.right = v_46;
      ns = ns_St_Go;
      nr = nr_St_Go;
      _out->rspeed = rspeed_St_Go;
      self->v_56 = derivative;
      self->v_55 = integral;
      self->v_54 = error;
      self->v_53 = outActionMark;
      self->v_52 = onActionMark;
      break;
    case Control__St_Turn:
      actionIndex_St_Turn = self->actionIndex_1;
      arriving_St_Turn = false;
      if (r) {
        v_20 = 0;
      } else {
        v_20 = self->v_19;
      };
      cpt = (1+v_20);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_21 = Mathext__float_out_st.o;
      turn_time = (Globals__timestep*v_21);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_22 = (actionIndex-1);
      v_15 = (actionIndex-1);
      v_24 = iti[between(actionIndex, Globals__itinum)];
      v_25 = (v_24.param>0.000000);
      v_23 = iti[between(v_22, Globals__itinum)];
      Control__convertMsToDps_step(v_23.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_28 = -(speed);
      v_26 = -(speed);
      v_29.left = speed;
      v_29.right = v_28;
      v_27.left = v_26;
      v_27.right = speed;
      if (v_25) {
        rspeed_St_Turn = v_27;
      } else {
        rspeed_St_Turn = v_29;
      };
      v_16 = iti[between(v_15, Globals__itinum)];
      v_14 = iti[between(actionIndex, Globals__itinum)];
      Control__getTurnTime_step(v_14.param, v_16.param,
                                &Control__getTurnTime_out_st);
      v_17 = Control__getTurnTime_out_st.time;
      v_18 = (v_17<turn_time);
      if (v_18) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_19 = cpt;
      break;
    case Control__St_Obstacle:
      actionIndex_St_Obstacle = self->actionIndex_1;
      arriving_St_Obstacle = false;
      v_13 = (sens.s_sonar>Control__obstacleDistance);
      if (v_13) {
        nr_St_Obstacle = true;
        ns_St_Obstacle = Control__St_Go;
      } else {
        nr_St_Obstacle = false;
        ns_St_Obstacle = Control__St_Obstacle;
      };
      _out->arriving = arriving_St_Obstacle;
      actionIndex = actionIndex_St_Obstacle;
      ns = ns_St_Obstacle;
      nr = nr_St_Obstacle;
      rspeed_St_Obstacle.right = 0.000000;
      rspeed_St_Obstacle.left = 0.000000;
      _out->rspeed = rspeed_St_Obstacle;
      break;
    case Control__St_TrafficLight:
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_9 = Utilities__compare_colors_out_st.correlation;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v = Utilities__compare_colors_out_st.correlation;
      v_10 = (v_9==1.000000);
      v_11 = !(v_10);
      v_7 = (v==1.000000);
      v_8 = !(v_7);
      v_12 = (v_8&&v_11);
      if (v_12) {
        nr_St_TrafficLight = true;
        ns_St_TrafficLight = Control__St_Go;
      } else {
        nr_St_TrafficLight = false;
        ns_St_TrafficLight = Control__St_TrafficLight;
      };
      _out->arriving = arriving_St_TrafficLight;
      actionIndex = actionIndex_St_TrafficLight;
      ns = ns_St_TrafficLight;
      nr = nr_St_TrafficLight;
      rspeed_St_TrafficLight.right = 0.000000;
      rspeed_St_TrafficLight.left = 0.000000;
      _out->rspeed = rspeed_St_TrafficLight;
      break;
    case Control__St_Arrived:
      actionIndex_St_Arrived = self->actionIndex_1;
      arriving_St_Arrived = true;
      nr_St_Arrived = false;
      ns_St_Arrived = Control__St_Arrived;
      _out->arriving = arriving_St_Arrived;
      actionIndex = actionIndex_St_Arrived;
      ns = ns_St_Arrived;
      nr = nr_St_Arrived;
      rspeed_St_Arrived.right = 0.000000;
      rspeed_St_Arrived.left = 0.000000;
      _out->rspeed = rspeed_St_Arrived;
      break;
    default:
      break;
  };
  self->actionIndex_1 = actionIndex;
  self->pnr = nr;
  self->ck = ns;;
}

