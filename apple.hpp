#ifndef apple_header
#define apple_header

#include "fruit.hpp"

class apple_t : public fruit_t {
  virtual void get_my_name(std::ostream &s_out) {
    s_out << "I am apple" << std::endl;
  }

public:
  virtual ~apple_t() {}
};

#endif // apple_header
