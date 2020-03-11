#ifndef SIMPLE_INTERPRETER_EVALUATOR_H
#define SIMPLE_INTERPRETER_EVALUATOR_H

#include <iostream>

namespace simple_interpreter
{

class Evaluator {
public:
  Evaluator(std::istream& in,
            std::ostream& out,
            std::ostream& err);
  void execute();

private:
  std::istream& input_;
  std::ostream& output_;
  std::ostream& error_;
};

} // namespace simple_interpreter

#endif // SIMPLE_INTERPRETER_EVALUATOR_H
