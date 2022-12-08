/* --- Generated the 8/12/2022 at 10:48 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. nov. 22 1:37:53 CET 2022) --- */
/* --- Command line: /home/alex/.opam/default/bin/heptc -c -target c challenge.ept --- */

#ifndef CHALLENGE_H
#define CHALLENGE_H

#include "challenge_types.h"
#include "city.h"
#include "globals.h"
#include "map.h"
#include "utilities.h"
#include "vehicle.h"
typedef struct Challenge__the_challenge_mem {
  Globals__interrupt v_4;
  Globals__sensors v_2;
  int v_1;
  Utilities__event_edge_mem event_edge;
  City__scoringA_mem scoringA;
  City__wallclock_mem wallclock;
  City__scoringB_mem scoringB;
  Vehicle__simulate_mem simulate;
} Challenge__the_challenge_mem;

typedef struct Challenge__the_challenge_out {
  Globals__phase ph;
  Globals__status sta;
  Globals__sign sign;
  Globals__event evt;
  int scoreA;
  int scoreB;
  float time;
} Challenge__the_challenge_out;

void Challenge__the_challenge_reset(Challenge__the_challenge_mem* self);

void Challenge__the_challenge_step(Globals__phase initial_ph, int top,
                                   Challenge__the_challenge_out* _out,
                                   Challenge__the_challenge_mem* self);

#endif // CHALLENGE_H
