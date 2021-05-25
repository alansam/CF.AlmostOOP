//
//  almost_oop.c
//  CF.AlmostOOP
//
//  Created by Alan Sampson on 5/24/21.
//

#include "almost_oop.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *  MARK: almost_oop()
 */
int almost_oop(int argc, char const * argv[]) {
  printf("In: %s\n", __func__);
#if defined(__cplusplus)
  std::cout << "C++ Version: " << __cplusplus << std::endl;
#else
  printf("C Version: %ld\n", __STDC_VERSION__);
#endif

  size_t loaded = 0;
  person people[1000] = { 0, };
  people[loaded++] = constructor("Ann Onymouse",
                                 44,
                                 250,
                                 "An important job",
                                 "important",
                                 10000000,
                                 "Our house, in the middle of our street, London, GB",
                                 "blonde",
                                 1440,
                                 49000,
                                 AMBIDEXTROUS);
  people[loaded++] = constructor("A. N. Other",
                                 35,
                                 209,
                                 "The full monty",
                                 "monty",
                                 5801050,
                                 "This is my place, CA, USA",
                                 "brunette",
                                 1527,
                                 53100,
                                 LEFT);
  people[loaded++] = constructor("Justin Alias",
                                 22,
                                 200,
                                 "Less than a full monty",
                                 "<monty",
                                 3000000,
                                 "This is my place, Sydney, AU",
                                 "brown",
                                 1966,
                                 50100,
                                 RIGHT);

  for (size_t p_ = 0; p_ < loaded; ++p_) {
    printf("Person [%4zu]\n", p_);
    person folk = people[p_];
    folk.show_name(&folk);
    folk.show_age(&folk);
    folk.show_CNP(&folk);
    folk.show_job(&folk);
    folk.show_job_short(&folk);
    folk.show_salary(&folk);
    folk.show_address_home(&folk);
    folk.show_hair_colour(&folk);
    folk.show_height(&folk);
    folk.show_weight(&folk);
    folk.show_handedness(&folk);
    putchar('\n');
  }

  return 0;
}

//  MARK: - Almost OOP struct method members
void show_name(person * this) {
  printf(". Name: %s\n", this->name);
}

void show_age(person * this) {
  printf(". Age: %u\n", this->age);
}

void show_CNP(person * this) {
  printf(". CNP: %u\n", this->CNP);
}

void show_job(person * this) {
  printf(". Job: %s\n", this->job);
}

void show_job_short(person * this) {
  printf(". Job [short desc.]: %s\n", this->job_short);
}

void show_salary(person * this) {
  div_t sal = div(this->salary, 100);
  printf(". Salary: \u00a4 %7d.%02d\n", sal.quot, sal.rem);
}

void show_address_home(person * this) {
  printf(". Home address: %s\n", this->address_home);
}

void show_hair_colour(person * this) {
  printf(". Hair colour: %s\n", this->hair_colour);
}

void show_height(person * this) {
  div_t height = div(this->height, 1000);
  printf(". Height: %3d.%03d m\n", height.quot, height.rem);
}

void show_weight(person * this) {
  div_t weight = div(this->weight, 1000);
  printf(". Weight: %3d.%03d kg\n", weight.quot, weight.rem);
}

void show_handedness(person * this) {

  char const * handy;
  switch (this->handedness) {
  case RIGHT:
    handy = "right";
    break;

  case LEFT:
    handy = "left";
    break;

  case AMBIDEXTROUS:
    handy = "ambidextrous";
    break;

  case UNKNOWN:
  default:
    handy = "unknown";
    break;
  }

  printf(". Handedness: %s\n", handy);
}

/*
 *  MARK: constructor()
 */
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
                   HANDEDNESS handedness) {
  person thisone;
  strncpy(thisone.name, name,
          sizeof(thisone.name) - 1);
  strncpy(thisone.job, job,
          sizeof(thisone.job) - 1);
  strncpy(thisone.job_short, job_short,
          sizeof(thisone.job_short) - 1);
  strncpy(thisone.address_home, address_home,
          sizeof(thisone.address_home) - 1);
  strncpy(thisone.hair_colour, hair_colour,
          sizeof(thisone.hair_colour) - 1);
  thisone.age = age;
  thisone.CNP = CNP;
  thisone.salary = salary;
  thisone.height = height;
  thisone.weight = weight;
  thisone.handedness = handedness;

  thisone.show_name = show_name;
  thisone.show_age = show_age;
  thisone.show_CNP = show_CNP;
  thisone.show_job = show_job;
  thisone.show_job_short = show_job_short;
  thisone.show_salary = show_salary;
  thisone.show_address_home = show_address_home;
  thisone.show_hair_colour = show_hair_colour;
  thisone.show_height = show_height;
  thisone.show_weight = show_weight;
  thisone.show_handedness = show_handedness;

  return thisone;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
