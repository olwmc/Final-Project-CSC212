#include "forward.h"
#include "value.h"
#include "visitor.h"
#include "context.h"
#include "callable.h"
#include "err.h"

#include <iostream>

/* User defined function */
Value ASTVisitor::visit(UserFunction& userFunction) {
  Value v = userFunction.body()->accept(*this);
  return v;
}


/* Builtin print statement */
Value ASTVisitor::visit(builtin_Print& printStatment) {
  // Get the input from context
  // Using "printStatement.args()" instead of __input__ to make this more
  // maintainable
  Value input = this->m_context->resolveVariable(printStatment.args()[0]);

  // Print the input
  std::cout << input.toString() << "\n";

  // Return NIL
  return Value();
}

/* Builtin assert statement */
Value ASTVisitor::visit(builtin_Assert& assertStatement) {
  // Assert that the value is true
  Value condition = this->m_context->resolveVariable(assertStatement.args()[0]);

  if(condition.type() == Value_Type::NUMBER && condition.asNumber() == 1) {
    return Value();
  }

  else {
    raiseError("FAILED TO ASSERT");
    exit(1);
  }
}