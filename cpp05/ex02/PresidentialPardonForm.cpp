#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > AForm::getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}