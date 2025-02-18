#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {

    private:
        const std::string target;
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif