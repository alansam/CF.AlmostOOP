//
//  this_is_oop.hpp
//  CF.AlmostOOP
//
//  Created by Alan Sampson on 5/24/21.
//

#define AS_EXPLICIT_COPY_MOVE_

#pragma once
#ifndef this_is_oop_hpp
#define this_is_oop_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

int this_is_oop(int argc, char const * argv[]);

//  MARK: Class Person
class Person {
public:
  enum Handedness { Right, Left, Ambidextrous, Unknown, };

private:
  std::string name_;
  uint32_t age_;
  uint32_t CNP_;
  std::string job_;
  std::string job_short_;
  uint32_t salary_;  /* units.decimals an int = 120.25 == 12025 */
  std::string address_home_;
  std::string hair_colour_;
  uint32_t height_;  /* in mm (i.e. m to 3 decimal places) */
  uint32_t weight_;  /* in g (i.e. kg to 3 decimal places) */
  Handedness handedness_;

public:
  Person(std::string name = ""s,
         uint32_t age = 0,
         uint32_t CNP = 0,
         std::string job = ""s,
         std::string job_short = ""s,
         uint32_t salary = 0,
         std::string address_home = ""s,
         std::string hair_colour = ""s,
         uint32_t height = 0,
         uint32_t weight = 0,
         Handedness handedness = Unknown);

#if defined(AS_EXPLICIT_COPY_MOVE_)
  Person(Person const & that);
  Person(Person && that);

  Person & operator=(Person const & that);
  Person & operator=(Person && that);
#else
  Person(Person const & that) = default;
  Person(Person && that) = default;

  Person & operator=(Person const & that) = default;
  Person & operator=(Person && that) = default;
#endif /* defined(EXPLICIT_COPY_MOVE_) */

  void show_name(void) const;
  void show_age(void) const;
  void show_CNP(void) const;
  void show_job(void) const;
  void show_job_short(void) const;
  void show_salary(void) const;
  void show_address_home(void) const;
  void show_hair_colour(void) const;
  void show_height(void) const;
  void show_weight(void) const;
  void show_handedness(void) const;
};

//  MARK: - OOP struct method members
inline
Person::Person(std::string name,
               uint32_t age,
               uint32_t CNP,
               std::string job,
               std::string job_short,
               uint32_t salary,
               std::string address_home,
               std::string hair_colour,
               uint32_t height,
               uint32_t weight,
               Handedness handedness)
: name_ { name }, age_ { age }, CNP_ { CNP },
  job_ { job }, job_short_ { job_short },
  salary_ { salary },
  address_home_ { address_home },
  hair_colour_ { hair_colour },
  height_ { height}, weight_ { weight},
  handedness_ { handedness}
{
  if (name.size() > 0) {
    std::cout << "dflt c'tor with values\n"sv;
  }
};

#if defined(AS_EXPLICIT_COPY_MOVE_)
inline
Person::Person(Person const & that) {
  std::cout << "copy c'tor\n"sv;
  name_ = that.name_;
  age_ = that.age_;
  CNP_ = that.CNP_;
  job_ = that.job_;
  job_short_ = that.job_short_;
  salary_ = that.salary_;
  address_home_ = that.address_home_;
  hair_colour_ = that.hair_colour_;
  height_ = that.height_;
  weight_ = that.weight_;
  handedness_ = that.handedness_;
}

inline
Person::Person(Person && that) {
  std::cout << "move c'tor\n"sv;
  name_ = std::move(that.name_);
  age_ = std::move(that.age_);
  CNP_ = std::move(that.CNP_);
  job_ = std::move(that.job_);
  job_short_ = std::move(that.job_short_);
  salary_ = std::move(that.salary_);
  address_home_ = std::move(that.address_home_);
  hair_colour_ = std::move(that.hair_colour_);
  height_ = std::move(that.height_);
  weight_ = std::move(that.weight_);
  handedness_ = std::move(that.handedness_);
}

inline
Person & Person::operator=(Person const & that) {
  std::cout << "copy assignment\n"sv;
  name_ = that.name_;
  age_ = that.age_;
  CNP_ = that.CNP_;
  job_ = that.job_;
  job_short_ = that.job_short_;
  salary_ = that.salary_;
  address_home_ = that.address_home_;
  hair_colour_ = that.hair_colour_;
  height_ = that.height_;
  weight_ = that.weight_;
  handedness_ = that.handedness_;

  return *this;
}

inline
Person & Person::operator=(Person && that) {
  std::cout << "move assignment\n"sv;
  name_ = std::move(that.name_);
  age_ = std::move(that.age_);
  CNP_ = std::move(that.CNP_);
  job_ = std::move(that.job_);
  job_short_ = std::move(that.job_short_);
  salary_ = std::move(that.salary_);
  address_home_ = std::move(that.address_home_);
  hair_colour_ = std::move(that.hair_colour_);
  height_ = std::move(that.height_);
  weight_ = std::move(that.weight_);
  handedness_ = std::move(that.handedness_);

  return *this;
}
#endif /* defined(EXPLICIT_COPY_MOVE_) */

inline
void Person::show_name(void) const {
  std::cout << ". Name: "sv << name_ << '\n';
}

inline
void Person::show_age(void) const {
  std::cout << ". Age: "sv << age_ << '\n';
}

inline
void Person::show_CNP(void) const {
  std::cout << ". CNP: "sv << CNP_ << '\n';
}

inline
void Person::show_job(void) const {
  std::cout << ". Job: "sv << job_ << '\n';
}

inline
void Person::show_job_short(void) const {
  std::cout << ". Job [short desc.]: "sv << job_short_ << '\n';
}

inline
void Person::show_salary(void) const {
  std::div_t sal = std::div(salary_, 100);
  std::cout << ". Salary: \u00a4 "sv
            << std::setw(7) << sal.quot
            << '.'
            << std::setfill('0')
            << std::setw(2) << sal.rem
            << std::setfill(' ')
            << '\n';
}

inline
void Person::show_address_home(void) const {
  std::cout << ". Home address: "sv << address_home_ << '\n';
}

inline
void Person::show_hair_colour(void) const {
  std::cout << ". Hair colour: "sv << hair_colour_ << '\n';
}

inline
void Person::show_height(void) const {
  std::div_t dheight = std::div(height_, 1'000);
  std::cout << ". Height: "sv
            << std::setw(3) << dheight.quot
            << '.'
            << std::setfill('0')
            << std::setw(3) << dheight.rem
            << std::setfill(' ')
            << " m"sv
            << '\n';
}

inline
void Person::show_weight(void) const {
  std::div_t dweight = std::div(weight_, 1'000);
  std::cout << ". Weight: "sv
            << std::setw(3) << dweight.quot
            << '.'
            << std::setfill('0')
            << std::setw(3) << dweight.rem
            << std::setfill(' ')
            << " kg"sv
            << '\n';
}

inline
void Person::show_handedness(void) const {

  std::string_view handy;
  switch (handedness_) {
  case Right:
    handy = "right"sv;
    break;

  case Left:
    handy = "left"sv;
    break;

  case Ambidextrous:
    handy = "ambidextrous"sv;
    break;

  case Unknown:
  default:
    handy = "unknown"sv;
    break;
  }

  std::cout << ". Handedness: "sv << handy << '\n';
}

#endif /* this_is_oop_hpp */
