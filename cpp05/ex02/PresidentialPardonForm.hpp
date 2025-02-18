#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

    private:
        const std::string target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif