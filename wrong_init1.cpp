#include "fruit.hpp"
#include "fruit_factory.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <version.h>

int main() {
  // The version is extracted from git tag and git hash
  std::string my_version = std::string(GIT_TAG) + "-" + GIT_COMMIT_HASH;
  std::cout << my_version << std::endl;
  //
  try {
    std::unique_ptr<fruit_t> a_child1 = make_base("apple");
    std::unique_ptr<fruit_t> a_child2 = make_base("kiwi");
  } catch (const std::out_of_range &) {
    std::cout << " bad initializtion !" << std::endl;
  }
  return 0;
}