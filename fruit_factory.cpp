#include "fruit_factory.hpp"
#include <map>
#include <memory>

const auto apple_factory = []() {
  return std::unique_ptr<apple_t>{new apple_t()};
};

const auto orange_factory = []() {
  return std::unique_ptr<orange_t>{new orange_t()};
};

std::map<std::string, std::function<std::unique_ptr<fruit_t>()>> factory_map{
    {"apple", apple_factory}, {"orange", orange_factory}};

std::unique_ptr<fruit_t> make_base(std::string id) {
  return factory_map.at(id)();
}
