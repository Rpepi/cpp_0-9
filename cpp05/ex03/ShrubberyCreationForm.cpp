#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!AForm::isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > AForm::getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file(target + "_shrubbery");
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}