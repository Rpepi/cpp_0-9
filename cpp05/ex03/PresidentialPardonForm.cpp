#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!AForm::isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > AForm::getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}