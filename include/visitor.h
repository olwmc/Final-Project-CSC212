#ifndef VISITOR_H
#define VISITOR_H

#include "forward.h"
#include "value.h"

/* AST Visitor "executes" each node */
class ProgramVisitor {
    Context* m_context;

    public:
        ProgramVisitor(Context* c) : m_context(c) {}

        /* Literal nodes */
        Value visit(NumberLiteral& numberLiteral);
        Value visit(StringLiteral& stringLiteral);
        Value visit(Identifier& identifier);

        /* Statement nodes */
        Value visit(BinaryExpression& binaryExpression);
        Value visit(ReturnStatement& returnStatement);
        Value visit(ForLoop& forLoop);
        Value visit(Block& block);
        Value visit(FunctionCall& functionCall);

        /* Function callables */
        Value visit(builtin_Print& printStatment);
        Value visit(UserFunction& userFunction);
        Value visit(builtin_Assert& assertStatement);
};

#endif /* VISITOR_H */