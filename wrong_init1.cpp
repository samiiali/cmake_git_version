#include "fruit.hpp"
#include "fruit_factory.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <version.h>

int main() {
  try {
    std::unique_ptr<fruit_t> a_child1 = make_base("apple");
    std::unique_ptr<fruit_t> a_child2 = make_base("kiwi");
  } catch (const std::out_of_range &) {
    std::cout << " bad initializtion !" << std::endl;
  }
  return 0;
}