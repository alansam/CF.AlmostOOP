//
//  almost_oop.h
//  CF.AlmostOOP
//
//  Created by Alan Sampson on 5/24/21.
//

#pragma once
#ifndef almost_oop_h
#define almost_oop_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(__cplusplus)
typedef enum HANDEDNESS HANDEDNESS;
#endif
enum HANDEDNESS { RIGHT, LEFT, AMBIDEXTROUS, UNKNOWN, };

typedef struct person person;

struct person {
  char name[80];
  uint32_t age;
  uint32_t CNP;
  char job[128];
  char job_short[20];
  uint32_t salary;  /* units.decimals an int = 120.25 == 12025 */
  char address_home[128];
  char hair_colour[20];
  uint32_t height;  /* in mm (i.e. m to 3 decimal places) */
  uint32_t weight;  /* in g (i.e. kg to 3 decimal places) */
  HANDEDNESS handedness;

  void (* show_name)(person *);
  void (* show_age)(person *);
  void (* show_CNP)(person *);
  void (* show_job)(person *);
  void (* show_job_short)(person *);
  void (* show_salary)(person *);
  void (* show_address_home)(person *);
  void (* show_hair_colour)(person *);
  void (* show_height)(person *);
  void (* show_weight)(person *);
  void (* show_handedness)(person *);
};

person constructor(char const * name,
                   uint32_t age,
                   uint32_t CNP,
                   char const * job,
                   char const * job_short,
                   uint32_t salary,
                   char const * address_home,
                   char const * hair_colour,
                   uint32_t height,
                   uint32_t weight,
                   HANDEDNESS handedness);

int almost_oop(int argc, char const * argv[]);

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* almost_oop_h */
