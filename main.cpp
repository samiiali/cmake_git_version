#include "fruit.hpp"
#include "fruit_factory.hpp"
#include <exception>
#include <iostream>
#include <memory>

int main() {
  try {
    std::unique_ptr<fruit_t> a_child1 = make_base("apple");
    std::unique_ptr<fruit_t> a_child2 = make_base("orange");
    a_child1->get_my_name(std::cout);
    a_child2->get_my_name(std::cout);
  } catch (const std::out_of_range &) {
    std::cout << " bad initializtion !" << std::endl;
  }
  return 0;
}