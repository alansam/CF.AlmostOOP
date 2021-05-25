//
//  almost.cpp
//  CF.AlmostOOP
//
//  Created by Alan Sampson on 5/24/21.
//

#include <iostream>
#include <iomanip>
#include <string>

#include "almost_oop.h"
#include "this_is_oop.hpp"

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.AlmostOOP"s << std::endl;
#if defined(__cplusplus)
  std::cout << "C++ Version: "s << __cplusplus << std::endl;
#else
  printf("C Version: %ld\n", __STDC_VERSION__);
#endif

  auto dlm = std::string(80, '~');

  std::cout << dlm << std::endl;
  almost_oop(argc, argv);
  std::cout << std::endl;

  std::cout << dlm << std::endl;
  this_is_oop(argc, argv);
  std::cout << std::endl;

  return 0;
}
