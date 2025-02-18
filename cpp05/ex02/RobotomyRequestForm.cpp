#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > AForm::getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "*drilling noises*" << std::endl;
    std::srand(std::time(0)); // Seed the random number generator
    if (std::rand() % 2 == 0) {  // Generates 0 or 1 (50% chance)
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else {
        std::cout << "Robotomization of " << target << " failed" << std::endl;
    }
}