/* --- Generated the 24/11/2022 at 10:30 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. nov. 22 1:37:53 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c control.ept --- */

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
  if ((strcmp(s, "St_Running")==0)) {
    return Control__St_Running;
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
    case Control__St_Running:
      strcpy(buf, "St_Running");
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

