#ifndef SIMPLE_INTERPRETER_DETAIL_TYPES_H
#define SIMPLE_INTERPRETER_DETAIL_TYPES_H

namespace simple_interpreter
{

namespace detail
{

enum class Op {
  plus = 1,
  unknown = -1
};

using Numeral = double;

} // namespace detail
} // namespace simple_interpreter

#endif // SIMPLE_INTERPRETER_DETAIL_TYPES_H
