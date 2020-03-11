#include "evaluator.h"

#include "ast.h"

#include <cassert>

namespace simple_interpreter
{

Evaluator::Evaluator(std::istream& in,
                     std::ostream& out,
                     std::ostream& err)
  : input_(in)
  , output_(out)
  , error_(err) {}

void Evaluator::execute() {
  auto root = std::make_unique<detail::Ast>();
  root->content = detail::Op::plus;
  root->left = std::make_unique<detail::Ast>();
  root->left->content = detail::Op::plus;
  root->left->left = std::make_unique<detail::Ast>();
  root->left->left->content = 2.;
  root->left->right = std::make_unique<detail::Ast>();
  root->left->right->content = 2.;
  root->right = std::make_unique<detail::Ast>();
  root->right->content = 2.;

  root->eval();

  assert(std::holds_alternative<double>(root->content));

  output_ <<
    __FUNCSIG__ << " -> " << std::get<double>(root->content) << std::endl;
}

} // namespace simple_interpreter
