#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else
        std::cout << "Form " << name << " created" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << name << " destroyed" << std::endl;
}

std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return issigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= gradeToSign)
        issigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const Form &f)
{
    out << "Form " << f.getName() << " is " << (f.isSigned() ? "" : "not ") << "signed";
    return out;
}

