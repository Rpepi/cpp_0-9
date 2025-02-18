#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

    private:
        const std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif