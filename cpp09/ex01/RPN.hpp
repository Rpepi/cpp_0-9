#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN {
    private:
        std::stack<int> numbers;
        bool isOperator(char c) const;
        void performOperation(char op);
        
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        
        int evaluate(const std::string& expression);
        
        class InvalidExpressionException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error";
                }
        };
};

#endif 