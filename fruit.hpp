#ifndef fruit_header
#define fruit_header

#include <ostream>

struct fruit_t {
  virtual void get_my_name(std::ostream &s_out) = 0;
  virtual ~fruit_t() {}
};

#endif // fruit_header
