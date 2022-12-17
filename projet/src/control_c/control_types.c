/* --- Generated the 17/12/2022 at 21:7 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. dec. 15 17:28:19 CET 2022) --- */
/* --- Command line: /home/a/.opam/default/bin/heptc -c -target c control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "control_types.h"

Control__st Control__st_of_string(char* s) {
  if ((strcmp(s, "St_Turn")==0)) {
    return Control__St_Turn;
  };
  if ((strcmp(s, "St_TrafficLight")==0)) {
    return Control__St_TrafficLight;
  };
  if ((strcmp(s, "St_Obstacle")==0)) {
    return Control__St_Obstacle;
  };
  if ((strcmp(s, "St_Go")==0)) {
    return Control__St_Go;
  };
  if ((strcmp(s, "St_Arrived")==0)) {
    return Control__St_Arrived;
  };
  if ((strcmp(s, "St_Action")==0)) {
    return Control__St_Action;
  };
}

char* string_of_Control__st(Control__st x, char* buf) {
  switch (x) {
    case Control__St_Turn:
      strcpy(buf, "St_Turn");
      break;
    case Control__St_TrafficLight:
      strcpy(buf, "St_TrafficLight");
      break;
    case Control__St_Obstacle:
      strcpy(buf, "St_Obstacle");
      break;
    case Control__St_Go:
      strcpy(buf, "St_Go");
      break;
    case Control__St_Arrived:
      strcpy(buf, "St_Arrived");
      break;
    case Control__St_Action:
      strcpy(buf, "St_Action");
      break;
    default:
      break;
  };
  return buf;
}

