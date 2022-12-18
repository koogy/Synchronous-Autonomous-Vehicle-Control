/* --- Generated the 18/12/2022 at 7:1 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control.h"

void Control__convertMsToDps_step(float ms, Control__convertMsToDps_out* _out) {
  
  float v;
  v = (3.472472*ms);
  _out->dps = (v*6.000000);;
}

void Control__getTurnTime_step(float deg, float ms,
                               Control__getTurnTime_out* _out) {
  Utilities__abs_out Utilities__abs_out_st;
  
  float v_3;
  float v_2;
  float v_1;
  float v;
  float circumference;
  float arcLength;
  v_3 = (ms/100.000000);
  Utilities__abs_step(deg, &Utilities__abs_out_st);
  v = Utilities__abs_out_st.o;
  v_1 = (v/360.000000);
  circumference = 18.849556;
  arcLength = (v_1*circumference);
  v_2 = (arcLength/100.000000);
  _out->time = (v_2/v_3);;
}

void Control__calculateK_step(float kc, float pc,
                              Control__calculateK_out* _out) {
  
  float v_5;
  float v_4;
  float v;
  _out->kp = (0.600000*kc);
  v_5 = (_out->kp*pc);
  _out->kd = (v_5/0.128000);
  v = (2.000000*_out->kp);
  v_4 = (v*Control__dt);
  _out->ki = (v_4/pc);;
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
  self->v_69 = 0.000000;
  self->v_68 = 0.000000;
  self->v_67 = 0.000000;
  self->v_66 = false;
  self->v_65 = false;
  self->v_22 = 0;
  self->tp_1 = 0.000000;
  self->lastActionTime_1 = 0.000000;
  self->actionIndex_1 = -1;
  self->pnr = false;
  self->ck = Control__St_Action;
  self->v_6 = 0;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out,
                              Control__controller_mem* self) {
  Mathext__floor_out Mathext__floor_out_st;
  Control__getTurnTime_out Control__getTurnTime_out_st;
  Control__convertMsToDps_out Control__convertMsToDps_out_st;
  Control__isActionMark_out Control__isActionMark_out_st;
  Mathext__float_out Mathext__float_out_st;
  Control__calculateK_out Control__calculateK_out_st;
  Utilities__compare_colors_out Utilities__compare_colors_out_st;
  Control__isTrafficLightMark_out Control__isTrafficLightMark_out_st;
  
  int v_14;
  int v_13;
  int v_12;
  float v_11;
  int v_10;
  int v_9;
  float v_8;
  int v_15;
  Globals__wheels v_32;
  float v_31;
  Globals__wheels v_30;
  float v_29;
  int v_28;
  Globals__itielt v_27;
  Globals__itielt v_26;
  int v_25;
  float v_24;
  int v_23;
  int v_21;
  int v_20;
  float v_19;
  Globals__itielt v_18;
  int v_17;
  Globals__itielt v_16;
  int cpt;
  float turn_time;
  float speed;
  int v_64;
  float v_63;
  int v_62;
  float v_61;
  int v_60;
  float v_59;
  float v_58;
  float v_57;
  float v_56;
  Globals__itielt v_55;
  float v_54;
  float v_53;
  float v_52;
  float v_51;
  float v_50;
  int v_49;
  int v_48;
  int v_47;
  float v_46;
  float v_45;
  int v_44;
  int v_43;
  int v_42;
  float v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  Control__st v_35;
  int v_34;
  Control__st v_33;
  float derivative_1;
  float integral_1;
  float error_1;
  int outActionMark_1;
  int onActionMark_1;
  int onTrafficLight;
  int isObstacle;
  int onActionMark;
  int outActionMark;
  float turn;
  float kp;
  float ki;
  float kd;
  float lastError;
  float error;
  float integral;
  float derivative;
  Globals__itielt v_77;
  int v_76;
  Control__st v_75;
  int v_74;
  Control__st v_73;
  int v_72;
  int v_71;
  int v_70;
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
  int nr_St_Obstacle;
  Control__st ns_St_Obstacle;
  float tp_St_Obstacle;
  float lastActionTime_St_Obstacle;
  int actionIndex_St_Obstacle;
  int arriving_St_Obstacle;
  Globals__wheels rspeed_St_Obstacle;
  int nr_St_Turn;
  Control__st ns_St_Turn;
  float tp_St_Turn;
  float lastActionTime_St_Turn;
  int actionIndex_St_Turn;
  int arriving_St_Turn;
  Globals__wheels rspeed_St_Turn;
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
  float v_7;
  int v;
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
    v = 1;
  } else {
    v = 0;
  };
  compt = (v+self->v_6);
  Mathext__float_step(compt, &Mathext__float_out_st);
  v_7 = Mathext__float_out_st.o;
  time = (Globals__timestep*v_7);
  switch (self->ck) {
    case Control__St_Action:
      tp_St_Action = self->tp_1;
      actionIndex_St_Action = (self->actionIndex_1+1);
      arriving_St_Action = false;
      lastActionTime_St_Action = time;
      _out->arriving = arriving_St_Action;
      actionIndex = actionIndex_St_Action;
      lastActionTime = lastActionTime_St_Action;
      v_77 = iti[between(actionIndex, Globals__itinum)];
      act = v_77.act;
      v_72 = (act==Globals__Stop);
      if (v_72) {
        v_74 = true;
        v_73 = Control__St_Arrived;
      } else {
        v_74 = false;
        v_73 = Control__St_Action;
      };
      v_71 = (act==Globals__Go);
      if (v_71) {
        v_76 = true;
        v_75 = Control__St_Go;
      } else {
        v_76 = v_74;
        v_75 = v_73;
      };
      v_70 = (act==Globals__Turn);
      if (v_70) {
        nr_St_Action = true;
        ns_St_Action = Control__St_Turn;
      } else {
        nr_St_Action = v_76;
        ns_St_Action = v_75;
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
        outActionMark_1 = false;
        onActionMark_1 = false;
      } else {
        derivative_1 = self->v_69;
        integral_1 = self->v_68;
        error_1 = self->v_67;
        outActionMark_1 = self->v_66;
        onActionMark_1 = self->v_65;
      };
      lastActionTime_St_Go = self->lastActionTime_1;
      actionIndex_St_Go = self->actionIndex_1;
      arriving_St_Go = false;
      isObstacle = (sens.s_sonar<=Control__obstacleDistance);
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_63 = Utilities__compare_colors_out_st.correlation;
      v_64 = (v_63>=1.000000);
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_61 = Utilities__compare_colors_out_st.correlation;
      v_62 = (v_61>=1.000000);
      onTrafficLight = (v_62||v_64);
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      onActionMark = Control__isActionMark_out_st.res;
      v_60 = !(onActionMark);
      outActionMark = (onActionMark_1&&v_60);
      lastError = error_1;
      Control__isTrafficLightMark_step(sens.s_road,
                                       &Control__isTrafficLightMark_out_st);
      v_48 = Control__isTrafficLightMark_out_st.res;
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      v_47 = Control__isActionMark_out_st.res;
      v_49 = (v_47||v_48);
      v_45 = (0.666667*integral_1);
      Control__isTrafficLightMark_step(sens.s_road,
                                       &Control__isTrafficLightMark_out_st);
      v_43 = Control__isTrafficLightMark_out_st.res;
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      v_42 = Control__isActionMark_out_st.res;
      v_44 = (v_42||v_43);
      v_40 = (sens.s_road.red-sens.s_road.green);
      Mathext__float_step(v_40, &Mathext__float_out_st);
      v_41 = Mathext__float_out_st.o;
      Control__isTrafficLightMark_step(sens.s_road,
                                       &Control__isTrafficLightMark_out_st);
      v_38 = Control__isTrafficLightMark_out_st.res;
      Control__isActionMark_step(sens.s_road, &Control__isActionMark_out_st);
      v_37 = Control__isActionMark_out_st.res;
      v_39 = (v_37||v_38);
      if (v_39) {
        error = error_1;
      } else {
        error = v_41;
      };
      v_50 = (error-lastError);
      if (v_49) {
        derivative = derivative_1;
      } else {
        derivative = v_50;
      };
      v_46 = (v_45+error);
      if (v_44) {
        integral = integral_1;
      } else {
        integral = v_46;
      };
      Control__calculateK_step(0.700000, 2.350000,
                               &Control__calculateK_out_st);
      kp = Control__calculateK_out_st.kp;
      ki = Control__calculateK_out_st.ki;
      kd = Control__calculateK_out_st.kd;
      v_54 = (kd*derivative);
      v_52 = (ki*integral);
      v_51 = (kp*error);
      v_53 = (v_51+v_52);
      turn = (v_53+v_54);
      if (isObstacle) {
        v_34 = true;
      } else {
        v_34 = false;
      };
      if (onTrafficLight) {
        v_36 = true;
      } else {
        v_36 = v_34;
      };
      if (outActionMark) {
        nr_St_Go = true;
      } else {
        nr_St_Go = v_36;
      };
      if (isObstacle) {
        v_33 = Control__St_Obstacle;
      } else {
        v_33 = Control__St_Go;
      };
      if (onTrafficLight) {
        v_35 = Control__St_TrafficLight;
      } else {
        v_35 = v_33;
      };
      if (outActionMark) {
        ns_St_Go = Control__St_Action;
      } else {
        ns_St_Go = v_35;
      };
      _out->arriving = arriving_St_Go;
      actionIndex = actionIndex_St_Go;
      lastActionTime = lastActionTime_St_Go;
      v_55 = iti[between(actionIndex, Globals__itinum)];
      Control__convertMsToDps_step(v_55.param,
                                   &Control__convertMsToDps_out_st);
      tp_St_Go = Control__convertMsToDps_out_st.dps;
      tp = tp_St_Go;
      v_58 = (tp+turn);
      Mathext__floor_step(v_58, &Mathext__floor_out_st);
      v_59 = Mathext__floor_out_st.o;
      v_56 = (tp-turn);
      Mathext__floor_step(v_56, &Mathext__floor_out_st);
      v_57 = Mathext__floor_out_st.o;
      rspeed_St_Go.left = v_57;
      rspeed_St_Go.right = v_59;
      ns = ns_St_Go;
      nr = nr_St_Go;
      _out->rspeed = rspeed_St_Go;
      self->v_69 = derivative;
      self->v_68 = integral;
      self->v_67 = error;
      self->v_66 = outActionMark;
      self->v_65 = onActionMark;
      break;
    case Control__St_Turn:
      tp_St_Turn = self->tp_1;
      lastActionTime_St_Turn = self->lastActionTime_1;
      actionIndex_St_Turn = self->actionIndex_1;
      arriving_St_Turn = false;
      if (r) {
        v_23 = 0;
      } else {
        v_23 = self->v_22;
      };
      if (true) {
        v_21 = 1;
      } else {
        v_21 = 0;
      };
      cpt = (v_21+v_23);
      Mathext__float_step(cpt, &Mathext__float_out_st);
      v_24 = Mathext__float_out_st.o;
      turn_time = (Globals__timestep*v_24);
      _out->arriving = arriving_St_Turn;
      actionIndex = actionIndex_St_Turn;
      v_25 = (actionIndex-1);
      v_17 = (actionIndex-1);
      lastActionTime = lastActionTime_St_Turn;
      tp = tp_St_Turn;
      v_27 = iti[between(actionIndex, Globals__itinum)];
      v_28 = (v_27.param>0.000000);
      v_26 = iti[between(v_25, Globals__itinum)];
      Control__convertMsToDps_step(v_26.param,
                                   &Control__convertMsToDps_out_st);
      speed = Control__convertMsToDps_out_st.dps;
      v_31 = -(speed);
      v_29 = -(speed);
      v_32.left = speed;
      v_32.right = v_31;
      v_30.left = v_29;
      v_30.right = speed;
      if (v_28) {
        rspeed_St_Turn = v_30;
      } else {
        rspeed_St_Turn = v_32;
      };
      v_18 = iti[between(v_17, Globals__itinum)];
      v_16 = iti[between(actionIndex, Globals__itinum)];
      Control__getTurnTime_step(v_16.param, v_18.param,
                                &Control__getTurnTime_out_st);
      v_19 = Control__getTurnTime_out_st.time;
      v_20 = (turn_time>v_19);
      if (v_20) {
        nr_St_Turn = true;
        ns_St_Turn = Control__St_Action;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Control__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      _out->rspeed = rspeed_St_Turn;
      self->v_22 = cpt;
      break;
    case Control__St_Obstacle:
      tp_St_Obstacle = self->tp_1;
      lastActionTime_St_Obstacle = self->lastActionTime_1;
      actionIndex_St_Obstacle = self->actionIndex_1;
      arriving_St_Obstacle = false;
      v_15 = (sens.s_sonar>Control__obstacleDistance);
      if (v_15) {
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
      ns = ns_St_Obstacle;
      nr = nr_St_Obstacle;
      rspeed_St_Obstacle.right = 0.000000;
      rspeed_St_Obstacle.left = 0.000000;
      _out->rspeed = rspeed_St_Obstacle;
      break;
    case Control__St_TrafficLight:
      tp_St_TrafficLight = self->tp_1;
      lastActionTime_St_TrafficLight = self->lastActionTime_1;
      actionIndex_St_TrafficLight = self->actionIndex_1;
      arriving_St_TrafficLight = false;
      Utilities__compare_colors_step(sens.s_front, Globals__amber,
                                     &Utilities__compare_colors_out_st);
      v_11 = Utilities__compare_colors_out_st.correlation;
      Utilities__compare_colors_step(sens.s_front, Globals__red,
                                     &Utilities__compare_colors_out_st);
      v_8 = Utilities__compare_colors_out_st.correlation;
      v_12 = (v_11==1.000000);
      v_13 = !(v_12);
      v_9 = (v_8==1.000000);
      v_10 = !(v_9);
      v_14 = (v_10&&v_13);
      if (v_14) {
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
      tp_St_Arrived = self->tp_1;
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
  self->tp_1 = tp;
  self->lastActionTime_1 = lastActionTime;
  self->actionIndex_1 = actionIndex;
  self->pnr = nr;
  self->ck = ns;
  self->v_6 = compt;;
}

