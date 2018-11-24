#ifndef orange_header
#define orange_header

#include "fruit.hpp"

class orange_t : public fruit_t {
  virtual void get_my_name(std::ostream &s_out) {
    s_out << "I am orange" << std::endl;
  }

public:
  virtual ~orange_t() {}
};

#endif // orange_header
