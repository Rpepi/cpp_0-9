#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade is too high";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade is too low";
            }
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif 