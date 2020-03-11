#include "ast.h"

#include <cassert>
#include <stdexcept>
#include <stack>

namespace simple_interpreter
{
namespace detail
{

void Ast::eval() {
  std::stack<Ast*> evalContext;
  evalContext.push(this);
  while (!evalContext.empty()) {
    Ast* node = evalContext.top();
    assert(node);

    if (std::holds_alternative<double>(node->content)) {
      assert(!node->left && !node->right);
      evalContext.pop();
    } else if (std::holds_alternative<Op>(node->content)) {
      switch (std::get<Op>(node->content)) {
        case Op::plus:
          assert(node->left && node->right);

          if (std::holds_alternative<double>(node->left->content) &&
              std::holds_alternative<double>(node->right->content)) {
            node->content = std::get<double>(node->left->content) +
                            std::get<double>(node->right->content);
            node->left.reset();
            node->right.reset();
            evalContext.pop();
            continue;
          }

          evalContext.push(node->left.get());
          evalContext.push(node->right.get());

          break;

        default:
          throw std::runtime_error(__FUNCSIG__ ": Unknown operator");
        break;
      }
    }
  }
}

} // namespace detail
} // namespace simple_interpreter
