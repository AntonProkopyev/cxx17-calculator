include_directories(detail)
include_directories(evaluator)

set(simple_interpreter_src
  detail/ast.h
  detail/ast.cpp
  detail/types.h

  evaluator/evaluator.h
  evaluator/evaluator.cpp

  main.cpp
)

add_executable(simple_interpreter ${simple_interpreter_src})
