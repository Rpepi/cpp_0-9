#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;
class Aform;

class Intern {

    public:
        Intern();
        ~Intern();
        AForm *makeForm(std::string forName, std::string target);
};

#endif