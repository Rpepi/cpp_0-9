#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    if (rrf) {
        try
        {
            Bureaucrat b("Jean", 1);
            b.signForm(*rrf);
            b.executeForm(*rrf);
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete rrf;
    }
    return 0;
}
