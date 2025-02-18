#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    else
        std::cout << "Form " << name << " created" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form " << name << " destroyed" << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return issigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= gradeToSign)
        issigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm &f)
{
    out << "Form " << f.getName() << " is " << (f.isSigned() ? "" : "not ") << "signed";
    return out;
}

