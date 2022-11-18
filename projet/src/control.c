/* --- Generated the 18/11/2022 at 1:0 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. oct. 5 14:31:43 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control.h"

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
  Globals__color mid;
  Control__compare_colors_step(sens.s_road, Globals__magenta,
                               &Control__compare_colors_out_st);
  _out->right = Control__compare_colors_out_st.v;
  Control__compare_colors_step(sens.s_road, Globals__cyan,
                               &Control__compare_colors_out_st);
  _out->left = Control__compare_colors_out_st.v;
  Mathext__float_step(Globals__blue.blue, &Mathext__float_out_st);
  v_31 = Mathext__float_out_st.o;
  v_32 = (v_31*0.500000);
  Mathext__float_step(Globals__cyan.blue, &Mathext__float_out_st);
  v_29 = Mathext__float_out_st.o;
  v_30 = (v_29*0.500000);
  v_33 = (v_30+v_32);
  Mathext__int_step(v_33, &Mathext__int_out_st);
  v_34 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.green, &Mathext__float_out_st);
  v_25 = Mathext__float_out_st.o;
  v_26 = (v_25*0.500000);
  Mathext__float_step(Globals__cyan.green, &Mathext__float_out_st);
  v_23 = Mathext__float_out_st.o;
  v_24 = (v_23*0.500000);
  v_27 = (v_24+v_26);
  Mathext__int_step(v_27, &Mathext__int_out_st);
  v_28 = Mathext__int_out_st.o;
  Mathext__float_step(Globals__blue.red, &Mathext__float_out_st);
  v_19 = Mathext__float_out_st.o;
  v_20 = (v_19*0.500000);
  Mathext__float_step(Globals__cyan.red, &Mathext__float_out_st);
  v_17 = Mathext__float_out_st.o;
  v_18 = (v_17*0.500000);
  v_21 = (v_18+v_20);
  Mathext__int_step(v_21, &Mathext__int_out_st);
  v_22 = Mathext__int_out_st.o;
  mid.red = v_22;
  mid.green = v_28;
  mid.blue = v_34;
  Control__compare_colors_step(sens.s_road, mid,
                               &Control__compare_colors_out_st);
  _out->middle = Control__compare_colors_out_st.v;;
}

void Control__getDirection_step(float left, float middle, float right,
                                Control__getDirection_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  float v;
  float min;
  Utilities__min_float_step(left, middle, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__min_float_step(v, right, &Utilities__min_float_out_st);
  min = Utilities__min_float_out_st.o;
  v_37 = (min==right);
  if (v_37) {
    v_38 = -1;
  } else {
    v_38 = 0;
  };
  v_36 = (min==middle);
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

void Control__adjustSpeed_step(float speed, Control__adjustSpeed_out* _out) {
  Utilities__min_float_out Utilities__min_float_out_st;
  Utilities__max_float_out Utilities__max_float_out_st;
  
  float v;
  Utilities__min_float_step(speed, 300.000000, &Utilities__min_float_out_st);
  v = Utilities__min_float_out_st.o;
  Utilities__max_float_step(v, -300.000000, &Utilities__max_float_out_st);
  _out->s = Utilities__max_float_out_st.o;;
}

void Control__setMotorSpeed_step(float leftSpeed, float rightSpeed,
                                 Control__setMotorSpeed_out* _out) {
  Control__adjustSpeed_out Control__adjustSpeed_out_st;
  
  float v_44;
  int v_43;
  float v_42;
  float v_41;
  int v_40;
  float v;
  v_44 = (-1.000000*rightSpeed);
  Control__adjustSpeed_step(rightSpeed, &Control__adjustSpeed_out_st);
  v_42 = Control__adjustSpeed_out_st.s;
  v_43 = (v_42<0.000000);
  if (v_43) {
    _out->rs = v_44;
  } else {
    _out->rs = rightSpeed;
  };
  v_41 = (-1.000000*leftSpeed);
  Control__adjustSpeed_step(leftSpeed, &Control__adjustSpeed_out_st);
  v = Control__adjustSpeed_out_st.s;
  v_40 = (v<0.000000);
  if (v_40) {
    _out->ls = v_41;
  } else {
    _out->ls = leftSpeed;
  };;
}

void Control__controller_step(Globals__sensors sens, Globals__itielts iti,
                              Control__controller_out* _out) {
  Control__getDistances_out Control__getDistances_out_st;
  Mathext__float_out Mathext__float_out_st;
  Control__getDirection_out Control__getDirection_out_st;
  Control__setMotorSpeed_out Control__setMotorSpeed_out_st;
  
  float v_47;
  float v_46;
  float v_45;
  int v;
  float left;
  float mid;
  float right;
  float leftSpeed;
  float rightSpeed;
  float error;
  float kp;
  float tp;
  float turn;
  Control__getDistances_step(sens, &Control__getDistances_out_st);
  left = Control__getDistances_out_st.left;
  mid = Control__getDistances_out_st.middle;
  right = Control__getDistances_out_st.right;
  _out->arriving = false;
  Control__getDirection_step(left, mid, right, &Control__getDirection_out_st);
  v = Control__getDirection_out_st.direction;
  Mathext__float_step(v, &Mathext__float_out_st);
  v_45 = Mathext__float_out_st.o;
  error = (mid*v_45);
  tp = 300.000000;
  kp = 0.300000;
  turn = (kp*error);
  v_47 = (tp-turn);
  v_46 = (tp+turn);
  Control__setMotorSpeed_step(v_46, v_47, &Control__setMotorSpeed_out_st);
  leftSpeed = Control__setMotorSpeed_out_st.ls;
  rightSpeed = Control__setMotorSpeed_out_st.rs;
  _out->rspeed.left = leftSpeed;
  _out->rspeed.right = rightSpeed;;
}

