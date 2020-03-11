#ifndef SIMPLE_INTERPRETER_DETAIL_AST_H
#define SIMPLE_INTERPRETER_DETAIL_AST_H

#include "types.h"

#include <memory>
#include <variant>

namespace simple_interpreter
{

namespace detail
{

struct Ast {
  std::variant<Numeral, Op> content;
  std::unique_ptr<Ast> left;
  std::unique_ptr<Ast> right;

  void eval();
};

} // namespace detail
} // namespace simple_interpreter

#endif // SIMPLE_INTERPRETER_DETAIL_AST_H
