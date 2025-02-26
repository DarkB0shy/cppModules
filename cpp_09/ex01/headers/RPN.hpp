//
// The stack has a LIFO memory access pattern and it is widely used to implement RPN calculators.
// std::stack is very convenient way to store the numbers of a revers polish expression: no parenthesis are allowed in this notation,
// meaning there is no need to execute some operations before others. std::stack is not iterable by default.
//

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>

class RPN {
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        double executeExpression(const std::string &expression);
        bool isOperator(char c) const;
        double performOperation(char op, double a, double b) const;
        void validateExpression(const std::string &expression) const;
};

#endif
