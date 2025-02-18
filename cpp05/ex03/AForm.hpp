#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool    issigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif