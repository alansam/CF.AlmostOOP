//
//  this_is_oop.cpp
//  CF.AlmostOOP
//
//  Created by Alan Sampson on 5/24/21.
//

#include "this_is_oop.hpp"

/*
 *  MARK: this_is_oop()
 */
int this_is_oop(int argc, char const * argv[]) {
  std::cout << "In: "sv << __func__ << '\n';
#if defined(__cplusplus)
  std::cout << "C++ Version: "sv << __cplusplus << std::endl;
#else
  printf("C Version: %ld\n", __STDC_VERSION__);
#endif

  auto people = std::vector<Person>(1'000);
  auto loaded { 0ull };
  people[loaded++] = Person("Ann Onymouse"s,
                            44,
                            250,
                            "An important job"s,
                            "important"s,
                            100'000'00,
                            "Our house, in the middle of our street, London, GB"s,
                            "blonde"s,
                            1'440,
                            49'000,
                            Person::Handedness::Ambidextrous);
  people[loaded++] = Person("A. N. Other"s,
                            35,
                            209,
                            "The full monty"s,
                            "monty"s,
                            58'010'50,
                            "This is my place, CA, USA"s,
                            "brunette"s,
                            1'527,
                            53'100,
                            Person::Handedness::Left);
  people[loaded++] = Person("Justin Alias"s,
                            22,
                            200,
                            "Less than a full monty"s,
                            "<monty"s,
                            30'000'00,
                            "This is my place, Sydney, AU"s,
                            "ginger"s,
                            1'966,
                            50'100,
                            Person::Handedness::Right);
  loaded++;

  std::for_each_n(people.cbegin(), loaded, [nr = 0ull](auto & folk) mutable {
    std::cout << "Person ["sv << std::setw(4) << nr++ << "]\n"sv;
    folk.show_name();
    folk.show_age();
    folk.show_CNP();
    folk.show_job();
    folk.show_job_short();
    folk.show_salary();
    folk.show_address_home();
    folk.show_hair_colour();
    folk.show_height();
    folk.show_weight();
    folk.show_handedness();
    putchar('\n');
  });

  return 0;
}
