#include <exception>
#include <iostream>
#include "evaluator.h"

int main(int argc, char* argv[]) {
  simple_interpreter::Evaluator evaluator{std::cin, std::cout, std::cerr};
  try {
    evaluator.execute();
  } catch (const std::exception& e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
