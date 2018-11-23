#ifndef fruit_factory_header
#define fruit_factory_header

#include "apple.hpp"
#include "orange.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>

extern std::map<std::string, std::function<std::unique_ptr<fruit_t>()>> factory_map;

extern std::unique_ptr<fruit_t> make_base(std::string id);

#endif // fruit_factory_header