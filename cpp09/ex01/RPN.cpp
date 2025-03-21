#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        numbers = other.numbers;
    return *this;
}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op) {
    if (numbers.size() < 2)
        throw InvalidExpressionException();
        
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();
    
    switch (op) {
        case '+':
            numbers.push(a + b);
            break;
        case '-':
            numbers.push(a - b);
            break;
        case '*':
            numbers.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw InvalidExpressionException();
            numbers.push(a / b);
            break;
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() == 1) {
            char c = token[0];
            if (isdigit(c)) {
                if (c - '0' >= 10)
                    throw InvalidExpressionException();
                numbers.push(c - '0');
            }
            else if (isOperator(c)) {
                performOperation(c);
            }
            else
                throw InvalidExpressionException();
        }
        else
            throw InvalidExpressionException();
    }
    
    if (numbers.size() != 1)
        throw InvalidExpressionException();
        
    return numbers.top();
} 